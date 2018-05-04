#include<iostream>
#include<cstdio>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int w[1000],c[1000][3];int f[100][100];
int main()
{
	freopen("gas.in","r",stdin);freopen("gas.out","w",stdout);
	memset(f,0,sizeof(f));
	int m1,m2,n,h=0;
	scanf("%d%d",&m1,&m2,&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&c[i][1],&c[i][2],&w[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=m1;j>=w[i];j--)
		for(int k=m2;k>=w[i];k--)
		{
			if(f[j][k]>f[j-w[i]][k-w[i]]+w[i])f[j][k]=f[j-w[i]][k-w[i]]+w[i];
		}
	}
	printf("%d",f[m1][m2]);
	return 0;
}
