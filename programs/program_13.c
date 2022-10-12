#include "deque_impl.c"

char isPalindrome(char *s) {
    int n = 0;
    while (s[n] != '\0') {
        n++;
    }
    deque *q = createDeque(n);
    for (int i = 0; i < n / 2; i++) {
        push_back(q, (int)s[i]);
    }
    for (int i = (n + 1) / 2; i < n; i++) {
        if ((char)peek_back(q) != s[i])
            return 0;
        else
            pop_back(q);
    }
    return isQEmpty(q);
}

int main() {
    char s1[] = "HeyayeH";
    char s2[] = "HyeH";
    printf("%s is palindrome : %s\n", s1, isPalindrome(s1) ? "Yes" : "No");
    printf("%s is palindrome : %s\n", s2, isPalindrome(s2) ? "Yes" : "No");
}