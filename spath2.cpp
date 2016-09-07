#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

class Order
{
    public: 
        
        bool operator() (pair<int,int> a,pair<int,int> b)
        {
            return a.second>b.second;
        }
};

vector<pair<int,int> > cities[10001];
unordered_map<string,int> names;
unordered_map<int,int> shpaths[10001];
int n;

int findSPath(int city1,int city2)
{
    if(shpaths[city1].find(city2)!=shpaths[city1].end())
    {
        return shpaths[city1].find(city2)->second;
    }
    priority_queue<pair<int,int>,vector<pair<int,int> > ,Order> q1;
    unordered_map<int,bool> visited;
    int i,j,k;
   

    q1.push(make_pair(city1,0));
    
    while(!q1.empty())
    {
        pair<int,int> currentCity=q1.top();
        q1.pop();
        //cout<<"current city is "<<":"<<currentCity.first<<" with cost "<<currentCity.second<<"\n";
        visited[currentCity.first]=true;
        shpaths[i][currentCity.first]=currentCity.second;
        if(currentCity.first==city2)
        {
            return currentCity.second;
        }
        for(auto it=cities[currentCity.first].begin();it!=cities[currentCity.first].end();it++)
        {
            if(visited[(*it).first]==true)
            {
                continue;
            }
            q1.push(make_pair((*it).first,(*it).second+currentCity.second));
        }
        
    }
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    //std::cin::sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);
    int s,i,j,p,nr,cost,r;
    string name;
    cin>>s;
    string str1,str2,str3;
    
    while(s--)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cities[i].clear();
            shpaths[i].clear();
            cin>>str1;
            names[str1]=i;
            cin>>p;
            for(j=1;j<=p;j++)
            {
                cin>>nr>>cost;
                cities[i].push_back(make_pair(nr,cost));
            }
        }
        cin>>r;
        for(i=1;i<=r;i++)
        {
            cin>>str1>>str2;
            cout<<findSPath(names[str1],names[str2])<<"\n";
        }
        names.clear();
        
    }
    return 0;
}
