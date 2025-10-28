#include "lasagna_master.h"

namespace lasagna_master {

  int preparationTime(const vector<string>& layers, int avg_layer_time) {
    return layers.size() * avg_layer_time;
  }

  amount quantities(const vector<string>& layers) {
    return std::accumulate(layers.begin(), layers.end(), amount{0, 0}, [](amount result, string_view layer){
        if(layer == "noodles") result.noodles += 50;
        if(layer == "sauce") result.sauce += 0.2;
        return result;
    });
  }

  void addSecretIngredient(vector<string>& my_list, const vector<string>& other){
    if (!my_list.empty() && !other.empty()) {
      my_list.back() = other.back();
    }
  }

  void addSecretIngredient(vector<string>& my_list, const string_view secret_ing){
    if(!my_list.empty()) my_list.back() = secret_ing;
  }

  vector<double> scaleRecipe(const vector<double>& quantities, int portions) {
    vector<double> result{}; result.reserve(quantities.size());
    for(auto q : quantities){
      result.push_back((q / 2) * portions);
    }
    return result;
  }

} // namespace lasagna_master
