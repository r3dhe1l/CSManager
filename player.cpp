#include <iostream>
#include <vector>
#include <string>
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/randomLibrary/random.hpp"
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/nameGenerator/dasmig/namegen.hpp"
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/nicknameGenerator/dasmig/nicknamegen.hpp"
#include "player.hpp"

namespace r3d
{
	player::player()
	{
		this->_gender = 'x';
		this->_age = 0;
		this->_skillLevel = 0;
	}

	player::player(std::wstring name, std::wstring nickname, std::string nationality, std::string born, std::string roleCT, std::string roleTR, char gender, std::uint8_t skillLevel, std::string currentDate)
	{
		this->_name = name;
		this->_nickname = nickname;
		this->_nationality = nationality;
		this->_born = born;
		this->_roleCT = roleCT;
		this->_roleTR = roleTR;
		this->_gender = gender;
		this->_skillLevel = skillLevel;
		this->_age = setAge(currentDate);
	}

	player::player(std::string country)
	{
		this->_name = L"Player`s Name";
		this->_nickname = L"Player`s Nickname";
		this->_nationality = country;
		this->_born = getRandomBorn();
		this->_roleCT = getRandomRoleCT();
		this->_roleTR = getRandomRoleTR();
		this->_gender = 'm';
		this->_skillLevel = getRandomSkillLevel();
		this->_age = setAge("31/01/2023");
	}

	std::uint8_t player::setAge(std::string currentDate)
	{
		int currentDay = stoi(currentDate.substr(0, 2));
		int currentMonth = stoi(currentDate.substr(3, 2));
		int currentYear = stoi(currentDate.substr(6, 4));
		int bornDay = stoi(this->_born.substr(0, 2));
		int bornMonth = stoi(this->_born.substr(3, 2));
		int bornYear = stoi(this->_born.substr(6, 4));

		if (currentMonth == bornMonth)
		{
			if (currentDay < bornDay)
			{
				return currentYear - bornYear - 1;
			}
		}
		else if (currentMonth < bornMonth)
		{
			return currentYear - bornYear - 1;
		}
		
		return currentYear - bornYear;
	}

	std::string player::getNationality()
	{
		return this->_nationality;
	}

	void player::showInformation()
	{
		std::wcout << "Nome do Jogador é " << this->_name << "\nNickname do jogador é " << this->_nickname << "\nNacionalidade é " << this->_nationality.c_str() <<
			"\nNasceu em " << this->_born.c_str() << "\nJoga de CT como " << this->_roleCT.c_str() << "\nJOga de TR como " << this->_roleTR.c_str() << "\nSexo " <<
			this->_gender << "\nCom skill level de " << this->_skillLevel << "\nE tem " << this->_age << " anos\n";
	}

	std::string player::getRandomBorn()
	{
		int year, month, day = 0;
		year = effolkronium::random_thread_local::get<int>(1990, 2006);
		month = effolkronium::random_thread_local::get<int>(1, 12);

		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			day = effolkronium::random_thread_local::get<int>(1, 31);
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			day = effolkronium::random_thread_local::get<int>(1, 30);
			break;
		case 2:
			if (year % 4 == 0)
			{
				day = effolkronium::random_thread_local::get<int>(1, 29);
			}
			else
			{
				day = effolkronium::random_thread_local::get<int>(1, 28);
			}
			break;
		}

		std::string dayString, monthString;

		day > 9 ? (dayString = std::to_string(day)) : dayString = "0" + std::to_string(day);
		month > 9 ? (monthString = std::to_string(month)) : monthString = "0" + std::to_string(month);

		return dayString + "/" + monthString + "/" + std::to_string(year);
	}

	std::string player::getRandomRoleCT()
	{
		std::string roles[] = { "mid", "rotator", "anchor A", "anchor B", "joker" };

		return roles[effolkronium::random_thread_local::get<int>(0, 4)];
	}

	std::string player::getRandomRoleTR()
	{
		std::string roles[] = { "entry", "support", "lurker", "trader", "joker" };

		return roles[effolkronium::random_thread_local::get<int>(0, 4)];
	}

	std::uint8_t player::getRandomSkillLevel()
	{
		return effolkronium::random_thread_local::get<int>(1, 100);
	}
}
