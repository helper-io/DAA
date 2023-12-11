#include <iostream>
#include<chrono>
#include <stdlib.h>
using namespace std;
using namespace std::chrono;

void merge(int arr[], int p, int q, int r) {
  
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}


void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    
    merge(arr, l, m, r);
  }
}


int main(){
    int t;
    int n;
    cout << "Enter no of test cases :";
    cin >> t;
    int ans[t][2];
    for(int i=0;i<t;i++){
        cout << "Enter no of element in the array: ";
        cin >> n;
        int arr[n];
        for(int j=0;j<n;j++){
            arr[j] = rand();
        }
        
        auto start = high_resolution_clock::now();
        for (int k = 0; k < 1000; k++)
        {
            mergeSort(arr,0,n-1);
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop-start);
        ans[i][0] = n;
        ans[i][1] = (double)duration.count()/1000;
    }
    cout<<"-------"<<endl;
    cout<<"|\tElements|\tTime\t|"<<endl;
    for(int i=0;i<t;i++){
        cout<<"|\t"<<ans[i][0]<<"\t|\t"<<ans[i][1]<<"\t|"<<endl;
    }
}