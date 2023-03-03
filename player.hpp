#pragma once

#include "thirdParty/nameGenerator/dasmig/namegen.hpp"
#include "roleSkillCountry.hpp"

namespace r3d
{
	class player
	{
	public:

		player();

		player(std::wstring name, std::wstring nickname, country::availableCountries nationality, std::wstring born, role::rolesCT primaryRoleCT, role::rolesTR primaryRoleTR,
			role::rolesCT secondaryRoleCT, role::rolesTR secondaryRoleTR, dasmig::ng::gender gender, std::uint8_t skillLevel, std::wstring currentDate);

		player(country::availableCountries country, dasmig::ng::gender gender);

		player(country::availableCountries country, int tier, dasmig::ng::gender gender);

		std::uint8_t setAge(std::wstring currentDate);

		country::availableCountries getNationality();

		role::rolesCT getPrimaryRoleCT();

		role::rolesTR getPrimaryRoleTR();

		role::rolesCT getSecondaryRoleCT();

		role::rolesTR getSecondaryRoleTR();

		std::uint8_t getSkillLevel();

		void showInformation();

	private:
		std::wstring createRandomName(country::availableCountries& country, dasmig::ng::gender& gender);

		std::wstring createRandomNick(std::wstring& name);

		std::wstring createRandomBorn();

		role::rolesCT chooseRandomPrimaryRoleCT();

		role::rolesTR chooseRandomPrimaryRoleTR();

		role::rolesCT chooseRandomSecondaryRoleCT();

		role::rolesTR chooseRandomSecondaryRoleTR();

		std::uint8_t createRandomSkillLevel();

		std::uint8_t createRandomSkillLevelByTier(int tier);

		std::wstring _name;
		std::wstring _nickname;
		country::availableCountries _nationality;
		std::wstring _born;
		role::rolesCT _primaryRoleCT;
		role::rolesTR _primaryRoleTR;
		role::rolesCT _secondaryRoleCT;
		role::rolesTR _secondaryRoleTR;
		dasmig::ng::gender _gender;
		std::uint8_t _age;
		std::uint8_t _skillLevel;
		//team _team;
		//std::vector <traits> _traits;

	};
};