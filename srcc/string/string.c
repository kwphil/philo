#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

char *substr(const char *str, const int start, const int end) {
    int _start = start, _end = end;
    
    if (_start < 0) _start += strlen(str);
    if (_end <= 0) _end += strlen(str);

    char *ret = (char *)malloc(_end - _start + 2);

    for (int i = _start, j = 0; i <= _end; i++) {
        ret[j] = str[i];
        j++;
    }

    ret[_end - _start + 1] = '\0'; // Null-terminate the result
    return ret;
}

char *appendStr(const char *str, ...) {
    va_list args;
    va_start(args, str);

    size_t totalLength = strlen(str);

    const char *currStr = va_arg(args, const char *);
    while (currStr != NULL) {
        totalLength += strlen(currStr);
        currStr = va_arg(args, const char *);
    }

    va_end(args);

    char *ret = (char *)malloc(totalLength + 1); // Include space for the null terminator

    if (ret == NULL) {
        return NULL;
    }

    va_start(args, str);
    strcpy(ret, str);
    currStr = va_arg(args, const char *);
    while (currStr != NULL) {
        strcat(ret, currStr);
        currStr = va_arg(args, const char *);
    }

    va_end(args);

    return ret;
}

char *appendf(const char *str, ...) {
    va_list args;
    va_start(args, str);

    va_list args_copy;
    va_copy(args_copy, args);
    int size = vsnprintf(NULL, 0, str, args_copy) + 1;
    va_end(args_copy);

    if (size <= 0) {
        va_end(args);
        return NULL;
    }

    char *ret = (char *)malloc(size);

    if (ret == NULL) {
        va_end(args);
        return NULL;
    }

    vsnprintf(ret, size, str, args);

    va_end(args);

    return ret;
}

bool isNum(const char *str) {
    int i = 0;
    
    while (str[i] != '\0') {
        if (!isdigit(str[i])) {
            return false;
        }
        i++;
    }

    return true;
}

char *sToA(const char **arr) {
    int length = 0;

    for (int i = 0; arr[i] != NULL; i++) {
        length += strlen(arr[i]);
    }

    char *ret = (char *)malloc(length + 1); // Include space for the null terminator
    int k = 0;

    for (int i = 0; arr[i] != NULL; i++) {
        for (int j = 0; arr[i][j] != '\0'; j++) {
            ret[k] = arr[i][j];
            k++;
        }
    }

    ret[length] = '\0'; // Null-terminate the result

    return ret;
}