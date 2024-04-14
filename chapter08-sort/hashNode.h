/**
 * @Description 哈希表
 * @Version 1.0.0
 * @Date 2024/4/13 0:42
 * @Author Kenton
 */
#ifndef INC_08WANGDAO_HASHNODE_H
#define INC_08WANGDAO_HASHNODE_H

#include "iostream"

using namespace std;

template<typename KeyType,typename ValueType>
class hashNode {
    KeyType key;
    ValueType value;
    hashNode *next;

    hashNode(const KeyType& key, const ValueType& value){
        this->key = key;
        this->value =value;
        this->next = NULL;
    }
};

template<typename KeyType,typename ValueType>
class HashTable{
    int size;
    hashNode<KeyType,ValueType> **table;

    int hash(const KeyType& key) const{
        int hashkey = key % size;
        if (hashkey < 0){
            hashkey += size;
        }
        return hashkey;
    }
public:
    HashTable()
};





#endif //INC_08WANGDAO_HASHNODE_H
