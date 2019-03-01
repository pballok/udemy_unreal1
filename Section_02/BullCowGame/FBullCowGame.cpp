#include "FBullCowGame.h"

#include <iostream>

constexpr int32 default_max_tries = 5;

FBullCowGame::FBullCowGame()
	: max_tries_(default_max_tries)
{
	new_game();
}

int32 FBullCowGame::current_try() const
{
	return current_try_;
}

int32 FBullCowGame::max_tries() const
{
	return max_tries_;
}

int32 FBullCowGame::word_length() const
{
	return hidden_word_.length();
}

void FBullCowGame::new_game()
{
	current_try_ = 1;
	hidden_word_ = "planet";
}

bool FBullCowGame::game_won() const
{
	return false;
}

EGuessVailidty FBullCowGame::valid_guess(const FString& guess) const
{
	if (guess.length() != word_length()) {
		return EGuessVailidty::wrong_length;
	}
	else if (false) {
		return EGuessVailidty::not_isogram;
	}
	else {
		return EGuessVailidty::ok;
	}
}

FBullCowCount FBullCowGame::submit_guess(const FString& guess)
{
	current_try_++;

	FBullCowCount count;
	int32 hidden_word_length = word_length();
	int32 guess_length = guess.length();
	for (int32 hidden_word_pos = 0; hidden_word_pos < hidden_word_length; ++hidden_word_pos) {
		for (int32 guess_pos = 0; guess_pos < guess_length; ++guess_pos) {
			if (hidden_word_[hidden_word_pos] == guess[guess_pos]) {
				if (hidden_word_pos == guess_pos) {
					count.bulls++;
				}
				else {
					count.cows++;
				}
			}
		}
	}
	return count;
}
