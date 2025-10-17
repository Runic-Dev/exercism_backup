#pragma once

#include <string>
using std::string;

namespace star_map {
    enum System {
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
    };
}
namespace heaven {
    using star_map::System;
    class Vessel {
    public:
        Vessel(string name, int generation, System system = System::Sol);
        [[nodiscard]] Vessel replicate(string name) const;
        void make_buster();
        bool shoot_buster();
        string name;
        System current_system;
        int generation;
        int busters{0};
    };
    string get_older_bob(Vessel vessel1, Vessel vessel2);
    bool in_the_same_system(Vessel vessel1, Vessel vessel2);
}