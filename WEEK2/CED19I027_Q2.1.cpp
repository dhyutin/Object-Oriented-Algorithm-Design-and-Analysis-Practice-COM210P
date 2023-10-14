#include<iostream>
using namespace std;

int fun(int* arr,int upper,int lower)
{
	int i=0;    
	while(1)
	{
		if(arr[i]==-1)             //O(n) where n is the number of insertions
		{
			break;
		}
		i++;
		
	}
	return i+1;
}


int main()
{
	cout<<"\n-----------------------------------------------------------\n";
	cout<<"CONSTRAINTS:\n";
	cout<<"(i) user should not enter the size of the array  \n";    
    cout<<"(ii) user should not enter -1 as it is used as delimiter. \n";
    cout<<"User enters until some time after which the user must enter -1 only and no other integer,the user can enter -1 any number of times.\n";
    cout<<"Enter 0 to stop"<<endl;
    
    int arr[1000];
    int i=0;
    while(1) 
    {
    	
		cout<<"Enter an integer"<<endl; 
    	cin>>arr[i]; 
    	if(arr[i]==0) 
    	{
    		cout<<"No more inputs will be taken"<<endl; 
			break; 
		}
    	if(arr[i]==-1) 
    	{
			cout<<"Only enter -1 from now on"<<endl; 
		}
		i=i+1; 
	}
	int upper = sizeof(arr)/sizeof(arr[0]) -1 ;
	
	int lower = 1;
	
cout<<"Position of first -1 : "<<fun(arr,upper,lower);

	return 0;                    
}
