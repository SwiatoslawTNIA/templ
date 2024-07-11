#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <deque>
#ifdef PART_1
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
   std::cout << "done" << n << std::endl;
}
template<typename T1, typename T2, typename T3 = int, typename T4 = int>
void print2(int n)
{
   std::cout << "done" << n << std::endl;
}
template<typename T2>
void print3(int bz)
{
   std::cout << "done" << bz << std::endl;
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
};
int main(void)
{
   // A<int> stack;//stack of ints
   // A<std::string> stack2;//stack of std::string
   // dequeue<int> intS;
   // intS.push(3424);
   // std::cout << "Element: " << intS.top() << std::endl;
   // stack.push(7);
   // std::cout << stack.top() << std::endl;

   // stack2.push("Hi");
   // std::cout << stack2.top() << std::endl;
   // stack.pop();
   // //use the version with two params:
   // A<double, std::deque<double>> arr;
   // arr.push(34.32);
   // std::cout << arr.top() << std::endl;
   // arr.pop();
   // // std::cout << arr.top();
   // print<int>(2);
   // print2<int, double>(5);
   // print3<int>(14);
   return 0;
}

template <typename T>
void insertion_sort(T *arr, std::size_t size)
{
   for(int j = 1;static_cast<unsigned long>(j) < size; ++j)
   {
      T key = arr[j];
      int i = j - 1;
      while(i >= 0 && arr[i] > key)
         arr[i + 1] = arr[i--];
      arr[i + 1] = key;//reassign the key
   }
}
template<typename T>
void merge_S(T *arr, std::size_t start, std::size_t end)
{
   if(start < end)//if start >= end, then the array is sorted
   {
      std::size_t mid = start + (end - start) / 2 ;
      merge_S(arr, start, mid);
      merge_S(arr, mid + 1, end);
      merge_merge(arr, start, mid, end);
   }
}
template<typename T>
void merge_merge(T * arr, std::size_t start, std::size_t mid, std::size_t end)
{
   std::size_t length_l = mid - start + 1;//mid included
   std::size_t length_r = end - mid;//mod not included
   T arr_l[length_l + 1];
   T arr_r[length_r + 1];
   std::size_t i = 0, j = 0;

   for(;i < length_l;++i)
      arr_l[i] = arr[i + start];
   arr_l[i] = std::numeric_limits<T>::max();

   for(; j < length_r; ++j)
      arr_r[j] = arr[j + mid + 1];
   arr_r[i] = std::numeric_limits<T>::max();

   //copy:
   i = j = 0;
   std::size_t k = start;
   while(i < length_l && j < length_r)
   {
      if(arr_l[i] <= arr_r[j])
         arr[k++] = arr_l[i++];
      else
         arr[k++] = arr_r[j++];
   }
   if(i < length_l)
      while(i < length_l)
         arr[k++] = arr_l[i++];
   if(j < length_r)
      while(j < length_r)
         arr[k++] = arr_l[j++];
   
}
#endif
template<typename T, std::size_t Maxsize>
  class Stack {
private:
   std::array<T,Maxsize> elems; // elements
   std::size_t numElems; // current number of elements
public:
    Stack();
    void push(T const& elem);
    void pop();
    T const& top() const;
    bool empty() const {return numElems == 0;}
    std::size_t size() const {return numElems;} 
};
// constructor
// push element
// pop element
// return top element
// return whether the stack is empty
// return current number of elements
 template<typename T, std::size_t Maxsize>
 Stack<T,Maxsize>::Stack ()
: numElems(0) // start with no elements 
{
// nothing else to do
}
 template<typename T, std::size_t Maxsize>
 //instead of the typename we can put either *T or &T or int types(size_t = unsigned long), long long, short, int, ....
 void Stack<T,Maxsize>::push (T const& elem)
 {
   assert(numElems < Maxsize);
   elems[numElems] = elem; // append element ++numElems; // increment number of elements
}
template<typename T, std::size_t Maxsize>
void Stack<T,Maxsize>::pop (void)
{
   assert(!elems.empty());
   --numElems; // decrement number of elements 
}
 template<typename T, std::size_t Maxsize>
 T const& Stack<T,Maxsize>::top () const
 {
   assert(!elems.empty());
   return elems[numElems-1]; // return last element
}
//to derive a param from the previous arg:
template<auto Val, typename T = decltype(Val)>
T something(void) noexcept
{

}
// template<const char *T>
// class Myclass
// {
//    std::string first_name;
// public:
//    MyClass(): 
// };


//with the new template 
template <typename T, auto MaxSize>
//the restrictions on nontype params remain the same
//so Stacking<34,23.12> //Error, the floating-point type is not allowed

class Stacking
{
public:
   using size_type = decltype(MaxSize);//define the type of MaxSize
private:
   std::array<T,MaxSize> arr;
   size_type numElems;//tracks the number of elements
public:
   Stacking();//default
   void push(const T & r) noexcept;
   void pop(void) noexcept;
   const T &top(void) const noexcept;
   bool empty(void) const noexcept{return numElems == 0;}
   size_type size(void) const noexcept{return numElems;}

};

//constructor:
template<typename T, auto MaxSize>
Stacking<T,MaxSize>::Stacking(void): numElems(0){}

template<typename T, auto MaxSize>
void Stacking<T,MaxSize>::push(const T & ref) noexcept
{
   assert(numElems < MaxSize);
   arr[numElems++] = ref;
}
template<typename T, auto MaxSize>
void Stacking<T,MaxSize>::pop(void) noexcept 
{
   assert(!empty());//check if the array is not empty
   --numElems;
}

template<typename T, auto MaxSize>
const T & Stacking<T,MaxSize>::top(void) const noexcept
{
   assert(!empty());
   return arr[numElems - 1];
}


//because strings can be passed as const arrays,
//we can do the following:
template< auto T>
class Message
{
   public:
      void print(void) const noexcept { std::cout << T << std::endl;}
};
int main(void) 
{
   //using the stacking template:
   Stacking<int, 20u> int20U;
   Stacking<std::string, 40> strings;
   int20U.push(24);
   std::cout << int20U.top() << std::endl;
   auto size_1 = int20U.size();//manipulate the strings
   strings.push("432");
   std::cout << strings.top() << std::endl;
   auto size_2 = strings.size();
   std::cout << "The diff: " << size_2 - size_1;//therefore the difference is undefined, 
   //the compiler can't compute the diff, since the types of args are different;
   //the types of size_1 and size_2 differ:

   //to check that the types differ:
   if(!std::is_same_v<decltype(size_1), decltype(size_2)>)//is true
   {
      std::cout << "The types of size_1 and size_2 differ";
   }
   static const char s[] = "An example";
   Message<s> var;//if static is not defined, error: expression must have a const value,
   //since static is added, we must add const, because we would not like to change the 
   //memory in static so often

   var.print();
   return 0;
}
//for funcs the types of args can be deduced from the arg list, if these types are present there,
//or by assigning default values.
//for classes, each type has to be declared specifically, unless the consructor can deduce the type
//from the args, or by assigning a default values;
