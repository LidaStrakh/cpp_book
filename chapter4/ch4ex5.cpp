#include "std_lib_facilities.h"

int main() {
  double num1 = 0;
  double num2 = 0;
  char character;
  
  cout << "Enter two double values and a character.\n";
  cin >> num1 >> num2 >> character;

  if (character == '+') {
    double sum = num1 + num2;
    cout << "The sum of " << num1 << " and " << num2 << " is " << sum << ".\n";
  } else if (character == '-') {
    double subtract = num1 - num2;
    cout << "The subtract of " << num1 << " and " << num2 << " is " << subtract << ".\n";
  } else if (character == '*') {
    double multiply = num1 * num2;
    cout << "The multiply of " << num1 << " and " << num2 << " is " << multiply << ".\n";
  } else if (character == '/') {
    if (num2 == 0) {
      cout << "Division by zero is undefined.\n";
    } else {
      double divide = num1 / num2;
      cout << "The divide of " << num1 << " and " << num2 << " is " << divide << ".\n";
    }
  } else {
    cout << "Character entered incorrectly. Try: +, -, *, /.\n";
  }
}
