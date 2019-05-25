#include <ctime>
#include <iostream>

void PrintIntroduction(int Difficulty)
{
  std::cout << "You are a secret agent breaking into a level " << Difficulty << " server room...\n";
  std::cout << "Enter the correct code to continue...\n\n";
}


bool PlayGame(int Difficulty)
{
  PrintIntroduction(Difficulty);

  const int CodeA = rand() % Difficulty + Difficulty;
  const int CodeB = rand() % Difficulty + Difficulty;
  const int CodeC = rand() % Difficulty + Difficulty;

  const int CodeSum = CodeA + CodeB + CodeC;
  const int CodeProduct = CodeA * CodeB * CodeC;

  std::cout << "There three numbers in the code.\n";
  std::cout << "The codes add up to " << CodeSum << std::endl;
  std::cout << "The codes multiply to give " << CodeProduct << std::endl;

  int GuessA = 0;
  int GuessB = 0;
  int GuessC = 0;

  std::cin >> GuessA >> GuessB >> GuessC;

  int GuessSum = GuessA + GuessB + GuessC;
  int GuessProduct = GuessA * GuessB * GuessC;

  if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
    std::cout << "\n*** Well done agent! You have extracted a file! Keep going! ***\n\n\n";
    return true;
  } else {
    std::cout << "\n*** You have entered the wrong code! Carefult agent! Try again! ***\n\n\n";
    return false;
  }
}


int main(int, char**)
{
  constexpr int MaxDifficulty = 5;
  int LevelDifficulty = 1;

  srand(time(nullptr));

  while (LevelDifficulty <= MaxDifficulty) {
    bool bLevelCompeted = PlayGame(LevelDifficulty);
    std::cin.clear();
    std::cin.ignore();

    if (bLevelCompeted) {
      ++LevelDifficulty;
    }
  }

  std::cout << "*** Great work agent! You got all the files! Now get out of there! ***\n";
  return 0;
}