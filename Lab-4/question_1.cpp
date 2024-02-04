#include <bits/stdc++.h>
using namespace std;
int merge(vector<int>a,int l,int m,int r){
    int invcount=0;
    int left = m-l+1;
    int right = r-m;
    int larr[left];int rarr[right];
    for(int i=0;i<left;i++){
        larr[i]=a[l+i];
    }
    for(int i=0;i<left;i++){
        rarr[i]=a[m+i+1];
    }
    int i=0;int j=0;int k=l;
    while(i<left && j<right){
        if(larr[i]>rarr[j]){
            a[k]=rarr[j];
            j++;
            invcount+=m-i+1;
        }
        else{
            a[k]=larr[i];
            i++;
        }
        k++;
    }
    while(i<left){
        a[k]=larr[i];
        k++;
        i++;
    }
    while(j<right){
        a[k]=rarr[j];
        k++;
        j++;
    }
    return invcount;
}
int mergesort(vector<int>a,int l,int r){
    if(l>=r){
        return 0;
    }
    int mid= (l+r)/2;
    int inv = 0;
    inv+=mergesort(a,l,mid);
    inv+=mergesort(a,mid+1,r);
    inv+=merge(a,l,mid,r);
    return inv;
}
int solve(vector<int>a,int n){
    int c=mergesort(a,0,n-1);
    return c;
}
int main(){
    int t;cin>>t;
    while(t--){
        vector<int>a;
        int n;cin>>n;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            a.push_back(x);
        }
        cout<<solve(a,n)<<endl;
    }
}