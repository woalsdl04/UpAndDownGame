#pragma once
#include "stdafx.h"

class Node //³ëµå
{
public:
	int key;
	Node* left;
	Node* right;

public:
	Node(int _key)
	{
		key = _key;
		left = nullptr;
		right = nullptr;
	}
};

void PrintPreorder(Node* root);
void PrintInorder(Node* root);
void PrintPostorder(Node* root);
Node* InsertNode(Node* root, int _key);
Node* SearchNode(Node* root, int _key);
Node* DeleteNode(Node* root, int _key);
Node* FindMinNodeValue(Node* root);
