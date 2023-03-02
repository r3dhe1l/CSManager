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

	team::team(std::wstring name, std::wstring country, std::wstring region, std::wstring creationDate, std::vector <r3d::player> players, r3d::coach coach)
		: _name(name), _country(country), _region(region), _creationDate(creationDate), _numberPlayers(this->_playersVector.size()), _playersVector(players), _coach(coach),
		_rolesCTFilled(fillRolesCT()), _rolesTRFilled(fillRolesTR())
	{}

	team::team(std::vector <r3d::player> players)
		: _name(L"Team's Name"), _playersVector(players), _numberPlayers(this->_playersVector.size()), _creationDate(createRandomFounding()), _country(playersDefineCountry()),
		_region(countryDefineRegion()), _rolesCTFilled(fillRolesCT()), _rolesTRFilled(fillRolesTR())
	{}

	team::team(std::wstring name)
		: _name(name), _numberPlayers(this->_playersVector.size()), _creationDate(createRandomFounding()), _rolesCTFilled(fillRolesCT()), _rolesTRFilled(fillRolesTR())
	{}

	void team::addPlayerToTeam(r3d::player player)
	{
		if (this->_numberPlayers < 4)
		{
			this->_playersVector.push_back(player);
			this->_numberPlayers = _playersVector.size();
			this->_country = playersDefineCountry();
			this->_region = countryDefineRegion();
			this->_rolesCTFilled = fillRolesCT();
			this->_rolesTRFilled = fillRolesTR();
		}
		else if (this->_numberPlayers == 4)
		{
			this->_playersVector.push_back(player);
			this->_numberPlayers = _playersVector.size();
			this->_country = playersDefineCountry();
			this->_region = countryDefineRegion();
			this->_rolesCTFilled = fillRolesCT();
			this->_rolesTRFilled = fillRolesTR();
		}
	}

	void team::addCoachToTeam(r3d::coach coach)
	{
		if (this->_coach.getName() == L"")
		{
			this->_coach = coach;
		}
	}

	std::vector <r3d::player> team::playersDraft(std::vector <r3d::player> possiblePlayers)
	{
		if (this->_numberPlayers == 0)
		{
			addPlayerToTeam(possiblePlayers.at(0));
			possiblePlayers.erase(possiblePlayers.begin());
		}
		int maxPlayers = 5 - (int)this->_numberPlayers;
		for (int i = 0; i < maxPlayers; i++)
		{
			int index = avaiblePlayer(possiblePlayers);
			addPlayerToTeam(possiblePlayers.at(index));
			possiblePlayers.erase(possiblePlayers.begin() + index);
		}
		return possiblePlayers;
	}

	std::vector <r3d::coach> team::coachDraft(std::vector <r3d::coach> possibleCoach)
	{
		if (this->_coach.getName() == L"")
		{
			int index = avaibleCoach(possibleCoach);
			addCoachToTeam(possibleCoach.at(index));
			possibleCoach.erase(possibleCoach.begin() + index);
		}
		return possibleCoach;
	}

	void team::showInformation()
	{
		std::wcout << this->_name << L" " << this->_country << L" " << this->_region << L" " << this->_creationDate << L" " << this->_numberPlayers << std::endl;
		for (int i = 0; i < this->_numberPlayers; i++)
		{
			std::wcout << this->_playersVector.at(i).getSkillLevel() << L" - " << this->_rolesCTFilled.at(i) << L" - " << this->_rolesTRFilled.at(i) <<
				L" - " << this->_playersVector.at(i).getNationality() << std::endl;
		}
		if (this->_coach.getName() != L"")
		{
			std::wcout << L"coach: " << this->_coach.getRating() << std::endl;
		}

	}

	std::wstring team::playersDefineCountry()
	{
		std::vector <std::wstring> playersNationalityVector{ 5 };
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

	std::wstring team::countryDefineRegion()
	{
		std::wstring region;
		this->_country == r3d::availableCountries.at(0) ? region = determineInternationalTeamRegion() : region = *r3d::countryGetRegion(this->_country);
		return region;
	}

	std::wstring team::determineInternationalTeamRegion()
	{
		std::vector <std::wstring> playersRegionVector{ 5 };

		for (int i = 0; i < this->_numberPlayers; i++)
		{
			playersRegionVector.at(i) = *r3d::countryGetRegion(this->_playersVector.at(i).getNationality());
		}

		std::vector <int> vectorNumberOfPLayersByRegion = {
			(int)std::count(playersRegionVector.begin(), playersRegionVector.end(), L"Europe"),
			(int)std::count(playersRegionVector.begin(), playersRegionVector.end(), L"CIS"),
			(int)std::count(playersRegionVector.begin(), playersRegionVector.end(), L"Americas"),
			(int)std::count(playersRegionVector.begin(), playersRegionVector.end(), L"Asia"),
			(int)std::count(playersRegionVector.begin(), playersRegionVector.end(), L"Oceania") };

		if (vectorNumberOfPLayersByRegion.at(0) > 2)
		{
			return L"Europe";
		}
		else if (vectorNumberOfPLayersByRegion.at(1) > 2)
		{
			return L"CIS";
		}
		else if (vectorNumberOfPLayersByRegion.at(2) > 2)
		{
			return L"Americas";
		}
		else if (vectorNumberOfPLayersByRegion.at(3) > 2)
		{
			return L"Asia";
		}
		else if (vectorNumberOfPLayersByRegion.at(4) > 2)
		{
			return L"Oceania";
		}
		else
		{
			auto it = std::find(vectorNumberOfPLayersByRegion.begin(), vectorNumberOfPLayersByRegion.end(), 2);

			int index = (int)std::distance(vectorNumberOfPLayersByRegion.begin(), it);

			switch (index)
			{
			case 1:
				return L"CIS";
			case 2:
				return L"Americas";
			case 3:
				return L"Asia";
			case 4:
				return L"Oceania";
			default:
				break;
			}
			return L"Europe";
		}
	}

	std::wstring team::createRandomFounding()
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

		std::wstring dayString, monthString;

		day > 9 ? (dayString = std::to_wstring(day)) : dayString = L"0" + std::to_wstring(day);
		month > 9 ? (monthString = std::to_wstring(month)) : monthString = L"0" + std::to_wstring(month);

		return dayString + L"/" + monthString + L"/" + std::to_wstring(year);
	}

	std::vector<std::wstring> team::fillRolesCT()
	{
		std::vector<std::wstring> rolesCT{ 5 };

		for (int i = 0; i < this->_numberPlayers; i++)
		{
			std::find(rolesCT.begin(), rolesCT.end(), this->_playersVector.at(i).getPrimaryRoleCT()) == rolesCT.end() ?
				rolesCT.at(i) = this->_playersVector.at(i).getPrimaryRoleCT() : rolesCT.at(i) = this->_playersVector.at(i).getSecondaryRoleCT();
		}

		return rolesCT;
	}

	std::vector<std::wstring> team::fillRolesTR()
	{
		std::vector<std::wstring> rolesTR{ 5 };

		for (int i = 0; i < this->_numberPlayers; i++)
		{
			std::find(rolesTR.begin(), rolesTR.end(), this->_playersVector.at(i).getPrimaryRoleTR()) == rolesTR.end() ?
				rolesTR.at(i) = this->_playersVector.at(i).getPrimaryRoleTR() : rolesTR.at(i) = this->_playersVector.at(i).getSecondaryRoleTR();
		}

		return rolesTR;
	}

	int team::avaiblePlayer(std::vector <r3d::player> possiblePlayers)
	{
		for (int i = 0; i < possiblePlayers.size(); i++)
		{
			if ((this->_playersVector.at(0).getSkillLevel() - 10) < possiblePlayers.at(i).getSkillLevel() &&
				(this->_playersVector.at(0).getSkillLevel() + 10) > possiblePlayers.at(i).getSkillLevel())
			{
				if (std::find(this->_rolesCTFilled.begin(), this->_rolesCTFilled.end(), possiblePlayers.at(i).getPrimaryRoleCT()) == this->_rolesCTFilled.end() ||
					std::find(this->_rolesCTFilled.begin(), this->_rolesCTFilled.end(), possiblePlayers.at(i).getSecondaryRoleCT()) == this->_rolesCTFilled.end())
				{
					if (std::find(this->_rolesTRFilled.begin(), this->_rolesTRFilled.end(), possiblePlayers.at(i).getPrimaryRoleTR()) == this->_rolesTRFilled.end() ||
						std::find(this->_rolesTRFilled.begin(), this->_rolesTRFilled.end(), possiblePlayers.at(i).getSecondaryRoleTR()) == this->_rolesTRFilled.end())
					{
						if (r3d::countryGetRegion(this->_playersVector.at(0).getNationality()) == r3d::countryGetRegion(possiblePlayers.at(i).getNationality()))
						{
							if (this->_playersVector.at(0).getNationality() == possiblePlayers.at(i).getNationality())
							{
								return i;
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < possiblePlayers.size(); i++)
		{
			if ((this->_playersVector.at(0).getSkillLevel() - 10) < possiblePlayers.at(i).getSkillLevel() &&
				(this->_playersVector.at(0).getSkillLevel() + 10) > possiblePlayers.at(i).getSkillLevel())
			{
				if (std::find(this->_rolesCTFilled.begin(), this->_rolesCTFilled.end(), possiblePlayers.at(i).getPrimaryRoleCT()) == this->_rolesCTFilled.end() ||
					std::find(this->_rolesCTFilled.begin(), this->_rolesCTFilled.end(), possiblePlayers.at(i).getSecondaryRoleCT()) == this->_rolesCTFilled.end())
				{
					if (std::find(this->_rolesTRFilled.begin(), this->_rolesTRFilled.end(), possiblePlayers.at(i).getPrimaryRoleTR()) == this->_rolesTRFilled.end() ||
						std::find(this->_rolesTRFilled.begin(), this->_rolesTRFilled.end(), possiblePlayers.at(i).getSecondaryRoleTR()) == this->_rolesTRFilled.end())
					{
						if (r3d::countryGetRegion(this->_playersVector.at(0).getNationality()) == r3d::countryGetRegion(possiblePlayers.at(i).getNationality()))
						{
							return i;
						}
					}
				}
			}
		}

		for (int i = 0; i < possiblePlayers.size(); i++)
		{
			if ((this->_playersVector.at(0).getSkillLevel() - 10) < possiblePlayers.at(i).getSkillLevel() &&
				(this->_playersVector.at(0).getSkillLevel() + 10) > possiblePlayers.at(i).getSkillLevel())
			{
				if (std::find(this->_rolesCTFilled.begin(), this->_rolesCTFilled.end(), possiblePlayers.at(i).getPrimaryRoleCT()) == this->_rolesCTFilled.end() ||
					std::find(this->_rolesCTFilled.begin(), this->_rolesCTFilled.end(), possiblePlayers.at(i).getSecondaryRoleCT()) == this->_rolesCTFilled.end())
				{
					if (std::find(this->_rolesTRFilled.begin(), this->_rolesTRFilled.end(), possiblePlayers.at(i).getPrimaryRoleTR()) == this->_rolesTRFilled.end() ||
						std::find(this->_rolesTRFilled.begin(), this->_rolesTRFilled.end(), possiblePlayers.at(i).getSecondaryRoleTR()) == this->_rolesTRFilled.end())
					{
						return i;
					}
				}
			}
		}

		return effolkronium::random_thread_local::get<int>(0, (int)possiblePlayers.size() - 1);
	}

	int team::avaibleCoach(std::vector <r3d::coach> possibleCoachs)
	{
		for (int i = 0; i < possibleCoachs.size(); i++)
		{
			if ((this->_playersVector.at(0).getSkillLevel() - 10) < possibleCoachs.at(i).getRating() &&
				(this->_playersVector.at(0).getSkillLevel() + 10) > possibleCoachs.at(i).getRating())
			{
				if (r3d::countryGetRegion(this->_playersVector.at(0).getNationality()) == r3d::countryGetRegion(possibleCoachs.at(i).getNationality()))
				{
					if (this->_playersVector.at(0).getNationality() == possibleCoachs.at(i).getNationality())
					{
						return i;
					}
				}
			}
		}

		for (int i = 0; i < possibleCoachs.size(); i++)
		{
			if ((this->_playersVector.at(0).getSkillLevel() - 10) < possibleCoachs.at(i).getRating() &&
				(this->_playersVector.at(0).getSkillLevel() + 10) > possibleCoachs.at(i).getRating())
			{
				if (r3d::countryGetRegion(this->_playersVector.at(0).getNationality()) == r3d::countryGetRegion(possibleCoachs.at(i).getNationality()))
				{
					return i;
				}
			}
		}

		for (int i = 0; i < possibleCoachs.size(); i++)
		{
			if ((this->_playersVector.at(0).getSkillLevel() - 10) < possibleCoachs.at(i).getRating() &&
				(this->_playersVector.at(0).getSkillLevel() + 10) > possibleCoachs.at(i).getRating())
			{
				return i;
			}
		}

		return effolkronium::random_thread_local::get<int>(0, (int)possibleCoachs.size() - 1);
	}
}