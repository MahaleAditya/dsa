#include<iostream>
#include<cstring>
#define MAX 20
using namespace std;
struct node{
	char data;
	node *left,*right;
};
node *root;
class cStack{
	public:
		int top;
		node *stk[MAX];

		cStack()
		{
			top=-1;
                       

		}
		int isFull()
		{
			if(top==MAX-1)
				return 1;
			else
				return 0;
		}
		int isEmpty()
		{
			if(top==-1)
				return 1;
			else
				return 0;
		}
		void push(node *n)
		{
			
				top++;
				stk[top]=n;
			
		}
		node* pop()
		{
			node *t;
			
				t=stk[top];
				top--;
			
			return(t);
		}
};
class Tree{
	public:
	Tree()
	{
		root=NULL;

	}
	void exp();
	void post(node *);
	void postOrd(node *);
	void del(node *);
};
void Tree::exp()
{     
       string pre;
	cout<<"Enter Prefix Exp";
	cin>>pre;
   	int i;
	int len=pre.length();
	cStack s;

	for(i=len;i>=0;i--)
	{  	node *n;
		n=new node;
		n->left=NULL;
		n->right=NULL;
              cout<<endl<<pre[i];
		if(isalpha(pre[i]))
		{     
			n->data=pre[i];
			s.push(n);
		}
		else if(pre[i]=='+' || pre[i]=='-' || pre[i]=='*' || pre[i]=='/')
			{    
				node *t1,*t2;
				t1=s.pop();
				t2=s.pop();
				n->data=pre[i];
				n->left=t1;
				n->right=t2;
				s.push(n);
		
			}
		
	}
root=s.pop();
}
void Tree::post(node *t)
{
	cStack s1,s2;
	node *t1=t;
	s1.push(t1);
	while(!s1.isEmpty())
	{
		t1=s1.pop();
		s2.push(t1);
		if(t1->left!=NULL)
			s1.push(t1->left);
		if(t1->right!=NULL)
			s1.push(t1->right);
		
	}
	while(!s2.isEmpty())
		{
			node *a;
			a=s2.pop();
			cout<<a->data;
		}
}
/*void Tree::postOrd(node *t)
{ if(t!=NULL)
   {
	postOrd(t->left);
	postOrd(t->right);
	cout<<t->data;
    }
}*/
void Tree::del(node *t)
{
if(t!=NULL){
	del(t->left);
	del(t->right);
	cout<<t->data<<endl;
	delete(t);
    cout<<t->data;
}

}
int main()
{
	
	Tree t;
	t.exp();
	cout<<endl<<"postorder ";
	t.post(root);
	//t.postOrd(root);
	cout<<"Deleting Tree ";
	t.del(root);
}
