// Copyright 2022 UNN-IASR
#include "fun.h"
#include <string>
#include <cmath>
#include <iostream>
#include <cstring>
#include <cctype>

unsigned int faStr1(const char *str) {
    int res = 0;
    bool hasDigits = false;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            hasDigits = true;
        } else if (isspace(str[i])) {
            if (!hasDigits) {
                res++;
            }
            hasDigits = false;
        }
    }
    
    if (!hasDigits) {
        res++;
    }
    
    return res;
}

unsigned int faStr2(const char *str) {
    int res = 0;
    bool isValidWord = false;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            isValidWord = true;
            continue;
        } else if (!islower(str[i]) && !isspace(str[i])) {
            isValidWord = false;
        }
        
        if (isspace(str[i]) && isValidWord) {
            res++;
            isValidWord = false;
        }
    }
    
    if (isValidWord) {
        res++;
    }
    
    return res;
}

unsigned int faStr3(const char *str) {
    int res = 0;
    int length = 0;
    int wordCount = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            if (length > 0) {
                res += length;
                length = 0;
                wordCount++;
            }
        } else {
            length++;
        }
    }

    if (length > 0) {
        res += length;
        wordCount++;
    }

    if (wordCount == 0) {
        return 0;
    }

    return static_cast<unsigned int>(std::round(static_cast<double>(res) / wordCount));
}
