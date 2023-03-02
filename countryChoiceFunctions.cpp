#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdint>
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/randomLibrary/random.hpp"
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/nameGenerator/dasmig/namegen.hpp"
#include "countryChoiceFunctions.hpp"
#include "magic_enum.hpp"

namespace r3d
{
	std::vector <int> playersGetCountriesByRankingRange(std::vector <int> sortedPlayerCountriesVector, int beginIndex, int endIndex,
		std::vector <r3d::country::avaibleCountries> countriesToDraw, int tierPlayer)
	{
		int countriesLimitVector = 0;
		int numberCountriesVector = 0;
		r3d::country::avaibleCountries randomCountry;

		for (beginIndex; beginIndex < endIndex; beginIndex++)
		{
			do
			{
				randomCountry = countriesToDraw.at(effolkronium::random_thread_local::get<std::size_t>(0, countriesToDraw.size() - 1));
				countriesLimitVector = (int)std::round(sortedPlayerCountriesVector.size() * playersCountryDistribution.at(randomCountry));
				numberCountriesVector = std::count(sortedPlayerCountriesVector.begin(), sortedPlayerCountriesVector.end(), magic_enum::enum_integer(randomCountry));

			} while (countriesLimitVector <= numberCountriesVector);

			sortedPlayerCountriesVector.at(beginIndex) = magic_enum::enum_integer(randomCountry);
			sortedPlayerCountriesVector.at(beginIndex + (sortedPlayerCountriesVector.size() / 2)) = tierPlayer;
		}

		return sortedPlayerCountriesVector;
	}

