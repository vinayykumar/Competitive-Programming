#include<bits/stdc++.h>
using namespace std;


int pCount(vector<int>& arr,int i,int sum,int k){
	if(i==arr.size()){
		if(sum==k) return 1;
		return 0;
	}

	sum+=arr[i];
	int l = pCount(arr,i+1,sum,k);

	sum-=arr[i];
	int r = pCount(arr,i+1,sum,k);

	return l + r;
}

int main(){
	vector<int> arr = {1,2,3,4,5};
	cout<<pCount(arr,0,0,6);
}