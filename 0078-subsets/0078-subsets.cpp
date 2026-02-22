class Solution {
public:
    void f(int idx, vector<int>& sub, vector<int>& nums, vector<vector<int>> &ans){

        if(idx==nums.size()){
            ans.push_back(sub);
            return;
        }

        sub.push_back(nums[idx]);
        f(idx+1,sub,nums,ans);

        sub.pop_back();
        f(idx+1,sub,nums,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> ans;
        f(0,sub,nums,ans);
        return ans;
    }
};