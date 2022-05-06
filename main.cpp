#include <iostream>

#include "MyString.h"

using namespace std;

int main() {
   MyString s1, s2;
   cin >> s1 >> s2;

   cout << s1.find(s2) << '\n';

   return 0;
}