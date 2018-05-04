#include<iostream>
#include<cstdio>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int w[1000],c[1000];int f[10000];
int main()
{
	freopen("package.in","r",stdin);freopen("package.out","w",stdout);
	memset(f,0,sizeof(f));
	int m,n,h=0;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&w[i],&c[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=w[i];j--)
		{
			if(f[j]<f[j-w[i]]+c[i])f[j]=f[j-w[i]]+c[i];
		}
	}
	printf("%d",f[m]);
	return 0;
}
