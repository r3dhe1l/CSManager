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

		team(std::wstring name);

		void addPlayerToTeam(r3d::player player);

		void addCoachToTeam(r3d::coach coach);

		std::vector <r3d::player> playersDraft(std::vector <r3d::player> possiblePlayers);

		std::vector <r3d::coach> coachDraft(std::vector <r3d::coach> possibleCoach);

		void showInformation();

	private:
		std::wstring _name;
		std::string _country;
		std::string _region;
		std::string _creationDate;
		std::size_t _numberPlayers;
		std::vector<r3d::player> _playersVector;
		r3d::coach _coach;
		std::vector<std::string> _rolesCTFilled{ 5 };
		std::vector<std::string> _rolesTRFilled{ 5 };

		std::string playersDefineCountry();

		std::string countryDefineRegion();

		std::string determineInternationalTeamRegion();

		std::string createRandomFounding();

		std::vector<std::string> fillRolesCT();

		std::vector<std::string> fillRolesTR();

		int avaiblePlayer(std::vector <r3d::player> possiblePlayers);

		int avaibleCoach(std::vector <r3d::coach> possibleCoachs);
	};
}
