#include <iostream>

#include "MyString.h"

using namespace std;

int main() {
   MyString s1, s2;
   cin >> s1 >> s2;
   s1.swap(s2);
   cout << s1 << '\n' << s2 << '\n';

   return 0;
}