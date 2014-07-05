#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int s[n];
		for(int i=0;i<n;i++)
			scanf("%d",&s[i]);
		int q;
		scanf("%d",&q);
		int own[n];
		for(int i=0;i<n;i++)
			own[i]=i;
		while(q--)
		{
			int cas;
			int x,y;
			scanf("%d",&cas);
			if(cas)
			{
				scanf("%d",&x);
				x=x-1;
				while(own[x]!=x)
				{
					x=own[x];
					own[x]=own[own[x]];
				}
				printf("%d\n",own[x]+1);
			}
			else
			{
				scanf("%d%d",&x,&y);
				x=x-1;
				y=y-1;
				while(own[x]!=x)
				{
					x=own[x];
					own[x]=own[own[x]];
				}
				while(own[y]!=y)
				{
					y=own[y];
					own[y]=own[own[y]];
				}
				if(s[own[x]]>s[own[y]])
				{
					own[y]=own[x];
				}
				else if(s[own[x]]<s[own[y]])
				{
					own[x]=own[y];
				}
				else if(own[x]==own[y])
					printf("Invalid query!\n");
			}
		}
	}
	return 0;
}

			
