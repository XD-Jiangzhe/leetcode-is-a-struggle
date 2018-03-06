/*
#include <vector>
#include <string>
#include <iostream>

using namespace std;
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        
        if(a.empty())
            return b;
        else if(b.empty())
            return a;
        
        int lengtha = a.size();
        int lengthb = b.size();
        int finallength = max(lengtha, lengthb)+1;

        a = string(finallength-lengtha, '0')+a;
        b = string(finallength-lengthb, '0')+b;
        int carry = 0;

        string result(finallength,'0');

        while(finallength>=1)
        {
            int cura = a[finallength-1]-'0';
            int curb = b[finallength-1]-'0';
            int resultDigit = cura+curb+carry;

            if(resultDigit >= 2)
                carry = 1; 
            else 
                carry = 0;

            result[finallength-1] = '0' + resultDigit%2;
            --finallength;
        }
        for(carry = 0; carry<result.size()-1; ++carry)
        {
            if(result[carry]!='0')
                break;
        }

        return result.substr(carry);
    }
};


int main()
{
    string a,b;
    Solution c;
    while(cin>>a>>b)
    {
        cout<<c.addBinary(a,b)<<endl;
    }
}