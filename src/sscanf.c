#include "sscanf.h"

void NULLY(int* star, int* width, char* length){
    *star = 0;
    *width = 0;
    *length = 0;
    return;
}

int CHARscanf(const char** str, int* star, int* width, char* length, char*  c){ //width = 0, length isn't possisple
    if (*star == 1){
        (*str)++;
        NULLY(star, width,length);
        return 0;
    }
    else {
        *c = **str;
        (*str)++;
       NULLY(star, width,length);
        return 1;
    }
}

int wideCHARscanf(const char** str,  int* star, int* width, char* length, wchar_t* c){
    (void)setlocale(LC_ALL,"");
    int n = 0;
    wchar_t  wc = 0;
    n = mbtowc(&wc, *str, MB_CUR_MAX);
    (*str) += 2;
    if (n == -1) {return 0;}
    if (n == 0){ NULLY(star, width,length); return 0;}
    if (!*star) {
        *c = wc;
        NULLY(star, width, length);
        return 1;
    }
    else {
        NULLY(star, width, length);
        return 0;
    }
}

int getint(const char** str, int* current, int * width){
    int res = 0;
    if (((**str) >= '0') && ((**str) <= '9')){
                res = (**str) - '0';
                (*str)++; (*current)++;
                while (((**str) >= '0') && ((**str) <= '9')  && ((((*current) < (*width)) && (*width > 0)) || (*width <= 0)))
                    {res = res * 10 +((**str) - '0'); (*str)++; (*current)++; }
            }
    return res;
}

int shortINT(const char** str, char* sign, int* star, int* width, char* length, short* c){
    int current = 0;
    short tmp = 0;
    tmp = getint(str, &current, width);
    if (!(*star)) {
        if (*sign == '-'){
            *c = (short) tmp * (-1);
            *sign = '+';
        }
        else {
            *c = (short) tmp;
        }
            NULLY(star, width,length);
            return 1;
    }
    else {
        *sign = '+';
        NULLY(star, width,length);
        return 0;
    }

}

long int getlongint(const char** str, int* current, int * width){
    long int res = 0;
    if (((**str) >= '0') && ((**str) <= '9')){
                res = (**str) - '0';
                (*str)++; (*current)++;
                while (((**str) >= '0') && ((**str) <= '9')  && ((((*current) < (*width)) && (*width > 0)) || (*width <= 0)))
                    {res = (res * 10 + ((**str) - '0')); (*str)++; (*current)++; }
            }
    return res;
}

unsigned long int unsigned_getlongint(const char** str, int* current, int * width){
    unsigned long int res = 0;
    if (((**str) >= '0') && ((**str) <= '9')){
                res = (**str) - '0';
                (*str)++; (*current)++;
                while (((**str) >= '0') && ((**str) <= '9')  && ((((*current) < (*width)) && (*width > 0)) || (*width <= 0)))
                    {res = (res * 10 + ((**str) - '0')); (*str)++; (*current)++; }
            }
    return res;
}

int longINT(const char** str, char* sign, int* star, int* width, char* length, long int* c){
    int current = 0;
    long int tmp = 0;
    tmp = getlongint(str, &current, width);
    if (!(*star)) {
        if (*sign == '-'){
            *c = (long int) tmp * (-1);
            *sign = '+';
        }
        else{
            *c = (long int) tmp;
        }
            NULLY(star, width,length);
            return 1;
    }
    else {
        *sign = '+';
        NULLY(star, width,length);
        return 0;
    }
}

int INTscanf(const char** str, char* sign, int* star, int* width, char* length, int*  c){
    int tmp = 0, current = 0;
    if (**str){
    tmp = getint(str, &current, width);}
    if (!(*star)) {
        if (*sign == '-'){
            *c = tmp * (-1);
            *sign = '+';
        }
        else{
            *c = tmp;
        }
            NULLY(star, width,length);
            return 1;
    }
    else {
        *sign = '+';
        NULLY(star, width,length);
        return 0;
    }
}

