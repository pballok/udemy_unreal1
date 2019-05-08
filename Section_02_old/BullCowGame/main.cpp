#include "FBullCowGame.h"

#include <algorithm>
#include <iostream>
#include <string>

using FText = std::string;
using int32 = int;

void print_intro(int32 word_length)
{
    std::cout << "Welcome to Bulls and Cows, a fun word game.\n\n";
    std::cout << "          }   {         ___\n";
    std::cout << "          (o o)        (o o)\n";
    std::cout << "   /-------\\ /          \\ /-------\\\n";
    std::cout << "  / | BULL |O            O| COW  | \\\n";
    std::cout << " *  |-,--- |              |------|  *\n";
    std::cout << "    ^      ^              ^      ^\n";
    std::cout << "Can you guess the " << word_length << " letter isogram I'm thinking of?\n\n";
}

bool ask_to_play_again()
{
	std::cout << "Do you want to play again? (y/n) ";
	FText response;
	std::getline(std::cin, response);

	return response.length() > 0 && (response[0] == 'y' || response[0] == 'Y');
}

FText get_valid_guess(const FBullCowGame& game)
{
	do {
		std::cout << "Try " << game.current_try() << " of " << game.max_tries() << ". Enter your guess: ";

		FText guess;
		std::getline(std::cin, guess);
		std::transform(guess.cbegin(), guess.cend(), guess.begin(), ::tolower);

		switch (game.valid_guess(guess)) {
		case EGuessVailidty::wrong_length:
			std::cout << "Please enter a " << game.word_length() << " letter word.\n\n";
			break;
		case EGuessVailidty::not_isogram:
			std::cout << "Please enter an isogram.\n\n";
			break;
		default:
			return guess;
		}
	} while (true);
}

void print_game_summary(const FBullCowGame& game)
{
	if (game.game_won()) {
		std::cout << "Well done! YOU WIN!\n";
	}
	else {
		std::cout << "Better luck next time!\n";
	}
}

void play_game(FBullCowGame& game)
{
	while (!game.game_won() && game.current_try() <= game.max_tries()) {
		auto guess = get_valid_guess(game);
		auto count = game.submit_guess(guess);
		std::cout << "Bulls: " << count.bulls << ", Cows: " << count.cows << "\n\n";
	}

	print_game_summary(game);
}

int main(int, char**)
{
	FBullCowGame bc_game;
	print_intro(bc_game.word_length());

	do {
		bc_game.new_game();
		play_game(bc_game);
	} while (ask_to_play_again());

	return 0;
}
