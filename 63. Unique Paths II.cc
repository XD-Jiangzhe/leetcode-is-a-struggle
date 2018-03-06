/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        if(obstacleGrid.empty())
            return 0;
        int height = obstacleGrid.size();    
        int length = obstacleGrid[0].size();

        return findUniqueWIthObstacles(obstacleGrid, 0, 0, height, length); 
    }
    int findUniqueWIthObstacles(vector<vector<int>>& matrix, int start_h, int start_l, int height, int length)
    {
        if((start_h == height-1 && start_l == length-1) && matrix[start_h][start_l]!=1)
            return 1;
        else if(start_h>=height ||start_l>= length)
            return 0;
        if(matrix[start_h][start_l]==1)
            return 0;

        return findUniqueWIthObstacles(matrix, start_h+1, start_l, height, length)+ findUniqueWIthObstacles(matrix, start_h, start_l+1, height, length);
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())
            return 0;
        int height = obstacleGrid.size();    
        int length = obstacleGrid[0].size();
        vector<vector<int> > matrix(height, vector<int>(length, 0));

        findUniqueWIthObstacles(obstacleGrid, matrix, height, length);
        return matrix[0][0];
    }

    void findUniqueWIthObstacles(vector<vector<int>>& map, vector<vector<int>>&matrix, int height, int length)
    {
        bool isStock = false;
        for(int i=height-1; i>=0; --i)
        {
            if(map[i][length-1] ==1&& !isStock)
                isStock = !isStock;

            if(!isStock)
                matrix[i][length-1] = 1;  
            else 
                matrix[i][length-1]  =0;    
        }
        isStock = false;
        for(int i=length-1; i>=0; --i)
        {
            if(map[height-1][i] ==1 && !isStock)
                isStock = !isStock;

            if(!isStock)
                matrix[height-1][i] = 1;  
            else 
                matrix[height-1][i]  =0;    
        }

        for(int i= height-2; i>=0; --i)
        {
            for(int j = length-2; j>=0; --j)
            {
                if(map[i][j] == 1)
                    matrix[i][j] = 0;
                else 
                    matrix[i][j] = matrix[i][j+1]+matrix[i+1][j];
            }
        }
    }
};

int main()
{
    vector<vector<int>> matrix{{1,1}};
    Solution a;
    cout<<a.uniquePathsWithObstacles(matrix)<<endl;
}