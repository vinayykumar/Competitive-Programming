#include<bits/stdc++.h>
using namespace std;

int subs(vector<int>& arr,int i,int target,int sum){
	if(i==arr.size()){
		if(sum==target) return 1;
		return 0;
	}

	sum+=arr[i];
	int left = subs(arr,i+1,target,sum);

	sum-=arr[i];
	int right = subs(arr,i+1,target,sum);

	return left+right;
}

int main(){
 	vector<int> arr = {1,2,3};
	cout<<subs(arr,0,3,0);
}