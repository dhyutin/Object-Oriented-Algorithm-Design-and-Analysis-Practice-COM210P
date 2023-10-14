#include<iostream>
#include <chrono> 
#include <algorithm> 
#include <cstdlib>
#include<time.h>
using namespace std;
using namespace std::chrono;  //to use clock

class hybrid_sort
{
	public :
		int a[1000];
		int new_a[1000];
		int s=1000;
		int dur[10];
};

class hybrid : public hybrid_sort
{
	public:
		void swap(int *m, int *n);
		void bubble_sort(int *p, int n,int l) ;
		void insertion_sort( int *p, int n,int l);
		void selection_sort(int *p, int n,int l);
		void merge_arr(int a[], int l, int m1,int m2, int r,int na[]);
		void mergesort(int a[], int l, int r,int k,int na[]);
		void insert_values();
		void count_time();
		int final();	
};

void hybrid :: swap(int *m, int *n)  // to interchange positions of 2 elements.
{
	
    int temp = *m; 
    *m = *n; 
    *n=temp; 
}
void hybrid :: bubble_sort(int *p, int n,int l)  // bubble sort method- repeated swapping of adjacent elements in correct order.
{
	for (int i=l;i<l+n;i++)
	{
		for(int j=l;j<l+n-i-1;j++)
		{
			if(p[j+1]<p[j])
			   swap(&p[j],&p[j+1]);
		}
	}
}
void hybrid :: insertion_sort( int *p, int n,int l) // insertion sort method - each element from the remaining unsorted array is placed in correct position in the preceding sorted array.
{

    for(int i=l+1;i<l+n;i++)
	{ 
        int temp=p[i]; 
        int j=i-1;
        while (j>=0 && p[j]>temp)
		{ 
            p[j+1] =p[j]; 
            j=j-1; 
        } 
        p[j+1]=temp; 
    }
}
void hybrid :: selection_sort(int *p, int n,int l) //selection sort method - repeated placing of lowest number from the remaining array in beginning for each pass.
{
    for(int i=l;i<l+n-1;i++)  
    {  
        int min=i;  
        for(int j=i+1;j<l+n;j++) 
		{ 
            if(p[j]<p[min])  
                min = j;
        }
        swap(&p[i],&p[min]);
    }
}
void hybrid :: merge_arr(int a[], int l, int m1,int m2, int r,int na[])  //l=left,r=right,m=middle  , all inclusive
{
   int i=l, j=m1+1, h=m2+1, k=l;  // k points to each element to be checked
   while(i<m1+1 && j<m2+1 && h<r+1) 
   {
        if(a[i] < a[j]) 
	    {
	  	    if(a[i] < a[h])
	  	    {
	  	    	na[k]=a[i];
	  	    	i++;
			}
			else
			{
				na[k]=a[h];
	  	    	h++;
			}
        }
	    else
	    {
	    	if(a[j] < a[h])
	  	    {
	  	    	na[k]=a[j];
	  	    	j++;
		    }
			else
			{
				na[k]=a[h];
	  	    	h++;
			}       
        }
        k++;
   }
   
     
    while (i<m1+1 && j<m2+1)   //first and second array  have remaining values
    {  
        if(a[i]<a[j])  
            na[k++]=a[i++];  
        else
            na[k++]=a[j++]; 
    }  
  
    
    while (j<m2+1 && h<r+1)  // second and third array have remaining values  
    {  
        if(a[j]<a[h]) 
            na[k++]=a[j++]; 
        else 
            na[k++] =a[h++];   
    }  
  
      
    while (i<m1+1 && h<r+1)  //  first and third array have remaining values
    {  
        if(a[i]<a[h]) 
            na[k++]=a[i++]; 
        else 
            na[k++] =a[h++]; 
    }  
    
    while(i<m1+1)          //extra elements in first array     
      na[k++] = a[i++];
    while(j<m2+1)          //extra element in second array    
      na[k++] = a[j++];
    while(h<r+1)           //extra element in third array     
      na[k++] = a[h++];

}
void hybrid:: mergesort(int a[], int l, int r,int k,int na[]) 
{
   if(r-l>19) 
   {
        int m1 = l+(r-l)/3;
        int m2 = l+(2*(r-l))/3;
        mergesort(a, l, m1,k,na);
        mergesort(a, m1+1, m2,k,na);
        mergesort(a, m2+1, r,k,na);
        merge_arr(a, l, m1, m2,r,na);
   }   
    else if(k==1)   
        bubble_sort(na,r-l+1,l);
     
	else if(k==2)   
        insertion_sort(na,r-l+1,l);
        
    else if(k==3)   
        selection_sort(na,r-l+1,l);
}

void hybrid :: insert_values()
{
		for(int i=0;i<s;i++)
		a[i]=rand();
}

void hybrid :: count_time()
{
		int opt=1;
	while(opt<4)
	{   
	    for(int i=0;i<s;i++)
	        new_a[i]=a[i];	
	 	
		cout<<endl;   	

	    auto start = steady_clock::now();
	    mergesort(a,0,s-1,opt,new_a);
	    auto stop = steady_clock::now(); 
	    auto duration = duration_cast<nanoseconds>(stop - start); 
	    dur[opt-1]=duration.count();
	    
	    string sort;
	    switch(opt)
	    {
	    	case 1:
	    		 sort="Bubble";
	    		break;
	    	case 2:
	    		 sort="Insertion";
	    		break;
	    	case 3:
	    		 sort="Selection";
	    		break;	
		}
  
        cout<<"Time taken by hybrid + "<<sort<<" : "<<dur[opt-1]<< " nanoseconds" << endl;         
        opt++;
	}  
	return;
}

int hybrid :: final()
{
	int min=0;  
    for(int j=1;j<3;j++) 
	{ 
        if(dur[j]<dur[min])  
            min = j;
    }
    return min;	
}

int main()
{
	//int s=1000;
	//int a[s],new_a[s],dur[10];
	
	srand(time(0));  // to generate different set of no.s every time program is run
	hybrid h1;
	h1.insert_values();	
    h1.count_time();
    int BEST = h1.final();
    string best;
    switch(BEST)
	    {
	    	case 0:
	    		 best="Bubble";
	    		break;
	    	case 1:
	    		 best="Insertion";
	    		break;
	    	case 2:
	    		 best="Selection";
	    		break;	
		}
  
        cout<<"\nBest hybrid sorting : Merge + "<<best<<endl; 
	
	return 0;
}
