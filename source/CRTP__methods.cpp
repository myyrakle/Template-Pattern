#include <iostream>
using namespace std;

template <class ImplType>
class Runnable
{
public:
  void run() const
  {
    static_cast<const ImplType*>(this)->run();
  }
};

class BoomRun: public Runnable<BoomRun>
{
public:
  void run() const
  {
    cout<<"붐!!"<<'\n';
  }
};

class FooRun: public Runnable<FooRun>
{
public:
  void run() const
  {
    cout<<"foo bar"<<'\n';
  }
};

template <class T>
void just_run(const Runnable<T>& runner)
{
  runner.run();
}

int main()
{
  just_run(BoomRun());
  just_run(FooRun());
  
  Runnable<BoomRun> boom = BoomRun();
  boom.run();
  
  Runnable<FooRun> foo = FooRun();
  foo.run();
}
