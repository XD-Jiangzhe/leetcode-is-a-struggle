/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        //return finduniquePaths(m, n);
        vector<vector<int>> matrix(m+1, vector<int>(n+1,1));

        insertMatrix(matrix, m, n);
        return matrix[m][n];
    };

    void insertMatrix(vector<vector<int>>& matrix, int m, int n)
    {
        for(int i=2; i<= m;++i)
        {
            for(int j=2; j<=n; ++j)
            {
                matrix[i][j] = matrix[i-1][j]+matrix[i][j-1];
            }
        }    
    }

    // int finduniquePaths(int m, int n)
    // {
    //     if(m==1 && n==1)
    //         return 1;
    //     else if(m==0 || n==0)
    //         return 0;
        
    //     return finduniquePaths(m-1,n)+finduniquePaths(m, n-1);
    // }
    
};

int main()
{
    Solution a;
    cout<<a.uniquePaths(3,3)<<endl;
    return 0;
}