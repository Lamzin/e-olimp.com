#include <stdio.h>

int sieve[50000], a, b;
bool space = false;

void make_sieve()
{
   sieve[0] = sieve[1] = 1;

   for (int i = 2; i*i < 50000; i++)
      if (!sieve[i])
      {
          for (int j = i*i; j < 50000; j+=i)
              sieve[j] = 1;
      }
}

bool check(int x)
{
   if (!sieve[x-2]) return true;
   
   for(int j = 3; 2*j<=x; j+=2)
       if (!sieve[j] && !sieve[x-j]) return true;

   return false;
}

int main()
{
  make_sieve();
  
  scanf("%d %d", &a, &b);
  
  for (int i = a; i<=b; i++)
  {
      if (check(i)) 
      {
          if (space) printf(" ");
          printf("%d", i);
          space = true;
      }
  }
  
  printf("\n");
  
}