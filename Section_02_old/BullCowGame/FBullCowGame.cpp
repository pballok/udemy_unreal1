#include "FBullCowGame.h"

#include <set>

template<typename ElementType>
using TSet = std::set<ElementType>;

FBullCowGame::FBullCowGame()
{
	new_game();
}

int32 FBullCowGame::current_try() const
{
	return current_try_;
}

int32 FBullCowGame::max_tries() const
{
    return word_length_to_max_tries_.at(word_length());
}

int32 FBullCowGame::word_length() const
{
	return hidden_word_.length();
}

bool FBullCowGame::game_won() const
{
	return game_won_;
}

void FBullCowGame::new_game()
{
	current_try_ = 1;
	game_won_ = false;
	hidden_word_ = "planet";
}

EGuessVailidty FBullCowGame::valid_guess(const FString& guess) const
{
	if (guess.length() != word_length()) {
		return EGuessVailidty::wrong_length;
	}
	else if (!isogram(guess)) {
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

	game_won_ = (count.bulls == word_length());

	return count;
}

bool FBullCowGame::isogram(const FString& word)
{
    if (word.length() <= 1)
        return true;

    TSet<char> letter_seen;
    for (auto ch : word) {
        if (letter_seen.find(ch) != letter_seen.cend())
            return false;

        letter_seen.insert(ch);
    }

    return true;
}
