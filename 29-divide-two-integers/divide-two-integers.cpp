class Solution {
public:
    int divide(int dividend, int divisor) {
        // 32-bit integer limits
        const int INT_MAX_VAL = 2147483647;
        const int INT_MIN_VAL = -2147483648;

        // Handle overflow case
        if (dividend == INT_MIN_VAL && divisor == -1)
            return INT_MAX_VAL;

        // Determine sign of result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long long to prevent overflow, use absolute values
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);

        long long quotient = 0;

        // Bit manipulation division
        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            // Double temp until it exceeds a
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            quotient += multiple;
        }

        // Apply sign
        quotient = negative ? -quotient : quotient;

        // Clamp result to 32-bit range
        if (quotient > INT_MAX_VAL) return INT_MAX_VAL;
        if (quotient < INT_MIN_VAL) return INT_MIN_VAL;

        return (int)quotient;
    }
};
