#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

class Solution {
public:
	template<typename T>
	bool next_permutation(vector<T>& v1);
    vector<vector<int>> permuteUnique(vector<int>& nums) {
  		vector<vector<int>> re;
  		sort(nums.begin(),nums.end());
  		do
	{
		re.push_back(nums);
	}while(next_permutation<int>(nums));



  		return re;      
    }
};

template<typename T>
bool Solution::next_permutation(vector<T> &v1)
{
	if(v1.empty()||v1.size() == 1)
		return false;

	typedef typename vector<T>::iterator Iter;
	do{
		Iter i,ii,j=v1.end();
		for(ii=--v1.end(), i=ii-1; i != v1.begin()-1; --i, --ii)
		{
			if(*i < *ii)
				break;
		}

		if(i == v1.begin()-1)
			break;

		while(!(*--j > *i) );
		iter_swap(j, i);

		reverse(ii, v1.end());
		return true;
	}while(0);
		
		reverse(v1.begin(), v1.end());
		return false;
}

template<typename T>
struct display
{	
	void operator()(const T& t)
	{
		cout<<t<<" ";
	}
};


int main()
{
	Solution S;
	vector<int> v{2,2,1,1};
	vector<vector<int>>re =  S.permuteUnique(v);

	for(int i =0 ;i<re.size(); ++i)
	{
		for_each(re[i].begin(), re[i].end(), display<int>());
		cout<<endl;
	}


	return 0;
}
