#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int a[18],n;
bool b[18]={true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true};
bool ss(int x)
{
	if(x==2||x==3||x==5||x==7||x==11||x==13||x==17||x==19||x==23||x==29||x==31||x==37)return true;
	else return false;
}
void print()
{
	for(int i=2;i<=n;i++){if(a[i]==0)return;}
	for(int i=1;i<=n;i++)
	{
		if(i==1)printf("%d",a[i]);
		else printf(" %d",a[i]);
	}
	printf("\n");
}
void dfs(int n,int v)
{
	if(v==n&&ss(1+a[n])==true){print();return;}
    int i,j;
    for(i=2;i<=n;i++)
    {
    	if((b[i]==true)&&(ss(i+a[v])))
    	{
    		v++;
    		a[v]=i;
    		b[i]=false;
    		dfs(n,v);
    	}
		a[v]=0;
    	b[i]=true;
    	v--;
    }
}
int main()
{
	freopen("prime.in","r",stdin);
	freopen("prime.out","w",stdout);
	scanf("%d",&n);
	b[1]=false;
	a[1]=1;
	dfs(n,1);
	return 0;
}
