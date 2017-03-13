#include <iostream>
#include <vector>
using namespace std;

/*
	take last element as a pivot and place it at it's correct position
	elements to the left side of pivot are smaller than pivot
	elements to the right side of pivot are grater than pivot 
*/
int partition(vector<int> &v,int p,int r)
{
	int pivot = v[r];	
	int i =p-1;

	for (int j = p; j <= r-1 ; ++j)
	{
		if (v[j] <= pivot)	// if current element is smaller than or equal to pivot 
		{
			i++;
			swap(v[i],v[j]);
		}
	}
	swap(v[i+1],v[r]);
	return (i+1);
}

int quickSort(vector<int> &v,int p,int r)
{
	if(p<r)
	{
		// q is partiotion Index
		int q = partition(v,p,r);	
		quickSort(v,p,q-1);
		quickSort(v,q+1,r);
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	vector<int> v ={8,5,7,3,1,9,2,11,10,4,6};

	quickSort(v,0,v.size()-1);

	cout<<"Sorted :"<<endl;
	for(int i : v)
	{
	    cout<<i<<endl;
	}
	return 0;
}

