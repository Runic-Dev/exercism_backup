#pragma once
#include <string>
#include <vector>
#include <numeric>

using std::string;
using std::string_view;
using std::vector;

namespace lasagna_master {

  struct amount {
    int noodles;
    double sauce;
  };

  int preparationTime(const vector<string>& layers, int avg_layer_time = 2);

  amount quantities(const vector<string>& layers);

  void addSecretIngredient(vector<string>& my_list, const vector<string>& other);
  void addSecretIngredient(vector<string>& my_list, const string_view secret_ing);

  vector<double> scaleRecipe(const vector<double>& quantities, int portions);

} // namespace lasagna_master
