#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "player.hpp"
#include "coach.hpp"
#include "team.hpp"

namespace r3d
{
	std::vector <int> playersGetCountriesByRankingRange(std::vector <int> sortedPlayerCountriesVector, int beginIndex, int endIndex,
		std::vector <r3d::country::avaibleCountries> countriesToDraw, int tierPlayer);

	std::vector <int> playersCountriesSortBySkillLevel(const int numPlayers);

	std::vector <r3d::player> createPlayersVector(const std::size_t numTeams);

	std::vector <std::wstring> coachGetCountriesByRankingRange(std::vector <std::wstring> sortedCoachCountriesVector, std::size_t beginIndex, std::size_t endIndex,
		std::vector <std::wstring> countriesToDraw, std::wstring tierCoach);

	std::vector <std::wstring> coachsCountriesSortBySkillLevel(const std::size_t numCoachs);

	std::vector <r3d::coach> createCoachsVector(const std::size_t numTeams);

	std::vector <r3d::team> createTeamsVector(const std::size_t numTeams);

	dasmig::ng::culture countryGetNGCulture(const r3d::country::avaibleCountries country);

	r3d::country::avaibleRegions countryGetRegion(const r3d::country::avaibleCountries country);
	
	class country
	{
	public:
		enum class avaibleCountries {
			//players' countries in hltv top 30 world ranking
			International,
			Argentina,
			Australia,
			Brazil,
			China,
			Czech_Republic,
			Denmark,
			Finland,
			France,
			Germany,
			Mongolia,
			Poland,
			Portugal,
			Russia,
			Sweden,
			Turkey,
			Ukraine,
			United_Kingdom,
			United_States,
			Belgium,
			Bosnia,
			Bulgaria,
			Canada,
			Chile,
			Estonia,
			Hungary,
			Israel,
			Kazakhstan,
			Kosovo,
			Latvia,
			Mexico,
			Montenegro,
			Netherlands,
			New_Zealand,
			Norway,
			Romania,
			Serbia,
			Slovakia,
			South_Africa,
			Spain,
			Switzerland,
			Uruguay
		};

		enum class avaibleRegions {
			International,
			Western_Europe,
			Eastern_Europe,
			CIS,
			Americas,
			Asia,
			Oceania
		};

		std::map <r3d::country::avaibleCountries, float> playersCountryDistribution{
			{Argentina, 0.0322},
			{Australia, 0.0456},
			{Brazil, 0.0972},
			{China, 0.0231},
			{Czech_Republic, 0.0186},
			{Denmark, 0.0722},
			{Finland, 0.0309},
			{France, 0.0258},
			{Germany, 0.0267},
			{Mongolia, 0.0263},
			{Poland, 0.0644},
			{Portugal, 0.0276},
			{Russia, 0.0733},
			{Sweden, 0.0423},
			{Turkey, 0.0204},
			{Ukraine, 0.0332},
			{United_Kingdom, 0.0267},
			{United_States, 0.0782},
			{Belgium, 0.0093},
			{Bosnia, 0.0093},
			{Bulgaria, 0.0111},
			{Canada, 0.0166},
			{Chile, 0.0093},
			{Estonia, 0.0093},
			{Hungary, 0.0093},
			{Israel, 0.0093},
			{Kazakhstan, 0.0137},
			{Kosovo, 0.0101},
			{Latvia, 0.0093},
			{Mexico, 0.0093},
			{Montenegro, 0.0093},
			{Netherlands, 0.0093},
			{New_Zealand, 0.0147},
			{Norway, 0.0093},
			{Romania, 0.0111},
			{Serbia, 0.0101},
			{Slovakia, 0.0111},
			{South_Africa, 0.0128},
			{Spain, 0.0137},
			{Switzerland, 0.0093},
			{Uruguay, 0.0093}
		};

		std::map <r3d::country::avaibleCountries, float> coachsCountryDistribution{
			{Argentina, 0.028},
			{Australia, 0.042},
			{Brazil, 0.109},
			{China, 0.020},
			{Czech_Republic, 0.020},
			{Denmark, 0.086},
			{Finland, 0.029},
			{France, 0.030},
			{Germany, 0.029},
			{Mongolia, 0.023},
			{Poland, 0.064},
			{Portugal, 0.023},
			{Russia, 0.085},
			{Sweden, 0.048},
			{Turkey, 0.020},
			{Ukraine, 0.035},
			{United_Kingdom, 0.023},
			{United_States, 0.088},
			{Belgium, 0.010},
			{Bosnia, 0.011},
			{Bulgaria, 0.011},
			{Canada, 0.015},
			{Chile, 0.010},
			{Estonia, 0.011},
			{Hungary, 0.011},
			{Israel, 0.011},
			{Kazakhstan, 0.015},
			{Kosovo, 0.010},
			{Latvia, 0.011},
			{Mexico, 0.010},
			{Montenegro, 0.011},
			{Netherlands, 0.010},
			{New_Zealand, 0.010},
			{Norway, 0.011},
			{Romania, 0.011},
			{Serbia, 0.011},
			{Slovakia, 0.011},
			{South_Africa, 0.010},
			{Spain, 0.011},
			{Switzerland, 0.010},
			{Uruguay, 0.010}
		};

		//static inline const std::map <std::wstring, float> teamsCountryDistribution{
		//	{availableCountries.at(0), 0.082},
		//	{availableCountries.at(1), 0.04},
		//	{availableCountries.at(2), 0.064},
		//	{availableCountries.at(3), 0.174},
		//	{availableCountries.at(4), 0.02},
		//	{availableCountries.at(5), 0.019},
		//	{availableCountries.at(6), 0.064},
		//	{availableCountries.at(7), 0.031},
		//	{availableCountries.at(8), 0.02},
		//	{availableCountries.at(9), 0.029},
		//	{availableCountries.at(10), 0.029},
		//	{availableCountries.at(11), 0.07},
		//	{availableCountries.at(12), 0.029},
		//	{availableCountries.at(13), 0.094},
		//	{availableCountries.at(14), 0.044},
		//	{availableCountries.at(15), 0.019},
		//	{availableCountries.at(16), 0.044},
		//	{availableCountries.at(17), 0.04},
		//	{availableCountries.at(18), 0.114} };
	};
}