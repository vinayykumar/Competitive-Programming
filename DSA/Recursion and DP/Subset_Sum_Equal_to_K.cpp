#include <bits/stdc++.h> 

bool solve(int i,int target,vector<int> &arr,vector<vector<int>> &dp){
	if(target==0) return true;
	if(i==0) return target==arr[0];
	if (dp[i][target] != -1) return dp[i][target];

	bool not_pick = solve(i-1,target,arr,dp);
	bool pick = false;
	if(target>=arr[i]){
		pick = solve(i-1,target-arr[i],arr,dp);
	}

	return dp[i][target] = pick || not_pick;
} 

bool subsetSumToK(int n, int k, vector<int> &arr) {
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return solve(n,k,arr);
}