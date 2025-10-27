#include <exception>
namespace election {
class NoVotesException : std::exception {
public:
  NoVotesException() {}
  const char *what() const noexcept override {
    return "No votes could be found";
  }
};
} // namespace election
