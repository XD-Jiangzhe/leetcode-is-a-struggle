/*
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {

        return isMatchCore(s, p);
    }

    bool isMatchCore(string s, string p)
    {
        if(p.empty())return s.empty();

        if(p[1]=='*')
        {
            if(s[0]==p[0] || (!s.empty() && p[0] =='.'))
                return isMatchCore(s, p.substr(2))
                    ||isMatchCore(s.substr(1), p.substr(2))
                    ||isMatchCore(s.substr(1), p);
            else   
                return isMatchCore(s, p.substr(2));
        }   
        if((p[0]==s[0])||(!s.empty() && p[0]=='.') )
        {
            return isMatchCore(s.substr(1), p.substr(1));
        }
        return false;

    }
};

int main()
{
    Solution aa;
    string s,p;
    while(cin>>s>>p)
    {
        if(aa.isMatch(s,p))
            std::cout<<"true"<<std::endl;
        else 
            std::cout<<"false"<<std::endl;
    }
}