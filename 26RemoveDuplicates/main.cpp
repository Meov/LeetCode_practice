#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
/*
Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;

        if(nums.size() == 0)  //边界条件 若输入的数组为空
            return 0;

        for (int i = 0; i<nums.size(); i++){
            if(nums[k]!=nums[i]){
                k++;
                nums[k] = nums[i];
            }                    
        }

        return k+1;       
    }
};

int main(){
    int arr[] = {1,1,1,2,2,3,3,3,5,5,5,6};
    clock_t start_time = clock();
    vector<int> test_array(arr,arr+sizeof(arr)/sizeof(int));
     clock_t end_time = clock();
    cout << Solution().removeDuplicates(test_array) << '\t'<<double(end_time-start_time)/CLOCKS_PER_SEC<<endl;
    return 0;

}