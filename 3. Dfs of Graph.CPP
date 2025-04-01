/*
Need to travel using DFS , We have given the Adjancy list of the graph.
*/

class Solution {
  public:
    void dfs(vector<vector<int>>& adj,vector<int>&visited,vector<int>&ans,int node){
        visited[node]=1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(visited[it]==0){
                dfs(adj,visited,ans,it);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>visited(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(adj,visited,ans,i);
            }
        }
        return ans;
    }
};

// Time complexity :-  O(n+E)   n -> Total Nodes  E -> Total Edges
// Space Complexity :- O(n)+o(n)  visited array + recursive stack