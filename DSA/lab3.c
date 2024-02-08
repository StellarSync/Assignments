#include<stdio.h>
void TOH(int n, char src, char dst, char tmp)
{
  if(n==1)
    printf("\nMove disc %d from %c to %c \n", n, src, dst);
  else {
    {
      TOH(n-1,src,tmp,dst);
      printf("\nMove disc %d from %c to %c \n", n, src, dst);
      TOH(n-1, tmp, dst, src);
    }
  }
}
int main()
{
  int n;
  printf("Enter number of discs \n");
  scanf("%d", &n);
  TOH(n, 'A', 'C', 'B');
  return 0;
}

