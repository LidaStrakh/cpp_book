#include "std_lib_facilities.h"

int main()
{
  string s = "Goodbye, cruel world! ";
  cout << s << '\n';
}
// 1 - 3 errors: STRING,cOut,S - was not declared; 1 warning - no return statement; Main -ok
// 2 - 3 errors: STRING,cOut,S - was not declared; warning go out away Main -> main
// 3 - 2 errors: cOut,S - was not declared; (STRING -> string)
// 4 - 1 error: S - was not declared;