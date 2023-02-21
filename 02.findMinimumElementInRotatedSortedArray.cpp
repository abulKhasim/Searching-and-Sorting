class Solution {
private:
    int minIndex(vector<int>& nums){
        int n = nums.size();
        int s=0, e=n-1;

        if(nums[e] >= nums[0]) return nums[0];

        while(s <= e) {
            int mid = s + (e-s) / 2;
            int prev = (mid+n-1) % n;
            if(nums[mid] <= nums[prev]) return nums[mid];

            else if(nums[mid] >= nums[0]) s = mid+1;

            else if(nums[mid] <= nums[e]) e = mid-1;
        }
        return 0;
        
    }
public:
    int findMin(vector<int>& nums) {
        int ans = minIndex(nums);
        return ans;
    }
};