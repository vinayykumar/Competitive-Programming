#include <bits/stdc++.h> 
using namespace std;


void solve(int arr[],int i,long long &mini,int &n,long long sum,long long tsum){
	if(i==n){
		long long ans = abs(tsum - sum*2);
		mini = min(mini,ans);
		return;
	}
	sum+=arr[i];
	solve(arr,i+1,mini,n,sum,tsum);
	sum-=arr[i];
	solve(arr,i+1,mini,n,sum,tsum);
}

int main(){
int n;
cin>>n;
int arr[n];
long long tsum=0;
for(int i=0;i<n;i++){
	cin>>arr[i];
	tsum=tsum+arr[i];
}

long long mini = INT_MAX;
solve(arr,0,mini,n,0,tsum);
	cout<<mini<<endl;
}