float getfloat(const char** str, int* current, int* width){
    float res = 0, frac  = 0;
    int drob = 1;
    if (((**str) >= '0') && ((**str) <= '9')){
                res = (**str) - '0';
                (*str)++; (*current)++;
                while (((**str) >= '0') && ((**str) <= '9')  && ((((*current) < *width) && (*width > 0)) || (*width <= 0)))
                    {res = res * 10 +((**str) - '0'); (*str)++; (*current)++;}
            }

    if (((**str) == '.') && ((*(*str + 1)) >= '0') && ((*(*str + 1)) <= '9') //fractional
        && ((((*current) < *width) && (*width > 0)) || (*width <= 0))) {
            (*str)++; (*current)++;
            if (((((*current) < *width) && (*width > 0)) || (*width <= 0))){
                frac = (float) ((**str) - '0')/10;
                drob++;
                (*str)++;
                (*current)++;
            }
            while (((**str) >= '0') && ((**str) <= '9') && ((((*current) < *width) && (*width > 0)) || (*width <= 0))){
                frac = frac + (float)((**str) - '0') / (int) pow(10, drob);
                (*str)++; (*current)++; drob++;
            }
        }
    res += frac;
    return res;
}

float get_degree(const char** str, int* current, int* width ){
    char sign_deg = '+';
    int degree = 0;
    float e = 1;
    if ((((**str) == 'e') || ((**str) == 'E')) && ((((*current) < *width) && (*width > 0)) || (*width <= 0))) { //degree
            (*str)++; (*current)++;
            if (((**str) == '-') && ((*(*str + 1)) >= '0') && ((*(*str + 1)) <= '9')
             && ((((*current) < *width) && (*width > 0)) || (*width <= 0))) {sign_deg = '-'; (*str)++; (*current)++;}

            else if (((**str) == '+') && ((*(*str + 1)) >= '0') && ((*(*str + 1)) <= '9')
             && ((((*current) < *width) && (*width > 0)) || (*width <= 0))) {sign_deg = '+'; (*str)++;(*current)++;}

            if (((**str) >= '0') && ((**str) <= '9') && ((((*current) < *width) && (*width > 0)) || (*width <= 0))) {
                degree = (**str) - '0';
                (*str)++; (*current)++;
                while (((**str) >= '0') && ((**str) <= '9') && ((((*current) < *width) && (*width > 0)) || (*width <= 0))){
                    degree = degree * 10 + ((**str) - '0'); (*str)++; (*current)++;
                }
            }
            else (*str)--;
        }
    for (int i = 0; i < degree; i++){
        if (sign_deg == '+')
            e *= 10;
        else if (sign_deg == '-')
            e =  e/10;
        }
    return e;
}

int scanfDOUBLE(const char** str, char* sign, int* star, int* width, char* length, long double* c){
    int current = 0;
    long double mantis = 0, e = 1;
    mantis = (long double) getfloat(str, &current, width);
    e = (long double) get_degree(str, &current, width);
    if (!(*star)) {
        if (*sign == '+') 
            *c = (long double) mantis * e;
        else 
            *c = (long double) mantis * e * (-1);
        *sign = '+';
        NULLY(star, width,length);
        return 1;
    }
    else {
        *sign = '+';
        NULLY(star, width,length);
        return 0;
    }
}

int scanfMANTIS(const char** str, char* sign, int* star, int* width, char* length,  float* c){
    int current = 0;
    float mantis = 0, e = 1;
    mantis = (float) getfloat(str, &current, width);
    e = get_degree(str, &current, width);
    if (!(*star)) {
        if (*sign == '+') 
            *c = mantis * e;
        else 
            *c = mantis * e * (-1);
        *sign = '+';
        NULLY(star, width,length);
        return 1;
    }
    else {
        *sign = '+';
        NULLY(star, width,length);
        return 0;
    }
}

