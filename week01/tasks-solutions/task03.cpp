#include<iostream>

template<class T>
void swap(T &x, T& y){

    T temp = x;
    x = y;
    y = temp;
}


int main(){

    int a = 4, b = 9;
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;

    double p = 1.5, q = -5.6;
    swap(p, q);
    std::cout << "p = " << p << ", q = " << q << std::endl;

    char c = 'a', d = 'd';
    swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
}