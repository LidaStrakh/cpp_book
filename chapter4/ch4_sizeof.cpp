#include "std_lib_facilities.h"
#include <cstring>

void sizeof_char_ptr(const char* s) {
  cout << "sizeof(s) " << sizeof(s) << ".\n";
}

// 'sizeof' on array function parametr 'a' will return size of pointer char*
void sizeof_char_array(const char a[47]) {    
  cout << "sizeof(a) " << sizeof(a) << ".\n"
       << "strlen(a)" << strlen(a) << ".\n";
}

int main() {
  vector<string> sp_value = 
    {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

  cout << "vector1 - " << sizeof(sp_value) << " vector2 type - " << sizeof(vector<string>) << "\n"
       << "string \"six\" " << sizeof(sp_value[6]) << " string \"seven\"" << sizeof(sp_value[7]) << "\n"
       << " string type" << sizeof(string) << "\n";
  cout << "sizeof(\"six\")" << sizeof("six") << " sizeof(\"seven\")" << sizeof("seven") << "\n";
  const char* s1 = "six"; 
  const char* s2 = "seven";
  cout << "sizeof(s1) " << sizeof(s1) << " sizeof(s2)" << sizeof(s2) << "\n";
  const char a1[] = "six"; 
  const char a2[] = "seven";
  cout << "sizeof(a1) " << sizeof(a1) << " sizeof(a2)" << sizeof(a2) << "\n";
  sizeof_char_ptr(s1);
  sizeof_char_array(a1);
}
