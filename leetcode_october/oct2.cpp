class Solution {
public:
    vector<vector<int>> result;
    
    void helper(int *arr, vector<int> current, int sum, int n){
        if(sum == 0){
            result.push_back(current);
            return;
        }
        if(n == 0) return;
        
        current.push_back(arr[0]);
        
        if(sum >= 0) helper(arr, current, sum - arr[0], n);
        
        current.pop_back();
        
        helper(arr + 1, current, sum, n - 1);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int *arr = new int[candidates.size() + 1];
        
        for(int i = 0; i < candidates.size(); i++){
            arr[i] = candidates[i];
        }
        
        vector<int> curr;
        
        helper(arr, curr, target, candidates.size());
        
        return result;
    }
};