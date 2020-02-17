#include <iostream>

template <class T>
struct is_class
{
  //결과 식별용 타입크기
  using yes = char[1];
  using no = char[2];
  
  //멤버에 대한 포인터는 클래스만 적용가능.
  //클래스가 아니면 치환 실패할 것임
  template <class Arg>
  static yes& check(int Arg::*);
  
  //위에꺼가 실패하면 무조건 이게 선택됨
  template <class Arg>
  static no& check(...);
  
  static const bool value = 
    sizeof(check<T>(0)) == sizeof(yes);
};

struct Foo
{};

int main()
{  
  if(is_class<char>::value)
    puts("char은 클래스요");
  else
    puts("char은 클래스가 아니오");
  
  if(is_class<Foo>::value)
    puts("Foo는 클래스요");
  else
    puts("Foo는 클래스가 아니오");
}



    
    
    
