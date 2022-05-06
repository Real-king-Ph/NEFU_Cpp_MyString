#include <iostream>

#include "MyString.h"

using namespace std;

int main() {
   string s1, s2;
   cin >> s1 >> s2;
   cout << " Compare " << MyString(s1).Compare(s2) << '\n';
   return 0;
}