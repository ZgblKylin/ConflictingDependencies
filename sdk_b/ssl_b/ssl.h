#ifndef SSL_H
#define SSL_H

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

int SSL_library_init();
unsigned long SSL_version();
const char* SSL_context();
void SSL_library_cleanup();

#ifdef __cplusplus
}  // extern "C"
#endif  // __cplusplus

#endif  // SSL_H
