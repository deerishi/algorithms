#include "bits/stdc++.h"
using namespace std;
char arr[1<<10];
int main()
{
	//char arr[20]="hello world";
	int i=10;
    int *p=&i;
    int *q=p;
    *p=12;
    *q=34;
    cout<<"i is "<<i<<"\n";
	//cout<<"\n arr[1] is "<<(i);

    return 0;
}
