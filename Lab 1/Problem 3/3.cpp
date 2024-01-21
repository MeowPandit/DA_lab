#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int array_size;
        cin >> array_size;
        int numbers[array_size];
        for (int i = 0; i < array_size; i++) {
            cin >> numbers[i];
        }
        for (int current_index = 1; current_index < array_size; current_index++) {
            int previous_index = current_index - 1;
            while (previous_index >= 0 && numbers[previous_index] > numbers[previous_index + 1]) {
                swap(numbers[previous_index], numbers[previous_index + 1]);
                previous_index--;
            }
        }
        for (int i = 0; i < array_size; i++) {
            cout << numbers[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
