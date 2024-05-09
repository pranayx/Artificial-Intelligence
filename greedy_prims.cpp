#include<iostream>
#include<unordered_map>
#include<vector>
#include<set>
#include<limits.h>
using namespace std;

class solution{
    public:
        unordered_map<int,vector<pair<int,int>>>adjlist;
        unordered_map<int, int> parent; // to store parent of each node in MST
        unordered_map<int,string> node_to_city;
        
        int nodes;
        int edges;
        solution(){
            nodes=0;
            edges=0;
        }

        void input(){

            cout<<"Enter total number of nodes : ";
            cin>>nodes;
            cout << "Enter names of cities:" << endl;

            for (int i = 0; i < nodes; ++i) {
                string city;
                cout << "City " << i << ": ";
                cin >> city;
                node_to_city[i] = city; // Mapping node indices to city names
            }
            cout<<"Enter the total number of edges : ";
            cin>>edges;
            int u, v;
            int w;
            for(int i=0;i<edges;i++){
                cout<<"Enter edge "<<i<<" ";
                cin>>u>>v;
                cout<<"enter weight: ";
                cin>>w;
                adjlist[u].push_back(make_pair(v,w));
                adjlist[v].push_back(make_pair(u,w));
            }

        }

        void print()
        {
            for(auto i :adjlist)
            {
                cout<<i.first<<"---->";
                for(auto j : i.second)
                {
                    cout<<"["<<j.first<<","<<j.second<<"]"<<" ";
                }
                cout<<endl;
            }
        }

        // Prim's Algorithm
        int prims(int startNode){
            set<pair<int, int>> minHeap;
            vector<int> distance(nodes + 1, INT_MAX);
            vector<bool> visited(nodes + 1, false);
            int minCost = 0;

            minHeap.insert({0, startNode});
            distance[startNode] = 0;
            
            while (!minHeap.empty()) {
                auto top = *minHeap.begin();
                minHeap.erase(minHeap.begin());

                int currentNode = top.second;
                int currentWeight = top.first;

                if (visited[currentNode]) {
                    continue;
                }

                visited[currentNode] = true;
                minCost += currentWeight;

                for (auto neighbour : adjlist[currentNode]) {
                    int neighbourNode = neighbour.first;
                    int neighbourWeight = neighbour.second;

                    if (!visited[neighbourNode] && neighbourWeight < distance[neighbourNode]) {
                        minHeap.insert({neighbourWeight, neighbourNode});
                        distance[neighbourNode] = neighbourWeight;
                        parent[neighbourNode] = currentNode; // store parent
                    }
                }
            }

            return minCost;
        }

        // Function to print MST edges
        void printMST() {
            cout << "Edges in Minimum Spanning Tree (MST):" << endl;
            for (auto node : parent) {
                if (node.first == 0) // Assuming the start node is 0
                    continue;
                cout << "(" << node_to_city[node.second] << ", " << node_to_city[node.first] << ")" << endl;
            }
        }
};

int main()
{
    solution s;
    s.input();
    s.print();
    cout << endl;
    int minCost = s.prims(0); // Assuming the start node is 1
    cout << "Minimum cost of the Minimum Spanning Tree (MST): " << minCost << endl;
    s.printMST(); // Print MST edges
    return 0;
}
