#include "bits/stdc++.h"
using namespace std;
#define REP(i,n) for(int i=0; i<n; i++)
#define For(i,st,end) for(int i=st;i<end;i++)
#define db(x) cout << (#x) << " = " << x << endl;
#define mp make_pair
#define pb push_back
typedef long long int ll;
int main(){
	
	int i=1,j=1,k=1;
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	For(i,0,n)
	{
	    For(j,0,m)
	    arr[i][j]=i*j;
	}
	cout<<" res is "<<(i&j&k)<<" \n";
	return 0;
    
}
