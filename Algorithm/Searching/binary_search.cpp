#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int>&v,int low,int high,int key)
{
	if(high>=low)
	{
		// lookup- https://research.googleblog.com/2006/06/extra-extra-read-all-about-it-nearly.html
		//int mid = low + ((high - low) / 2);
		//right shift by 1 is divide by 2
		int mid = ((unsigned int)low+(unsigned int)high) >> 1;

		if(key == v[mid]) return mid;
		else if(key > v[mid]) return binary_search(v,mid+1,high,key);
		else return binary_search(v,low,mid-1,key);
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	
	vector <int> v ={7,8,9,11,15,20,36};
	int search_key = 15;
	
	int x = binary_search(v,0,v.size()-1,search_key);

	(x== -1) ? cout<<"NOT Present" : cout<<"Search Key is Present at :"<<x;

	return 0;
}