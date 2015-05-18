/**********************************************
* File: node.cpp                              *
* Author: Aida Nordman                        *
* Course: TND004, Lab 3                       *
* Date: VT2, 2014                             *
* Description: class Node                     *
***********************************************/

#include "node.h"

#ifndef DOXYGEN_SHOULD_SKIP_THIS


Node::Node(ELEMENT v, Node *l, Node *r)
 : value(v), left(l), right(r)
{
    l_thread = r_thread = false;
}


//Destructor
//recursively deletes the nodes in the left_subtree and right-subtree
Node::~Node()
{
    //ADD CODE
}


//Insert v in the tree having as root this node
//Return true, if v was inserted
//Otherwise, return false --v already exists in the tree
bool Node::insert(ELEMENT v)
{
    if(value.first > v.first)
    {
        if(l_thread)
        {
            left = new Node(v);
            l_thread = false;
			left->l_thread = left->r_thread = true;

            return true;
        }
        else
            return left->insert(v);
    }
    else if(value.first < v.first)
    {
        if(r_thread)
        {
            right = new Node(v);
            r_thread = false;
			right->l_thread = right->r_thread = true;
            return true;
        }
        else
            return right->insert(v);
    }
    else if(value.first == v.first)
        return false;
}



//Remove the key from the tree having as root this node
//Return true, if a node storing key was found and deleted
//Otherwise, return false -- there is no node storing key
//isRight==false: this node is left child of parent
//isRight==true: this node is right child of parent
bool Node::remove(string key, Node* parent, bool isRight)
{
    //ADD CODE
    return false;
}



//Remove this node -- this node has at most one child
//isRight==false: this node is left child of parent
//isRight==true: this node is right child of parent
//Remove has 6 cases
//1a: a left child with only a right child
//1b: a left child with only a left child
//1c: a left child with no children
//2a: a right child with only a right child
//2b: a right child with only a left child
//2c: a right child with no children
void Node::removeMe(Node* parent, bool isRight)
{
   //ADD CODE
}



//Return a pointer to the Node storing key
//key is possibly stored in one of the sub-trees of this node
//If there is no node storing key then return nullptr
Node* Node::find(string key)
{
    if(value.first > key && !l_thread)
        return left->find(key);
    else if(value.first < key && !r_thread)
        return right->find(key);
	else if (value.first == key)
		return this;
	else
		return nullptr;
}


//Return a pointer to the node storing the smalest value
//of the tree whose root is this node
Node* Node::findMin()
{
    if(l_thread)
       return this;
    return left->findMin();
}


//Return a pointer to the node storing the largest value
//of the tree whose root is this node
Node* Node::findMax()
{
    if(r_thread)
       return this;
    return right->findMax();
}



//Display in inorder all keys
//stored in the tree whose root is this node
//recursive function
//Used for debugging -- ONLY
void Node::display() const
{
    if ( !l_thread ) //display left sub-tree
        left->display();

    cout << value.first << " "; //display key stored in the node

    if ( !r_thread ) //display right sub-tree
        right->display();
}


#endif /* DOXYGEN_SHOULD_SKIP_THIS */
