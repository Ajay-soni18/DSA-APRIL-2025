/*
We have given the edges vector need to detect cycle in the graph 
*/

// Using DFS :-
class Solution {
public:
    bool cycle_detection(vector<vector<int>>& adj, int node, vector<int>& visited, int parent) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (visited[it] == 0) {
                if (cycle_detection(adj, it, visited, node)) return true;
            } else if (it != parent) {
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        // Step 1: Convert edge list to adjacency list
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Detect cycle using the adjacency list
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                if (cycle_detection(adj, i, visited, -1)) return true;
            }
        }
        return false;
    }
};

// Time complexity :- O(E)+O(E+V)
// Space complexity :- O(V) + O(V)


// Using BFS :-

  bool checkCycleBFS(vector<vector<int>>&adj,vector<int>&visited,int node,int parent){
        visited[node]=1;
        queue<pair<int,int>>q;
        q.push({node,parent});
        while(!q.empty()){
            int curr = q.front().first;
            int  itsParent = q.front().second;
            q.pop();
            for(auto it : adj[curr]){
                if(visited[it]==0){
                    visited[it]=1;
                    q.push({it,curr});
                }else{
                    if(it!=itsParent) return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                if(checkCycleBFS(adj,visited,i,-1)) return true;
            }
        }
        return false;
    }
};

//Time Complexity:  O(V+E)

// Space Complexity: O(V) (due to the visited array and the BFS queue)

