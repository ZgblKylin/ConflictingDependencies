# Conflicting Dependencies

Sample project to resolve conflicting dependencies between two libraries which depends on same library with different version.

## Dependency Structure

Assume we have two sdk libraries linked to different openssl version like:

```text
Main App -- libsdk_a.so -- libssl_a.so
         \
          - libsdk_b.so -- libssl_b.so
```

## Problem Analyze

Both SDK A and SDK B depends on openssl, but with different versions.

Since openssl use a global context internally, it'll initialized twice in different SDK in single process, and shared between both SDKs, which will result in runtime error.

We should isolate the two different openssl library in separaed execution environment.

### Hiding symbols

At first, I tried to create `wrapper_a.so` and `wrapper_b.so`, which linked to `libsdk_a.so` and `libsdk_b.so`, hidding all symbols by default(`-fvisibility=hidden`), and only export symbols that the app used, forward call to underlying sdk library.

This solution works well in Windows, since each DLL has it's own runtime environment(e.g. stack segment), those two `libssl.dll` could run in different memory field correctly.

But it fails on Linux. When `libsdk_b.so` invokes `SSL_library_init`, it goes into `libssl_a.so`, which leads to `SIGSEGV`.

### dlopen

Furthermore, I tried to load `libsdk_a.so` and `libsdk_b.so` dynamically at runtime, instead of linking them in compile time.

That means, `libwrapper_a.so` and `libwrapper_b.so` do not link to sdk and ssl libraries directly, but load sdk libraries instead. Then I use `dlsym` to extract symbols from sdk library, then call forward user's call to it.

Fortuately, it runs well in my computer.

## Build

For reproduce the crash scenario:

```bash
mkdir build
cd build
cmake .. -DCONFLICT_RESOLVE=OFF
cmake --build . -j
cd ../bin
./test
# Initialize SDK A with ssl version 010101
# test: conflicting_dependencies/sdk_a/ssl_a/ssl.c:15: SSL_library_init: Assertion `NULL == ssl_context' failed.
# [1]    2545059 IOT instruction (core dumped)  ./test
```

For problem solved:

```bash
mkdir build
cd build
cmake .. -DCONFLICT_RESOLVE=ON
cmake --build . -j
cd ../bin
./test
# Initialize SDK A with ssl version 010101
# Initialize SDK B with ssl version 010203
# Release SDK B
# Release SDK A
```

## New Dependency Structure

```text
Main App -- libwrapper_a.so --(dyload)-- libsdk_a.so -- libssl_a.so
         \
          - libwrapper_b.so --(dyload)-- libsdk_b.so -- libssl_b.so
