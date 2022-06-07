#include <stdio.h>
int q(int m, int n)
{
    return !(m % n) ? n : q(n, m % n);
}
int z(int p, int l)
{
    while (p % l) {
        int n = p; p = l; l = n % l;
    }
    return l;

}
int main() {
    int m, n;
    printf("gcd of n and m:");
    scanf("%d", &n);
    scanf("%d", &m);
    printf("cycle: %d\n", z(m, n));
    printf("recursion: %d\n", q(m, n));
    return 0;
