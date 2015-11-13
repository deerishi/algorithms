#include "bits/stdc++.h"
char TEMP[1<<10],CH;
using namespace std;

int getInt()
{
	int sign=1,n=0;
	CH=getc_unlocked(stdin);
	while(CH<'-') CH=getc_unlocked(stdin);
	
	if(CH=='-') sign=-1,CH=getc_unlocked(stdin);
	
	while(isdigit(CH))
	{
		n=n*10+CH-'0';
		CH=getc_unlocked(stdin);
	}
	return n*sign;
} 

int arr[300001];
int main()
{
	int windowStart,i,j;
	int N=getInt();
	int M=getInt();

	for(i=0;i<N;i++)
	{	
		arr[i]=getInt();
		cout<<"arr["<<i<<"] is "<<arr[i]<<"\n";
	}
	i=1;
	windowStart=0;
	int sum=0,maxs=INT_MIN;
	while(i<N)
	{
		if(sum<=0 and arr[i] > 0)
		{
			sum=arr[i];
			if(maxs<sum)
			{
				maxs=sum;
			}
		}
		else
		{
			sum+=arr[i];
		}
		printf("sum is %d and arr[i] is %d and maxs is %d\n",sum,arr[i],maxs);
		if(maxs< sum )
		{
			maxs=sum;
			//i++;
		}

		i++;
	}
	printf("%d\n",maxs);
	return 0;
}
		

