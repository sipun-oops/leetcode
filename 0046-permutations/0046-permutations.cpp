class Solution {
public:
    void permutation(vector<vector<int>>& ans, vector<int>& ds,
                     vector<int>& arr, vector<int>& mp) {
        if (ds.size() == arr.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (!mp[i]) {
                ds.push_back(arr[i]);
                mp[i] = 1;
                permutation(ans, ds, arr, mp);
                ds.pop_back();
                mp[i] = 0;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> mp(nums.size(), 0);
        permutation(ans, ds, nums, mp);

        return ans;
    }
};

/*

generate all arrangements where order matters
use backtracking + visited array
at each step, try every unused element
once an element is used, mark it and don’t reuse in same path
build solution step by step until size == n

*/