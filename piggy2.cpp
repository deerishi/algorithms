#include<iostream>
#include<cstdio>
//#include<cstring>
using namespace std;
 
int main()
{
int t,n,i,f,d,val,wt,j;
int a[10010];
scanf("%d",&t);
while(t--)
{
scanf("%d%d",&i,&f);
d=f-i;
for(j=0;j!=10010;j++)
a[j]=32767;
scanf("%d",&n);
for(i=0;i!=n;i++)
{
scanf("%d%d",&val,&wt);
if(a[wt]>val)
{
a[wt]=val;
for(j=wt+1;j<=d;j++)
{
if(a[wt] + a[j-wt] < a[j])
a[j]=a[wt]+a[j-wt];
}
}
}
if(a[d]==32767)
cout<<"This is impossible."<<endl;
else
cout<<"The minimum amount of money in the piggy-bank is "<<a[d]<<"."<<endl;
}
return 0;
}

