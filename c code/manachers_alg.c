#include <stdio.h>
#include <string.h>
void manachers(char *s) {
	int i;
    int n = strlen(s);
    char converted_str[2 * n + 3];
    converted_str[0] = '@';
    converted_str[1] = '#';
    for (i = 0; i < n; i++) {
        converted_str[2 * (i + 1)] = s[i];
        converted_str[2 * (i + 1) + 1] = '#';
    }
    converted_str[2 * n + 2] = '\0';
    
    int l = strlen(converted_str);
    int P[l];
    int C = 1;
    int R = 1;

    for (i = 1; i < l - 1; i++) {
        int mirror = 2 * C - i;
        if (i < R)
            P[i] = (R - i < P[mirror]) ? R - i : P[mirror];
        else
            P[i] = 0;

        while (converted_str[i + P[i] + 1] == converted_str[i - P[i] - 1])
            P[i]++;

        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    int max_len = 0;
    int center_ind = 0;
    if(n!=1){
	    for (i = 0; i < l; i++) {
        if (P[i] > max_len) {
            max_len = P[i];
            center_ind = i;
        }
    }
}
    int start = (center_ind - max_len) / 2;
    printf("Given string is: %s\n", s);
    printf("Length of longest palindromic substring is %d\n", max_len);
    printf("Longest palindromic substring is ");
    for (i = start; i < start + max_len; i++)
        printf("%c", s[i]);
    printf("\n");
}

int main() {
    FILE *file = fopen("c_input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char str[1000];
    fgets(str, 1000, file);
    fclose(file);

    manachers(str);

    return 0;
}
