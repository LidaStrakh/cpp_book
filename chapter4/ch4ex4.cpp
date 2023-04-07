#include "std_lib_facilities.h"
#include <cassert>
#include <cstring>

bool VERBOSE = false;

void step(int* start, int* end, int x, bool interactive) {
  assert(*start < *end);
  string str;
  int mid = (*start + *end + 1) / 2;

  if (VERBOSE || interactive) {
    cout << "Is the number you are thinking of less than " << mid <<"?(yes/no)\n";
  }
  if (interactive) {
    cin >> str;
  } else {
    str = x < mid ? "yes" : "no";
    if (VERBOSE) {
      cout << str << "\n";
    }
  }

  if (str == "yes") {
    *end = mid - 1;
  } else if (str == "no") {
    *start = mid;
  } else {
    cout << "Expected answers: yes or no.\n";
    abort();
  }
}

int guess(int x, bool interactive = false) {
  int start = 1;
  int end = 100;
  while (start < end) {
    step(&start, &end, x, interactive);
    if (VERBOSE) {
      cout << "start - " << start << "; end - " << end << ".\n";
    }
  }
  return start;
}

int main(int argc, char** argv) {
  if (argc == 1) {
    VERBOSE = false;
  } else if (argc == 2 && (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--verbose") == 0)) {
    VERBOSE = true;
  } else {
    cout << "Usage: " << argv[0] << " [-v | --verbose]\n";
    return 1;
  }

  for (int y = 1; y <= 100; ++y) {
    if (VERBOSE) {
      cout << "!!!" << y  << "\n";
    }
    assert(y == guess(y));
  }


  int x;
  cout << "Enter a number between 1 and 100 and my program will figure out what the number is.\n";
  cin >> x;
  int z = guess(x, true);
  cout << "You are thinking of " << z << ".\n";

}
