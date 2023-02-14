#pragma once
#include <iostream>
#include <vector>
#include <map>

namespace r3d
{
	class player
	{
	public:

		player();

		player(std::wstring name, std::wstring nickname, std::string nationality, std::string born, std::string primaryRoleCT, std::string primaryRoleTR,
			std::string secondaryRoleCT, std::string secondaryRoleTR, char gender, std::uint16_t skillLevel, std::string currentDate);

		player(std::string country, char gender);

		player(std::string country, char tierLettre, char gender);

		std::uint16_t setAge(std::string currentDate);

		std::string getNationality();

		std::string getPrimaryRoleCT();

		std::string getPrimaryRoleTR();

		std::string getSecondaryRoleCT();

		std::string getSecondaryRoleTR();

		std::uint16_t getSkillLevel();

		void showInformation();

	private:
		std::wstring createRandomName(std::string& country, char& gender);

		std::wstring createRandomNick(std::wstring& name);

		std::string createRandomBorn();

		std::string chooseRandomPrimaryRoleCT();

		std::string chooseRandomPrimaryRoleTR();

		std::string chooseRandomSecondaryRoleCT();

		std::string chooseRandomSecondaryRoleTR();

		std::uint16_t createRandomSkillLevel();

		std::uint16_t createRandomSkillLevelByTier(char tierLettre);

		std::wstring _name;
		std::wstring _nickname;
		std::string _nationality;
		std::string _born;
		std::string _primaryRoleCT;
		std::string _primaryRoleTR;
		std::string _secondaryRoleCT;
		std::string _secondaryRoleTR;
		char _gender;
		std::uint16_t _age;
		std::uint16_t _skillLevel;
		std::vector <std::string> _traits;

		std::map <std::string, std::uint16_t> _generalAttributes{ {"Motor Skills", 0}, {"Soft Skills", 0}, {"Cognitive Skills", 0}, {"Memorization Skills", 0}, {"Karma", 0},
			{"Accuracy", 0}, {"Reflex", 0}, {"Spray Control", 0}, {"Movement", 0}, {"Positioning", 0}, {"Aim Placement", 0}, {"Peeking", 0}, {"Strafe", 0}, {"Pre-Fire", 0},
			{"Concentration", 0}, {"Fortitude", 0}, {"Creativity", 0}, {"Aggressiveness", 0}, {"Game Sense", 0}, {"Commitment", 0}, {"Modesty", 0}, {"Teamwork", 0},
			{"Leadership", 0}, {"Charisma", 0} };

		std::map <std::string, std::uint16_t> _gunsProficiency{ {"Knife", 0}, {"Zeus x27", 0},
			{"USP-S", 0}, {"P2000", 0}, {"Glock-18", 0}, {"Dual Berettas", 0}, {"P250", 0}, {"Five-Seven", 0}, {"Tec-9", 0}, {"CZ75-Auto", 0}, {"Desert Eagle", 0},
			{"R8 Revolver", 0}, //pistols
			{"Nova", 0}, {"XM1014", 0}, {"MAG-7", 0}, {"Sawed-Off", 0}, {"M249", 0}, {"Negev", 0}, //heavys
			{"MP9", 0}, {"MAC-10", 0}, {"MP7", 0}, {"MP5-SD", 0}, {"UMP-45", 0}, {"P90", 0}, {"PP-Bizon", 0}, //SMGs
			{"FAMAS", 0}, {"Galil AR", 0}, {"M4A1-S", 0}, {"M4A4", 0}, {"SSG 08", 0}, {"AUG", 0}, {"SG 553", 0}, {"AWP", 0}, {"SCAR-20", 0}, {"G3SG1", 0} };//rifles

		std::map <std::string, std::uint16_t> _utilityProficiency{ {"HE Grenade", 0}, {"Flashbang", 0}, {"Smoke Grenade", 0}, {"Decoy Grenade", 0}, {"Incendiary Grenade", 0},
			{"Molotov", 0} };

		std::map <std::string, std::uint16_t> _roleKnowledge{ {"CT Mid", 0}, {"CT Rotator", 0}, {"CT Anchor A", 0}, {"CT Anchor B", 0}, {"CT Joker", 0}, {"TR Entry", 0},
			{"TR Support", 0}, {"TR Lurker", 0}, {"TR Trader", 0}, {"TR Joker", 0} };

		std::map <std::string, std::uint16_t> _mapKnowledge{ {"de_ancient", 0}, {"de_anubis", 0}, {"de_inferno", 0}, {"de_mirage", 0}, {"de_nuke", 0}, {"de_overpass", 0},
			{"de_vertigo", 0}, {"de_cache", 0}, {"de_cobblestone", 0}, {"de_dust2", 0}, {"de_train", 0} };

		std::map <std::string, std::uint16_t> _positionsAncient{ {"CT Spawn", 0}, {"T Spawn", 0}, {"Bomb A", 0}, {"Bomb B", 0}, {"Snake", 0}, {"Main", 0}, {"Totem", 0},
			{"Mid", 0}, {"Red", 0}, {"Square", 0}, {"Cave", 0}, {"Secret", 0}, {"Banana", 0}, {"Ramp", 0}, {"Doors", 0}, {"Temple", 0} };

