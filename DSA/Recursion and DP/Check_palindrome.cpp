#include<bits/stdc++.h>
using namespace std;

bool check(string& str,int l,int& siz){
	if(l>=siz/2) return true;
	if(str[l]!=str[siz-1-l]) return false;
	return check(str,l+1,siz);
}

int main(){
	string str = "NasN";
	int siz = str.size();
	cout<<check(str,0,siz);
}