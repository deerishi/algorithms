#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout);
int getInt()  
{ 
	ch=getc_unlocked(stdin); 
	//cout<<" in the beginning with ch as "<<ch; 
	while(ch<'-'){/*cout<<" in while 1 with ch as "<<ch;*/ ch=getc_unlocked(stdin);} 
	int sign=1,n1=0; 
	if(ch=='-') sign=-1,ch=getc_unlocked(stdin); 
	while(ch>'-' ) 
	{ 
		//cout<<" in while 2 with ch as "<<ch; 
		n1=n1*10 +ch-'0'; 
		ch=getc_unlocked(stdin); 
	} 
	return n1*sign; 
}

void printn(int n) 
{
	char *ptr=temp+30;
	*ptr--='\0';
	int flag=1;
	if(n)
	{
		if(n<0) n*=-1,flag=-1;
			
		while(n>0)
		{
			*ptr--=(n%10) +'0';
			n/=10;
		}
		if(flag==-1) *ptr--='-';
		
	}
	else {*ptr='0';putc_unlocked('0',stdout);return;}
	ptr++;
	while(*ptr!='\0')
	{
		putc_unlocked(*ptr++,stdout);
	}
}

class node
{
	public:
	int data;
	node *left,*right;
	
		void add(int val);
		void traverse(node *root);
		void convert(node* root);
		void traverse2(node* root);
}*root=NULL;

void node::traverse2(node* root)
{
	queue<node*> q1;
	stack<node*> s1;
	q1.push(root);
	node* cur;
	int i=0;
	cout<<"\nin func cur is "<<root->data<<"\n";
	while(!q1.empty() or !s1.empty())
	{
		if(!q1.empty() and q1.front()!=NULL)
		{
			cur=q1.front();
			cout<<"\nin func2 cur is "<<cur->data<<" and i is "<<i<<"\n";
		}
		else if(!s1.empty() and s1.top()!=NULL)
		cur=s1.top();
		i++;
		while(cur!=NULL)
		{
			printn(cur->data);
			if(cur->right!=NULL) s1.push(cur->right);
			cur=cur->left;
			putc_unlocked(' ',stdout);
		}
		q1.pop();
		if(!s1.empty() and s1.top()!=NULL)
		{
			cur=s1.top();
			s1.pop();
			printn(cur->data);
			putc_unlocked(' ',stdout);
			if(cur->left!=NULL)
			{
				q1.push(cur->left);
			}
		}
	}
	
}	

void node::add(int val)
{
	queue<node*> q1;
	q1.push(root);
	node *cur;
	while(!q1.empty())
	{
		cur=q1.front();
		q1.pop();
		if(cur->left==NULL)
		{
			cout<<"adding left\n";
			cur->left= new node();
			cur->left->data=val;
			cur->left->left=NULL;
			cur->left->right=NULL;
			return;
		}
		else if(cur->right==NULL)
		{
			cout<<"adding right\n";
			cur->right=new node();
			cur->right->data=val;
			cur->right->left=NULL;
			cur->right->right=NULL;
			return;
		}
		else
		{
			q1.push(cur->left);
			q1.push(cur->right);
		}
	}
}
void node:: traverse(node *root)
{
	if(root==NULL) return;
	
	printn(root->data);
	putc_unlocked(' ',stdout);
	traverse(root->left);
	traverse(root->right);
}
void node:: convert(node *root)
{
	node *temp;
	if(root->left!=NULL and root->right!=NULL)
	{
		temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
	else if(root->left==NULL and root->right!=NULL)
	{
		root->left=root->right;
		root->right=NULL;
	}
	else if(root->left!=NULL and root->right==NULL)
	{
		root->right=root->left;
		root->left=NULL;
	}
	else
	{
		return;
	}
}
			
	
int main()
{
	int n;
	
	while(1)
	{
		n=getInt();
		if(n==-1) break;
		if(root==NULL)
		{
			root=new node();
			root->data=n;
			root->left=NULL;
			root->right=NULL;
		}
		else	
		root->add(n);
	}
	cout<<"\n now traversing\n";
	root->traverse(root);
	root->convert(root);
	//cout<<"\n the mirror image is \n";
	//root->traverse(root);
	cout<<"\n now the iterative preorder traversal is\n";
	cout<<"\n cur is "<<root->data<<"\n";
	root->traverse2(root);
	cout<<"\n"; 
	return 0;
}
		
	
