#include <stdio.h>
#include <stdlib.h>

double* TwoArraySum(double a[], double b[], int n) {
    double *ans = (double*)malloc(n * sizeof(double));
    if (ans == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        ans[i] = a[i] + b[i];
    }
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);
    double a[n];
    double b[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }
    double *ans = TwoArraySum(a, b, n);
    if (ans != NULL) {
        for (int i = 0; i < n; i++) {
            printf("%.2lf ", ans[i]);
        }
        printf("\n");
        free(ans);
    }
    return 0;
}
