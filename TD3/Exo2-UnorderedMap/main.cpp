#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSumBruteForce(const vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i+1; j < nums.size(); j++)
        {
            if(nums[i]+nums[j]==target){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

vector<int> twoSumOptimal(const vector<int>& nums, int target) {
    unordered_map<int,int> numMap;
    for (int i = 0; i < nums.size(); i++)
    {
        if(numMap.find(target-nums[i])!=numMap.end()){
            return {numMap[target-nums[i]],i};
        }
        numMap[nums[i]]=i;
    }
    return {-1,-1};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);
    cout << "Brute Force Solution: ["
         << indicesBruteForce[0] 
         << ", " 
         << indicesBruteForce[1] 
         << "]" 
         << endl;

    vector<int> indicesOptimal = twoSumOptimal(nums, target);
    cout << "Optimal Solution: ["
         << indicesOptimal[0] 
         << ", " 
         << indicesOptimal[1] 
         << "]" 
         << endl;

    return 0;
}