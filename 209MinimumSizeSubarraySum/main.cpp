#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = -1; //窗口设定 nums[l...r]
        int sum = 0; //窗口中元素的和
        int res = nums.size()+1; //最小的长度 在最开始设定他为数组中最大的值

        while(l < nums.size()){           
            if(sum < s && r+1 < nums.size()){
                sum += nums[++r];   //增加右区间一个值
            }
            else{  
                sum -= nums[l++];   //去掉左区间第一个值         
            } 
            if(sum >= s)
                res = min(res, r-l+1);  //前闭后闭区间 所以要+1   
                
        }
        if(res == nums.size()+1){
            return 0;        
        }
        return res;
    }
};


int main(){
    int arr[] = {1,2,3,4,5,4,31,1};
    vector<int>test_arr(arr,arr+sizeof(arr)/sizeof(int));
    cout << Solution().minSubArrayLen(3,test_arr);



    return 0;
}
