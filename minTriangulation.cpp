#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

vector<pair<int,int> > v1;
/*
double findCost(int i ,int j)
{
    cout<<"Points "<<v1[i].first<<","<<v1[i].second<<" and "<<v1[j].first<<","<<v1[j].second<<" : ";
    double dist=double((v1[i].first-v1[j].first)*(v1[i].first-v1[j].first) + (v1[i].second-v1[j].second)*(v1[i].second-v1[j].second));
    cout<<sqrt(dist)<<"\n";
    return sqrt(dist);
}*/

double dp[100][100];
bool filledDp[100][100];

double findCost(int i,int k,int j)
{
    pair<int,int> p1=v1[i],p2=v1[k],p3=v1[j];
    double d1,d2,d3;
    d1=sqrt(double((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second)));
    d2=sqrt(double((p1.first-p3.first)*(p1.first-p3.first) + (p1.second-p3.second)*(p1.second-p3.second)));
    d3=sqrt(double((p2.first-p3.first)*(p2.first-p3.first) + (p2.second-p3.second)*(p2.second-p3.second)));
    
    return d1+d2+d3;
}
/*double findMinTriangulation(int start,int end)
{
    int i,j,k;
   Forall(i,start,end)
   {
        Forall(j,start,end)
        {
            Forall(k,start,end)
            {
                if(k)
            }
        }
        dp[i][j]=min
   }
}*/

double findMinTriangulation(int start,int end)
{
    int i,j,k;
    if(end-start<2)
    {
        return 0.0;
    }
    double res=double(INT_MAX);
    Forall(k,start+1,end-1)
    {
        double temp=findMinTriangulation(start,k)+findMinTriangulation(k,end)+findCost(start,k,end);
        res=min(res,temp);
    }
    return res;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,k,N,x,y;
    cin>>N;
    For(i,0,N)
    {
        cin>>x>>y;
        v1.push_back(make_pair(x,y));
    }
    cout<<"res is "<<findMinTriangulation(0,v1.size()-1)<<"\n";
    return 0;
}