int scanfWIDEstr(const char** str, int* star, int* width, char* length,  wchar_t* c){
    (void)setlocale(LC_ALL, "");
    size_t  retval;
    int current = 0, n = 0;
    char* s;
    while (!iswspace(**str) && (((current/2 < *width) && (*width > 0)) || (*width <= 0))){
        n++;(*str)++; current++;
    }
    s = malloc(n * 2 * sizeof(char) + 1 * sizeof(char));
    for (int i = 0; i < n * 2; i++){
        s[i] = 0;
    }
    s[n] = '\0';
    if (!*star){
        for (int i = n; i > 0; i--){
        (*str)--; s[i - 1] = **str;
        }
        for (int i = 0; i < n; i++){
        (*str)++;
        }
    }
    s[n] = '\0';
    retval = mbstowcs(c, s, n); // функция которая преобразовывает байтовый массив символов в широкий массив символов
    if ((int) retval == -1) {NULLY(star, width,length); return 0;}
    free(s);
     if (!*star) {NULLY(star, width,length); return 1;}
    else {NULLY(star, width,length); return 0;}
}

int scanfSTR(const char** str, int* star, int* width, char* length,  char* c){
    int i = 0;
    int current = 0;
     while(isspace(**str)) {
        (*str)++;
    }
    while ((**str) && (*str) && (!isspace((unsigned char)**str)) && (((current < *width) && (*width > 0)) || (*width <= 0))){
        if (!*star) {
            c[i] = **str;
            i++;
    }
        current++;
        (*str)++; 
    }
    c[i] = '\0';
     if (!*star) {NULLY(star, width,length); return 1;}
    else {NULLY(star, width,length); return 0;}
}

long int getoctal(const char** str, int* current, int* width){
    char octalstr[65] = {0};
    char* endptr;
    long int res = 0;
    int i = 0;
    while ((**str >= '0') && (**str <= '7') && ((((*current) < (*width)) && ((*width) > 0)) || ((*width) <= 0))){
        octalstr[i] = **str;
        (*current)++;
        (*str)++;
        i++;
    }
    octalstr[i] = '\0';
    res = strtol(octalstr, &endptr, 8);;
    if (*endptr != '\0')
        return 0;

    return res;
}

unsigned long int unsigned_getoctal(const char** str, int* current, int* width){
    char octalstr[65] = {0};
    char* endptr ;
    unsigned long int res = 0;
    int i = 0;
    while ((**str >= '0') && (**str <= '7') && ((((*current) < (*width)) && ((*width) > 0)) || ((*width) <= 0))){
        octalstr[i] = **str;
        (*current)++;
        (*str)++;
        i++;
    }
    octalstr[i] = '\0';
    res =  strtol(octalstr, &endptr, 8);
    if ((*endptr != '\0'))
        return 0;
    return res;
}

unsigned long int unsigned_gethex(const char** str, int* current, int* width){
    char octalstr[65] = {0};
    char* endptr ;
    unsigned long int res = 0;
    int i = 0;
    if ((**str == '0') && ((*(*str + 1) == 'x')|| (*(*str + 1) == 'X'))) {
        (*str) += 2;
        (*current) += 2;
    }
    while ((((**str >= '0') && (**str <= '9')) || ((**str >= 'A') && (**str <= 'F')) || ((**str >= 'a') && (**str <= 'f'))) &&
     ((((*current) < (*width)) && (*width > 0)) || (*width <= 0))){
        octalstr[i] = **str;
        (*current)++;
        (*str)++;
        i++;
    }
    octalstr[i] = '\0';
    res = strtol(octalstr, &endptr, 16);
    if ((*endptr != '\0'))
        return 0;
    return res;
}

long int gethex(const char** str, int* current, int* width){
    char octalstr[65] = {0};
    char* endptr;
    long int res = 0;
    int i = 0;
    while ((((**str >= '0') && (**str <= '9')) || ((**str >= 'A') && (**str <= 'F')) || ((**str >= 'a') && (**str <= 'f'))) &&
     ((((*current) < (*width)) && (*width > 0)) || (*width <= 0))){
        octalstr[i] = **str;
        (*current)++;
        (*str)++;
        i++;
    }
    octalstr[i] = '\0';
    res = strtol(octalstr, &endptr, 16);
    if (*endptr != '\0')
        return 0;
    return res;
}

