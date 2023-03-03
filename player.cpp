#include "player.hpp"
#include "random.hpp"
#include "magic_enum.hpp"
#include "thirdParty/nicknameGenerator/dasmig/nicknamegen.hpp"
#include "countryChoiceFunctions.hpp"

namespace r3d
{
	player::player()
		: _age(10), _gender(dasmig::ng::gender::m), _nationality(country::availableCountries::Brazil), _primaryRoleCT(role::rolesCT::Mid), _primaryRoleTR(role::rolesTR::Joker),
		_secondaryRoleCT(role::rolesCT::Joker), _secondaryRoleTR(role::rolesTR::Entry), _skillLevel(100)
	{}

	player::player(std::wstring name, std::wstring nickname, country::availableCountries nationality, std::wstring born, role::rolesCT primaryRoleCT, role::rolesTR primaryRoleTR,
		role::rolesCT secondaryRoleCT, role::rolesTR secondaryRoleTR, dasmig::ng::gender gender, std::uint8_t skillLevel, std::wstring currentDate)
		: _name(name), _nickname(nickname), _nationality(nationality), _born(born), _primaryRoleCT(primaryRoleCT), _primaryRoleTR(primaryRoleTR),
		_secondaryRoleCT(secondaryRoleCT), _secondaryRoleTR(secondaryRoleTR), _gender(gender), _age(setAge(currentDate)), _skillLevel(skillLevel)
	{}

	player::player(country::availableCountries country, dasmig::ng::gender gender)
		: _name(createRandomName(country, gender)), _nickname(createRandomNick(this->_name)), _nationality(country), _born(createRandomBorn()),
		_primaryRoleCT(chooseRandomPrimaryRoleCT()), _primaryRoleTR(chooseRandomPrimaryRoleTR()), _secondaryRoleCT(chooseRandomSecondaryRoleCT()),
		_secondaryRoleTR(chooseRandomSecondaryRoleTR()), _gender(gender), _age(setAge(L"12/02/2023")), _skillLevel(createRandomSkillLevel())
	{}

	player::player(country::availableCountries country, int tier, dasmig::ng::gender gender)
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

	country::availableCountries player::getNationality()
	{
		return this->_nationality;
	}

	role::rolesCT player::getPrimaryRoleCT()
	{
		return this->_primaryRoleCT;
	}

	role::rolesTR player::getPrimaryRoleTR()
	{
		return this->_primaryRoleTR;
	}

	role::rolesCT player::getSecondaryRoleCT()
	{
		return this->_secondaryRoleCT;
	}

	role::rolesTR player::getSecondaryRoleTR()
	{
		return this->_secondaryRoleTR;
	}

	std::uint8_t player::getSkillLevel()
	{
		return this->_skillLevel;
	}

	void player::showInformation()
	{
		std::string country{ magic_enum::enum_name<country::availableCountries>(this->_nationality) };
		std::string primaryRoleCT{ magic_enum::enum_name<role::rolesCT>(this->_primaryRoleCT) };
		std::string primaryRoleTR{ magic_enum::enum_name<role::rolesTR>(this->_primaryRoleTR) };
		std::string gender{ magic_enum::enum_name<dasmig::ng::gender>(this->_gender) };

		std::wcout << L"Nome do Jogador é " << this->_name << L"\nNickname do jogador é " << this->_nickname << L"\nNacionalidade é " << country.c_str() <<
			L"\nNasceu em " << this->_born << L"\nJoga de CT como " << primaryRoleCT.c_str() << L"\nJOga de TR como " << primaryRoleTR.c_str() << L"\nSexo " <<
			gender.c_str() << L"\nCom skill level de " << this->_skillLevel << L"\nE tem " << this->_age << L" anos\n";
	}

	std::wstring player::createRandomName(country::availableCountries& country, dasmig::ng::gender& gender)
	{
		int random = effolkronium::random_thread_local::get<int>(1, 30);

		switch (random)
		{
		case 10:
			return dasmig::ng::instance().get_name(gender, countryGetNGCulture(country)).append_name().append_surname();
		case 20:
			return dasmig::ng::instance().get_name(gender, countryGetNGCulture(country)).append_surname().append_surname();
		case 30:
			return dasmig::ng::instance().get_name(gender, countryGetNGCulture(country)).append_name().append_surname().append_surname();
		default:
			break;
		}

		return dasmig::ng::instance().get_name(gender, countryGetNGCulture(country)).append_surname();
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

	role::rolesCT player::chooseRandomPrimaryRoleCT()
	{
		int randomRole = effolkronium::random_thread_local::get<int>(0, 4);

		return magic_enum::enum_cast<role::rolesCT>(randomRole).value();
	}

	role::rolesTR player::chooseRandomPrimaryRoleTR()
	{
		int randomRole = effolkronium::random_thread_local::get<int>(0, 4);

		return magic_enum::enum_cast<role::rolesTR>(randomRole).value();
	}

	role::rolesCT player::chooseRandomSecondaryRoleCT()
	{
		int randomRole;

		do
		{
			randomRole = effolkronium::random_thread_local::get<int>(0, 4);

		} while (randomRole == magic_enum::enum_integer(this->_primaryRoleCT));

		return magic_enum::enum_cast<role::rolesCT>(randomRole).value();
	}

	role::rolesTR player::chooseRandomSecondaryRoleTR()
	{
		int randomRole;

		do
		{
			randomRole = effolkronium::random_thread_local::get<int>(0, 4);

		} while (randomRole == magic_enum::enum_integer(this->_primaryRoleTR));

		return magic_enum::enum_cast<role::rolesTR>(randomRole).value();
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