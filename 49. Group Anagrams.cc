#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <map>

/*这题在于创建一个 字典序，然后将 字典序 中的数据 与之比较*/

using namespace std;

/*class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
    	vector<string> dict;
    	dict.assign(strs.begin(), strs.end());
        for(int i=0; i<static_cast<int>(strs.size()); ++i)
        {	
        	sort(dict[i].begin(), dict[i].end());
        }
        sort(dict.begin(), dict.end());
        auto tail = unique(dict.begin(), dict.end());
        dict.erase(tail, dict.end());

        vector<vector<string>> re(dict.size(), {""});

        for(auto const tempstr : strs)
        {
        	string tms = tempstr;
        	sort(tms.begin(), tms.end());
        	int i =0;
        	for( ; i<static_cast<int>(dict.size()); i++)
        	{
        		if(dict[i] == tms)
        			break;
        	}
        	if(i!= static_cast<int>(dict.size()))
        		re[i].push_back(tempstr);
        }

        sort(re.begin()	, re.end(), [](vector<string> r1, vector<string>r2){return r1.size()>r2.size();});
        for(int i=0; i<dict.size() ;++i)
        	sort(re[i].begin(), re[i].end());
        for(int i=0;i<dict.size();++i)
        {
        	re[i].erase(re[i].begin());
        }

    	return re;
    }

};*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
    	map<string, multiset<string>> dict;		//这里 mulitset 已经对 string 进行了排序,然后一个 字典对应了一系列 字符串 真的厉害。。。自己谢了一堆垃圾代码 。。。。
    	for(string s: strs)
    	{
    		string temp =s;
    		sort(s.begin(), s.end());
    		dict[s].insert(temp);
    	}

    	vector<vector<string>> re;
    	for(auto m : dict)
    	{
    		vector<string> mama(m.second.begin(), m.second.end());
    		re.push_back(mama);
    	}
    	return re;
    }
};


int main()
{
	vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> re;
	
	Solution a;
	re = a.groupAnagrams(strs);

	for(int i=0; i<re.size(); i++)
	{
		for(int j = 0;j<re[i].size();j++)
			cout<<re[i][j]<<" ";
		cout<<endl;
	}

	return 0;
}