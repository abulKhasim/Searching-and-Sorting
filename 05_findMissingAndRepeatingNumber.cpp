class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        int *ans = new int[2];

        int xor1;
        int set_bit_no;

        int i;
        int x = 0; // missing
        int y = 0; // repeated

        xor1 = arr[0];

        for (i = 1; i < n; i++)
            xor1 = xor1 ^ arr[i];

        for (i = 1; i <= n; i++)
            xor1 = xor1 ^ i;

        set_bit_no = xor1 & ~(xor1 - 1);

        for (i = 0; i < n; i++)
        {
            if (arr[i] & set_bit_no)
                /* arr[i] belongs to first set */
                x = x ^ arr[i];

            else
                /* arr[i] belongs to second set */
                y = y ^ arr[i];
        }

        for (i = 1; i <= n; i++)
        {
            if (i & set_bit_no)
                /* i belongs to first set */
                x = x ^ i;

            else
                /* i belongs to second set */
                y = y ^ i;
        }

        // NB! numbers can be swapped, maybe do a check ?
        int x_count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
                x_count++;
        }

        if (x_count == 0)
        {
            ans[0] = y;
            ans[1] = x;
            return ans;
        }
        ans[0] = x;
        ans[1] = y;
        return ans;
    }
};