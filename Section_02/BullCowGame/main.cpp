#include "FBullCowGame.h"

#include <iostream>
#include <string>

using FText = std::string;
using int32 = int;

void print_intro(int32 word_length)
{
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << word_length << " letter isogram I'm thinking of?\n\n";
}

bool ask_to_play_again()
{
	std::cout << "Do you want to play again? (y/n) ";
	FText response;
	std::getline(std::cin, response);

	return response.length() > 0 && (response[0] == 'y' || response[0] == 'Y');
}

FText get_guess(int32 current_try)
{
	std::cout << "Try " << current_try << ". Enter your guess: ";
	FText guess;
	std::getline(std::cin, guess);

	return guess;
}

void play_game(FBullCowGame& game)
{
	for (int32 turn = 1; turn <= game.max_tries(); ++turn) {
		auto guess = get_guess(game.current_try());  //TODO make loop check for valid guess
		auto count = game.submit_guess(guess); // TODO submit only valid guess

		std::cout << "Bulls: " << count.bulls << ", Cows: " << count.cows << std::endl;
	}

	//TODO summarize here
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
