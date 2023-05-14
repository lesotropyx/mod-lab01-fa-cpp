// Copyright 2022 UNN-IASR
#include "fun.h"
#include <ctype.h>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool isWord = false;
    bool containsDigit = false;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (!isspace(str[i])) {
            isWord = true;
            if (isdigit(str[i])) {
                containsDigit = true;
            }
        } else {
            if (isWord && !containsDigit) {
                count++;
            }
            isWord = false;
            containsDigit = false;
        }
    }

    if (isWord && !containsDigit) {
        count++;
    }
    return count;
}

unsigned int faStr2(const char *str) {
  int count = 0;
  bool flag = true;
  for (int i = 0; i < strlen(str) + 1; i++) {
    flag = true;
    if ((str[i - 1] == ' ' || i == 0) && (str[i] >= 'A' && str[i] <= 'Z')) {
      i++;
      while (str[i] != ' ' && str[i] != '\0') {
        if (!(str[i] >= 'a' && str[i] <= 'z')) {
          flag = false;
        }
        i++;
      }
      if (flag) {
        count++;
      }
    }
  }
  return count;
}

unsigned int faStr3(const char *str) {
  int countWord = 0;
  int countLetters = 0;
  bool isWord = false;
  while (*str) {
    if (*str != ' ' && isWord == false) {
      countWord++;
      countLetters++;
      isWord = true;
    } else if (*str != ' ') {
      countLetters++;
    } else if (*str == ' ' && isWord == true) {
      isWord = false;
    }
    ++str;
  }
  return (countLetters/countWord);
}
