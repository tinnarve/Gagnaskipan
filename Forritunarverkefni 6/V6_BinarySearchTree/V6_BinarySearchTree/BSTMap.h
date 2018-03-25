#ifndef BSTMAP_H
#define BSTMAP_H
#include "map.h"
#include "BinaryTreeNode.h"

template <class K, class T>
class BSTMap : public Map<K, T>
{
    public:
        BSTMap() {
            //make an empty root Node
            root = NULL;
            numItems = 0;
        }

        virtual ~BSTMap() {
            //lets use an already made function
            clear();
        }

        virtual void insert(K key, T data)
        {
            /*Check if there is a node that matches the key already
             find returns a NULL node at the correct place if there
             is no node with the same key*/
            BinaryTreeNode<K, T>* &node = find(key, root);
            if(node == NULL)
            {
                //add new node and increase number of items.
                node = new BinaryTreeNode<K, T>(key, data);
                numItems++;
            }
            //if there is already a node with the same key return
            // exception
            else{
                throw ItemExistsException();
            }

        }

        virtual void update(K key, T data) {
            //find the note and return exception if it is empty
            //else change data.
            BinaryTreeNode<K, T>* &node = find(key, root);
            if(node == NULL){
                throw NotFoundException();
            }
            node->data = data;
        }

        virtual T get(K key) {
            //find the note and return exception if it is empty
            //else return the data.
            BinaryTreeNode<K, T>* node = find(key, root);
            if(node == NULL)
            {
                throw NotFoundException();
            }
            return node->data;
        }

        virtual void remove(K key) {
            // find the note and return exception if it is empty
            // else use another function to remove the note and
            // then reduce number of items
            BinaryTreeNode<K, T>* &node = find(key, root);
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
               BinaryTreeNode<K, T>* &nodeForDeletion = findRightMostNode(node->left);
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
            //check if there is a node with the given key. if the node is empty
            //return false, else return true.
            BinaryTreeNode<K, T> * node = find(key, root);
            if(node != NULL) {
                return true;
            }
            else{
                return false;
            }
        }
        BinaryTreeNode<K, T>* &find(K key, BinaryTreeNode<K, T>* &node)
        {
            // return a NULL node in the right place if the whole
            // tree has been checked and it has not been found.
            if(node == NULL){
                return node;
            }
            // check the left node if the key is lower than the
            // node being node.
            if(key < node->key)
            {
                return find(key, node->left);
            }
            // send the right node to be checked if the key is higher
            // than the node being checked.
            else if(node->key < key){
                return find(key, node->right);
            }// else return the node as it has been found.
            return node;
        }

        virtual int size() const {
            return numItems;
        }

        virtual bool empty() const {
            //return true if the root node is empty
            if(root == NULL)
            {
                return true;
            }
            return false;
        }

        virtual void clear() {
            // use a separate function to delete the tree if it
            // is not empty. Then NULL the root and item count.
            if(root != NULL)
            {
                cleanTree(root);
                root = NULL;
                numItems = 0;
            }
        }

        void cleanTree(BinaryTreeNode<K, T> *root)
        {
            // use recursion to find all the nodes and then
            // delete them on the way back
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

        void print(BinaryTreeNode<K, T>* node) const {
            if(node != NULL) {
                print(node->left);
                cout << node->data << " ";
                print(node->right);
            }
        }
};

#endif // BSTMAP2_H
