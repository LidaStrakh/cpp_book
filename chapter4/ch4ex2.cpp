#include "std_lib_facilities.h"

int main() {
  double num;
  vector<double> numbers;
  double median;
  cout << "Enter numbers.\n";
  while (cin >> num) {
    numbers.push_back(num);
  }
  sort(numbers.begin(), numbers.end());
  size_t len = numbers.size(); 
  if (len == 0) {
    cout << "No numbers - no median!!!\n";
    return 1;
  } else if (len % 2 != 0) {
    median = numbers[len / 2];
  } else {
    double med1 = numbers[len / 2 - 1];
    double med2 = numbers[len / 2];
    median = (med1 + med2) / 2;
  }
  cout << "Median is: " << median << ".\n";
}
