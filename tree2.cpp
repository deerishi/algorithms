#include "bits/stdc++.h"
using namespace std;
char temp[1<<10],ch;
#define blank putc_unlocked('\n',stdout);
#define pre 1
#define in 2
#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
 
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
int precounter=0;
char preorder[100],inorder[100];
class node
{
	public:
		char data;
		node *left,*right;
		node* add(node* root,char val);
		void traverse(node *root,int order);
		node* create(node *root,int start,int end);
}*root=NULL;;
node* node:: create(node *root,int start,int end)
{	
	if(start>end) return NULL;
	//cout<<"start= "<<start<<" and end= "<<end<<"\n";
	if(root==NULL)
	{
		root=new node();
		root->data=preorder[precounter];
		root->left=NULL;
		root->right=NULL;
		cout<<" now adding "<<root->data<<"\n";
	}
	int pos;
	for(int i=start;i<=end;i++)
	{
		if(preorder[precounter]==inorder[i])
		{
			pos=i;
			break;
		}
	}
	precounter++;
	root->left=create(root->left,start,pos-1);
	root->right=create(root->right,pos+1,end);
	return root;
}
void node:: traverse(node *root,int order)
{

	if(order==pre)
	{
		if(root==NULL) return ;
		
		cout<<root->data<<" ";
		traverse(root->left,order);
		traverse(root->right,order);
	}
	else
	{
		if(root==NULL) return;
		traverse(root->left,order);
		cout<<root->data<<" ";
		traverse(root->right,order);
	}
}			
node* node:: add(node*root,char ch)
{
	if(root==NULL)
	{
		root=new node();
		root->data=ch;
		root->left=NULL;
		root->right=NULL;
		cout<<"\n now entering "<<root->data<<"\n";
	}
	else if(root->data>ch)
	root->left=add(root->left,ch);
	else
	root->right=add(root->right,ch);
	return root;
}
int main()
{
	int n,pos;

	n=getInt();
	char s[100];
	cout<<"\n enter preorder \n";
	scanf("%s",s);
	for(int i=0;i<n;i++)
	preorder[i]=s[i];
	cout<<"\n enter inorder\n";
	scanf("%s",s);
	for(int i=0;i<n;i++)
	inorder[i]=s[i];
	/*if(root==NULL and n>0)
	{
		root=new node();
		root->data=preorder[precounter++];
		root->left=NULL;
		root->right=NULL;
		for(int i=0;i<n;i++)
		{
			if(inorder[i]==preorder[precounter-1])
			{
				pos=i;
				break;
			}
		}
	}
	root->left=root->create(root->left,0,pos-1);
	root->right=root->create(root->right,pos+1,n-1);		*/
	root=root->create(root,0,n-1);
	cout<<"\n the preoder traversal is \n";
	//cout<<"\n root is "<<root->data<<"\n"; 
	root->traverse(root,pre);
	cout<<"\n the inoder traversal is \n";
	root->traverse(root,in);
	
	cout<<"\n now enter a binary search tree\n";
	node *root2=NULL;
	ch='a';
	n=1;
	while(1)
	{
		n=getInt();
		ch=n+'0';
		if(n==0) break;
		root2=root2->add(root2,ch);
	}
	cout<<"\n now the traversal is\n";
	root2->traverse(root2,pre);
	return 0;
}
	
	
	
