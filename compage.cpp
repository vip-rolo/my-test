#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int n,m,a[21];
void print()
{
	for(int i=1;i<m;i++)printf("%d ",a[i]);
	printf("%d\n",a[m]);
}
void dfs(int i)
{
	for(int j=a[i-1]+1;j<=n;j++)
	{
		a[i]=j;
		if(i==m)print();
		else dfs(i+1);			
		a[i]=0;
	}
}
int main()
{
	freopen("compage.in","r",stdin);
	freopen("compage.out","w",stdout);
	ios::sync_with_stdio(1);
	cin>>n>>m;
	a[0]=0;
	dfs(1);
	return 0;
}
