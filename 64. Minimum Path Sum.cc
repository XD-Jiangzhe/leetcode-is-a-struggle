/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
[[1,3,1],
 [1,5,1],
 [4,2,1]]
Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the sum.
*/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int height = grid.size();
        int length = grid[0].size();
        vector<vector<int>> map(height, vector<int>(length, 0));
        insertPathMap(grid, map , height, length);

        return map[height-1][length-1];
    }

    void insertPathMap(vector<vector<int>>& grid, vector<vector<int>>& map, int height, int length)
    {
        int down = 0;
        int right = 0;
        for(int i=0; i<height; ++i)
        {
            map[i][0] = down+grid[i][0];
            down +=grid[i][0];
        } 
        for(int i=0; i<length; ++i)
        {
            map[0][i] = right+grid[0][i];
            right += grid[0][i];
        }

        for(int i=1; i<height; ++i)
        {
            for(int j =1; j<length; ++j)
            {
                map[i][j] = min(map[i-1][j], map[i][j-1])+grid[i][j];
            }
        }
    }
};

int main()
{
    vector<vector<int>> map{{1,3,1},{1,5,1},{4,2,1}};
//    vector<vector<int>> map{{1}};
    Solution a;
    cout<<a.minPathSum(map)<<endl;
    return 0;
}