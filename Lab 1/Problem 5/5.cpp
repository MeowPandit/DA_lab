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
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int testCases;
    cin >> testCases;
    // cout << testCases << '\n';

    while (testCases--) {
        int arraySize;
        cin >> arraySize;

        int numbers[arraySize];
        for (int i = 0; i < arraySize; i++) {
            cin >> numbers[i];
        }

        QuickSort(numbers, 0, arraySize - 1);

        if (arraySize % 2) {
            cout << numbers[arraySize / 2] << '\n';
        }
        else {
            cout << ((double)numbers[arraySize / 2] + numbers[arraySize / 2 + 1]) / 2 << '\n';
        }
    }

    return 0;
}
