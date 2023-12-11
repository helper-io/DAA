#include <bits/stdc++.h> 
using namespace std; 

int knapSack(int W, int wt[], int val[], int n) 
{ 
	int dp[W + 1]; 
	memset(dp, 0, sizeof(dp)); 

	for (int i = 1; i < n + 1; i++) { 
		for (int w = W; w >= 0; w--) { 

			if (wt[i - 1] <= w) 
				
				dp[w] = max(dp[w], 
							dp[w - wt[i - 1]] + val[i - 1]); 
		} 
	} 
	
	return dp[W]; 
} 

int main() 
{ 
	int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    int profit[n],weight[n];
    cout<<"Enter the profit each item: "<<endl;
    for(int i=0;i<n;i++){
        cin>>profit[i];
    }

    cout<<"Enter the weight each item:"<<endl;
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }

    int W;
    cout<<"Enter the capacity of knapsack: ";
    cin>>W;
    cout<<"Maximum profit: ";
	cout << knapSack(W, weight, profit, n); 
	return 0; 
}
