/*
We have Given a Directed Graph Need to tell whether it contains Cycle or Not
*/

// Method 1 :- ( DFS )

class Solution {
  private:
    bool dfs(int node,vector<int>adj[],int visited[],int path[]){
        visited[node]=1;
        path[node]=1;
        for(auto it : adj[node]){
            if(visited[it]==0){
                if(dfs(it,adj,visited,path)) return true;
            }
            else {
                if(path[it]==1) return true;
            }
        }
        path[node]=0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        int visited[V]={0};
        int path[V]={0};
        for(int i=0;i<V;i++){
            if(visited[i]!=1){
                if(dfs(i,adj,visited,path)) return true;
            }
        }
        return false;
    }
};

//Time Complexity :- O(V+E)
//Space Complexity :- O(V)+O(V) + Recursive stack


// Method 2 Using Toposort or Khans Algorithm :-

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
       vector<int>indegree(V,0);
       for(int i=0;i<V;i++){
           for(auto it : adj[i]){
               indegree[it]++;
           }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int>toposort;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            toposort.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        
        return V!=toposort.size();
        
       
    }
};