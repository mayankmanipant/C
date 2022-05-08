#include<stdio.h>
#include<stdlib.h>
int armstrong(int a[], int n);
int main ()
{
    int n , i , a[50];
    printf("Enter the limit of the array: ");
    scanf("%d",&n);
    printf("Enter the elements: \n");
    for(i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
    }
    for(i=0 ; i < n ; i++)
    armstrong(a,n);
    return 0 ;
}
int armstrong(int a[], int n)
{
    int i , sum = 0 , rem , temp = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        sum = 0 , rem = 0;
        temp = a[i];
        while(a[i] != 0)
        {
            rem = a[i] % 10;
            sum = sum + (rem*rem*rem);
            a[i] = a[i] / 10;
        }
        if(temp==sum)
        printf("%d is an armstrong number\n",temp);
        else
        printf("%d is not an armstrong number\n",temp);
    }
    exit(0);
}
