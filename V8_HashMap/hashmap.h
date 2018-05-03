#ifndef HASHMAP_H
#define HASHMAP_H

#include "keydatalist.h"
#include "map.h"
const int INIT_SIZE = 4;

template<class K, class T>
class HashMap : public Map<K, T>
{
    public:

        HashMap(int (*hash_func)(K)){
            this->hash_func = hash_func;
            table = new KeyDataList<K, T> *[INIT_SIZE]();
            for (int i = 0; i < INIT_SIZE; i++){
                table[i] = NULL;
            }
        };

        virtual ~HashMap() {
            clear();
        }
        void insert(K key, T data)
        {
            ///Add the data with the key key
            ///If there is already an item with the key key in the map,
            ///throw ItemExistsException .
            newKey = hash_func(key);
            bool check = false;

            if(table[newKey] == NULL)
            {
                KeyDataList<K, T> bucket = KeyDataList<K, T>(newKey);
                table[newKey] = &bucket;
                check = table[newKey]->add(key, data);
                if(!check)
                {
                    throw ItemExistsException();
                }
                numItems++;
                return;
            }

           /*
            int tablekey;

            for(int i = 0; i < INIT_SIZE; i++)
            {


                tablekey = table[i]->getKey();
                if(table[i] == NULL)
                {
                    KeyDataList<K, T> bucket = KeyDataList<K, T>(newKey);
                    table[i] = &bucket;
                    check = table[i]->add(key, data);
                    if(!check)
                    {
                        throw ItemExistsException();
                    }
                    numItems++;
                    return;
                }
                else if(tablekey == newKey)
                {
                    if(table[i]->find(key))
                    {
                        throw ItemExistsException();
                    }
                    else{
                        table[i]->add(key, data);
                        numItems++;
                        return;
                    }
                }
            }*/
        }

        void update(K key, T data)
        {
            ///Updates the data connected to the key key so they are now data .
            ///If no item with the key key is found in the map, throw NotFoundException .

        }

        T get(K key)
        {
            ///Returns the data connected to the key key .
            ///If no item with the key key is found in the map, throw NotFoundException
            return false;
        }

        void remove(K key)
        {
            ///Removes the key key and its connected data from the data structure.
            ///If no item with the key key is found in the map, throw NotFoundException.

        }

        bool contains(K key)
        {
            newKey = hash_func(key);
            bool check = false;
            int tablekey;

            for(int i = 0; i < INIT_SIZE; i++)
            {
                tablekey = table[i]->getKey();

                if(tablekey == newKey)
                {
                    if(table[i]->find(key))
                    {
                        return true;
                    }
                    else{
                        return false;
                    }
                }
            }
            ///Returns true the map contains the key key and connected data, otherwise false .
            return false;
        }

        int size() const{
            //Returns the number of items currently in the map
            return numItems;
        }

        bool empty() const
        {
            //if list is empty return true, else false.
            return false;
        }

        void clear()
        {
            ///Empties the data structure.

        }

        void print(ostream& out) const
        {
            /*for(int i = 0; i < INIT_SIZE; i++)
            {
                if(table[i] != NULL)
                {
                    table[i]->print(out);
                }
            }*/
            table[100]->print(out);
        }

    protected:

    private:
        int numItems;
        KeyDataList<K, T> **table;
        int newKey;

        int (*hash_func)(K);
};

#endif // HASHMAP_H
