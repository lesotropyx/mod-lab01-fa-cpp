// Copyright 2022 UNN-IASR
#include "fun.h"
#include <string>
#include <cmath>

unsigned int faStr1(const char *str) {
        bool space = true;
        int res = 0;
        int i = 0;
        bool no_digit = true;
        while (str[i] != '\0') {
                if (str[i] == ' ') {
                        i++;
                        no_digit = true;
                        space = true;
                        continue;
                } else {
                        if (space) {
                                space = false;
                                if (isdigit(str[i])) {
                                        no_digit = false;
                                } else {
                                        if (no_digit) {
                                                res += 1;
                                        }
                                }
                        } else {
                                if (isdigit(str[i]) && no_digit) {
                                        res -= 1;
                                        no_digit = false;
                                }
                        }
                        i++;
                }
        }
        return res;
}

unsigned int faStr2(const char *str) {
        int res = 0;
        bool space = true;
        bool no_upper = true;
        int i = 0;
        while (str[i] != '\0') {
                if (str[i] == ' ') {
                        i++;
                        space = true;
                        no_upper = true;
                        continue;
                } else {
                        if (space) {
                                space = false;
                                if (isupper(str[i])) {
                                        res += 1;
                                } else {
                                        no_upper = false;
                                }
                        } else {
                                if (isupper(str[i]) || (!isalnum(str[i]))) {
                                    if (no_upper) {
                                            res -= 1;
                                            no_upper = false;
                                    }
                                }
                        }
                        i++;
                }
        }
        return res;
}

unsigned int faStr3(const char *str) {
        double res = 0;
        int quantity = 0;
        int sum = 0;
        bool space = true;
        bool is_litera = true;
        int i = 0;
        while (str[i] != '\0') {
                if (str[i] == ' ') {
                        i++;
                        space = true;
                        is_litera = false;
                        continue;
                } else {
                        if (space) {
                                quantity += 1;
                                space = false;
                                is_litera = true;
                        }
                        if (is_litera) {
                                sum += 1;
                        }
                        i++;
                }
        }
        if (quantity == 0 || sum == 0) {
                return 0;
        } else {
                res = static_cast<int>(sum / quantity);
                return res;
        }
}