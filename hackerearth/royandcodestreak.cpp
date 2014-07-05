#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int cnt=0;
		int max=0;
		vector<int> vec;
		for(int i=0;i<n;i++)
		{
			int s;
			int r;
			scanf("%d%d",&s,&r);
			if(r==1)
			{	if(!binary_search(vec.begin(),vec.end(),s))
				{
					vec.push_back(s);
					cnt++;
				}
			}
			else if(r==0)
			{
				if(cnt>max)
					max=cnt;
				cnt=0;
			}
/*			for(int j=0;j<vec.size();j++)
			{
				printf("%d cnt=%d\n",vec[j],cnt);
			}
*/		}
		if(cnt>max)
			max=cnt;
		printf("%d\n",max);
	}
	return 0;
}