		std::map <std::string, std::uint16_t> _positionsAnubis{ {"CT Spawn", 0}, {"T Spawn", 0}, {"Bomb A", 0}, {"Bomb B", 0}, {"Tunnel", 0}, {"Palace", 0}, {"Alley", 0},
			{"Mid", 0}, {"Walkway", 0}, {"Main", 0}, {"Boat", 0}, {"Connector", 0}, {"Long", 0}, {"Street", 0}, {"Bridge", 0}, {"Ruins", 0} };

		std::map <std::string, std::uint16_t> _positionsInferno{ {"CT Spawn", 0}, {"T Spawn", 0}, {"Bomb A", 0}, {"Bomb B", 0}, {"Ramp", 0}, {"Banana", 0}, {"Mid", 0},
			{"Second Mid", 0}, {"Construction", 0}, {"Library", 0}, {"Long", 0}, {"Top Mid", 0}, {"Pit", 0}, {"Underpass", 0}, {"Apartments", 0}, {"Short", 0}, {"Alley", 0} };

		std::map <std::string, std::uint16_t> _positionsMirage{ {"CT Spawn", 0}, {"T Spawn", 0}, {"Bomb A", 0}, {"Bomb B", 0}, {"Market", 0}, {"Apartments", 0}, {"House", 0},
			{"Palace", 0}, {"Ramp", 0}, {"Connector", 0}, {"Window", 0}, {"Mid", 0}, {"Top Mid", 0}, {"Short", 0}, {"Underpass", 0} };

		std::map <std::string, std::uint16_t> _positionsNuke{ {"CT Spawn", 0}, {"T Spawn", 0}, {"Bomb A", 0}, {"Bomb B", 0}, {"Silo", 0}, {"Outside", 0}, {"Garage", 0},
			{"Secret", 0}, {"Main", 0}, {"Catwalk", 0}, {"Heaven", 0}, {"Hell", 0}, {"Lobby", 0}, {"Squeaky", 0}, {"Radio", 0}, {"Ramp", 0}, {"Hut", 0}, {"Vent", 0},
			{"Window", 0}, {"Double Doors", 0}, {"Single Door", 0} };

		std::map <std::string, std::uint16_t> _positionsOverpass{ {"CT Spawn", 0}, {"T Spawn", 0}, {"Bomb A", 0}, {"Bomb B", 0}, {"Bank", 0}, {"Heaven", 0}, {"Hell", 0},
			{"Canals", 0}, {"Monster", 0}, {"Water", 0}, {"Connector", 0}, {"Short", 0}, {"Long", 0}, {"Toilets", 0}, {"Party", 0}, {"Stairs", 0}, {"Fountain", 0},
			{"Playground", 0} };

		std::map <std::string, std::uint16_t> _positionsVertigo{ {"CT Spawn", 0}, {"T Spawn", 0}, {"Bomb A", 0}, {"Bomb B", 0}, {"Connector", 0}, {"Mid", 0}, {"Stairs", 0},
			{"Elevators", 0}, {"Top Mid", 0}, {"Yellow", 0}, {"Ramp", 0}, {"Heaven", 0}, {"Ladder", 0}, {"Main", 0}, {"Tunnels", 0}, {"Big Box", 0} };

		std::map <std::string, std::uint16_t> _positionsCache{ {"CT Spawn", 0}, {"T Spawn", 0}, {"Bomb A", 0}, {"Bomb B", 0}, {"Hell", 0}, {"Car", 0}, {"Highway", 0}, {"Mid", 0},
			{"Window", 0}, {"Heaven", 0}, {"Boxes", 0}, {"Garage", 0}, {"Checkers", 0}, {"Vent", 0}, {"Halls", 0}, {"Main", 0}, {"Boost", 0}, {"Squeaky", 0}, {"Long", 0} };

		std::map <std::string, std::uint16_t> _positionsCobblestone{ {"CT Spawn", 0}, {"T Spawn", 0}, {"Bomb A", 0}, {"Bomb B", 0}, {"Statue", 0}, {"Dragon Lore", 0},
			{"T Ramp", 0}, {"Mid", 0}, {"CT Ramp", 0}, {"Catwalk", 0}, {"A Long", 0}, {"Connector", 0}, {"Sky", 0}, {"Drop", 0}, {"B Long", 0}, {"Doors", 0}, {"Plat", 0} };

		std::map <std::string, std::uint16_t> _positionsDust2{ {"CT Spawn", 0}, {"T Spawn", 0}, {"Bomb A", 0}, {"Bomb B", 0}, {"CT Mid", 0}, {"Upper", 0}, {"Lower", 0},
			{"Short", 0}, {"Ramp", 0}, {"Car", 0}, {"Long", 0}, {"Pit", 0}, {"Mid", 0}, {"T Mid", 0}, {"Suicide", 0}, {"Football", 0}, {"Outside Long", 0}, {"Long Doors", 0} };

		std::map <std::string, std::uint16_t> _positionsTrain{ {"CT Spawn", 0}, {"T Spawn", 0}, {"Bomb A", 0}, {"Bomb B", 0}, {"Stairs", 0}, {"Back Site", 0}, {"Sidewalk", 0},
			{"Catwalk", 0}, {"Upper", 0}, {"Lower", 0}, {"Halls", 0}, {"Pop", 0}, {"Showers", 0}, {"Main", 0}, {"Connector", 0}, {"Heaven", 0}, {"Hell", 0}, {"Olof", 0},
			{"Old Bomb", 0}, {"Tunnel", 0}, {"Ivy", 0}, {"Pigeons", 0}, {"Alley", 0} };
	};
}
