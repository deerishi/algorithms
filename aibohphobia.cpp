#include "bits/stdc++.h"
using namespace std;

void sgets(string &s)
{
	s.clear();
	char ch=getc_unlocked(stdin);
	while(!isalpha(ch)) ch=getc_unlocked(stdin);
	while(isalpha(ch))
	{
		s+=ch;
		ch=getc_unlocked(stdin);
	}
}
int arr[6102][6102];
int main()
{
	int i,j,t,len;
	char s[6102];
	for(i=0;i<6102;i++)
	{
		arr[i][0]=0;
		arr[0][i]=0;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		len=strlen(s);
		//cout<<"len is "<<len<<"\n";
		for(i=1;i<=len;i++)
		{
			for(j=1;j<=len;j++)
			{
				//cout<<"comparing "<<s[i-1]<<" and "<<s[len-j]<<"\n";
				if(s[i-1]==s[len-j])
				{
					arr[i][j]=1+arr[i-1][j-1];
				}
				else
				{
					arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
				}
			}
		}
			/*cout<<"the matrix is \n";
			for(i=0;i<=len;i++)
			{
				for(j=0;j<=len;j++)
				{
					cout<<arr[i][j]<<" ";
				}
				cout<<"\n";
			}*/
		
		printf("%d\n",len-arr[len][len]);
	}
	return 0;
}
