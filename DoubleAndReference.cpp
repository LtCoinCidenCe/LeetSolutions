#include <iostream>
#include <memory>
struct Foo {
  ~Foo() { std::cout << "destruction" << std::endl; }
};

Foo FooFactory() { return Foo(); }

class DoubleAnd {
private:
  int a;

public:
};

int fools()
{
  std::cout << "before copy constructor..." << std::endl;
  Foo foo1 = FooFactory();
  std::cout << "after copy constructor..." << std::endl << std::endl;
  // 引用右值，避免生成新对象
  Foo &&foo2 = FooFactory();
  std::cout << "life time ends!" << std::endl << std::endl;

  return 0;
}

int main()
{
  fools();

  DoubleAnd one;
  // value reference
  DoubleAnd *two = new DoubleAnd(DoubleAnd());
  // const reference
  std::unique_ptr<DoubleAnd> three = std::make_unique<DoubleAnd>(one);

  delete two;
  return 0;
}
