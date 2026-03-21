class Solution {
public:
    int trap(vector<int>& height) {

        int n=height.size();

        vector<int> prefix_max(n);
        prefix_max[0]=height[0];
        for(int i=1; i<n; i++){
            prefix_max[i]=max(prefix_max[i-1],height[i]);
        }
        vector<int> postfix_max(n);
        postfix_max[n-1]=height[n-1];
        for(int i=n-2; i>=0; i--){
            postfix_max[i]=max(postfix_max[i+1],height[i]);
        }

        int trapped_water=0;
        for(int i=0; i<n; i++){
            trapped_water += min(prefix_max[i],postfix_max[i])-height[i];
        }
        return trapped_water;
    }
};