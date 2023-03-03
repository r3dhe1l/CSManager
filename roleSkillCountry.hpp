#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdint>
#include <string_view>

namespace r3d::role {
	enum class rolesCT {
		Mid,
		Rotator,
		Anchor_A,
		Anchor_B,
		Joker
	};

	enum class rolesTR {
		Entry,
		Support,
		Lurker,
		Trader,
		Joker

	};
}

//namespace red::skill {
//	enum class generalAttribute {
//		Motor_Skills, Soft_Skills, Cognitive_Skills, Memorization_Skills, Karma, Accuracy, Reflex, Spray_Control, Movement, Positioning,
//		Aim_Placement, Peeking, Strafe, Pre_Fire, Concentration, Fortitude, Creativity, Aggressiveness, Game_Sense, Commitment, Modesty, Teamwork, Leadership, Charisma
//	};
//
//	enum class gunsProficiency {
//		Knife, Zeus_x27,
//		USP_S, P2000, Glock_18, Dual_Berettas, P250, Five_Seven, Tec_9, CZ75_Auto, Desert_Eagle, R8_Revolver, //pistols
//		Nova, XM114, MAG_7, Sawed_Off, M249, Negev, //heavys
//		MP9, MAC_10, MP7, MP5_SD, UMP_45, P90, PP_Bizon, //SMGs
//		FAMAS, Galil_AR, M4A1_S, M4A4, SSG_08, AUG, SG_553, AWP, SCAR_20, G3SG1 //rifles
//	};
//
//	enum class utilityProficiency {
//		HE_Grenade, Flashbang, Smoke_Grenade, Decoy_Grenade,
//		Incendiary_Grenade, Molotov
//	};
//
//	enum class roleKnowledge {
//		CT_Mid, CT_Rotator, CT_Anchor_A, CT_Anchor_B, CT_Joker, TR_Entry,
//		TR_Support, TR_Lurker, TR_Trader, TR_Joker
//	};
//
//	enum class mapKnowledge {
//		de_ancient, de_anubis, de_inferno, de_mirage, de_nuke, de_overpass,
//		de_vertigo, de_cache, de_cobblestone, de_dust2, de_train
//	};
//
//	enum class ancientPositions {
//		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Snake, Main, Totem,
//		Mid, Red, Square, Cave, Secret, Banana, Ramp, Doors, Temple
//	};
//
//	enum class anubisPositions {
//		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Tunnel, Palace, Alley, Mid, Walkway, Main, Boat, Connector, Long, Street, Bridge, Ruins
//	};
//
//	enum class infernoPositions {
//		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Ramp, Banana, Mid, Second_Mid, Construction, Library, Long, Top_Mid, Pit, Underpass, Apartments, Short, Alley
//	};
//
//	enum class miragePositions {
//		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Market, Apartments, House, Palace, Ramp, Connector, Window, Mid, Top_Mid, Short, Underpass
//	};
//
//	enum class nukePositions {
//		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Silo, Outside, Garage, Secret, Main, Catwalk, Heaven, Hell, Lobby, Squeaky, Radio, Ramp, Hut, Vent, Window, Double_Doors,
//		Single_Door
//	};
//
//	enum class overpassPositions {
//		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Bank, Heaven, Hell, Canals, Monster, Water, Connector, Short, Long, Toilets, Party, Stairs, Fountain, Playground
//	};
//
//	enum class vertigoPositions {
//		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Connector, Mid, Stairs, Elevators, Top_Mid, Yellow, Ramp, Heaven, Ladder, Main, Tunnels, Big_Box
//	};
//
//	enum class cachePositions {
//		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Hell, Car, Highway, Mid, Window, Heaven, Boxes, Garage, Checkers, Vent, Halls, Main, Boost, Squeaky, Long
//	};
//
//	enum class cobblestonePositions {
//		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Statue, Dragon_Lore, T_Ramp, Mid, CT_Ramp, Catwalk, A_Long, Connector, Sky, Drop, B_Long, Doors,
//		Plat
//	};
//
//	enum class dust2Positions {
//		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, CT_Mid, Upper, Lower, Short, Ramp, Car, Long, Pit, Mid, T_Mid, Suicide, Football, Outside_Long, Long_Doors
//	};
//
//	enum class trainPositions {
//		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Stairs, Back_Site, Sidewalk, Catwalk, Upper, Lower, Halls, Pop, Showers, Main, Connector, Heaven, Hell, Olof, Old_Bomb,
//		Tunnel, Ivy, Pigeons, Alley
//	};
//}

