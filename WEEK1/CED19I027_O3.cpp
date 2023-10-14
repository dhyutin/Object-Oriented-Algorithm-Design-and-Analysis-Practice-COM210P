#include <iostream>
using namespace std;

class prime_factors
{
public:
    void p_f(int num)
    {
        for(int j=2 ; j<=num;++j)
        {
            if(num%j==0)
            {
                int prime = 1;
                for(int k=2;k<j;++k)
                {
                    if(j%k==0 && j!=2)
                        prime = 0 ;
                }
                if(prime==1)
                {
                    while(num%j==0)
                    {
                        cout<<j<<" ";
                        num = num/j;
                    }
                }
            }
        }
        return;
    }
};
int main()
{
    prime_factors p1;
    int num,i=1;
    cout<<"Enter a number:";
    cin>>num;
    if(num<=1)
    {
        cout<<"By definition , prime factors of non-positive numbers and 1 do not exist"<<endl;
        return 0;
    }
    cout<<"The prime factors of the number are :"<<endl;
    p1.p_f(num);
    return 0;
}
