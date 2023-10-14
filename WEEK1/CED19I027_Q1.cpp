#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Max
{
	public:
		int max;
		int Maximum1(int n,int *arr)   //(n-1) comparisons-------METHOD 1
		{
			int i;
			max=arr[0];
			for(i=1;i<n;i++)
			{
				if(arr[i]>max)
				{
					max=arr[i];
				}
			}
			return max;
		}
		int Maximum2(int n, int *arr)  //(n-1) comparisons--------METHOD 2
		{
			int temp,j;
			for(j=0;j<n-1;j++)
			{
				if(arr[j]>arr[j+1])
				{
					temp=arr[j];
					arr[j]=arr[j+1];
					arr[j+1]=temp;
				}
			}
			max=arr[n-1];
			return max;
		}
		int Maximum3(int n,int *arr)  //(n-1) comparisons-----METHOD 3
		{
			int i,max1,max2;
			max1=arr[0];
			max2=arr[n/2];
			for(i=1;i<n/2;i++)
			{
				if(arr[i]>max1)
				{
					max1=arr[i];
				}
			}
			for(i=n/2;i<n;i++)
			{
				if(arr[i]>max2)
				{
					max2=arr[i];
				}
			}
		    if(max1>max2)
			{
			    return max1;
			}
			else
			{
			    return max2;
			}
		}
};

int main()
{
	int n,i;
	cout<<"Enter the size of array: ";
	cin>>n;
	int arr[n];
	cout<<"\nEnter the values for the array:\n";
	for(i=0;i<n;i++)
	{
		cout<<i+1<<"- value: ";
		cin>>arr[i];
		cout<<"\n";
	}
	Max m1;   //creating an object
	cout<<"The MAXIMUM VALUE OF THE GIVEN INPUT IS:  "<<m1.Maximum1(n,&arr[0])<<" (using method-1)"<<endl;
	cout<<"The MAXIMUM VALUE OF THE GIVEN INPUT IS:  "<<m1.Maximum2(n,&arr[0])<<" (using method-2)"<<endl;
	cout<<"The MAXIMUM VALUE OF THE GIVEN INPUT IS:  "<<m1.Maximum3(n,&arr[0])<<" (using method-3)"<<endl;
}
