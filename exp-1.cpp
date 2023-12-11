#include<iostream>
#include<chrono>
#include <stdlib.h>
using namespace std::chrono;
using namespace std;

int partition(int arr[], int st,int end){
    int i=st;
    int j=st;
    int pivot = arr[end];
    while(j<=end){
        if(arr[j]<=pivot){
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
            j++;
        }else{
            j++;
        }
    }
    return i-1;
}

void quicksort(int arr[],int st,int end){
    if(st<end){
        int pivot = partition(arr,st,end);
        quicksort(arr,st,pivot-1);
        quicksort(arr,pivot+1,end);
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
            quicksort(arr,0,n-1);
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