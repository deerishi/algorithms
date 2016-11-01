//SPOJ LRUCACHE
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

class Cache
{
    int num;
    public:
    Cache *next,*prev;
    Cache(int n):num(n),next(NULL),prev(NULL){}
    int getId(){return num;}
}*head,*last;

unordered_map<int,Cache*> cacheMap1;
vector<int> arr;
void printMap()
{
    for(auto it=cacheMap1.begin();it!=cacheMap1.end();it++)
    {
        cout<<(it->first)<<","<<(it->second)<<"\n";
    }
}

void insertNew(int val)
{
    Cache *newNode=new Cache(val);
    if(head==NULL and last==NULL)
    {
        head=newNode;
        last=newNode;
        cacheMap1[val]=head;
        return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    cacheMap1[val]=head;
}
void reassign(int val)
{
    Cache *temp=cacheMap1[val];
    if(temp->next==NULL)
    { //MEANS ITS THE LAST ONE
        last=last->prev;
        last->next=NULL;
       
    }
    else
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
     delete temp;
    
    Cache *newNode=new Cache(val);
    if(head==NULL and last==NULL)
    {
        head=newNode;
        last=newNode;
        return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    cacheMap1[val]=head;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,k,n,size,x;
    cin>>size>>n;

    For(i,0,n)
    {
        cin>>x; 
        arr.push_back(x);
       
    }
   
    int faults=0;
    int sizec=0;
    cacheMap1.clear();
    For(i,0,n)
    {
        

        if(cacheMap1.find(arr[i])==cacheMap1.end())
        {
            //cout<<"Fault at  "<<arr[i]<<"\n";
            if(cacheMap1.size()==size)
            {
                
               //delete the last one and then push
               Cache *temp=last;
               cacheMap1.erase(temp->getId());
               if(last->prev==NULL) //size 1 cacheMap1
               {
                    last=NULL;
                    head=NULL;
               }
               else
               {
                    last=last->prev;
                    last->next=NULL;
               }
                delete temp;
            }
            insertNew(arr[i]);
            faults++;
        }
        else
        {
            //cout<<"No fault at "<<arr[i]<<"\n";
            if(cacheMap1.size()==1 or size==1 or head->getId()==arr[i]) continue;
            
            reassign(arr[i]);
        }
        //cout<<"map is  \n";printMap();cout<<"\n";
        //cout<<"head is "<<head->getId()<<"\n";
    }
    cout<<faults<<"\n";
    return 0;
}
