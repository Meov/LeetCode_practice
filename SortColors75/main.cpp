#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
using namespace std;

/****
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the 
same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
***/



class Solution{
public:
    //时间复杂度O(1)
    //空间复杂度O(k) //开辟了一个count[3]数组  k为元素的取值范围
    //计数排序，在数据量有限时，分别数出数组中有多少个相应的元素，然后将各个元素再按照各自的个数存入数组中。

    void sortColors(vector<int>&nums){
        int count[3] = {0};  //存放0 1 2 三个数的频率
        for(int i =0; i<nums.size();i++){
            assert(nums[i]>=0 && nums[i]<=2);
            count[nums[i]]++;
        }
        int index = 0;
        for(int i = 0;i<count[0];i++){
            nums[index++] = 0;
        }
        for(int i = 0; i<count[1]; i++){
            nums[index++] = 1;
        }
        for(int i =0;i<count[2]; i++){
            nums[index++] = 2;
        }

/****
       for(int i = 0; i<nums.size();i++){
            if(i < count[0])
                nums[i] = 0;
            else if(i<count[1]+count[0])
                nums[i] = 1;
            else 
                nums[i] = 2;   
        } 
 ***/
        
    }
};


int main(){
    Solution s;
    int arr[] = {0,1,2,2,2,1,1,1,2,2,2,2,0,0,0};
    vector<int>test_array(arr,arr+sizeof(arr)/sizeof(int));
    s.sortColors(test_array);
    
    for(int i = 0; i<test_array.size();i++){
        cout << test_array[i] <<"\t";
    }


    return 0;
}