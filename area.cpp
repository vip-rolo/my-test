#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int a[501][501],l[500][2],b[501][501];
int dx[5]={0,0,-1,0,1};
int dy[5]={0,-1,0,1,0};
void bfs(int x,int y)
{
	int h=0,t=2;l[1][0]=x;l[1][1]=y;
	while(h!=t)
	{
		if(h==500)h=1;else h++;
		
		for(int i=1;i<=4;i++)
		{
			int ddx=l[h][0]+dx[i],ddy=l[h][1]+dy[i];
			if(a[ddx][ddy]!=1&&b[ddx][ddy]!=1)
			{
				l[t][0]=ddx;l[t][1]=ddy;
				if(t==500)t=1;else t++;
			}
		}
		b[l[h][0]][l[h][1]]=1;
	}
}
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	string aa;int i,j=1,ans=0,len,j_;
	ios::sync_with_stdio(1);
	while(cin>>aa)
	{
		len=aa.size();
		for(i=0;i<len;i++)
		{
			if(aa[i]=='0')a[j][i]=0;
			else 
			{
				a[j][i]=1;b[j][i]=1;
			}
			j++;
		}
	}
	bfs(0,0);
	for(i=1;i<=4;i++)for(j_=1;j_<=5;j_++)if(b[i][j_]==0)ans++;
	cout<<ans;
	return 0;
}
