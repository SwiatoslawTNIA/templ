#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <deque>
// template <typename T>
// class A
// {
//    std::vector<T> v;
// public:
//    void push(const T&) noexcept;
//    void pop(void) noexcept;
//    const T& top(void) const noexcept;
//    bool empty(void) const noexcept {return v.size() == 0;}
// };
// template<typename T>
// void A<T>::push(const T& ref) noexcept
// {
//    v.push_back(ref);
// }
// template<typename T>
// void A<T>::pop(void) noexcept
// {
//    assert(!empty());
//    v.pop_back();
// }
// template <typename T>
// const T& A<T>::top(void) const noexcept
// {
//    assert(!empty());
//    return v.back();//
// }

// //a class specialization for the type std::string:
// template <>
// class A<std::string>
// {
//    std::vector<std::string> v;
// public:
//    void push(const std::string & r) noexcept;
//    void pop(void) noexcept;
//    const std::string & top(void) const noexcept;
//    bool empty(void) const noexcept {return v.size() == 0;}

// }
// void A<std::string>::push(const std::string & r) noexcept
// {
//    v.push_back(r);
// }
// void A<std::string>::pop(void) noexcept
// {
//    assert(!empty());
//    v.pop_back();
// }
// const std::string & A<std::string>::top(void) const noexcept
// {
//    assert(!empty());
//    return v.back();//return the element at the top of the stack
// }


template <typename T, typename Cont = std::vector<T>>
class A
{
   Cont elems;
public:
   void push(const T& obj) noexcept;
   void pop(void) noexcept;
   bool empty(void) const noexcept;
   const T& top(void) const noexcept;
};
template <typename T, typename Cont>
void A<T,Cont>::push(const T& obj) noexcept
{
   elems.push_back(obj);
}
template <typename T, typename Cont>
void A<T,Cont>::pop(void) noexcept
{
   assert(!empty());//nonzero true, otherwise false
   elems.pop_back();
}
template<typename T, typename Cont>
bool A<T,Cont>::empty(void) const noexcept
{
   return elems.size() == 0;
}
template<typename T, typename Cont>
const T& A<T,Cont>::top(void) const noexcept
{
   assert(!empty());
   return elems.back();
}
template<typename T1, typename T2 = int, typename T3 = int, typename T4 = int>
void print(int n)
{
   std::cout << "done";
}
template<typename T1, typename T2, typename T3 = int, typename T4 = int>
void print2(int n)
{
   std::cout << "done";
}
template<typename T2>
void print3(int bz)
{
   std::cout << "done";
}


 template <typename T>
 using dequeue = A<T, std::deque<T>>;//dequeue is a type alias for Stack<T, std::deque<T>>
   //so instead of writing Stack<int, std::deque<int>> we would write dequeue<int>
template <typename T>
class Stack
{
   std::vector<T> elems;
public:
   Stack() = default;//request a defualt constructor
   Stack(const Stack & r): elems({r}){}//r is passed to the copy constructor and 
   //elems are initialized to a vector with a single arg, with elems(r) would mean a vector with r args, with no value
}
int main(void)
{
   A<int> stack;//stack of ints
   A<std::string> stack2;//stack of std::string
   dequeue<int> intS;
   intS.push(3424);
   std::cout << "Element: " << intS.top() << std::endl;
   stack.push(7);
   std::cout << stack.top() << std::endl;

   stack2.push("Hi");
   std::cout << stack2.top() << std::endl;
   stack.pop();
   //use the version with two params:
   A<double, std::deque<double>> arr;
   arr.push(34.32);
   std::cout << arr.top() << std::endl;
   arr.pop();
   // std::cout << arr.top();
   print<int>(2);
   print2<int, double>(5);
   print3<int>(14);


   
   
   return 0;
}