#include "bits/stdc++.h"
using namespace std;
int main()
{
	int t,n,i,j;
	char ch;
	std::ios_base::sync_with_stdio(false);
	string str1,str2,str3,str4,str5,str6,str;
	map<string,int> m1;
	map<string,int>::iterator it;
	cin>>t;
	//cout<<" t is "<<t<<"\n";
	while(t--)
	{
		cin>>n;
		//cout<<"n is "<<n<<"\n";
		m1.clear();
		for(j=0;j<n;j++)
		{
			str.clear();
			cin>>str1>>str2>>str3>>str4>>str5>>str6;
			str+=str1+' '+str2+' '+str3+' '+str4+' '+str5+' '+str6;
			//cout<<"s is "<<str<<"\n";
			if(m1.find(str)==m1.end())
			{
				m1[str]=1;
			}
			else
			{
				m1[str]++;
			}
		}
		for(it=m1.begin();it!=m1.end();it++)
		{
			cout<<it->first<<" "<<it->second<<"\n";
		}
		
		cout<<"\n";
		//ch=getc_unlocked(stdin);
		//cout<<"ch is "<<(int)ch<<" end  ";
	}
	return 0;
}
