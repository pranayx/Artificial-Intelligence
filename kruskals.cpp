#include<bits/stdc++.h>
using namespace std;

unordered_map<int,string> node_to_city;

bool compare(vector<int>&a, vector<int>&b){
    return a[2]<b[2];
}

int findparent(int node, vector<int>&parent){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=findparent(parent[node],parent);
}

void unionSet(int u, int v, vector<int>&parent,vector<int>&rank){
    u=findparent(u, parent);
    v=findparent(v,parent);

    if(rank[u]<rank[v]){
        parent[u]=v;    
    }
    else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}

int mst(vector<vector<int>>& edges, int n){

    sort(edges.begin(),edges.end(),compare);
    vector<int>parent(n);
    vector<int>rank(n);
    int minwt=0;
    for(int i=0;i<n;i++){
        parent[i]=i;
        rank[i]=0;
    }

    for(int i=0;i<edges.size();i++){
        int u= findparent(edges[i][0],parent);
        int v=findparent(edges[i][1],parent);
        int w=edges[i][2];

        if(u!=v){
            unionSet(u,v,parent,rank);
            minwt+=w;
            // Store the MST edge
            cout<<node_to_city[edges[i][0]]<<"--"<<node_to_city[edges[i][1]]<<"-"<<w<<endl;
        }
    }
    return minwt;
}

int main(){
    cout<<"Enter no of nodes: ";
    int n;
    cin>>n;
   
    for (int i = 0; i < n; ++i) {
                string city;
                cout << "City " << i << ": ";
                cin >> city;
                node_to_city[i] = city; // Mapping node indices to city names
        }
    
    cout<<"Enter no of edges: ";
    int m;
    cin>>m;
    cout<<"Enter edges: ";
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    
    
    int minWeight = mst(edges, n);
    
    cout<<"Minimum weight of spanning tree is: "<<minWeight << endl;


    return 0;
}
