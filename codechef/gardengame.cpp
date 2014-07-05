#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#define MOD 1000000007
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		long long a[100001];
		long long ans,cnt;
		long long b[100001]={0};	
		scanf("%lld",&n);
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		for(long long i=1;i<=n;i++)
		{
			cnt=1;
			if(b[i]==0)
			{
				long long j=a[i];
				while(j!=i)
				{
					j=a[j];
					b[j]=1;
					cnt++;
				}
				b[i]=cnt;
			}
		}
		
	/*	for(long long i=1;i<=n;i++)
		{
			printf("%lld ",b[i]);
		}
	*/		
		ans=1;
		map<long long,long long> maps;
		for(long long i = 1 ; i <= n ; i++)
		{
			long long m=2;
        		long long ile,co;
        		while(m*m<=b[i])
        		{
            			co=ile=0;
            			if(b[i]%m==0)
            			{
					co=m;
                			while(b[i]%m==0)
                			{
                    				++ile;
                    				b[i]/=m;
                			}
					if(maps.count(co)>0)
					{
						if(ile>maps[co])
							maps[co]=ile;
					}
					else
					{
						maps.insert(pair<long long,long long>(co,ile));
					}
            			}
            			if(b[i]==1)break;
            				++m;
        		}
        		if(b[i]>1&&!maps.count(b[i]))maps.insert(pair<long long,long long>(b[i],1));
 		}
		map<long long ,long long>::iterator it;
		for(it=maps.begin();it!=maps.end();++it)
		{
			for(int i=0;i<it->second;i++)
			{
				ans=(ans*it->first)%MOD;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
	
				
		
