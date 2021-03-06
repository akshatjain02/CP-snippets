#include <bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define lol         1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define SIZE		1000005
using namespace std;


void MOD(ll &x)
{
	if (x >= lol) x -= lol;
	if (x < 0) x += lol;
}


typedef struct node
{
	ll val;
	struct node* left;
	struct node* right;
} node;


node* newNode(int value)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->val = value;
	temp->left = temp->right = NULL;
	return temp;
}


node* insert(node* root, int value)
{
	if(root==NULL)
		return newNode(value);

	if(value <= (root->val))
		root->left = insert(root->left, value);
	else
		root->right = insert(root->right, value);

	return root;	//returns pointer to the inserted node
}



//Traversals



void preorder(node* root)
{
	if(root)
	{
		cout<<root->val<<endl;
		preorder(root->left);
		preorder(root->right);
	}
}



void postorder(node* root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->val<<endl;
	}
}



void inorder(node* root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->val<<endl;
		inorder(root->right);	
	}

}



void solve()
{
	
	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}