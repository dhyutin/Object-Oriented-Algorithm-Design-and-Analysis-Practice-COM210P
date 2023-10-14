/*EGYPTIAN FRACTION: Every positive fraction can be represented as sum of unique unit fractions.
                     A fraction is unit fraction if numerator is 1 and denominator is a positive integer 
                     */
#include <iostream>
using namespace std;
  
class egyptian
{
	public:
		
};

class e : public egyptian
{
	public:
		void egypt(int n, int d);
		
};

void e ::egypt(int n, int d)
{
    
    if (d==0 || n==0)  //either numtr or denmtr is 0
    {
    	cout<<" Either numerator or denominator is 0";
    	return;
	}
    if (d%n==0)         //denmtr is multiple of numtr,  then it can be made into 1/(something) form directly
    {
        cout << "1/" << d/n;
        return;
    }
    if (n%d == 0)      // numtr is perfectly divisible by denominator (not a fraction)
    {
        cout << n/d<<" (entered fraction is an integer itself on reducing)";
        return;
    }
    if (n>d)     
    {
        cout << n/d<< " + ";    //to get the whole no.
        egypt(n%d,d);  // (n%d)/d
        return;
    }
    //its a reduced positive fraction
    int c = d/n + 1;   //ceiling of d/n and print it as first fraction and then pass the remaining fraction as recursion
    cout << "1/" <<c<<" + ";

    egypt(n*c-d,d*c);    // n/d - 1/c = (nc-d)/(cd) = (n^2)/d(n+d)  + n/(n+d)= n/d
 }

int main()
{
    int n,d;
    e e1;
    cout<<"Enter numerator of fraction: ";
    cin>>n;
    cout<<"Enter denominator of fraction: ";
    cin>>d;
    cout<<endl;
    cout << "Egyptian Fraction Representation is: "<<n<<"/"<<d<<" = ";
	e1.egypt(n,d);
    
    return 0;
}



