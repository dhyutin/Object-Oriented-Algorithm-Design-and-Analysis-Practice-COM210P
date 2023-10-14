#include<iostream>
#include <vector>
using namespace std;

class fractional_knapsack
{
	public:
			float profit =0;
};

class fk : public fractional_knapsack
{
	public:
		void sort(float obj[][4],int num,int k);
		void fk_wt(float obj[][4],int num,float W,float* ans);
		void fk_profit(float obj[][4],int num,float W,float* ans);
		void fk_pwratio(float obj[][4],int num,float W,float* ans);
		int display(float obj[][4],int num,float* ans);		
};

void fk :: sort(float obj[][4],int num,int k)   //k= 0 => sort by weight
{                                    //k= 1 => sort by profits   
	for(int i=0;i<num;i++)           //k= 2 => sort by profit/weight ratio
	{ 
        float temp=obj[i][k]; 
        int j=i-1;
        while (j>=0 && obj[j][k]>temp)
		{ 
            for(int a=0;a<4;a++)
            {
            	swap(obj[j+1][a],obj[j][a]);
			}
            j=j-1; 
        } 
        obj[j+1][k]=temp; 
    }	
}

void fk :: fk_wt(float obj[][4],int num,float W,float* ans)
{
	sort(obj,num,0);  // 0 => sort by weight
	float current_wt=0.00;
	for(int i=0;i<num;i++)
	{
		if(current_wt + obj[i][0] <=W)
		{
			current_wt= current_wt + obj[i][0];
		    ans[i]=100;
		}
		else
		{
			float remaining = W - current_wt;                  // a% of arr[i][0] = residue		 
			 ans[i] = (100*remaining)/obj[i][0];              // (a/100)*arr[i][0] = residue
			break;                                			 // a = (100*residue)/arr[i][0]
		}
	}	
}

void fk :: fk_profit(float obj[][4],int num,float W,float* ans)
{
	sort(obj,num,1);  // 1 => sort by profit
	float current_wt=0.00;
	for(int i=num-1;i>=0;i--)
	{
		if(current_wt + obj[i][0] <=W)
		{
			current_wt= current_wt + obj[i][0];
		    ans[i]=100;
		}
		else
		{
			float remaining = W - current_wt;                  // a% of arr[i][0] = residue		 
			 ans[i] = (100*remaining)/obj[i][0];              // (a/100)*arr[i][0] = residue
			break;                                			 // a = (100*residue)/arr[i][0]
		}
	}	
}

void fk :: fk_pwratio(float obj[][4],int num,float W,float* ans)
{
	sort(obj,num,2);  // 2 => sort by profit/wt ratio
	float current_wt=0.00;
	for(int i=num-1;i>=0;i--)
	{
		if(current_wt + obj[i][0] <=W)
		{
			current_wt= current_wt + obj[i][0];
		    ans[i]=100;
		}
		else
		{
			float remaining = W - current_wt;                  // a% of arr[i][0] = residue		 
			ans[i] = (100*remaining)/obj[i][0];              // (a/100)*arr[i][0] = residue
			break;                                			 // a = (100*residue)/arr[i][0]
		}
	}
}

int fk :: display(float obj[][4],int num,float* ans)
{
	profit=0;
	for(int i=0;i<num;i++)
	{
		if(ans[i]!=0)
		{
			cout<<" Object "<<obj[i][3]<<" : "<<ans[i]<<" %"<<endl;
			profit = profit + ((obj[i][1]*ans[i])/100);
		}
		ans[i]=0;
	}	
	cout<<"Profit = "<<profit<<endl;
	cout<<"----------------------------------------------------------------------------------------"<<endl;	
}

int main()
{
	int num;
	fk object;
	float W;
	cout<<"Number of Objects: ";
	cin>>num;
	while(num<0)
	{
		cout<<"Enter a positive number."<<endl;
		main();
	}
	
	float obj[num][4];          //Array of type float 
	float ans[num];             //To store the percentage of object in knapsack

	
	for(int i=0;i<num;i++)
	{
		cout<<"Weight of object "<<i+1<<" : ";
		cin>>obj[i][0];                              //store weight in 1st row of array
		cout<<"Profit from object "<<i+1<<" : ";
		cin>>obj[i][1];                             //store profit in 2nd row of array
		obj[i][2]=obj[i][1]/obj[i][0];             //store profit/weight ratio in 3rd row of array
		obj[i][3]=i+1;                             //store object number in 4th row of array
	}
	cout<<"Enter the weight of fractional knapsack :";
	cin>>W;
	cout<<"----------------------------------------------------------------------------------------"<<endl;
	cout<<"Given Inputs are : "<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<"Object "<<obj[i][3]<<":  Weight: "<<obj[i][0]<<"  Profit: "<<obj[i][1]<<"  Profit/Weight ratio: "<<obj[i][2]<<endl;
	}
	cout<<"Knacpsack weight: "<<W<<endl;
	cout<<"----------------------------------------------------------------------------------------"<<endl;
    cout<<"Method 1: w.r.t Weight"<<endl<<"Objects in knapsack are:"<<endl;
	object.fk_wt(obj,num,W,ans);
	object.display(obj,num,ans);
	cout<<"Method 2: w.r.t profit"<<endl<<"Objects in knapsack are:"<<endl;
	object.fk_profit(obj,num,W,ans);
	object.display(obj,num,ans);
	cout<<"Method 3: w.r.t profit/weight ratio"<<endl<<"Objects in knapsack are:"<<endl;
	object.fk_pwratio(obj,num,W,ans);
	object.display(obj,num,ans);	
	return 0;
}
