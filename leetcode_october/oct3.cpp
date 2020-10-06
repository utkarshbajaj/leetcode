class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        
        set<pair<int, int>> seen;
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(abs(nums[i] - nums[j]) == k){
                    pair<int, int> p;
                    p.first = max(nums[i], nums[j]);
                    p.second = min(nums[i], nums[j]);
                    if(!seen.count(p)) seen.insert(p);
                } 
            }
        }
        
        return seen.size();
    }
};