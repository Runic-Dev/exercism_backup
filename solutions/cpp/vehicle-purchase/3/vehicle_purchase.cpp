#include "vehicle_purchase.h"

#include <utility>
#include "vector"

using std::string;
using std::vector;
using std::sort;
using std::move;

namespace vehicle_purchase {

// needs_license determines whether a license is needed to drive a type of
// vehicle. Only "car" and "truck" require a license.
bool needs_license(string kind) {
    // TODO: Return true if you need a license for that kind of vehicle.
    if(kind == "truck" || kind == "car") return true;
    return false;
}

// choose_vehicle recommends a vehicle for selection. It always recommends the
// vehicle that comes first in lexicographical order.
string choose_vehicle(string option1, string option2) {
    vector<string> v{ std::move(option1), std::move(option2) };
    sort(v.begin(), v.end());

    return v[0] + " is clearly the better choice.";
}

// calculate_resell_price calculates how much a vehicle can resell for at a
// certain age.
double calculate_resell_price(double original_price, double age) {
    if (age < 3)  return original_price * 0.8;
    if (age >= 10) return original_price * 0.5;
    return original_price * 0.7;
}

}  // namespace vehicle_purchase
