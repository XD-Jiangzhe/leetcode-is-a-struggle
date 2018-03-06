/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

*/

#include <vector>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()<=0)
            return;
        int height = matrix.size();
        int length = matrix[0].size();
        set<int> rows;
        set<int> cols;
        
        recordTheRowsAndCols(matrix, rows, cols, height, length);
        // for(auto const& i: rows)
        //     cout<<i<<" ";
        // cout<<endl;
        // for(auto const& j: cols)
        //     cout<<j<<" ";
        // cout<<endl;

        setZeroInMatrix(matrix, rows, cols, height, length);
    }
    void recordTheRowsAndCols(vector<vector<int>>& matrix, set<int>& rows, set<int>& cols, int height, int length)
    {
        for(int i=0; i<height; ++i)
        {   for(int j=0; j<length; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
    }
    void setZeroInMatrix(vector<vector<int>>& matrix, set<int>& rows, set<int>&cols, int height, int length)
    {
        for(auto const& i :rows)
        {
            for(int j=0;j<length; ++j)
                matrix[i][j] = 0;
        }
        for(auto const& i: cols)
        {
            for(int j=0; j<height; ++j)
                matrix[j][i] = 0;
        }
    }
};

int main()
{
    vector<vector<int>> re{{1,0}};
    Solution a;
    a.setZeroes(re);

    return 0;
}