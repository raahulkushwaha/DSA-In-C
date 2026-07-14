#include <stdio.h>

int main()
{
    int arr[] = {2, 4, 5, 6, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 11;

    int left = 0, right = size - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum == target)
        {
            printf("Index %d and %d Sums Target - %d\n", left, right, target);
            return 0;
        }
        else if (sum < target)
        {
            left++;
        }
        else if (sum > target)
        {
            right--;
        }
    }

    printf("No Index is Mature Enough\n");
    return 0;
}