/*
Implement pow(x, n).


Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
   double myPow(double x, int n) {
        if (n==0) return 1;
        double t = pow(x,n/2);
        if (n%2) {
            return n<0 ? 1/x*t*t : x*t*t;
        } else {
            return t*t;
        }
    }
};


int main()
{
    Solution a;
    cout<<a.myPow(0.00001,2147483647)<<endl;
    return 0;
}