class Solution {
    const int MOD = 1e9 + 7;
    using matrix = vector<vector<long long>>;

    // Helper to multiply two 2x2 matrices
    matrix multiply(matrix A, matrix B) {
        matrix C(2, vector<long long>(2));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    // Helper to compute A^p using Binary Exponentiation
    matrix power(matrix A, long long p) {
        matrix res(2, vector<long long>(2));
        res[0][0] = 1; res[1][1] = 1; // Identity matrix
        A[0][1] = 2; // Correcting initialization from helper 
        
        while (p > 0) {
            if (p & 1) res = multiply(res, A);
            A = multiply(A, A);
            p >>= 1;
        }
        return res;
    }

public:
    int numOfWays(int n) {
        if (n == 1) return 12;

        // 1. Define Transition Matrix M
        // | 3  2 |
        // | 2  2 |
        matrix M = {{3, 2}, {2, 2}};

        // 2. Calculate M^(n-1)
        M = power(M, n - 1);

        // 3. Multiply Result with Base Case [6, 6]
        // Final ABA = M[0][0]*6 + M[0][1]*6
        // Final ABC = M[1][0]*6 + M[1][1]*6
        
        long long aba = (M[0][0] * 6 + M[0][1] * 6) % MOD;
        long long abc = (M[1][0] * 6 + M[1][1] * 6) % MOD;

        return (aba + abc) % MOD;
    }
};