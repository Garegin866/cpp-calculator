#pragma once

#include <optional>
#include <string>

using Number = double;

// Возвращает true, если удалось прочитать число
// и сохранить его в Number.
bool ReadNumber(Number& result);

// Возвращает true, если работа завершилась штатно
// командой q. Если из-за ошибки, возвращает false.
bool RunCalculatorCycle();

// Возвращает true, если удалось выполнить арифметическую операцию
// и сохранить результат в number.
// В случае ошибки возвращает false.
bool PerformArithmeticOperation(Number& number, const std::string& token);

// Возвращает true, если удалось выполнить управляющую операцию.
// В случае ошибки возвращает false.
bool PerformControlOperation(Number& number, const std::string& token, std::optional<double>& buffer);
