class Solution {
private:
    int findCandidate(vector<int>& a, int size) 
    { 
        int maj_index = 0, count = 1; 

        for (int i = 1; i < size; i++) 
        { 
            
            if (a[maj_index] == a[i]) 
                count++; 
            else
                count--; 
            if (count == 0) 
            { 
                maj_index = i; 
                count = 1; 
            } 
        } 
        return a[maj_index]; 
    }
    
    bool isMajority(vector<int>& a, int size, int cand) 
    { 
        int count = 0; 
        for (int i = 0; i < size; i++) 
            if (a[i] == cand) 
                count++; 
              
        if (count > size/2) 
            return 1; 
          
        else
            return 0; 
    }

public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cand = findCandidate(nums, n); 
      
        if (isMajority(nums, n, cand)) 
            return cand;
        else
            return -1;
        
        
        // unordered_map<int, int> map;
        // for(auto i : nums){
        //     map[i]++;
        // }

        // int a = nums.size()/2;

        // for(auto i : map){
        //     if(i.second > a){
        //         return i.first;
        //     }
        // }
        // return -1;
    }
};