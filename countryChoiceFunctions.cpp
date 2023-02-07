#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdint>
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/randomLibrary/random.hpp"
#include "countryChoiceFunctions.hpp"

namespace r3d
{
	std::vector <std::string> teamsCreateCountriesVector(const std::size_t numCountries)
	{
		std::vector <std::string> teamsCountriesVector{ numCountries };
		float countriesLimitVector = 0;
		std::int64_t numberCountriesVector = 0;
		std::string randomCountry = "";

		for (int i = 0; i < numCountries; i++)
		{
			do
			{
				randomCountry = availableCountries.at(effolkronium::random_thread_local::get<int>(0, 18));
				countriesLimitVector = std::round(numCountries * teamsRegionalDistribution.at(randomCountry));
				numberCountriesVector = std::count(teamsCountriesVector.begin(), teamsCountriesVector.end(), randomCountry);
			
			} while (countriesLimitVector <= numberCountriesVector);
			
			teamsCountriesVector.at(i) = randomCountry;
		}
		return teamsCountriesVector;
	}

	std::vector <std::string> playersCreateCountriesVector(const std::size_t numCountries)
	{
		std::vector <std::string> playersCountriesVector{ numCountries };
		float countriesLimitVector = 0;
		std::int64_t numberCountriesVector = 0;
		std::string randomCountry = "";

		for (int i = 0; i < numCountries; i++)
		{
			do
			{
				randomCountry = availableCountries.at(effolkronium::random_thread_local::get<std::size_t>(1, (availableCountries.size() - 2)));
				countriesLimitVector = std::round(numCountries * playersRegionalDistribution.at(randomCountry));
				numberCountriesVector = std::count(playersCountriesVector.begin(), playersCountriesVector.end(), randomCountry);

			} while (countriesLimitVector <= numberCountriesVector);

			playersCountriesVector.at(i) = randomCountry;
		}
		return playersCountriesVector;
	}

	std::vector <std::string> countriesTeamsPlayers(const std::size_t numTeams)
	{
		const size_t sizeVector = std::floor(numTeams * 9.2) + 2;
		std::vector <std::string> listOfTeamsPlayers{ sizeVector };
		std::vector <std::string> countriesTeams = teamsCreateCountriesVector(numTeams);
		std::vector <std::string> countriesPlayers = playersCreateCountriesVector(std::floor(numTeams * 7.2));
		int x = 1;
		listOfTeamsPlayers.at(numTeams * 8) = "Free Players";
		listOfTeamsPlayers.at(numTeams * 9 + 1) = "Free Coachs";

		for (int i = 0; i <= (numTeams * 8 - 8); i += 8)
		{
			std::size_t randomNumber = effolkronium::random_thread_local::get<std::size_t>(0, countriesTeams.size() - 1);
			listOfTeamsPlayers.at(i) = "Team number " + std::to_string(x++);
			listOfTeamsPlayers.at(i + 1) = "Country Team " + countriesTeams.at(randomNumber);
			countriesTeams.erase(countriesTeams.begin() + randomNumber);
		}

		for (int i = 0; i < sizeVector; i++)
		{
			if (listOfTeamsPlayers.at(i) == "")
			{
				std::size_t randomNumber = effolkronium::random_thread_local::get<std::size_t>(0, countriesPlayers.size() - 1);
				listOfTeamsPlayers.at(i) = "Country Player " + countriesPlayers.at(randomNumber);
				countriesPlayers.erase(countriesPlayers.begin() + randomNumber);
			}
		}

		return listOfTeamsPlayers;
	}

	const std::string* countryGetCulture(const std::string& country)
	{
		if (countryToCulture.contains(country))
		{
			return &countryToCulture.at(country);
		}

		return &availableCountries.at(availableCountries.size() - 1);
	}

	const std::wstring* countryGetCode(const std::string& country)
	{
		if (countryToCode.contains(country))
		{
			return &countryToCode.at(country);
		}

		return &countryToCode.at("International"); //return Country not found.
	}

	const std::string* countryGetRegion(const std::string& country)
	{
		if (countryToRegion.contains(country))
		{
			return &countryToRegion.at(country);
		}

		return &availableCountries.at(availableCountries.size() - 1);
	}
}