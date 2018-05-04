#include<iostream>
#include<cstdio>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int w[1000],c[1000];int f[100][100];
int main()
{
	freopen("knapsack.in","r",stdin);freopen("knapsack.out","w",stdout);
	memset(f,0,sizeof(f));
	int m,n,h=0,i,j;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)scanf("%d%d",&w[i],&c[i]);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(j<w[i])f[i][j]=f[i-1][j];
			else 
			{
				if(f[i-1][j]>f[i][j-w[i]]+c[i])f[i][j]=f[i-1][j];
				else f[i][j]=f[i][j-w[i]]+c[i];
			}
		}
	}
	cout<<"max="<<f[m]<<endl;
	return 0;
}
