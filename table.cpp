#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
char a[10000001];int w,l,i=1;
int main()
{
	freopen("table.in","r",stdin);
	freopen("table.out","w",stdout);
	while(cin>>a[i])
	{
		if(a[i]=='E')break;
		else 
		{
			if(a[i]=='W')w++;
			else l++;
		}
		if(w>=11&&w-l>=2)
		{
			cout<<w<<":"<<l<<endl;
			w=l=0;
		}
		else if(l>=11&&l-w>=2)
		{
			cout<<w<<":"<<l<<endl;
			w=l=0;
		}
		i++;
	}
	cout<<w<<":"<<l<<endl<<endl;
	w=l=0;
	for(i=1;i<=strlen(a)-1;i++)
	{
		if(a[i]=='E')break;
		else 
		{
			if(a[i]=='W')w++;
			else l++;
		}
		if(w>=21&&w-l>=2)
		{
			cout<<w<<":"<<l<<endl;
			w=l=0;
		}
		else if(l>=21&&l-w>=2)
		{
			cout<<w<<":"<<l<<endl;
			w=l=0;
		}
	}
	cout<<w<<":"<<l<<endl;
	return 0;
}
