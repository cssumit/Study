#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int lis(vector<int> ar)
{
	if(ar.size()==1)
	{
		return 1;
	}
	else if(ar[ar.size()-1]>ar[ar.size()-2])
	{
		ar.pop_back();	
		return 1+lis(ar);
	}
	else
	{
		ar.pop_back();
		return lis(ar);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> ar;
	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);
		ar.push_back(p);
	}
	int arc=lis(ar);
	printf("%d\n",arc);
	return 0;
}
		
