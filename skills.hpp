
namespace r3d::skill
{
	enum class generalAttribute {
		Motor_Skills, Soft_Skills, Cognitive_Skills, Memorization_Skills, Karma, Accuracy, Reflex, Spray_Control, Movement, Positioning,
		Aim_Placement, Peeking, Strafe, Pre_Fire, Concentration, Fortitude, Creativity, Aggressiveness, Game_Sense, Commitment, Modesty, Teamwork, Leadership, Charisma
	};

	enum class _gunsProficiency {
		Knife, Zeus_x27,
		USP_S, P2000, Glock_18, Dual_Berettas, P250, Five_Seven, Tec_9, CZ75_Auto, Desert_Eagle, R8_Revolver, //pistols
		Nova, XM114, MAG_7, Sawed_Off, M249, Negev, //heavys
		MP9, MAC_10, MP7, MP5_SD, UMP_45, P90, PP_Bizon, //SMGs
		FAMAS, Galil_AR, M4A1_S, M4A4, SSG_08, AUG, SG_553, AWP, SCAR_20, G3SG1 //rifles
	};

	enum class _utilityProficiency {
		HE_Grenade, Flashbang, Smoke_Grenade, Decoy_Grenade,
		Incendiary_Grenade, Molotov
	};

	enum class _roleKnowledge {
		CT_Mid, CT_Rotator, CT_Anchor_A, CT_Anchor_B, CT_Joker, TR_Entry,
		TR_Support, TR_Lurker, TR_Trader, TR_Joker
	};

	enum class _mapKnowledge {
		de_ancient, de_anubis, de_inferno, de_mirage, de_nuke, de_overpass,
		de_vertigo, de_cache, de_cobblestone, de_dust2, de_train
	};

	enum class _positionsAncient {
		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Snake, Main, Totem,
		Mid, Red, Square, Cave, Secret, Banana, Ramp, Doors, Temple
	};

	enum class _positionsAnubis {
		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Tunnel, Palace, Alley, Mid, Walkway, Main, Boat, Connector, Long, Street, Bridge, Ruins
	};

	enum class _positionsInferno {
		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Ramp, Banana, Mid, Second_Mid, Construction, Library, Long, Top_Mid, Pit, Underpass, Apartments, Short, Alley
	};

	enum class _positionsMirage {
		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Market, Apartments, House, Palace, Ramp, Connector, Window, Mid, Top_Mid, Short, Underpass
	};

	enum class _positionsNuke {
		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Silo, Outside, Garage, Secret, Main, Catwalk, Heaven, Hell, Lobby, Squeaky, Radio, Ramp, Hut, Vent, Window, Double_Doors,
		Single_Door
	};

	enum class _positionsOverpass {
		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Bank, Heaven, Hell, Canals, Monster, Water, Connector, Short, Long, Toilets, Party, Stairs, Fountain, Playground
	};

	enum class _positionsVertigo {
		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Connector, Mid, Stairs, Elevators, Top_Mid, Yellow, Ramp, Heaven, Ladder, Main, Tunnels, Big_Box
	};

	enum class _positionsCache {
		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Hell, Car, Highway, Mid, Window, Heaven, Boxes, Garage, Checkers, Vent, Halls, Main, Boost, Squeaky, Long
	};

	enum class _positionsCobblestone {
		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Statue, Dragon_Lore, T_Ramp, Mid, CT_Ramp, Catwalk, A_Long, Connector, Sky, Drop, B_Long, Doors,
		Plat
	};

	enum class _positionsDust2 {
		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, CT_Mid, Upper, Lower, Short, Ramp, Car, Long, Pit, Mid, T_Mid, Suicide, Football, Outside_Long, Long_Doors
	};

	enum class _positionsTrain {
		CT_Spawn, T_Spawn, Bomb_A, Bomb_B, Stairs, Back_Site, Sidewalk, Catwalk, Upper, Lower, Halls, Pop, Showers, Main, Connector, Heaven, Hell, Olof, Old_Bomb,
		Tunnel, Ivy, Pigeons, Alley
	};
}