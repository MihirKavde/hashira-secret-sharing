#include <stdio.h>
#include <string.h>
#include <math.h>

// Convert character to digit (supports 0-9, a-z, A-Z)
int charToDigit(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'z') return 10 + (c - 'a');
    if (c >= 'A' && c <= 'Z') return 10 + (c - 'A');
    return -1; // invalid
}

// Convert number string in given base to decimal
long long convertToDecimal(const char *value, int base) {
    long long result = 0;
    for (int i = 0; value[i] != '\0'; i++) {
        int digit = charToDigit(value[i]);
        if (digit < 0 || digit >= base) {
            printf("Error: invalid digit '%c' for base %d\n", value[i], base);
            return -1;
        }
        result = result * base + digit;
    }
    return result;
}

// Lagrange interpolation: compute f(0)
long long lagrangeInterpolation(long long x[], long long y[], int k) {
    long double secret = 0.0;
    for (int i = 0; i < k; i++) {
        long double term = y[i];
        for (int j = 0; j < k; j++) {
            if (i == j) continue;
            term *= (0.0 - x[j]) / (x[i] - x[j]);
        }
        secret += term;
    }
    return llround(secret); // nearest integer
}

int main() {
    // -------- Testcase 1 --------
    int n1 = 4, k1 = 3;
    long long x1[4], y1[4];

    x1[0] = 1; y1[0] = convertToDecimal("4", 10);
    x1[1] = 2; y1[1] = convertToDecimal("111", 2);
    x1[2] = 3; y1[2] = convertToDecimal("12", 10);
    x1[3] = 6; y1[3] = convertToDecimal("213", 4);

    printf("Secret (Testcase 1): %lld\n", lagrangeInterpolation(x1, y1, k1));

    // -------- Testcase 2 --------
    int n2 = 10, k2 = 7;
    long long x2[10], y2[10];

    x2[0] = 1;  y2[0] = convertToDecimal("13444211440455345511", 6);
    x2[1] = 2;  y2[1] = convertToDecimal("aed7015a346d635", 15);
    x2[2] = 3;  y2[2] = convertToDecimal("6aeeb69631c227c", 15);
    x2[3] = 4;  y2[3] = convertToDecimal("e1b5e05623d881f", 16);
    x2[4] = 5;  y2[4] = convertToDecimal("316034514573652620673", 8);
    x2[5] = 6;  y2[5] = convertToDecimal("2122212201122002221120200210011020220200", 3);
    x2[6] = 7;  y2[6] = convertToDecimal("20120221122211000100210021102001201112121", 3);
    x2[7] = 8;  y2[7] = convertToDecimal("20220554335330240002224253", 6);
    x2[8] = 9;  y2[8] = convertToDecimal("45153788322a1255483", 12);
    x2[9] = 10; y2[9] = convertToDecimal("1101613130313526312514143", 7);

    printf("Secret (Testcase 2): %lld\n", lagrangeInterpolation(x2, y2, k2));

    return 0;
}

