#include<iostream>
using namespace std;
class truck_
{
	public:		
};

class max_num : public truck_
{
	public:
		int max_containers(int*arr,int cno,int x);
		
};

int max_num :: max_containers(int*arr,int cno,int x) 
{
// cno = number of containers being considered
// x = capacity of truck 
	int max_c_num = 0;
//define an array matrix of dimensions (number of containers)X(capacity of truck)
	int array_matrix[cno+1][x+1];  
// We then start filling the matrix from (0,0) TO OUR TARGET (CNO,X)
	for(int i=0; i<=cno;i++) 
	{
		for(int j=0;j<=x;j++)
		{
			if( i==0 ||j==0) //if capacity of truck is 0 or when there are no containers , max number of containers required =0
			{
				array_matrix[i][j]=0;
			}
			else if( j - arr[i-1] >= 0) //if weight of the container is less than the considered capacity of truck
			{
				//array_matrix[i][j] = max ( answer when we include this container , answer when we exclude this container)
				array_matrix[i][j] = max(array_matrix[i - 1][j - arr[i - 1]] + 1, array_matrix[i - 1][j]);
			}
            else //WHEN THE CONTAINER IS HEAVITER THAN TRUCK CAPACITY 
                array_matrix[i][j] = array_matrix[i-1][j]; //ANSWER WE GET WHEN WE INCLUDE THE CONTAINER = ANSWER WE GET WHEN WE EXCLUDE THE CONTAINER
		}
	}
	return array_matrix[cno][x];
}

int main()
{
	int cno,x;
	max_num c1;
	
	cout<<"Enter the capacity of truck: ";
	cin>>x;
	
	cout<<"Number of different containers: ";
	cin>>cno;
	while(cno<0)
	{
		cout<<"Number of different containers cannot be negative";
		main();
	}

	int arr[cno];
	for(int i=0;i<cno;i++)
	{
		cout<<"Enter weight of container "<<i+1<<" : ";
		cin>>arr[i];
	}

	cout<<"MAX NUMBER OF CONTAINERS THAT CAN FIT IN TRUCK = "<<c1.max_containers(arr,cno,x);

	return 0;
}
