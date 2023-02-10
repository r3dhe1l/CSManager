#include <iostream>
#include <vector>
#include <string>
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/randomLibrary/random.hpp"
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/nameGenerator/dasmig/namegen.hpp"
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/nicknameGenerator/dasmig/nicknamegen.hpp"
#include "countryChoiceFunctions.hpp"
#include "coach.hpp"


namespace r3d
{
	coach::coach()
	{
		this->_gender = 'x';
		this->_rating = 0;
		this->_age = 0;
	}

	coach::coach(std::wstring name, std::wstring nickname, std::string nationality, std::string born, char gender, std::uint8_t rating, std::string currentDate)
		: _name(name), _nickname(nickname), _nationality(nationality), _born(born), _gender(gender), _age(setAge(currentDate)), _rating(rating)
	{}

	coach::coach(std::string& country, char gender)
		: _name(createRandomName(country, gender)), _nickname(createRandomNick(this->_name)), _nationality(country), _born(createRandomBorn()), _gender(gender),
		_age(setAge("07/02/2023")), _rating(createRandomRating())
	{}

	std::uint8_t coach::setAge(std::string currentDate)
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

	std::wstring coach::getName()
	{
		return this->_name;
	}

	void coach::showInformation()
	{
		std::wcout << "Nome do treinador é " << this->_name << "\nNickname do treinador é " << this->_nickname << "\nNacionalidade é " << this->_nationality.c_str() <<
			"\nNasceu em " << this->_born.c_str() << "\nSexo " << this->_gender << "\nCom rating de " << this->_rating << "\nE tem " << this->_age << " anos\n";
	}

	std::wstring coach::createRandomName(std::string& country, char& gender)
	{
		int random = effolkronium::random_thread_local::get<int>(1, 30);
		std::wstring wGender;
		wGender = gender;

		switch (random)
		{
		case 10:
			return dasmig::ng::instance().get_name(dasmig::ng::to_gender(wGender), dasmig::ng::to_culture(*r3d::countryGetCode(country))).append_name().append_surname();
		case 20:
			return dasmig::ng::instance().get_name(dasmig::ng::to_gender(wGender), dasmig::ng::to_culture(*r3d::countryGetCode(country))).append_surname().append_surname();
		case 30:
			return dasmig::ng::instance().get_name(dasmig::ng::to_gender(wGender), dasmig::ng::to_culture(*r3d::countryGetCode(country))).append_name().append_surname().append_surname();
		default:
			break;
		}

		return dasmig::ng::instance().get_name(dasmig::ng::to_gender(wGender), dasmig::ng::to_culture(*r3d::countryGetCode(country))).append_surname();
	}

	std::wstring coach::createRandomNick(std::wstring& name)
	{
		return dasmig::nng::instance().get_nickname(name);
	}

	std::string coach::createRandomBorn()
	{
		int year, month, day = 0;
		year = effolkronium::random_thread_local::get<int>(1980, 2000);
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

	std::uint8_t coach::createRandomRating()
	{
		return effolkronium::random_thread_local::get<int>(1, 100);
	}
}