	std::vector <int> playersCountriesSortBySkillLevel(const int numPlayers)
	{
		std::vector <int> sortedPlayerCountriesVector{ numPlayers * 2 };

		int beginIndex = 0;
		int endIndex = (int)std::round(numPlayers * 0.00184); //tier 1 = define 2 highest overall for 1080 players or 180 teams
		std::vector <r3d::country::avaibleCountries> avaibleCountriesForTier = { r3d::country::avaibleCountries::Sweden, r3d::country::avaibleCountries::Sweden, r3d::country::avaibleCountries::France,
			r3d::country::avaibleCountries::France, r3d::country::avaibleCountries::Ukraine, r3d::country::avaibleCountries::Ukraine, r3d::country::avaibleCountries::Brazil, r3d::country::avaibleCountries::Brazil,
			r3d::country::avaibleCountries::Denmark, r3d::country::avaibleCountries::Bosnia, r3d::country::avaibleCountries::Slovakia };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, 100);

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.00278); //tier 1 = define 3-5 for 1080 players or 180 teams
		avaibleCountriesForTier = { r3d::country::avaibleCountries::Russia, r3d::country::avaibleCountries::Russia, r3d::country::avaibleCountries::Russia, r3d::country::avaibleCountries::Denmark,
			r3d::country::avaibleCountries::Denmark, r3d::country::avaibleCountries::Denmark, r3d::country::avaibleCountries::Bosnia, r3d::country::avaibleCountries::Bosnia, r3d::country::avaibleCountries::Poland,
			r3d::country::avaibleCountries::Poland, r3d::country::avaibleCountries::Sweden, r3d::country::avaibleCountries::France, r3d::country::avaibleCountries::Ukraine, r3d::country::avaibleCountries::Brazil,
			r3d::country::avaibleCountries::Norway, r3d::country::avaibleCountries::United_States };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, 200);

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.00463); //tier 1 = define 6-10 for 1080 players or 180 teams
		avaibleCountriesForTier = { r3d::country::avaibleCountries::Sweden, r3d::country::avaibleCountries::Sweden, r3d::country::avaibleCountries::Sweden, r3d::country::avaibleCountries::France,
			r3d::country::avaibleCountries::France, r3d::country::avaibleCountries::France, r3d::country::avaibleCountries::Denmark, r3d::country::avaibleCountries::Denmark, r3d::country::avaibleCountries::Russia,
			r3d::country::avaibleCountries::Russia, r3d::country::avaibleCountries::Ukraine, r3d::country::avaibleCountries::Brazil, r3d::country::avaibleCountries::United_States, r3d::country::avaibleCountries::Slovakia,
			r3d::country::avaibleCountries::Canada, r3d::country::avaibleCountries::Latvia, r3d::country::avaibleCountries::Estonia, r3d::country::avaibleCountries::Kazakhstan, r3d::country::avaibleCountries::Belgium,
			r3d::country::avaibleCountries::Germany };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, 300);

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.00927); //tier 1 = define 11 - 20 for 1080 players or 180 teams
		avaibleCountriesForTier = { r3d::country::avaibleCountries::Denmark, r3d::country::avaibleCountries::Denmark, r3d::country::avaibleCountries::Denmark, r3d::country::avaibleCountries::Sweden,
			r3d::country::avaibleCountries::Sweden, r3d::country::avaibleCountries::Sweden, r3d::country::avaibleCountries::France, r3d::country::avaibleCountries::France, r3d::country::avaibleCountries::Brazil,
			r3d::country::avaibleCountries::Brazil, r3d::country::avaibleCountries::Bosnia, r3d::country::avaibleCountries::Bosnia, r3d::country::avaibleCountries::United_States,
			r3d::country::avaibleCountries::United_States, r3d::country::avaibleCountries::Russia, r3d::country::avaibleCountries::Ukraine, r3d::country::avaibleCountries::Poland, r3d::country::avaibleCountries::Slovakia,
			r3d::country::avaibleCountries::Canada, r3d::country::avaibleCountries::Latvia, r3d::country::avaibleCountries::Estonia, r3d::country::avaibleCountries::Norway, r3d::country::avaibleCountries::Kazakhstan,
			r3d::country::avaibleCountries::Finland, r3d::country::avaibleCountries::Israel, r3d::country::avaibleCountries::Australia, r3d::country::avaibleCountries::Czech_Republic,
			r3d::country::avaibleCountries::Turkey, r3d::country::avaibleCountries::Bulgaria };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, 400);

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.02778); //tier 1 = define 21 - 50 for 1080 players or 180 teams
		avaibleCountriesForTier = { r3d::country::avaibleCountries::Denmark, r3d::country::avaibleCountries::Sweden, r3d::country::avaibleCountries::France, r3d::country::avaibleCountries::Russia,
			r3d::country::avaibleCountries::Ukraine, r3d::country::avaibleCountries::Brazil, r3d::country::avaibleCountries::Bosnia, r3d::country::avaibleCountries::Poland, r3d::country::avaibleCountries::United_States,
			r3d::country::avaibleCountries::Slovakia, r3d::country::avaibleCountries::Canada, r3d::country::avaibleCountries::Latvia, r3d::country::avaibleCountries::Estonia, r3d::country::avaibleCountries::Norway,
			r3d::country::avaibleCountries::Kazakhstan, r3d::country::avaibleCountries::Israel, r3d::country::avaibleCountries::Australia, r3d::country::avaibleCountries::Czech_Republic,
			r3d::country::avaibleCountries::Germany, r3d::country::avaibleCountries::United_Kingdom, r3d::country::avaibleCountries::Hungary, r3d::country::avaibleCountries::Netherlands,
			r3d::country::avaibleCountries::Serbia };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, 500);

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.09261); //tier 2 = define 51 - 150 for 1080 players or 180 teams
		avaibleCountriesForTier = { r3d::country::avaibleCountries::Argentina, r3d::country::avaibleCountries::Australia, r3d::country::avaibleCountries::Brazil, r3d::country::avaibleCountries::Czech_Republic,
			r3d::country::avaibleCountries::Denmark, r3d::country::avaibleCountries::Finland, r3d::country::avaibleCountries::France, r3d::country::avaibleCountries::Germany, r3d::country::avaibleCountries::Mongolia,
			r3d::country::avaibleCountries::Poland, r3d::country::avaibleCountries::Portugal, r3d::country::avaibleCountries::Russia, r3d::country::avaibleCountries::Sweden, r3d::country::avaibleCountries::Turkey,
			r3d::country::avaibleCountries::Ukraine, r3d::country::avaibleCountries::United_Kingdom, r3d::country::avaibleCountries::United_States, r3d::country::avaibleCountries::Belgium,
			r3d::country::avaibleCountries::Bosnia, r3d::country::avaibleCountries::Bulgaria, r3d::country::avaibleCountries::Canada, r3d::country::avaibleCountries::Chile, r3d::country::avaibleCountries::Estonia,
			r3d::country::avaibleCountries::Hungary, r3d::country::avaibleCountries::Israel, r3d::country::avaibleCountries::Kazakhstan, r3d::country::avaibleCountries::Kosovo, r3d::country::avaibleCountries::Latvia,
			r3d::country::avaibleCountries::Montenegro, r3d::country::avaibleCountries::Netherlands, r3d::country::avaibleCountries::Norway, r3d::country::avaibleCountries::Romania, r3d::country::avaibleCountries::Serbia,
			r3d::country::avaibleCountries::Slovakia, r3d::country::avaibleCountries::South_Africa, r3d::country::avaibleCountries::Spain, r3d::country::avaibleCountries::Switzerland,
			r3d::country::avaibleCountries::Uruguay };//whitout China, Mexico and New Zealand
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, 600);

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.46295); //tier 3 = define 151 - 650 for 1080 players or 180 teams
		avaibleCountriesForTier = { r3d::country::avaibleCountries::Argentina, r3d::country::avaibleCountries::Australia, r3d::country::avaibleCountries::Brazil, r3d::country::avaibleCountries::China,
			r3d::country::avaibleCountries::Czech_Republic, r3d::country::avaibleCountries::Denmark, r3d::country::avaibleCountries::Finland, r3d::country::avaibleCountries::France, r3d::country::avaibleCountries::Germany,
			r3d::country::avaibleCountries::Mongolia, r3d::country::avaibleCountries::Poland, r3d::country::avaibleCountries::Portugal, r3d::country::avaibleCountries::Russia, r3d::country::avaibleCountries::Sweden,
			r3d::country::avaibleCountries::Turkey, r3d::country::avaibleCountries::Ukraine, r3d::country::avaibleCountries::United_Kingdom, r3d::country::avaibleCountries::United_States,
			r3d::country::avaibleCountries::Belgium, r3d::country::avaibleCountries::Bosnia, r3d::country::avaibleCountries::Bulgaria, r3d::country::avaibleCountries::Canada, r3d::country::avaibleCountries::Chile,
			r3d::country::avaibleCountries::Estonia, r3d::country::avaibleCountries::Hungary, r3d::country::avaibleCountries::Israel, r3d::country::avaibleCountries::Kazakhstan, r3d::country::avaibleCountries::Kosovo,
			r3d::country::avaibleCountries::Latvia, r3d::country::avaibleCountries::Mexico, r3d::country::avaibleCountries::Montenegro, r3d::country::avaibleCountries::Netherlands,
			r3d::country::avaibleCountries::New_Zealand, r3d::country::avaibleCountries::Norway, r3d::country::avaibleCountries::Romania, r3d::country::avaibleCountries::Serbia, r3d::country::avaibleCountries::Slovakia,
			r3d::country::avaibleCountries::South_Africa, r3d::country::avaibleCountries::Spain, r3d::country::avaibleCountries::Switzerland, r3d::country::avaibleCountries::Uruguay };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, 700);

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.23148); //tier 4 = define 651 - 900 for 1080 players or 180 teams
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, 800);

		beginIndex = endIndex;
		endIndex = numPlayers; //tier 5 = define 901 - 1080 for 1080 players or 180 teams
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, 900);

		return sortedPlayerCountriesVector;
	}

	std::vector <r3d::player> createPlayersVector(const std::size_t numTeams)
	{
		std::vector <r3d::player> playersVector{ numTeams * 6 };
		std::vector <int> countriesAndTierSkill = playersCountriesSortBySkillLevel(numTeams * 6);

		for (int i = 0; i < playersVector.size(); i++)
		{
			playersVector.at(i) = r3d::player(magic_enum::enum_cast<r3d::country::avaibleCountries>(countriesAndTierSkill.at(i)).value(), countriesAndTierSkill.at(i + (numTeams * 6)),
				dasmig::ng::gender::m);
		}

		return playersVector;
	}

	std::vector <int> coachGetCountriesByRankingRange(std::vector <int> sortedCoachCountriesVector, int beginIndex, int endIndex,
		std::vector <r3d::country::avaibleCountries> countriesToDraw, int tierCoach)
	{
		int countriesLimitVector = 0;
		int numberCountriesVector = 0;
		r3d::country::avaibleCountries randomCountry;

		for (beginIndex; beginIndex < endIndex; beginIndex++)
		{
			do
			{
				randomCountry = countriesToDraw.at(effolkronium::random_thread_local::get<std::size_t>(0, countriesToDraw.size() - 1));
				countriesLimitVector = (int)std::round(sortedCoachCountriesVector.size() * coachsCountryDistribution.at(randomCountry));
				numberCountriesVector = std::count(sortedCoachCountriesVector.begin(), sortedCoachCountriesVector.end(), magic_enum::enum_integer(randomCountry));

			} while (countriesLimitVector <= numberCountriesVector);

			sortedCoachCountriesVector.at(beginIndex) = magic_enum::enum_integer(randomCountry);
			sortedCoachCountriesVector.at(beginIndex + (sortedCoachCountriesVector.size() / 2)) = tierCoach;
		}

		return sortedCoachCountriesVector;
	}

	std::vector <int> coachsCountriesSortBySkillLevel(const int numCoachs)
	{
		std::vector <int> sortedCoachCountriesVector{ numCoachs * 2 };

		int beginIndex = 0;
		int endIndex = (int)std::round(numCoachs * 0.047); //tier 1
		std::vector <r3d::country::avaibleCountries> avaibleCountriesForTier = { r3d::country::avaibleCountries::Australia, r3d::country::avaibleCountries::Brazil, r3d::country::avaibleCountries::Czech_Republic,
			r3d::country::avaibleCountries::Denmark, r3d::country::avaibleCountries::Finland, r3d::country::avaibleCountries::France, r3d::country::avaibleCountries::Germany, r3d::country::avaibleCountries::Poland,
			r3d::country::avaibleCountries::Russia, r3d::country::avaibleCountries::Sweden, r3d::country::avaibleCountries::Turkey, r3d::country::avaibleCountries::Ukraine, r3d::country::avaibleCountries::United_Kingdom,
			r3d::country::avaibleCountries::United_States, r3d::country::avaibleCountries::Belgium, r3d::country::avaibleCountries::Bosnia, r3d::country::avaibleCountries::Bulgaria, r3d::country::avaibleCountries::Canada,
			r3d::country::avaibleCountries::Estonia, r3d::country::avaibleCountries::Hungary, r3d::country::avaibleCountries::Israel, r3d::country::avaibleCountries::Kazakhstan, r3d::country::avaibleCountries::Latvia,
			r3d::country::avaibleCountries::Netherlands, r3d::country::avaibleCountries::Norway, r3d::country::avaibleCountries::Serbia, r3d::country::avaibleCountries::Slovakia };
		sortedCoachCountriesVector = coachGetCountriesByRankingRange(sortedCoachCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, 100);

		beginIndex = endIndex;
		endIndex += (int)std::round(numCoachs * 0.094); //tier 2
		avaibleCountriesForTier = { r3d::country::avaibleCountries::Argentina, r3d::country::avaibleCountries::Australia, r3d::country::avaibleCountries::Brazil, r3d::country::avaibleCountries::Czech_Republic,
			r3d::country::avaibleCountries::Denmark, r3d::country::avaibleCountries::Finland, r3d::country::avaibleCountries::France, r3d::country::avaibleCountries::Germany, r3d::country::avaibleCountries::Mongolia,
			r3d::country::avaibleCountries::Poland, r3d::country::avaibleCountries::Portugal, r3d::country::avaibleCountries::Russia, r3d::country::avaibleCountries::Sweden, r3d::country::avaibleCountries::Turkey,
			r3d::country::avaibleCountries::Ukraine, r3d::country::avaibleCountries::United_Kingdom, r3d::country::avaibleCountries::United_States, r3d::country::avaibleCountries::Belgium,
			r3d::country::avaibleCountries::Bosnia, r3d::country::avaibleCountries::Bulgaria, r3d::country::avaibleCountries::Canada, r3d::country::avaibleCountries::Chile, r3d::country::avaibleCountries::Estonia, 
			r3d::country::avaibleCountries::Hungary, r3d::country::avaibleCountries::Israel, r3d::country::avaibleCountries::Kazakhstan, r3d::country::avaibleCountries::Kosovo, r3d::country::avaibleCountries::Latvia,
			r3d::country::avaibleCountries::Montenegro, r3d::country::avaibleCountries::Netherlands, r3d::country::avaibleCountries::Norway, r3d::country::avaibleCountries::Romania, r3d::country::avaibleCountries::Serbia,
			r3d::country::avaibleCountries::Slovakia, r3d::country::avaibleCountries::South_Africa, r3d::country::avaibleCountries::Spain, r3d::country::avaibleCountries::Switzerland,
			r3d::country::avaibleCountries::Uruguay };//whitout China, Mexico and New Zealand
		sortedCoachCountriesVector = coachGetCountriesByRankingRange(sortedCoachCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, 200);

		beginIndex = endIndex;
		endIndex += (int)std::round(numCoachs * 0.464); //tier 3
		avaibleCountriesForTier = { r3d::country::avaibleCountries::Argentina, r3d::country::avaibleCountries::Australia, r3d::country::avaibleCountries::Brazil, r3d::country::avaibleCountries::China,
			r3d::country::avaibleCountries::Czech_Republic, r3d::country::avaibleCountries::Denmark, r3d::country::avaibleCountries::Finland, r3d::country::avaibleCountries::France, r3d::country::avaibleCountries::Germany,
			r3d::country::avaibleCountries::Mongolia, r3d::country::avaibleCountries::Poland, r3d::country::avaibleCountries::Portugal, r3d::country::avaibleCountries::Russia, r3d::country::avaibleCountries::Sweden,
			r3d::country::avaibleCountries::Turkey, r3d::country::avaibleCountries::Ukraine, r3d::country::avaibleCountries::United_Kingdom, r3d::country::avaibleCountries::United_States,
			r3d::country::avaibleCountries::Belgium, r3d::country::avaibleCountries::Bosnia, r3d::country::avaibleCountries::Bulgaria, r3d::country::avaibleCountries::Canada, r3d::country::avaibleCountries::Chile,
			r3d::country::avaibleCountries::Estonia, r3d::country::avaibleCountries::Hungary, r3d::country::avaibleCountries::Israel, r3d::country::avaibleCountries::Kazakhstan, r3d::country::avaibleCountries::Kosovo,
			r3d::country::avaibleCountries::Latvia, r3d::country::avaibleCountries::Mexico, r3d::country::avaibleCountries::Montenegro, r3d::country::avaibleCountries::Netherlands,
			r3d::country::avaibleCountries::New_Zealand, r3d::country::avaibleCountries::Norway, r3d::country::avaibleCountries::Romania, r3d::country::avaibleCountries::Serbia, r3d::country::avaibleCountries::Slovakia,
			r3d::country::avaibleCountries::South_Africa, r3d::country::avaibleCountries::Spain, r3d::country::avaibleCountries::Switzerland, r3d::country::avaibleCountries::Uruguay };
		sortedCoachCountriesVector = coachGetCountriesByRankingRange(sortedCoachCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, 300);

		beginIndex = endIndex;
		endIndex += (int)std::round(numCoachs * 0.232); //tier 4
		sortedCoachCountriesVector = coachGetCountriesByRankingRange(sortedCoachCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, 400);

		beginIndex = endIndex;
		endIndex = numCoachs; //tier 5
		sortedCoachCountriesVector = coachGetCountriesByRankingRange(sortedCoachCountriesVector, beginIndex, endIndex, avaibleCountriesForTier, 500);

		return sortedCoachCountriesVector;
	}

	std::vector <r3d::coach> createCoachsVector(const std::size_t numTeams)
	{
		int numCoachs = (int)std::floor(numTeams * 1.2);
		std::vector <r3d::coach> coachsVector{ numCoachs };
		std::vector <int> countriesAndTierSkill = coachsCountriesSortBySkillLevel(numCoachs);

		for (int i = 0; i < coachsVector.size(); i++)
		{
			coachsVector.at(i) = r3d::coach(magic_enum::enum_cast<r3d::country::avaibleCountries>(countriesAndTierSkill.at(i)).value(), countriesAndTierSkill.at(i + numCoachs),
				dasmig::ng::gender::m);
		}

		return coachsVector;
	}

	std::vector <r3d::team> createTeamsVector(const std::size_t numTeams)
	{
		std::vector <r3d::team> teamsVector{ numTeams };
		std::vector <r3d::player> playersVector = createPlayersVector(numTeams);
		std::vector <r3d::coach> coachsVector = createCoachsVector(numTeams);
		int x = 1;

		for (int i = 0; i < numTeams; i++)
		{
			teamsVector.at(i) = r3d::team(L"Team " + std::to_wstring(x++));
			playersVector = teamsVector.at(i).playersDraft(playersVector);
			coachsVector = teamsVector.at(i).coachDraft(coachsVector);
		}

		return teamsVector;
	}

	dasmig::ng::culture countryGetNGCulture(const r3d::country::avaibleCountries country)
	{
		switch (country)
		{
		case avaibleCountries::Argentina:
			return dasmig::ng::culture::argentinian;
		case avaibleCountries::Australia:
			return dasmig::ng::culture::australian;
		case avaibleCountries::Brazil:
			return dasmig::ng::culture::brazilian;
		case avaibleCountries::China:
			return dasmig::ng::culture::chinese;
		case avaibleCountries::Czech_Republic:
			return dasmig::ng::culture::polish; //Need to include czech culture
		case avaibleCountries::Denmark:
			return dasmig::ng::culture::danish;
		case avaibleCountries::Finland:
			return dasmig::ng::culture::finnish;
		case avaibleCountries::France:
			return dasmig::ng::culture::french;
		case avaibleCountries::Germany:
			return dasmig::ng::culture::german;
		case avaibleCountries::Mongolia:
			return dasmig::ng::culture::turkish; //Need to include mongolian culture
		case avaibleCountries::Poland:
			return dasmig::ng::culture::polish;
		case avaibleCountries::Portugal:
			return dasmig::ng::culture::portuguese;
		case avaibleCountries::Russia:
			return dasmig::ng::culture::russian;
		case avaibleCountries::Sweden:
			return dasmig::ng::culture::swedish;
		case avaibleCountries::Turkey:
			return dasmig::ng::culture::turkish;
		case avaibleCountries::Ukraine:
			return dasmig::ng::culture::ukrainian;
		case avaibleCountries::United_Kingdom:
			return dasmig::ng::culture::british;
		case avaibleCountries::United_States:
			return dasmig::ng::culture::american;
		case avaibleCountries::Belgium:
			return dasmig::ng::culture::french;
		case avaibleCountries::Bosnia:
			return dasmig::ng::culture::turkish;
		case avaibleCountries::Bulgaria:
			return dasmig::ng::culture::bulgarian;
		case avaibleCountries::Canada:
			return dasmig::ng::culture::canadian;
		case avaibleCountries::Chile:
			return dasmig::ng::culture::argentinian;
		case avaibleCountries::Estonia:
			return dasmig::ng::culture::russian;
		case avaibleCountries::Hungary:
			return dasmig::ng::culture::polish; //Switch to czech
		case avaibleCountries::Israel:
			return dasmig::ng::culture::russian;
		case avaibleCountries::Kazakhstan:
			return dasmig::ng::culture::kazakh;
		case avaibleCountries::Kosovo:
			return dasmig::ng::culture::turkish;
		case avaibleCountries::Latvia:
			return dasmig::ng::culture::russian;
		case avaibleCountries::Mexico:
			return dasmig::ng::culture::mexican;
		case avaibleCountries::Montenegro:
			return dasmig::ng::culture::bulgarian;
		case avaibleCountries::Netherlands:
			return dasmig::ng::culture::german;
		case avaibleCountries::NewZealand:
			return dasmig::ng::culture::australian;
		case avaibleCountries::Norway:
			return dasmig::ng::culture::norwegian;
		case avaibleCountries::Romania:
			return dasmig::ng::culture::bulgarian;
		case avaibleCountries::Serbia:
			return dasmig::ng::culture::bulgarian;
		case avaibleCountries::Slovakia:
			return dasmig::ng::culture::polish; //Switch to czech culture
		case avaibleCountries::South_Africa:
			return dasmig::ng::culture::american;
		case avaibleCountries::Spain:
			return dasmig::ng::culture::spanish;
		case avaibleCountries::Switzerland:
			return dasmig::ng::culture::german;
		case avaibleCountries::Uruguay:
			return dasmig::ng::culture::argentinian;
		};
	}

	r3d::country::avaibleRegions countryGetRegion(const r3d::country::avaibleCountries country)
	{
		switch (country)
		{
		case avaibleCountries::International:
			return avaibleRegions::International;
		case avaibleCountries::Argentina:
			return avaibleRegions::Americas;
		case avaibleCountries::Australia:
			return avaibleRegions::Oceania;
		case avaibleCountries::Brazil:
			return avaibleRegions::Americas;
		case avaibleCountries::China:
			return avaibleRegions::Asia;
		case avaibleCountries::Czech_Republic:
			return avaibleRegions::Eastern_Europe;
		case avaibleCountries::Denmark:
			return avaibleRegions::Western_Europe;
		case avaibleCountries::Finland:
			return avaibleRegions::Western_Europe;
		case avaibleCountries::France:
			return avaibleRegions::Western_Europe;
		case avaibleCountries::Germany:
			return avaibleRegions::Western_Europe;
		case avaibleCountries::Mongolia:
			return avaibleRegions::Asia;
		case avaibleCountries::Poland:
			return avaibleRegions::Eastern_Europe;
		case avaibleCountries::Portugal:
			return avaibleRegions::Western_Europe;
		case avaibleCountries::Russia:
			return avaibleRegions::CIS;
		case avaibleCountries::Sweden:
			return avaibleRegions::Western_Europe;
		case avaibleCountries::Turkey:
			return avaibleRegions::Eastern_Europe;
		case avaibleCountries::Ukraine:
			return avaibleRegions::CIS;
		case avaibleCountries::United_Kingdom:
			return avaibleRegions::Western_Europe;
		case avaibleCountries::United_States:
			return avaibleRegions::Americas;
		case avaibleCountries::Belgium:
			return avaibleRegions::Western_Europe;
		case avaibleCountries::Bosnia:
			return avaibleRegions::Eastern_Europe;
		case avaibleCountries::Bulgaria:
			return avaibleRegions::Eastern_Europe;
		case avaibleCountries::Canada:
			return avaibleRegions::Americas;
		case avaibleCountries::Chile:
			return avaibleRegions::Americas;
		case avaibleCountries::Estonia:
			return avaibleRegions::Eastern_Europe;
		case avaibleCountries::Hungary:
			return avaibleRegions::Eastern_Europe;
		case avaibleCountries::Israel:
			return avaibleRegions::Eastern_Europe;
		case avaibleCountries::Kazakhstan:
			return avaibleRegions::CIS;
		case avaibleCountries::Kosovo:
			return avaibleRegions::Eastern_Europe;
		case avaibleCountries::Latvia:
			return avaibleRegions::Eastern_Europe;
		case avaibleCountries::Mexico:
			return avaibleRegions::Americas;
		case avaibleCountries::Montenegro:
			return avaibleRegions::Eastern_Europe;
		case avaibleCountries::Netherlands:
			return avaibleRegions::Western_Europe;
		case avaibleCountries::NewZealand:
			return avaibleRegions::Oceania;
		case avaibleCountries::Norway:
			return avaibleRegions::Western_Europe;
		case avaibleCountries::Romania:
			return avaibleRegions::Eastern_Europe;
		case avaibleCountries::Serbia:
			return avaibleRegions::Eastern_Europe;
		case avaibleCountries::Slovakia:
			return avaibleRegions::Eastern_Europe;
		case avaibleCountries::South_Africa:
			return avaibleRegions::Americas;
		case avaibleCountries::Spain:
			return avaibleRegions::Western_Europe;
		case avaibleCountries::Switzerland:
			return avaibleRegions::Western_Europe;
		case avaibleCountries::Uruguay:
			return avaibleRegions::Americas;
		};
	}
}