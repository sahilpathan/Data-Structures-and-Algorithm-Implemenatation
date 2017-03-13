#include <iostream>
#include <vector>

using namespace std;
int merge(vector<int> &v,int p,int q,int r)
{
	int n1 = q-p+1;
	int n2 =r-q;

//copy data to the left and right sublists
	int L[n1] , R[n2];
	for (int i=0;i < n1;i++)
	{
		L[i] = v[p+i];
	}
	for(int j=0; j < n2;j++)
	{
		R[j] = v[q+1+j];
	}

//merge L and R into v
	int i=0; int j=0; int k =p;
	while( i< n1 && j< n2)
	{
		if(L[i] <= R[j])
		{
			v[k] = L[i];
			i++;
			//k++;
		}
		else
		{
			v[k] = R[j];
			j++;
			//k++;
		}
		k++;
	}
// move the leftovers into v if any 
while( i < n1 )
{
	v[k] = L[i];
	i++;
	k++;
}
while( j< n2 )
{
	v[k] = R[j];
	j++;
	k++;
}
	
}

int mergeSort (vector <int> &v,int p,int r)
{
	if(p<r)
	{
		int q = p+(r-p)/2;
		mergeSort(v,p,q);
		mergeSort(v,q+1,r);

		merge(v,p,q,r);
	}
} 
int main(int argc, char const *argv[])
{
	vector<int> v = {8,5,7,3,1,9,2,11,10,4,6};

	mergeSort(v,0,v.size()-1);
	cout<<"Sorted :"<<endl;
	for(int i : v)
	{
		cout<<i<<endl;
	}

	return 0;
}