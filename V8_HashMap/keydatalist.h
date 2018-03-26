#ifndef KEYDATALIST_H
#define KEYDATALIST_H

using namespace std;

#include "map.h"
#include "keydatalistnode.h"

template <class K, class T>
class KeyDataList : public Map<K, T>
{
    public:
        KeyDataList() {
            first = last;
            numItems = 0;
        }
        virtual ~KeyDataList() {
            clear();
        }

        void insert(K key, T data)
        {
            ///Add the data data with the key key .
            ///If there is already an item with the key key in the map,
            ///throw ItemExistsException .
            if(first == NULL)
            {
                first->next = new KeyDataListNode<K, T>(key, data, NULL);
                first = last;
            }
            else
            {
                KeyDataListNode<K, T> *newNode = new KeyDataListNode<K, T>(key, data, NULL);
                last->next = newNode;
                last = newNode;
            }
            numItem++;
        }

        void update(K key, T data)
        {
            ///Updates the data connected to the key key so they are now data .
            ///If no item with the key key is found in the map, throw NotFoundException .
            curr = find(key);

            if(key = node->key)
            {
                node.data = data;
            }

            else{
                throw NotFoundException();
            }
        }

        T get(K key)
        {
            ///Returns the data connected to the key key .
            ///If no item with the key key is found in the map, throw NotFoundException
            node = find(key);

            if(key = node->key)
            {
                return node.data;
            }

            else{
                throw NotFoundException();
            }
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
                numItems--;
            }
            else{
                throw NotFoundException();
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

        int size() const{
            //Returns the number of items currently in the map
            return numItems;
        }

        bool empty() const
        {//if list is empty return true, else false.
            if(numItems == 0){
                return true;
            }
            else{
                return false;
            }
        }

        void clear()
        {
            ///Empties the data structure.
            node = first;
            KeyDataListNode<K, T> *temp;

            while((node->next != NULL)
            {
                temp = node->next->next;
                delete node->next;
                node->next = temp;
                node = temp;
            }

        }

        void print(ostream& out)
        {
            node = first
            while(node->next != NULL)
            {
                cout << node << endl;
                node = node->next;
            }
        }

        KeyDataListNode<K, T>* find(K key)
        {
            node = first;
            while(node->next != NULL)
                {
                    if(node.key = key)
                    {
                        return node;
                    }
                    node = node->next;
                }

            node = NULL;
            return curr;
        }

    protected:

    private:
        int numItems;
        KeyDataListNode<K, T> *first;
        KeyDataListNode<K, T> *last;

        KeyDataListNode<K, T> *node;
};

#endif // KEYDATALIST_H
