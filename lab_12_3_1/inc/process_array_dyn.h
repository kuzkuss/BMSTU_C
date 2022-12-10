#ifndef PROCESS_ARRAY_DYN_H
#define PROCESS_ARRAY_DYN_H

#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

#define ARR_DECL __cdecl

#include <stddef.h>

ARR_DLL int ARR_DECL key(const int *pb_src, const int *pe_src, int *pb_dst, int *pe_dst, int *dst_len);
ARR_DLL void ARR_DECL mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
ARR_DLL int ARR_DECL comp_int(const void *a, const void *b);

#endif // PROCESS_ARRAY_DYN_H
