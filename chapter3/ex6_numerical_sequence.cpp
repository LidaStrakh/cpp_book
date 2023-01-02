#include "std_lib_facilities.h"

int main() {
  int val1 = 0;
  int val2 = 0;
  int val3 = 0;
  int min = 0;
  int mid = 0;
  int max = 0;
  cout << "Enter three numbers: ";
  cin >> val1 >> val2 >> val3;
  // a b c; a c b; b a c; b c a; c a b; c b a 
  if (val1 <= val2 && val2 <= val3) {
    min = val1;
    mid = val2;
    max = val3;
  } else if (val1 <= val3 && val3 <= val2) {
    min = val1;
    mid = val3;
    max = val2;
  } else if (val2 <= val1 && val1 <= val3) {
    min = val2;
    mid = val1;
    max = val3;
  } else if (val2 <= val3 && val3 <= val1) {
    min = val2;
    mid = val3;
    max = val1;
  } else if (val3 <= val1 && val1 <= val2) {
    min = val3;
    mid = val1;
    max = val2;
  } else if (val3 <= val2 && val2 <= val1) {
    min = val3;
    mid = val2;
    max = val1;
  }
  cout << min << ", " << mid << ", " << max << "\n";
  return 0;
} 
