class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        for(int i=0; i<nums.size(); i++){
            int needmore=target-nums[i];
            if(mpp.find(needmore)!=mpp.end()){
                return {i,mpp[needmore]};
            }
            mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
};