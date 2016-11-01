//SPOJ TREE ORDER
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long int ull;
#define blank putc_unlocked('\n',stdout);
#define ForIter( it,name) for(auto it=name.begin();it!=name.end();it++)
#define Forall(i,start,end) for(i=start;i<=end;i++)
#define For(i,start,end) for(i=start;i<end;i++)
vector<int> pre,post,in;
struct Node{
    int val;
    Node *left,*right;
    Node(int val) :val(val),left(NULL),right(NULL){}
};
Node *root=NULL;
unordered_map<int,int> positionOfInOrder;
int precounter=0;
Node *makeTreeFromPreAndInOrder(int start,int end1)
{
    if(start>end1 or precounter>=in.size()) return NULL;
    int i;
    
    Node *new1=new Node(pre[precounter]);
    int position=positionOfInOrder[pre[precounter]];
    precounter++;
    new1->left=makeTreeFromPreAndInOrder(start,position-1);
    new1->right=makeTreeFromPreAndInOrder(position+1,end1);
    return new1;
}

void printPre(Node *root)
{
    if(root==NULL) return;
    if(root!=NULL) cout<<root->val<<" ";
    printPre(root->left);
    printPre(root->right);
}
int postCounter=0;
void checkTreeValidity(Node*root)
{
    if(root==NULL) return;
    checkTreeValidity(root->left);
    checkTreeValidity(root->right);
    if(root->val!=post[postCounter])
    {
        cout<<"no\n";exit(0);
        
    }
    postCounter++;    
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n,i,x;
    cin>>n;
    For(i,0,n){
        cin>>x;
        pre.push_back(x);
    } 
    
    For(i,0,n){
        cin>>x;
        post.push_back(x);
    } 
    
    For(i,0,n){
        cin>>x;
        positionOfInOrder.insert(make_pair(x,i));
        in.push_back(x);
    } 
    Node*root=makeTreeFromPreAndInOrder(0,in.size()-1);
    checkTreeValidity(root);
    cout<<"yes"<<"\n";
    return 0;
}
