#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(int value)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;	  
}
//Inorder Traversal (Left ? Root ? Right)
void Inorder(struct Node* root)
{
	if(root != NULL)
	{
		Inorder(root->left);
		printf("%d ", root->data);
		Inorder(root->right);
    }
}

//Preorder Traversal (Root ? Left ? Right)
void Preorder(struct Node* root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		Preorder(root->left);
		Preorder(root->right);
	}
}

//Postorder Tranversal (Left ? Right ? Root)
void Postorder(struct Node* root)
{
	if(root != NULL)
	{
		Postorder(root->left);
		Postorder(root->right);
		printf("%d ", root->data);
	}
}

int main()
{
	struct Node* root = createNode(4);
	root->left = createNode(2);
	root->right = createNode(6);
	root->left->left = createNode(1);
	root->left->right = createNode(3);
	root->right->left = createNode(5);
	root->right->right = createNode(7);
	
	printf("Inorder Tranversal: ");
	Inorder(root);
	printf("\n");
	
	printf("Preorder Tranversal: ");
	Preorder(root);
	printf("\n");
	
	printf("Postorder Tranversal: ");
	Postorder(root);
	printf("\n");
	
	return 0;
}

