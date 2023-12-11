#include<iostream>
using namespace std;

int main(){
    int stages;
    int n;
    cout << "Enter the number of stages: ";
    cin >> stages;
    cout<<"Enter the number of vertices: ";
    cin >> n;

    int cost[n+1];
    int d[n+1];
    int path[n+1];
    int graph[n+1][n+1];

    cout << "Enter the cost matrix: " << endl;
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            cin >> graph[i][j];
        }
    }

    // {{0 0 0 0 0 0 0 0 0}
    //  {0 0 2 1 3 0 0 0 0}
    //  {0 0 0 0 0 2 3 0 0}
    //  {0 0 0 0 0 6 7 0 0}
    //  {0 0 0 0 0 6 8 9 0}
    //  {0 0 0 0 0 0 0 0 6}
    //  {0 0 0 0 0 0 0 0 4}
    //  {0 0 0 0 0 0 0 0 5}
    //  {0 0 0 0 0 0 0 0 0}}

    cost[n]=0;
    for (int i = n-1; i >=1 ; i--)
    {
        int min = INT16_MAX;
        for (int k = i+1; k <= n; k++)
        {
            if(graph[i][k] != 0 && graph[i][k] + cost[k] < min){
                min = graph[i][k] + cost[k];
                d[i] = k;
            }
        }
        cost[i] = min;
    }

    path[1] = 1;
    path[stages] = n;
    for (int i = 2; i < stages; i++)
    {
        path[i] = d[path[i-1]];
    }

    cout << "The minimum cost is: " << cost[1] << endl;
    cout << "The path is: ";
    for (int i = 1; i <= stages; i++)
    {
        cout << path[i] << " ";
    }
    
    
    return 0;
}