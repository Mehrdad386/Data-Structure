#include"Entry.hpp"
#include<list>
#include<iostream>

class HashTable{

public:

 
    HashTable() : size(10) {
        entries = new std::list<Entry>[size];
    }
    

    void put(int key, const std::string& value) {
        int index = hash(key);
        std::list<Entry>& bucket = entries[index];
        
        for (auto& entry : bucket) {
            if (entry.key == key) {
                entry.value = value; 
                return;
            }
        }

        Entry newEntry(key, value);
        bucket.push_back(newEntry);
    }


    std::string get(int key){
        int index = hash(key) ;
        std::list<Entry>& bucket = entries[index] ;
        if(!bucket.empty()){
            for(auto& entry : bucket){
                if(entry.key == key){
                    return entry.value ;
                }
            }
        }
        return "NULL" ;
    }

    void remove(int key) {
        int index = hash(key);
        std::list<Entry>& bucket = entries[index];

        if (bucket.empty()) {
            throw std::invalid_argument("No key to remove");
        }


        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it); 
                return;
            }
        }

        throw std::invalid_argument("Key not found");
    }
    

    ~HashTable(){ delete[] entries ;}

private:
    std::list<Entry>* entries  ;
    int size ;

    int hash(int key){
        return key % size ;
    }

};