#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
找下一个字典序 序列

从后往前 找 按 从小到大排序的最后徐一个数

然后 再从后往前找 第一个比 nums[k]小的数，
然后交换  两者的位置 
再将后面的数重新排序

寻找下一个字典序 ，其实是 找 一个突出来的 峰， 此尖头的左右其实都是按照字典序来的

找 不按字典序的序列 的前一个，然后 再从后往前找第一个 比 峰前大的值， 交换之后再对其后进行重新排序 

此题直接用 

next_permutation(nums.begin(),nums.end());
该算法是求出此队列的下一个字典序

算法可以直接得到答案。。。。233333

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

    	int k = -1,i=-1;
    	for(k = nums.size()-2; k >=0; --k)
    	{
    		if(nums[k]<nums[k+1])
    			break;
    	}
    	if(k == -1)
    		reverse(nums.begin(), nums.end());
    	else
    	{
    		for( i=nums.size()-1;i>k; --i)
    		{
    			if(nums[i]>nums[k])
    				break;
    		}
    		swap(nums[i], nums[k]);
    		reverse(nums.begin()+k+1, nums.end());
    	}
    }
};

void print(vector<int>& nums)
{
	for(const auto & i: nums)
	{
		cout<<i<<" ";
	}
	cout<<endl;
}

int main()
{
	Solution a;

	vector<int> s{1,2,10,3};
	a.nextPermutation(s);

	print(s);

	return 0;
}