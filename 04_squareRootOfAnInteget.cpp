class Solution {
public:
    int mySqrt(int x) {
        // int i = 1;
        // while(i*i <= x){
        //     i++;
        // }
        // return i-1;

        if(x == 0 || x == 1) return x;

        int s = 1, e = x;
        int ans = -1;

        while(s <= e){
            long long int mid = s + (e-s) / 2;
            long long int sqr = mid * mid;

            if(sqr == x){
                return mid;
            }
            else if(sqr < x){
                ans = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }
        }

        return ans;
    }
};