/*
Given a string s of lowercase English alphabets, your task is to return the maximum number of substrings formed, after possible partitions (probably zero) of s such that no two substrings have a common character.
*/

class Solution {
  public:
    int maxPartitions(string &s) {
        int n  = s.size();
        vector<int>last_index(26,0);
        for(int i=0;i<n;i++){
            last_index[s[i]-'a']=i;
        }
        int j=0,i=0;
        int count=0;
        while(i<n){
            char ch = s[i];
            j=max(j,last_index[ch-'a']);
            if(j==i) count++;
            i++;
        }
        return count;
        
    }
};

// Time Complexity: O(n)
// Space Complexity: O(N)