// Input : arr[] = {4, 5, 6, 7, 6}
//            k = 1
//            x = 6
// Output : 2
// The first index of 6 is 2.

// Input : arr[] = {20, 40, 50, 70, 70, 60}  
//           k = 20
//           x = 60
// Output : 5
// The index of 60 is 5

int search(int arr[], int n, int x, int k)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == x)
            return i;
 
        // Jump the difference between current
        // array element and x divided by k
        // We use max here to make sure that i
        // moves at-least one step ahead.
        i = i + max(1, abs(arr[i]-x) / k);
    }

    return -1;
}