#include "std_lib_facilities.h"

int main() {
  vector<double> numbers;
  double x = 0;
  cout << "Enter two numbers and '|' in the end: ";
  
  while (cin >> x) {
    numbers.push_back(x);  
  }
  if (numbers.size() <= 2) {
    cout << "You have entered: ";
    for ( double х : numbers) {
      cout << х << ", " ;
    }
    cout << "\n"; 
    
    sort(numbers);
    cout << "The smaller value is: " << numbers[0] << "\n";
    cout << "The larger value is: " << numbers[numbers.size() - 1] << "\n";
    
    if (numbers[0] == (numbers[numbers.size() - 1])) {
      cout << "The numbers " << numbers[0] << " and " << numbers[numbers.size() - 1] << " are equal.\n";
    } else if (numbers[numbers.size() - 1] -  numbers[0] <= 1) {
      cout << "The numbers " << numbers[0] << " and " << numbers[numbers.size() - 1] << " are almost equal (differ by less than 1.0).\n";
    } else if (numbers[numbers.size() - 1] -  numbers[0] <= 100) {
      cout << "The numbers " << numbers[0] << " and " << numbers[numbers.size() - 1] << " are almost equal (differ by less than 100).\n";
    }
    
   } else {
    cout << " You entered too many numbers.\n";
   }
    
}

