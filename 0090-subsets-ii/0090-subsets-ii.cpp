class Solution {
public:
    void subsetII(int idx,vector<vector<int>>&ans,vector<int>&ds,vector<int>&arr){
    ans.push_back(ds);
    for (int i = idx; i < arr.size(); i++)
    {
        if (i!=idx && arr[i]==arr[i-1])
        {
            continue;
        }

        ds.push_back(arr[i]);
        subsetII(i+1,ans,ds,arr);
        ds.pop_back();
        
    }
    
}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>ds;
        subsetII(0,ans,ds,nums);

        return ans;
    }
};

/*
sort the input array so duplicates are adjacent
use backtracking to generate all subsets
at every recursive call, store the current subset as a valid answer
iterate from the current index to explore choices
skip duplicate elements only at the same recursion level
pick an element and move forward (i + 1) to avoid permutations
backtrack by removing the last picked element
this ensures all subsets are unique without repetition
*/