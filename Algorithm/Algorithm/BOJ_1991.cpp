/*
백준 1991번 트리 순회
20/03/19
*/
#include <iostream>

using namespace std;

typedef struct TreeNode
{
	char data;
	TreeNode *left, *right;
}TreeNode;

TreeNode* newNode(char);
void insertChild(TreeNode*, char, char, char);
void preorder(TreeNode*);
void inorder(TreeNode*);
void postorder(TreeNode*);

int main(void) 
{
	int n;
	scanf("%d", &n);
	
	TreeNode* root = new TreeNode;
	char rt, rl, rr;
	root->data = 'A';
	root->left = root->right = NULL;

	for (int i = 0; i < n; ++i)
	{
		scanf(" %c %c %c", &rt, &rl, &rr);
		insertChild(root, rt, rl, rr); 
	}

	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	
	delete root;

	return 0;
}

TreeNode* newNode(char id)
{
	if (id == '.') return NULL;

	TreeNode *node = new TreeNode;
	node->data = id;
	node->left = node->right = NULL;
	return node;
}

void insertChild(TreeNode* root, char key, char left, char right)
{
	if (root == NULL) return;
	if (root->data == key)
	{
		root->left = newNode(left);
		root->right = newNode(right);
	}
	else
	{
		insertChild(root->left, key, left, right);
		insertChild(root->right, key, left, right);
	}
}

void preorder(TreeNode* root)
{
	if (root)
	{
		printf("%c", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(TreeNode* root)
{
	if (root)
	{
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}

void postorder(TreeNode* root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%c", root->data);
	}
}
