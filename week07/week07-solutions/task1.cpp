#include <iostream>
#include <functional>
#include <stdexcept>
using namespace std;

template<typename T>
void map(T * arr, size_t SIZE, std::function<T(T)> func) {
    for(size_t i = 0; i < SIZE; i++) {
        arr[i] = func(arr[i]);
    }
}


int main()
{
     const size_t SIZE = 5;
    int arr[SIZE] = {1, 2, 3, 4, 6};
    map<int>(arr, SIZE, [](int x) -> int { return 2 * x; } );
    
    for(int i = 0; i < SIZE; i++){
        cout << arr[i];
    }
    
    size_t resultArraySize;

    return 0;
}
