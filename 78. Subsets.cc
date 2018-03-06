/*
78. Subsets
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

给出一个数组，求出它的子集
该问题使用递归来解决
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>>result;
        vector<int> now;

        for(int i=0; i<nums.size(); ++i)
        {
            now.push_back(nums[i]);
            FindNextSubSets(result ,now, nums, i+1);
            now.clear();
        }
        result.push_back(now);
        return result;
    }

    void FindNextSubSets(vector<vector<int>>& result, vector<int>& now, vector<int>& nums, int pos)
    {
        if(pos ==nums.size())
        {
            result.push_back(now);
            return;
        }    
        
        now.push_back(nums[pos]);
        FindNextSubSets(result, now, nums, pos+1);
        now.pop_back();
        FindNextSubSets(result, now, nums, pos+1);
    }
};

int main()
{
    vector<int> nums{1,2,3};
    Solution a;
    auto re = a.subsets(nums);

    for(auto const& i : re)
    {
        for(auto const& j : i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}