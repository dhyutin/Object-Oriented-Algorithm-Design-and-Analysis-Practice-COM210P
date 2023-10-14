#include <iostream>
#include <list>
#include <cmath>

using namespace std;

class gcdlcm
{
public:

 int p_f(int num,int *arr)  //Finding the prime factors.
	{
		int i,j=0;
		int temp=num;
		while(num%2==0)
		{
			arr[j]=2;                          //O(log n base 2)
			j++;
			num=num/2;
		}	
		for(i=3;i<=sqrt(num);i=i+2)
		{                                     //O(log(log n)*n)
			while(num%i==0)
			{
				arr[j]=i;
				j++;
				num=num/i;
			}
		}
		if(num > 2)
		{
			j=j+1;
			arr[j]=num;
		}
		return 0;
	}
    int gcd3(int* arr1 ,int* arr2,int num1,int num2)
    {
        p_f(num1,arr1); 
        p_f(num2,arr2);
        int gcd=1; 
        for(int i = 0;i<num1;++i) 
        {                                              //O(num1*num2)
            for(int j = 0;j<num2;++j)
            {
                if(arr1[i]==arr2[j] && arr1[i]!=0) 
                {
                    gcd=gcd*arr1[i]; 
                    arr1[i]=0; 
                    arr2[j]=0; 
                }
            }                     
        }
        return gcd;
    }
    int lcm3(int* arr1,int*arr2,int num1,int num2)
    {
        int lcm = gcd3(arr1,arr2,num1,num2);  //o(n1*n2)
        for(int i =0;i<num1;i++) 
        {
            if(arr1[i]!=0) 
                lcm=lcm*arr1[i];
        }
        for(int i=0;i<num2;i++) 
        {
            if(arr2[i]!=0) 
                lcm=lcm*arr2[i];
        }
        return lcm;
    }
};
int main()
{
    int num1,num2;
    gcdlcm pair;
    cout<<"Enter the 2 numbers whose G.C.D and L.C.M are to be calculated :"<<endl;
    cin>>num1>>num2;
    if(num1*num2<=0)
    {
        cout<<"Please enter positive integers only"<<endl;
        return 0;
    }
    int arr1[num1],arr2[num2];
    for(int z=0;z<num1;z++)
        arr1[z]=0;
    for(int z=0;z<num2;z++)
        arr2[z]=0;
    cout<<"GCD :"<<pair.gcd3(arr1,arr2,num1,num2)<<endl<<"LCM :"<<pair.lcm3(arr1,arr2,num1,num2);
    return 0;
}
