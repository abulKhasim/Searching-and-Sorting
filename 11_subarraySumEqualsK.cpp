class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> prevSum;
        int ans = 0;
        int sum = 0;

        for(int i=0; i<n; i++){
            sum += nums[i];

            if(sum == k){
                ans++;
            }

            if(prevSum.find(sum-k) != prevSum.end()){
                ans += prevSum[sum-k];
            }

            prevSum[sum]++;
        }

        return ans;
    }
};