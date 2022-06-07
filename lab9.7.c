#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int isnumber(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++)
        if (!isdigit(str[i]) && str[i] != '\n')
            return 0;
    return 1;
}
int main() {
    int sum = 0;
    char str[256];
    fgets(str, 256, stdin);
    char delim[] = ", ";
    char* p = strtok(str, delim);
    if (isnumber(p)) {
        sum += atoi(p);
    }
    while (p = strtok(NULL, delim)) {
        if (isnumber(p)) {
            sum += atoi(p);
        }
    }
    printf("%d", sum);
    return 0;
} 
