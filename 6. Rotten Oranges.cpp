/*
We have given the Grid which contains three type of ele 
0 -> Empty
1 -> Fresh
2 -> Rotten

At every second , Rotten oranges convert there neighbours rotten
Return minimum time required to convert all the fresh oranges to rotten
*/

// As Minimum Time we have to give So BFS will work here 

class Solution {
    private:
    bool isValid(vector<vector<int>>& grid,int row,int col){
        int m = grid.size();
        int n = grid[0].size();
        return (row>=0 && col>=0 && row<m && col<n);
    }
    public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); // rows
        int n = grid[0].size(); // cols
        vector<vector<int>>visited(m,vector<int>(n,0)); // Visited array to mark 
        // Need a queue with {{row,col},time}
        queue<pair<pair<int,int>,int>>q;
        // Need to count fresh oranges 
        int fresh = 0;
        // First Fill all rotten oranges in the queue with time 0
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=1; // mark it as visited
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int finalTime = 0;
        // To check in its all four direction
        int delrow[] = {0,0,-1,1};
        int delcol[] = {1,-1,0,0};
        // Apply BFS 
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            finalTime=max(finalTime,time);
            for(int i=0;i<4;i++){
                int newrow = row+delrow[i];
                int newcol = col+delcol[i];
                if(isValid(grid,newrow,newcol)){
                    if(visited[newrow][newcol]==0 && grid[newrow][newcol]==1){
                        visited[newrow][newcol]=1;
                        q.push({{newrow,newcol},time+1});
                        fresh--;
                    }
                }
            }
        }
        return fresh==0 ? finalTime : -1;
        
    }
};


// Time Complexity :- O(m*n) + O(m*n*4)
// Space Complexity :- O(m*n)        Visited Array