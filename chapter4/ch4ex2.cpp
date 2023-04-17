#include "std_lib_facilities.h"
#include <cmath>
#include <cassert>

double median(const vector<double>* pnumbers) {
  double med1;
  size_t len = pnumbers->size();

  if (len == 0) {
    cout << "No numbers - no median!!!\n";
    return NAN; // NAN - not a number
  } else if (len % 2 != 0) {
    med1 = (*pnumbers)[len / 2];
  } else {
    double med2 = (*pnumbers)[len / 2 - 1];
    double med3 = (*pnumbers)[len / 2];
    med1 = (med2 + med3) / 2;
  }
  return med1;
}

void test() {
  vector<double> test1;
  vector<double> test2 = {1, 2, 3};
  vector<double> test3 = {1, 2, 3, 4};
  assert(isnan(median(&test1)) != 0);
  assert(median(&test2) == 2);
  assert(median(&test3) == 2.5);
}

int main() {
  test();

  double num;
  double med;
  vector<double> numbers;

  cout << "Enter numbers.\n";
  while (cin >> num) {
    numbers.push_back(num);
  }
  sort(numbers.begin(), numbers.end());
  med = median(&numbers);
  cout << "Median is: " << med << ".\n";
}
