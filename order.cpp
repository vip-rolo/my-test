# include <cstring>
# include <iostream>
#include<cstdio>
using namespace std;

int n,vis[400000],cnt[10],queue[400000],sum;
char c[20],s[20];

int id(char i)
{
    switch(i)
    {
	case 'A':    return 0;
	case 'T':    return 1;
	case 'C':    return 2;
	case 'G':    return 3;
    }
}

int exchange(int a[])
{
    int sum=0,mul=1;
    for(int i=n-1;i>=0;i--)
    {
        sum+=a[i]*mul;
        mul*=4;
    }
    return sum;
}

void decode(int re,int a[])
{
    for(int i = n-1;i>=0;i--)
    {
        a[i] = re % 4;
        re/=4;
    }
}

int hash (int a[])
{
    int t=sum,rank=0;
    int c[10];
    memcpy(c,cnt,sizeof(c));     //������ĸ���ֵĴ���;
    for(int i=0;i<n;i++)         //�ӵ�һ����ĸ��ʼ,��ʼ���ֵ���������֮ǰ���ַ�������Щ;
    {
        for(int j=0;j<a[i];j++)
            if(c[j])    rank += t*c[j]/(n-i);     //�������õ���ȫ���еķ�������ģ�����չ���������������;
			
	t = t*c[a[i]]/(n-i);
	--c[a[i]];
    }
    return rank;
}

int main()
{
    freopen("order.in","r",stdin);
	freopen("order.out","w",stdout);
    while(cin>>n&&n)
    {
        memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        int current[20],target[20],i,j;
        sum=1;
        scanf("%s%s",c,s);
        for(i=0;i<n;i++)
        {
            current[i]=id(c[i]);      //����ĸת��Ϊ���֣�
            target[i]=id(s[i]);
            sum*=i+1;                //���㵱ǰN�����ظ�����ĸ��ȫ����;
            cnt[current[i]]++;       //ͳ��ÿ����ĸ���ֵĴ���;
        } 
        int currentcode=exchange(current),targetcode=exchange(target);    //������ת��Ϊʮ����;
		
        for(i=0;i<4;i++)     //����������ַ�����ȫ���У�ȥ��֮��
            for(j=1;j<=cnt[i];j++)
                sum/=j;
			
	if(currentcode==targetcode)   { printf("0\n"); continue; }
			
	int tail=0,head=0,step=1,ans=-1;
			
			queue[tail++] = currentcode;
			vis[hash(current)] = 1;
			
			for(;head < tail && ans==-1;step++)    //��ʼ����;
			{
				int size =tail - head;
				for(; size ;head++,size--)    //��ÿһ�㿪ʼ;
				{
					for(i=0;i<2;i++)
					{
						decode(queue[head],current);     //��ʮ������ת��Ϊ�Ľ��Ƶģ�
						//�������ֽ���;
						if(i==0)    swap(current[0],current[1]);
						else
						{
							j=current[0];
							for(int k=1;k<n;k++)
								current[k-1]=current[k];
							current[n-1]=j;
						}
						
						j=hash(current);    //�����ǰ����״̬��hashֵ;
						
						if(!vis[j])
						{
							vis[j]=1;
							currentcode=exchange(current);
							if(currentcode==targetcode)
							{
								ans=step;
								break;
							}
							queue[tail++]=currentcode;
						}
					}
				}
			}
			printf("%d\n",ans);
    }
    getchar();
    return 0;
}

