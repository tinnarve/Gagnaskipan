#ifndef BSTMAP2_H
#define BSTMAP2_H
#include "map.h"
#include "BinaryTreeNode.h"

template <class K, class T>
class BSTMap2 : public Map<K, T>
{
    public:
        BSTMap2() {
            root = NULL;
            numItems = 0;
        }

        virtual ~BSTMap2() {

        }

        virtual void insert(K key, T data)
        {
            BinaryTreeNode<K,T>* node = find(key, root);
            if(node->key != NULL)
            {
                throw ItemExistsException();
            }
            else if(node == NULL){
                node = new BinaryTreeNode<K,T>(key, data);
            }

        }

        virtual void update(K key, T data) {

        }

        virtual T get(K key) {
            return false;
        }

        virtual void remove(K key) {

        }

        virtual bool contains(K key)
        {
            BinaryTreeNode<K, T> * node = find(key, root);
            if(node != NULL) {
                return true;
            }
            else{
                return false;
            }
            //return find(k, root) != NULL;
        }
        BinaryTreeNode<K, T>* find(K key, BinaryTreeNode<K,T>* &node)
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
            return false;
        }

        virtual void clear() {

        }

        virtual void print(ostream& out) const {

        }

    private:
        BinaryTreeNode<K, T> *root;
        int numItems;
};

#endif // BSTMAP2_H
