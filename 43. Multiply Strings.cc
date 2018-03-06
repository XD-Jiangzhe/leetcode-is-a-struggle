#include <vector>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
	两个大数做乘法

	最终的长度为 i+j i和j都从 0 开始算，如果最后有进位 则多一位

	要注意的是 相乘部分的 进位，每次循环一轮之后 在头部 加一位进位 ，全部循环完之后 加上 最后的一位进位

*/

class Solution {
public:
    string multiply(string num1, string num2) {

    	string mul(num1.size()+num2.size()-1, '0');

    	int carry = 0;
    	for(int i = num1.size()-1; i>=0; --i)
    	{
    		if(carry != 0)
    		{
    			mul[i] += carry;	   
    		}

    		carry = 0;
    		for(int j = num2.size()-1; j >=0; --j)
    		{
    			int temp = carry;
    			carry = (mul[i+j]-'0'+(num1[i]-'0')*(num2[j]-'0')+temp)/10;
				mul[i+j] = (mul[i+j]-'0'+(num1[i]-'0')*(num2[j]-'0')+temp)%10+'0';
    		}	
    	}
    	if(carry != 0)
    		{
    		/*	string a(1,'0'+carry);
    			mul =a+mul;*/
    			mul.insert(mul.begin(), '0'+carry);		//这里千万记住 加了insert 之后的迭代器 会变得无效 ！！！！、
    		
    		}
    	auto i = mul.begin();
    	for(; i!= mul.end(); ++i)
    	{
    		if(*i != '0')
    			break;
    	}
    	if(i == mul.end())
    		return "0";
    	else
    		return string(i, mul.end());
    
    }
};


int main()
{
	Solution A;

	string num1, num2;
	while(cin>>num1>>num2)
		cout<<A.multiply(num1, num2)<<endl;

	return 0;
}