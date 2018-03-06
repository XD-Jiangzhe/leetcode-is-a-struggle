#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty())
            return false;
        return jump_next(0, nums);

    }
    bool jump_next(int pos, vector<int>& nums)
    {
        if(pos == nums.size()-1)
            return true;
        else 
        {
            int max_jmp = min(nums[pos], int(nums.size())-pos-1);
            for(int i=1; i<=max_jmp ; ++i)
            {
                if(jump_next(pos+i, nums))
                    return true;
            }
            return false;
        }
    }
    bool canJump1(vector<int>&nums)
    {
        int i=0;
        for(int reach = 0; i<nums.size()&&reach < nums.size(); ++i)
        {
            reach = max(i+nums[i], reach);
        }
        return i == nums.size();
    }
};


int main()
{
    Solution a;
    vector<int> ex{2,0,0};
    if(a.canJump(ex))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}