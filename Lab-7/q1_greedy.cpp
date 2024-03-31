#include <bits/stdc++.h>
using namespace std;

// We give priority to those items which have more value/weight value
struct ValueWeightComparator {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return (a.first / a.second) > (b.first / b.second);
    }
};

// Greedy approach is to choose items in order of best value/weight value 
int greedyMaxValue(int weights[], int values[], int itemCount, int maxWeight) {
    multimap<pair<int, int>, int, ValueWeightComparator> itemMap;
    for (int i = 0; i < itemCount; i++)
        itemMap.insert(pair<pair<int, int>, int>({values[i], weights[i]}, weights[i]));

    int totalValue = 0;
    for (auto item : itemMap) {
        if (item.second <= maxWeight) {
            maxWeight -= item.second;
            totalValue += item.first.first;
        }
    }
    return totalValue;
}

int main() {
    freopen("input1_greedy.txt", "r", stdin);
    freopen("output_greedy.txt", "w", stdout);
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int itemCount;
        cin >> itemCount;
        int weights[itemCount], values[itemCount];
        for (int i = 0; i < itemCount; i++) cin >> weights[i];
        for (int i = 0; i < itemCount; i++) cin >> values[i];
        int maxWeight;
        cin >> maxWeight;
        cout << greedyMaxValue(weights, values, itemCount, maxWeight) << endl;
    }
    return 0;
}
