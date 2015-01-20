#include "bits/stdc++.h"

using namespace std;

int main()
{
	set<long long int> marked;
	long long  count=0,i,j;
	marked.clear(i);
	int num=5000000;
	int y=num/2;
	int marked[5000000];
	memset(marked,0,5000000);
	for(i=2;i<=sqrt(num)+1;i++)
	{
		if(count==1000000)
		break;
		if(marked[i]==-1) continue;
		marked[2*i]=-1;
		x=(y-y%i)
		for( j=2*i;j<=num;j=j+i)
		marked.insert(j);
	}

	/*for(i=2;i<100;i++)
	{
		if(marked.count(i)==0)
		{
			cout<<i<<",";count++;
		}
		
	}*/
	cout<<"\n count is "<<count<<"\n";
	return 0;
		
}
		
