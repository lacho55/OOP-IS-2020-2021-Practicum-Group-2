#include <iostream>
#include <string.h>
using namespace std;

const int SIZE = 100;

class Movie {
private:
    char* title;
    char* director;
    int minutes;

    void copy(const Movie& other) {

        this->title = new char[strlen(other.title) + 1];
        strcpy(this->title, other.title);
        this->director = new char[strlen(other.director) + 1];
        strcpy(this->director, other.director);
        this->minutes = other.minutes;
    }

    void destroy() {
        delete[] this->title;
        delete[] this->director;
    }
public:
    Movie() {
        this->title = NULL;
        this->director = NULL;
        this->minutes = 0;
    }

    Movie(const char* title, const char* director, int minutes) {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
        this->director = new char[strlen(director) + 1];
        strcpy(this->director, director);
        this->minutes = minutes;
    }

    Movie(const Movie& other) {
        copy(other);
    }

    Movie& operator=(const Movie& other) {
        if (this != &other) {
            destroy();
            copy(other);
        }
        return *this;
    }

    ~Movie() {
        destroy();
    }

    const char* getTitle() const {
        return this->title;
    }

    const char* getDirector() const {
        return this->director;
    }

    int getMinutes() const {
        return this->minutes;
    }

    void setTitle(const char* title) {
        delete[] this->title;
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
    }

    void setDirector(const char* director) {
        delete[] this->director;
        this->director = new char[strlen(director) + 1];
        strcpy(this->director, director);
    }


    void setMinutes(int minutes) {
        this->minutes = minutes;
    }

    friend ostream& operator<<(ostream& os, const Movie& movie) {
        os << movie.title << endl;
        os << movie.director << endl;
        os << movie.minutes << endl;
        return os;
    }

    friend istream& operator>>(istream& is, Movie& movie) {
        delete [] movie.title;
        delete [] movie.director;
        
        char* buffer = new char[SIZE];
        
        is.getline(buffer, SIZE);
        movie.title = new char[strlen(buffer) + 1];
        strcpy(movie.title, buffer);

        is.getline(buffer, SIZE);
        movie.director = new char[strlen(buffer) + 1];
        strcpy(movie.director, buffer);

        is >> movie.minutes;
        is.ignore();

        delete[] buffer;
        return is;
    }
};

int main() {

    Movie one("Mmmmm", "Ddddddd", 125);
    cout << one;
    Movie two;
    cin >> two;
    cout << two;
    return 0;
}