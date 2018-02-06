#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

template<typename T>
bool next_permutation(vector<T> &v1)
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

template <typename T>
bool prev_permutation(vector<T>& v2)
{
	typedef typename vector<T>::iterator Iter;
	Iter i,ii,j= v2.end();

	do{

		for(ii = --v2.end(), i = ii-1; i!= v2.begin()-1; --i, --ii)
		{
			if(*i > *ii)
				break;
		}
		if(i == v2.begin()-1)
			break;

		while(!(*--j < *i));
		iter_swap(j, i);
		reverse(ii, v2.end());

		return true;
	}while(0);

	reverse(v2.begin(), v2.end());
	return false;
}

template<typename T>
void display(const T& t)
{
	cout<<t<<" ";
}

int main()
{
	vector<int> test{1,2,3,4};

	do{

		for_each(test.begin(), test.end(), display<int>);
		cout<<endl;
	}while(next_permutation<int>(test));
	cout<<endl;

	reverse(test.begin(), test.end());
	do{

		for_each(test.begin(), test.end(), display<int>);
		cout<<endl;
	}while(prev_permutation<int>(test));

	vector<int> t{0,1};
	double count1;
	for( int i =0; i<1000 ;i++)
	{
		random_shuffle(t.begin(), t.end());
		if(*(t.begin()) == 0 )
			count1++;
	}

	cout<<setprecision(10)<<count1/1000<<endl;
	return 0;
}