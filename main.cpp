#include <iostream>

#include "MyString.h"

//#define _SELECT
//如果完成了选做内容，请将此宏_SELECT定义前的注释符号删除

#ifndef _SELECT
#include <cstring>
#include <sstream>
#include <string>
#endif

using namespace std;

// 请将完成的所有代码粘贴在此处，包括类的声明和所有定义
// ,并注释掉下面一行语句
// typedef string MyString;
//测试时请注释掉上面一行语句

#define output(x) cout << #x << " = " << x << '\n';

int main() {
   {  output("test 1")                             //测试1
      MyString s1;                 // si = ""
      MyString s2("Hello");        // s2 = "Hello"
      MyString s3(4, 'K');         // s3 = "KKKK"
      MyString s4("12345", 1, 3);  // s4 = "234"，即 "12345" 的从下标
                                   // 1 开始，长度为 3 的子串
      output(s1)
      output(s2)
      output(s3)
      output(s4)
   }

   {
      {
         output("test 2")
         MyString s1, s2;
         s1 = "Hello";  // s1 = "Hello"
         s2 = 'K';      // s2 = "K”
         output(s1)
         output(s2)
      }

      {
         MyString s1("12345"), s2, s3;
         s3.assign(s1);  // s3 = s1
         output(s3)
         s2.assign(s1, 1, 2);  // s2 = "23"，即 s1 的子串(1, 2)
         output(s2)
         s2.assign(4, 'K');  // s2 = "KKKK"
         output(s2)
         s2.assign("abcde", 2, 3);  // s2 = "cde"，即 "abcde" 的子串(2, 3)
         output(s2)
      }
   }

   {  //测试3
      output("test 3")
      MyString s1("12345"), s2;
      output(s1.length())
      output(s2.size())
   }

   {  //测试4
      output("test 4")
      MyString s1("123"), s2("abc");
      s1.append(s2);  // s1 = "123abc"
      output(s1)
      s1.append(s2, 1, 2);  // s1 = "123abcbc"
      output(s1)
      s1.append(3, 'K');  // s1 = "123abcbcKKK"
      output(s1)
      s1.append("ABCDE", 2,
                3);  // s1 = "123abcbcKKKCDE"，添加 "ABCDE" 的子串(2, 3)
      output(s1)
   }

   {  //测试5
      output("test 5")
      MyString s1("hello"), s2("hello, world");
      cout << (s1 > s2) << (s1 < s2) << (s1 >= s2) << (s1 <= s2)
           << (s1 == s2) << (s1 != s2) << '\n';
      int n = s1.compare(s2);
      output(n)
      n = s1.compare(1, 2, s2, 0,
                     3);  //比较s1的子串 (1,2) 和s2的子串 (0,3)
      output(n)
      n = s1.compare(0, 2, s2);  // 比较s1的子串 (0,2) 和 s2
      output(n)
      n = s1.compare("Hello");
      output(n)
      n = s1.compare(1, 2, "Hello");  //比较 s1 的子串(1,2)和"Hello”
      output(n)
      n = s1.compare(1, 2, "Hello", 1,
                     2);  //比较 s1 的子串(1,2)和 "Hello" 的子串(1,2)
      output(n)
   }

   {  //测试6
      output("test 6")
      MyString s1 = "this is ok";
      MyString s2 = s1.substr(2, 4);  // s2 = "is i"
      output(s1)
      output(s2)
      s2 = s1.substr(2);  // s2 = "is is ok"
      output(s2)
   }

   {  //测试7
      output("test 7")
      MyString s1("West"), s2("East");
      output(s1) 
      output(s2)
      s1.swap(s2);  // s1 = "East"，s2 = "West"
      output(s1) 
      output(s2)
   }

   {  //测试8
      output("test 8")
      MyString s1("Source Code");
      size_t n;

      if ((n = s1.find('u')) != MyString::npos)  //查找 u 出现的位置
         cout << "1) " << n << "," << s1.substr(n) << '\n';
      //输出 l)2,urce Code
      if ((n = s1.find("Source", 3)) ==
          MyString::npos)  //从下标3开始查找"Source"，找不到
         cout << "2) "
              << "Not Found" << '\n'; //输出 2) Not Found
      if ((n = s1.find("Co")) !=
          MyString::npos)  //查找子串"Co"。能找到，返回"Co"的位置
         cout << "3) " << n << ", " << s1.substr(n)<< '\n';
      //输出 3) 7, Code
      if ((n = s1.find_first_of("ceo")) !=
          MyString::npos)  //查找第一次出现或 'c'、'e'或'o'的位置
         cout << "4) " << n << ", " << s1.substr(n)<< '\n';
      //输出 4) l, ource Code
      if ((n = s1.find_last_of('e')) !=
          MyString::npos)  //查找最后一个 'e' 的位置
         cout << "5) " << n << ", " << s1.substr(n)<< '\n';
      //输出 5) 10, e
      if ((n = s1.find_first_not_of("eou", 1)) !=
          MyString::npos)  //从下标1开始查找第一次出现非 'e'、'o' 或 'u'
                           //字符的位置
         cout << "6) " << n << ", " << s1.substr(n)<< '\n';
      //输出 6) 3, rce Code
   }

   {  //测试9
      output("test 9")
      MyString s1("Real Steel");
      output(s1)
      s1.replace(1, 3, "123456", 2,
                 4);  //用 "123456" 的子串(2,4) 替换 s1 的子串(1,3)
      output(s1)     //输出 R3456 Steel

      MyString s2("Harry Potter");
      output(s2)
      s2.replace(2, 3, 5, '0');  //用 5 个 '0' 替换子串(2,3)
      output(s2)                //输出 Ha00000 Potter

      size_t n = s2.find("00000");  //查找子串 "00000" 的位置，n=2
      output(n)                   //输出2
      s2.replace(n, 5, "XXX");      //将子串(n,5)替换为"XXX"
      output(s2)                 //输出 HaXXX Potter
   }

   {  //测试10
      output("test 10")
      MyString s1("Real Steel");
      output(s1)
      s1.erase(1, 3);  //删除子串(1, 3)，此后 s1 = "R Steel"
      output(s1)
      s1.erase(5);  //删除下标5及其后面的所有字符，此后 s1 = "R Ste"
      output(s1)
   }

   {  //测试11
      output("test 11")
      MyString s1("Limitless"), s2("00");
      cout << s1 << s2;
      s1.insert(
          2, "123");  //在下标 2 处插入字符串"123"，s1 = "Li123mitless"
      output(s1)
      s1.insert(3, s2);  //在下标 2 处插入 s2 , s1 = "Li10023mitless"
      output(s1)
      s1.insert(
          3, 5,
          'X');  //在下标 3 处插入 5 个 'X'，s1 = "Li1XXXXX0023mitless"
      output(s1)
   }

   {  //测试12  选做部分
#ifdef _SELECT
      //没有完成选作部分则使用string类和istringstream类测试
      MyString src("Avatar 123 5.2 Titanic K");
      istringstream istrStream(src);  //建立src到istrStream的联系
      MyString s1, s2;
      int n;
      double d;
      char c;
      istrStream >> s1 >> n >> d >> s2 >>
          c;  //把src的内容当做输入流进行读取

      ostringstream ostrStream;
      ostrStream << s1 << s2 << n << d << c;
      cout << ostrStream.str() << endl;


      //如果完成选作部分则使用MyString类和iMyStringstream类测试
      MyString src("Avatar 123 5.2 Titanic K");
      iMyStringstream istrStream(src);  //建立src到istrStream的联系
      MyString s1, s2;

      int n;
      double d;
      char c;
      istrStream >> s1 >> n >> d >> s2 >>
          c;  //把src的内容当做输入流进行读取
      oMyStringstream ostrStream;
      ostrStream << s1 << s2 << n << d << c;
      cout << ostrStream.str() << endl;

#endif  // _SELECT
   }

   return 0;
}
