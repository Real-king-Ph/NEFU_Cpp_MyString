#include <iostream>

#include "MyString.h"

using namespace std;

int main() {
   cout << MyString("abcdefg").substr(1, 3) << '\n';
   return 0;
}