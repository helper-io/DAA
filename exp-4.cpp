#include<iostream>
using namespace std;

int maxProfit(int p[],int d[],int n){
    int maxTime=0;
    for (int i = 0; i < n; i++)
    {
        if(d[i]>maxTime){
            maxTime = d[i];
        }
    }

	int profit=0;
	while (maxTime>0)
	{
		int temp = 0;
		for (int i = 0; i < n; i++)
		{
			if(d[i]==maxTime && p[i]>temp){
				temp = p[i];
			}
		}
		profit+=temp;
		maxTime--;
		 
	}
	
    return profit;
}

int main(){
    int n;
	cout<<"Enter no of jobs :";
	cin>>n;
	int p[n];
	int d[n];
	cout<<"Enter the profit array :"<<endl;
	for (int i = 0; i < n; i++)
	{
		cin>>p[i];
	}
	cout<<"Enter the deadline array :"<<endl;
	for (int i = 0; i < n; i++)
	{
		cin>>d[i];
	}

	cout<<"The maximum profit is :"<<maxProfit(p,d,n);
}