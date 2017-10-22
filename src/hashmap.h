#pragma once

#include <string>
#include <functional>

using namespace std;

// HashMap
// Basic hash map supporting anything you can hash with std::hash

namespace exemplar
{
    template <class K, class V> class HashMap
    {
    private:
        class Item
        {
        public:
            Item(const K& key, const V& value, Item* next)
            : key(key)
            , value(value)
            , next(next)
            {
            }
    
            K key;
            V value;
            Item* next;
        };

    public:
        HashMap(int initialCapacity = 100)
        {
            data.resize(initialCapacity, nullptr);
        }

        void set(const K& key, const V& value)
        {
            int hashCode = getHashCode(key);
            int index = abs(hashCode) % data.size();
            Item* item = nullptr;
            for (item = data[index]; item != nullptr; item = item->next) {
                if (item->key == key) {
                    item->value = value;
                    return;
                }
            }

            item = new Item(key, value, data[index]);
            data[index] = item;
        }

        V get(const K& key)
        {
            int hashCode = getHashCode(key);
            int index = abs(hashCode) % data.size();
            Item* item = nullptr;
            for (item = data[index]; item != nullptr; item = item->next) {
                if (item->key == key) {
                    return item->value;
                }
            }
            return V();
        }

    private:
        vector<Item*> data;

        int getHashCode(K key)
        {
            hash<K> hashGen;
            return hashGen(key);
        }
    };
}