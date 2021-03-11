#include <iostream>
#include <iomanip>

class Employee
{ 
public:
    void read();              
    void print() const;       

private:
    struct
    { 
        char first[16];       
        char last[16];       
    } name;
    struct
    { 
        double hours;         
        double salary;       
    } work;
};

void Employee::read()
{
    std::cout << "Enter name: ";
    std::cin >> name.first;

    std::cout << "Enter last name: ";
    std::cin >> name.last;

    std::cout << "Enter hours: ";
    std::cin >> work.hours;

    std::cout << "Enter salary: ";
    std::cin >> work.salary;

    std::cin.ignore();   
}

void Employee::print() const
{
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2);
    std::cout << name.first << " " << name.last << " "
         << work.hours * work.salary << std::endl;
}

int main()
{
    Employee e; 

    e.read();
    e.print();

    return 0;
}