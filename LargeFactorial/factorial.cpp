#include <iostream>
#include <string>
#include <sstream>

using namespace std;

std::string reverse_str(std::string in_str) {
  std::string rev_str(in_str);
  std::string::iterator ritr = rev_str.end()-1;
  for (std::string::iterator itr = in_str.begin(); itr != in_str.end(); ++itr) {
    *ritr = *itr;
    ritr--;
  }
  return rev_str;
}

std::string num_to_str(int number) {
  std::ostringstream buffer;
  buffer << number;
  return buffer.str();
}

std::string rFactorial(std::string in_str, int number) {
  int carry = 0;
  std::string out_str = "";

  for (std::string::iterator itr = in_str.begin(); itr != in_str.end(); ++itr) {

      int prod = (*itr - '0')*number + carry;
      std::string s_prod = num_to_str(prod);

      if (itr != in_str.end()-1) {
        out_str.append(s_prod.end()-1, s_prod.end());
        s_prod.erase(s_prod.length()-1);

        if(!s_prod.empty())
          carry = std::stoi(s_prod);
        else
          carry = 0;
      }
      else {
        std::string sr_prod = reverse_str(s_prod);
        out_str.append(sr_prod.begin(), sr_prod.end());
      }
  }

  return out_str;
}

std::string factorial(int number) {
  std::string in_str = reverse_str(num_to_str(number));
  std::string out_str;

  if (number <= 1) {
    out_str = "1";
    return out_str;
  }

  while (number != 1) {
      out_str = rFactorial(in_str, number-1);
      in_str = out_str;
      number--;
  }
  return reverse_str(out_str);
}

int main(int argc, char const *argv[]) {
  int number[] = {-2, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

  for (size_t i = 0; i < 17; i++) {
    string result = factorial(number[i]);
    std::cout << "number: " << number[i] << ", result: " << result << '\n';
  }

  return 0;
}
