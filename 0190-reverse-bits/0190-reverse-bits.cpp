class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string bits = "";

        // Extract all 32 bits
        for (int i = 0; i < 32; i++) {
            bits += ((n & 1) ? '1' : '0');
            n >>= 1;
        }

        uint32_t ans = 0;

        // Rebuild from reversed bits
        for (int i = 0; i < 32; i++) {
            ans = (ans << 1) | (bits[i] - '0');
        }

        return ans;
    }
};
