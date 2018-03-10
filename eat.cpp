#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int a[2000100],b[2000100];
int cmp1(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("eat.in","r",stdin);
	freopen("eat.out","w",stdout);
	int n,m,i,j,k=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(j=1;j<=m;j++)scanf("%d",&b[j]);
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+m+1);
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
	    if(a[i]>b[j])k++;
	    else break;
	}	
	printf("%d",k);
	return 0;	
}
