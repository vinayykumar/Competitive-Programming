#include<bits/stdc++.h>
using namespace std;

void subs(vector<int>& arr, vector<int> sub,int i){
	if(i==arr.size()){
		for(auto it : sub){
			cout<<it<<" ";
		}
		cout<<endl;
		return;
	}
	sub.push_back(arr[i]);
	subs(arr,sub,i+1);

	sub.pop_back();
	subs(arr,sub,i+1);
}

int main(){
	vector<int> sub;
	vector<int> arr = {1,2,3};
	subs(arr,sub,0);
}