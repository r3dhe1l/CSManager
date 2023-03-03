#include "coach.hpp"
#include "random.hpp"
#include "magic_enum.hpp"
#include "thirdParty/nicknameGenerator/dasmig/nicknamegen.hpp"
#include "countryChoiceFunctions.hpp"

namespace r3d
{
	coach::coach()
		: _age(10), _gender(dasmig::ng::gender::m), _nationality(country::availableCountries::Brazil), _rating(100)
	{}

	coach::coach(std::wstring name, std::wstring nickname, country::availableCountries nationality, std::wstring born, dasmig::ng::gender gender, std::uint8_t rating,
		std::wstring currentDate)
		: _name(name), _nickname(nickname), _nationality(nationality), _born(born), _gender(gender), _age(setAge(currentDate)), _rating(rating)
	{}

	coach::coach(country::availableCountries country, dasmig::ng::gender gender)
		: _name(createRandomName(country, gender)), _nickname(createRandomNick(this->_name)), _nationality(country), _born(createRandomBorn()), _gender(gender),
		_age(setAge(L"07/02/2023")), _rating(createRandomRating())
	{}

	coach::coach(country::availableCountries country, int tier, dasmig::ng::gender gender)
		: _name(createRandomName(country, gender)), _nickname(createRandomNick(this->_name)), _nationality(country), _born(createRandomBorn()), _gender(gender),
		_age(setAge(L"09/02/2023")), _rating(createRandomRatingByTier(tier))
	{}

	std::uint8_t coach::setAge(std::wstring currentDate)
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

	std::uint8_t coach::getRating()
	{
		return this->_rating;
	}

	country::availableCountries coach::getNationality()
	{
		return this->_nationality;
	}

	void coach::showInformation()
	{
		//std::wcout << L"Nome do treinador é " << this->_name << L"\nNickname do treinador é " << this->_nickname << L"\nNacionalidade é " << this->_nationality <<
			//L"\nNasceu em " << this->_born << L"\nSexo " << this->_gender << L"\nCom rating de " << this->_rating << L"\nE tem " << this->_age << L" anos\n";
	}

	std::wstring coach::createRandomName(country::availableCountries& country, dasmig::ng::gender& gender)
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

	std::wstring coach::createRandomNick(std::wstring& name)
	{
		return dasmig::nng::instance().get_nickname(name);
	}

	std::wstring coach::createRandomBorn()
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

		std::wstring dayString, monthString;

		day > 9 ? (dayString = std::to_wstring(day)) : dayString = L"0" + std::to_wstring(day);
		month > 9 ? (monthString = std::to_wstring(month)) : monthString = L"0" + std::to_wstring(month);

		return dayString + L"/" + monthString + L"/" + std::to_wstring(year);
	}

	std::uint8_t coach::createRandomRating()
	{
		return effolkronium::random_thread_local::get<int>(55, 100);
	}

	std::uint8_t coach::createRandomRatingByTier(int tier)
	{
		switch (tier)
		{
		case 100:
			return effolkronium::random_thread_local::get<int>(82, 100);

		case 200:
			return effolkronium::random_thread_local::get<int>(78, 84);

		case 300:
			return effolkronium::random_thread_local::get<int>(69, 80);

		case 400:
			return effolkronium::random_thread_local::get<int>(64, 72);

		case 500:
			return effolkronium::random_thread_local::get<int>(55, 67);
		}
		return 0;
	}
};
