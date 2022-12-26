int main() {
  int x; // ok
  int Number1; // ok
  int _x_y; //ok
  int string; // ok, string is a type but not a reserved word
  int bool; // error: bool is a reserved word
  int while; // error: while is a reserved word
  int 3xxx; // error: identifier cannot start with a digit
  int %name; // error: identifier cannot contain a special symbol (except underscore)
  
}
