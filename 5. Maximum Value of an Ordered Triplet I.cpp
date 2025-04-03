/*
Need to tell the Best triple Value , where Value is calculating as
value = (nums[i]-nums[j])*nums[k] where i<j<k
*/

// Solution 1 ( Brute Force) :- 

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    long long val = 1LL*(nums[i]-nums[j])*nums[k];
                    res=max(res,val);
                }
            }
        }
        return res;
    }
};

// Time Complexity :- O(n^3) Space :- O(1);