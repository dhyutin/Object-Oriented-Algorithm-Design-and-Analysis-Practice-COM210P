#include<iostream>
using namespace std;

class coin_change
{
	public:
		int check=0;
		
};

class cc : public coin_change
{
	public:
		void sort_arr(int* arr,int cno);
		int coin_change(int*arr,int cno,int x,int*ans);
		
};
void cc :: sort_arr(int* arr,int cno)
{
    for(int i=0;i<cno;i++)
	{ 
        int temp=arr[i]; 
        int j=i-1;
        while (j>=0 && arr[j]>temp)
		{ 
            swap(arr[j+1],arr[j]); 
            j=j-1; 
        } 
        arr[j+1]=temp; 
    }	
}

int cc :: coin_change(int*arr,int cno,int x,int*ans)
{
	if(cno!=0 && x!=0)
	{
		int c = x/arr[cno-1];
		ans[cno-1]= c;
		check= x - c*arr[cno-1];
	    coin_change(arr,cno-1, check,ans);
	}
	return check;
}
int main()
{
	int cno,x;
	cc c1;
	cout<<"Number of different coins: ";
	cin>>cno;
	while(cno<0)
	{
		cout<<"Number of different coins cannot be negative";
		main();
	}
	int arr[cno];
	int ans[cno];
	for(int i=0;i<cno;i++)
	{
		cout<<"Enter value of coin "<<i+1<<" : ";
		ans[i]=0;
		cin>>arr[i];
	}
	c1.sort_arr(arr,cno);
	cout<<"Enter the change you want: ";
	cin>>x;
	int number =c1.coin_change(arr,cno,x,ans);
	
    if(number==0)
    {
      cout<<"Denominations are:"<<endl;
    
      for(int i=0;i<cno;i++)
      {
    	  cout<<arr[i]<<" coin : "<<ans[i]<<endl;
	  }    	
	}
	else
	cout<<x<<" cannot be given using the available denominations";

	return 0;
}
