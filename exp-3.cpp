#include<iostream>
using namespace std;

int maxProfit(int p[],int w[],int n,int k){
	double mat[2][n];
	for (int i = 0; i < n; i++)
	{
		mat[0][i] = i;
		mat[1][i] = (double)(p[i]/w[i]);
	}

	for (int i = 0; i < n-1; i++)
	{
		int temp = mat[1][i];
		int tempIndex = mat[0][i];
		for (int j = i+1; j < n; j++)
		{
			if(mat[1][j]>temp){
				temp = mat[1][j];
				tempIndex = mat[0][j];
			}
		}
		int t = mat[1][i];
		int it = mat[0][i];
		mat[1][i] = temp;
		mat[0][i] = tempIndex;
		mat[1][tempIndex] = t;
		mat[0][tempIndex] = it;

	}
	int profit =0;
	for (int i = 0; i < n && k>0; i++)
	{
		int index = mat[0][i];
		if(w[index]<=k){
			profit += p[index];
			k-=w[index];
		}else{
			profit += mat[1][i]*k;
			k-= w[index];
		}
	}
	return profit;
}

int main(){
	int n;
	int k;
	cout<<"Enter no of elements :";
	cin>>n;
	cout<<"Enter capacity of sack :";
	cin>>k;
	int p[n];
	int w[n];
	cout<<"Enter the profit array :"<<endl;
	for (int i = 0; i < n; i++)
	{
		cin>>p[i];
	}
	cout<<"Enter the weight array :"<<endl;
	for (int i = 0; i < n; i++)
	{
		cin>>w[i];
	}

	cout<<"The maximum profit is :"<<maxProfit(p,w,n,k);
	
}