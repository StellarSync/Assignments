#include <stdio.h>
#include <time.h>

long long fibo(int n) {
   static long long memo[100] = {0};  // Adjust array size as needed

   if (n == 1 || n == 2) {
       return 1;
   } else if (memo[n] == 0) {
       memo[n] = fibo(n - 1) + fibo(n - 2);
   }

   return memo[n];
}

int main() {
   int n;
   clock_t t1, t2;

   printf("Enter a number: ");
   scanf("%d", &n);

   t1 = clock();
   long long ans = fibo(n);
   t2 = clock();

   printf("The answer is %lld\n", ans);
   printf("The time taken is %f s\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

   return 0;
}

