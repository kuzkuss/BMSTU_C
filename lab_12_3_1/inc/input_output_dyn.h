#ifndef INPUT_OUTPUT_DYN_H
#define INPUT_OUTPUT_DYN_H

#ifdef ARR_EXPORTS
#define ARR_DLL __declspec(dllexport)
#else
#define ARR_DLL __declspec(dllimport)
#endif

#define ARR_DECL __cdecl

#include <stdio.h>

ARR_DLL int ARR_DECL input_array(FILE *f_in, int **arr_beg, int **arr_end);
ARR_DLL int ARR_DECL output_array(const char *filename, int *arr_beg, const int *arr_end);

#endif // INPUT_OUTPUT_DYN_H
