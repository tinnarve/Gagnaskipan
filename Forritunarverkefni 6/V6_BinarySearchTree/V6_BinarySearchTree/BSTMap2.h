#ifndef BSTMAP2_H
#define BSTMAP2_H
#include "map.h"
#include "BinaryTreeNode.h"

template <class K, class T>
class BSTMap2 : public Map<K, T>
{
    public:
        BSTMap2() {
            //make an empty root Node
            root = NULL;
            numItems = 0;
        }

        virtual ~BSTMap2() {
            clear();
        }

        virtual void insert(K key, T data)
        {
            BinaryTreeNode<K,T>* &node = find(key, root);
            if(node == NULL)
            {
                node = new BinaryTreeNode<K,T>(key, data);
                numItems++;
            }
            else{
                throw ItemExistsException();
            }

        }

        virtual void update(K key, T data) {
            BinaryTreeNode<K,T>* &node = find(key, root);
            if(node == NULL){
                throw NotFoundException();
            }
            node->data = data;
        }

        virtual T get(K key) {
            BinaryTreeNode<K,T>* node = find(key, root);
            if(node == NULL)
            {
                throw NotFoundException();
            }
            return node->data;
        }

        virtual void remove(K key) {
           BinaryTreeNode<K, T>* &node = find(key, root);
            /*if(node != NULL) {
                //remove(node->left);
                //remove(node->right);
                delete node;
            }*/
            if(node == NULL) {
                    throw NotFoundException();
            }
            nodeRemove(node);
            numItems--;
        }

        void nodeRemove(BinaryTreeNode<K, T>* &node) {
            if(node->left == NULL && node->right == NULL) {
                delete node;
                node = NULL;
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
               BinaryTreeNode<K,T>* &nodeForDeletion = findRightMostNode(node->left);
               node->key = nodeForDeletion->key;
               node->data = nodeForDeletion->data;
               nodeRemove(nodeForDeletion);
            }
        }

        BinaryTreeNode<K, T>* &findRightMostNode(BinaryTreeNode<K, T>* &node) {
            if (node->right == NULL) {
                return node;
            }
            return findRightMostNode(node->right);
        }

        virtual bool contains(K key)
        {
            BinaryTreeNode<K, T> * node = find(key, root);
            if(node != NULL) {
                return true;
            }
            else{
                return false;
                numItems++;
            }
            //return find(k, root) != NULL;
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
            if(root == NULL)
            {
                return true;
            }
            return false;
        }

        virtual void clear() {
            if(root != NULL)
            {
                cleanTree(root);
                root = NULL;
                numItems = 0;
            }
        }

        void cleanTree(BinaryTreeNode<K,T> *root)
        {
            if(root->left != NULL)
            {
                cleanTree(root->left);
            }
            if(root->right!=NULL)
            {
                cleanTree(root->right);
            }
            delete root;
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

#endif // BSTMAP2_H
