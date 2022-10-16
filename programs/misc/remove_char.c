/*
Given string contains all types of printable characters. Write a program to
remove all characters other than alphabets from string with fixed amount of
additional storage area. (e.g. "He4ll%=O" to be converted to "HellO").
What is time complexity of your function ?
A : O(n) where n is the length of the string
*/
#include <stdio.h>
#define MAX 100

char *remove_char(char *str) {
    int x = 0;
    char *s = str;
    while (*str != '\0') {
        if (('a' <= (*str) && (*str) <= 'z') ||
            ('A' <= (*str) && (*str) <= 'Z')) {
            s[x++] = (*str);
        }
        str++;
    }
    s[x] = '\0';
    return s;
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("New string: %s\n", remove_char(str));
    return 0;
}