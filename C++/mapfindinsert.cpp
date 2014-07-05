#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	cin>>t;
	map<int,int> hello;
	while(t--)
	{
		int p;
		scanf("%d",&p);
		map<int,int>::iterator it=hello.find(p);
		if(it!=hello.end())
		{
			int r=it->second;
			it->second=r+1;
		}
		else
		{
			hello.insert(pair<int,int>(p,1));
		}
	}
	for(map<int,int>::iterator it=hello.begin();it!=hello.end();++it)
	{
		printf("%d %d\n",it->first,it->second);
	}
	return 0;
}
