/*
NEED TO RETURN MAXIMUM POINTS. GIVEN 2D ARRAY 1ST ELEMENT IS POINTS AND 2ND ELEMENT IS BRAINPOWER.
IF YOU PICK QUESTION , POINTS WILL BE ADDED BUT YOU HAVE TO SKIP NEXT BRAINPOWER NUMBER QUESTIONS.
*/

// TOPIC :- DYNAMIC PROGRAMMING

// MEMOIZATION :-  
class Solution {
private:
    long long helper(vector<long long>&dp,vector<vector<int>>& arr,int idx,int n){
        if(idx>=n) return 0;
        if(idx==n-1) return arr[n-1][0];
        if(dp[idx]!=-1) return dp[idx];
        long long take = arr[idx][0];
        if(idx<n) take += helper(dp,arr,idx+arr[idx][1]+1,n);
        long long not_take = helper(dp,arr,idx+1,n);
        return dp[idx] = max(take,not_take);
    }
public:
    long long mostPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<long long> dp(n+1,-1);
        return helper(dp,arr,0,n);
    }
};

// TIME COMPLEXITY :- O(N)
// SPACE COMPLEXITY :- O(N)+O(N)  DP ARRAY AND RECURSIVE STACK

// TABULATION

class Solution {
public:
    long long mostPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<long long> dp(n + 1, 0); // DP array to store the maximum points
        dp[n - 1] = arr[n - 1][0]; // Base case: if only the last question is considered

        // Iterate from the second last to the first element
        for (int idx = n - 2; idx >= 0; --idx) {
            long long take = arr[idx][0]; // Points if we take the current question
            int next = idx + arr[idx][1] + 1; // Next question index after the jump

            // Add the points from the next possible question if within bounds
            if (next < n) take += dp[next];
            long long not_take = dp[idx + 1]; // Points if we skip the current question

            // Store the maximum of taking or not taking the current question
            dp[idx] = max(take, not_take);
        }
        return dp[0]; // The answer is stored in the first element
    }
};

// TIME COMPLEXITY :- O(N)
// SPACE COMPLEXITY :- O(N)  DP ARRAY