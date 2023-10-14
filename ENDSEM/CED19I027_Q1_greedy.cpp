#include<iostream>
using namespace std;

class truck_container
{
	public:
		int containers;      //no of containers
		int x;                 // capacity of truck
		int arr[100];         //to store weights of each container
	   		
};

class truck : public truck_container
{
	public:
		int cont_trk(int j,int x);
		void merge_sort(int l,int r);
		int merge(int l,int m,int r);		
};


//Sort the containers based on their weights . TIME COMPLEXITY = O(nlogn) , where n is the number 0f containers
//MERGE SORT
int truck :: merge(int l,int m,int r)
{
	int s1,s2,i,j,k;
	s1=m-l+1;
	s2=r-m;
	int arr1[s1],arr2[s2];
	for(i=0;i<s1;i++)
	{
		arr1[i]=arr[l+i];
	}
	for(j=0;j<s2;j++)
	{
		arr2[j]=arr[m+1+j];
	}
	i=0;
	j=0;
	k=l;
	while(i+j!=s1+s2)
	{
		if((arr1[i]<arr2[j] && i<s1) || j>=s2)
		{
			arr[k]=arr1[i];
			i++;
		}
		else
		{
			arr[k]=arr2[j];
			j++;
		}
		k++;
	}
}

void truck :: merge_sort(int l, int r)
{
	if(l>=r)
	{
		return;
	}
	int m=l+(r-l)/2;
	merge_sort(l,m);
	merge_sort(m+1,r);
	merge(l,m,r);
}

//Greedy - We take the least weighed container and put it in the truck first in order to put maximum number of containers in truck
int truck :: cont_trk(int j,int x)
{
	int i=0,temp=x;
	while(temp>=arr[i] && i<=containers)  //If the particular container is <= the weight remaining to be filled in truck , we include it in the truck
	{
	    temp=temp-arr[i];
		i++;		
	}
	return i;
}

int main()
{
	
	truck t1;
	cout<<"Enter the maximum capacity the truck can hold: "; 
	cin>>t1.x;
	
	cout<<"Number of different containers: "; 
	cin>>t1.containers;
	while(t1.containers<0)
	{
		cout<<"Number of different containers cannot be negative";
		main();
	}

	for(int i=0;i<t1.containers;i++)  //taking in values of weights of containers //T.C=O(dno)
	{
		cout<<"Enter weight of container "<<i+1<<" : ";
		cin>>t1.arr[i];
	}
	
	//We first sort the elements based on weights to implement greedy => Time complexity = O(nlogn) , where n = number of containers
	t1.merge_sort(0,t1.containers-1);  

     // We keep including the container with smallest weight to attain max number of containers   	
 	cout<<"MAX NUMBER OF CONTAINERS THAT CAN FIT IN TRUCK = "<<t1.cont_trk(0,t1.x);  
		return 0;
}
