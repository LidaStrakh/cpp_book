#include "std_lib_facilities.h"

int main() {
  double val1 = 0;
  double val2 = 0;
  double min;
  double max;
  cout << "Enter two floating-point numbers: ";
  cin >> val1 >> val2;
  if (val1 < val2) {
    min = val1;
    max = val2;
  } else {
    min = val2;
    max = val1;
  }
  cout << "Smaller: " << min << "\n";
  cout << "Larger: " << max << "\n";
  cout << "Sum: " << val1 + val2 << "\n";
  cout << "Difference: " << val1 - val2 << "\n";
  cout << "Product: " << val1 * val2 << "\n";
  if (val2 != 0) {
    cout << "Ratio: " << val1 / val2 << "\n";
  } else {
    cout << "Error: division by zero\n";
  }  
} 
