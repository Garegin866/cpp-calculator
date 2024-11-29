#include "calculator.h"

#include <iostream>
#include <cmath>

using namespace std::literals;

bool ReadNumber(Number& result) {
    const auto err_not_num = "Error: Numeric operand expected"s;

    if (!(std::cin >> result)) {
        std::cerr << err_not_num << std::endl;
        return false;
    }
    return true;
}

bool RunCalculatorCycle() {
    Number number = 0;
    ReadNumber(number);

    std::optional<double> buffer;
    std::string token;
    while(std::cin >> token) {
        if (token == "q"s) {
            return true;
        }

        if (token == "+"s || token == "-"s || token == "*"s || token == "/"s || token == "**"s) {
            if (!PerformArithmeticOperation(number, token)) {
                break;
            }
        } else {
            if (!PerformControlOperation(number, token, buffer)) {
                break;
            }
        }
    }
    return false;
}

bool PerformArithmeticOperation(Number& number, const std::string& token) {
    Number right = 0;
    if (!ReadNumber(right)) {
        return false;
    }

    if (token == "+"s) {
        number += right;
    } else if (token == "-"s) {
        number -= right;
    } else if (token == "*"s) {
        number *= right;
    } else if (token == "/"s) {
        number /= right;
    } else if (token == "**"s) {
        number = std::pow(number, right);
    } else {
        std::cerr << "Error: Unknown token "s << token << std::endl;
        return false;
    }
    return true;
}

bool PerformControlOperation(Number& number, const std::string& token, std::optional<double>& buffer) {
    if (token == "c"s) {
        number = 0;
    } else if (token == "s"s) {
        buffer = number;
    } else if (token == "="s) {
        std::cout << number << std::endl;
    } else if (token == ":"s) {
        Number right = 0;
        if (!ReadNumber(right)) {
            return false;
        }
        number = right;
    } else if (token == "l"s) {
        if (!buffer.has_value()) {
            std::cerr << "Error: Memory is empty " << std::endl;
            return false;
        }
        number = buffer.value();
    } else {
        std::cerr << "Error: Unknown token "s << token << std::endl;
        return false;
    }
    return true;
}
