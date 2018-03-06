#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int tail = s.size()-1;
        while(tail>0&&s[tail]==' ') --tail;
        s = s.substr(0, tail);
        int pos = s.find_last_of(' ');
        return tail-pos-1;
    }
};