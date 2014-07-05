#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
typedef struct st
{
	long long t;
	long long c;
}tab;
using namespace std;
bool my_func(tab t1,tab t2)
{
	double rat1=(double)t1.t/(double)t1.c;
	double rat2=(double)t2.t/(double)t2.c;
	if(rat1==rat2)
		return t1.c<t2.c;
	else
		return rat2<rat1;
}
int main()
{
	long long n,m,h;
	vector<tab> vec;
	scanf("%lld%lld%lld",&n,&m,&h);
	long long s1=0;
	for(long long i=0;i<h;i++)
	{
		tab temp;
		scanf("%lld%lld",&temp.t,&temp.c);
		vec.push_back(temp);
		s1=s1+temp.t;
	}
	if(s1<(n*m))
	{
		printf("Impossible\n");
		return 0;
	}
	sort(vec.begin(),vec.end(),my_func);
/*	for(long long i=0;i<vec.size();i++)
	{
		printf("%lld, %lld\n",vec[i].t,vec[i].c);
	}
*/	long long sum=0;
	long long cost=0;
	long long i=0;
	while(sum<(n*m))
	{
		sum=sum+vec[i].t;
		cost=cost+vec[i].t*vec[i].c;
		if(sum>(n*m))
		{
			cost=cost-(sum-n*m)*vec[i].c;
		}
		i++;
	}
	printf("%lld\n",cost);
	return 0;
}
