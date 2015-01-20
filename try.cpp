#include "bits/stdc++.h"
using namespace std;
int compare( const void *aa, const void  *bb)
{
	int *a=(int *)aa;
	int *b=(int *)bb;
	if (a[0]<b[0])
	 return -1;
	else if (a[0]==b[0]) 
	return 0;
	else  
	 return 1;
	
}
int main() 
{
 	const char *s1="abcd e",*s2="abcd a";
 	cout<<"\n comparing "<<strcmp(s1,s2)<<"\n";
    return 0;
   }
