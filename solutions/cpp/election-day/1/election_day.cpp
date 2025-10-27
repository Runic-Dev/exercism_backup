#include "./election_day.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace election {

struct ElectionResult {
  string name{};
  int votes{};
};

int vote_count(const ElectionResult &election_result) {
  return election_result.votes;
}

void increment_vote_count(ElectionResult &election_result,
                          int number_of_votes) {
  election_result.votes += number_of_votes;
}

ElectionResult &determine_result(vector<ElectionResult> &final_count) {
  int winning_idx = -1;
  int hightest = 0;
  for (int i = 0; i < final_count.size(); ++i) {
    if (final_count[i].votes > hightest) {
      winning_idx = i;
      hightest = final_count[i].votes;
    }
  }
  if (winning_idx == -1) {
    throw new NoVotesException();
  }
  ElectionResult &winner = final_count[winning_idx];

  winner.name = "President " + winner.name;
  return winner;
}

} // namespace election
