#include <iostream>
#include <vector>
#include <string>
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/randomLibrary/random.hpp"
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/nameGenerator/dasmig/namegen.hpp"
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/nicknameGenerator/dasmig/nicknamegen.hpp"
#include "countryChoiceFunctions.hpp"
#include "player.hpp"

namespace r3d
{
	player::player()
	{
		this->_gender = 'x';
		this->_age = 0;
		this->_skillLevel = 0;
	}

	player::player(std::wstring name, std::wstring nickname, std::string nationality, std::string born, std::string roleCT, std::string roleTR, char gender,
		std::uint8_t skillLevel, std::string currentDate)
		: _name(name), _nickname(nickname), _nationality(nationality), _born(born), _roleCT(roleCT), _roleTR(roleTR), _gender(gender), _age(setAge(currentDate)),
		_skillLevel(skillLevel)
	{}

	player::player(std::string& country, char gender)
		: _name(createRandomName(country, gender)), _nickname(createRandomNick(this->_name)), _nationality(country), _born(createRandomBorn()), _roleCT(chooseRandomRoleCT()),
		_roleTR(chooseRandomRoleTR()), _gender(gender), _age(setAge("07/02/2023")), _skillLevel(createRandomSkillLevel())
	{}

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

	std::wstring player::createRandomName(std::string& country, char& gender)
	{
		int random = effolkronium::random_thread_local::get<int>(1, 30);

		switch (random)
		{
		case 10:
			return dasmig::ng::instance().get_name(dasmig::ng::to_gender(std::to_wstring(gender)), dasmig::ng::to_culture(*r3d::countryGetCode(country))).append_name().append_surname();
		case 20:
			return dasmig::ng::instance().get_name(dasmig::ng::to_gender(std::to_wstring(gender)), dasmig::ng::to_culture(*r3d::countryGetCode(country))).append_surname().append_surname();
		case 30:
			return dasmig::ng::instance().get_name(dasmig::ng::to_gender(std::to_wstring(gender)), dasmig::ng::to_culture(*r3d::countryGetCode(country))).append_name().append_surname().append_surname();
		default:
			break;
		}

		return dasmig::ng::instance().get_name(dasmig::ng::to_gender(std::to_wstring(gender)), dasmig::ng::to_culture(*r3d::countryGetCode(country))).append_surname();
	}

	std::wstring player::createRandomNick(std::wstring& name)
	{
		return dasmig::nng::instance().get_nickname(name);
	}

	std::string player::createRandomBorn()
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

	std::string player::chooseRandomRoleCT()
	{
		std::string roles[] = { "mid", "rotator", "anchor A", "anchor B", "joker" };

		return roles[effolkronium::random_thread_local::get<int>(0, 4)];
	}

	std::string player::chooseRandomRoleTR()
	{
		std::string roles[] = { "entry", "support", "lurker", "trader", "joker" };

		return roles[effolkronium::random_thread_local::get<int>(0, 4)];
	}

	std::uint8_t player::createRandomSkillLevel()
	{
		return effolkronium::random_thread_local::get<int>(1, 100);
	}
}
