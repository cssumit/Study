#include<iostream>
#include<vector>
#include<utility>
#include<cstdio>
#include<algorithm>
using namespace std;
bool func(const pair<unsigned long long,unsigned long long>& lhs,const pair<unsigned long long,unsigned long long >& rhs)
{
	return lhs.second < rhs.second; 
}
int main()
{
	unsigned long long n,k,p;
	scanf("%llu%llu%llu",&n,&k,&p);
	vector<pair<unsigned long long,unsigned long long> > vec;
	unsigned long long i=1;
	while(i<=n)
	{
		unsigned long long s;
		scanf("%lld",&s);
		pair<unsigned long long,unsigned long long> pi;
		pi=make_pair(i,s);
		vec.push_back(pi);
		i++;
	}
	sort(vec.begin(),vec.end(),func);
/*	for(long long j=0;j<n;j++)
	{
		printf("%lld ---%lld\n",vec[j].first,vec[j].second);
	}
*/	i=1;
	while(i<=p)
	{
		unsigned long long a,b;
		scanf("%llu%llu",&a,&b);
		if(a==b)
		{
			printf("Yes\n");
		}
		else
		{
			//pair<unsigned long long ,unsigned long long > mypaira,mypairb;
			unsigned long long  ai,bi;
			ai=lower_bound(vec.begin(),vec.end(),a,[](pair<unsigned long long, unsigned long long> const & x,unsigned long long d)
          { return x.second < d; });
			bi=lower_bound(vec.begin(),vec.end(),b,[](pair<unsigned long long, unsigned long long> const & x,unsigned long long d)
          { return x.second < d; });
		/*for(unsigned long long j=0;j<vec.size();j++)
		{
			if(vec[j].first==a)
			{
//				printf("%lld. j=%lld vec[j].first=%lld\n",i,j,vec[j].first);
				ai=j;
			}
			else if(vec[j].first==b)
			{
//				printf("%lld. j=%lld\n",i,j);
				bi=j;
			}
		}}*/
			int flag=0;
//		printf("%lld.a=%lld,b=%lld\n",i,ai,bi);
			if(ai<bi)
			{
				for(unsigned long long j=ai;j<bi;j++)
				{
//					printf("%lld.%lld\n",i,(vec[j+1].second-vec[j].second));
					if((vec[j+1].second-vec[j].second)>k)
					{
						flag=1;
						break;
					}
				}
			}
			else if(ai>bi)
			{
//				printf("yes");
				for(unsigned long long j=bi;j<ai;j++)
					if((vec[j+1].second-vec[j].second)>k)
					{
						flag=1;
						break;
					}
					
			}
			else
			{
				flag=0;
			}
			if(flag==1)
				printf("No\n");
			else
				printf("Yes\n");	
		}
		i++;
	}
	return 0;
}
