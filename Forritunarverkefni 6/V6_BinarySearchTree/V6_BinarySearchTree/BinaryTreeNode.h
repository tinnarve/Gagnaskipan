#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
#include <stdio.h>

template <class K, class T>
class BinaryTreeNode
{
    public:
        BinaryTreeNode(K key, T data, BinaryTreeNode *left = NULL, BinaryTreeNode *right = NULL)
                      : key(key), data(data), left(left), right(right) {};
        virtual ~BinaryTreeNode() {};

        K key;
        T data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;
};

#endif // BINARYTREENODE_H
