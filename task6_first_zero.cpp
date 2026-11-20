#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const int N = 12;
    int arr[N];

    cout << "Generated array: ";
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 9 - 4;
        cout << arr[i] << " ";
    }
    cout << endl;

    int zeroIndex = -1;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 0) {
            zeroIndex = i;
            break;
        }
    }

    if (zeroIndex != -1) {
        cout << "First zero element index (0-based): " << zeroIndex
             << " (position: " << zeroIndex + 1 << ")" << endl;
    } else {
        cout << "Array does not contain zero elements." << endl;
    }

    return 0;
}
