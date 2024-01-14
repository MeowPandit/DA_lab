#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("input_1.in","r",stdin);
    freopen("output_1.out","w",stdout);
    int size;
    cin >> size;
    vector<int> elements;
    int element;
    for(int i = 0; i < size; i++){
        cin >> element;
        elements.push_back(element);
    }

    int firstLargestIndex = 0;
    int secondLargestIndex = -1;
    for(int i = 1; i < size; i++){
        if(elements[firstLargestIndex] <= elements[i]) {
            secondLargestIndex = firstLargestIndex;
            firstLargestIndex = i;
        }
        else if(secondLargestIndex == -1 || elements[secondLargestIndex] < elements[i]) secondLargestIndex = i;
    }

    cout << elements[firstLargestIndex] + elements[secondLargestIndex];
    return 0;
}
