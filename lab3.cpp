#include <bits/stdc++.h>

using namespace std;
const int INFINITY_VALUE = 1000000;

int minCostTraversal(int currentVertex, int visitedMask, int vertexCount, vector<vector<int>>& memo, vector<vector<int>>& adjacencyMatrix)
{
    if (visitedMask == ((1 << currentVertex) | 3))
        return adjacencyMatrix[1][currentVertex];
    
    if (memo[currentVertex][visitedMask] != 0)
        return memo[currentVertex][visitedMask];

    int result = INFINITY_VALUE;
    for (int nextVertex = 1; nextVertex <= vertexCount; nextVertex++) {
        if ((visitedMask & (1 << nextVertex)) && nextVertex != currentVertex && nextVertex != 1) {
            result = min(result, minCostTraversal(nextVertex, visitedMask & (~(1 << currentVertex)), vertexCount, memo, adjacencyMatrix) + adjacencyMatrix[nextVertex][currentVertex]);
        }
    }

    return memo[currentVertex][visitedMask] = result;
}

int main() {
    freopen("input_3.in", "r", stdin);
    freopen("output_3.out", "w", stdout);
    
    int vertexCount;
    cin >> vertexCount;
    
    vector<vector<int>> memo(vertexCount + 1, vector<int>(1 << (vertexCount + 1), 0));
    vector<vector<int>> adjacencyMatrix(vertexCount + 1, vector<int>(vertexCount + 1, 0));

    int minimumCost = INFINITY_VALUE;
    for (int i = 0; i < vertexCount + 1; i++) {
        for (int j = 0; j < vertexCount + 1; j++) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    for (int startVertex = 1; startVertex <= vertexCount; startVertex++) {
        minimumCost = min(minimumCost, minCostTraversal(startVertex, (1 << (vertexCount + 1)) - 1, vertexCount, memo, adjacencyMatrix) + adjacencyMatrix[startVertex][1]);
    }

    cout << minimumCost;

    return 0;
}