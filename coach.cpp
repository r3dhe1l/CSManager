#include <iostream>
#include <vector>
#include <string>
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/randomLibrary/random.hpp"
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/nameGenerator/dasmig/namegen.hpp"
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/nicknameGenerator/dasmig/nicknamegen.hpp"
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
	{
		this->_name = name;
		this->_nickname = nickname;
		this->_nationality = nationality;
		this->_born = born;
		this->_gender = gender;
		this->_rating = rating;
		this->_age = setAge(currentDate);
	}

	coach::coach(std::string country)
	{
		this->_name = L"Coach`s Name";
		this->_nickname = L"Coach`s Nickname";
		this->_nationality = country;
		this->_born = getRandomBorn();
		this->_gender = 'm';
		this->_rating = getRandomRating();
		this->_age = setAge("31/01/2023");
	}

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

	std::string coach::getRandomBorn()
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

	std::uint8_t coach::getRandomRating()
	{
		return effolkronium::random_thread_local::get<int>(1, 100);
	}
}
