#include "speedywagon.h"

namespace speedywagon {

  // Enter your code below:

  // Please don't change the interface of the uv_light_heuristic function
  int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
      avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
      if (element > avg) ++uv_index;
    }
    return uv_index;
  }

  bool connection_check(pillar_men_sensor *sensor) {
    return sensor != nullptr;
  }

  int activity_counter(pillar_men_sensor* sensor_array_ptr, int length){
    int sum = 0;
    for (auto i = 0; i < length; ++i) {
      sum += sensor_array_ptr[i].activity;
    }
    return sum;
  }

  bool alarm_control(pillar_men_sensor *sensor){
    return (sensor != nullptr && sensor->activity >= 10);
  }

  bool uv_alarm(pillar_men_sensor *sensor) {
    if(sensor == nullptr) return false;
    auto uv_value = uv_light_heuristic(&sensor->data);
    return uv_value > sensor->activity;
  }
}  // namespace speedywagon
