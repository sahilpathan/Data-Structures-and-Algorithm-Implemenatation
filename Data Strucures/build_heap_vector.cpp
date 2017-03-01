#include <iostream>
#include <vector>
using namespace std;

void max_heapify(vector <int> &arr,int i) {
  int left = 2*i+1;
  int right = 2*i+2;
  int largest=i;
  if (left < arr.size() && arr[left] > arr[largest])
       largest = left;
  //else{largest = i;}

  if(right < arr.size() && arr[right] > arr[largest])
      largest = right;
  //else {largest = i;}

  if (largest != i)
  {
      std::swap(arr[i],arr[largest]);
      max_heapify(arr,largest);
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

  for(int i=len/2-1; i>=0; i--)
  {

    max_heapify(arr,i);
  }
  printArr(arr);
  return 0;
}
/*
30
26
16
25
15
9
13
12

*/