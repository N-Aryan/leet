class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int zerocount=0;
        int maxlen=0;
        int len=0;

        while(j<nums.size()){

            if(nums[j]==0 && zerocount<=k){
                zerocount++;
            }

            while(nums[j]==0 && zerocount>k){
                if(nums[i]==0){
                    zerocount--;
                }
                i++;
            }

            len=j-i+1;
            maxlen=max(maxlen,len);

            j++;
        }
        return maxlen;
    }
};