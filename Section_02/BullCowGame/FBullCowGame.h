#pragma once

#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 bulls = 0;
	int32 cows = 0;
};

enum class EGuessVailidty
{
	ok,
	not_isogram,
	wrong_length
};

class FBullCowGame
{
public:
	FBullCowGame();

	int32 current_try() const;
	int32 max_tries() const;
	int32 word_length() const;

	void new_game();
	bool game_won() const;
	EGuessVailidty valid_guess(const FString& guess) const;
	FBullCowCount submit_guess(const FString& guess);

private:
	int32 current_try_;
	int32 max_tries_;
	FString hidden_word_;
};