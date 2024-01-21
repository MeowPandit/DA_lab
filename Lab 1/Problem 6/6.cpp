#include<iostream>
#include<algorithm>
using namespace std;

void QuickSort(int array[], int start, int end) {
    if (start >= end)
        return;

    int pivot = (start + end) / 2;

    swap(array[pivot], array[end]);

    int left = start, right = start;
    while (right < end) {
        if (array[right] <= array[end]) {
            swap(array[left], array[right]);
            left++;
        }
        right++;
    }
    swap(array[left], array[end]);
    QuickSort(array, start, left - 1);
    QuickSort(array, left + 1, end);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int array_size;
        cin >> array_size;

        int numbers[array_size];
        for (int i = 0; i < array_size; i++) {
            cin >> numbers[i];
        }

        QuickSort(numbers, 0, array_size - 1);

        for (int i = 0; i < array_size; i++) {
            cout << numbers[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
