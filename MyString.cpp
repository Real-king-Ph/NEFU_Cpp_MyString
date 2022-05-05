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

#ifdef DEBUG
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
#ifdef DEBUG
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
#ifdef DEBUG
   std::cerr << "a MyString is Generated! \n";
   if (_self != nullptr) {
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
   _self[0] = t;
#ifdef DEBUG
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
      _self[i] = str[i];
   }
   _size = len;

#ifdef DEBUG
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
      _self[i] = str[i];
   }
   _size = len;

#ifdef DEBUG
   std::cerr << "A MyString is Generated! \n";
   std::cerr << *this << '\n';
#endif
}

MyString::MyString(const MyString& str) {
   auto len = str.length();
   recapacity(len);
   for (int i = 0; i != str.length(); i++) {
      (*this)[i] = str[i];
   }
   _size = str.length();

#ifdef DEBUG
   std::cerr << "A MyString is Generated! \n";
   std::cerr << *this << '\n';
#endif
}

// MyString::MyString(int times, const MyString& str) : MyString() {
//    for (int i = 0; i != times; i++) {
//       this->append(str);
//    }
// }

// * * * * * * * * * * *
// * base function
// * * * * * * * * * * *

unsigned MyString::size() const { return _size; }
unsigned MyString::length() const { return this->size(); }

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
   for (int i = 0; i != str.length(); i++) {
      (*this)[i] = str[i];
   }
   _size = str.length();

#ifdef DEBUG
   std::cerr << "MyString = d\n";
   std::cerr << *this << '\n';
#endif
   return *this;
}

// * * * * * * * * * * *
// * advanced function
// * * * * * * * * * * *

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

#ifdef DEBUG
   std::cout << "_self has been deleted!\n";
#endif
}