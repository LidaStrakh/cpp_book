#include "std_lib_facilities.h"

const double kMilesToKm = 1.609;

int main() {
  cout << "Enter miles:\n";
  double miles = 0;
  cin >> miles;
  double km = miles * kMilesToKm;
  cout << miles << " miles = " << km << " km\n";
  return 0;
}
