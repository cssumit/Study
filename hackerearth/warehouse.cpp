#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
	int n,t;
	scanf("%d%d",&n,&t);
	vector<int> ar;
	for(int i=1;i<=n;i++)
	{
		ar.push_back(i);
	}
	int gr[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			gr[i][j]=0;
	for(int i=0;i<t;i++)
	{
		int r,s;
		scanf("%d%d",&r,&s);
		gr[r-1][s-1]=1;
		gr[s-1][r-1]=1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d\t",gr[i][j]);
		printf("\n");
	}
	int cnt=0;
	int num=0;
	for(int i=0;i<ar.size();i++)
	{
		int flag=0;
		for(int j=0;j<n;j++)
		{
			if(gr[i][j]==1)
			{
				if(i!=j)
				{	
					for(int k=0;k<n;k++)
					gr[j][k]=0;
				}
				cnt++;
			}
		
		}
	}
	printf("%d\n",cnt);
	return 0;
}	
