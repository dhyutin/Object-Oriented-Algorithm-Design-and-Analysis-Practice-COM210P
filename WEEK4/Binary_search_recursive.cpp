#include <iostream>
using namespace std;



class binary_search
{
	public:
		int arr[100];
		int size;
};

class search : public binary_search
{
	public:
		void selection_sort(int* arr,int size);
		int b_s_r(int* arr, int l , int r , int x);
};

		void search :: selection_sort(int* arr,int size)
		{
			int i,j,min;
			
			for(i=0;i<size;i++)
			{
				min=i;
				for(j=i+1;j<size;j++)
				{
					if(arr[j]<arr[min])
					min=j;
					
					int k = arr[min];
					arr[min]=arr[i];
					arr[i]=k;
				}
			}
		}
		
		int search ::b_s_r(int* arr, int l , int r , int x)
		{
			if(r>=l)
			{
				int mid = l + (r-l)/2;
				
				if(arr[mid]==x)
				return mid;
				
				if(arr[mid]>x)
				return b_s_r(arr,l,mid-1,x);
				else return b_s_r(arr,mid+1,r,x);
			}
			return -1;
		}


int main()
{
	int x;
	search s1;
	cout<<"Enter the size of array :";
	cin>>s1.size;
	for(int i=0;i<s1.size;i++)
	{
		cout<<"Enter value : ";
		cin>>s1.arr[i];
	}
	s1.selection_sort(s1.arr,s1.size);
	
	cout<<"Enter the number to be searched: ";
	cin>>x;
	int a=-1;
	a = s1.b_s_r(s1.arr,0,s1.size-1,x);
	if(a!=-1)
	cout<<"Element found ";
	else
	cout<<"Element not found";
	
	return 0;

}
