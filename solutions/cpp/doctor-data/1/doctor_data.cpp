#include "doctor_data.h"

namespace heaven {
    Vessel::Vessel(string name, int generation, System system) {
        this->name = name;
        this->generation = generation;
        this->current_system = system;
    }

    void Vessel::make_buster() {
        this->busters++;
    }

    bool Vessel::shoot_buster() {
        if (this->busters == 0) return false;
        this->busters--;
        return true;
    }

    Vessel Vessel::replicate(string name) const {
        return {std::move(name), this->generation + 1};
    }

    string get_older_bob(Vessel vessel1, Vessel vessel2) {
        return vessel1.generation < vessel2.generation
                   ? vessel1.name
                   : vessel2.name;
    }

    bool in_the_same_system(Vessel vessel1, Vessel vessel2) {
        return vessel1.current_system == vessel2.current_system;
    }
}
