#pragma once

#include <unordered_set>

using std::string;
using std::unordered_set;

namespace allergies {
    class AllergyTest {
    public:
        explicit AllergyTest(unordered_set<string> allergies);
        bool is_allergic_to(const string &allergen) const;
        unordered_set<string> get_allergies();
    private:
        unordered_set<string> detected_allergies;
    };
    AllergyTest allergy_test(int score);
}  // namespace allergies
