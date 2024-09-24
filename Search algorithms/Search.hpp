#include<vector>
#include<algorithm>
#include<cmath>

class Search{

public:

    int linearSearch(std::vector<int>& array , int target){
        for(int i{} ; i<array.size() ; i++){
            if(array.at(i) == target)
                return i ;
        }
        return - 1 ;
    }

    int binarySearch(std::vector<int>& array , int target){
        std::sort(array.begin() , array.end()) ;
        return binarySearch (array , target , 0 , array.size() - 1) ;

    }

    int ternarySearch(std::vector<int>& array , int target){
        std::sort(array.begin() , array.end()) ;
        return ternarySearch(array , target , 0 , array.size() - 1) ;
    }

private:


    int binarySearch(std::vector<int>& array , int target , int left , int right){
        
        if(right<left)
            return -1 ;
        
        int middle = std::floor((left + right) / 2) ;

        if(array.at(middle) == target)
            return middle ;
        if(target < array.at(middle))
            return binarySearch(array , target , 0 , middle - 1) ;
        else
            return binarySearch(array , target , middle + 1 , array.size() - 1) ;
        
    }

    int ternarySearch(std::vector<int>& array , int target , int left , int right){
        
        if(right<left)
            return -1 ;   

        int partitionSize = (right - left) / 3 ;
        int mid1 = left + partitionSize ;
        int mid2 = right - partitionSize ;

        if(array.at(mid1) == target)
            return mid1 ;
        if(array.at(mid2) == target)
            return mid2 ;
        
        if(target<array.at(mid1))
            return ternarySearch(array , target , left , mid1-1) ;
        if(target>array.at(mid2))
            return ternarySearch(array , target , mid2+1 , right ) ;
        else  
            return ternarySearch(array , target , mid1 + 1 , mid2 - 1) ; 

    }
    



};