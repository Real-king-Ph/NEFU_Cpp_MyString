#include "MyString.h"

// * ----------------------------------------------
// * private function
// * ----------------------------------------------
/**
 * @brief 重新分配内存
 *
 * @param size
 */
void MyString::recapacity(unsigned size) {
   if (_capa > size) return;

   // rechange _capa
   if (_capa == 0) _capa = 1;
   while (_capa < size) _capa <<= 1;

   // allocate
   auto new_ch = _self;
   new_ch = new char[_capa];

   // copy back

   for (auto i = 0u; i != _size; i++) {
      new_ch[i] = _self[i];
   }

   if (_self != nullptr) delete _self;
   _self = new_ch;

#ifdef _DEBUG
   std::cout << "_capa has been reset!\n";
#endif
}

/**
 * @brief 摧毁一个 char*
 *
 * @param target
 */
void MyString::destory(char* target) {
   if (target != nullptr) delete (target);
#ifdef _DEBUG
   std::cout << "target has been deleted!\n";
#endif
}

void MyString::_self_set(char* _oth) { _self = _oth; }
void MyString::_size_set(unsigned t) { _size = t; }
void MyString::_capa_set(unsigned t) { _capa = t; }

// * ----------------------------------------------
// * public function
// * ----------------------------------------------

// * * * * * * * * * * * *
// * construct function
// * * * * * * * * * * * *

/**
 * @brief Construct a new My String:: My String object
 *
 */
MyString::MyString() {
   recapacity(0);
#ifdef _DEBUG
   std::cerr << "a MyString is Generated! \n";
   if (_self == nullptr) {
      std::cerr << "wrong !\n";
      exit(-1);
   }
#endif
}

/**
 * @brief Construct a new My String:: My String object
 *
 * @param t
 */
MyString::MyString(char t) {
   recapacity(1);
   (*this)[0] = t;
   _size = 1;
#ifdef _DEBUG
   std::cerr << "A MyString is Generated! \n";
   std::cerr << *this << '\n';
#endif
}

/**
 * @brief Construct a new My String:: My String object
 *
 * @param str
 */
MyString::MyString(const char* str) {
   auto len = strlen(str);
   recapacity(len);
   for (unsigned i = 0; i != len; i++) {
      (*this)[i] = str[i];
   }
   _size = len;

#ifdef _DEBUG
   std::cerr << "A MyString is Generated! \n";
   std::cerr << *this << '\n';
#endif
}

/**
 * @brief Construct a new My String:: My String object
 *
 * @param str
 */
MyString::MyString(const std::string& str) {
   auto len = str.length();
   recapacity(len);
   for (unsigned i = 0; i != len; i++) {
      (*this)[i] = str[i];
   }
   _size = len;

#ifdef _DEBUG
   std::cerr << "A MyString is Generated! \n";
   std::cerr << *this << '\n';
#endif
}

MyString::MyString(const MyString& str) {
   auto len = str.length();
   recapacity(len);
   for (unsigned i = 0; i != str.length(); i++) {
      (*this)[i] = str[i];
   }
   _size = str.length();

#ifdef _DEBUG
   std::cerr << "A MyString is Generated! \n";
   std::cerr << *this << '\n';
#endif
}

MyString::MyString(int times, const MyString& str) : MyString() {
   for (int i = 0; i != times; i++) {
      this->append(str);
   }
#ifdef _DEBUG
   std::cerr << "A multi MyString is Generated! \n";
   std::cerr << *this << '\n';
#endif
}

MyString::MyString(const MyString& str, int start, int leng) {
   recapacity(leng);
   for (int i = 0; i != leng; i++) {
      (*this)[i] = str[i + start];
   }
   _size = leng;

#ifdef _DEBUG
   std::cerr << "MyString has Generated! div success!\n";
   std::cerr << *this << '\n';
#endif
}

// * * * * * * * * * * *
// * base function
// * * * * * * * * * * *

unsigned MyString::size() const { return _size; }
unsigned MyString::length() const { return this->size(); }

MyString& MyString::append(const MyString& str) {
   recapacity(_size + str.length());
   for (auto i = _size; i != _size + str.length(); i++) {
      (*this)[i] = str[i - _size];
   }
   _size += str.length();
#ifdef _DEBUG
   std::cout << "append once\n";
   std::cout << *this << '\n';
#endif
   return *this;
}

// * * * * * * * * * * *
// * operator function
// * * * * * * * * * * *

char& MyString::operator[](int pos) {
   if (pos < 0) pos += size();
   return *(_self + pos);
}

const char& MyString::operator[](int pos) const {
   if (pos < 0) pos += size();
   return *(_self + pos);
}

MyString& MyString::operator=(const MyString& str) {
   auto len = str.length();
   recapacity(len);
   for (unsigned i = 0u; i != str.length(); i++) {
      (*this)[i] = str[i];
   }
   _size = str.length();

#ifdef _DEBUG
   std::cerr << "function = is running\n";
   std::cerr << *this << '\n';
#endif
   return *this;
}

MyString MyString::operator+(const MyString& str) const {
   MyString tmp = *this;
   tmp.append(str);

#ifdef _DEBUG
   std::cerr << "function + is running\n";
   std::cerr << "return value is : " << tmp << '\n';
#endif
   return tmp;
}

MyString& MyString::operator+=(const MyString& str) {
   return this->append(str);
}

// * * * * * * * * * * *
// * advanced function
// * * * * * * * * * * *

MyString MyString::substr(int start) const {
   return MyString((*this), start, (*this).length() - start);
}

MyString MyString::substr(int start, int len) const {
   return MyString((*this), start, len);
}

// * ----------------------------------------------
// * friend function
// * ----------------------------------------------

std::ostream& operator<<(std::ostream& out, const MyString& str) {
   for (unsigned i = 0; i != str._size; i++) {
      out << str._self[i];
   }
   return out;
}

MyString::~MyString() {
   if (_self != nullptr) delete _self;
   _size = 0, _capa = 0;

#ifdef _DEBUG
   std::cerr << "_self has been deleted!\n";
#endif
}
