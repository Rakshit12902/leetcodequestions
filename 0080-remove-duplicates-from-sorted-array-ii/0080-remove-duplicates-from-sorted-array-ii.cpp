class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // If the array has 2 or fewer elements, no duplicates can exceed the limit
        if (nums.size() <= 2) {
            return nums.size();
        }
        
        int index = 2; // The write pointer: positions 0 and 1 are always kept
        
        for (int i = 2; i < nums.size(); i++) {
            // Compare current element with the element two positions behind the write pointer
            if (nums[i] != nums[index - 2]) {
                nums[index] = nums[i]; // Overwrite the duplicate position
                index++;               // Move write pointer forward
            }
        }
        
        return index; // Returns the new length of the modified array
    }
};
