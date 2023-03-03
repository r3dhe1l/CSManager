#pragma once

#include "roleSkillCountry.hpp"
#include "coach.hpp"
#include "player.hpp"

namespace r3d
{
	class team
	{
	public:

		team();

		team(std::wstring name, country::availableCountries country, country::availableRegions region, std::wstring creationDate, std::vector <player> players, coach coach);

		team(std::vector <player> players);

		team(std::wstring name);

		void addPlayerToTeam(player player);

		void addCoachToTeam(coach coach);

		std::vector <player> playersDraft(std::vector <player> possiblePlayers);

		std::vector <coach> coachDraft(std::vector <coach> possibleCoach);

		void showInformation();

	private:
		country::availableCountries playersDefineCountry();

		country::availableRegions countryDefineRegion();

		country::availableRegions determineInternationalTeamRegion();

		std::wstring createRandomFounding();

		std::vector <role::rolesCT> fillRolesCT();

		std::vector <role::rolesTR> fillRolesTR();

		int availablePlayer(std::vector <player> possiblePlayers);

		int availableCoach(std::vector <coach> possibleCoachs);

		std::wstring _name;
		country::availableCountries _country;
		country::availableRegions _region;
		std::wstring _creationDate;
		std::size_t _numberPlayers;
		std::vector <player> _playersVector;
		coach _coach;
		std::vector <role::rolesCT> _rolesCTFilled{ 5 };
		std::vector <role::rolesTR> _rolesTRFilled{ 5 };
	};
};
