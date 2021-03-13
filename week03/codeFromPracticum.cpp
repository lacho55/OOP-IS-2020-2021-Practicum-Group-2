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

//Да се направи клас Мovie, който в себе си има полетата име, режисьор и продължителноста на филма. За този клас трябва да се реализират: 
//	конструктор по подразбиране
//	конструктор за копиране
//	конструктор с параметри
//	деструктор
//	оператор за присвояване
//	оператора за вход
//	оператор за изход

class Movie
{
private:
  char* name;
  char* director;
  int duration; //oопа
  
public:
  
   	void set_name(const char* _name) 
    {
      delete[] this->name;
      int len = strlen(_name) + 1; 
      this->name = new char[len];
    	strcpy_s(this->name, _name);
    }
    char* get_name()const {
        return this->name;
    }

    void set_director(const char* _director) {
        strcpy_s(this->name, _director);
    }
    char* get_director()const {
        return this->director;
    }

    void set_duration(const int _duration) {
        this->duration = _duration;
    }
    int get_duration()const {
        return this->duration;
    }
  
  
  Movie();tor;
  Movie(const Movie& other);
  Movie(const char* name, const char* director, const int duration)other);
  ~Movie();
  
  Movie& operator=(const Movie& other);
  
  friend ostream& operator<<(ostream &os, const Movie &movie);
  friend istream& operator>>(istream &is, Movie &movie);
}

friend ostream& Movie::operator<<(ostream &os, const Movie &movie) const
{
	os << movie.get_name() << std::endl;
  os << movie.get_director() << std::endl;
  os << movie.get_duration() << std::endl;
  
  return os;
}

friend istream& Movie::operator>>(istream &is, Movie &movie)
{	
  char buffer[50];
  is >> buffer;
  //name = new char[strlen(buffer) + 1]; не се мисли само се копира
 	movie.set_name(buffer);
  
  is >> buffer;
  //director = new char[strlen(buffer) + 1];  // а това не се ли прави в сетъра? 
  movie.set_director(buffer);
  
  int duration_;
  in >> duration_;
  movie.set_duration(duration_);
  
  return is;
}     
    
int main()
{
	Movie robinHood;
  robinHood.set_name("Robin Hood");
  robinHood.set_director("Steven Spielberg");
  robinHood.set_duration(150);

  cout << robinHood;
  cin >> robinHood;
  
  return 0;
}
  

Movie(char* _name = nullptr, int _duration = 0, int _castNumber = 0) : name(_name), duration(_duration), castNumber(_castNumber) {}
        
        
      
        
        
        
        
        
        
        
        
        
        