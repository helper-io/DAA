#include<iostream>
#include<limits.h>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

int primsAlgorithm(vector<vector<int>> &graph,int n){
    unordered_map<int,list<pair<int,int>>> adjList;
    for (int i = 0; i < graph.size(); i++)
    {
        adjList[graph[i][0]].push_back(make_pair(graph[i][1],graph[i][2]));
        adjList[graph[i][1]].push_back(make_pair(graph[i][0],graph[i][2]));
    }
    vector<bool> visited(n,false);
    vector<int> parent(n,-1);
    vector<int> weight(n,INT_MAX);
    weight[0] = 0;
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        int minWeight = INT_MAX;
        int minVertex = -1;
        for (int j = 0; j < n; j++)
        {
            if(!visited[j] && weight[j] < minWeight){
                minWeight = weight[j];
                minVertex = j;
            }
        }
        visited[minVertex] = true;
        sum+=minWeight;
        for(auto neighbour:adjList[minVertex]){
            if(!visited[neighbour.first] && neighbour.second < weight[neighbour.first]){
                parent[neighbour.first] = minVertex;
                weight[neighbour.first] = neighbour.second;
            }
        }
    }
    return sum;
    
    
}

int main(){
    int n;
    cout<<"Enter the no of Vertices :";
    cin >> n;

    vector<vector<int>> graph;
    
    cout << "Enter Grpah Edges :"<<endl;
    int flag = 1;
    while(flag){
        vector<int> edge;
        int n,p,w;
        cout << "Enter Node 1:";
        cin >> n;
        cout << "Enter Node 2:";
        cin >> p;
        cout << "Enter Weight :";
        cin >> w;
        edge.push_back(n);
        edge.push_back(p);
        edge.push_back(w);
        graph.push_back(edge);
        cout << "Enter 1 to continue OR 0 to stop:";
        cin >> flag;
    }

    int ans = primsAlgorithm(graph,n);
    cout << "minimum spanning tree weight :" << ans;
    return 0;
    
}