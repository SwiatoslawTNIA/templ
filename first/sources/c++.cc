//---------------------------------------------------------------------------------------------------------------------
// c++.cc
//
// <Explanation of the program ...>
// <... May have multiple lines.>
//
//---------------------------------------------------------------------------------------------------------------------
//
#include "c++.h"
#include <type_traits>
#include <cstring>
//---------------------------------------------------------------------------------------------------------------------
///
/// This is an example header comment. Here, you explain, what the
/// function does. Copypaste and adapt it!
///
/// @param numbers an array to check
/// @param length The length of the array. If this text is too long you can
///
/// @return the highest number
//

//simple template example:
// template <typename T>
// T max(T a, T b)
// {
//   return a >b?a:b;
// }
// template <typename T1, typename T2>
// std::common_type_t<T1,T2> max(T1 a, T2 b)
// {
//   return a > b ? a: b;
// }
// template <typename RT = double, typename T1, typename T2>
// RT max(T1 a, T2 b)
// {
//   return a>b?a:b;//returns double if not specifying any type, else returns the specific type
//   //if we explicitly declare so:
//   //max(34,23);//returns double(default return type)
//   //max<int>(32.2, 324.3)//returns int, explicit declaration.
// }
// //I can have as many TPs as I want:
// template <typename T1, typename T2, typename T3>
// void max(T1 a, T2 b, T3 c)
// {
//   // return (a > b)?(a > c ? a: (b > c ? b: c));this poses a problem, how to declare a return type??

// }

template <typename T>//for two types
T max(T a, T b)
{
  return a > b?a:b;
}
template <typename T>
T* max(T* a, T*b)//version for two pointers
{
  return *b < *a? a:b;
}

const char *max(const char * s1, const char *s2)//specific overloading for const char *
{
  return strcmp(s1, s2) < 0? s1: s2;
}
int main(void)
{
  using namespace std;
  int i = 7;
  std::cout << "max (7, i) " << ::max(7, i) << std::endl;//int template will be used
  double f1 = 3.4, f2 = -6.7;
  std::cout << "max(f1, f2) " << ::max(f1, f2) << std::endl;//int template
  std::string s1 = "math", s2 = std::string("mathematics");
  std::cout << "max(s1, s2) " << ::max(s1, s2) << std::endl;//std::stirng template(1. one)
  return 0;
}
