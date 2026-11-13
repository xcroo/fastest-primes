#include <stdio.h>
#include <string.h>
/* Odd-only sieve of Eratosthenes. c[i] marks odd number 2*i+1 as composite.
   Counts primes <= N, N up to 5,000,000 (array sized for that bound). */
int main(void){
    long n;
    if(scanf("%ld",&n)!=1) return 0;
    if(n<2){ puts("0"); return 0; }
    long m=(n+1)/2;
    static unsigned char c[2500000];
    memset(c,0,m);
    for(long i=3;i*i<=n;i+=2)
        if(!c[i/2])
            for(long j=i*i;j<=n;j+=2*i) c[j/2]=1;
    long t=1;
    for(long i=3;i<=n;i+=2) if(!c[i/2]) t++;
    printf("%ld\n",t);
    return 0;
}
