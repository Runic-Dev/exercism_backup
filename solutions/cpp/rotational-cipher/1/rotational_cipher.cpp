#include "rotational_cipher.h"
#include <string>

using std::string;
using std::isdigit;
using std::ispunct;
using std::isspace;
using std::isdigit;

namespace rotational_cipher {

    string rotate(string input, int rotation) {
        string result = "";
        for (const auto c : input) {
            if (ispunct(c) or isspace(c) or isdigit(c)) {
                result+=c;
                continue;
            }
            const auto max = isupper(c) ? 90 : 122;
            const auto min = max - 25;
            rotation = rotation > 25 ? (26 - rotation) * -1 : rotation;
            auto ascii_idx = c + rotation;
            ascii_idx = ascii_idx > max ? min + ((max - ascii_idx) * -1) - 1 : ascii_idx;
            result+=ascii_idx;
        }
        return result;
    }
}  // namespace rotational_cipher
