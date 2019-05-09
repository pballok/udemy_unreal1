#include <iostream>

int main(int, char**)
{
  std::cout << "You are a secret agent breaking into a secure server room..." << std::endl;
  std::cout << "Enter the correct code to continue..." << std::endl;

  constexpr int a = 4;
  constexpr int b = 3;
  constexpr int c = 2;

  constexpr int sum = a + b +c;
  constexpr int product = a * b * c;

  std::cout << sum << std::endl << product << std::endl;

  return 0;
}