class Solution {
private:
    static bool cmp(int &x,int &y){
        int c1 = __builtin_popcount(x) , c2 = __builtin_popcount(y);
        //return (c1 == c2 ) ? x<y : c1 < c2;
        if(c1 == c2) return x < y;
        return c1 < c2;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};