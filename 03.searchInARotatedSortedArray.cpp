class Solution {
private:
    int mini(vector<int>& nums){
        int n = nums.size();
        int s=0, e=n-1;

        if(nums[s] < nums[e]) return nums[s];

        while(s <= e) {
            int mid = s + (e-s) / 2;
            int prev = (mid+n-1) % n;
            if(nums[mid] <= nums[prev]) return mid;

            else if(nums[mid] >= nums[0]) s = mid+1;

            else if(nums[mid] <= nums[e]) e = mid-1;
        }
        return -1;
    }

    int l(vector<int>& nums, int s, int e, int target){
        while(s <= e){
            int mid = s + (e-s) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                s = mid+1;
            }
            else if(nums[mid] > target){
                e = mid-1;
            }
        }
        return -1;
    }

    int r(vector<int>& nums, int s, int e, int target){
        while(s <= e){
            int mid = s + (e-s) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                s = mid+1;
            }
            else if(nums[mid] > target){
                e = mid-1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int minIndex = mini(nums);
        
        int left = l(nums, 0, minIndex-1, target);
        int right = r(nums, minIndex, nums.size()-1, target);

        if(left >= 0){
            return left;
        }
        if(right >= 0){
            return right;
        }
        return -1;
    }
};