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
		void merge_arr(int a[], int l, int m, int r,int na[]);
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
void hybrid :: merge_arr(int a[], int l, int m, int r,int na[])  //l=left,r=right,m=middle
{      
   int i=l, j=m+1, k=l;  
   while(i<m+1 && j<(r+1)) 
   {
      if(a[i] <= a[j]) 
	  {
         na[k] = a[i];
         i++;
      }
	  else
	  {
         na[k] = a[j];
         j++;
      }
      k++;
   }
   while(i<m+1)   //extra element in left array      
      na[k++] = a[i++];

   while(j<r+1)    //extra element in right array    
      na[k++] = a[j++];

}

void hybrid :: mergesort(int a[], int l, int r,int opt,int na[]) 
{
   if(r-l>19) 
   {
        int m = l+(r-l)/2;
        mergesort(a, l, m,opt,na);
        mergesort(a, m+1, r,opt,na);
        merge_arr(a, l, m, r,na);
   }   
    else if(opt==1)   //bubble
        bubble_sort(na,r-l+1,l);
     
	else if(opt==2)   //insertion
        insertion_sort(na,r-l+1,l);
        
    else if(opt==3)   //selection
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
}

int hybrid :: final()
{
	int min=0;  
    for(int j=1;j<3;j++) 
	{ 
        if(dur[j]< dur[min])  
            min = j;
    }
    return min;	
}

int main()
{
//	int s=1000;
	//int a[s],new_a[s],dur[10];
	hybrid h1;
	 	
	srand(time(0));  // to generate different set of no.s every time program is run
		
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
