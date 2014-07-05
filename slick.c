#include<stdio.h>
typedef struct st
{
	int large;
	int many;
}sl;
int main()
{
	int slick[251][251];
	sl sliker[251];
	while(1)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		if(m==0&&n==0)
		{
			return 0;
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&slick[i][j]);
			}
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(slick[i][j]==1)
				{
						
