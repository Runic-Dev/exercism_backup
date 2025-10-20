#include <array>
#include <string>
#include <vector>
#include <format>


// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    auto rounded_down = std::vector<int> {};
    for (const auto sc : student_scores) {
        int as_int = static_cast<int>(sc);
        rounded_down.emplace_back(as_int);
    }
    return rounded_down;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int failed = 0;
    for (const auto sc: student_scores) {
        if (sc <= 40) failed++;
    }
    return failed;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int threshold_factor = (highest_score - 40) / 4;
    auto result = std::array<int, 4>{
        {41}
    };

    for (auto i = 1; i <= 3; i++) {
        result[i] = result[i - 1] + threshold_factor;
    }

    return result;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> result = std::vector<std::string>{};
    for (int i = 0; i < student_scores.size(); i++) {
        result.emplace_back(std::format("{}. {}: {}", i + 1,
            student_names[i],
            student_scores[i]));
    }
    return result;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    if (const auto result = std::ranges::find(student_scores, 100); result != student_scores.end()) {
        const auto idx = std::distance(student_scores.begin(), result);
        return student_names[idx];
    }
    return "";
}
