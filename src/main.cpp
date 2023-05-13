// Copyright 2022 UNN-IASR
#include <iostream>
#include <string>
#include "fun.h"

int main() {
    char str[1000];
    std::cin.getline(str, 1000);
    std::cout << "Words without numbers: " << faStr1(str) << std::endl;
    std::cout << "Words with a capital: " << faStr2(str) << std::endl;
    std::cout << "Average word length: " << faStr3(str) << std::endl;
    return 0;
}
