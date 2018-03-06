/*
79. Word Search

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || word.empty())
            return false;
        
        int height = board.size();
        int length = board[0].size();
        
        vector<vector<bool>> isUsed(height, vector<bool>(length, false));
        
        bool result = false;
        for(int i=0; i<height; ++i)
            for(int j =0; j<length; ++j)
                result |=exitCore(board, word, isUsed, height, length, i, j);

        return result;
    }
    
    bool exitCore(vector<vector<char>>& board, string word, vector<vector<bool>>& isUsed, int height, int length, int x, int y)
    {
        if(word.empty())
            return true;
        if(x<0 || x>=height || y<0 ||y>length)
            return false;

        bool result = false;
        auto temp = word.substr(1);
        if(word[0] == board[x][y] && !isUsed[x][y])
         {
            isUsed[x][y] = true;
            result =  exitCore(board, temp, isUsed, height, length, x+1, y)
                    ||exitCore(board, temp, isUsed, height, length, x-1,  y)
                    ||exitCore(board, temp, isUsed, height, length, x, y-1)
                    ||exitCore(board, temp, isUsed, height, length, x, y+1);
            if(result == false)
            {
                isUsed[x][y] = false;
            }
         }   
        return result;
    }
};

int main()
{
    vector<vector<char>> matrix{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    Solution a;
    auto re = a.exist(matrix, "ABCCED");
    cout<<re<<endl;

    return 0;
}