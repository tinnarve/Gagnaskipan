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
        }

        virtual ~BSTMap2() {

        }

        virtual void insert(K key, T data)
        {
            BinaryTreeNode* node = find(key, root);
            if(node->data != NULL)
            {
                throw ItemExistsException();
            }
            else if(node == NULL){
                node = new BinaryTreeNode(key);
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
            BinaryTreeNode* node = find(key, root);
            if(node != NULL) {
                return true;
            }
            else{
                return false;
            }
            //return find(k, root) != NULL;
        }
        BinaryTreeNode* find(K key, BinaryTreeNode* &node)
        {
            if(node == NULL){
                return node;
            }
            if(key < node->data)
            {
                return find(key, node->left);
            }
            else if(node->data < key){
                return find(key, node->right);
            }
            return node;
        }

        virtual int size() const {
            return 0;
        }

        virtual bool empty() const {
            return false;
        }

        virtual void clear() {

        }

        virtual void print(ostream& out) const {

        }

    private:
        BinaryTreeNode *root;
};

#endif // BSTMAP2_H
