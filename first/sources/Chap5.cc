#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <cstdlib>
#ifndef PART_1
//the typename keyword:
template <typename T>
class A
{
public: 
    void f(void) 
    {
        //here the second typename is used to clarify that SubType is used inside a class T
        //thus ptr is a pointer to the type SubType*;
        typename T::SubType* ptr;
        //without typename, SubType would be nontype member:
        //static mem, or enum const
        //thus T::SubType* ptr would be a multiplication of T::SubType with ptr;

    }
    

};
//zero initialization:
    //for fundamental types there is no defualt constructor, if the var is not defined,
    //the results may be devastating, to explicitly call a default constructor on 
    //basic_types, so that the values are initialized:
template <typename T>
void f(void) 
{
    T x{};//value initialization: call a provided constructor, or initialize a value to 0
    // T x = T();//before c++11, the syntax to ensure proper initialization
}
//to ensure that a class member, whose type is parameterized gets initialized, I can write
//a default constructor the following way:
template<typename T>
class MyClass
{
private:
    T x;
public:
    MyClass(): x{} {/*...*/}//ensures that x is initialized even for built-in types
    //pre c++11 syntax was: MyClass(): x() {...}

};
//since c++11 I can also provide a default initialization for a nonstatic member:
//following is also possible:
template<typename T>
class m
{
    private:
    T x{};//provide a default initialization for a nonstatic member(static members don't 
    //need default initialization, they have it built-in)
};
//however: 
// template<typename T>
// void f(T arg{}){/*...*/}//Error: default args can't use this syntax
//write template<typename T>
//void f(T arg = T{}){...}//the correct syntax, before c++17 T() must be used

//template for raw arrays and string literals:
//if template args are declared as refs, the args don't decay:("hello" becomes char (&)[6])

template<typename T, int M, int N>
bool less(T (&a)[N], T (&b)[M])//takes 
{
    for(int i = 0; i < N && i < M;++i)
    {
        if(a[i] >= b[i])
            return false;
    }
    return N < M;
}
//member templates can exist both in member funcs and in nested classes,
//member templates can be assigned to each other only if they have the same type
//Stack<double> a1 = {1,2,34}, a2 = {4,32,324.324};
//Stack<int> k = {12,3,4,13"}; a1 = k;//false
//the default assignment operator requires that both sides are of the same type, to 
//move two different types available:
class Stac
{//specialization of member func templates:
private:
    std::string s;
public: 
    Stac(const std::string & r): s(r) {}
    template<typename T = std::string>
    T get(void) const
    {
        return s;//through this function, I can access the Stac's member s, 
        //or when redefined, the original value will be converted from std::string to the defined type
    }

};
//the func specialization for the type bool (get):
template<>
bool Stac::get<bool>(void) const
{
    return s == "true" || s == "1" || s == "on";//we determine the truthfullness on the private
    //param std::string

}
 void f(void);
int main(void) 
{
    int x[] = {1, 2, 3};
    int y[] = {1, 2, 3, 4, 5};
    std::cout << less(x,y) << "\n";
    //less is instantiated with T being int, N = 3, M = 5;
    //we  dont directly use less<int,5,3>(x,y) because the compiler can deduce the types 
    //from the args passed.
    //the same template can be used for string literal:
    std::cout << less("abc", "abc") << std::endl;//flushes the obuffer, + adds a new line
    f();
    
}
#endif

//variable templates:(can be used for different translation units, since var is declared
//globally = static storage duration, external linkage, global scope.))
    //define the value of Pi, while still not defining the type of the value:
    
template<typename T>
constexpr T pi = {3.14159};//a template var, type is undefined, 
//?constexpr::
 void f(void)
 {
    //to use a variable template(variable is a noun) we have to specify its type:
    // std::cout << "Type int: " << pi<int> << std::endl;//int can't be used, since pi is constexpr +
    //pi is floating-point type
    std::cout << "Type double: " << pi<double> << std::endl;
    std::cout << "Type float: " << pi<float> << std::endl;


 }
//  //     header.hpp: template<typename T> T val{};
// //     translation unit 1: #include "header.hpp"
// int main() {
//      val<long> = 42;
// print(); }
// // translation unit 2: #include "header.hpp"
//    void print()
//{std::cout << val<long> << std::endl;}


//->variable templates can have a default typename types:
template<typename T = long double>
constexpr T pi_1{3.1415926535897932385};
//now if I call just pi_1<>, that will imply pi_1<long double> instantiation
//!!! if pi_1<double> will yield double type
//! pi_1 is ERROR:



//variable templates can be parameterized by nontype params:
template<int N>
std::array<int, N> ar{};//the second arg is passed explicitly through <> notation, 
//if N is zero, then std::array is still initialized through a default constructor()
//zero initialization


template<auto N>
//decltype will be deduce from N alone, this is not the same as decltype(auto(N))!!!
constexpr decltype(N) dval = N;//type of dval depends on passed value;

//example:
int main(void)
{
    std::cout << dval<'c'> << std::endl;
    ar<10>[0] = 12;//first element of the ar(length 10, )
    return 0;
}
