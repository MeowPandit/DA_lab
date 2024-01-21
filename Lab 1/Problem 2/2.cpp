#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int array_size, m;
        cin >> array_size >> m;

        int numbers[array_size];

        for (int i = 0; i < array_size; i++) {
            cin >> numbers[i];
        }

        for (int i = m - 1; i < array_size; i++) {
            int j = i - 1;

            while (j >= 0 && numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
                j--;
            }
        }

        for (int i = 0; i < array_size; i++) {
            cout << numbers[i] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
