#pragma once
#include <iostream>
#include <vector>
#include "player.hpp"
#include "coach.hpp"

namespace r3d
{
	class team
	{
	public:

		team();

		team(std::wstring name, std::string country, std::string region, std::string creationDate, std::vector<r3d::player> players, r3d::coach coach);

		team(std::vector<r3d::player> players);

		void addPlayerToTeam(r3d::player player);

		void addCoachToTeam(r3d::coach coach);

	private:
		std::wstring _name;
		std::string _country;
		std::string _region;
		std::string _creationDate;
		std::size_t _numberPlayers;
		std::vector<r3d::player> _playersVector;
		r3d::coach _coach;

		std::string playersGetCountry();

		std::string countryGetRegion();

		std::string determineInternationalTeamRegion();

		std::string createRandomFounding();
	};
}
