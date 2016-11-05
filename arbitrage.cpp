#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
int n;
void findRes(){
    unordered_map<string,int> map1;
    int i,j,k,m;
    string s1,s2;
    For(i,1,n+1){
        cin>>s1;
        map1.insert(make_pair(s1,i));
    }
    cin>>m;
    int adj[35][35];
    double arr[35][35],x;
    memset(arr,0,sizeof(arr));
    For(i,0,n){
        arr[i][i]=1;
        adj[i][i]=1;
    }

    memset(adj,0,sizeof(adj));
    For(i,0,m){
        cin>>s1>>x>>s2;
        //cout<<"s1 is "<<s1<<" x is "<<x<<" s2 is "<<s2<<"\n";
        adj[map1[s1]][map1[s2]]=1;
        arr[map1[s1]][map1[s2]]=x;
    }
    /*cout<<"Before arr was \n";
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    For(k,1,n+1){
        For(i,1,n+1){
            For(j,1,n+1){
                //if(adj[i][k]==1 and adj[k][j]==1){
                    arr[i][j]=max(arr[i][j],arr[i][k]*arr[k][j]);
                    //adj[i][j]=1;
                //}
            }
        }
    }
    /*cout<<"\nNow arr is \n";
     for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    For(i,1,n+1){
        if(arr[i][i]>1.0){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
}
int main(){
    std::ios::sync_with_stdio(false);
    int i=1;
    while(1){
        cin>>n;
        //cout<<"n is "<<n<<"\n";
        if(n==0){
            break;
        }
        cout<<"Case "<<i<<": ";
        findRes();
        i++;
    }
}