int scanlongDIGIT(const char** str, char* sign, int* star, int* width, char* length,  long int* c){
    int current = 0;
    if (((**str) >= '1') && ((**str) <= '9') && ((((current) < (*width)) && (*width > 0)) || (*width <= 0))){
        *c = getlongint(str, &current, width);
    }
    else if ((**str == '0') && !((*(*str + 1) == 'x') || (*(*str + 1) == 'X'))){
        (*str)++; (*width)--;  
        *c = getoctal(str, &current, width);
    }
    else if ((**str == '0') && ((*(*str + 1) == 'x') || (*(*str + 1) == 'X'))){
        (*str) += 2; 
        (*width) -= 2; 
        *c = gethex(str, &current, width);
    }
    if ((*sign == '-') && (!*star))  *c = -1 * (*c);
    *sign = '+';
     if (!*star) {NULLY(star, width,length); return 1;}
    else {NULLY(star, width,length); return 0;}
}

int scanshortDIGIT(const char** str, char* sign, int* star, int* width, char* length,  short* c){
    int current = 0; short int tmp = 0;
    if (((**str) >= '1') && ((**str) <= '9') && ((((current) < (*width)) && (*width > 0)) || (*width <= 0))){
        tmp = getlongint(str, &current, width);
             if (!*star) *c = (short) tmp;
    }
    else if ((**str == '0') && !((*(*str + 1) == 'x') || (*(*str + 1) == 'X'))){
        (*str)++; (*width)--;  
        tmp = getoctal(str, &current, width);
        if ((tmp <= SHRT_MAX) && (tmp >= SHRT_MIN)) 
             if (!*star) *c = (short) tmp;
    }
    else if ((**str == '0') && ((*(*str + 1) == 'x') || (*(*str + 1) == 'X'))){
        (*str) += 2; 
        (*width) -= 2; 
        tmp = gethex(str, &current, width);
             if (!*star) *c = (short) tmp;
    }
    if ((*sign == '-') && (!*star)) *c = -1 * (*c);
    *sign = '+';
     if (!*star) {NULLY(star, width,length); return 1;}
    else {NULLY(star, width,length); return 0;}
}

int scanDIGIT(const char** str, char* sign, int* star, int* width, char* length,  int* c){
    int current = 0; int tmp;
    if (((**str) >= '1') && ((**str) <= '9') && ((((current) < (*width)) && (*width > 0)) || (*width <= 0))){
        tmp = getlongint(str, &current, width);
             if (!*star) *c = (int) tmp;
    }
    else if ((**str == '0') && !((*(*str + 1) == 'x') || (*(*str + 1) == 'X'))){
        (*str)++; (*width)--;  
        tmp = getoctal(str, &current, width);
             if (!*star) *c = (int) tmp;
    }
    else if ((**str == '0') && ((*(*str + 1) == 'x') || (*(*str + 1) == 'X'))){
        (*str) += 2; 
        (*width) -= 2; 
        tmp = gethex(str, &current, width);
             if (!*star) *c = (int) tmp;
    }
    if ((*sign == '-') && (!*star)) *c = -1 * (*c);
    *sign = '+';
     if (!*star) {NULLY(star, width,length); return 1;}
    else {NULLY(star, width,length); return 0;}
}

int scanlongOCT(const char** str,char* sign, int* star, int* width, char* length, unsigned long int* c){
    int current = 0;
    unsigned long int tmp = unsigned_getoctal(str, &current, width);
    if (!*star) *c = tmp;
    if ((*sign == '-') && (!*star)) *c = -1 * (*c);
    *sign = '+';
     if (!*star) {NULLY(star, width,length); return 1;}
    else {NULLY(star, width,length); return 0;}
}

