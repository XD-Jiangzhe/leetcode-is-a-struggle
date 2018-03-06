/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> re;
        if(n<=0)
            return re;

        vector<int> line(n);
        for(int i=0; i<n; ++i)
            re.push_back(line);
        
        int start = 0;
        int number  = 1;
        while(n>0)
        {
            insertTheCircle(re, start, n, number);
            ++start;
            n -=2;
        }
        return re;
    }

    void insertTheCircle(vector<vector<int> >& matrix, int start, int n, int& number)
    {
        for(int i=0; i<n; ++i)
        {
            matrix[start][start+i] = number++;
        }
        if(n>2)
        for(int i=1; i<n-1; ++i)
        {
            matrix[start+i][start+n-1] = number++;
        }
        if(n>1)
        for(int i=n-1; i>=0; --i)
            matrix[start+n-1][start+i] = number++;
        if(n>2)
        for(int i=n-2; i>=1; --i)
            matrix[start+i][start] = number++;
    }
};

int main()
{
    int n;
    Solution a;
    while(cin>>n)
    {
        auto re = a.generateMatrix(n);
        for(auto const& i: re)
        {  
            for(auto const& j: i)
                cout<<j<<" ";
            cout<<endl;
        }
    }
}