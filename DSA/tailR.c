#include <stdio.h>
long tailFact(int n, long a)
{
    if(n==0 || n==1)
        return a;
    else
        return tailFact(n-1,a*n);
}
int main()
{
    int n;
    printf("Enter a number ");
    scanf("%d",&n);
    printf("The factorial of %d is %ld\n",n,tailFact(n,1));
    return 0;
}
