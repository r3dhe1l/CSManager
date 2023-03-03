#include "team.hpp"
#include "random.hpp"
#include "magic_enum.hpp"
#include "countryChoiceFunctions.hpp"
#include "coach.hpp"
#include "player.hpp"


namespace r3d
{
	team::team()
		: _country(country::availableCountries::Brazil), _numberPlayers(0), _region(country::availableRegions::Americas)
	{}

	team::team(std::wstring name, country::availableCountries country, country::availableRegions region, std::wstring creationDate, std::vector <player> players, coach coach)
		: _name(name), _country(country), _region(region), _creationDate(creationDate), _numberPlayers(this->_playersVector.size()), _playersVector(players), _coach(coach),
		_rolesCTFilled(fillRolesCT()), _rolesTRFilled(fillRolesTR())
	{}

	team::team(std::vector <player> players)
		: _name(L"Team's Name"), _playersVector(players), _numberPlayers(this->_playersVector.size()), _creationDate(createRandomFounding()), _country(playersDefineCountry()),
		_region(countryDefineRegion()), _rolesCTFilled(fillRolesCT()), _rolesTRFilled(fillRolesTR())
	{}

	team::team(std::wstring name)
		: _name(name), _numberPlayers(this->_playersVector.size()), _creationDate(createRandomFounding()), _rolesCTFilled(fillRolesCT()), _rolesTRFilled(fillRolesTR())
	{}

	void team::addPlayerToTeam(player player)
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

	void team::addCoachToTeam(coach coach)
	{
		if (this->_coach.getName() == L"")
		{
			this->_coach = coach;
		}
	}

	std::vector <player> team::playersDraft(std::vector <player> possiblePlayers)
	{
		if (this->_numberPlayers == 0)
		{
			addPlayerToTeam(possiblePlayers.at(0));
			possiblePlayers.erase(possiblePlayers.begin());
		}
		int maxPlayers = 5 - (int)this->_numberPlayers;
		for (int i = 0; i < maxPlayers; i++)
		{
			int index = availablePlayer(possiblePlayers);
			addPlayerToTeam(possiblePlayers.at(index));
			possiblePlayers.erase(possiblePlayers.begin() + index);
		}
		return possiblePlayers;
	}

	std::vector <coach> team::coachDraft(std::vector <coach> possibleCoach)
	{
		if (this->_coach.getName() == L"")
		{
			int index = availableCoach(possibleCoach);
			addCoachToTeam(possibleCoach.at(index));
			possibleCoach.erase(possibleCoach.begin() + index);
		}
		return possibleCoach;
	}

	void team::showInformation()
	{
		//std::wcout << this->_name << L" " << this->_country << L" " << this->_region << L" " << this->_creationDate << L" " << this->_numberPlayers << std::endl;
		//for (int i = 0; i < this->_numberPlayers; i++)
		//{
		//	std::wcout << this->_playersVector.at(i).getSkillLevel() << L" - " << this->_rolesCTFilled.at(i) << L" - " << this->_rolesTRFilled.at(i) <<
		//		L" - " << this->_playersVector.at(i).getNationality() << std::endl;
		//}
		//if (this->_coach.getName() != L"")
		//{
		//	std::wcout << L"coach: " << this->_coach.getRating() << std::endl;
		//}

	}

	country::availableCountries team::playersDefineCountry()
	{
		std::vector <country::availableCountries> playersNationalityVector{ 5 };
		std::int64_t numCountries;

		for (int i = 0; i < this->_numberPlayers; i++)
		{
			playersNationalityVector.at(i) = this->_playersVector.at(i).getNationality();
		}

		for (int i = 0; i < magic_enum::enum_count<country::availableCountries>(); i++)
		{
			numCountries = std::count(playersNationalityVector.begin(), playersNationalityVector.end(), magic_enum::enum_value<country::availableCountries>(i));

			if (numCountries > 2)
			{
				return magic_enum::enum_value<country::availableCountries>(i);
			}
		}
		return magic_enum::enum_value<country::availableCountries>(0);
	}

	country::availableRegions team::countryDefineRegion()
	{
		return this->_country == magic_enum::enum_value<country::availableCountries>(0) ? determineInternationalTeamRegion() : countryGetRegion(this->_country);
	}

