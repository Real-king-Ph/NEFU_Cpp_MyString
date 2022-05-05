#include <iostream>

#include "MyString.h"

using namespace std;

int main() {
   string s = "xyz";
   MyString x = s;
   for (int i = -3; i < 3; i++) {
      cout << x[i] << '\n';
   }
   x = MyString("uvx");
}