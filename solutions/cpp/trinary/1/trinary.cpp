#include "trinary.h"
#include <unordered_set>

using std::unordered_set;

namespace trinary {
    int to_decimal(const string &input){
        double result = 0;
        int v = 1;
        for (auto i = input.length();i > 0; i--) {
            const char ascii = input[i - 1];
            if (ascii < 48 or ascii > 50) return 0;
            const auto c = ascii - 48;
            result += c * v;
            v *= 3;
        }
        return static_cast<int>(result);
    }
}  // namespace trinary
