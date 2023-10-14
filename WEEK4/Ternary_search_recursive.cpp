#include <iostream>
using namespace std;

class ternary_search
{
	public:
		int arr[100];
		int size;

};
class search :public ternary_search
{
	public:
		void selection_sort(int* arr,int size);
		int t_s_r(int l,int r,int x,int* arr);
};

		void search :: selection_sort(int* arr,int size)
		{
			int i,j,min;
			
			for(i=0;i<size-1;i++)
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
		
		int search :: t_s_r(int l,int r,int x,int* arr)
		{
			if(r>=l)
			{
				int mid_left= l + (r-l)/3;
				int mid_right = r - (r-l)/3;
				
				if(arr[mid_left]==x) return mid_left;
				if(arr[mid_right]==x) return mid_right;
				
				if(x < arr[mid_left]) return t_s_r(l,mid_left -1 ,x,arr);
				
				else if( x > arr[mid_right]) return t_s_r(mid_right +1,r,x,arr);
				
				else return t_s_r(mid_left +1,mid_right -1 ,x,arr);
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
	int a= s1.t_s_r(0,s1.size,x,s1.arr);
	if(a!=-1)
	cout<<"Element found" ;
	else
	cout<<"Element not found";
	
	return 0;
}
