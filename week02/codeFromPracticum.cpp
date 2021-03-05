class Employee {
private:
    char* name;
    int age;
  
  	void copy(const Employee&);
  	void destroy();
  
public:
    Employee();
  	Employee(char* _name, int age);
  	Employee(const Employee& other);
  	Employee& operator=(const Employee& other);
  	bool operator==(const Employee& other) const;
  	~Employee();
};

Employee::bool operator==(const Employee& other) const{
 return strcmp(this->name, other.name) && (this->age == other.age);
}


Employee::Employee()
{
	name = "";
  age = 0;
}

Employee::Employee(const Employee& other)
{
  
  this->name = new char[strlen(other.name) + 1];
  strcpy_s(this->name, other.name);
	this->age = other.age;
}

Employee::~Employee()
{
	delete[] name;
  age = 0;
}

Employee::Employee& operator=(const Employee& other)
{
	if(this != &other){
      delete[] name;
  		this->name = new char[strlen(other.name) + 1];
  		strcpy_s(this->name, other.name);
			this->age = other.age;
  }
  
  return *this;
}

Employee::Employee(char* _name, int _age)
{
	this->name = new char[strlen(_name) + 1];
  strcpy_s(this->name, _name);
	this->age = _age;
}


int main()
{
  Employee junior;
  Employee cloning(junior);
  Employee equalCloning = cloning;
  Employee gosho("Georgi", 19);
  
  Employee traicho;
  Employee Dimitar;
  
  if(traicho == Dimitar){
    
  }
  
	return 0;
}


//Да се дефинира клас Employee, който пресмята заплатата на чиновник, дефиниран чрез:
//име, зададено чрез структура с полета first(собствено име) и last(фамилно име) и
//работа, зададена чрез структура с полета hours(часове) и salary(заплащане за 1 час).

struct Name {
    char* firstName;
    char* lastName;
};
 
struct Work
{
    int hours;
    float salary;
};
 
class Employee {
private:
    Name name;
    Work work;
public:
    void initialize(Name _name, Work _work);
    void display() const;
};
 
void Employee::initialize(Name _name, Work _work) {
    strcpy_s(name.firstname, _firstname);
  	strcpy_s(name.lastname, _lastname);
    work.hours = _work.hours;
    work.salary = _work.salary;
}
 
void Employee::display() const {
    std::cout << "Wmployee name is " << name.firstName <<" " <<name.lastName << " and they works " <<
        work.hours<< " and has "<< work.salary<<"."<< std::endl;
}


int main()
{

    return 0;
}





class Employee {
private:
    Names name;
    Work work;

public:
    void set_name(Names _names) {
        name = _names;
    }

    Names get_name() {
        return name;
    }

    void set_work(Work _work) {
        work = _work;
    }

   void Func()
    {
        name.
    }
};

struct Names {
private:
    char first[32];
    char last[32];
public:

    void set_first(char* _first) {
        strcpy_s(first, _first);
    }

    char* get_first() {
        return first;
    }

    void set_last(char* _last) {
        strcpy_s(last, _last);
    }

    char* get_last() {
        return last;
    }
};

class Work
{
private:
    int hours;
    double salary;
public:
    void set_hours(int _hours) {
        hours = _hours;
    }

    int get_hours() {
        return hours;
    }

    void set_salary(double _salary) {
        salary = _salary;
    }

    double get_salary() {
        return salary;
    }
};
/////////////////////////////////////////////////////////////////////////////////////


#include <iostream>

struct Name {
    char first[12];
    char last[12];
};

struct Job {
    double hours;
    double salary;
};

class Employee {
private:

    Job job;
    Name name;
public:

    double calculateSalary();
    void display() const;
    void setSalary(double, double);
    void setName(const char*, const char*);

};

void Employee::setName(const char name [], const char second [])
{
    strcpy(this->name.first, name);
    strcpy(this->name.last, second);
}

double Employee::calculateSalary() {
   return (this->job.salary * this->job.hours);
}

void Employee::display() const{
    std::cout << this->name.first << " " << this->name.last<<std::endl;
    std::cout << calculateSalary();
}

void Employee::setSalary(double hours, double salary) {
    this->job.hours = hours;
    this->job.salary = salary;
}


int main()
{
    Employee first;
   
    first.setSalary(5, 10);
    first.setName("Toshko", "Batsanov");
    first.display();
}
