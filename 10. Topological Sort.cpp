/*
We have given the Direct Acyclic Graph (DAG) We need to find the Topological Sort of the Graph
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
*/


// Method 1 :- ( Using DFS)

class Solution {
  private:
    void dfs(vector<vector<int>>&adj,int vis[],stack<int>&st,int node){
        vis[node]=1;
        for(auto it : adj[node]){
            if(vis[it]==0){
                dfs(adj,vis,st,it);
            }
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        
        int vis[V]={0};
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            dfs(adj,vis,st,i);
	        }
	    }
	    vector<int>ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
    }
};

// Time Complexity :- O(V+E) + O(V+E) + O(V);
// Space Complexity :- O(V+E) + O(V)


// Method 2 :- Kahn's Algorithm ( USing BFS)

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int indegree[V]={0};
	    for(int i=0;i<V;i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    queue<int>pq;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) pq.push(i);
	    }
	    vector<int>topo;
	    while(!pq.empty()){
	        int node = pq.front();
	        pq.pop();
	        topo.push_back(node);
	        // since you have push back the node into the topo vector 
	        // Now Decrease its InDegree
	        for(auto it: adj[node]){
	            indegree[it]--;
	            if(indegree[it]==0) pq.push(it);
	        }
	    }
	    return topo;
	}
};