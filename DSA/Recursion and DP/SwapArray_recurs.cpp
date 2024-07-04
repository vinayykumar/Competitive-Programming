#include<bits/stdc++.h>
using namespace std;

// using two pointers
// void reverse(vector<int>& vec,int l,int r){
// 	if(l==r) return;
// 	swap(vec[l],vec[r]);
// 	reverse(vec,l+1,r-1);
// }

// using one pointers
void rev(vector<int>&vec,int l,int&siz){
	if(l>=siz/2) return;
	swap(vec[l],vec[siz-l-1]);
	rev(vec,l+1,siz);
}

int main(){
	vector<int> vec = {1,2,3,4,5};
	int siz = vec.size();
	// reverse(vec,0,siz-1);
	rev(vec,0,siz);

	for(auto it : vec){
		cout<<it<<" ";
	}
}