	country::availableRegions team::determineInternationalTeamRegion()
	{
		std::vector <country::availableRegions> playersRegionVector{ this->_numberPlayers };

		for (int i = 0; i < this->_numberPlayers; i++)
		{
			playersRegionVector.at(i) = countryGetRegion(this->_playersVector.at(i).getNationality());
		}

		std::vector <int> vectorNumberOfPLayersByRegion = {
			(int)std::count(playersRegionVector.begin(), playersRegionVector.end(), country::availableRegions::Western_Europe),
			(int)std::count(playersRegionVector.begin(), playersRegionVector.end(), country::availableRegions::Eastern_Europe),
			(int)std::count(playersRegionVector.begin(), playersRegionVector.end(), country::availableRegions::CIS),
			(int)std::count(playersRegionVector.begin(), playersRegionVector.end(), country::availableRegions::Americas),
			(int)std::count(playersRegionVector.begin(), playersRegionVector.end(), country::availableRegions::Asia),
			(int)std::count(playersRegionVector.begin(), playersRegionVector.end(), country::availableRegions::Oceania) };

		if (vectorNumberOfPLayersByRegion.at(0) > 2)
		{
			return country::availableRegions::Western_Europe;
		}
		else if (vectorNumberOfPLayersByRegion.at(1) > 2)
		{
			return country::availableRegions::Eastern_Europe;
		}
		else if (vectorNumberOfPLayersByRegion.at(2) > 2)
		{
			return country::availableRegions::CIS;
		}
		else if (vectorNumberOfPLayersByRegion.at(3) > 2)
		{
			return country::availableRegions::Americas;
		}
		else if (vectorNumberOfPLayersByRegion.at(4) > 2)
		{
			return country::availableRegions::Asia;
		}
		else if (vectorNumberOfPLayersByRegion.at(5) > 2)
		{
			return country::availableRegions::Oceania;
		}
		else
		{
			auto it = std::find(vectorNumberOfPLayersByRegion.begin(), vectorNumberOfPLayersByRegion.end(), 2);

			int index = (int)std::distance(vectorNumberOfPLayersByRegion.begin(), it);

			switch (index)
			{
			case 0:
				return country::availableRegions::Western_Europe;
			case 1:
				return country::availableRegions::Eastern_Europe;
			case 2:
				return country::availableRegions::CIS;
			case 3:
				return country::availableRegions::Americas;
			case 4:
				return country::availableRegions::Asia;
			case 5:
				return country::availableRegions::Oceania;
			default:
				return vectorNumberOfPLayersByRegion.at(0) == 1 ? country::availableRegions::Western_Europe : country::availableRegions::Eastern_Europe;
			}
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

	std::vector <role::rolesCT> team::fillRolesCT()
	{
		std::vector<role::rolesCT> rolesCT{ this->_numberPlayers };

		for (int i = 0; i < this->_numberPlayers; i++)
		{
			std::find(rolesCT.begin(), rolesCT.end(), this->_playersVector.at(i).getPrimaryRoleCT()) == rolesCT.end() ?
				rolesCT.at(i) = this->_playersVector.at(i).getPrimaryRoleCT() : rolesCT.at(i) = this->_playersVector.at(i).getSecondaryRoleCT();
		}

		return rolesCT;
	}

	std::vector <role::rolesTR> team::fillRolesTR()
	{
		std::vector<role::rolesTR> rolesTR{ this->_numberPlayers };

		for (int i = 0; i < this->_numberPlayers; i++)
		{
			std::find(rolesTR.begin(), rolesTR.end(), this->_playersVector.at(i).getPrimaryRoleTR()) == rolesTR.end() ?
				rolesTR.at(i) = this->_playersVector.at(i).getPrimaryRoleTR() : rolesTR.at(i) = this->_playersVector.at(i).getSecondaryRoleTR();
		}

		return rolesTR;
	}

	int team::availablePlayer(std::vector <player> possiblePlayers)
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
						if (countryGetRegion(this->_playersVector.at(0).getNationality()) == countryGetRegion(possiblePlayers.at(i).getNationality()))
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
						if (countryGetRegion(this->_playersVector.at(0).getNationality()) == countryGetRegion(possiblePlayers.at(i).getNationality()))
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

	int team::availableCoach(std::vector <coach> possibleCoachs)
	{
		for (int i = 0; i < possibleCoachs.size(); i++)
		{
			if ((this->_playersVector.at(0).getSkillLevel() - 10) < possibleCoachs.at(i).getRating() &&
				(this->_playersVector.at(0).getSkillLevel() + 10) > possibleCoachs.at(i).getRating())
			{
				if (countryGetRegion(this->_playersVector.at(0).getNationality()) == countryGetRegion(possibleCoachs.at(i).getNationality()))
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
				if (countryGetRegion(this->_playersVector.at(0).getNationality()) == countryGetRegion(possibleCoachs.at(i).getNationality()))
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
};