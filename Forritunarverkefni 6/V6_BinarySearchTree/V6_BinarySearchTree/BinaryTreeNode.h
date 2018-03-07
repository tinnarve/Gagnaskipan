#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
#include <stdio.h>

class BinaryTreeNode
{
    public:
        BinaryTreeNode(char data = '0', BinaryTreeNode *left = NULL, BinaryTreeNode *right = NULL)
                      : data(data), left(left), right(right) {};
        virtual ~BinaryTreeNode() {};

        char data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;
};

#endif // BINARYTREENODE_H
