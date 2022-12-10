#ifndef LIB_ARR_H
#define LIB_ARR_H

#define TRUE 1
#define FALSE 0

#define OVERFLOW_ARRAY 1
#define OK 0

#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

#define ARR_DECL __cdecl

ARR_DLL void ARR_DECL fill_primes(int *arr, int n);
ARR_DLL int ARR_DECL filter(int *src, int src_len, int *dst, int *dst_len, int value);

#endif // LIB_ARR_H
