#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	 ios::sync_with_stdio(0);
	 int n,i,p,m;string a;
	 map<string,int> d;
	 cin>>n;
	 for(i=1;i<=n;i++)
	 {
	 	cin>>a>>p;
	 	d[a]=p;
	 }
	 cin>>m;
	 for(i=1;i<=m;i++)
	 {
	 	cin>>a;
	 	cout<<d[a]<<endl;
	 }
	 return 0;
}
