/*
77. Combinations

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> result;
        vector<int> now;
        findAllComAtThisPos(result, now, k, 0, 0, n);
        
        return result;    
        
    }

    void findAllComAtThisPos(vector<vector<int>>& result, vector<int> &now, int k, int pos ,int prev, int n)
    {
        if(pos == k)
        {
            result.push_back(now);
            return;
        }
        for(int i=prev+1; i<=n; ++i)
        {
            now.push_back(i);
            findAllComAtThisPos(result, now, k, pos+1, i, n);
            now.pop_back();
        }
    }
};

int main()
{
    Solution a;
    vector<vector<int>> re = a.combine(4, 2);
    for(auto const& i:re)
    {
        for(auto const& j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}