#include<iostream>
using namespace std;

class if_exists{
	public:
		int psum;   //sum of pair
    	int f_ind;   //first index
    	int s_ind;   //second index
		int check_element(int a[],int n,int sum);
        int check_common(if_exists x, if_exists y);		
};

int compare(const void* a, const void* b)     // needed for inbuilt library function qsort() 
{                                             
    return ((*(if_exists*)a).psum - (*(if_exists*)b).psum);
}

int if_exists:: check_common(if_exists x, if_exists y)    // to check if there are same no.s present in 2 pairs
{
    if (x.f_ind == y.f_ind || x.f_ind == y.s_ind || x.s_ind == y.f_ind || x.s_ind == y.s_ind)
        return 0;
    return 1;
}

int if_exists::check_element(int a[], int n, int sum)   //to check if there are 4 elements
{
    
    int size = (n*(n - 1))/2;   // storing sum of all possible pair of elements in an psum and 
    if_exists data[size];       //save index of elements in pair of psum in data object array
 
    int i,j,k = 0;
    for (i = 0; i<n-1; i++)       // THIS HAS TIME COMPLEXITY= O(n^2)
	{
        for (j = i+1; j<n; j++) 
		{
            data[k].psum = a[i]+a[j];  // sum of 2 pairs
            data[k].f_ind = i;         // index of first element in pair
            data[k].s_ind = j;         // index of second element in pair
            k++;
        }
    }
 
    qsort(data, size, sizeof(data[0]), compare);     // quick sorting the data object array accoring to psum. 
                                                     //time complexity=> n^2.log(n^2) = O(n^2.logn)
    i = 0;
    j = size - 1;
    while (i < size && j >= 0)   // checking if any two psums==sum(k) . time complexity= O(n^2.logn)
	{
        if ((data[i].psum + data[j].psum == sum) && check_common(data[i], data[j])==1) // if the sum(k) is equal sum of psum and there are no common elements in pairs.
		{
            return 1;
        }
        else if (data[i].psum + data[j].psum < sum)  //if the sum is less than sum(k)
            i++;
        else
            j--;
    }
    
    return 0;
}

int main()
{
	int s,k,arr[100];
	cout<<"Enter size of array: ";
	cin>>s;
	cout<<"Enter array:"<<endl;
	for(int i=0;i<s;i++)
	   cin>>arr[i];
	cout<<endl;
	cout<<"Enter integer k: ";
	cin>>k;   
	if_exists obj;
	int check=obj.check_element(arr,s,k);  
	if(check)
	    cout<<"A set of 4 numbers whose sum is "<<k<<" is present"<<endl;
	else
	    cout<<"A Set of 4 number whose sum is "<<k<<" is NOT present"<<endl;	 
	return 0;
}
