#include "std_lib_facilities.h"

string pluralize(string word, int num) {
  if (num <=1) {
    return word;
  } 
  int l = word.length();
  if (word[l-1] == 'i') {
    word += "es";
  } else { 
    word += 's';
  }
  return word;
}

int main() {
  int penni = 0;
  int nickel = 0;
  int dime = 0;
  int quarter = 0;
  int half_dollar = 0;
  int one_dollar = 0;
  double total = 0; 
  string sentence = "You have ";

  cout << "How many pennies do you have?\n";
  cin >> penni;
  cout << "How many nickels do you have?\n";
  cin >> nickel;
  cout << "How many dimes do you have?\n";
  cin >> dime;
  cout << "How many quarters do you have?\n";
  cin >> quarter;
  cout << "How many half dollars do you have?\n";
  cin >> half_dollar;
  cout << "How many one-dollar coins do you have?\n";
  cin >> one_dollar;

  total = penni + (nickel * 5) + (dime * 10) + (quarter * 25) + (half_dollar * 50) + (one_dollar * 100);
  
  cout << sentence << penni << " " << pluralize("penni", penni) << ".\n";
  cout << sentence << nickel << " " << pluralize("nickel", nickel) << ".\n";
  cout << sentence << dime << " " << pluralize("dime", dime) << ".\n";
  cout << sentence << quarter << " " << pluralize("quarter", quarter) << ".\n";
  cout << sentence << half_dollar << " " << pluralize("half dollar", half_dollar) << ".\n";
  cout << sentence << one_dollar << " " << pluralize("one-dollar coin", one_dollar) << ".\n";
    
  cout << "The value of all of your coins is " << total << " cents or " << (total / 100) << " dollars.\n";
  return 0;
}
