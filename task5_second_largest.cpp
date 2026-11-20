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
            candidate = rand() % 100 - 30;
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

    int firstMax, secondMax;
    if (arr[0] > arr[1]) {
        firstMax = arr[0];
        secondMax = arr[1];
    } else {
        firstMax = arr[1];
        secondMax = arr[0];
    }

    for (int i = 2; i < N; i++) {
        if (arr[i] > firstMax) {
            secondMax = firstMax;
            firstMax = arr[i];
        } else if (arr[i] > secondMax) {
            secondMax = arr[i];
        }
    }

    cout << "Largest element: " << firstMax << endl;
    cout << "Second largest element: " << secondMax << endl;

    return 0;
}
