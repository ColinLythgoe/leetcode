class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashmap;
        vector<int> ret;
        
        for (int i = 0; i < nums.size(); i ++)
        {
            int diff = target - nums[i];
            if (hashmap.find(diff) != hashmap.end())
            {
                ret.push_back(hashmap[diff]);
                ret.push_back(i);
                return ret;
            }
            hashmap.emplace(nums[i], i);
        }
        return ret;
    }
};