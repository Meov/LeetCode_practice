#include <vector>
#include <iostream>
using namespace std;

class Solution {
public: 
    //暴力解法
    //时间复杂度O(n^2)
    //空间复杂度O(1) 
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = 0;
        int index = 0;
        vector<int> result;
        for(i=0; i<numbers.size();i++){
            for(j=i+1; j<numbers.size();j++)
                {
                    if(numbers[i]+numbers[j] == target)
                    return {i+1,j+1};
                }
        }
        return {0,0};
    }



    //时间复杂度O(n)
    //空间复杂度O(1) 
    vector<int> twoSum2(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;  //[0.....n-1]       
        while(numbers[l]+numbers[r]!=target){
            if(numbers[l]+numbers[r]>target)
                r--;
            else 
                l++;
        }
        return vector<int>({l+1,r+1});   
    }
};


int main(){
    vector<int>test_array = {1,2,9,9,999,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,2,1,1,1,13,3};
    int target = 5;
    Solution s;
    for(int i = 0; i<s.twoSum2(test_array,target).size();i++){
        cout << s.twoSum2(test_array,target)[i]<<"\t";
    }
}