#include <iostream>

#include "MyString.h"

using namespace std;

int main() {
   MyString s1("Limitless"), s2("00");
   cout << s1.insert(2, "123") << '\n';
   //在下标 2 处插入字符串"123"，s1 = "Li123mitless"
   cout << s1.insert(3, s2) << '\n';
   //在下标 2 处插入 s2 , s1 = "Li10023mitless"
   cout << s1.insert(3, 5, 'X') << '\n';
   //在下标 3 处插入 5 个 'X'，s1 = "Li1XXXXX0023mitless"
}