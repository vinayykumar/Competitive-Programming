#include<bits/stdc++.h>
using namespace std;

int solve(int arr[],int i,vector<int> &dp,int &n,int prev){
	if(i==n ){
		return 0;
	}
	if(arr[i]<=prev) return 0;
	if(dp[i]!=-1) return dp[i];

	int pick = 1 + solve(arr,i+1,dp,n,arr[i]);
	int not_pick = 0 + solve(arr,i+1,dp,n,prev);

	return dp[i] = max(pick,not_pick);
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int> dp(n+1,-1);
	cout<<solve(arr,0,dp,n,INT_MIN)<<endl;
}