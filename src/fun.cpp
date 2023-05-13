// Copyright 2022 UNN-IASR
#include "fun.h"
#include <string>
#include <cmath>
#include <iostream>
#include <cstring>
#include <cctype>

unsigned int faStr1(const char *str) {
    unsigned int res = 0;
    int i = 0;
    while (str[i]) {
        while (isspace(str[i])) {
            i++;
        }
        if (!str[i]) {
            break;
        }
        bool is_word = true;
        while (str[i] && !isspace(str[i])) {
            if (isdigit(str[i])) {
                is_word = false;
                break;
            }
            i++;
        }
        if (is_word) {
            res++;
        }
    }
    return res;
}

unsigned int faStr2(const char *str) {
    unsigned int res = 0;
    int i = 0;
    while (str[i]) {
        while (isspace(str[i])) {
            i++;
        }
        if (!str[i]) {
            break;
        }
        bool is_word = true;
        bool first_letter_uppercase = false;
        while (str[i] && !isspace(str[i])) {
            if (isalpha(str[i])) {
                if (isupper(str[i])) {
                    if (!first_letter_uppercase) {
                        first_letter_uppercase = true;
                    } else {
                        is_word = false;
                        break;
                    }
                } else if (!islower(str[i])) {
                    is_word = false;
                    break;
                }
            } else {
                is_word = false;
                break;
            }
            i++;
        }
        if (is_word && first_letter_uppercase) {
            res++;
        }
    }
    return res;
}

unsigned int faStr3(const char *str) {
    unsigned int res = 0;
    unsigned int len_sum = 0;
    int i = 0;
    while (str[i]) {
        while (isspace(str[i])) {
            i++;
        }
        if (!str[i]) {
            break;
        }
        bool is_word = true;
        unsigned int len = 0;
        while (str[i] && !isspace(str[i])) {
            if (isalpha(str[i])) {
                len++;
            } else {
                is_word = false;
                break;
            }
            i++;
        }
        if (is_word) {
            res++;
            len_sum += len;
        }
    }
    double sred_len = static_cast<double>(len_sum) / res;
    unsigned int rounded_sred_len = static_cast<unsigned int>(round(sred_len));
    return rounded_sred_len;
}
