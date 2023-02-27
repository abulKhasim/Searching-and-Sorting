class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<long long int> l(n), r(n);
        vector<long long int> ans = nums;
        
        
        l[0] = 1;
        r[n-1] = 1;
        
        
        // left array
        for(int i=1; i<n; i++){
            l[i] = l[i-1] * nums[i-1];
        }
        
        // right array
        for(int i=n-2; i>=0; i--){
            r[i] = r[i+1] * nums[i+1];
        }
        
        //ans
        for(int i=0; i<n; i++){
            ans[i] = l[i] * r[i];
        }
        
        return ans;
    }
};