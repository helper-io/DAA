// kruskal algorithm
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//disjoint set functions
void initializeSet(vector<int> &parent,vector<int> &rank,int n){
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }  
}

int getParent(vector<int> &parent, int node){
    if (parent[node]==node){
        return node;
    }
    return parent[node] = getParent(parent,parent[node]);
}

void unionSet(vector<int> &parent,vector<int> &rank,int node1,int node2){
    node1 = getParent(parent,node1);
    node2 = getParent(parent,node2);

    if(rank[node1] < rank[node2]){
        parent[node1] = node2;
    }else if(rank[node1] > rank[node2]){
        parent[node2] = node1;
    }else{
        parent[node2] = node1;
        rank[node1]++;
    }
}

bool cmp(vector<int> &a,vector<int> &b){
    return a[2] < b[2];
}

int kruskalAlgorithm(vector<vector<int>> &graph,int n){
    //kruskal logic
    vector<int> parent(n);
    vector<int> rank(n);
    initializeSet(parent,rank,n);
    sort(graph.begin(),graph.end(),cmp);
    int sum=0;

    for (int i = 0; i < graph.size(); i++)
    {
        vector<int> edge = graph[i];
        if(getParent(parent,edge[0])!=getParent(parent,edge[1])){
            unionSet(parent,rank,edge[0],edge[1]);
            sum+=edge[2];   
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

    int ans = kruskalAlgorithm(graph,n);
    
    cout << "minimum spanning tree weight :" << ans;
    return 0;
    
}