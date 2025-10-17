#include "atbash_cipher.h"
#include <string>
#include <string_view>
#include <ctype.h>

using std::string;
using std::string_view;

namespace atbash_cipher {
    string encode(string input) {
        string result = "";
        int space_idx = 0;
        for (const auto c: input) {
            if (!std::isalpha(c) and !std::isdigit(c)) continue;
            if (space_idx == 5) {
                result += " ";
                space_idx = 0;
            }
            if (std::isalpha(c)) {
                const auto lower = std::tolower(c);
                auto ascii_i = lower + 25;
                ascii_i = ascii_i > 122 ? 122 + (122 - ascii_i) : ascii_i;
                result += ascii_i;
            }
            if (std::isdigit(c)) {
                result += c;
            }
            space_idx++;
        }
        return result;
    }
    string decode(string input) {
        string result = "";
        for (const auto c: input) {
            if (std::isspace(c)) continue;
            if (std::isdigit(c)) {
                result+=c;
                continue;
            }
            int ascii_dec = c - 25;
            ascii_dec = ascii_dec < 97 ? 97 - (ascii_dec - 97) : ascii_dec;
            result+=ascii_dec;
        }
        return result;
    }
} // namespace atbash_cipher
