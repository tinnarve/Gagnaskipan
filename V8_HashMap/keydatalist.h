#ifndef KEYDATALIST_H
#define KEYDATALIST_H


class KeyDataList : public Map<K, T>
{
    public:
        KeyDataList() {
            ///ADD
        }
        virtual ~KeyDataList() {
            clear();
        }

        void insert(K key, T data)
        {
            ///Add the data data with the key key .
            ///If there is already an item with the key key in the map,
            ///throw ItemExistsException .
        }
        void update(K key, T data)
        {
            ///Updates the data connected to the key key so they are now data .
            ///If no item with the key key is found in the map, throw NotFoundException .
        }
        T get(K key)
        {
            ///Returns the data connected to the key key .
            ///If no item with the key key is found in the map, throw NotFoundException .
        }
        void remove(K key)
        {
            ///Removes the key key and its connected data from the data structure.
            ///If no item with the key key is found in the map, throw NotFoundException.
        }
        bool contains(K key)
        {
            ///Returns true the map contains the key key and connected data, otherwise false .
        }
        int size() {
            //Returns the number of items currently in the map
            return numItems;
        }
        bool empty()
        {
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
        }
        void print(ostream& out)
        {
            ///Prints the contents of the data structure.
            ///This function is only for your own testing. Mooshak does not call it.
        }

    protected:

    private:
        int numItems;
};

#endif // KEYDATALIST_H
