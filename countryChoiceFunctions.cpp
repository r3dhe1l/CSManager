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
		std::size_t countriesLimitVector = 0;
		std::size_t numberCountriesVector = 0;
		std::string randomCountry = "";

		for (int i = 0; i < numCountries; i++)
		{
			do
			{
				randomCountry = availableCountries.at(effolkronium::random_thread_local::get<int>(0, 18));
				countriesLimitVector = (int)std::round(numCountries * teamsCountryDistribution.at(randomCountry));
				numberCountriesVector = std::count(teamsCountriesVector.begin(), teamsCountriesVector.end(), randomCountry);

			} while (countriesLimitVector <= numberCountriesVector);

			teamsCountriesVector.at(i) = randomCountry;
		}
		return teamsCountriesVector;
	}

	std::vector <std::string> playersCreateCountriesVector(const std::size_t numCountries)
	{
		std::vector <std::string> playersCountriesVector{ numCountries };
		std::size_t countriesLimitVector = 0;
		std::size_t numberCountriesVector = 0;
		std::string randomCountry = "";

		for (int i = 0; i < numCountries; i++)
		{
			do
			{
				randomCountry = availableCountries.at(effolkronium::random_thread_local::get<std::size_t>(1, (availableCountries.size() - 2)));
				countriesLimitVector = (int)std::round(numCountries * playersCountryDistribution.at(randomCountry));
				numberCountriesVector = std::count(playersCountriesVector.begin(), playersCountriesVector.end(), randomCountry);

			} while (countriesLimitVector <= numberCountriesVector);

			playersCountriesVector.at(i) = randomCountry;
		}
		return playersCountriesVector;
	}

	std::vector <std::string> playersGetCountriesByRankingRange(std::vector <std::string> sortedPlayerCountriesVector, std::size_t beginIndex, std::size_t endIndex,
																std::vector <std::string> countriesToDraw, std::string tierPlayer)
	{
		std::size_t countriesLimitVector = 0;
		std::size_t numberCountriesVector = 0;
		std::string randomCountry = "";

		for (beginIndex; beginIndex < endIndex; beginIndex++)
		{
			do
			{
				randomCountry = countriesToDraw.at(effolkronium::random_thread_local::get<std::size_t>(0, countriesToDraw.size() - 1));
				countriesLimitVector = (int)std::round(sortedPlayerCountriesVector.size() * playersCountryDistribution.at(randomCountry));
				numberCountriesVector = std::count(sortedPlayerCountriesVector.begin(), sortedPlayerCountriesVector.end(), randomCountry);

			} while (countriesLimitVector <= numberCountriesVector);

			sortedPlayerCountriesVector.at(beginIndex) = randomCountry;
			sortedPlayerCountriesVector.at(beginIndex + (sortedPlayerCountriesVector.size() / 2)) = tierPlayer;
		}

		return sortedPlayerCountriesVector;
	}

	std::vector <std::string> playersCountriesSortBySkillLevel(const std::size_t numTeams)
	{
		std::size_t numPlayers = numTeams * 6;
		std::vector <std::string> sortedPlayerCountriesVector{ numPlayers * 2 };

		std::size_t beginIndex = 0;
		std::size_t endIndex = (int)std::round(numPlayers * 0.00184); //tier 1 = define 2 highest overall for 1080 players or 180 teams
		std::vector <std::string> avaibleCountriesForTier = { "Sweden", "Sweden", "France", "France", "Ukraine", "Ukraine", "Brazil", "Brazil", "Denmark", "Bosnia", "Slovakia" };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, "A");

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.00278); //tier 1 = define 3-5 for 1080 players or 180 teams
		avaibleCountriesForTier = { "Russia", "Russia", "Russia", "Denmark", "Denmark", "Denmark", "Bosnia", "Bosnia", "Poland", "Poland", "Sweden", "France", "Ukraine", "Brazil",
									"Norway", "United States" };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, "B");

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.00463); //tier 1 = define 6-10 for 1080 players or 180 teams
		avaibleCountriesForTier = { "Sweden", "Sweden", "Sweden", "France", "France", "France", "Denmark", "Denmark", "Russia", "Russia", "Ukraine", "Brazil", "United States",
									"Slovakia", "Canada", "Latvia", "Estonia", "Kazakhstan", "Belgium", "Germany" };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, "C");

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.00927); //tier 1 = define 11 - 20 for 1080 players or 180 teams
		avaibleCountriesForTier = { "Denmark", "Denmark", "Denmark", "Sweden", "Sweden", "Sweden", "France", "France", "Brazil", "Brazil", "Bosnia", "Bosnia", "United States",
									"United States", "Russia", "Ukraine", "Poland", "Slovakia", "Canada", "Latvia", "Estonia", "Norway", "Kazakhstan", "Finland", "Israel",
									"Australia", "Czech Republic", "Turkey", "Bulgaria" };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, "D");

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.02778); //tier 1 = define 21 - 50 for 1080 players or 180 teams
		avaibleCountriesForTier = { "Denmark", "Sweden", "France", "Russia", "Ukraine", "Brazil", "Bosnia", "Poland", "United States", "Slovakia", "Canada", "Latvia",
									"Estonia", "Norway", "Kazakhstan", "Israel", "Australia", "Czech Republic", "Germany", "United Kingdom", "Hungary", "Netherlands",
									"Serbia" };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, "E");

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.09261); //tier 2 = define 51 - 150 for 1080 players or 180 teams
		avaibleCountriesForTier = { "Argentina", "Australia", "Brazil", "Czech Republic", "Denmark", "Finland", "France", "Germany", "Mongolia", "Poland", "Portugal", "Russia",
									"Sweden", "Turkey", "Ukraine", "United Kingdom", "United States", "Belgium", "Bosnia", "Bulgaria", "Canada", "Chile", "Estonia", "Hungary",
									"Israel", "Kazakhstan", "Kosovo", "Latvia", "Montenegro", "Netherlands", "Norway", "Romania", "Serbia", "Slovakia", "South Africa", "Spain",
									"Switzerland", "Uruguay", };//whitout China, Mexico and New Zealand
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, "F");

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.46295); //tier 3 = define 151 - 650 for 1080 players or 180 teams
		avaibleCountriesForTier = { "Argentina", "Australia", "Brazil", "China", "Czech Republic", "Denmark", "Finland", "France", "Germany", "Mongolia", "Poland", "Portugal",
									"Russia", "Sweden", "Turkey", "Ukraine", "United Kingdom", "United States", "Belgium", "Bosnia", "Bulgaria", "Canada", "Chile", "Estonia",
									"Hungary", "Israel", "Kazakhstan", "Kosovo", "Latvia", "Mexico", "Montenegro", "Netherlands", "New Zealand", "Norway", "Romania", "Serbia",
									"Slovakia", "South Africa", "Spain", "Switzerland", "Uruguay", };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, "G");

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.23148); //tier 4 = define 651 - 900 for 1080 players or 180 teams
		avaibleCountriesForTier = { "Argentina", "Australia", "Brazil", "China", "Czech Republic", "Denmark", "Finland", "France", "Germany", "Mongolia", "Poland", "Portugal",
									"Russia", "Sweden", "Turkey", "Ukraine", "United Kingdom", "United States", "Belgium", "Bosnia", "Bulgaria", "Canada", "Chile", "Estonia",
									"Hungary", "Israel", "Kazakhstan", "Kosovo", "Latvia", "Mexico", "Montenegro", "Netherlands", "New Zealand", "Norway", "Romania", "Serbia",
									"Slovakia", "South Africa", "Spain", "Switzerland", "Uruguay", };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, "H");

		beginIndex = endIndex;
		endIndex = numPlayers;
		avaibleCountriesForTier = { "Argentina", "Australia", "Brazil", "China", "Czech Republic", "Denmark", "Finland", "France", "Germany", "Mongolia", "Poland", "Portugal",
									"Russia", "Sweden", "Turkey", "Ukraine", "United Kingdom", "United States", "Belgium", "Bosnia", "Bulgaria", "Canada", "Chile", "Estonia",
									"Hungary", "Israel", "Kazakhstan", "Kosovo", "Latvia", "Mexico", "Montenegro", "Netherlands", "New Zealand", "Norway", "Romania", "Serbia",
									"Slovakia", "South Africa", "Spain", "Switzerland", "Uruguay", };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, "I");

		return sortedPlayerCountriesVector;
	}

	std::vector <r3d::player> createPlayersVector(const std::size_t numTeams)
	{
		std::vector <r3d::player> playersVector{ numTeams * 6 };
		std::vector <std::string> countriesAndTierSkill = playersCountriesSortBySkillLevel(numTeams);

		for (int i = 0; i < playersVector.size(); i++)
		{
			playersVector.at(i) = r3d::player(countriesAndTierSkill.at(i), countriesAndTierSkill.at(i + (numTeams * 6))[0], 'm');
		}

		return playersVector;
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