#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int dijikstra(int gr[900][4],int st,int en,int k)
{
	queue<int> que;
	que.push(st);
	int dis[k];
	for(int i=0;i<k;i++)
		dis[i]=-1;
	dis[st]=0;
	while(!que.empty())
	{
		int v=que.front();
		que.pop();
		for(int i=0;i<4;i++)
		{
			if(gr[v][i]!=-1&&dis[gr[v][i]]==-1)
			{
				dis[gr[v][i]]=dis[v]+1;
				que.push(gr[v][i]);
			}
		}
	}
	return dis[en];
}
int main()
{
	char jun[30][30];
	int gr[900][4];
	int n;
	int k=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>jun[i][j];
		}
	}
	int st,en;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(jun[i][j]!='T')
			{
				if(i-1<0||jun[i-1][j]=='T')
					gr[k][0]=-1;
				else
					gr[k][0]=(n*(i-1))+j;
				if(j-1<0||jun[i][j-1]=='T')
					gr[k][1]=-1;
				else
					gr[k][1]=(n*i)+(j-1);
				if(i+1>=n||jun[i+1][j]=='T')
					gr[k][2]=-1;
				else
					gr[k][2]=(n*(i+1))+j;
				if(j+1>=n||jun[i][j+1]=='T')
					gr[k][3]=-1;
				else
					gr[k][3]=(n*i)+(j+1);
				if(jun[i][j]=='S')
					st=(n*i)+j;
				if(jun[i][j]=='E')
					en=(n*i)+j;
			}
			else
			{
				for(int m=0;m<4;m++)
				{
					gr[k][m]=-1;
				}
			}
			k++;
		}
	printf("%d\n",dijikstra(gr,st,en,k));
	return 0;
}
