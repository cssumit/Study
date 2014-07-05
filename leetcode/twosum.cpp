#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> vec;
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		int p;
		cin>>p;
		vec.push_back(p);
	}
	int target;
	cin>>target;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(vec[i]+vec[j]==target)
			{
				break;
			}
		}
	}
	cout<<"index1="<<i+1<<" index2="<<j+1;
	return 0;
}
