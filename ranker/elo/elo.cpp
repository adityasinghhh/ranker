#include "elo.h"

#define BASE_RATING 1500.0
#define K_WEAK 32.0
#define K_STRONG 16.0

float Elo::get_default_rating() {
	return BASE_RATING;
}

float Elo::get_K(float &rating) {
	return rating >= 1500.0 ? K_STRONG: K_WEAK;
}

float Elo::get_S(bool win) {
	return win ? 1.0 : 0.0;
}


pair<float, float> Elo::compute_new_ratings(float &rating_1, float &rating_2, bool &player_1_wins) {
	float expectation_1 = 1.0 / (1.0 + pow(10.0, (rating_2 - rating_1) / 400.0));
	float expectation_2 = 1.0 / (1.0 + pow(10.0, (rating_1 - rating_2) / 400.0));

	return make_pair(rating_1 + get_K(rating_1) * (get_S(player_1_wins) - expectation_1), rating_2 + get_K(rating_2) * (get_S(!player_1_wins) - expectation_2));
}

