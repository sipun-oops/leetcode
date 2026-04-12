class Solution {
public:
    void permutationOP(int idx, vector<vector<int>>& ans, vector<int>& arr) {
        if (idx == arr.size()) {
            ans.push_back(arr);
        }

        for (int i = idx; i < arr.size(); i++) {
            swap(arr[i], arr[idx]);
            permutationOP(idx + 1, ans, arr);
            swap(arr[i], arr[idx]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& v) {
        vector<vector<int>> ans;
        permutationOP(0, ans, v);

        return ans;
    }
};


// BACKTRACKING PATTERN (Permutation Style)
//
// 1. Fix one position at a time (idx represents current position)
// 2. Try all possible choices for that position (loop from idx → n-1)
// 3. Swap to make the choice
// 4. Recurse for next position (idx + 1)
// 5. Backtrack (undo swap)
//
// RULE:
// → Recursion always moves using (idx + 1), NOT loop variable (i + 1)
//
// TEMPLATE:
//
// void solve(int idx, vector<int>& arr) {
//     if (idx == arr.size()) {
//         // store answer
//         return;
//     }
//
//     for (int i = idx; i < arr.size(); i++) {
//         swap(arr[i], arr[idx]);   // choose
//         solve(idx + 1, arr);      // explore
//         swap(arr[i], arr[idx]);   // un-choose (backtrack)
//     }
// }