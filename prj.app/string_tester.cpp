#include <movetester/movetester.hpp>
#include <string>

int main() {
  for (int len = 1; len < 10; ++len) {
    std::string str(len, 'a');
    std::cout << "Result for string with length " << len << ":\n";
    Print(MoveTest(str));
    std::cout << "============================================\n";
  }
  for (int len = 10; len < 1e7; len *= 10) {
    std::string str(len, 'a');
    std::cout << "Result for string with length " << len << ":\n";
    Print(MoveTest(str));
    std::cout << "============================================\n";
  }
  return 0;
}