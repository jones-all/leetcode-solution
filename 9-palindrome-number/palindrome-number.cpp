class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int number = x;
        int reversed = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            if (reversed > INT_MAX / 10 ||
                (reversed == INT_MAX / 10 && digit > 7))
                return false;
            reversed = reversed * 10 + digit;
        }
        return reversed == number;
    }
};