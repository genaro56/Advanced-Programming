#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    int a, b;
    while (t--) {
        int n;

        scanf("%d", &n);
        int sumId = 0;
        int sumOfChild = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a);
            scanf("%d", &b);
            sumId += a;
            sumOfChild += b;
        }
        printf("\n");
        printf("%d\n", sumId - sumOfChild);
    }
    return 0;
}