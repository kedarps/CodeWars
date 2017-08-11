#include <vector>
#include <iostream>

std::vector<double> averages(std::vector<int> numbers)
{
    std::vector<double> result;

    if (numbers.size() <= 1) {
      return result;
    }

    for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end()-1; ++it)
    {
      std::cout << "avg here: " << (*it + *(it+1)) / 2.0 << '\n';
      result.push_back( (*it + *(it+1)) / 2.0 );
    }

    return result;
}

int main(int argc, char const *argv[]) {
  std::vector<int> nums = {};
  std::vector<double> res = averages(nums);

  return 0;
}
