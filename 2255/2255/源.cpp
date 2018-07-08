#include <iostream>

using namespace std;

class Node
{
public:
	char value[27];
	Node *left;
	Node *right;
	Node()
	{
		for (int i = 0; i < 27; ++i)
		{
			value[i] = NULL;
		}
		left = NULL;
		right = NULL;
	}
	~Node()
	{
		delete left;
		delete right;
		left = NULL;
		right = NULL;
	}
};

char a[27] = { NULL };
char b[27] = { NULL };

Node *root = new Node;
Node *re = new Node;
void preOrder(Node* r,char place) {
	if (!r) {
		return;
	}
	int t = 0;
	while (r->value[t] != NULL)
	{
		if (place == r->value[t])
		{
			re = r;
		}
		t++;
	}
	preOrder(r->left, place);
	preOrder(r->right, place);
}



Node* Divide(char place)
{
	if(place==NULL)
	{
		return NULL;
	}
	preOrder(root, place);
	
	int t = 0;
	while (re->value[t]!=place)
	{
		t++;
	}
	int length = 0;
	while (re->value[length] != NULL)
	{
		length++;
	}

	if(length==1)
	{
		return NULL;
	}

	Node *left = new Node;
	for (int i = 0; i < t; ++i)
	{
		left->value[i] = re->value[i];
	}

	Node *right = new Node;
	int r_p = 0;
	for (int i = t+1; i < length; ++i)
	{
		right->value[r_p] = re->value[i];
		r_p++;
	}
	re->left = left;
	re->right = right;

	for (int i = 0; i < length; ++i)
	{
		re->value[i]=NULL;
	}
	re->value[0] = place;
	return re;
}

char FindLeftChild(Node* father)
{	
	if(father->left==NULL)
	{
		return NULL;
	}
	int a_place = 0;
	while (a[a_place]!=father->value[0])
	{
		a_place++;
	}

	for (int i = a_place+1; a[i]!=NULL ; ++i)
	{
		int k = 0;
		while (father->left->value[k] != NULL)
		{
			if(father->left->value[k]==a[i])
			{
				return a[i];
			}
			k++;
		}
	}
	return NULL;	
}

char FindRightChild(Node* father)
{
	if (father->right == NULL)
	{
		return NULL;
	}
	int a_place = 0;
	while (a[a_place] != father->value[0])
	{
		a_place++;
	}
	for (int i = a_place; a[i] != NULL; ++i)
	{
		int k = 0;
		while (father->right->value[k] != NULL)
		{
			if (father->right->value[k] == a[i])
			{
				return a[i];
			}
			k++;
		}
	}
	return NULL;
}

void pre_order_d(Node* r) {
	if (!r) {
		return;
	}
	char left = FindLeftChild(r);
	Divide(left);
	pre_order_d(r->left);
	char right = FindRightChild(r);
	Divide(right);
	pre_order_d(r->right);
}

void postOrder(Node* root) {
	if (!root) {
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	if(root->value[0]!=NULL)
	{
		cout << root->value[0];
	}	
}

int main()
{
	
	while (cin>>a>>b)
	{
		int length = 0;
		while (b[length] != NULL)
		{
			root->value[length] = b[length];
			length++;
		}
		Divide(a[0]);		
		pre_order_d(root);
		postOrder(root);
		cout << endl;
		root->left = NULL;
		root->right = NULL;
		root->value[0] = NULL;
	}
	return 0;
}
