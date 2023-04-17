#include "std_lib_facilities.h"
#include <cmath>
#include <cassert>

double mean(const vector<double>* pnumbers) {
  size_t len = pnumbers->size();

  if (len == 0) {
    cout << "No numbers - no mean!!!\n";
    return NAN; // NAN - not a number
  }
  
  double sum = 0;
  for(double x : *pnumbers) {
    sum += x;
  }
  return sum / len;
}

void test() {
  vector<double> test1;
  vector<double> test2 = {1, 2, 3};
  vector<double> test3 = {1, 2, 6};
  vector<double> test4 = {1, 2, 3, 4};
  assert(isnan(mean(&test1)) != 0);
  assert(mean(&test2) == 2);
  assert(mean(&test3) == 3);
  assert(mean(&test4) == 2.5);
}

int main() {
  test();

  double num;
  double m;
  vector<double> numbers;

  cout << "Enter numbers.\n";
  while (cin >> num) {
    numbers.push_back(num);
  }
  m = mean(&numbers);
  cout << "Mean is: " << m << ".\n";
}
