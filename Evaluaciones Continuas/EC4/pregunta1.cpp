#include "iostream"
#include "unordered_map"

using namespace std;


class Solution{
public:
    Solution(){}

    int sol(string word) {
        unordered_map<char, int> table;
        for (auto i: word) {
            table[i]++;
        }

        for(int i = 0;i<word[i];i++){
            if(table[word[i]] == 1){
                return i;
            }
        }

        return -1;


    }
};


int main(){

    Solution s1;

    cout<<s1.sol("aabb");

}