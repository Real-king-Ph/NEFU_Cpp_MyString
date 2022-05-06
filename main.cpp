#include <iostream>

#include "MyString.h"

using namespace std;

int main() {
   MyString s1;
   cout << s1 << endl;
   MyString s2("Hello");
   cout << s2 << endl;
   MyString s3(4, 'K');
   cout << s3 << endl;
   MyString s4("12345", 1, 3);
   cout << s4 << endl;
}