#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class LCMgcd
{
	private:


    public:

    int lcm1(int n,int m)
    {

        int lcm,temp,i=1;
        if(n>m)
            {
                lcm=n;
                temp=m;
            }
        else
            {
                lcm=m;
                temp=n;
            }
        int num=lcm;
        while(1)
        {
            if(lcm%temp==0)
                return lcm;
            else
            {
                i=i+1;
                lcm=i*num;
            }
        }
    }
    int gcd1(int n,int m)
    {
        int a=n;
        int b=m;
        while(a!=b)
        {
            if(a>b)
                a=a-b;
            else
                b=b-a;
        }
        return a;
    }

    int lcm2(int a, int b)
    {
        return (a / gcd2(a, b)) * b;
    }

	int gcd2(int a,int b)
    {
        if (b == 0)
        return a;
        return gcd2(b, a % b);
    }

    prime_fact(int num,int *arr)  //Finding the prime factors.
	{
		int i,j=0;
		while(num%2==0)
		{
			arr[j]=2;
			j++;
			num=num/2;
		}
		for(i=3;i<=num;i=i+2)
		{
			while(num%i==0)
			{
				arr[j]=i;
				j++;
				num=num/i;
			}
		}

	}

	int lcm3(int *arr1,int *arr2,int n,int m)
	{
		prime_fact(n,arr1);
		prime_fact(m,arr2);
		int i;
		for(i=0;i<n;i++)
		{
			cout<<arr1[i]<<" ";
		}
		cout<<endl;
		for(i=0;i<m;i++)
		{
			cout<<arr2[i]<<" ";
		}

		int b=1;
		for(i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(arr1[i]==arr2[j]&&arr1[i]!=0)
                {
                    b=b*arr1[i];
                    arr1[i]=0;
                    arr2[j]=0;
                }
            }
        }
        int lcm=b;
        for(i=0;i<n;i++)
        {
            if(arr1[i]!=0)
                lcm=lcm*arr1[i];
        }
        for(int i=0;i<m;i++)
        {
            if(arr2[i]!=0)
                lcm=lcm*arr2[i];
        }
        return lcm;
	}

	int gcd3(int *arr1,int *arr2,int n,int m)
	{
		int i,j;
		for(i=0;i<n;i++)
        {
    	    arr1[i]=0;
	    }
    	for(i=0;i<m;i++)
        {
        	arr2[i]=0;
	    }
		prime_fact(n,arr1);
		prime_fact(m,arr2);

		int gcd=1;
		for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(arr1[i]==arr2[j]&&arr1[i]!=0)
                {
                    gcd=gcd*arr1[i];
                    arr1[i]=0;
                    arr2[j]=0;
                }
            }
        }
        return gcd;
	}


};
int main()
{
	int n,m,i;
	int arr1[n],arr2[m];
    LCMgcd obj;
    cout<<"Enter the 2 numbers whose LCM and GCD you want to find out: ";
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
    	arr1[i]=0;
	}
	for(i=0;i<m;i++)
    {
    	arr2[i]=0;
	}
    cout<<endl<<"Method-1:"<<endl<<"LCM :"<<obj.lcm1(n,m)<<endl<<"GCD :"<<obj.gcd1(n,m)<<endl;
    cout<<"______________"<<endl<<endl;
    cout<<"Method-2:"<<endl<<"LCM :"<<obj.lcm2(n,m)<<endl<<"GCD :"<<obj.gcd2(n,m)<<endl;
    cout<<"______________"<<endl<<endl;
    cout<<"Method-3:"<<endl<<"LCM :"<<obj.lcm3(arr1,arr2,n,m)<<endl<<"GCD :"<<obj.gcd3(arr1,arr2,n,m)<<endl;
    return 0;
}
