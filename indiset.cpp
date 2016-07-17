#include "bits/stdc++.h"
using namespace std;
#define For(i,start,end) for(i=start;i<end;i++)

vector<int> adj[2005];
unordered_map<int,int> map1;
bool visited[2005];
vector<pair<int,int> > v1;
vector<int> result;
bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.second<b.second;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int i,j,k,x,y;
    For(j,1,n+1)
    {
        visited[i]=false;
    }
    For(i,0,m)
    {
            cin>>x>>y;
            if(map1.find(x)==map1.end())
            {
                map1[x]=1;   
            }
            else
            {
                map1[x]++;
            }
            if(map1.find(y)==map1.end())
            {
                map1[y]=1;   
            }
            else
            {
                map1[y]++;
            }
            
        
        adj[x].push_back(y);
        adj[y].push_back(x);
        
    }
    unordered_map<int,int>::iterator it;
    for(it=map1.begin();it!=map1.end();it++)
    {
        v1.push_back(make_pair(it->first,it->second));
    }
    sort(v1.begin(),v1.end(),cmp);
    vector<pair<int,int> >::iterator it2;
    vector<int>::iterator it3;
    for(it2=v1.begin();it2!=v1.end();it2++)
    {
        if(!visited[it2->first])
        {
            result.push_back(it2->first);
            for(it3=adj[it2->first].begin();it3!=adj[it2->first].end();it3++)
            {
                visited[*it3]=true;
            }
        }
        
    }
    for(it3=result.begin();it3!=result.end();it3++)
    {
        cout<<*it3<<" ";
    }
    cout<<"\n";
    return 0;
}
