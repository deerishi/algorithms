#include "bits/stdc++.h"
using namespace std;
class Order
{
    public: 
        
        bool operator() (pair<int,int> a,pair<int,int> b)
        {
            return a.second>b.second;
        }
};


//unordered_map<int,int> shpaths[10001];
int n;

int findSPath(int city1,int city2,vector<vector<pair<int, int> > >& cities)
{
   
    priority_queue<pair<int,int>,vector<pair<int,int> > ,Order> q1;
    unordered_map<int,bool> visited;
    int i,j,k;
   

    q1.push(make_pair(city1,0));
    
    while(!q1.empty())
    {
        pair<int,int> currentCity=q1.top();
        q1.pop();

        visited[currentCity.first]=true;
        //shpaths[i][currentCity.first]=currentCity.second;
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
    string str1,str2,str3;
    int s,i,j,p,nr,cost,r;
    
    cin>>s;
        
    while(s--)
    {
        vector<vector<pair<int, int> > > cities;
        unordered_map<string,int> names;
        cities.push_back(vector<pair<int, int> > ());
        cin>>n;
        for(i=1;i<=n;i++)
        {
            
            cin>>str1;
            names[str1]=i;
            cities.push_back(vector<pair<int, int> > ());
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
            cout<<findSPath(names[str1],names[str2],cities)<<"\n";
        }
        
    }
    return 0;
}
