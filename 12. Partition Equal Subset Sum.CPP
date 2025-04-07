/*
 Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
*/


// Method 1 ( Memoization )

class Solution {
private:
    bool helper(vector<int>& nums, int ind, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (ind == 0) return nums[0] == target;
        if (dp[ind][target] != -1) return dp[ind][target];
        if (nums[ind] <= target) {
            return dp[ind][target] = helper(nums, ind - 1, target - nums[ind], dp) || helper(nums, ind - 1, target, dp);
        } else {
            return dp[ind][target] = helper(nums, ind - 1, target, dp);
        }
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        // if sum not even cannot be divided into two subsets equally
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return helper(nums, n - 1, target, dp);
    }
};

// Time Complexity :- O(n) + O(n*target)
// Space Complexity  :- O(n*target) + recursive stack

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Sum should be even 
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        // if sum is even then i have to check for sum/2 array.
        vector<vector<bool>>dp(n,vector<bool>(sum/2 +1 ,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true; // when sum is zero , possible
        }
        if(nums[0]<=sum/2) dp[0][nums[0]] = true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum/2;j++){
                if(nums[i]<=j){ // both the options availble pick/notpick
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n-1][sum/2];
    }
};

// Time Complexity :- O(n) + O(n*target)
// Space Complexity  :- O(n*target) 