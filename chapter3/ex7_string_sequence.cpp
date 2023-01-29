#include "std_lib_facilities.h"

int main() {
  string word1 = "???";
  string word2 = "???";
  string word3 = "???";
  string min_word;
  string mid_word;
  string max_word;
  cout << "Enter three words: ";
  cin >> word1 >> word2 >> word3;
  if (word1 <= word2 && word1 <= word3) {
    min_word = word1;		   
  } 
  else if (word1 > word2 && word1 < word3) {
    mid_word = word1;
  } 
  else if (word1 > word2 && word1 > word3) {
    max_word = word1;
  }
  if (word1 == min_word && word2 <= word3) {
    mid_word = word2;
    max_word = word3;	
  }
   else if (word1 == min_word && word2 >= word3) {
     max_word = word2;
     mid_word = word3;
   }
   else if (word1 == mid_word && word2 <= word1) {
     min_word = word2;
     max_word = word3;
   }
   else if (word1 == mid_word && word2 >= word1) {
     max_word = word2; 
     min_word = word3;
   }
   else if (word1 == max_word && word2 <= word3) {
     min_word = word2;
     mid_word = word3;
   }
   else if (word1 == max_word && word2 >= word3) {
     min_word = word3;
     mid_word = word2;
   }
  cout << min_word << ", " << mid_word << ", " << max_word << "\n";
  return 0;
} 
