#include <iostream>
using namespace std;

int num=0;

int display(int* ss,int subsize)
{
	num++;
	cout<<"Subset"<<num<<" : ";
	for(int j =0; j < subsize ; j++)
	{
		cout<<ss[j]<<" ";
	}
	cout<<endl;
}

void subset_sum(int* arr,int* ss,int size,int subsize,int subsum,int node,int k)
{
	if(subsum==k && subsize!=0)
	{
		display(ss,subsize);
		return;
	}
	else
	{
		for(int i = node ; i< size;i++)
		{
			ss[subsize]=arr[i];
			subset_sum(arr,ss,size,subsize+1,subsum+arr[i],i+1,k);
		}
	}
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
	
	int ss[size]; 
	
	cout<<"Subsets with sum ="<<k<<endl;
	subset_sum(arr,ss,size,0,0,0,k);

	
	if(num==0)
	{
		cout<<"A subset with the given sum is not present in the set";
	}
	
	return 0;
}
