#include <iostream>
using namespace std; 

class find_max_min
{
public:
void find_min1_min2_max(int a[],int size)
{
	
                         //Create Variables for Minimum1,minimum2,Maximum
	int min_1, min_2, max,i=0;    
	int m1,m2; 
	                   
                        //When the size of array is of the form 3n+1	
	if(size%3 == 1)  
	{
		if(size == 1)   //if the size of array = 1, that one element is only min1,min2,max
		{
			cout<<"\n min : min2 : max :"<<a[0];
			 return;
		}
		
                      //if size of array is not 1 but of form 3n+1, we initiate min1,min2,max to the first element and calculate values for the remaining 3n elements		
		else    
		{
			min_1 = a[0];
			min_2 = a[0];
			max = a[0];
			i = 1;    // we move i to 1 as we already assigned the value of first element to minimums and maximum
		}
	}
                      //When the size of the array is of the form 3n+2	
	else if(size%3 == 2) 
	{
	    if(size == 2) //if the size of array = 2, that one element is only min1,min2,max
	    {
	    	if(a[0]<a[1])
	    	{
			   cout<<"\n min :"<<a[0];
			   cout<<"\n min2 : max"<<a[1];
			   m2 = a[1];
		    }	
		   else
		    {
		    	cout<<"\n min :"<<a[1];
			    cout<<"\n min2 : max"<<a[0]; 
		    }
		
		   return;
        }
                      //if size of array is not 2 but of form 3n+2, we initiate min1,min2,max to the first element and calculate values for the remaining 3n elements
	   else 
	   {
	   	    if(a[0]<a[1])
	   	    {
	   	    	min_1 = a[0];
			    min_2 = a[1];
			    max = a[1];
			}
			else
			{
				min_1 = a[1];
			    min_2 = a[0];
			    max = a[0];
			}
			i = 2; // we move i to 2 as we already assigned the value of first element and second element to minimums and maximum
	   }
	}
                  // When the array size is of the form 3n ,we simply initiate values of min1,min2 and max
	else  
	{
		if(a[i] < a[i+1])     
	    {
		    if(a[i] < a[i+2])    
		    {
			    min_1 = a[i];
			    if(a[i+1] < a[i+2])     
			    {
				    min_2 = a[i+1];
				    max = a[i+2];
			    }
			    else
			    {
				    min_2 = a[i+2];
				    max = a[i+1];
			    }
		    }
		    else
		    {
			    min_2 = a[i];   
			    max = a[i+1];
			   min_1 = a[i+2];
		    }
	   } 
	   else
	   {  
	    	min_2 = a[i+1];
			if(a[i] < a[i+2])
			{
				min_2 = a[i];
				max = a[i+2];
				min_1 = a[i+1];
			}
			else
			{
				max = a[i];
				if(a[i+2] < min_2)
				{
					min_1 = a[i+2];
				}  
				else
				{
					min_1 = a[i+1];
					min_2 = a[i+2];
				}  
			}	
	    }
	    i = 3;
	}
                               //After initiating values of min1,min2,max and position of i 
	while(i < size) 
	{
		if(a[i] < a[i+1])     //We compare the first 3 elemets and initiate the values of min1 , min2 and max
		{
			if(a[i]<min_2)   //If a[i] is less than min2,swap
			  min_2 = a[i];     
			  
			if(a[i]<a[i+2])  
			{
				if(a[i] < min_1)
				{
					 min_2 = min_1;
					 min_1 = a[i];
				}   
				
				if(a[i+1]<a[i+2])
				{
					if(a[i+1] < min_2)
					    min_2 = a[i+1];
					    
					if(a[i+2] > max)
					    max = a[i+2];
				}
				
				else
				{
					if(a[i+2] < min_2)
					min_2 = a[i+2];
					
					if(a[i+1] > max)
					max = a[i+1];
		        }
				
			}
			
			else
			{
				if(a[i+2] < min_1)
				   min_1 = a[i+2];
				   
				if(a[i+1] > max)
				   max = a[i+1];
			}
		}
		else
		{
			if(a[i] < a[i+2])
			{
				if(a[i] < min_2)
				min_2 = a[i];
				if(a[i+2] > max)
				max = a[i+2];
				if(a[i+1] < min_1)
				min_1 = a[i+1];
			}
			else
			{
				if(a[i] > max)
				max = a[i];
				if(a[i+2] < min_2)
				{
					if(a[i+2] < min_1)
					min_1 = a[i+2];
				}  
				else
				{
					if(a[i+1] < min_1)
					min_1 = a[i+1];
					if(a[i+2] < min_2)
					min_2 = a[i+2];
				}  
			}
		}
		i = i+3;
	}
	cout<<"min :"<<min_1<<" min2 :"<<min_2<<" max :"<<max;  //Display Answers
}			
};


int main()
{
	int size,i;
	find_max_min f1;
	//Taking Inputs from user
	cout<<"\n Enter the Size :";
	cin>>size;   
	int arr[size];
	for(i = 0; i < size; i++)
	{
		cout<<"Enter "<<i+1<<" element :";
		cin>>arr[i];
	}
	f1.find_min1_min2_max(arr,size);   //Call the function
	return 0;
}
