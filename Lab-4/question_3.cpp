#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        vector<int>a;
        int n;cin>>n;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            a.push_back(x);
        }
        priority_queue<int>p(a.begin(),a.end());
        int k;cin>>k;
        int ans;
        while(k--){
            ans=p.top();
            p.pop();
        }
        cout<<ans<<endl;
    }
}