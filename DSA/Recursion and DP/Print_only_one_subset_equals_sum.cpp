#include<bits/stdc++.h>
using namespace std;

bool subs(vector<int>& arr, vector<int> sub,int i,int target,int curr){
	if(i==arr.size()){
		if(curr==target){
			for(auto it : sub) cout<<it<<" ";
			cout<<endl;
			return true;
		}
		return false;
	}
	sub.push_back(arr[i]); 
	curr+=arr[i];
	if(subs(arr,sub,i+1,target,curr)) return true;

	sub.pop_back();
	curr-=arr[i];
	if(subs(arr,sub,i+1,target,curr)) return true;

	return false;
}

int main(){
	vector<int> sub;
	vector<int> arr = {1,2,3};
	subs(arr,sub,0,3,0);
}