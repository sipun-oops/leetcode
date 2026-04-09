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