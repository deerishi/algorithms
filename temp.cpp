#include "bits/stdc++.h"


using namespace std;
/*bool compare(const void *aa, const void  *bb)
{
  
    return a[0]<b[0];
}*/
int main()
{
	unordered_map<int,set<int> > m1;
	
	
	set<int> s1;
	s1.insert(12);
	s1.insert(13);
	m1[2]=s1;
	set<int>:: iterator it;
	it=m1[2].begin();
	for(it=m1[2].begin();it!=m1[2].end();it++)
	{
	    cout<<*it<<" ";
	}
	cout<<"\n";
	return 0;
}
