#pragma once
#include <iostream>

namespace r3d
{
	class player
	{
	public:

		player();

		player(std::wstring name, std::wstring nickname, std::string nationality, std::string born, std::string roleCT, std::string roleTR, char gender, std::uint8_t skillLevel, std::string currentDate);

		player(std::string country);

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

		std::string getRandomBorn();

		std::string getRandomRoleCT();

		std::string getRandomRoleTR();

		std::uint8_t getRandomSkillLevel();
	};
}
