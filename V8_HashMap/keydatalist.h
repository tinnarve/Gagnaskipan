#ifndef KEYDATALIST_H
#define KEYDATALIST_H

#include "keydatalistnode.h"
#include "map.h"

template <class K, class T>
class KeyDataList
{
    public:
        KeyDataList(int keys) {
            key = keys;
            first = NULL;
            last = NULL;
            node = first;
        }
        virtual ~KeyDataList() {
            //clear();
        }

        int getKey(){
            return key;
        }

        bool add(K key, T data)
        {
            ///Add the data data with the key key .
            ///If there is already an item with the key key in the map,
            ///return false
            node = find(key);
            if(node == NULL)
            {
                KeyDataListNode<K, T> *newNode = new KeyDataListNode<K, T>(key, data);
                if(first == NULL)
                {
                    first = newNode;
                    last = newNode;
                }
                else
                {
                    last->next = newNode;
                    last = newNode;
                }

                return true;
            }
            else
            {
                return false;
            }
        }

        bool update(K key, T data)
        {
            ///Updates the data connected to the key key so they are now data .
            ///If no item with the key key is found in the map, throw NotFoundException .
            node = find(key);

            if(key == node->key)
            {
                node->data = data;
                return true;
            }

            else{
                return false;
            }
        }

        KeyDataListNode<K, T>* find(K key)
        {
            node = first;
            if(last == first)
            {
                return first;
            }

            while(node->next != NULL)
            {
                if(node->key == key)
                {
                    return node;
                }
                node = node->next;
            }

            node = NULL;
            return node;
        }

        void remove(K key)
        {
            ///Removes the key key and its connected data from the data structure.
            ///If no item with the key key is found in the map, throw NotFoundException.
            node = first;
            while((node->next->key != key) || (node->next == NULL))
            {
                node = node->next ;
            }

            if(node->next->key == key)
            {
                KeyDataListNode<K, T> *temp = node->next->next;
                delete node->next;
                node->next = temp;
                return true;
            }
            else{
                return false;
            }
        }

        bool contains(K key)
        {
            ///Returns true the map contains the key key and connected data, otherwise false .
            node = find(key);
            if(node == NULL)
            {
                return false;
            }
            return true;
        }

        void clear()
        {
            ///Empties the data structure.
            node = first;
            KeyDataListNode<K, T> *temp;

            while(node->next != NULL)
            {
                temp = node->next->next;
                delete node->next;
                node->next = temp;
                node = temp;
            }

        }

        /*
        ● bool pop(K &key, T &data)
Puts key and data into these reference variables, then removes the item and returns
true. Returns false if list is empty..
*/
        void print(ostream& out)
        {
            if(node == NULL){
                cout << "nothing to see here" << endl;
            }
            node = first;
            while(node != NULL)
            {
                out << node->data;
                node = node->next;
            }

        }
    protected:

    private:
        KeyDataListNode<K, T> *first;
        KeyDataListNode<K, T> *last;

        KeyDataListNode<K, T> *node;
        int key;
};

#endif // KEYDATALIST_H
