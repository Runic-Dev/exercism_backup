#include "power_of_troy.h"
#include <memory>

namespace troy {
  void give_new_artifact(human &human, std::string artifact_name){
    human.possession = std::make_unique<artifact>(artifact(artifact_name));
  }

  void exchange_artifacts(std::unique_ptr<artifact> &artifact_1, std::unique_ptr<artifact> &artifact_2){
    artifact_1.swap(artifact_2);
  }

  void manifest_power(human &human, std::string power_name){
    human.own_power = std::make_unique<power>(power(power_name));
  }

  void use_power(human &caster, human &target) {
    target.influenced_by = caster.own_power;
  }

  int power_intensity(human &human) {
    return human.own_power.use_count();
  }

}  // namespace troy
