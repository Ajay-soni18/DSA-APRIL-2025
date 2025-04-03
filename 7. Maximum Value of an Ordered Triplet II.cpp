/*
You are given a 0-indexed integer array nums.
Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.
The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].
*/


class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftMax(n,0);
        vector<int>rightMax(n,0);

        for(int i=1;i<n;i++){
            leftMax[i]=max(leftMax[i-1],nums[i-1]);
            rightMax[n-i-1]=max(rightMax[n-i],nums[n-i]);
        }
        long long res = 0;
        for(int j=1;j<n-1;j++){
            res = max(res, 1LL*((leftMax[j]-nums[j])*1LL*rightMax[j]));
        }
        return res;
    }
};

// Time Complexity :- O(n)+O(n)
// Space Complexity :- O(2n)