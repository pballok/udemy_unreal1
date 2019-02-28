#include <iostream>
#include <string>

void print_intro()
{
	constexpr int word_length = 6;

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << word_length << " letter isogram I'm thinking of?\n\n";
}

std::string get_guess()
{
	std::cout << "Enter your guess: ";
	std::string guess;
	std::getline(std::cin, guess);

	return guess;
}

void play_game()
{
	constexpr int number_of_turns = 5;
	for (int Turn = 1; Turn <= number_of_turns; ++Turn) {
		auto guess = get_guess();
		std::cout << "Your guess was: " << guess << "\n";
	}
}

bool ask_to_play_again()
{
	std::cout << "Do you want to play again? (y/n) ";
	std::string response;
	std::getline(std::cin, response);

	return response.length() > 0 && (response[0] == 'y' || response[0] == 'Y');
}

int main(int, char**)
{
	print_intro();

	bool play_again = false;
	do {
		play_game();
		play_again = ask_to_play_again();
	} while (play_again);

	return 0;
}
