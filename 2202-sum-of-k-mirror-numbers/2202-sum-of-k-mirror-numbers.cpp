class Solution {
public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;
        int length = 1;

        while (count < n) {
            // Generate all palindromes of a given length
            for (long long pal : generatePalindromes(length)) {
                if (isPalindrome(toBaseK(pal, k))) {
                    sum += pal;
                    count++;
                    if (count == n) return sum;
                }
            }
            length++;
        }
        return sum;
    }

private:
    vector<long long> generatePalindromes(int len) {
        vector<long long> res;
        int half = (len + 1) / 2;
        long long start = pow(10, half - 1);
        long long end = pow(10, half);

        for (long long i = start; i < end; ++i) {
            string left = to_string(i);
            string right = string(left.rbegin() + (len % 2), left.rend());
            res.push_back(stoll(left + right));
        }
        return res;
    }

    string toBaseK(long long n, int k) {
        string res;
        while (n > 0) {
            res = char('0' + n % k) + res;
            n /= k;
        }
        return res;
    }

    bool isPalindrome(const string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};
