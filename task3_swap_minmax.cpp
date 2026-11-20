#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const int N = 10;
    int arr[N];

    for (int i = 0; i < N; i++) {
        bool unique;
        int candidate;
        do {
            unique = true;
            candidate = rand() % 100 - 40;
            for (int j = 0; j < i; j++) {
                if (arr[j] == candidate) {
                    unique = false;
                    break;
                }
            }
        } while (!unique);
        arr[i] = candidate;
    }

    cout << "Generated array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int minIdx = 0;
    int maxIdx = 0;
    for (int i = 1; i < N; i++) {
        if (arr[i] < arr[minIdx]) {
            minIdx = i;
        }
        if (arr[i] > arr[maxIdx]) {
            maxIdx = i;
        }
    }

    int temp = arr[minIdx];
    arr[minIdx] = arr[maxIdx];
    arr[maxIdx] = temp;

    cout << "After swapping min (" << temp << ") and max (" << arr[minIdx] << "): ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
