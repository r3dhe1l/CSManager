#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/randomLibrary/random.hpp"
#include "player.hpp"
#include "coach.hpp"
#include "team.hpp"
#include "countryChoiceFunctions.hpp"

namespace r3d
{
	team::team()
	{
		this->_numberPlayers = 0;
	}

	team::team(std::wstring name, std::string country, std::string region, std::string creationDate, std::vector <r3d::player> players, r3d::coach coach)
		: _name(name), _country(country), _region(region), _creationDate(creationDate), _numberPlayers(this->_playersVector.size()), _playersVector(players), _coach(coach)
	{}

	team::team(std::vector <r3d::player> players)
		: _name(L"Team's Name"), _playersVector(players), _numberPlayers(this->_playersVector.size()), _creationDate(createRandomFounding()), _country(playersDefineCountry()),
		_region(countryDefineRegion())
	{}

	void team::addPlayerToTeam(r3d::player player)
	{
		if (this->_numberPlayers < 5)
		{
			this->_playersVector.push_back(player);
			this->_country = playersDefineCountry();
			this->_region = countryDefineRegion();
		}
	}

	void team::addCoachToTeam(r3d::coach coach)
	{
		if (this->_coach.getName() == L"")
		{
			this->_coach = coach;
		}
	}

	std::string team::playersDefineCountry()
	{
		std::vector <std::string> playersNationalityVector;
		int index;
		std::int64_t numCountries;

		for (int i = 0; i < this->_numberPlayers; i++)
		{
			playersNationalityVector.at(i) = this->_playersVector.at(i).getNationality();
		}

		for (int i = 0; i < r3d::availableCountries.size(); i++)
		{
			numCountries = std::count(playersNationalityVector.begin(), playersNationalityVector.end(), r3d::availableCountries.at(i));
			index = i;

			if (numCountries > 2)
			{
				return r3d::availableCountries.at(index);
			}
		}
		return r3d::availableCountries.at(0);
	}

	std::string team::countryDefineRegion()
	{
		if (this->_country == r3d::availableCountries.at(0))
		{
			determineInternationalTeamRegion();
		}

		return *r3d::countryGetRegion(this->_country);
	}

	std::string team::determineInternationalTeamRegion()
	{
		std::vector <std::string> playersRegionVector;

		for (int i = 0; i < this->_numberPlayers; i++)
		{
			playersRegionVector.at(i) = *r3d::countryGetRegion(this->_playersVector.at(i).getNationality());
		}

		std::vector <int> vectorNumberOfPLayersByRegion = {
			(int)std::count(playersRegionVector.begin(), playersRegionVector.end(), "Europe"),
			(int)std::count(playersRegionVector.begin(), playersRegionVector.end(), "CIS"),
			(int)std::count(playersRegionVector.begin(), playersRegionVector.end(), "Americas"),
			(int)std::count(playersRegionVector.begin(), playersRegionVector.end(), "Asia"),
			(int)std::count(playersRegionVector.begin(), playersRegionVector.end(), "Oceania") };

		auto it = std::find(vectorNumberOfPLayersByRegion.begin(), vectorNumberOfPLayersByRegion.end(), 2);

		int index = (int)std::distance(vectorNumberOfPLayersByRegion.begin(), it);

		switch (index)
		{
		case 1:
			return "CIS";
		case 2:
			return "Americas";
		case 3:
			return "Asia";
		case 4:
			return "Oceania";
		default:
			break;
		}

		return "Europe";
	}

	std::string team::createRandomFounding()
	{
		int year, month, day = 0;
		year = effolkronium::random_thread_local::get<int>(2013, 2022);
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
}