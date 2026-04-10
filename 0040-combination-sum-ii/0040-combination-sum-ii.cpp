class Solution {
public:
    void findCombination(int idx, int target, set<vector<int>>& ans,
                         vector<int>& ds, vector<int>& candidates) {
        if (target == 0) {
            ans.insert(ds);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            if (target < candidates[i]) {
                break;
            }

            ds.push_back(candidates[i]);
            findCombination(i + 1, target - candidates[i], ans, ds, candidates);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, ans, ds, candidates);
        vector<vector<int>> v;
        for (auto it : ans) {
            v.push_back(it);
        }

        return v;
    }
};


// Pattern: Backtracking (Pick / Not Pick with pruning)
// 1. Sort input → helps skip duplicates & prune early
// 2. Loop from current index (idx → n)
// 3. Skip duplicates: if(i > idx && arr[i] == arr[i-1]) continue
// 4. Prune: if(arr[i] > target) break
// 5. Pick element → recurse with (i+1, target - arr[i]) → no reuse
// 6. Backtrack → remove last element
// 7. Base case: if(target == 0) → store answer