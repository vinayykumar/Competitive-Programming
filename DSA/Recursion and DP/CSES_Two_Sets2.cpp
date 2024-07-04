#include<bits/stdc++.h>
using namespace std;

void solve(int i,set<vector<int>> &st,vector<int> sub,int target,int n,int sum){
	if(i==n+1){
		if(sum==target){
			st.insert(sub);
		}
		return;
	}
	sub.push_back(i);
	sum+=i;
	solve(i+1,st,sub,target,n,sum);

	sum-=i;
	sub.pop_back();
	solve(i+1,st,sub,target,n,sum);
}

int main(){
	int n;
	cin>>n;
	int sum = 0;
	for(int i=1;i<=n;i++) sum+=i;
	set<vector<int>> st;
	vector<int> sub;
	solve(1,st,sub,sum/2,n,0);
	cout<<st.size()<<endl;
}