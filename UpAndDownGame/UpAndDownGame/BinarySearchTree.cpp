#include "BinarySearchTree.h"

void PrintPreorder(Node* root) //깊이 우선 순회
{
	if (root == nullptr) return;

	cout << root->key << " ";

	PrintPreorder(root->left);

	PrintPreorder(root->right);
}

void PrintInorder(Node* root) // 중위 트리 순회 (오름차순)
{
	if (root == nullptr) return;

	PrintInorder(root->left);

	cout << root->key << " ";

	PrintInorder(root->right);
}

void PrintPostorder(Node* root) // 후위 트리 순회
{
	if (root == nullptr) return;

	PrintPostorder(root->left);

	PrintPostorder(root->right);

	cout << root->key << " ";
}

Node* InsertNode(Node* root, int _key) //노드 추가
{
	if (root == nullptr || root->key == _key)
	{
		Node* newNode = new Node(_key);
		//cout << "Insert Node Key is : " << newNode->key << endl;
		return newNode;
	}

	if (root->key > _key)
	{
		root->left = InsertNode(root->left, _key);
	}
	else if (root->key < _key)
	{
		root->right = InsertNode(root->right, _key);
	}

	return root;
}

Node* SearchNode(Node* root, int _key) //노드 검색
{
	if (root == nullptr || root->key == _key)
	{
		return root;
	}

	if (root->key > _key)
	{
		return SearchNode(root->left, _key);
	}

	return SearchNode(root->right, _key);
}

Node* DeleteNode(Node* root, int key) //노드 삭제
{
	if (root == NULL)
		return root;

	if (root->key > key)
	{
		root->left = DeleteNode(root->left, key);
	}
	else if (root->key < key)
	{
		root->right = DeleteNode(root->right, key);
	}
	else
	{
		Node* swapNode = nullptr;

		if (root->left == nullptr) {
			swapNode = root->right;
			free(root);
			return swapNode;
		}
		else if (root->right == nullptr) {
			swapNode = root->left;
			free(root);
			return swapNode;
		}

		swapNode = FindMinNodeValue(root->right);

		cout << "Swap Node Key is : " << root->key << " ==> " << swapNode->key << endl;

		root->key = swapNode->key;

		root->right = DeleteNode(root->right, swapNode->key);
	}

	return root;
}

Node* FindMinNodeValue(Node* root) //find successor 
{
	Node* node = root;

	while (node != nullptr && node->left != nullptr)
	{
		node = node->left;
	}

	return node;
}