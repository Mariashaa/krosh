#include <stdio.h>
 
 
int main(void)
{
    int k;
    char n;
    scanf("%i %c", &k, &n);
    while (n != 10)
    {
        if (n >= 'a' && n <= 'z')
        {
            n = n + k;
                if(n < 'a')
                    n += 26;
        }
        else
            if(n >= 'A' && n <= 'Z')
        {
            n = n + k;
                if(n < 'A')
                    n += 26;
        }
        printf ("%c", n);
        scanf("%c", &n);
    }
 
      
        return 0;
}
