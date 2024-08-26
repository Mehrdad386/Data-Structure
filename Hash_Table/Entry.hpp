#include<string>

struct Entry{
    int key ;
    std::string value ;

    Entry(int key , std::string value) : key(key) , value(value) {}
};