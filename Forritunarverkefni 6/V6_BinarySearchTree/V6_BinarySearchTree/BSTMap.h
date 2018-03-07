#ifndef BSTMAP_H
#define BSTMAP_H
#include <iostream>
#include "map.h"
#include "BinaryTreeNode.h"

using namespace std;

template <class K, class T>
class BSTMap : public Map<K, T>
{
    public:
        BSTMap() {
            root = NULL;
            numItems = 0;
        }
        virtual ~BSTMap() {
            clear();
        }
        virtual void insert(K key, T data) {
            BinaryTreeNode<K,T>* &node = find(key, root);
            if(node == NULL)
            {
                node = new BinaryTreeNode<K,T>(key, data);
            }
            else{
            BinaryTreeNode<K,T>* node = new BinaryTreeNode<K,T>(key, data, NULL, NULL);
            numItems++;
            }
        }

        virtual void update(K key, T data) {

        }

        virtual T get(K key) {

        }

        virtual void remove(K key) {
            BinaryTreeNode<K, T>* node = find(key, root);
            if(node != NULL) {
                remove(node->left);
                remove(node->right);
                delete node;
            }
        }

        void nodeRemove(BinaryTreeNode<K, T>* &node) {
            if(node->left == NULL && node->right == NULL) {
                delete node;
                node = null;
            }
            else if(node->right == NULL) {
                BinaryTreeNode<K, T>* tmp = node;
                node = node->left;
                delete tmp;
            }
            else if(node->left == NULL) {
                BinaryTreeNode<K, T>* tmp = node;
                node = node->right;
                delete tmp;
            }
            else {
               BinaryTreeNode* &nodeForDeletion = findRightMostNode(node->left);
               node->data = nodeForDeletion->data;
               removeNode(nodeForDeletion);
            }
        }

        findRightMostNode(BinaryTreeNode* &node) {

        }

        virtual bool contains(K key) {

        }

        BinaryTreeNode<K, T>* &find(K key, BinaryTreeNode<K,T>* &node)
        {
            if(node == NULL){
                return node;
            }
            if(key < node->key)
            {
                return find(key, node->left);
            }
            else if(node->key < key){
                return find(key, node->right);
            }
            return node;
        }

        virtual int size() const {
            return numItems;
        }

        virtual bool empty() const {

        }

        virtual void clear() {
            remove(root);
            root = NULL;
        }

        virtual void print(ostream& out) const {
            print(root);
        }

    private:
        BinaryTreeNode<K, T> *root;
        int numItems;

        void print(BinaryTreeNode<K,T>* node) const {
            if(node != NULL) {
                print(node->left);
                cout << node->data << " ";
                print(node->right);
            }
        }
};

#endif // BSTMAP_H
