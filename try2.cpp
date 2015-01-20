#include "bits/stdc++.h"
using namespace std;
bool compare( array<int,2> a, array<int,2> b)
{
	return a[0]<b[0];
}
int main()
{
	int i,j;
	array<array<int,2>, 5> ar1;
	for(i=0;i<5;i++)
	{
		for(j=0;j<2;j++)
		{
			cin>>ar1[i][j];
		}
	}
	cout<<"\n earlier it is \n";
	for(i=0;i<5;i++)
	{
		for(j=0;j<2;j++)
		{
			cout<<ar1[i][j]<<" ";
		}
		cout<<"\n";
	}
	sort(ar1.begin(),ar1.end(),compare);
	cout<<"\n after sorting \n";
	for(i=0;i<5;i++)
	{
		for(j=0;j<2;j++)
		{
			cout<<ar1[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
