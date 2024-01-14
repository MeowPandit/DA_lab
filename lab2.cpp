#include <bits/stdc++.h>
using namespace std;

int recursiveKnapsack(vector<int>& weights, vector<int>& values, int n, int maxWeight){
    if(n == 0 || maxWeight == 0) return 0;
    if(weights[n-1] > maxWeight) return recursiveKnapsack(weights, values, n - 1, maxWeight);
    return max(values[n-1] + recursiveKnapsack(weights, values, n - 1, maxWeight - weights[n-1]), recursiveKnapsack(weights, values, n - 1, maxWeight));
}

int memoizedKnapsack(vector<int>& weights, vector<int>& values, int n, int maxWeight, map<pair<int,int>,int>& memo){
    if(n == 0 || maxWeight == 0) return 0;
    if(memo.find({n, maxWeight}) != memo.end()) return memo[{n, maxWeight}];
    if(weights[n-1] > maxWeight) memo[{n, maxWeight}] = memoizedKnapsack(weights, values, n - 1, maxWeight, memo);
    else memo[{n, maxWeight}] = max(values[n-1] + memoizedKnapsack(weights, values, n - 1, maxWeight - weights[n-1], memo),
                                      memoizedKnapsack(weights, values, n - 1, maxWeight, memo));
    return memo[{n, maxWeight}];
}

int main(){
    freopen("input_2.in","r",stdin);
    freopen("output_2.out","w",stdout);
    int itemCount;
    cin >> itemCount;
    
    vector<int> itemWeights, itemValues;
    int itemWeight, itemValue;
    for(int i = 0; i < itemCount; i++){
        cin >> itemWeight;
        itemWeights.push_back(itemWeight);
    }
    for(int i = 0; i < itemCount; i++){
        cin >> itemValue;
        itemValues.push_back(itemValue);
    }
    
    int knapsackCapacity;
    cin >> knapsackCapacity;
    
    map<pair<int,int>,int> memo;
    int result = memoizedKnapsack(itemWeights, itemValues, itemCount, knapsackCapacity, memo);
    cout << result;
    
    return 0;
}
