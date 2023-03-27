#include "std_lib_facilities.h"
#include <cassert>

bool verbose;

void step(int* start, int* end, int x) {
  assert(*start < *end);
  string str;
  int mid = (*start + *end + 1) / 2;
  
  //cout << "Is the number you are thinking of less than " << mid <<"?(yes/no)\n";
  str = x < mid ? "yes" : "no";
  //cout << str << "\n";
  
  if (str == "yes") {
    *end = mid - 1;
  } else if (str == "no") {
    *start = mid;
  } else {
    abort();
  }
}

int guess(int x) {
  int start = 1;
  int end = 100;
  while (start < end) {
    step(&start, &end, x);
    cout << "start - " << start << " end - " << end << ".\n";
  }
  return start;
}

int main() {

  for (int y = 1; y <= 100; ++y) {
    cout << "!!!" << y  << "\n";
    assert(y == guess(y));
  }

  int x;
  cout << "Enter a number between 1 and 100 and my program will figure out what the number is.\n";
  cin >> x;
  cout << "You are think of " << guess(x) << ".\n";
}
