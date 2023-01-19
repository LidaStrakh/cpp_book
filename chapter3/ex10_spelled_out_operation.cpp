#include "std_lib_facilities.h"

int main() {
  string operation = " ";
  double val1;
  double val2;
  double result;
  bool ok = true;

  cout << "Enter an operation followed by two operands: ";
  cin >> operation >> val1 >> val2;

  if (operation == "+" || operation == "plus") {
    result = val1 + val2;
  } else if (operation == "-" || operation == "minus") {
    result = val1 - val2;
  } else if (operation == "*" || operation == "mul") {
    result = val1 * val2;
  } else if (operation == "/" || operation == "div") {
    if (val2 != 0) {
      result = val1 / val2;
    } else { 
      ok = false;
      cout << "Error: division by zero. The result is incorrect.\n";
    }  
  } else {
    ok = false;
    cout << "Data entered incorrectly.The result is incorrect.\n";
  }
  if (ok) {
    cout << "The result is: " << result << "\n";
  }
  return 0;
}
