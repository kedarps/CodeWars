#include <vector>
#include <iostream>
#include <algorithm>

class BestTravel
{
public:
    static int chooseBestSum(int t, int k, std::vector<int>& ls) {
      if(ls.size() < k) { return -1; }
      int result = 0;
      std::vector<bool> mask(ls.size());
      std::vector<int> distances;

      // create mask vector of booleans with k values to generate combinations
      for (std::vector<bool>::iterator itr = mask.end()-k; itr != mask.end(); itr++) {
        *itr = true;
      }

      // for each permutation, find the sum using mask boolean
      do {
        int sum = 0;
        for (size_t j = 0; j < ls.size(); j++) {
          if (mask[j]) {
            sum += ls[j];
          }
        }
        // retain distances that are less than or equal to threshold
        if(sum <= t) { distances.push_back(sum); }
      } while(std::next_permutation(mask.begin(), mask.end()));

      // find max of resultant distance vector
      int max = -1;
      for(auto const &x: distances) {
        if(x > max) { max = x; }
      }
      result = max;
      return result;
    }
};

int main(int argc, char const *argv[]) {
  std::vector<int> ts;
  int n;

  ts = {50, 55, 56, 57, 58};
  n = BestTravel::chooseBestSum(163, 3, ts);
  std::cout << "1. result: " << n << '\n';
  std::cout << "----------------" << '\n';

  ts = {50};
  n = BestTravel::chooseBestSum(163, 3, ts);
  std::cout << "2. result: " << n << '\n';
  std::cout << "----------------" << '\n';
  // testequal(n, -1);

  ts = {91, 74, 73, 85, 73, 81, 87};
  n = BestTravel::chooseBestSum(230, 3, ts);
  std::cout << "3. result: " << n << '\n';
  std::cout << "----------------" << '\n';
  // testequal(n, 228);

  n = BestTravel::chooseBestSum(331, 2, ts);
  std::cout << "4. result: " << n << '\n';
  std::cout << "----------------" << '\n';
  // testequal(n, 178);

  n = BestTravel::chooseBestSum(331, 4, ts);
  std::cout << "5. result: " << n << '\n';
  std::cout << "----------------" << '\n';
  // testequal(n, 331);

  n = BestTravel::chooseBestSum(331, 5, ts);
  std::cout << "6. result: " << n << '\n';
  std::cout << "----------------" << '\n';
  // testequal(n, -1);
  //
  n = BestTravel::chooseBestSum(331, 1, ts);
  std::cout << "7. result: " << n << '\n';
  std::cout << "----------------" << '\n';
  // testequal(n, 91);

  n = BestTravel::chooseBestSum(700, 8, ts);
  std::cout << "8. result: " << n << '\n';
  std::cout << "----------------" << '\n';
  // testequal(n, -1);

  return 0;
}
