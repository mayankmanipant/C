#include <stdio.h>
int palindrome(int n)
{
    int temp = n;
    int rev = 0;
    while (n != 0)
    {
        rev = rev * 10 + n % 10;
        n = n / 10;
    }
    if (rev == temp)
        return 1;
    else
        return 0;
}
int main()
{
    int n;
    printf("\nEnter the size of an array. ");
    scanf("%d", &n);
    int ar[n];
    printf("Enter the elements of array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
        int c = palindrome(ar[i]);
        if (c == 1)
            printf("\n%d is palindrome\n", ar[i]);
    }
    return 0;
}
