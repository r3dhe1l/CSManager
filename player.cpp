#include <iostream>
#include <vector>
#include <string>
#include "random.hpp"
#include "magic_enum.hpp"
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/nameGenerator/dasmig/namegen.hpp"
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/nicknameGenerator/dasmig/nicknamegen.hpp"
#include "magic_enum.hpp"
#include "countryChoiceFunctions.hpp"
#include "player.hpp"

namespace r3d
{
	player::player() {}

	player::player(std::wstring name, std::wstring nickname, r3d::country::avaibleCountries nationality, std::wstring born, r3d::rolesCT primaryRoleCT, r3d::rolesTR primaryRoleTR,
		r3d::rolesCT secondaryRoleCT, r3d::rolesTR secondaryRoleTR, dasmig::ng::gender gender, std::uint8_t skillLevel, std::wstring currentDate)
		: _name(name), _nickname(nickname), _nationality(nationality), _born(born), _primaryRoleCT(primaryRoleCT), _primaryRoleTR(primaryRoleTR),
		_secondaryRoleCT(secondaryRoleCT), _secondaryRoleTR(secondaryRoleTR), _gender(gender), _age(setAge(currentDate)), _skillLevel(skillLevel)
	{}

	player::player(r3d::country::avaibleCountries country, dasmig::ng::gender gender)
		: _name(createRandomName(country, gender)), _nickname(createRandomNick(this->_name)), _nationality(country), _born(createRandomBorn()),
		_primaryRoleCT(chooseRandomPrimaryRoleCT()), _primaryRoleTR(chooseRandomPrimaryRoleTR()), _secondaryRoleCT(chooseRandomSecondaryRoleCT()),
		_secondaryRoleTR(chooseRandomSecondaryRoleTR()), _gender(gender), _age(setAge(L"12/02/2023")), _skillLevel(createRandomSkillLevel())
	{}

	player::player(r3d::country::avaibleCountries country, int tier, dasmig::ng::gender gender)
		: _name(createRandomName(country, gender)), _nickname(createRandomNick(this->_name)), _nationality(country), _born(createRandomBorn()),
		_primaryRoleCT(chooseRandomPrimaryRoleCT()), _primaryRoleTR(chooseRandomPrimaryRoleTR()), _secondaryRoleCT(chooseRandomSecondaryRoleCT()),
		_secondaryRoleTR(chooseRandomSecondaryRoleTR()), _gender(gender), _age(setAge(L"12/02/2023")), _skillLevel(createRandomSkillLevelByTier(tier))
	{}

	std::uint8_t player::setAge(std::wstring currentDate)
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

	r3d::country::avaibleCountries player::getNationality()
	{
		return this->_nationality;
	}

	r3d::rolesCT player::getPrimaryRoleCT()
	{
		return this->_primaryRoleCT;
	}

	r3d::rolesTR player::getPrimaryRoleTR()
	{
		return this->_primaryRoleTR;
	}

	r3d::rolesCT player::getSecondaryRoleCT()
	{
		return this->_secondaryRoleCT;
	}

	r3d::rolesTR player::getSecondaryRoleTR()
	{
		return this->_secondaryRoleTR;
	}

	std::uint8_t player::getSkillLevel()
	{
		return this->_skillLevel;
	}

	void player::showInformation()
	{
		std::wcout << L"Nome do Jogador é " << this->_name << L"\nNickname do jogador é " << this->_nickname << L"\nNacionalidade é " << this->_nationality <<
			L"\nNasceu em " << this->_born << L"\nJoga de CT como " << this->_primaryRoleCT << L"\nJOga de TR como " << this->_primaryRoleTR << L"\nSexo " <<
			this->_gender << L"\nCom skill level de " << this->_skillLevel << L"\nE tem " << this->_age << L" anos\n";
	}

	std::wstring player::createRandomName(r3d::country::avaibleCountries& country, dasmig::ng::gender& gender)
	{
		int random = effolkronium::random_thread_local::get<int>(1, 30);

		switch (random)
		{
		case 10:
			return dasmig::ng::instance().get_name(gender, r3d::countryGetNGCulture(country)).append_name().append_surname();
		case 20:
			return dasmig::ng::instance().get_name(gender, r3d::countryGetNGCulture(country)).append_surname().append_surname();
		case 30:
			return dasmig::ng::instance().get_name(gender, r3d::countryGetNGCulture(country)).append_name().append_surname().append_surname();
		default:
			break;
		}

		return dasmig::ng::instance().get_name(gender, r3d::countryGetNGCulture(country)).append_surname();
	}

	std::wstring player::createRandomNick(std::wstring& name)
	{
		return dasmig::nng::instance().get_nickname(name);
	}

	std::wstring player::createRandomBorn()
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

		std::wstring dayString, monthString;

		day > 9 ? (dayString = std::to_wstring(day)) : dayString = L"0" + std::to_wstring(day);
		month > 9 ? (monthString = std::to_wstring(month)) : monthString = L"0" + std::to_wstring(month);

		return dayString + L"/" + monthString + L"/" + std::to_wstring(year);
	}

	r3d::rolesCT player::chooseRandomPrimaryRoleCT()
	{
		int randomRole = effolkronium::random_thread_local::get<int>(0, 4);

		return magic_enum::enum_cast<r3d::rolesCT>(randomRole).value();
	}

	r3d::rolesTR player::chooseRandomPrimaryRoleTR()
	{
		int randomRole = effolkronium::random_thread_local::get<int>(0, 4);

		return magic_enum::enum_cast<r3d::rolesTR>(randomRole).value();
	}

	r3d::rolesCT player::chooseRandomSecondaryRoleCT()
	{
		int randomRole;

		do
		{
			int randomRole = effolkronium::random_thread_local::get<int>(0, 4);

		} while (randomRole == magic_enum::enum_integer(this->_primaryRoleCT));

		return magic_enum::enum_cast<r3d::rolesCT>(randomRole).value();
	}

	r3d::rolesTR player::chooseRandomSecondaryRoleTR()
	{
		int randomRole;

		do
		{
			randomRole = effolkronium::random_thread_local::get<int>(0, 4);

		} while (randomRole == magic_enum::enum_integer(this->_primaryRoleTR));

		return magic_enum::enum_cast<r3d::rolesTR>(randomRole).value();
	}

	std::uint8_t player::createRandomSkillLevel()
	{
		return effolkronium::random_thread_local::get<int>(55, 100);
	}

	std::uint8_t player::createRandomSkillLevelByTier(int tier)
	{
		switch (tier)
		{
		case 100:
			return effolkronium::random_thread_local::get<int>(95, 100);

		case 200:
			return effolkronium::random_thread_local::get<int>(92, 96);

		case 300:
			return effolkronium::random_thread_local::get<int>(89, 93);

		case 400:
			return effolkronium::random_thread_local::get<int>(85, 90);

		case 500:
			return effolkronium::random_thread_local::get<int>(82, 87);

		case 600:
			return effolkronium::random_thread_local::get<int>(78, 84);

		case 700:
			return effolkronium::random_thread_local::get<int>(69, 80);

		case 800:
			return effolkronium::random_thread_local::get<int>(64, 72);

		case 900:
			return effolkronium::random_thread_local::get<int>(55, 67);

		}
		return 0;
	}
}