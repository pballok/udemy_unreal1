#pragma once

#include <string>

class FBullCowGame {
public:
	void reset(); //TODO return value
	int max_tries() const;
	int current_try() const;
	bool game_won() const;
	bool valid_guess(const std::string& guess) const;

private:
	int current_try_;
	int max_tries_;

};