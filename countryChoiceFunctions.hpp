#pragma once
#include <iostream>
#include <vector>
#include <map>

namespace r3d
{
	std::vector <std::string> teamsCreateCountriesVector(const std::size_t numCountries);

	std::vector <std::string> playersCreateCountriesVector(const std::size_t numCountries);

	const std::string* countryGetCulture(const std::string& country);

	const std::wstring* countryGetCode(const std::string& country);

	const std::string* countryGetRegion(const std::string& country);

	std::vector <std::string> countriesTeamsPlayers(const std::size_t numTeams);

	static inline const std::vector <std::string> availableCountries = {
		//players' countries in hltv top 30 world ranking
		"International",
		"Argentina",
		"Australia",
		"Brazil",
		"China",
		"Czech Republic",
		"Denmark",
		"Finland",
		"France",
		"Germany",
		"Mongolia",
		"Poland",
		"Portugal",
		"Russia",
		"Sweden",
		"Turkey",
		"Ukraine",
		"United Kingdom",
		"United States",
		"Belgium",
		"Bosnia",
		"Bulgaria",
		"Canada",
		"Chile",
		"Estonia",
		"Hungary",
		"Israel",
		"Kazakhstan",
		"Kosovo",
		"Latvia",
		"Mexico",
		"Montenegro",
		"Netherlands",
		"New Zealand",
		"Norway",
		"Romania",
		"Serbia",
		"Slovakia",
		"South Africa",
		"Spain",
		"Switzerland",
		"Uruguay",
		"Country not found." };

	static inline const std::vector <std::string> availableCultures = {
		"american",
		"argentinian",
		"australian",
		"brazilian",
		"british",
		"bulgarian",
		"canadian",
		"chinese",
		"czech", // I include this culture in relation to the namegenerator
		"danish",
		"finnish",
		"french",
		"german",
		"kazakh",
		"mexican",
		"mongolian", // I include this culture in relation to the namegenerator
		"norwegian",
		"polish",
		"portuguese",
		"russian",
		"spanish",
		"swedish",
		"turkish",
		"ukrainian",
		"international" };

	static inline const std::map <std::string, std::string> countryToCulture{
		{availableCountries.at(0), availableCultures.at(24)},
		{availableCountries.at(1), availableCultures.at(1)},
		{availableCountries.at(2), availableCultures.at(2)},
		{availableCountries.at(3), availableCultures.at(3)},
		{availableCountries.at(4), availableCultures.at(7)},
		{availableCountries.at(5), availableCultures.at(17)}, //Czech Republic - polish
		{availableCountries.at(6), availableCultures.at(9)},
		{availableCountries.at(7), availableCultures.at(10)},
		{availableCountries.at(8), availableCultures.at(11)},
		{availableCountries.at(9), availableCultures.at(12)},
		{availableCountries.at(10), availableCultures.at(22)}, //Mongolia - turkish
		{availableCountries.at(11), availableCultures.at(17)},
		{availableCountries.at(12), availableCultures.at(18)},
		{availableCountries.at(13), availableCultures.at(19)},
		{availableCountries.at(14), availableCultures.at(21)},
		{availableCountries.at(15), availableCultures.at(22)},
		{availableCountries.at(16), availableCultures.at(23)},
		{availableCountries.at(17), availableCultures.at(4)},
		{availableCountries.at(18), availableCultures.at(0)},
		{availableCountries.at(19), availableCultures.at(11)},// Belgium - french
		{availableCountries.at(20), availableCultures.at(22)},// Bosnia - turkish
		{availableCountries.at(21), availableCultures.at(5)},
		{availableCountries.at(22), availableCultures.at(6)},
		{availableCountries.at(23), availableCultures.at(1)},// Chile - argentinian
		{availableCountries.at(24), availableCultures.at(19)},//Estonia - russian
		{availableCountries.at(25), availableCultures.at(17)},//Hungary - polish (czech)
		{availableCountries.at(26), availableCultures.at(19)},//Israel - russian
		{availableCountries.at(27), availableCultures.at(13)},
		{availableCountries.at(28), availableCultures.at(22)},//Kosovo - turkish
		{availableCountries.at(29), availableCultures.at(19)},//Latvia - russian
		{availableCountries.at(30), availableCultures.at(14)},
		{availableCountries.at(31), availableCultures.at(5)},//Montenegro - bulgarian
		{availableCountries.at(32), availableCultures.at(12)},//Netherlands - german
		{availableCountries.at(33), availableCultures.at(2)},//New Zealand - australian
		{availableCountries.at(34), availableCultures.at(16)},
		{availableCountries.at(35), availableCultures.at(5)},//Romania - bulgarian
		{availableCountries.at(36), availableCultures.at(5)},//Serbia - bulgarian
		{availableCountries.at(37), availableCultures.at(8)},//Slovakia - czech
		{availableCountries.at(38), availableCultures.at(0)},//South Africa - american
		{availableCountries.at(39), availableCultures.at(20)},
		{availableCountries.at(40), availableCultures.at(12)},//Switzerland - german
		{availableCountries.at(41), availableCultures.at(1)} };//Uruguay - argentinian

