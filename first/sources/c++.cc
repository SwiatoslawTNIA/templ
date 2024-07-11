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
//the larger size I specify, the more data can go unused, the less size I specify, 
//the more likely, that the stack can get full
template<typename T, std::size_t MaxSize>
class Stack
{
  private:
    std::array<T, MaxSize> elems;
    std::size_t numElems;
  public:
    Stack();
    void push(const T &ref) noexcept;
    void pop(void) noexcept;
    T const& top(void) const noexcept {return elems[0];}
    bool empty(void) const noexcept {return elems.size();}
    std::size_t size(void) const noexcept
};
template<typename T, std::size_t MaxSize>
Stack<T,MaxSize>::Stack(): numElems(0){}
//a default constructor template for tor two args
template<typename T, std::size_t MaxSize>
void Stack<T,MaxSize>::push(const T& ref) noexcept
{
  assert(numElems < MaxSize);// the number of the elements should be less than the MaxSize of the array
  elems[numElems++] = ref;
}
template<typename T, std::size_t MaxSize>
void Stack<T,MaxSize>::pop(void) noexcept
{
  assert(numElems > 0);
  --numElems;//since it's an array
}
template<typename T, std::size_t MaxSize>
const T& Stack<T,MaxSize>::top(void) const noexcept 
{
  assert(numElems > 0);
  return elems[numElems - 1];
}//to use the template, we have to specify both the param type and the arr_size:


int main(void)
{
  using namespace std;
  // int i = 7;
  // std::cout << "max (7, i) " << ::max(7, i) << std::endl;//int template will be used
  // double f1 = 3.4, f2 = -6.7;
  // std::cout << "max(f1, f2) " << ::max(f1, f2) << std::endl;//int template
  // std::string s1 = "math", s2 = std::string("mathematics");
  // std::cout << "max(s1, s2) " << ::max(s1, s2) << std::endl;//std::stirng template(1. one)
  Stack<int, 20> stack1;//stack of up to 20 ints
  Stack<int, 40> stack2;//stack of up to 40 ints;
  Stack<std::string, 40> strings;
  //manipulating the stack:
  stack1.push(17);
  std::cout << stack1.top() << "\n";
  stack1.pop();//remove the first element in the stack
  strings.push("What a wonderful world");
  std::cout << strings.top() << std::endl;
  strings.pop();//pop th e
  return 0;
}
