#include<unordered_map>
#include<set>
#include<string>

class CharFinder{

public:

    //this function is defined to find first unique character in a string by hash_table(unordered_map)
    char findFirstUniqueCharacter( std::string word ){
        std::unordered_map<char , int> hash ;
        char output = '\0' ;
        for(char i : word){
            hash[i]++ ;    
        }
        for(char i : word){
            if(hash[i] == 1){
                output = i ;
                break;
            }
        } 
        return output ;

    }

    //this function is defined to find first repeated character in  a string by set
    char findFirstRepeatedCharacter(std::string word){
        std::set<char> Set ;
        for(char i : word){
            if(Set.find(i) == Set.end())
                Set.insert(i) ;
            else
                return i ;
        }
        return '\0' ;
    }

private:



};