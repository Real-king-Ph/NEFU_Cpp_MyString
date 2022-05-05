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

#include <cstring>
#include <iostream>
#include <istream>
#include <ostream>

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

   MyString(int, const MyString&);  // TODO: 2 MyString(numb, str)

   MyString(const MyString&, int,
            int);  // TODO: MyString(str ,start ,size)

   // * base function

   unsigned size() const;
   unsigned length() const;

   void append(const MyString&);  // TODO: 1 append

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

   // * advanced function

   // * friend function
   /**
    * @brief Mystream std::out
    *
    * @return std::ostream&
    */
   friend std::ostream& operator<<(std::ostream&, const MyString&);
   ~MyString();
};

#endif