#include <iostream>
using namespace std;

template<class T>
struct ObjectCounter
{
  //타입으로 구체화될때마다 0으로 생성됨
  static int count;
  
  //구체화된 상태에서 생성될 때마다 증가
  ObjectCounter()
  {
    count++;
  }

  //구체화된 상태에서 소멸될 때마다 감소
  ~ObjectCounter()
  {
    count--;
  }
};
template <class T>
int ObjectCounter<T>::count = 0;

struct Boom: public ObjectCounter<Boom>
{};


int main()
{
  cout<<Boom::count<<endl;
  
  {
    Boom a;
    Boom b;
    cout<<Boom::count<<endl;
  }
  
  cout<<Boom::count<<endl;
}
