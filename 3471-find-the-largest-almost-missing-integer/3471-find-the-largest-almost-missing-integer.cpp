class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> countsMap;
        
        // 1. Maintain a vector to preserve the unique encounter order of the values 
        vector<int> originalOrder;
        unordered_set<int> uniqueChecker;

        for (int val : nums) {
            if (uniqueChecker.find(val) == uniqueChecker.end()) {
                uniqueChecker.insert(val);
                originalOrder.push_back(val);
            }
        }

        // 2. Slide a window of size k across the array
        for (int i = 0; i <= n - k; ++i) {
            // Deduplicate elements within the current window boundary
            unordered_set<int> uniqueInWindow;
            for (int j = i; j < i + k; ++j) {
                uniqueInWindow.insert(nums[j]);
            }
            
            // Increment the aggregated sub-array frequency count
            for (int val : uniqueInWindow) {
                countsMap[val]++;
            }
        }

        int maxAlmostMissing = -1;

        // 3. Traverse elements using your reverse iteration design
        for (auto it = originalOrder.rbegin(); it != originalOrder.rend(); ++it) {
            int currentNum = *it;
            // Identify elements that appear in EXACTLY 1 sub-array
            if (countsMap[currentNum] == 1) {
                maxAlmostMissing = max(maxAlmostMissing, currentNum);
            }
        }

        return maxAlmostMissing;
    }
};

    
