#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class scheduling
{
	public:
		vector<int> sc;
		int cnt=0;
};

class sche : public scheduling
{
	public:
		void display();
		void insertion( int p[],int s[],int job[], int n);
		int schedule(int s[],int f[],int j[], int n);	
};

void sche :: display() 
{
    for(auto i=sc.begin();i!=sc.end();i++)
        cout<<*i +1<<" ";
		
	cout<<endl;	    
}

void sche :: insertion( int p[],int s[],int job[], int n) // insertion sort method - each element from the remaining unsorted array is placed in correct position in the preceding sorted array.
{
	int i,k,j; 
    for (i=1;i<n;i++)
	{ 
        int temp1=p[i];
		int temp2=s[i]; 
		int temp3=job[i];
        j=i-1;
        while (j>=0 && p[j]>temp1)
		{ 
            p[j+1] =p[j];
			s[j+1] =s[j]; 
			job[j+1] =job[j];
            j=j-1; 
        } 
        p[j+1]=temp1; 
        s[j+1]=temp2;
        job[j+1]=temp3;
    }
    
}

int sche :: schedule(int s[],int f[],int j[], int n)
{
	
	insertion(f,s,j,n);  //sort according to finish time
	sc.push_back(j[0]);
	int t=0,m=0;
	while(m<n)
	{
		int t=m;
		while(m<n && s[m]<f[t])  // find starting job whose start time greater than previous 
			m++;
		
		if(m<n)
		    sc.push_back(j[m]);		
    }	
	return sc.size();    
}

int main()
{
	int n;
	sche s1;
	cout<<"Enter no. of jobs to be scheduled: ";
	cin>>n;
	
	int s[n],f[n],j[n];
	
	for(int i=0;i<n;i++)
	{
		cout<<endl;
		cout<<"\nFor job "<<i+1;
		cout<<"\nEnter start time: ";
		cin>>s[i];
		cout<<"Enter finish time: ";
		cin>>f[i];
		j[i]=i;		
	}
	
	
	cout<<"\nThe max no. of jobs is: "<<s1.schedule(s,f,j,n)<<endl;
	s1.display();
	return 0;
}
