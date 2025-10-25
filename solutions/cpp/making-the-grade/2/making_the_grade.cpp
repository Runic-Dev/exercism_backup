#include <algorithm>
#include <array>
#include <format>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
  auto rounded_down = std::vector<int>{};
  for (const auto sc : student_scores) {
    int as_int = static_cast<int>(sc);
    rounded_down.emplace_back(as_int);
  }
  return rounded_down;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
  int failed = 0;
  for (const auto sc : student_scores) {
    if (sc <= 40)
      failed++;
  }
  return failed;
}

// Create a list of grade thresholds based on the provided highest grade.
array<int, 4> letter_grades(int highest_score) {
  int threshold_factor = (highest_score - 40) / 4;
  auto result = array<int, 4>{{41}};

  for (auto i = 1; i <= 3; i++) {
    result[i] = result[i - 1] + threshold_factor;
  }

  return result;
}

// Organize the student's rank, name, and grade information in ascending order.
vector<string> student_ranking(vector<int> student_scores,
                               vector<string> student_names) {
  vector<string> result = vector<string>{};
  for (int i = 0; i < student_scores.size(); ++i) {
    string line = to_string(i + 1) + ". " + student_names[i] + ": " +
                  to_string(student_scores[i]);
    result.push_back(line);
  }
  return result;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
string perfect_score(vector<int> student_scores, vector<string> student_names) {
  for (auto i = 0; i < student_scores.size(); ++i) {
    if (student_scores[i] == 100)
      return student_names[i];
  }
  return "";
}
