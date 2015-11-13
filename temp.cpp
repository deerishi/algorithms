#include "bits/stdc++.h"
using namespace std;

int main()
{
	char a1[4]={'N','S','E','W'};
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(i==j)
			{
				continue;
			}
			else
			{
				cout<<a1[i]<<"2"<<a1[j]<<"="<<"sem_create(\""<<a1[i]<<"2"<<a1[j]<<"\",2);\n";
			}
		}
	}
	cout<<"\n\n";
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(i==j)
			{
				continue;
			}
			else
			{
				cout<<"KASSERT("<<a1[i]<<"2"<<a1[j]<<" !=NULL);\n";
				cout<<"sem_destroy("<<a1[i]<<"2"<<a1[j]<<");\n";
			}
		}
	}
	return 0;
}