	static inline const std::map <std::string, std::wstring> countryToCode{
		{availableCountries.at(0), L"Country not found."},
		{availableCountries.at(1), L"ar"},
		{availableCountries.at(2), L"au"},
		{availableCountries.at(3), L"br"},
		{availableCountries.at(4), L"cn"},
		{availableCountries.at(5), L"pl"}, //Czech Republic - polish
		{availableCountries.at(6), L"dk"},
		{availableCountries.at(7), L"fi"},
		{availableCountries.at(8), L"fr"},
		{availableCountries.at(9), L"de"},
		{availableCountries.at(10), L"tr"}, //Mongolia - turkish
		{availableCountries.at(11), L"pl"},
		{availableCountries.at(12), L"pt"},
		{availableCountries.at(13), L"ru"},
		{availableCountries.at(14), L"se"},
		{availableCountries.at(15), L"tr"},
		{availableCountries.at(16), L"ua"},
		{availableCountries.at(17), L"bg"},
		{availableCountries.at(18), L"us"},
		{availableCountries.at(19), L"fr"},// Belgium - french
		{availableCountries.at(20), L"tr"},// Bosnia - turkish
		{availableCountries.at(21), L"bg"},
		{availableCountries.at(22), L"ca"},
		{availableCountries.at(23), L"ar"},// Chile - argentinian
		{availableCountries.at(24), L"ru"},//Estonia - russian
		{availableCountries.at(25), L"pl"},//Hungary - polish
		{availableCountries.at(26), L"ru"},//Israel - russian
		{availableCountries.at(27), L"kz"},
		{availableCountries.at(28), L"tr"},//Kosovo - turkish
		{availableCountries.at(29), L"ru"},//Latvia - russian
		{availableCountries.at(30), L"mx"},
		{availableCountries.at(31), L"bg"},//Montenegro - bulgarian
		{availableCountries.at(32), L"de"},//Netherlands - german
		{availableCountries.at(33), L"au"},//New Zealand - australian
		{availableCountries.at(34), L"no"},
		{availableCountries.at(35), L"bg"},//Romania - bulgarian
		{availableCountries.at(36), L"bg"},//Serbia - bulgarian
		{availableCountries.at(37), L"pl"},//Slovakia - polish (czech)
		{availableCountries.at(38), L"us"},//South Africa - american
		{availableCountries.at(39), L"es"},
		{availableCountries.at(40), L"de"},//Switzerland - german
		{availableCountries.at(41), L"ar"}};//Uruguay - argentinian

