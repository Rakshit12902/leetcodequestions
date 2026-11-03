class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int ans = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = i ; j < n ; j++) {
                ans = ans + nums[j];
                if(ans == k) {
                    count++;
                }
            }
            ans = 0;
        }
        return count;
    }
};