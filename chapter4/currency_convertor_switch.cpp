#include "std_lib_facilities.h"

int main() {
  const double YenD = 0.0075;
  const double EuroD = 1.06;
  const double PoundD = 1.2;
  const double BynD = 0.4;
  double amount = 0;
  double dollar = 0;
  char currency = ' ';
  
  cout << "Enter an amount followed by a currency (y - yen, e - euro, p - pound, b - byn) that you want to convert to dollars: ";
  cin >> amount >> currency;
  
  switch (currency) {
    case 'y':
      cout << amount << " yen = " << amount * YenD << " dollars.\n";
      break;
    case 'e':
      cout << amount << " euro = " << amount * EuroD << " dollars.\n";
      break;
    case 'p':
      cout << amount << " pound = " << amount * PoundD << " dollars.\n";
      break;
    case 'b':
      cout << amount << " byn = " << amount * BynD << " dollars.\n";
      break;
    default:
      cout << "Sorry, I can't convert this. Incorrect data.\n";
      break;
  }
  return 0;
}
