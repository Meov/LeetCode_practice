#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //时间复杂度 O(n)
    //空间复杂度 O(n)
    
    void moveZeroes(vector<int>& nums) { 
        vector<int> nonZeroElements;
        for(int i = 0; i<nums.size();i++)
            if(nums[i])
                nonZeroElements.push_back(nums[i]);   //提取非0元素
        for(int i=0; i<nonZeroElements.size();i++)
            nums[i] = nonZeroElements[i];             //存入非0元素
        for(int i =nonZeroElements.size(); i<nums.size();i++) //存入0元素
             nums[i]  = 0;
    }
    //时间复杂度 O(n)
    //空间复杂度 O(1)
    void moveZeroes_2(vector<int>& nums){
        int k = 0; //nums中，[0....k)的元素为非零
        //遍历到第i个元素后，保证[0....k)的元素为0
        for(int i = 0; i<nums.size(); i++)
            if(nums[i]){
                nums[k++] = nums[i];   //非0元素存入[0...k)索引中
            }       
        for(int i = k; i<nums.size(); i++)  //将0元素 存入[K...nums.size())中
            nums[i] = 0;
    }

    //零元素和非零元素交换位置
    void moveZeroes_3(vector<int>& nums){
        int k = 0; //nums中，[0....k)的元素为非零
        //遍历到第i个元素后，保证[0....k)的元素为0
        for(int i = 0; i<nums.size(); i++)
            if(nums[i]){
                if(i != k)//  特殊情况下整个数组都是非0元素，防止自己和自己交换
                    swap(nums[k++],nums[i]);   //非0元素存入[0...k)索引中
                else 
                    k++;
            }              
    }
};


int main(){  
    int arr[] = {1,2,0,4,5,6,7,0,7,5,3,2,1,4,67,9,0,5,6,0};
    vector<int> test_arr(arr, arr+sizeof(arr)/sizeof(int));
    Solution().moveZeroes_3(test_arr);
    for(int i = 0; i<test_arr.size();i++){
        cout<<test_arr[i]<<"\t";
    }
    cout<<endl;

}
     