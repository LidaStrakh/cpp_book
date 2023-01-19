#include "std_lib_facilities.h"

int main() {
  const double YenD = 0.0075;
  const double EuroD = 1.06;
  const double PoundD = 1.2;
  const double BynD = 0.4;
  double amount = 0;
  double dollar = 0;
  string currency = " ";
  
  cout << "Enter an amount followed by a currency (yen, euro, poun, byn) that you want to convert to dollars: ";
  cin >> amount >> currency;
  if (currency == "yen") {
    cout << amount << " " << currency << " = " << amount * YenD << " dollars.\n";
  } else if (currency == "euro") {
    cout << amount << " " <<  currency << " = " << amount * EuroD << " dollars.\n";
  } else if (currency == "pound") {
    cout << amount << " " << currency << " = " << amount * PoundD << " dollars.\n";
  } else if (currency == "byn") {
    cout << amount << " " << currency << " = " << amount * BynD << " dollars.\n";
  } else {
    cout << "Sorry, I can't convert this. Incorrect data.\n";
  }
  return 0;
}
