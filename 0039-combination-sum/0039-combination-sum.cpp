class Solution {
public:
    void findCombinations(int idx,int target,vector<vector<int>>&ans,vector<int>&v,vector<int>&ds){
        if(idx == v.size()){
            if(target==0){
                ans.push_back(ds);
            }

            return;
        }

        if(v[idx]<=target){
            ds.push_back(v[idx]);
            findCombinations(idx,target-v[idx],ans,v,ds);
            ds.pop_back();
        }

        findCombinations(idx+1,target,ans,v,ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findCombinations(0,target,ans,candidates,ds);
        return ans;
    }
};

/*

Whenever the problem is printing combinations or subsequence --> first thought must be Recursion 

whenever the problem id picking of elements from a array to form a combination , we start thinnking about pick / not_pick thought process 

*/