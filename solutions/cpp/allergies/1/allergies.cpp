#include "allergies.h"
#include <bitset>

using std::unordered_set;
using std::bitset;
using std::unordered_map;
using std::move;

namespace allergies {
    AllergyTest::AllergyTest(unordered_set<string> allergies) {
        this->detected_allergies = allergies;
    }

    bool AllergyTest::is_allergic_to(const string &allergen) const {
        auto result = this->detected_allergies.find(allergen);
        if (result != this->detected_allergies.end()) {
            return result->length() > 0;
        }
        return false;
    };

    unordered_set<string> AllergyTest::get_allergies() {
        return this->detected_allergies;
    }

    AllergyTest allergy_test(int score) {
        auto result = unordered_set<string>{};
        if (score == 0) {
            return AllergyTest(result);
        }

        const auto possible_allergies = std::array<string, 8> {
            "eggs",
            "peanuts",
            "shellfish",
            "strawberries",
            "tomatoes",
            "chocolate",
            "pollen",
            "cats"
        };

        const bitset<8> bitset(score);
        for (auto i = 7; i >= 0; i--) {
            if (bitset.test(i)) {
                result.insert(possible_allergies[i]);
            }
        }
        return AllergyTest(result);
    }
} // namespace allergies
