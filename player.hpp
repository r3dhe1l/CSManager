#pragma once
#include <iostream>

namespace r3d
{
	class player
	{
	public:

		player();

		player(std::wstring name, std::wstring nickname, std::string nationality, std::string born, std::string primaryRoleCT, std::string primaryRoleTR,
			std::string secondaryRoleCT, std::string secondaryRoleTR, char gender, std::uint8_t skillLevel, std::string currentDate);

		player(std::string country, char gender);

		player(std::string country, char tierLettre, char gender);

		std::uint8_t setAge(std::string currentDate);

		std::string getNationality();

		std::string getPrimaryRoleCT();

		std::string getPrimaryRoleTR();

		std::string getSecondaryRoleCT();

		std::string getSecondaryRoleTR();

		std::uint8_t getSkillLevel();

		void showInformation();

	private:
		std::wstring _name;
		std::wstring _nickname;
		std::string _nationality;
		std::string _born;
		std::string _primaryRoleCT;
		std::string _primaryRoleTR;
		std::string _secondaryRoleCT;
		std::string _secondaryRoleTR;
		char _gender;
		std::uint8_t _age;
		std::uint8_t _skillLevel;

		std::wstring createRandomName(std::string& country, char& gender);

		std::wstring createRandomNick(std::wstring& name);

		std::string createRandomBorn();

		std::string chooseRandomPrimaryRoleCT();

		std::string chooseRandomPrimaryRoleTR();

		std::string chooseRandomSecondaryRoleCT();

		std::string chooseRandomSecondaryRoleTR();

		std::uint8_t createRandomSkillLevel();

		std::uint8_t createRandomSkillLevelByTier(char tierLettre);
	};
}
