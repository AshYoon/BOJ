#pragma once
#ifndef _TREE_LINK_H
#define _TREE_LINK_H

typedef int Element;


typedef struct Node {
	Element data;
	struct Node* left;
	struct Node* right;

} Node ;

Node* create(Element e);
void dispose(Node* root);
void print(const Node* root);

Node* insertLeft(Node* root, int value);
Node* insertRight(Node* root, int value);

void inOrder(const Node* root);
void preOrder(const Node* root);
void postorder(const Node* root);;
void levelOrder(const Node* root);

int noOfNodes(const Node* root);
int noOfLeafNodes(const Node* root);
int noOfInternalNodes(const Node* root);
int height(const Node* root);



Node* BST_recursiveSearch(Node* root, Element e);
Node* BST_iterativeSearch(Node* root, Element e);

Node* BST_recursiveInsert(Node* root, Element e);
Node* BST_recursiveDelete(Node* root, Element e);

Node* BST_findMin(Node* node);
Node* BST_findMax(Node* node);
int DegreeIsOne(Node* root);


#endif