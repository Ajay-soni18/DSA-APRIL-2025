/*
Given The adj list , We need to traverse the graph using BFS.
*/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
      queue<int>q;
        int n = adj.size();
        vector<int>visited(n,0);
        visited[0]=1;
        q.push(0);
        vector<int>ans;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto it : adj[curr]){
                if(visited[it]==0){
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        return ans;
        
    }
};

// Time Complexity :- O(n+E)   n -> Total Nodes  E -> Total Edges
// Space Complexity :- O(n)+o(n)  visited array + Queue