// Copyright 2021 mkhorosh
#include <iostream>
#include <string>

#include "postfix.h"

int main() {
  std::string input1 = "(6 * (4 - 2) + 5) * (2.6 + 3 * 7) - 9";
  std::cout << "Infix form is:\t" << input1 << std::endl;
  std::cout << "Postfix form is:\t" << infix2postfix(input1) << std::endl;
  std::string input2 = "2 + 2 + 2 + 2 - (2 + 2) + 2";
  std::cout << "Infix form is:\t" << input2 << std::endl;
  std::cout << "Postfix form is:\t" << infix2postfix(input2) << std::endl;
  std::string input3 = "a + b * (c - e) - i";
  std::cout << "Infix form is:\t" << input3 << std::endl;
  std::cout << "Postfix form is:\t" << infix2postfix(input3) << std::endl;
  std::string input4 = "2.5 + 2.56743 + 2.0 + 2 * (2 + 2 / 1.0)";
  std::cout << "Infix form is:\t" << input4 << std::endl;
  std::cout << "Postfix form is:\t" << infix2postfix(input4) << std::endl;
  std::string input5 = "132435 - 123 * 34";
  std::cout << "Infix form is:\t" << input5 << std::endl;
  std::cout << "Postfix form is:\t" << infix2postfix(input5) << std::endl;
}
