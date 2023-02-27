class Solution
{

public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        sort(arr, arr + n);
        long long ans = 0;

        for (int i = 0; i < n - 2; i++)
        {
            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                long long sum_1 = arr[i] + arr[l] + arr[r];
                if (sum_1 < sum)
                {
                    ans += (r - l);
                    l++;
                }
                else if (sum_1 >= sum)
                {
                    r--;
                }
            }
        }

        return ans;
    }
};