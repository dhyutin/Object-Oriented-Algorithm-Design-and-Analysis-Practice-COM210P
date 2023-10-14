#include <iostream>

using namespace std;

class patterns
{
	public:
		
			int pattern1(int n)
			{
				int num=n;
				if(n==0)
				{
					return 0;
				}
				for(int i=1;i<=num;i++)
				{
					cout<<i<<" ";
					if(i==num)
					{
						cout<<endl;
					}
				}
				pattern1(n-1);
			}
			int pattern2(int n)
			{
				int num = n;
				if(num==0) return 0;
				for(int i=1;i<=num;i++)
				{
					for(int j =1;j<=num;j++)
					{
						if(j<i)
						{
							cout<<" "<<" ";
						}
						else
						{
							cout<<j<<" ";
						}
					}
					cout<<endl;
				}
			}
			int pattern3(int n)
			{
				int num = n;
				for(int i=1;i<=num;i++)
				{
					int k=1;
					while(k<=i)
					{
						cout<<k<<" ";
						k=k+1;
					}
					cout<<endl;
				}
				return 0;
			}
			int pattern4(int n)
			{
				int num = n;
				for(int i=1;i<=num;i++)
				{
					for(int j=1;j<=num;j++)
					{
						if(j <= num - i)
						{
							cout<<" "<<" ";
						}
						else
						{
							cout<<j<<" ";
						}
					}
					cout<<endl;
				}
				return 0;
			}
			int pattern5(int n)
			{
				int num=n,a;
				int k = num/2;
				if(num%2==1)
				{
					a = num/2 +1;
				}
				else
				{
					a = num/2;
				}
				for(int i = 1;i<=a;i++)
				{
					for(int j =1;j<=num;j++)
					{
						if(j>=i && j <= num+1-i)
						{
							cout<<j<<" ";
						}
						else
						{
							cout<<" "<<" ";
						}
					}
					cout<<endl;
					if(i == num/2 +1)
					{
						break;
					}
				}

				for(int i=1;i<=a;i++)
				{
					for(int j=1;j<=num;j++)
					{
						if( j >= num - k - i +1 && j<= num-k+i && num%2==0)
						{
							cout<<j<<" ";
						}
						else if( j >=num-k-i+1 && j<= num-k-1+i && num%2==1)
						{
							cout<<j<<" ";
						}
						else
						{
							cout<<" "<<" ";
						}
					}
					cout<<endl;
				}
				return 0;
			}
		
};

int main()
{
	int n;
	patterns p;
	cout<<"Enter a number :";
	cin>>n;
	cout<<"Pattern 1:"<<endl;
	p.pattern1(n);
	cout<<"Pattern 2:"<<endl;
	p.pattern2(n);
	cout<<"Pattern 3:"<<endl;
	p.pattern3(n);
	cout<<"Pattern 4:"<<endl;
	p.pattern4(n);
	cout<<"Pattern 5: "<<endl;
	p.pattern5(n);
	
}
