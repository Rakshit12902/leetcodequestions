class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        std::vector<int> ans;
    if (nums.empty()) return ans;

    // 1. Sort the vector in ascending order
    std::sort(nums.begin(), nums.end());

    // 2. Loop through the array and fill gaps between adjacent elements
    for (size_t i = 0; i < nums.size() - 1; i++) {
        int current = nums[i];
        int next = nums[i + 1];

        // If there's a gap greater than 1, find all missing numbers in between
        for (int missing = current + 1; missing < next; missing++) {
            ans.push_back(missing);
        }
    }
    return ans;
    }
};