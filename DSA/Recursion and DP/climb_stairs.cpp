#include<bits/stdc++.h>
using namespace std;


// int climb(int n,vector<int>& dp){
// 	if(n==0 || n==1) return 1;
// 	int one = dp[n-1]!=-1 ? dp[n-1] : climb(n-1,dp);
// 	int two = dp[n-2]!=-1 ? dp[n-2] : climb(n-2,dp);
// 	return dp[n] = one + two;
// }

int climb(int n){
	if(n==0 || n==1) return 1;
	int one = climb(n-1);
	int two = climb(n-2);
	return one + two;
}

int main(){
	int n;
	cin>>n;
	vector<int> dp(n+1,-1);
	dp[n]=1;
	cout<<climb(n);
}