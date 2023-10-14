#include<iostream>
using namespace std;

class NetherMaxMin
{
	public:
		int num;
		int findNUM(int n,int *arr)
		{
			int a,b,c,i=2;
			a=arr[0];
			b=arr[1];
			c=arr[2];
            while(i<n)
            {
            	if(b<a&&a<c||c<a&&a<b)
			    {
				    return a;
			    }
			    else if(a<b&&b<c||c<b&&b<a)
			    {
				    return b;
			    }
			    else if(a<c&&c<b||b<c&&c<a)
		    	{
			    	return c;
		    	}
		    	else
		    	{
				    if(a==b)
				    {
				    	a=arr[i+1];
					}
					else if(b==c)
					{
						b=arr[i+1];
					}
					else
					{
						c=arr[i+1];
					}
					i++;
			    }
			}
			return -1;
		}
};

int main()
{
	int n,i;
	cout<<"Enter the size of array: ";
	cin>>n;
	if(n<3)
	{
		cout<<"Minimum number of elements required to perform the given question is 3.Please try again.";
		return 0;
	}
	int arr[n];
	cout<<"\nEnter the values for the array:\n";
	for(i=0;i<n;i++)
	{
		cout<<i+1<<"- value: ";
		cin>>arr[i];
		cout<<"\n";
	}
	NetherMaxMin obj;  //Object definition
	int x=obj.findNUM(n,&arr[0]);
	if(x!=-1)
	cout<<"The number that is neither minimum nor maximum is: "<<x<<endl;
	else
	cout<<"A number which is neither maximum nor minimum cant be found with the given input";
}
