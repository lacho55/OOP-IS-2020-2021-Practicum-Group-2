#include <iostream>
#include <cstring>
using namespace std;
//Да се дефинира шаблон на процедура, която разменя стойностите на две променливи от тип T. 
//В главната функция са направени четири специализации за да се разменят стойностите на две променливи от тип:
//а) int
//б) double
//в) char
template<class T>
  void swap(T& a, T& b)
{
  T temp = a;
	a = b;
  b = temp;
}

int main()
{
  int a = 4, b = 3;
  swap<int>(a, b); // swap(a, b);
  std::cout << a << " " << b << std::endl;
  
  double c = 5.6, d = 6.7;
  swap<double>(c, d);
  std::cout << c <<  " " << d << std::endl;
  return 0;
}