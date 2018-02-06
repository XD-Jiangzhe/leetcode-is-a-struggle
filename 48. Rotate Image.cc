/*
将一个矩阵 顺时针 旋转 90 度， 可以先将 所有的元素根据竖对象线 进行翻转，即reverse 操作，然后 再根据正斜对角线进行变化，即可得到 顺时针 旋转90度之后的矩阵 
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
    	int length = matrix[0].size();
    	int deepth = matrix.size();

    	for(int i=0; i< deepth;++i)
    	{
    		reverse(matrix[i].begin(), matrix[i].end());
    	}

    	int mutex= 1, i= deepth-mutex, j = 0  ;
    	for( ; mutex <=length ; ++mutex)
    	{
    		for(int temp = 0; temp <= length-mutex; ++temp)
    		{
    			swap(matrix[i][j+temp], matrix[i-temp][j]);
    		}
    		j++;
    		i--;
    	}

    }
};

template<typename T>
struct display{

	void operator()(const T& t){
		cout<<t<<" ";
	}
};

int main()
{
	vector<vector<int>> matrix{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
	Solution a;
	a.rotate(matrix);

	for(int i =0; i<matrix.size(); i++)
	{
		for_each(matrix[i].begin(), matrix[i].end(), display<int>());
		cout<<endl;
	}

	return 0;
}
