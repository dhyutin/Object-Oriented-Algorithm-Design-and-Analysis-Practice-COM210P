#include <iostream>
using namespace std;

class gcdlcm
{
public:
    int num1;
    int num2;

    int gcd1()
    {
        int a = num1;  
        int b = num2;  
        while(a!=b)   
        {                           
            if(a>b)    
                a = a-b;               //O(N) where N is max of num1,num2
            else
                b=b-a; 
        }
        return a; 
    }
    int lcm1()
    {
        int lcm,temp,i=1; 
        if(num1>num2)    
            {
                lcm=num1; 
                temp=num2; 
            }                    
        else
            {
                lcm=num2; 
                temp=num1; 
            }
        int num=lcm; 
        while(1)  
        {
            if(lcm%temp==0) 
                return lcm; 
            else
            {                         //O(N)  where n is the smaller number
                i=i+1; 
                lcm = i * num; 
            }
        }       
    }
};                   
int main()
{
    gcdlcm pair;
    cout<<"Enter the 2 numbers whose G.C.D and L.C.M are to be calculated :"<<endl;
    cin>>pair.num1>>pair.num2;
    if(pair.num1*pair.num2<=0)
      {
        cout<<"Please enter positive integers only"<<endl;
        return 0;
      }
    cout<<"GCD :"<<pair.gcd1()<<endl<<"LCM :"<<pair.lcm1();
    return 0;
}