	static inline const std::map <std::string, std::string> countryToRegion{
		{availableCountries.at(0), "International"},
		{availableCountries.at(1), "Americas"},
		{availableCountries.at(2), "Oceania"},
		{availableCountries.at(3), "Americas"},
		{availableCountries.at(4), "Asia"},
		{availableCountries.at(5), "Europe"},
		{availableCountries.at(6), "Europe"},
		{availableCountries.at(7), "Europe"},
		{availableCountries.at(8), "Europe"},
		{availableCountries.at(9), "Europe"},
		{availableCountries.at(10), "Asia"},
		{availableCountries.at(11), "Europe"},
		{availableCountries.at(12), "Europe"},
		{availableCountries.at(13), "CiS"},
		{availableCountries.at(14), "Europe"},
		{availableCountries.at(15), "Europe"},
		{availableCountries.at(16), "CIS"},
		{availableCountries.at(17), "Europe"},
		{availableCountries.at(18), "Americas"},
		{availableCountries.at(19), "Europe"},// Belgium - french
		{availableCountries.at(20), "Europe"},// Bosnia - turkish
		{availableCountries.at(21), "Europe"},
		{availableCountries.at(22), "Americas"},
		{availableCountries.at(23), "Americas"},// Chile - argentinian
		{availableCountries.at(24), "Europe"},//Estonia - russian
		{availableCountries.at(25), "Europe"},//Hungary - czech
		{availableCountries.at(26), "Europe"},//Israel - russian
		{availableCountries.at(27), "CIS"},
		{availableCountries.at(28), "Europe"},//Kosovo - turkish
		{availableCountries.at(29), "Europe"},//Latvia - russian
		{availableCountries.at(30), "Americas"},
		{availableCountries.at(31), "Europe"},//Montenegro - bulgarian
		{availableCountries.at(32), "Europe"},//Netherlands - german
		{availableCountries.at(33), "Oceania"},//New Zealand - australian
		{availableCountries.at(34), "Europe"},
		{availableCountries.at(35), "Europe"},//Romania - bulgarian
		{availableCountries.at(36), "Europe"},//Serbia - bulgarian
		{availableCountries.at(37), "Europe"},//Slovakia - czech
		{availableCountries.at(38), "Americas"},//South Africa - american
		{availableCountries.at(39), "Europe"},
		{availableCountries.at(40), "Europe"},//Switzerland - german
		{availableCountries.at(41), "Americas"}};//Uruguay - argentinian

	static inline const std::map <std::string, float> teamsRegionalDistribution{
		{availableCountries.at(0), 0.082},
		{availableCountries.at(1), 0.04},
		{availableCountries.at(2), 0.064},
		{availableCountries.at(3), 0.174},
		{availableCountries.at(4), 0.02},
		{availableCountries.at(5), 0.019},
		{availableCountries.at(6), 0.064},
		{availableCountries.at(7), 0.031},
		{availableCountries.at(8), 0.02},
		{availableCountries.at(9), 0.029},
		{availableCountries.at(10), 0.029},
		{availableCountries.at(11), 0.07},
		{availableCountries.at(12), 0.029},
		{availableCountries.at(13), 0.094},
		{availableCountries.at(14), 0.044},
		{availableCountries.at(15), 0.019},
		{availableCountries.at(16), 0.044},
		{availableCountries.at(17), 0.04},
		{availableCountries.at(18), 0.114} };

	static inline const std::map <std::string, float> playersRegionalDistribution{
		{availableCountries.at(1), 0.0353},
		{availableCountries.at(2), 0.0543},
		{availableCountries.at(3), 0.1635},
		{availableCountries.at(4), 0.0211},
		{availableCountries.at(5), 0.0143},
		{availableCountries.at(6), 0.0853},
		{availableCountries.at(7), 0.0342},
		{availableCountries.at(8), 0.0243},
		{availableCountries.at(9), 0.0263},
		{availableCountries.at(10), 0.0253},
		{availableCountries.at(11), 0.0753},
		{availableCountries.at(12), 0.0283},
		{availableCountries.at(13), 0.0874},
		{availableCountries.at(14), 0.0493},
		{availableCountries.at(15), 0.0163},
		{availableCountries.at(16), 0.0383},
		{availableCountries.at(17), 0.0263},
		{availableCountries.at(18), 0.0935},
		{availableCountries.at(19), 0.0033},
		{availableCountries.at(20), 0.0033},
		{availableCountries.at(21), 0.0053},
		{availableCountries.at(22), 0.0123},
		{availableCountries.at(23), 0.0033},
		{availableCountries.at(24), 0.0033},
		{availableCountries.at(25), 0.0033},
		{availableCountries.at(26), 0.0033},
		{availableCountries.at(27), 0.0081},
		{availableCountries.at(28), 0.0043},
		{availableCountries.at(29), 0.0033},
		{availableCountries.at(30), 0.0033},
		{availableCountries.at(31), 0.0033},
		{availableCountries.at(32), 0.0033},
		{availableCountries.at(33), 0.0092},
		{availableCountries.at(34), 0.0033},
		{availableCountries.at(35), 0.0053},
		{availableCountries.at(36), 0.0043},
		{availableCountries.at(37), 0.0053},
		{availableCountries.at(38), 0.007},
		{availableCountries.at(39), 0.0081},
		{availableCountries.at(40), 0.0033},
		{availableCountries.at(41), 0.0033}, };
}