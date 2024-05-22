#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;

class Solution{
public:
    Solution(){}

    int sol(vector<int> nums) {
        unordered_map<int,bool> table;
        int max = nums[0];
        int min = nums[0];

        for(auto i : nums){
            table[i] = true;
            if(max < i){
                max = i;
            }
            if(min > i){
                min = i;
            }
        }
        int cont = 1;
        while (true){
            if(cont > 0 && !table[cont]){
                return cont;
            }
            cont++;
        }
    }
};

int main(){
    Solution s1;

    vector<int> nums = {1,2,0};
    cout<<s1.sol(nums)<<endl;

    vector<int> nums2 = {3,4,-1,1};
    cout<<s1.sol(nums2)<<endl;

    vector<int> nums3 = {7,8,11,12};
    cout<<s1.sol(nums3)<<endl;


}