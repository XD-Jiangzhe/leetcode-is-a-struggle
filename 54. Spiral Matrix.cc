/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <map>
#include <iterator>

using namespace std;

int i;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		vector<int> re;
		if(matrix.empty())
			return re;
		
		int cols = matrix[0].size();
		int rows = matrix.size();
		int start = 0;
		while(cols > 0 && rows >0)
		{
			printOneCircle(matrix, re, rows, cols, start);
			cols -=2;
			rows -=2;
			++start;
		}
		return re;
    }
	vector<int> printOneCircle(vector<vector<int>>& matrix, vector<int>& re, int rows, int cols, int start)
	{

		int endX = cols-1;
		int endY = rows-1;

		if(cols>0)
			for(int i=start; i<start+cols; ++i)
				re.push_back(matrix[start][i]);
		if(rows>=2)
			for(int i=start+1; i<start+rows-1; ++i)
				re.push_back(matrix[i][start+cols-1]);
		if(rows>=2)
			for(int i=start+cols-1; i>=start; --i)
				re.push_back(matrix[start+rows-1][i]);
		if(cols>=2)
			for(int i=start+rows-2; i>=start+1; --i)
				re.push_back(matrix[i][start]);

		return re;
	}
};

int main()
{
	Solution a;
	vector<vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
//	vector<vector<int>> matrix{{6,9,7}};
	auto re = a.spiralOrder(matrix);
	
	copy(re.begin(), re.end(), ostream_iterator<int>(cout, " "));
	cout<<"\n";

	return 0;
}

