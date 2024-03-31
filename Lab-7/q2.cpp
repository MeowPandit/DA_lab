#include <bits/stdc++.h>
using namespace std;

// Struct for custom comparator to order jobs according to descending order of profits
struct ProfitComparator {
    bool operator()(const pair<int, pair<int, char>>& p1, const pair<int, pair<int, char>>& p2) {
        return p1.first > p2.first;
    }
};

// Function to calculate maximum profit using greedy approach
int calculateMaxProfit(map<int, vector<pair<int, char>>>& jobsMap) {
    priority_queue<pair<int, pair<int, char>>, vector<pair<int, pair<int, char>>>, ProfitComparator> pq;
    int totalProfit = 0;
    for (auto x : jobsMap) {
        int maxJobs = x.first;
        int size = (int)(x.second).size();
        for (int i = 0; i < size; i++) {
            if ((int)pq.size() < maxJobs) {
                pq.push({x.second[i].first, {x.first, x.second[i].second}});
                totalProfit += x.second[i].first;
            } else if (pq.top().first < x.second[i].first) {
                totalProfit -= pq.top().first;
                pq.pop();
                pq.push({x.second[i].first, {x.first, x.second[i].second}});
                totalProfit += x.second[i].first;
            }
        }
    }
    multimap<int, char> jobSequence;
    while (!pq.empty()) {
        jobSequence.insert(pq.top().second);
        pq.pop();
    }
    for (auto q : jobSequence) {
        cout << q.second << ' ';
    }
    cout << endl;
    return totalProfit;
}

int main() {
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int numberOfJobs;
        cin >> numberOfJobs;
        map<int, vector<pair<int, char>>> jobsMap;
        for (int i = 0; i < numberOfJobs; i++) {
            char jobName;
            int deadline, profit;
            cin >> jobName >> deadline >> profit;
            jobsMap[deadline].push_back({profit, jobName});
        }
        cout << calculateMaxProfit(jobsMap) << endl << endl;
    }
    return 0;
}
