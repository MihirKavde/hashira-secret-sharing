Hashira Placements Assignment – Secret Sharing (Polynomial Interpolation)
========================================================================

Problem Statement:
------------------
We are given `n` roots encoded in JSON format, where each root has:
- An index `x` (the key in JSON)
- A value `y` stored in a certain base (2–36)

The task is to:
1. Convert the value from its base into decimal.
2. Use the first `k` points (x, y) to reconstruct the hidden secret using Lagrange interpolation.
3. Output the secret, which is the constant term of the polynomial (f(0)).

---

Approach:
---------
1. Base Conversion:
   - Each value is converted manually from its base to decimal using the formula:
     result = 0
     for each digit d in value:
         result = result * base + d
   - Digits '0'-'9' map to 0-9, 'a'-'z' and 'A'-'Z' map to 10-35.
   - This avoids using library functions for conversion.

2. Lagrange Interpolation:
   - For k points (x1, y1), ..., (xk, yk), the secret is computed as:
     f(0) = Σ ( yi * Π ( (0 - xj) / (xi - xj) ) ), j ≠ i
   - This formula calculates the constant term of the polynomial, which is the hidden secret.

3. Implementation in C:
   - Base conversion and interpolation are implemented manually without external libraries.
   - The code takes hardcoded input values (from the given JSON) and outputs the secret.
   - Floating-point arithmetic is used for Lagrange interpolation and the result is rounded to the nearest integer.

---

How to Run:
-----------
1. Compile the code:
   gcc main.c -o main -lm

2. Run the executable:
   ./main

---

Sample Output:
--------------
Testcase 1:
Secret: 3

Testcase 2:
Secret: <big integer>   (Replace with actual output from code)

---

------
- This assignment demonstrates:
  - Manual base conversion
  - Polynomial interpolation using Lagrange formula
  - Understanding of secret reconstruction (Shamir’s Secret Sharing)
- The code is self-contained, clean, and commented for readability.

Note: Testcase 2 numbers exceed the range of C long long.
For very large numbers, a language with arbitrary-precision integers (like Python) is needed.


