#include <bits/stdc++.h>
using namespace std;
double solve(vector<int>a,vector<int>b,int n1,int n2){
    int left = (n1+n2+1)/2;
    if(n1>n2){
        return solve(b,a,n2,n1);
    }
    int total = n1+n2;
    int low = 0;
    int high = n1;
    while(low <= high){
        int mid = (low+high)/2;
        int m1 = mid;
        int m2 = left - m1;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;
        if(m1<n1) r1=a[m1];
        if(m2<n2) r2=b[m2];
        if(m1-1>=0) l1=a[m1-1];
        if(m2-1>=0) l2=b[m2-1];
        if(l1<=r2 && l2<=r1){
            if(total%2==0) return (max(l1,l2)+min(r1,r2))/2.0;
            return max(l1,l2);
        }
        else{
            if(l1>r2){
                high = mid-1;
            }
            if(l2>r1){
                low = mid + 1;
            }
        }
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        vector<int>a;
        vector<int>b;
        int n1;int n2;
        cin>>n1>>n2;
        for(int i=0;i<n1;i++){
            int x;cin>>x;
            a.push_back(x);
        }
        for(int i=0;i<n2;i++){
            int z;cin>>z;
            b.push_back(z);
        }
        cout<<solve(a,b,n1,n2)<<endl;
    }
}