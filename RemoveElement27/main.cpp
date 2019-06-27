#include <iostream>
#include <vector>
using namespace std;
//删除掉数组中给定的val值 并返回删除后的数组的长度

class Solution {
public:
    //时间复杂度O(n)
    //空间复杂度O(1)
    int removeElement1(vector<int>& nums, int val) {
        int k = 0;
        for(int i=0; i < nums.size(); i++)
            if(nums[i] != val)
                nums[k++] = nums[i];  //不等val的值存入[0....k)中
        return k;
    }


    //将找到的元素放置在数组最后几位
    //时间复杂度O(n)
    //空间复杂度O(1)
    int removeElement2(vector<int>& nums, int val) {
        int k = 0;
        for(int i=0; i < nums.size(); i++)
            if(nums[i] ^ val)
                nums[k++] = nums[i];  //不等val的值存入[0....k)中
        for(int i =k; i<nums.size(); i++)
            nums[i] = val;
        return k;
    }

    //删掉数组中指定的元素并返回删掉后的数组
    //时间复杂度O(n)
    //空间复杂度O(1)
    int removeElement3(vector<int>& nums, int val) {
        int k = 0;
        for(int i= 0; i < nums.size(); i++)
            if(nums[i] != val)
                swap(nums[k++], nums[i]);  //不等val的值存入[0....k)中             
        int nums_lenth =  nums.size();       
        for(int i = k; i < nums_lenth; i++)  { //每执行以此pop_back nums.size()就会减少1 所以这里循环时不能使用nums.size()
            nums.pop_back();
        }           
        return k;
    }
};


int main(){
    int arr[] = {1,8,8,8,8,8,8,3,4,5,6,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,3};
    vector<int> test_arr(arr, arr+sizeof(arr)/sizeof(int));  //创建一个vector
    
    cout<<Solution().removeElement3(test_arr,8);
    cout << endl;
    for(int i=0; i<test_arr.size();i++)
        cout <<test_arr[i]<<"\t";
    return 0;

}