int scanshortOCT(const char** str, char* sign, int* star, int* width, char* length, unsigned short* c){
    int current = 0;
    unsigned long int tmp = unsigned_getoctal(str, &current, width);
    if (tmp <= USHRT_MAX) {
       if (!*star) *c = (unsigned short) tmp;
    }
    if ((*sign == '-') && (!*star)) *c = -1 * (*c);
    *sign = '+';
    if (!*star) {NULLY(star, width,length); return 1;}

    else {NULLY(star, width,length); return 0;}
}

int scanOCT(const char** str,char* sign, int* star, int* width, char* length, unsigned int* c){
    int current = 0;
    unsigned long int tmp =  unsigned_getoctal(str, &current, width);
    if (tmp <= UINT_MAX){
        if (!*star) *c = (unsigned int) tmp;
    }
    if ((*sign == '-') && (!*star)) *c = -1 * (*c);
    *sign = '+';
    if (!*star) {NULLY(star, width,length); return 1;}

    else {NULLY(star, width,length); return 0;}
}

int scanlongHEX(const char** str,char* sign, int* star, int* width, char* length, unsigned long int* c){
    int current = 0;
    unsigned long int tmp = unsigned_gethex(str, &current, width);
    if (!*star) *c = tmp;
    if ((*sign == '-') && (!*star)) *c = -1 * (*c);
    *sign = '+';
    if (!*star) {NULLY(star, width,length); return 1;}
    else {NULLY(star, width,length); return 0;}
}

int scanshortHEX(const char** str,char* sign, int* star, int* width, char* length, unsigned short* c){
    int current = 0;
    unsigned long int tmp = unsigned_gethex(str, &current, width);
    if (tmp <= USHRT_MAX){ 
        if (!*star) *c = (unsigned short) tmp;
    }
    if ((*sign == '-') && (!*star)) *c = -1 * (*c);
    *sign = '+';
    if (!*star) {NULLY(star, width,length); return 1;}

    else {NULLY(star, width,length); return 0;}
}

int scanHEX(const char** str,char* sign, int* star, int* width, char* length, unsigned int* c){
    int current = 0;
    unsigned long int tmp =  unsigned_gethex(str, &current, width);
    if (tmp <= UINT_MAX){
        if (!*star) *c = (unsigned int) tmp;
    }
    if ((*sign == '-') && (!*star)) *c = -1 * (*c);
    *sign = '+';
    if (!*star) {NULLY(star, width,length); return 1;}

    else {NULLY(star, width,length); return 0;}
}

int scanlongUINT(const char** str, char* sign, int* star, int* width, char* length, unsigned long int* c){
    int current = 0;
    unsigned long int tmp = unsigned_getlongint(str, &current, width);
    if (!*star) *c = tmp;
    if ((*sign == '-') && (!*star)) *c = -1 * (*c);
    *sign = '+';
     if (!*star) {NULLY(star, width,length); return 1;}
    else {NULLY(star, width,length); return 0;}
}

int scanshortUINT(const char** str,char* sign, int* star, int* width, char* length, unsigned short* c){
    int current = 0;
    unsigned long int tmp = unsigned_getlongint(str, &current, width);
    if (tmp <= USHRT_MAX){ 
        if (!*star) *c = (unsigned short) tmp;
    }
    if ((*sign == '-') && (!*star)) *c = -1 * (*c);
    *sign = '+';
    if (!*star) {NULLY(star, width,length); return 1;}

    else {NULLY(star, width,length); return 0;}
}

int scanUINT(const char** str,char* sign, int* star, int* width, char* length, unsigned int* c){
    int current = 0;
    unsigned long int tmp =  unsigned_getlongint(str, &current, width);
    if (tmp <= UINT_MAX){
        if (!*star) *c = (unsigned int) tmp;
    }
    if ((*sign == '-') && (!*star)) *c = -1 * (*c);
    *sign = '+';
    if (!*star) {NULLY(star, width,length); return 1;}

    else {NULLY(star, width,length); return 0;}
}

