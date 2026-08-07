class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int st = 0;
    int en = nums.size() - 1;
    
    while (st <= en) {
        if (nums[st] == val) {
            // Swap with the end element, decrease end pointer
            std::swap(nums[st], nums[en]);
            en--; 
            // Do NOT increment 'st' yet, because we need to check the swapped element
        } else {
            st++;
        }
    }
    return st; // 'st' will hold the new size

    }
};