#include <iostream>
#include <cstring>

const int MAX_NAME = 24;
const int MAX_NUM = 16;

class BankAccount {
private:
    char name[MAX_NAME];            
    char accountnum[MAX_NUM];      
    double balance;                 

public:
 
    BankAccount(const char * = "", const char * = "0", double = 0.0);

    void print() const;
    void put_in(double);
    void draw(double);
};

BankAccount::BankAccount(const char * cl, const char * n, double b)
{
    strncpy(name, cl, MAX_NAME-1);
    name[MAX_NAME-1] = '\0';

    strncpy(accountnum, n, MAX_NUM);
    accountnum[MAX_NUM] = '\0';

    balance = b;
}

void BankAccount::print() const
{
    std::cout << "Име на клиент: " << name << std::endl;
    std::cout << "Номер на сметка: " << accountnum << std::endl;
    std::cout << "Баланс: " << balance << std::endl;
}

void BankAccount::put_in(double cash)
{
    if(cash >= 0)
        balance = balance + cash;
    else
        std::cout << "Некоректен опит за внасяне на пари.\n";
}

void BankAccount::draw(double cash)
{
    if(cash < 0)
    {
        std::cout << " Некоректен опит за теглене на пари.\n ";
    }
    else
    {
        if(cash <= balance)
            balance = balance - cash;
        else
            std::cout << "Сметката не съдържа достатъчно пари.\n";
    }
}

int main()
{

    BankAccount x;
    x.print();
    BankAccount y("Peter Ivanov", "PIvanov1923", 6123.65);
    y.print();
    BankAccount z = BankAccount("Georgi Petrov", "GPetrov3917", 819.60);
    z.print();


    x.put_in(20);
    x.print();

    y.draw(250);
    y.print();

    z.draw(50);
    z.print();

    return 0;
}