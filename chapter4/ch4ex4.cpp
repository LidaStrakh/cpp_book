#include "std_lib_facilities.h"
#include <cassert>

void guess(int* start, int* end) {
  assert(*start < *end);
  string str;
  int mid = (*start + *end + 1) / 2;
  cout << "Is the number you are thinking of less than " << mid <<"?(yes/no)\n";
  cin >> str;
  
  if (str == "yes") {
    *end = mid - 1;
  } else if (str == "no") {
    *start = mid;
  } else {
    abort();
  }
}

int main() {
  cout << "Think of a number between 1 and 100 and my program will figure out what the number is.\n";

  int start = 1;
  int end = 100;
  
  while (start < end) {
    guess(&start, &end);
    cout << "start - " << start << " end - " << end << ".\n";
  }
  
  cout << "You are think of " << start << ".\n";

}
