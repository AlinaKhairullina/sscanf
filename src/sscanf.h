#include <stdarg.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <wctype.h>
#include <limits.h>
#include <math.h>

void NULLY(int* star, int* width, char* length);

int CHARscanf(const char** str, int* star, int* width, char* length, char*  c);

int wideCHARscanf(const char** str,  int* star, int* width, char* length, wchar_t* c);

int getint(const char** str, int* current, int * width);

int shortINT(const char** str, char* sign, int* star, int* width, char* length, short* c);

long int getlongint(const char** str, int* current, int * width);

unsigned long int unsigned_getlongint(const char** str, int* current, int * width);

int longINT(const char** str, char* sign, int* star, int* width, char* length, long int* c);

int INTscanf(const char** str, char* sign, int* star, int* width, char* length, int*  c);

float getfloat(const char** str, int* current, int* width);

float get_degree(const char** str, int* current, int* width );

int scanfDOUBLE(const char** str, char* sign, int* star, int* width, char* length, long double* c);

int scanfMANTIS(const char** str, char* sign, int* star, int* width, char* length,  float* c);

int scanfWIDEstr(const char** str, int* star, int* width, char* length,  wchar_t* c);

int scanfSTR(const char** str, int* star, int* width, char* length,  char* c);

long int getoctal(const char** str, int* current, int* width);

unsigned long int unsigned_getoctal(const char** str, int* current, int* width);

unsigned long int unsigned_gethex(const char** str, int* current, int* width);

long int gethex(const char** str, int* current, int* width);

int scanlongDIGIT(const char** str, char* sign, int* star, int* width, char* length,  long int* c);

int scanshortDIGIT(const char** str, char* sign, int* star, int* width, char* length,  short* c);

int scanDIGIT(const char** str, char* sign, int* star, int* width, char* length,  int* c);

int scanlongOCT(const char** str,char* sign, int* star, int* width, char* length, unsigned long int* c);

int scanshortOCT(const char** str, char* sign, int* star, int* width, char* length, unsigned short* c);

int scanOCT(const char** str,char* sign, int* star, int* width, char* length, unsigned int* c);

int scanlongHEX(const char** str,char* sign, int* star, int* width, char* length, unsigned long int* c);

int scanshortHEX(const char** str,char* sign, int* star, int* width, char* length, unsigned short* c);

int scanHEX(const char** str,char* sign, int* star, int* width, char* length, unsigned int* c);

int scanlongUINT(const char** str, char* sign, int* star, int* width, char* length, unsigned long int* c);

int scanshortUINT(const char** str,char* sign, int* star, int* width, char* length, unsigned short* c);

int scanUINT(const char** str,char* sign, int* star, int* width, char* length, unsigned int* c);

int scanPTR(const char** str, char* sign, int* star, int* width,char * length,  void** c);

void scanN(int* star, int len, int* c);

int s21_sscanf(const char *str, const char *format, ...);