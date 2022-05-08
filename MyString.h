/**
 * @file MyString.h
 * @author Rk_ph (real-king-ph.github.io)
 * @brief NEFU c++ Mystring
 * @version 0.1
 * @date 2022-05-05
 *
 * @copyright Copyright (c) 2022 Rk_ph All right reserved
 */

#ifndef _R_K_STRING_H_E_A_D_E_R_
#define _R_K_STRING_H_E_A_D_E_R_

#include <iostream>
#include <set>

/**
 * @brief MySring is a NEFU_Mirror of std::string
 * @attention MyString will be working like vector
 *
 * This is a special string,
 * because nothing can be done.
 */
class MyString {
  private:
   char* _self = nullptr;  ///< base of MyString
   unsigned _size = 0;     ///< size of MyString
   unsigned _capa = 0;     ///< the capacity of MyString

  private:
   void recapacity(unsigned);
   /**
    * @brief
    * @attention 不能忘记改变 size
    */
   void destory(char*);
   void _self_set(char*);
   void _size_set(unsigned);
   void _capa_set(unsigned);

  public:
   // * construct function
   /**
    * @brief Construct a new My String object
    */
   MyString();
   MyString(char);
   MyString(const char*);
   MyString(const std::string&);
   MyString(const MyString&);
   /**
    * @brief Construct a new My String object
    *
    * @param times
    * @param str
    *
    * 生成 times 次的 str
    * 例如 str = "abc"
    * 3 "abc" --> abcabcabc
    */
   MyString(int times, const MyString& str);
   /**
    * @brief Construct a new My String object
    *
    * @param str
    * @param fir
    * @param len
    *
    * 对一个字符做裁剪，生成从 [fir] 开始长 len 的字符串
    * 例如 "abcde" 1 3
    * bcd
    */
   MyString(const MyString& str, int fir, int len);

   // * base function

   unsigned size() const;
   unsigned length() const;
   const static unsigned npos = 1e9 + 777;

   MyString& append(const MyString&);
   MyString& append(int, const MyString&);
   MyString& append(const MyString&, int, int);
   void swap(MyString&);
   MyString& assign(const MyString& str) {
      return this->operator=(str);
   }
   MyString& assign(int times, const MyString& str) {
      return (*this) = MyString(times, str);
   }
   MyString& assign(const MyString& str, int start, int end) {
      return (*this) = MyString(str, start, end);
   }

   // * operator function
   /**
    * @brief 可以使用下标进行访问
    *
    * @param pos 下标
    * @return char& [const]
    * @attention 确保你的范围在规定内
    *
    * 如果 pos >= 0 那么将从零开始计数
    * 如果 pos < 0 那么将从末尾往前从一开始计数。
    */
   char& operator[](int);
   const char& operator[](int) const;

   MyString& operator=(const MyString&);

   MyString operator+(const MyString&) const;
   MyString& operator+=(const MyString&);

   bool operator<(const MyString&) const;
   bool operator<=(const MyString&) const;
   bool operator>(const MyString&) const;
   bool operator>=(const MyString&) const;
   bool operator==(const MyString&) const;
   bool operator!=(const MyString&) const;

   // * advanced function

   MyString& erase(const MyString&);
   /**
    * @brief 删除 start 后所有字符串
    *
    * @param start
    */
   MyString& erase(int start);
   /**
    * @brief 删除从 start 开始的 size 个字符串
    *
    * @param start
    * @param size
    */
   MyString& erase(int start, int size);

   /**
    * @brief 切割子串
    *
    * @param start 起始点
    * @return MyString 返回从 start 一直到末尾的子串。
    *
    */

   MyString substr(int start) const;
   /**
    * @brief 切割子串
    *
    * @param start
    * @param len
    * @return MyString 返回从 start 开始长尾 len 的子串
    */
   MyString substr(int start, int len) const;

   /**
    * @brief 在 pos 的位置上插入一个字符串
    *
    * @param pos
    * @param str
    * @return MyString&
    */
   MyString& insert(int pos, const MyString& str);

   /**
    * @brief 在 pos 的位置上插入 times 个字符串
    *
    * @param pos
    * @param times
    * @param str
    * @return MyString&
    */
   MyString& insert(int pos, int times, const MyString& str);

   int compare(const MyString&) const;
   int compare(int, int, const MyString&) const;
   int compare(const MyString&, int, int) const;
   int compare(int, int, const MyString&, int, int) const;

   /**
    * @brief 查找子串
    * @param str-MyString 目标
    * @param start 选择从什么地方开始匹配
    * @return signed
    */
   signed find(const MyString&, int start = 0) const;
   signed rfind(const MyString&, int start = 0) const;
   signed find_first_of(const MyString&, int start = 0) const;
   signed find_last_of(const MyString&, int start = 0) const;
   signed find_first_not_of(const MyString&, int start = 0) const;
   signed find_last_not_of(const MyString&, int start = 0) const;

   MyString& replace(const MyString&, const MyString&);
   MyString& replace(int, int, const MyString&);
   MyString& replace(int, int, int, const MyString&);
   MyString& replace(int, int, const MyString&, int, int);
   MyString& replace(int, int, int, const MyString&, int, int);

   // * friend function
   /**
    * @brief Mystream std::out
    *
    * @return std::ostream&
    */
   friend std::ostream& operator<<(std::ostream&, const MyString&);
   friend std::istream& operator>>(std::istream&, MyString&);
   ~MyString();
};

#endif