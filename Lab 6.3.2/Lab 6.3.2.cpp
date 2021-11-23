// Lab 6.3.2.cpp
// IT-12, Fihura Taras

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

template <typename T>
void create(T* a, const int size, const T low, const T high, int i)
{
    a[i] = low + rand() % (high - low + 1);
    if (i < size - 1) {
        create(a, size, low, high, i + 1);
    }
}

template <typename T>
void print(T* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1) {
        print(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}

template <typename T>
int unevenCount(T* vector, int length, int i) {
    if (i < length) {
        if (vector[i] % 2 != 0) {
            return 1 + unevenCount(vector, length, i + 1);
        }
        else {
            return 0 + unevenCount(vector, length, i + 1);
        }
    }
    else {
        return 0;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    const int n = 10;
    long a[n];
    long low = -10;
    long high = 10;
    create(a, n, low, high, 0);
    print(a, n, 0);

    cout << "vector contains " << unevenCount(a, n, 0) << " uneven numbers";

    return 0;
}