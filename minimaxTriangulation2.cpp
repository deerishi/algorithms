#include "bits/stdc++.h"
using namespace std;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
class Order
{
    public:
    
    bool operator() (double a,double b)
    {
        return a<b;
    }
};
priority_queue<double,vector<double>,Order> maxHeap;
double dp[55][55];
bool isFilled[55][55];
vector<pair<int,int> > v1;
/*
double findArea(int i ,int j)
{
    cout<<"Points "<<v1[i].first<<","<<v1[i].second<<" and "<<v1[j].first<<","<<v1[j].second<<" : ";
    double dist=double((v1[i].first-v1[j].first)*(v1[i].first-v1[j].first) + (v1[i].second-v1[j].second)*(v1[i].second-v1[j].second));
    cout<<sqrt(dist)<<"\n";
    return sqrt(dist);
}*/



double findArea(int i,int k,int j)
{
    //cout<<"area called for "<<i<<","<<k<<","<<j<<"\n";
    pair<int,int> p1=v1[i],p2=v1[k],p3=v1[j];
    double d1,d2,d3;
    d1=sqrt(double((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second)));
    d2=sqrt(double((p1.first-p3.first)*(p1.first-p3.first) + (p1.second-p3.second)*(p1.second-p3.second)));
    d3=sqrt(double((p2.first-p3.first)*(p2.first-p3.first) + (p2.second-p3.second)*(p2.second-p3.second)));
    double semiParameter=(d1+d2+d3)/2;
    double area1=semiParameter*(semiParameter-d1)*(semiParameter-d2)*(semiParameter-d3);
    
    //cout<<"Area by ("<<p1.first<<","<<p1.second<<"),("<<p2.first<<","<<p2.second<<"),("<<p3.first<<","<<p3.second<<") is "<<sqrt(area1)<<"\n";
    return sqrt(area1);
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
    if(isFilled[start][end]==true)
    {
        return dp[start][end];
    }
    if(end-start<2)
    {
        dp[start][end]=0.0;
        isFilled[start][end]=true;
        return 0.0;
    }
    double res,res2=DBL_MAX;
    Forall(k,start+1,end-1)
    {
        double temp1=findArea(start,k,end);
        double temp2=max(findMinTriangulation(start,k),findMinTriangulation(k,end));
        res=max(temp1,temp2);
        res2=min(res2,res);
    }
    dp[start][end]=res2;
    isFilled[start][end]=true;
    return res2;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,k,N,x,y,t;
    double res1,res2=DBL_MAX;
    cin>>t;
    while(t--)
    {   
        cin>>N;
        For(i,0,N)
        {
            cin>>x>>y;
            v1.push_back(make_pair(x,y));
        }
        For(i,0,N)
        {
            For(j,0,N)
            {
                isFilled[i][j]=false;
            }
        }
        
        For(i,1,N-1)
        {
            //cout<<"splitting at "<<i<<"\n";
            double temp1=findArea(0,i,N-1);
            double temp2=max(findMinTriangulation(0,i),findMinTriangulation(i,N-1));
            res1=max(temp1,temp2);
            res2=min(res1,res2);
            //cout<<"\n\n new trigulation res1 is "<<res1<<" and res2 is "<<res2<<"\n\n"; 
        }
        cout<<std::fixed;
        cout<<std::setprecision(1);
        cout<<res2<<"\n";
    }
    
    return 0;
}
