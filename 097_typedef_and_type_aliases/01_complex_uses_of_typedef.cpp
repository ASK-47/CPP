#include <iostream>

//1 void (*f)(int); // f has type "pointer to function of int returning void"
//typedef void (*f)(int); // f is an alias for "pointer to function of int returning void"

//2 void (Foo::*pmf)(int); // pmf has type "pointer to member function of Foo taking int and returning void"
//typedef void (Foo::*pmf)(int); // pmf is an alias for "pointer to member function of Foo taking int and returning void"

//3 void (Foo::*Foo::f(const char*))(int); ???
//typedef void (Foo::pmf)(int); //// pmf is a pointer to member function type
//pmf Foo::f(const char*);



//4 int (&g())[100]; ???
//typedef int (&ra)[100]; // ra means "reference to array of 100 ints"
// int (&g())[100]; => ra g();


int main() {}