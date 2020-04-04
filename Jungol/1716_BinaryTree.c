#include <stdio.h>
#include <malloc.h>

int arr[21];
int n;
typedef struct _tree Tree;
typedef struct _node Node;
struct _tree {
	Node* root;
};
struct _node {
	int data;
	Node* parent;
	Node* left;
	Node* right;
};
void init(Tree* tree);
Node* Left(Node* node);
Node* Right(Node* node);
void postorder(Node* node);

int main() {
	freopen("in.txt", "r", stdin);
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	init(tree);
	postorder(tree->root);
	return 0;
}

void postorder(Node* node) {
	if (node->left != NULL) postorder(node->left);
	if (node->right != NULL) postorder(node->right);
	printf("%d ", node->data);
	return;
}

void init(Tree* tree) {
	for (int i = 0; i < 21; i++) {
		scanf("%d", &arr[i]);
	}
	tree->root = (Node*)malloc(sizeof(Node));
	tree->root->parent = NULL;
	tree->root->data = arr[n++];
	if (arr[n] != -1) tree->root->left = Left(tree->root);
	else {
		tree->root->left = NULL;
		n++;
	}
	if (arr[n] != -1) tree->root->right = Right(tree->root);
	else {
		tree->root->right = NULL;
		n++;
	}
	return;
}
Node* Left(Node* node) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = arr[n++];
	newNode->parent = node;
	newNode->parent->left = newNode;
	if (arr[n] != -1) Left(newNode);
	else {
		newNode->left = NULL;
		n++;
	}
	if (arr[n] != -1) Right(newNode);
	else {
		newNode->right = NULL;
		n++;
	}
	return newNode;
}
Node* Right(Node* node) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = arr[n++];
	newNode->parent = node;
	newNode->parent->right = newNode;
	if (arr[n] != -1) Left(newNode);
	else {
		newNode->left = NULL;
		n++;
	}
	if (arr[n] != -1) Right(newNode);
	else {
		newNode->right = NULL;
		n++;
	}
	return newNode;
}
