#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
char a[10001][51];
int main()
{
	freopen("link.in","r",stdin);
	freopen("link.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,i,j=0,maxn=0;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i]+1;
	for(i=2;i<=n;i++)
	{
		if(strstr(a[i-1],a[i]))j++;
		else
		{
			if(j>maxn)maxn=j;
			j=0;
		}
	}
	cout<<maxn;
	return 0;
}
