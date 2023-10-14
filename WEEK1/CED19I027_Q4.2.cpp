#include <iostream>
using namespace std;

class gcdlcm
{
public:
    int num1,num2,i;
    int gcd2()
    {
        int big,small; 
        if(num1>num2) 
        {
            big=num1;
            small=num2;
        }
        else
        {
            big=num2;
            small=num1;
        }
        for(i=small;i>0;--i) 
        {                                         //O(n) n is the smaart number
            if(big%i==0 && small%i==0) 
                return i; 
        }
        return 0; 
    }

    int lcm2()
    {
        int GCD= gcd2();        //O(n) + O(1)
        return (num1*num2)/GCD ;
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
    cout<<"GCD :"<<pair.gcd2()<<endl<<"LCM :"<<pair.lcm2();
    return 0;
}
