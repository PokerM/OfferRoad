class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        for(int i=0;i<length;i++){
            int index=numbers[i] % length;//防止越界
            if(numbers[index] >= length){
                *duplication=index;
                return true;
            }              
            numbers[index] += length;//标记为数字被访问过  
        }
        return false;
    }
};