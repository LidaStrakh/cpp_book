#include "std_lib_facilities.h"

int main() {
  vector<int> numbers;
  int x = 0;
  cout << "Enter two numbers and '|' in the end: ";
  
  while (cin >> x) {
    numbers.push_back(x);  
  }
  if (numbers.size() <= 2) {
    cout << "You have entered: ";
    for ( int х : numbers) {
      cout << х << ", " ;
    }
    cout << "\n"; 
    sort(numbers);
    int first = numbers[0];
    int last = numbers[numbers.size() - 1];
    cout << "The smaller value is: " << first << "\n";
    cout << "The larger value is: " << last << "\n";
    if (first == last) {
      cout << "The numbers " << first << " and " << last << " are equal.\n";
    }
  } else {
    cout << " You entered too many numbers.\n";
  }
   
}

