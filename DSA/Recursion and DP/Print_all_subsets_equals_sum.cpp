#include<bits/stdc++.h>
using namespace std;

void subs(vector<int>& arr, vector<int> sub,int i,int target,int curr){
	if(i==arr.size()){
		if(curr==target){
			for(auto it : sub) cout<<it<<" ";
			cout<<endl;
		}
		return;
	}
	sub.push_back(arr[i]);
	curr+=arr[i];
	subs(arr,sub,i+1,target,curr);

	sub.pop_back();
	curr-=arr[i];
	subs(arr,sub,i+1,target,curr);
}

int main(){
	vector<int> sub;
	vector<int> arr = {1,2,3};
	subs(arr,sub,0,3,0);
}