//SPOJ 
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

vector<int> arr[10005];
bool visited[10005];
int n;
int bfs1()
{
    queue<int> bfsq;
    int node1,node2;
    bfsq.push(1);

    int lastNode;
    while(!bfsq.empty())
    {
        node1=bfsq.front();
        //cout<<"current node is "<<node1<<"\n";
        bfsq.pop();
        if(visited[node1]) continue;
        visited[node1]=true;
        lastNode=node1;
        for(auto it=arr[node1].begin();it!=arr[node1].end();it++)
        {
            if(!visited[*it])
            {
                bfsq.push(*it);
            }
        }
        //bfsq.push(-1);
    }
    //cout<<"lastNode is "<<lastNode<<"\n";
    return lastNode;
}

int bfs2(int startNode)
{
    memset(visited,false,n+2);
    queue<int> bfsq;
    bfsq.push(startNode);
    bfsq.push(-1);
    int node1,longestPath=0;
    while(!bfsq.empty())
    {
        node1=bfsq.front();
        bfsq.pop();
    
        if(node1==-1)
        {
            if(!bfsq.empty())
             {   bfsq.push(-1);
            
                longestPath++; }	
            
            continue;
        }
        if(visited[node1]) continue;
        visited[node1]=true;
        for(auto it=arr[node1].begin();it!=arr[node1].end();it++)
        {
            if(!visited[*it])
            {
                bfsq.push(*it);
            }
        }
        
    }
    return longestPath;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,x,y;
    cin>>n;
    
    Forall(i,1,n-1)
    {

        cin>>x>>y;
        //cout<<"x is "<<x<<" y is "<<y<<"\n";
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    
    memset(visited,false,n+2);
    int last=bfs1();
    int res=bfs2(last);
    cout<<res<<"\n";
    return 0;
    
    
}
