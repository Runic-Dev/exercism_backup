#include "luhn.h"

namespace luhn {
    bool valid(string input) {
        int result = 0, counter = 0;
        for (auto i = input.length(); i > 0; i--) {
            const char ascii = input[i - 1];
            if (ascii == ' ') continue;
            if (ascii < 48 or ascii > 57) return false;
            const int num = counter % 2 != 0 ? (ascii - 48) * 2 : ascii - 48;
            result += num > 9 ? num - 9 : num;
            counter++;
        }
        return counter > 1 and result % 10 == 0;
    }
}  // namespace luhn