namespace r3d::country {
	enum class availableCountries {
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

	enum class availableRegions {
		Western_Europe,
		Eastern_Europe,
		CIS,
		Americas,
		Asia,
		Oceania
	};

	static const inline std::map <availableCountries, double> playersCountryDistribution{
		{availableCountries::Argentina, 0.0322},
		{availableCountries::Australia, 0.0456},
		{availableCountries::Brazil, 0.0972},
		{availableCountries::China, 0.0231},
		{availableCountries::Czech_Republic, 0.0186},
		{availableCountries::Denmark, 0.0722},
		{availableCountries::Finland, 0.0309},
		{availableCountries::France, 0.0258},
		{availableCountries::Germany, 0.0267},
		{availableCountries::Mongolia, 0.0263},
		{availableCountries::Poland, 0.0644},
		{availableCountries::Portugal, 0.0276},
		{availableCountries::Russia, 0.0733},
		{availableCountries::Sweden, 0.0423},
		{availableCountries::Turkey, 0.0204},
		{availableCountries::Ukraine, 0.0332},
		{availableCountries::United_Kingdom, 0.0267},
		{availableCountries::United_States, 0.0782},
		{availableCountries::Belgium, 0.0093},
		{availableCountries::Bosnia, 0.0093},
		{availableCountries::Bulgaria, 0.0111},
		{availableCountries::Canada, 0.0166},
		{availableCountries::Chile, 0.0093},
		{availableCountries::Estonia, 0.0093},
		{availableCountries::Hungary, 0.0093},
		{availableCountries::Israel, 0.0093},
		{availableCountries::Kazakhstan, 0.0137},
		{availableCountries::Kosovo, 0.0101},
		{availableCountries::Latvia, 0.0093},
		{availableCountries::Mexico, 0.0093},
		{availableCountries::Montenegro, 0.0093},
		{availableCountries::Netherlands, 0.0093},
		{availableCountries::New_Zealand, 0.0147},
		{availableCountries::Norway, 0.0093},
		{availableCountries::Romania, 0.0111},
		{availableCountries::Serbia, 0.0101},
		{availableCountries::Slovakia, 0.0111},
		{availableCountries::South_Africa, 0.0128},
		{availableCountries::Spain, 0.0137},
		{availableCountries::Switzerland, 0.0093},
		{availableCountries::Uruguay, 0.0093}
	};

	static const inline std::map <availableCountries, double> coachsCountryDistribution{
		{availableCountries::Argentina, 0.028},
		{availableCountries::Australia, 0.042},
		{availableCountries::Brazil, 0.109},
		{availableCountries::China, 0.020},
		{availableCountries::Czech_Republic, 0.020},
		{availableCountries::Denmark, 0.086},
		{availableCountries::Finland, 0.029},
		{availableCountries::France, 0.030},
		{availableCountries::Germany, 0.029},
		{availableCountries::Mongolia, 0.023},
		{availableCountries::Poland, 0.064},
		{availableCountries::Portugal, 0.023},
		{availableCountries::Russia, 0.085},
		{availableCountries::Sweden, 0.048},
		{availableCountries::Turkey, 0.020},
		{availableCountries::Ukraine, 0.035},
		{availableCountries::United_Kingdom, 0.023},
		{availableCountries::United_States, 0.088},
		{availableCountries::Belgium, 0.010},
		{availableCountries::Bosnia, 0.011},
		{availableCountries::Bulgaria, 0.011},
		{availableCountries::Canada, 0.015},
		{availableCountries::Chile, 0.010},
		{availableCountries::Estonia, 0.011},
		{availableCountries::Hungary, 0.011},
		{availableCountries::Israel, 0.011},
		{availableCountries::Kazakhstan, 0.015},
		{availableCountries::Kosovo, 0.010},
		{availableCountries::Latvia, 0.011},
		{availableCountries::Mexico, 0.010},
		{availableCountries::Montenegro, 0.011},
		{availableCountries::Netherlands, 0.010},
		{availableCountries::New_Zealand, 0.010},
		{availableCountries::Norway, 0.011},
		{availableCountries::Romania, 0.011},
		{availableCountries::Serbia, 0.011},
		{availableCountries::Slovakia, 0.011},
		{availableCountries::South_Africa, 0.010},
		{availableCountries::Spain, 0.011},
		{availableCountries::Switzerland, 0.010},
		{availableCountries::Uruguay, 0.010}
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
}