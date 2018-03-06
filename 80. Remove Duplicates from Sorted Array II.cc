/*
80. Remove Duplicates from Sorted Array II

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
It doesn't matter what you leave beyond the new length.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        int preCount = 1;
        int result = nums.size();

        
        for(int i=1 ;i<nums.size(); ++i)
        {
            if(nums[i] == nums[i-1])
            {
                ++preCount;
                if(preCount >2)
                {
                    result--;
                    auto temp = nums.erase(nums.begin()+i);
                    if(temp != nums.end())
                        i = temp-nums.begin()-1;
                }
            }
            else 
                preCount =1;
        }
        return result;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0;
        for(int  n: nums)
            if(i<2 || n > nums[i-2])
                nums[i++] = n;
        return i;

    }
};
int main()
{
    Solution a;
    vector<int> nums{1,1,1,1,1,1};
    cout<<a.removeDuplicates(nums)<<endl;
    for(auto const& i : nums)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}