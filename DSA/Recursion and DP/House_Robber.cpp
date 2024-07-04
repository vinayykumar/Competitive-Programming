#include<bits/stdc++.h>
using namespace std;

int rob(int i,vector<int>& arr,vector<int>& dp){
	if(i==0) return arr[i];
	if(i<0) return 0;
	if(dp[i]!=-1) return dp[i];
	int pick = arr[i] + rob(i-2,arr,dp);
	int not_pick = 0 + rob(i-1,arr,dp);

	return dp[i]=max(pick,not_pick);
}

int main(){
	vector<int> arr = {1,2,3,1};
	int n = arr.size();
	vector<int> dp(n+1,-1);
	cout<<rob(n-1,arr,dp);
}