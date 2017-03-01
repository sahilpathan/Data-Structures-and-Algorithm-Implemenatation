#include <iostream>
#include <vector>
using namespace std;

void max_heapify(vector <int> &arr,int i,int length) {
  int left = 2*i+1;
  int right = 2*i+2;
  int largest=i;
  if (left < length && arr[left] > arr[largest])
       largest = left;
  //else{largest = i;}

  if(right < length && arr[right] > arr[largest])
      largest = right;
  //else {largest = i;}

  if (largest != i)
  {
      std::swap(arr[i],arr[largest]);
      max_heapify(arr,largest,length);
  }
}
void heap_sort(std::vector<int> &arr)
{
  // extract root one by one
  for (int i = arr.size()-1; i>=0; --i)   
  {
    std :: swap(arr[0],arr[i]);  //move root to the last position

    max_heapify(arr,0,i);

  }
}
void printArr(vector <int> &arr) {
  /* code */
  for(int i =0;i<arr.size();i++)
  std::cout << arr[i] << std::endl;
}
int main()
{
  vector <int> arr={15,25,13,12,26,9,16,30};
 int len =arr.size();
  
  //build_heap
  for(int i=len/2-1; i>=0; i--)
  {

    max_heapify(arr,i,len);
  }
  cout<<"AFTER build_heap :\n";
  printArr(arr);

  heap_sort(arr);
  cout<<"sorted :\n";
  printArr(arr);
  return 0;
}
/*
AFTER build_heap :
30
26
16
25
15
9
13
12
sorted :
9
12
13
15
16
25
26
30

*/