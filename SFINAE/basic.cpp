#include <iostream>
using namespace std;

template <class T>
void foo(T t)
{
  puts("첫번째요");
}

template <class T>
void foo(typename T::NoType t)
{
  puts("두번째요");
}

struct Foo
{
  using NoType = int;
};

int main()
{  
  foo<int>(34); // int::Notype은 유효하지 않음
  foo<Foo>(99); // Foo::Notype은 유효함. int.
}
