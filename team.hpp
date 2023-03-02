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

		team(std::wstring name, std::wstring country, std::wstring region, std::wstring creationDate, std::vector<r3d::player> players, r3d::coach coach);

		team(std::vector<r3d::player> players);

		team(std::wstring name);

		void addPlayerToTeam(r3d::player player);

		void addCoachToTeam(r3d::coach coach);

		std::vector <r3d::player> playersDraft(std::vector <r3d::player> possiblePlayers);

		std::vector <r3d::coach> coachDraft(std::vector <r3d::coach> possibleCoach);

		void showInformation();

	private:
		std::wstring playersDefineCountry();

		std::wstring countryDefineRegion();

		std::wstring determineInternationalTeamRegion();

		std::wstring createRandomFounding();

		std::vector<std::wstring> fillRolesCT();

		std::vector<std::wstring> fillRolesTR();

		int avaiblePlayer(std::vector <r3d::player> possiblePlayers);

		int avaibleCoach(std::vector <r3d::coach> possibleCoachs);

		std::wstring _name;
		std::wstring _country;
		std::wstring _region;
		std::wstring _creationDate;
		std::size_t _numberPlayers;
		std::vector<r3d::player> _playersVector;
		r3d::coach _coach;
		std::vector<std::wstring> _rolesCTFilled{ 5 };
		std::vector<std::wstring> _rolesTRFilled{ 5 };
	};
}
