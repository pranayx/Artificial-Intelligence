#include <iostream>
#include <unordered_map>
#include <queue>
#include<vector>

using namespace std; 


class Graph{
    public:

    int nodes;
    int edges;
    Graph()
    {
        nodes = 0;
        edges = 0;
    }

    unordered_map<string, vector<string>> adjlist;
    unordered_map<string , bool> visited;
    unordered_map<string , bool> visited1;

    void addedge()
    {
        cout<<"Enter the number of nodes: "<<endl;
        cin>>nodes;
        cout<<"Enter the number of edges : "<<endl;
        cin>>edges;
        for(int i =0; i<edges; i++)
        {
            string u , v;
            cin>>u>>v;

            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
    }
    
    void print()
    {
        for(auto i : adjlist)
        {
            cout<<i.first<<"--->";
            for(auto j : i.second)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    void bfsHelper(queue<pair<string,int>>& q, vector<string>& ans) {
        if (q.empty()) 
            return;

        string front = q.front().first;
        int level = q.front().second;
        q.pop();

        ans.push_back(front + " (level: " + to_string(level) + ")");
        
        for (auto i : adjlist[front]) {
            if (!visited[i]) {
                visited[i] = 1;
                q.push({i, level + 1});
            }
        }

        bfsHelper(q, ans); 
     }

        void bfs(string node, vector<string>& ans) {
            queue<pair<string,int>> q;
            q.push({node, 0});
            visited[node] = 1;

            bfsHelper(q, ans); 
        }


    void dfs(string node, vector<string>& ans, int level) {
        visited1[node] = true;
        ans.push_back(node + " (level: " + to_string(level) + ")");

        for (auto i : adjlist[node]) {
            if (!visited1[i]) {
                dfs(i, ans, level + 1);
            }
        }
    }


};


int main()
{
    Graph g;

    g.addedge();
    g.print();

    vector<string> ans1;
    vector<string> ans2;
    cout<<endl;
    g.bfs("a", ans1);

    cout<<"BFS: ";
    for(int i =0; i<ans1.size(); i++)
    {
        cout<<ans1[i]<<"  ";
    }
    cout<<endl;
    cout<<"Dfs: ";


    g.dfs("a", ans2,0);

    for(int i =0; i<ans2.size(); i++)
    {
        cout<<ans2[i]<<" ";
    }

}