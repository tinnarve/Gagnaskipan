#ifndef BSTMAP_H
#define BSTMAP_H
#include "map.h"
#include "BinaryTreeNode.h"

template <class K, class T>
class BSTMap
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

        }

        virtual bool contains(K key) {

        }

        virtual int size() const {

        }

        virtual bool empty() const {

        }

        virtual void clear() {

        }

        virtual void print(ostream& out) const {

        }

    private:
        BinaryTreeNode *root;
};

#endif // BSTMAP_H
