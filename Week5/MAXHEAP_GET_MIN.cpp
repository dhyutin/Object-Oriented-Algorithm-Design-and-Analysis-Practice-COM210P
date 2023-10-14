#include<iostream>
using namespace std;

class get_min_heap
{
	public:
		int arr[1000];
		int a_min[2];
		
};

class minimum : public get_min_heap
{
	public:
		void new_arr(int a[],int n);
		void get_min(int n);
		void answer();
};

void minimum :: new_arr(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		arr[i]=a[i];
	}
	
}

void minimum :: get_min(int n)
{
	int m1,m2;
    m1=n/2;
	for(int i=m1+1;i<n;i++)
	{
		if(arr[i]<arr[m1])
		    m1=i;
	}
	
	m2=n/2;
    if(m1 == n-1)
     m2=n/4;
	for(int i=m2+1;i<n;i++)
	{
		if(arr[i]<arr[m2] && i!=m1)
		    m2=i;
	}
	
	a_min[0]=arr[m1];
	a_min[1]=arr[m2];
}

void minimum :: answer()
{
    for(int i=0;i<2;i++)
    	cout<<"\nMinimum "<<i+1<<" of max heap : "<<a_min[i]<<endl;	
}

int main()
{
	int n;
	minimum m;
    cout<<"Enter size of heap : ";
    cin>>n;
    int a[n];
    cout<<"\nEnter elements of max heap"<<endl;
    for(int i=0;i<n;i++)
    	cin>>a[i];
    m.new_arr(a,n);
    m.get_min(n);
    m.answer();
	return 0;
}
