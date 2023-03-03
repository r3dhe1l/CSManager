#include "countryChoiceFunctions.hpp"
#include "random.hpp"
#include "magic_enum.hpp"
#include "player.hpp"
#include "coach.hpp"
#include "team.hpp"

namespace r3d
{
	std::vector <int> playersGetCountriesByRankingRange(std::vector <int> sortedPlayerCountriesVector, int beginIndex, int endIndex,
		std::vector <country::availableCountries> countriesToDraw, int tierPlayer)
	{
		int countriesLimitVector = 0;
		int numberCountriesVector = 0;
		country::availableCountries randomCountry;

		for (beginIndex; beginIndex < endIndex; beginIndex++)
		{
			do
			{
				randomCountry = countriesToDraw.at(effolkronium::random_thread_local::get<std::size_t>(0, countriesToDraw.size() - 1));
				countriesLimitVector = (int)std::round(sortedPlayerCountriesVector.size() * country::playersCountryDistribution.at(randomCountry));
				numberCountriesVector = (int)std::count(sortedPlayerCountriesVector.begin(), sortedPlayerCountriesVector.end(), magic_enum::enum_integer(randomCountry));

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
		std::vector <country::availableCountries> availableCountriesForTier = { country::availableCountries::Sweden, country::availableCountries::Sweden, country::availableCountries::France,
			country::availableCountries::France, country::availableCountries::Ukraine, country::availableCountries::Ukraine, country::availableCountries::Brazil, country::availableCountries::Brazil,
			country::availableCountries::Denmark, country::availableCountries::Bosnia, country::availableCountries::Slovakia };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, availableCountriesForTier, 100);

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.00278); //tier 1 = define 3-5 for 1080 players or 180 teams
		availableCountriesForTier = { country::availableCountries::Russia, country::availableCountries::Russia, country::availableCountries::Russia, country::availableCountries::Denmark,
			country::availableCountries::Denmark, country::availableCountries::Denmark, country::availableCountries::Bosnia, country::availableCountries::Bosnia, country::availableCountries::Poland,
			country::availableCountries::Poland, country::availableCountries::Sweden, country::availableCountries::France, country::availableCountries::Ukraine, country::availableCountries::Brazil,
			country::availableCountries::Norway, country::availableCountries::United_States };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, availableCountriesForTier, 200);

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.00463); //tier 1 = define 6-10 for 1080 players or 180 teams
		availableCountriesForTier = { country::availableCountries::Sweden, country::availableCountries::Sweden, country::availableCountries::Sweden, country::availableCountries::France,
			country::availableCountries::France, country::availableCountries::France, country::availableCountries::Denmark, country::availableCountries::Denmark, country::availableCountries::Russia,
			country::availableCountries::Russia, country::availableCountries::Ukraine, country::availableCountries::Brazil, country::availableCountries::United_States, country::availableCountries::Slovakia,
			country::availableCountries::Canada, country::availableCountries::Latvia, country::availableCountries::Estonia, country::availableCountries::Kazakhstan, country::availableCountries::Belgium,
			country::availableCountries::Germany };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, availableCountriesForTier, 300);

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.00927); //tier 1 = define 11 - 20 for 1080 players or 180 teams
		availableCountriesForTier = { country::availableCountries::Denmark, country::availableCountries::Denmark, country::availableCountries::Denmark, country::availableCountries::Sweden,
			country::availableCountries::Sweden, country::availableCountries::Sweden, country::availableCountries::France, country::availableCountries::France, country::availableCountries::Brazil,
			country::availableCountries::Brazil, country::availableCountries::Bosnia, country::availableCountries::Bosnia, country::availableCountries::United_States,
			country::availableCountries::United_States, country::availableCountries::Russia, country::availableCountries::Ukraine, country::availableCountries::Poland, country::availableCountries::Slovakia,
			country::availableCountries::Canada, country::availableCountries::Latvia, country::availableCountries::Estonia, country::availableCountries::Norway, country::availableCountries::Kazakhstan,
			country::availableCountries::Finland, country::availableCountries::Israel, country::availableCountries::Australia, country::availableCountries::Czech_Republic,
			country::availableCountries::Turkey, country::availableCountries::Bulgaria };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, availableCountriesForTier, 400);

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.02778); //tier 1 = define 21 - 50 for 1080 players or 180 teams
		availableCountriesForTier = { country::availableCountries::Denmark, country::availableCountries::Sweden, country::availableCountries::France, country::availableCountries::Russia,
			country::availableCountries::Ukraine, country::availableCountries::Brazil, country::availableCountries::Bosnia, country::availableCountries::Poland, country::availableCountries::United_States,
			country::availableCountries::Slovakia, country::availableCountries::Canada, country::availableCountries::Latvia, country::availableCountries::Estonia, country::availableCountries::Norway,
			country::availableCountries::Kazakhstan, country::availableCountries::Israel, country::availableCountries::Australia, country::availableCountries::Czech_Republic,
			country::availableCountries::Germany, country::availableCountries::United_Kingdom, country::availableCountries::Hungary, country::availableCountries::Netherlands,
			country::availableCountries::Serbia };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, availableCountriesForTier, 500);

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.09261); //tier 2 = define 51 - 150 for 1080 players or 180 teams
		availableCountriesForTier = { country::availableCountries::Argentina, country::availableCountries::Australia, country::availableCountries::Brazil, country::availableCountries::Czech_Republic,
			country::availableCountries::Denmark, country::availableCountries::Finland, country::availableCountries::France, country::availableCountries::Germany, country::availableCountries::Mongolia,
			country::availableCountries::Poland, country::availableCountries::Portugal, country::availableCountries::Russia, country::availableCountries::Sweden, country::availableCountries::Turkey,
			country::availableCountries::Ukraine, country::availableCountries::United_Kingdom, country::availableCountries::United_States, country::availableCountries::Belgium,
			country::availableCountries::Bosnia, country::availableCountries::Bulgaria, country::availableCountries::Canada, country::availableCountries::Chile, country::availableCountries::Estonia,
			country::availableCountries::Hungary, country::availableCountries::Israel, country::availableCountries::Kazakhstan, country::availableCountries::Kosovo, country::availableCountries::Latvia,
			country::availableCountries::Montenegro, country::availableCountries::Netherlands, country::availableCountries::Norway, country::availableCountries::Romania, country::availableCountries::Serbia,
			country::availableCountries::Slovakia, country::availableCountries::South_Africa, country::availableCountries::Spain, country::availableCountries::Switzerland,
			country::availableCountries::Uruguay };//whitout China, Mexico and New Zealand
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, availableCountriesForTier, 600);

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.46295); //tier 3 = define 151 - 650 for 1080 players or 180 teams
		availableCountriesForTier = { country::availableCountries::Argentina, country::availableCountries::Australia, country::availableCountries::Brazil, country::availableCountries::China,
			country::availableCountries::Czech_Republic, country::availableCountries::Denmark, country::availableCountries::Finland, country::availableCountries::France, country::availableCountries::Germany,
			country::availableCountries::Mongolia, country::availableCountries::Poland, country::availableCountries::Portugal, country::availableCountries::Russia, country::availableCountries::Sweden,
			country::availableCountries::Turkey, country::availableCountries::Ukraine, country::availableCountries::United_Kingdom, country::availableCountries::United_States,
			country::availableCountries::Belgium, country::availableCountries::Bosnia, country::availableCountries::Bulgaria, country::availableCountries::Canada, country::availableCountries::Chile,
			country::availableCountries::Estonia, country::availableCountries::Hungary, country::availableCountries::Israel, country::availableCountries::Kazakhstan, country::availableCountries::Kosovo,
			country::availableCountries::Latvia, country::availableCountries::Mexico, country::availableCountries::Montenegro, country::availableCountries::Netherlands,
			country::availableCountries::New_Zealand, country::availableCountries::Norway, country::availableCountries::Romania, country::availableCountries::Serbia, country::availableCountries::Slovakia,
			country::availableCountries::South_Africa, country::availableCountries::Spain, country::availableCountries::Switzerland, country::availableCountries::Uruguay };
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, availableCountriesForTier, 700);

		beginIndex = endIndex;
		endIndex += (int)std::round(numPlayers * 0.23148); //tier 4 = define 651 - 900 for 1080 players or 180 teams
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, availableCountriesForTier, 800);

		beginIndex = endIndex;
		endIndex = numPlayers; //tier 5 = define 901 - 1080 for 1080 players or 180 teams
		sortedPlayerCountriesVector = playersGetCountriesByRankingRange(sortedPlayerCountriesVector, beginIndex, endIndex, availableCountriesForTier, 900);

		return sortedPlayerCountriesVector;
	}

	std::vector <player> createPlayersVector(const std::size_t numTeams)
	{
		std::vector <player> playersVector{ numTeams * 6 };
		std::vector <int> countriesAndTierSkill = playersCountriesSortBySkillLevel((int)numTeams * 6);

		for (int i = 0; i < playersVector.size(); i++)
		{
			playersVector.at(i) = player(magic_enum::enum_cast<country::availableCountries>(countriesAndTierSkill.at(i)).value(), countriesAndTierSkill.at(i + (numTeams * 6)),
				dasmig::ng::gender::m);
		}

		return playersVector;
	}

	std::vector <int> coachGetCountriesByRankingRange(std::vector <int> sortedCoachCountriesVector, int beginIndex, int endIndex,
		std::vector <country::availableCountries> countriesToDraw, int tierCoach)
	{
		int countriesLimitVector = 0;
		int numberCountriesVector = 0;
		country::availableCountries randomCountry;

		for (beginIndex; beginIndex < endIndex; beginIndex++)
		{
			do
			{
				randomCountry = countriesToDraw.at(effolkronium::random_thread_local::get<std::size_t>(0, countriesToDraw.size() - 1));
				countriesLimitVector = (int)std::round(sortedCoachCountriesVector.size() * country::coachsCountryDistribution.at(randomCountry));
				numberCountriesVector = (int)std::count(sortedCoachCountriesVector.begin(), sortedCoachCountriesVector.end(), magic_enum::enum_integer(randomCountry));

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
		std::vector <country::availableCountries> availableCountriesForTier = { country::availableCountries::Australia, country::availableCountries::Brazil, country::availableCountries::Czech_Republic,
			country::availableCountries::Denmark, country::availableCountries::Finland, country::availableCountries::France, country::availableCountries::Germany, country::availableCountries::Poland,
			country::availableCountries::Russia, country::availableCountries::Sweden, country::availableCountries::Turkey, country::availableCountries::Ukraine, country::availableCountries::United_Kingdom,
			country::availableCountries::United_States, country::availableCountries::Belgium, country::availableCountries::Bosnia, country::availableCountries::Bulgaria, country::availableCountries::Canada,
			country::availableCountries::Estonia, country::availableCountries::Hungary, country::availableCountries::Israel, country::availableCountries::Kazakhstan, country::availableCountries::Latvia,
			country::availableCountries::Netherlands, country::availableCountries::Norway, country::availableCountries::Serbia, country::availableCountries::Slovakia };
		sortedCoachCountriesVector = coachGetCountriesByRankingRange(sortedCoachCountriesVector, beginIndex, endIndex, availableCountriesForTier, 100);

		beginIndex = endIndex;
		endIndex += (int)std::round(numCoachs * 0.094); //tier 2
		availableCountriesForTier = { country::availableCountries::Argentina, country::availableCountries::Australia, country::availableCountries::Brazil, country::availableCountries::Czech_Republic,
			country::availableCountries::Denmark, country::availableCountries::Finland, country::availableCountries::France, country::availableCountries::Germany, country::availableCountries::Mongolia,
			country::availableCountries::Poland, country::availableCountries::Portugal, country::availableCountries::Russia, country::availableCountries::Sweden, country::availableCountries::Turkey,
			country::availableCountries::Ukraine, country::availableCountries::United_Kingdom, country::availableCountries::United_States, country::availableCountries::Belgium,
			country::availableCountries::Bosnia, country::availableCountries::Bulgaria, country::availableCountries::Canada, country::availableCountries::Chile, country::availableCountries::Estonia, 
			country::availableCountries::Hungary, country::availableCountries::Israel, country::availableCountries::Kazakhstan, country::availableCountries::Kosovo, country::availableCountries::Latvia,
			country::availableCountries::Montenegro, country::availableCountries::Netherlands, country::availableCountries::Norway, country::availableCountries::Romania, country::availableCountries::Serbia,
			country::availableCountries::Slovakia, country::availableCountries::South_Africa, country::availableCountries::Spain, country::availableCountries::Switzerland,
			country::availableCountries::Uruguay };//whitout China, Mexico and New Zealand
		sortedCoachCountriesVector = coachGetCountriesByRankingRange(sortedCoachCountriesVector, beginIndex, endIndex, availableCountriesForTier, 200);

		beginIndex = endIndex;
		endIndex += (int)std::round(numCoachs * 0.464); //tier 3
		availableCountriesForTier = { country::availableCountries::Argentina, country::availableCountries::Australia, country::availableCountries::Brazil, country::availableCountries::China,
			country::availableCountries::Czech_Republic, country::availableCountries::Denmark, country::availableCountries::Finland, country::availableCountries::France, country::availableCountries::Germany,
			country::availableCountries::Mongolia, country::availableCountries::Poland, country::availableCountries::Portugal, country::availableCountries::Russia, country::availableCountries::Sweden,
			country::availableCountries::Turkey, country::availableCountries::Ukraine, country::availableCountries::United_Kingdom, country::availableCountries::United_States,
			country::availableCountries::Belgium, country::availableCountries::Bosnia, country::availableCountries::Bulgaria, country::availableCountries::Canada, country::availableCountries::Chile,
			country::availableCountries::Estonia, country::availableCountries::Hungary, country::availableCountries::Israel, country::availableCountries::Kazakhstan, country::availableCountries::Kosovo,
			country::availableCountries::Latvia, country::availableCountries::Mexico, country::availableCountries::Montenegro, country::availableCountries::Netherlands,
			country::availableCountries::New_Zealand, country::availableCountries::Norway, country::availableCountries::Romania, country::availableCountries::Serbia, country::availableCountries::Slovakia,
			country::availableCountries::South_Africa, country::availableCountries::Spain, country::availableCountries::Switzerland, country::availableCountries::Uruguay };
		sortedCoachCountriesVector = coachGetCountriesByRankingRange(sortedCoachCountriesVector, beginIndex, endIndex, availableCountriesForTier, 300);

		beginIndex = endIndex;
		endIndex += (int)std::round(numCoachs * 0.232); //tier 4
		sortedCoachCountriesVector = coachGetCountriesByRankingRange(sortedCoachCountriesVector, beginIndex, endIndex, availableCountriesForTier, 400);

		beginIndex = endIndex;
		endIndex = numCoachs; //tier 5
		sortedCoachCountriesVector = coachGetCountriesByRankingRange(sortedCoachCountriesVector, beginIndex, endIndex, availableCountriesForTier, 500);

		return sortedCoachCountriesVector;
	}

	std::vector <coach> createCoachsVector(const std::size_t numTeams)
	{
		std::vector <coach> coachsVector{ (std::size_t)std::floor(numTeams * 1.2) };
		std::vector <int> countriesAndTierSkill = coachsCountriesSortBySkillLevel((int)std::floor(numTeams * 1.2));

		for (int i = 0; i < coachsVector.size(); i++)
		{
			coachsVector.at(i) = coach(magic_enum::enum_cast<country::availableCountries>(countriesAndTierSkill.at(i)).value(), countriesAndTierSkill.at(i + (int)std::floor(numTeams * 1.2)),
				dasmig::ng::gender::m);
		}

		return coachsVector;
	}

	std::vector <team> createTeamsVector(const std::size_t numTeams)
	{
		std::vector <team> teamsVector{ numTeams };
		std::vector <player> playersVector = createPlayersVector(numTeams);
		std::vector <coach> coachsVector = createCoachsVector(numTeams);
		int x = 1;

		for (int i = 0; i < numTeams; i++)
		{
			teamsVector.at(i) = team(L"Team " + std::to_wstring(x++));
			playersVector = teamsVector.at(i).playersDraft(playersVector);
			coachsVector = teamsVector.at(i).coachDraft(coachsVector);
		}

		return teamsVector;
	}

	dasmig::ng::culture countryGetNGCulture(const country::availableCountries country)
	{
		switch (country)
		{
		case country::availableCountries::Argentina:
			return dasmig::ng::culture::argentinian;
		case country::availableCountries::Australia:
			return dasmig::ng::culture::australian;
		case country::availableCountries::Brazil:
			return dasmig::ng::culture::brazilian;
		case country::availableCountries::China:
			return dasmig::ng::culture::chinese;
		case country::availableCountries::Czech_Republic:
			return dasmig::ng::culture::polish; //Need to include czech culture
		case country::availableCountries::Denmark:
			return dasmig::ng::culture::danish;
		case country::availableCountries::Finland:
			return dasmig::ng::culture::finnish;
		case country::availableCountries::France:
			return dasmig::ng::culture::french;
		case country::availableCountries::Germany:
			return dasmig::ng::culture::german;
		case country::availableCountries::Mongolia:
			return dasmig::ng::culture::turkish; //Need to include mongolian culture
		case country::availableCountries::Poland:
			return dasmig::ng::culture::polish;
		case country::availableCountries::Portugal:
			return dasmig::ng::culture::portuguese;
		case country::availableCountries::Russia:
			return dasmig::ng::culture::russian;
		case country::availableCountries::Sweden:
			return dasmig::ng::culture::swedish;
		case country::availableCountries::Turkey:
			return dasmig::ng::culture::turkish;
		case country::availableCountries::Ukraine:
			return dasmig::ng::culture::ukrainian;
		case country::availableCountries::United_Kingdom:
			return dasmig::ng::culture::british;
		case country::availableCountries::United_States:
			return dasmig::ng::culture::american;
		case country::availableCountries::Belgium:
			return dasmig::ng::culture::french;
		case country::availableCountries::Bosnia:
			return dasmig::ng::culture::turkish;
		case country::availableCountries::Bulgaria:
			return dasmig::ng::culture::bulgarian;
		case country::availableCountries::Canada:
			return dasmig::ng::culture::canadian;
		case country::availableCountries::Chile:
			return dasmig::ng::culture::argentinian;
		case country::availableCountries::Estonia:
			return dasmig::ng::culture::russian;
		case country::availableCountries::Hungary:
			return dasmig::ng::culture::polish; //Switch to czech
		case country::availableCountries::Israel:
			return dasmig::ng::culture::russian;
		case country::availableCountries::Kazakhstan:
			return dasmig::ng::culture::kazakh;
		case country::availableCountries::Kosovo:
			return dasmig::ng::culture::turkish;
		case country::availableCountries::Latvia:
			return dasmig::ng::culture::russian;
		case country::availableCountries::Mexico:
			return dasmig::ng::culture::mexican;
		case country::availableCountries::Montenegro:
			return dasmig::ng::culture::bulgarian;
		case country::availableCountries::Netherlands:
			return dasmig::ng::culture::german;
		case country::availableCountries::New_Zealand:
			return dasmig::ng::culture::australian;
		case country::availableCountries::Norway:
			return dasmig::ng::culture::norwegian;
		case country::availableCountries::Romania:
			return dasmig::ng::culture::bulgarian;
		case country::availableCountries::Serbia:
			return dasmig::ng::culture::bulgarian;
		case country::availableCountries::Slovakia:
			return dasmig::ng::culture::polish; //Switch to czech culture
		case country::availableCountries::South_Africa:
			return dasmig::ng::culture::american;
		case country::availableCountries::Spain:
			return dasmig::ng::culture::spanish;
		case country::availableCountries::Switzerland:
			return dasmig::ng::culture::german;
		case country::availableCountries::Uruguay:
			return dasmig::ng::culture::argentinian;
		default:
			return dasmig::ng::culture::any;
		};
	}

	country::availableRegions countryGetRegion(const country::availableCountries country)
	{
		switch (country)
		{
		case country::availableCountries::Argentina:
			return country::availableRegions::Americas;
		case country::availableCountries::Australia:
			return country::availableRegions::Oceania;
		case country::availableCountries::Brazil:
			return country::availableRegions::Americas;
		case country::availableCountries::China:
			return country::availableRegions::Asia;
		case country::availableCountries::Czech_Republic:
			return country::availableRegions::Eastern_Europe;
		case country::availableCountries::Denmark:
			return country::availableRegions::Western_Europe;
		case country::availableCountries::Finland:
			return country::availableRegions::Western_Europe;
		case country::availableCountries::France:
			return country::availableRegions::Western_Europe;
		case country::availableCountries::Germany:
			return country::availableRegions::Western_Europe;
		case country::availableCountries::Mongolia:
			return country::availableRegions::Asia;
		case country::availableCountries::Poland:
			return country::availableRegions::Eastern_Europe;
		case country::availableCountries::Portugal:
			return country::availableRegions::Western_Europe;
		case country::availableCountries::Russia:
			return country::availableRegions::CIS;
		case country::availableCountries::Sweden:
			return country::availableRegions::Western_Europe;
		case country::availableCountries::Turkey:
			return country::availableRegions::Eastern_Europe;
		case country::availableCountries::Ukraine:
			return country::availableRegions::CIS;
		case country::availableCountries::United_Kingdom:
			return country::availableRegions::Western_Europe;
		case country::availableCountries::United_States:
			return country::availableRegions::Americas;
		case country::availableCountries::Belgium:
			return country::availableRegions::Western_Europe;
		case country::availableCountries::Bosnia:
			return country::availableRegions::Eastern_Europe;
		case country::availableCountries::Bulgaria:
			return country::availableRegions::Eastern_Europe;
		case country::availableCountries::Canada:
			return country::availableRegions::Americas;
		case country::availableCountries::Chile:
			return country::availableRegions::Americas;
		case country::availableCountries::Estonia:
			return country::availableRegions::Eastern_Europe;
		case country::availableCountries::Hungary:
			return country::availableRegions::Eastern_Europe;
		case country::availableCountries::Israel:
			return country::availableRegions::Eastern_Europe;
		case country::availableCountries::Kazakhstan:
			return country::availableRegions::CIS;
		case country::availableCountries::Kosovo:
			return country::availableRegions::Eastern_Europe;
		case country::availableCountries::Latvia:
			return country::availableRegions::Eastern_Europe;
		case country::availableCountries::Mexico:
			return country::availableRegions::Americas;
		case country::availableCountries::Montenegro:
			return country::availableRegions::Eastern_Europe;
		case country::availableCountries::Netherlands:
			return country::availableRegions::Western_Europe;
		case country::availableCountries::New_Zealand:
			return country::availableRegions::Oceania;
		case country::availableCountries::Norway:
			return country::availableRegions::Western_Europe;
		case country::availableCountries::Romania:
			return country::availableRegions::Eastern_Europe;
		case country::availableCountries::Serbia:
			return country::availableRegions::Eastern_Europe;
		case country::availableCountries::Slovakia:
			return country::availableRegions::Eastern_Europe;
		case country::availableCountries::South_Africa:
			return country::availableRegions::Americas;
		case country::availableCountries::Spain:
			return country::availableRegions::Western_Europe;
		case country::availableCountries::Switzerland:
			return country::availableRegions::Western_Europe;
		case country::availableCountries::Uruguay:
			return country::availableRegions::Americas;
		default:
			return country::availableRegions::Western_Europe;
		};
	}
}