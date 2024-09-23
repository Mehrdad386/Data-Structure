#include<vector>
#include<cmath>

class Sort{

public:

    void bubbleSort(std::vector<int>& array){
        
        bool swapped ; //to check if array is already sorted

        for(size_t i{} ; i<array.size()  ; i++){
            swapped = false ;
            for(size_t j{1} ; j<array.size() - i ; j++){
                if(array[j] < array[j-1]){
                    std::swap(array[j] , array[j-1]) ;
                    swapped = true ;
                }
            }
            if(!swapped){
                break;
            }
        }

    }


    void selectionSort(std::vector<int>& array) {
        for (size_t i = 0; i < array.size() - 1; i++) {
            size_t minIndex = i;
            for (size_t j = i + 1; j < array.size(); j++) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            
            std::swap(array[i], array[minIndex]);
        }
    }

    void insertionSort(std::vector<int>& array){
        for(size_t i{1} ; i<array.size() ; i++){
            int current = array[i] ;
            int j = i-1 ;
            while (j >= 0 && array[j] > current)
            {
                array[j+1] = array[j] ;
                j--;
            }
            array[j+1] = current ;
            
        }
    }

    void mergeSort(std::vector<int>& array){

        if(array.size() < 2)
            return ;
            
        size_t middle = std::floor(array.size() / 2) ;

        std::vector<int> left(middle) ;
        for(int i{} ; i<middle ; i++){
            left[i] = array[i] ;
        }
        std::vector<int> right(array.size() - middle) ;
        for(int i =middle ; i<array.size() ; i++){
            right[i-middle] = array[i] ;
        }
        mergeSort(left) ;
        mergeSort(right) ;

        merge(left , right , array) ;
    }

    void quickSort(std::vector<int>& array){
        quickSort(array , 0 , array.size() - 1) ;
    }

private:

    //to be used in mergeSort method
    void merge(std::vector<int>& left , std::vector<int>& right , std::vector<int>& result){
        int i{} , j{} , k{} ;
        while(i<left.size() && j<right.size()){
            if(left[i] < right[j])
                result[k++] = left[i++] ;
            else
                result[k++] = right[j++] ;
            
            
        }
        while(i<left.size())
            result[k++] = left[i++] ;
        while(j<right.size())
            result[k++] = right[j++] ;
    }

    //to be used in quickSort method
    int partition(std::vector<int>& array, int start, int end) {
        int pivot = array[end];
        int boundary = start - 1;

        
        for (int i = start; i < end; i++) {
            if (array[i] <= pivot) {
                std::swap(array[++boundary], array[i]);
            }
        }
        
        std::swap(array[boundary + 1], array[end]);
        return boundary + 1;
    }

    void quickSort(std::vector<int>& array , int start , int end){
        if(start >= end)
            return ;

        int boundary = partition(array , start , end) ;
        quickSort(array , start , boundary-1) ;
        quickSort(array , boundary + 1 , end) ;

    }

};