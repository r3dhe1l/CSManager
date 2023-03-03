#pragma once

#include "thirdParty/nameGenerator/dasmig/namegen.hpp"
#include "roleSkillCountry.hpp"

namespace r3d
{
	class player;
	class coach;
	class team;

	std::vector <int> playersGetCountriesByRankingRange(std::vector <int> sortedPlayerCountriesVector, int beginIndex, int endIndex,
		std::vector <country::availableCountries> countriesToDraw, int tierPlayer);

	std::vector <int> playersCountriesSortBySkillLevel(const int numPlayers);

	std::vector <player> createPlayersVector(const int numTeams);

	std::vector <int> coachGetCountriesByRankingRange(std::vector <int> sortedCoachCountriesVector, int beginIndex, int endIndex,
		std::vector <country::availableCountries> countriesToDraw, int tierCoach);

	std::vector <int> coachsCountriesSortBySkillLevel(const int numCoachs);

	std::vector <coach> createCoachsVector(const int numTeams);

	std::vector <team> createTeamsVector(const std::size_t numTeams);

	dasmig::ng::culture countryGetNGCulture(const country::availableCountries country);

	country::availableRegions countryGetRegion(const country::availableCountries country);
}