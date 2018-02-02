#include <iostream>
#include <algorithm>

using namespace std;

/*
next-permutation 
	模板函数， 功能是按照默认 operator< 生成指向容器的下一个词典排列，即 全排列中的下一个词典序列
	
	这个 如果 是有下一个 词典排序 则 返回true 并且将 序列变成下一个词典排序， 如果没有下一个 则 返回true 并将其 按照 < 排好序

*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
    	vector<vector<int>> mul;

    	do
    	{
    		mul.push_back(nums);
    	}while(next_permutation(nums.begin(), nums.end()));

    	return mul;
    }
};