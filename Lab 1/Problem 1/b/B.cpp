#include <bits/stdc++.h>
using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        int size_a, size_b;
        cin >> size_a >> size_b;

        int array_a[size_a], array_b[size_b];

        for (int i = 0; i < size_a; i++)
            cin >> array_a[i];

        for (int i = 0; i < size_b; i++)
            cin >> array_b[i];

        vector<int> merged_array;
        int index_a = 0, index_b = 0;

        while (index_a < size_a && index_b < size_b) {
            if (array_a[index_a] < array_b[index_b]) {
                merged_array.push_back(array_a[index_a]);
                index_a++;
                while (index_a < size_a && array_a[index_a - 1] == array_a[index_a])
                    index_a++;
            } else if (array_a[index_a] > array_b[index_b]) {
                merged_array.push_back(array_b[index_b]);
                index_b++;
                while (index_b < size_b && array_b[index_b - 1] == array_b[index_b])
                    index_b++;
            } else {
                merged_array.push_back(array_a[index_a]);
                index_a++;
                index_b++;
                while (index_a < size_a && array_a[index_a - 1] == array_a[index_a])
                    index_a++;
                while (index_b < size_b && array_b[index_b - 1] == array_b[index_b])
                    index_b++;
            }
        }

        while (index_a < size_a) {
            merged_array.push_back(array_a[index_a]);
            index_a++;
            while (index_a < size_a && array_a[index_a - 1] == array_a[index_a])
                index_a++;
        }

        while (index_b < size_b) {
            merged_array.push_back(array_b[index_b]);
            index_b++;
            while (index_b < size_b && array_b[index_b - 1] == array_b[index_b])
                index_b++;
        }

        for (int &element : merged_array) {
            cout << element << ' ';
        }
        cout << endl;
    }

    return 0;
}
