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
        }
        virtual ~BSTMap() {
            clear();
        }
        virtual void insert(K key, T data) {

        }

        virtual void update(K key, T data) {

        }

        virtual T get(K key) {

        }

        virtual void remove(K key) {
            BinaryTreeNode<K, T> *node;
            key->node;
            if(node != NULL) {
                remove(node->left);
                remove(node->right);
                delete node;
            }
        }

        virtual bool contains(K key) {

        }

        virtual int size() const {

        }

        virtual bool empty() const {

        }

        virtual void clear() {
            remove(root);
            root = NULL;
        }

        virtual void print(ostream& out) const {

        }

    private:
        BinaryTreeNode<K, T> *root;
};

#endif // BSTMAP_H
