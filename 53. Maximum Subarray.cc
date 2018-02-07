/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

/*
这里使用的方法 特别的巧妙，就是当和小于 0 的时候 才会重置，否则会一直加 避免了 前面是一个 较小的负数，后面是一个大正数的极值的情况
因为这种情况 肯定是不如 直接加一个大正数 来的大，因为此时 的sum是小于0 的
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <map>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
  
    	int sum =nums.front();
    	int max1 = sum;
    	for(int i=1; i<nums.size(); ++i)
    	{
    		sum = max(sum, 0);	
    		sum = sum+ nums[i];
    		max1 = max(sum, max1);

    	}

    	return max1;
    }
};