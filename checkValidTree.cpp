#include "bits/stdc++.h"
using namespace std;
//SPOJ DATING RISHI
typedef unsigned long long int ll;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
vector<int> arr[10002];
int main(){
    std::ios::sync_with_stdio(false);
    int i,j,n,x,m,y;
    cin>>n>>m;

    For(i,0,m){
        cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    bool visited[10002];
    memset(visited,false,n+1);
    stack<int> s1;
    s1.push(1);
    int prev=-1,cur;
    unordered_map<int,int> map1;//Node,Parent
    int parent;
    int num=0;
    map1.insert(make_pair(1,-1));
    while(!s1.empty()){
        cur=s1.top();
        s1.pop();
        num++;
        parent=map1[cur];
        For(i,0,arr[cur].size()){
            //cout<<"Neighbour of "<<cur<<" is "<<arr[cur][i]<<"\n";

            if(parent!=arr[cur][i]){
                if(map1.find(arr[cur][i])!=map1.end() and map1[arr[cur][i]]!=cur){

                    cout<<"NO\n";
                    return 0;
                }
                s1.push(arr[cur][i]);
                map1.insert(make_pair(arr[cur][i],cur));
            }
        }
        prev=cur;
    }
    if(num!=n){
         cout<<"NO\n";
         return 0;
    }
    cout<<"YES\n";
    return 0;

}
