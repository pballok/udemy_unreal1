#include <iostream>

int main(int, char**)
{
  std::cout << "You are a secret agent breaking into a secure server room..." << std::endl;
  std::cout << "Enter the correct code to continue..." << std::endl << std::endl;

  constexpr int CodeA = 4;
  constexpr int CodeB = 3;
  constexpr int CodeC = 2;

  constexpr int CodeSum = CodeA + CodeB + CodeC;
  constexpr int CodeProduct = CodeA * CodeB * CodeC;

  std::cout << "There three numbers in the code." << std::endl;
  std::cout << "The codes add up to " << CodeSum << std::endl;
  std::cout << "The codes multiply to give " << CodeProduct << std::endl;

  int GuessA = 0;
  int GuessB = 0;
  int GuessC = 0;

  std::cin >> GuessA >> GuessB >> GuessC;

  int GuessSum = GuessA + GuessB + GuessC;
  int GuessProduct = GuessA * GuessB * GuessC;

  if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
    std::cout << "You Win!" << std::endl;
  } else {
    std::cout << "You Lose!" << std::endl;
  }

  return 0;
}