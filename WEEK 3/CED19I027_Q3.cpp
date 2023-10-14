#include <iostream>
using namespace std;

int subset_sum(int*arr,int size,int k)
{
	if(k==0) return 1;                                                              //O(2^n) where n is the number of elements in set
	if(size==0) return 0;
	
	return subset_sum(arr,size -1,k) || subset_sum(arr,size-1, k - arr[size-1]);
}

int main()
{
	int size;
	cout<<"Enter array size :";
	cin>>size;
	int arr[size],k;
	for(int i =0;i<size;i++)
	{
		cout<<"Enter value to be added into array : ";
		cin>>arr[i];
	}
	cout<<"Enter the value of subset sum :";
	cin>>k;
	
	if(subset_sum(arr,size,k)==1)
	{
		cout<<"A subset with the given sum is present";
	}
	else
	{
		cout<<"A subset with given sum is not present";
	}
	return 0;
}
