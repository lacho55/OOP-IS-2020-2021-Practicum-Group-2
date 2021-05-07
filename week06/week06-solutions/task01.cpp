#include<iostream>
#include <functional>
#include <stdexcept>


template<typename T>
void map(T * arr, size_t SIZE, std::function<T(T)> func) {
    for(size_t i = 0; i < SIZE; i++) {
        arr[i] = func(arr[i]);
    }
}


template<typename T>
T* filter(T* arr, const size_t SIZE, std::function<bool(T)> func, size_t & resultSize) {
    T * result = new T[SIZE];
    resultSize = 0;
    for(size_t i = 0; i < SIZE; i++) {
		try {
			if(func(arr[i])) {
				result[resultSize] = arr[i];
				resultSize++;
			}
		} catch(...) { // Catch every exception thrown by the lambda
			delete[] result; // prevent memory leak 
			throw; // and rethrow exception
		}
    }

    return result;
}


int main() {
    const size_t SIZE = 5;
    int arr[SIZE] = {1, 2, 3, 4, 6};

    map<int>(arr, SIZE, [](int x) -> int { return 2 * x; } );
    size_t resultArraySize;
    int * resultArray = 
	try {
		filter<int>(arr, SIZE, [](int number) -> bool { throw 42; }, resultArraySize);
    } catch(int ex) {
		// catch exceptions thrown by the lambda
	}
}