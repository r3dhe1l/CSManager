#pragma once
#include <iostream>

namespace r3d
{
	class player
	{
	public:

		player();

		player(std::wstring name, std::wstring nickname, std::string nationality, std::string born, std::string roleCT, std::string roleTR, char gender,
				std::uint8_t skillLevel, std::string currentDate);

		player(std::string& country, char gender);

		player(std::string& country, char tierLettre, char gender);

		std::uint8_t setAge(std::string currentDate);

		std::string getNationality();

		void showInformation();

	private:
		std::wstring _name;
		std::wstring _nickname;
		std::string _nationality;
		std::string _born;
		std::string _roleCT;
		std::string _roleTR;
		char _gender;
		std::uint8_t _age;
		std::uint8_t _skillLevel;

		std::wstring createRandomName(std::string& country, char& gender);

		std::wstring createRandomNick(std::wstring& name);

		std::string createRandomBorn();

		std::string chooseRandomRoleCT();

		std::string chooseRandomRoleTR();

		std::uint8_t createRandomSkillLevel();

		std::uint8_t createRandomSkillLevelByTier(char tierLettre);
	};
}
