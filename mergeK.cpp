#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter(it,name) for(it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)

 struct ListNode {
     int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

  ListNode* merge1(ListNode* l1,ListNode* l2)
    {
        ListNode* newList=NULL,*head=NULL,*cur=NULL;
        cout<<"l1 is "<<l1->val<<" l2 is "<<l2->val<<"\n";
        while(l1!=NULL and l2!=NULL)
        {
            
            if(l1->val < l2->val)
            {
                
                if(newList==NULL)
                {
                    head=new ListNode(l1->val);
                    newList=head;
                }
                else
                {
                    head->next=new ListNode(l1->val);
                    head=head->next;
                }
                 l1=l1->next;
            }
            else 
            {
                if(newList==NULL)
                {
                    head=new ListNode(l2->val);
                    newList=head;
                }
                else
                {
                    head->next=new ListNode(l2->val);
                    head=head->next;
                }
                l2=l2->next;
            }
            
           
            
            
           
        }
        while(l1==NULL and l2!=NULL)
        {
                if(newList==NULL)
                {
                    head=new ListNode(l2->val);
                    newList=head;
                }
                else
                {
                    head->next=new ListNode(l2->val);
                    head=head->next;
                }
                l2=l2->next;
            
        }
        while(l1!=NULL and l2==NULL)
        {
                if(newList==NULL)
                {
                    head=new ListNode(l1->val);
                    newList=head;
                }
                else
                {
                    head->next=new ListNode(l1->val);
                    head=head->next;
                }
                l1=l1->next;
             
        }
        return newList;
    }
    
    void deleteList(ListNode*n)
    {
        ListNode *temp1=n,*temp2;
        while(n!=NULL)
        {
            temp1=n->next;
            free(n);
            n=temp1;
            
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int i,j,k=lists.size();
        ListNode *n1,*n2;
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        n1=merge1(lists[0],lists[1]);
        cout<<"thye output is \n";
        n2=n1;
        while(n2!=NULL)
        {
            cout<<n2->val<<" ";
            n2=n2->next;
        }
        for(i=2;i<k;i++)
        {
            n2=n1;
            n1=merge1(n1,lists[i]);
            deleteList(n2);
            
        }
        return n1;
        
    }

void printList(ListNode *n)
{
    ListNode *cur=n;
    while(cur!=NULL)
    {
        cout<<cur->val<<"  ";
        cur=cur->next;
    }
    cout<<"\n";
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    ListNode *l1=NULL,*l2=NULL,*l3=NULL,*l4=NULL,*head=NULL;
    int i,j;
    For(i,10,15)
    {
        if(l1==NULL)
        {
            head=new ListNode(i);
            l1=head;
            //cout<<"head->next is "<<head->next;
            //head=head->next;
        }
        else
        {
            head->next=new ListNode(i);
            head=head->next;
            //cout<<"head->next2 is "<<head;
        }
        //cout<<"\n";
    }
    cout<<"List 1 is ";printList(l1);
    For(i,5,9)
    {
        if(l2==NULL)
        {
            head=new ListNode(i);
            l2=head;
        }
        else
        {
            head->next=new ListNode(i);
            head=head->next;
        }
    }
    cout<<"List 2 is ";printList(l2);
    For(i,1,5)
    {
        if(l3==NULL)
        {
            head=new ListNode(i);
            l3=head;
        }
        else
        {
            head->next=new ListNode(i);
            head=head->next;
        }
    }    
    cout<<"List 3 is ";printList(l3);
    vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);
    return 0;
}

