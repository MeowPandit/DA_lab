// divide and conqueor
#include <bits/stdc++.h>
using namespace std;
int crossingsum(vector<int>a,int f,int m,int l){
    int leftsum=INT_MIN;
    int sum=0;
    for(int i=m;i>=f;i--){
        sum+=a[i];
        if(sum>leftsum){
            leftsum=sum;
        }
    }
    sum = 0; 
	int rightsum =INT_MIN; 
	for (int i=m;i<=l;i++) { 
		sum+=a[i]; 
		if(rightsum<sum) 
			rightsum=sum; 
	}
    return max(leftsum,max(rightsum,(leftsum+rightsum-a[m]))); 
}
int maxsumsubarray(vector<int>a,int f,int l){
    if(f>l){
        return INT_MIN;
    }
    if(f==l){
        return a[f];
    }
    int m=(f+l)/2;
    
    return max(max(maxsumsubarray(a,f,m-1),maxsumsubarray(a,m+1,l)),crossingsum(a,f,m,l));
}
int main(){
    vector<int>a;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a.push_back(x);
    }
    // vector<int>a={10,-20,3,4,5,-1,-1,12,-3,1};
    // int n=10;
    // int m=4;
    // int f = 9;
	// int right_sum =-10000000; 
	// for (int i = m; i <= f; i++) { 
	// 	sum = sum + a[i]; 
	// 	if (right_sum<sum) 
	// 		right_sum = sum; 
	// } 
    // cout<<right_sum;
    cout<<maxsumsubarray(a,0,n-1);
}