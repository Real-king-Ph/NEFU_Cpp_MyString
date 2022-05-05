#include <iostream>

#include "MyString.h"

using namespace std;

int main() {
   char a[] = "abc";
   MyString(4, 'K');
   MyString(4, "xyz");
   MyString(2, a);
   string texxt("112");
   MyString x(3, texxt);
   MyString(3, x);
}