#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int a[501][501],l[500][2],len,j_;
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
			if(a[ddx][ddy]!=1&&ddx>=0&&ddx<=len&&ddy>=0&&ddy<=j_)
			{
				l[t][0]=ddx;l[t][1]=ddy;
				if(t==500)t=1;else t++;
			}
		}
		a[l[h][0]][l[h][1]]=1;
	}
}
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	string aa;int i,j=0,ans=0;
	ios::sync_with_stdio(0);
	while(cin>>aa)
	{
		j_++;
		len=aa.size();
		for(i=0;i<len;i++)
		{
			if(aa[i]=='0')a[j_][i]=0;
			else a[j_][i]=1;
		}
	}
	bfs(0,0);
	for(i=1;i<=j;i++)for(j=1;j<=len;j++)if(a[i][j_]==0)ans++;
	cout<<ans;
	return 0;
}
