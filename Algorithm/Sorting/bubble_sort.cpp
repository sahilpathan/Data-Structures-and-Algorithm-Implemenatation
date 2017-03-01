#include <iostream>
#include <vector>


using namespace std;
void bubble_sort(vector<int> &v)
{
	bool isSwaped = false;	
	//int len = v.size();
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v.size()-i-1; ++j)	//last i values are alredy sorted 
		{
			if(v[j] > v[j+1]) 
				{
					std::swap(v[j],v[j+1]);
					isSwaped = true;	
				}		
		}
		if (isSwaped == false)
		{
			break;	//nothing isSwaped in first pass then list is sorted already
		}
	}
}
int main()
{

	vector<int> v ={5,8,2,1,4,3};

	bubble_sort(v);

	cout<<"Sorted :"<<endl;
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<endl;
	}

}   