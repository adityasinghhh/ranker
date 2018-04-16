#ifndef ELO_H
#define ELO_H

#include <cmath>
#include <utility>

using namespace std;

class Elo {
	private:
		float get_K(float &rating);

		float get_S(bool win);
	public:
		float get_default_rating();

		pair<float, float> compute_new_ratings(float &rating_1, float &rating_2, bool &player_1_wins);
};

#endif
