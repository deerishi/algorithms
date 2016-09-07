#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout);


struct ListNode {
       int val;
       ListNode  *next;
       ListNode(int x) : val(x), next(NULL) {}
   };
  
struct TreeNode {
   int val;
   TreeNode  *left;
   TreeNode  *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

pair<ListNode*,ListNode*> getMiddle(ListNode* head)
{
        ListNode* cur=head,*curnext=head->next,*temp=head;
        if(cur->next==NULL)
        {
            return make_pair(head,head);
        }
        while(curnext!=NULL)
        {
            temp=cur;
            cur=cur->next;
            //cout<<"cur is "<<(cur->val)<<"\n";
            if(curnext->next!=NULL)
                curnext=curnext->next->next;
            else curnext=curnext->next;
        }
        //cout<<"returning\n";
        return make_pair(temp,cur);
    }
    

TreeNode* sortedListToBST(ListNode* head) 
 {
        if(head==NULL)
        {
            //cout<"returning caz head is NULL\n";
            return NULL;
        }
        pair<ListNode*,ListNode*> p=getMiddle(head);
        ListNode *middle=p.second;
        //cout<<"head is "<<(head->val)<<"\n";
        //cout<<"Middle is "<<(middle->val)<<"\n";
        ListNode *prev=p.first;
        TreeNode *root=new TreeNode(middle->val);
        prev->next=NULL;
        if(middle==prev)
        {
            head=NULL;
            middle->next=NULL;
        }
        TreeNode *left1=sortedListToBST( head) ;
        TreeNode *right1=sortedListToBST(middle->next); 
        if(left1!=NULL)
        {
            //root->left=(TreeNode*)malloc(sizeof(TreeNode));
           
                root->left=left1;
            
        }
        if(right1!=NULL)
        {
            //root->right=(TreeNode*)malloc(sizeof(TreeNode));
           
                root->right=right1;
            
        }
        //cout<<"root is "<<root->val<<"\n";
        return root;
}
void inorder(TreeNode *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<(root->val)<<" ";
    inorder(root->right);
}
int main()
{
    ListNode *head=NULL,*temp1=NULL,*temp2=NULL,*temp3;
    //head=(ListNode *)malloc(sizeof(ListNode));
    head=new ListNode(1);
    temp1=head;
    //cout<<"head is "<<(head->val)<<"\n";
    for(int i=2;i<=6;i++)
    {
        temp3=new ListNode(i);
        //cout<<"temp3 is "<<(temp3->val)<<" and "<<temp3<<"\n";
        temp1->next=temp3;
        //cout<<"head next is "<<(head->next)<<"\n";
        temp1=temp1->next;
    }
    
    cout<<"priniting the list\n";
    temp2=head;
    while(temp2!=NULL)
    {
        cout<<(temp2->val)<<" ";
        temp2=temp2->next;
    }
    cout<<"\nnow calling create tree\n";
    TreeNode* root=sortedListToBST(head);
    cout<<"root is "<<(root->val)<<"\n and inorder is \n";inorder(root);cout<<"\n";
    cout<<"now deleting the linked list\n";
    temp2=head;
    while(temp2!=NULL)
    {
        //cout<<(temp2->val)<<" ";
        temp3=temp2;
        
        temp2=temp2->next;
        delete temp3;
    }
    return 0;
}
