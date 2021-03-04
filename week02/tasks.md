# Задача 1

<h3>Да се намери резултатът от изпълнението на програмата:

```C++
#include<iostream>

class A {
    public:
        void Hello();
};

void A::Hello(){
    std::cout << "Hello world!\n";
}

int main(){
    A object;
    object.Hello();

    return 0;
}

```
</h3>

## Задача 2
<h3>
Да се намери резултатът от изпълнението на програмата: 

```C++
#include<iostream>

class B {
    public:
        int a, b;
        void init(int, int);
};

void B::init(int x, int y){
    a = x;
    b = y;
}


int main(){
    B obj;

    obj.init(5, 8);
    //Какво ще стане ако a и b не бяха public , а private ?
    std::cout << obj.a << " " << obj.b << std::endl;

    return 0;
}

```

</h3>


## Задача 3
<h3>
Да се намери резултатът от изпълнението на програмата: 

```C++
#include<iostream>

class C {
    private:
        int a, b;
    public:
        void init(int, int);
        void display() const;
};

void C::init(int x, int y){
    a = x;
    b = y;
}

void C::display() const{
    std:: cout << a << " " << b << std::endl;
}

int main(){
    C obj;

    obj.init(5, 8);
    obj.display();

    return 0;
}

```
</h3>

## Задача 4
<h3>Да се дефинира клас Employee, който пресмята заплатата на чиновник, дефиниран чрез:
<ul>
<li> име, зададено чрез структура с полета first(собствено име) и last(фамилно име) и</li>
<li> работа, зададена чрез структура с полета hours(часове) и salary(заплащане за 1 час).</li>
</ul>

</h3>

## Задача 5
<h3> Да се намери резултатът от изпълнението на програмата: </h3>

```C++
#include <iostream>

class E { 
private:
    int a, b;

public:
    void init();
    void init(int);
    void init(int, int);
    void display() const;
};

void E::init()
{ 
    a = b = 0;
}

void E::init(int x)
{ 
    a = x;
}

void E::init(int x, int y)
{
    a = x;
    b = y;
}

void E::display() const
{ 
    std::cout << a << " " << b << std::endl;
}

int main()
{ 
    E e1, e2, e3;

    e1.init();
    e2.init(1);
    e3.init(1, 2);

    e1.display();
    e2.display();
    e3.display();

    return 0;
}

```

## Задача 6
<h3>Да се намери резултатът от изпълнението на програмата:

```C++
#include <iostream>

class F {
private:
    int a, b;

public:
    F();
    F(int);
    F(int, int);

    void display() const;
};

F::F()
{
    a = b = 0;
}

F::F(int x)
{
    a = x;
}

F::F(int x, int y)
{
    a = x;
    b = y;
}

void F::display() const
{
    std::cout << a << " " << b << std::endl;
}

int main()
{
    F e1, e2(1), e3(1, 2);

    e1.display();
    e2.display();
    e3.display();

    return 0;
}

```
</h3>

## Задача 7
<h3>
Да се дефинира клас BankAccount, определящ банкова сметка на клиент, съдържаща:
име на клиент(символен низ с дължина 23 знака), номер на банкова сметка(символен низ с дължина до 15 знака) и налична сума на клиент(реално число). Класът да притежава методи, чрез които: да създава банкова сметка на клиент, да извежда на екрана банкова сметка, да внася и тегли пари от банкова сметка.
Да се дефинира главна функция, която демонстрира класа.

</h3>