int scanPTR(const char** str, char* sign, int* star, int* width,char * length,  void** c){
    unsigned long ptr = 0;
    int current = 0;
    if ((**str == '0') && ((*(*str + 1) == 'x') || (*(*str + 1) == 'X'))){
        (*str) += 2;
        current += 2;
    }
    ptr = unsigned_gethex(str, &current, width);
    if (*star)
    {
        *sign = '+';
        NULLY(star, width, length);
        return 0;
    }
    else {
        if ((*sign == '-') && (!*star)) ptr = -1 * ptr;
        *c = (void *) ptr;
        NULLY(star, width, length);
        return 1;
    }

}

void scanN(int* star, int len, int* c){
    if (!*star) {*c = len; *star = 0;}
    return;
}

int s21_sscanf(const char *str, const char *format, ...){
    int result = 0, width = 0, star = 0, len = strlen(format);
    char length = 0, sign = '+';
    const char* tmp = str;
    va_list ap;
    va_start(ap, format);
    for (size_t offset = 0; format[offset] != '\0'; offset++)
    {
        if (format[offset] != '%') {
            if ((*tmp == format[offset])) tmp++;
            else if (isspace(format[offset])) continue;
            else break;
        }
        else{
            offset++;
            if (format[offset] == '*'){
                star = 1;
                offset++;
            }
            if (( '1' <= (format[offset])) && ((format[offset]) <= '9' )){
                width = (format[offset]) - '0';
                offset++;
                while (( '0' <= (format[offset])) && ( (format[offset]) <= '9' )){
                    width = width * 10 + ((format[offset]) - '0');
                    offset++;}
            }
            if ((format[offset] == 'h') || (format[offset] == 'l') || (format[offset] == 'L')){
                length = format[offset];
                offset++;
            }
            if (format[offset] == 'c'){
                if (length != 'l') { result += CHARscanf(&tmp , &star, &width, &length, (char*) va_arg(ap, int*));
                    }
                else result += wideCHARscanf(&tmp , &star, &width, &length, (wchar_t*) va_arg(ap, wchar_t*));
            }
            else if ((format[offset] == 'd')){
                while(isspace(*tmp)) tmp++;
                if (!(*tmp) ) break;
                    if ((*tmp) == '-') { sign = '-'; tmp++; width--;}
                    else if ((*tmp) == '+') {sign = '+'; tmp++; width--;}

                    if (((*tmp) < '0') || ((*tmp) > '9')) offset = len;
                    else if (length == 'h') result += shortINT(&tmp, &sign, &star, &width, &length, (short*) va_arg(ap, int*));
                    else if (length == 'l') result += longINT(&tmp, &sign, &star, &width, &length,(long int*) va_arg(ap, long int*));
                    else  {
                        result += INTscanf(&tmp, &sign, &star, &width, &length,  va_arg(ap, int*));
                       
                    }
            }
            else if ((format[offset] == 'e') || (format[offset] == 'E') || (format[offset] == 'f') || (format[offset] == 'g') || (format[offset] == 'G')){

                    while(isspace(*tmp)) tmp++; 
                    if (!(*tmp) ) break;
                    if (tmp[0] == '-'){sign = '-'; tmp++; width--;}
                    else if (tmp[0] == '+') {sign = '+', tmp++; width--;}
                    if (((*tmp) < '0') || ((*tmp) > '9')) offset = len;
                    if (length == 'L') result += scanfDOUBLE(&tmp, &sign, &star, &width, &length, (long double* ) va_arg(ap, double*));
                    else 
                        result += scanfMANTIS(&tmp, &sign, &star, &width, &length,  (float*) va_arg(ap, float*));

                    

            }
            else if (format[offset] == 's'){
                if (!(*tmp) ) break;
                if (length == 'l')  result += scanfWIDEstr(&tmp, &star, &width, &length,  (wchar_t* ) va_arg(ap, wchar_t*));
                else {result += scanfSTR(&tmp, &star, &width, &length,  (char* ) va_arg(ap, char*));

                }
            } 
            else if (format[offset] == 'i'){
                while(isspace(*tmp)) tmp++;
                if (!(*tmp) ) break;
                if (tmp[0] == '-'){sign = '-'; tmp++; width--;}
                else if (tmp[0] == '+') {sign = '+', tmp++; width--;}
                if (((*tmp) < '0') || ((*tmp) > '9')) offset = len;
                if (length == 'h') result += scanshortDIGIT(&tmp, &sign, &star, &width, &length, (short* ) va_arg(ap, short*));
                else if (length == 'l') result += scanlongDIGIT(&tmp, &sign, &star, &width, &length, (long int* ) va_arg(ap, long int*));
                else {result += scanDIGIT(&tmp, &sign, &star, &width, &length, (int* ) va_arg(ap, int*));
                }
            }
            else if ( format[offset] == 'o'){
                while(isspace(*tmp)) tmp++;
                if (!(*tmp) ) break;
                if (tmp[0] == '-'){sign = '-'; tmp++; width--;}
                else if (tmp[0] == '+') {sign = '+', tmp++; width--;}
                if (((*tmp) < '0') || ((*tmp) > '9')) offset = len;
                if (length == 'h') result += scanshortOCT(&tmp,&sign, &star, &width, &length, (unsigned short* ) va_arg(ap,unsigned short*));
                else if (length == 'l') result += scanlongOCT(&tmp, &sign, &star, &width, &length, (unsigned long int* ) va_arg(ap,unsigned long int*));
                else {result += scanOCT(&tmp, &sign, &star, &width, &length, (unsigned int* ) va_arg(ap,unsigned int*));
                }

            }
            else if (( format[offset] == 'x') || ( format[offset] == 'X')){ 
                while(isspace(*tmp)) tmp++;  
                if (!(*tmp) ) break;
                if (tmp[0] == '-'){sign = '-'; tmp++; width--;}
                else if (tmp[0] == '+') {sign = '+', tmp++; width--;}
                if (((*tmp) < '0') || ((*tmp) > '9')) offset = len;
                if (length == 'h') result += scanshortHEX(&tmp, &sign, &star, &width, &length, (unsigned short* ) va_arg(ap,unsigned short*));
                else if (length == 'l') result += scanlongHEX(&tmp, &sign, &star, &width, &length, (unsigned long int* ) va_arg(ap,unsigned long int*));
                else {result += scanHEX(&tmp, &sign, &star, &width, &length, (unsigned int* ) va_arg(ap,unsigned int*));
                }

            }
            else if ( format[offset] == 'u'){
                 while(isspace(*tmp)) tmp++; 
                 if (!(*tmp) ) break;
                 if (tmp[0] == '-'){sign = '-'; tmp++; width--;}
                else if (tmp[0] == '+') {sign = '+', tmp++; width--;}
                if (((*tmp) < '0') || ((*tmp) > '9')) offset = len;
                if (length == 'h') result += scanshortUINT(&tmp, &sign, &star, &width, &length, (unsigned short* ) va_arg(ap,unsigned short*));
                else if (length == 'l') result += scanlongUINT(&tmp,&sign,  &star, &width, &length, (unsigned long int* ) va_arg(ap,unsigned long int*));
                else {result += scanUINT(&tmp, &sign, &star, &width, &length, (unsigned int* ) va_arg(ap,unsigned int*));
                }

            }
            else if ( format[offset] == 'p'){
                while(isspace(*tmp)) tmp++;
                if (!(*tmp) ) break;
                if (tmp[0] == '-'){sign = '-'; tmp++; width--;}
                if (((*tmp) < '0') || ((*tmp) > '9')) offset = len;
                else if (tmp[0] == '+') {sign = '+', tmp++; width--;}
                result += scanPTR(&tmp, &sign, &star, &width, &length, (void** ) va_arg(ap, void**));
            }
            else if ( format[offset] == 'n'){
                scanN(&star, tmp - str, (int* ) va_arg(ap, int*));

            }
            else if ( format[offset] == '%'){
                while(isspace(*tmp)) tmp++;
                if (*tmp == '%') tmp++;
                if (*tmp) continue;
            }
        }
    }

  return result;
}
