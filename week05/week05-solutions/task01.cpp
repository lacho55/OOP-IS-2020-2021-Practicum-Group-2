#include<iostream.h>
#include<cmath.h>
#include<stdexcept>
#include<cassert.h>
using std::cin;
using std::cout;

class DynArray {
public:
    int * data;
    size_t size, capacity;

    void resize() {
        this->capacity *= 2;
        int * oldData = this->data;
        this->data = new int[this->capacity];
        for(size_t i = 0; i < this->size; i++) {
            this->data[i] = oldData[i];
        }
        delete[] oldData;
    }
    void initialize() {
        this->capacity = 8;
        this->data = new int[this->capacity];
        this->size = 0;
    }

    void addToEnd(int newElement) {
        if(this->size == this->capacity) {
            resize();
        }
        this->data[this->size] = newElement;
        this->size++;
    }

    bool hasElem(int element) {
        for(size_t i = 0; i < this->size; i++) {
            if(this->data[i] == element) {
                return true;
            }
        }
        return false;
    }

    bool isEmpty() {
        return this->size == 0;
    }

    void deinitialize() {
        delete[] this->data;
    }
};

int main() {
	
    DynArray array; 
    
	array.initialize();
	
    array.addToEnd(12);

    for(size_t i = 0; i < array.size; i++) {
        cout << array.data[i] << " ";
    }
    cout << "\n";
    array.addToEnd(15);
    for(size_t i = 0; i < array.size; i++) {
        cout << array.data[i] << " ";
    }

    DynArray array2;
    array2 = array;

    array.deinitialize();
    cout << '\n';
	
}