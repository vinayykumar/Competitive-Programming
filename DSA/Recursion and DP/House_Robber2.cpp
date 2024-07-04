#include<bits/stdc++.h>
using namespace std;

int solve(int i, vector<int>& nums, vector<int>& dp, bool last_taken) {
        if (i == 0 && last_taken != true) return nums[i];
        if (i == 0 && last_taken == true) return 0;
        if (i < 0) return 0;

        if (dp[i] != -1) return dp[i];

        int pick = nums[i] + solve(i - 2, nums, dp, last_taken);
        int not_pick = 0 + solve(i - 1, nums, dp, last_taken);

        return dp[i] = max(pick, not_pick);
    }

int main(){
    vector<int> nums={2,3,2};
	int n = nums.size();
    if (n == 1) return nums[0];
        
    vector<int> dp(n, -1);
    int with_first = solve(n - 2, nums, dp, false);
    fill(dp.begin(), dp.end(), -1);
    int without_first = solve(n - 1, nums, dp, true);

    cout<<max(with_first, without_first);
}