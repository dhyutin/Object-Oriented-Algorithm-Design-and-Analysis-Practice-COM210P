#include <iostream>
using namespace std;

int pivpos[100];      //to store left and right pivot values

class quick_sort
{
	public:
		int arr[1000];
};
class quick : public quick_sort
{
	public:
		void new_arr(int a[],int n);
		void partition(int low, int high);
		void quicksort(int first, int last);
		void swap(int* a, int* b);
		void display(int n);
};

void quick :: new_arr(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		arr[i]=a[i];
	}
	
}


void quick :: swap(int* a, int* b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

void quick :: quicksort(int first, int last)
{   
   if (first < last) 
   {  
       int lp, rp; 
       partition(first,last); 
       lp=pivpos[0];
       rp=pivpos[1];
       quicksort(first, lp - 1);
       quicksort( lp + 1, rp - 1); 
       quicksort(rp + 1,last);   
   } 
    
} 

void quick :: partition(int f, int l) 
{ 
    if (arr[f] > arr[l])           // if first element > last element, we have to switch bcoz
       swap(&arr[f], &arr[l]);     //  LP should be lesser than RP 


    int j = f+1, i=l-1, k=f+1 ;     // j will return index of 1st partition, it holds left index
                                    // g will return index of 2nd partition, it holds right index
                                    // k points to the element to be checked ( from l-> R)

    int lp = arr[f];   // lp = left pivot
    int rp = arr[l];  // rp = right pivot.

    while (k <= i) 
    { 
        if (arr[k] < lp)  // if element is less than the left pivot 
        { 
            swap(&arr[k], &arr[j]);   // for small window  (maintained after LP)
            j++;             
        } 
        
        else if (arr[k] >= rp)   // if elements are >= to the right pivot
        {
            while (arr[i] > rp && k < i)   //to keep building large window from right
            i--; 
            swap(&arr[k], &arr[i]); 
            i--; 
            
            if (arr[k] < lp)     // if the swapped element is lesser than LP
            { 
                swap(&arr[k], &arr[j]); 
                j++; 
                
            } 
        } 
        k++;    
    } 
    j--;      // bring index back to their appropriate positions. 
    i++;      // j=last element of SW,   g=1st element of LW
    
    swap(&arr[f], &arr[j]);    //SWAP(LP and last element of SW)
    swap(&arr[l], &arr[i]);    //SWAP(rP and first element of lW)
    pivpos[0] = j; 
    pivpos[1] = i; 
} 

void quick :: display(int n)
{
    cout << "\nThe sorted array is : "; 
    for (int i = 0; i < n; i++) 
       cout << arr[i] << " "; 
}

    
int main()
{ 
    int n;
    quick q1;
    cout<<"Enter size of array : ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
    	cout<<"\nEnter element "<<i+1<<" : ";
    	cin>>a[i];
	}
    q1.new_arr(a,n);
    q1.quicksort(0,n-1); 
    q1.display(n);     
    return 0;  
} 
