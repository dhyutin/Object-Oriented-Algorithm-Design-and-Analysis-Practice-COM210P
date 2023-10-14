#include<iostream>
using namespace std;

int fun1(int *arr,int i)
{
    int sum=0,temp=0;
	while(1)
	{
		temp=sum;
		sum = sum + arr[i];          //O(n) where n is the number of insertions
		if(sum - temp ==-1)
		{
			return i+1;
		}
		i++;
	}
}

int main()
{
	int arr[1000];
	cout<<"\n-----------------------------------------------------------\n";
	cout<<"CONSTRAINTS:\n";
	cout<<"(i) user should not enter the size of the array  \n";    
    cout<<"(ii) user should not enter -1 as it is used delimiter. \n";
    cout<<"User enters until some time after which the user must enter -1 only and no other integer,the user can enter -1 any number of times.\n";
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
	for(int j =i;j<1000;j++)
	{
		arr[j]=-1;
	}
	cout<<"Position of first -1 : "<<fun1(arr,0);
}
