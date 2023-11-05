#include <stdio.h>

int maxele(int arr[], int n)
{
    int maxi = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (maxi < arr[i])
            maxi = arr[i];
    }
    return maxi;
}

void countSort(int arr[], int n)
{
    int maxx = maxele(arr, n) + 1;
    int count[maxx];

    for (int i = 0; i < maxx; i++)
    {
        count[i] = 0;
    }

    int sorted[n];

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i < maxx; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        sorted[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", sorted[i]);
    }

    printf("\n");
}

int main()
{
    int arr[] = {136, 487, 358, 469, 570, 247, 598, 639, 205, 609};
    int n = sizeof(arr) / sizeof(arr[0]);

    countSort(arr, n);

    return 0;
}
