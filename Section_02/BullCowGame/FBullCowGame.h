#pragma once

#include <map>
#include <string>

using FString = std::string;
using int32 = int;

template <typename KeyType, typename ElementType>
using TMap = std::map<KeyType, ElementType>;

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
	bool game_won() const;

	void new_game();
	EGuessVailidty valid_guess(const FString& guess) const;
	FBullCowCount submit_guess(const FString& guess);

private:
	int32 current_try_;
	FString hidden_word_;
	bool game_won_;
    TMap<int32, int32> word_length_to_max_tries_ = { {3,4}, {4,7}, {5,10}, {6,15}, {7,20} };

    static bool isogram(const FString& word);
};