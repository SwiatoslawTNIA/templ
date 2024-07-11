#include <iostream>
#include <cassert>//for assert
#include <cstdlib>//for rand, exit...
//templates that can take an unbounded amount of args, are called variadic:
//Example:
//call print with n elems:
void print(void) {}//for case with 0 elements, overwrite the template
template<typename T, typename... Types>//since typenames are infinite, we add "..." to typename, not Args
//template can be only types, or ref, pointer, int types, nothing else!!!
void print(T first_arg,Types... args)
{
    std::cout << first_arg << std::endl;
    //sizeof... prints the number of the remaining args:
    std::cout << "The number of remaining args: " << sizeof...(args) << std::endl;
    //sizeof...(Types) prints the number of the remaining types:
    std::cout << "The number of remaining types: " << sizeof...(Types) << std::endl;
    //the value is printed even for 0, even though with zero args, the default 
    //main print version should have been applied

    print(args...);
}
//2.Compute the result of the binary operator using ...:
// template<typename... T>
// auto plus(T... args)//return type must be auto, since we're returning,
// {
//     return(... + args);//?????
// }
int main(void) 
{
    print("something", 14, -3.23l, "wow");
    //the call expands to print<const char *, int, long double, const char*>(...);
    //with T is type const char *, so print prints it, then passes to itself only 3 args
    //now print<int,long double, const char*>(...);
    //now `T is int, so print prints int, passes to itself two args;
    //now print<long double, const char *>(...);
    //now T is long double...
    //now print<const char *>(...);
    //now T is const char *, ..., passes to itself void
    //for void we overwrite the template: the default 
    // plus(2,3,4,4,3,3,2,3);
    return 0;
}//I will read more about variadic templates later