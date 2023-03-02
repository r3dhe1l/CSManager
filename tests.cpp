#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string_view>
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/randomLibrary/random.hpp"
#include "magic_enum.hpp"
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/nameGenerator/dasmig/namegen.hpp"
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/nicknameGenerator/dasmig/nicknamegen.hpp"
#include "countryChoiceFunctions.hpp"
#include "player.hpp"
#include "coach.hpp"
#include "team.hpp"

int main()
{
	enum class xxx {
		brazil,
		argentina,
		chile,
		uruguai
	};

	std::vector <xxx> test{ xxx::brazil, xxx::brazil, xxx::argentina, xxx::chile, xxx::uruguai };

	std::cout << test.at(0) << "\n";

	//enum teste {
	//	abc,
	//	def,
	//	ghi,
	//	jkl,
	//	mno
	//};

	//std::wstring xxx{ magic_enum::enum_name(teste::def).begin(), magic_enum::enum_name(teste::def).end() };
	//std::string teste2{ "def" };
	//auto xyz = magic_enum::enum_cast<teste>("jkl");
	//std::string teste4{ magic_enum::enum_name(xyz.value()) };
	//auto kkk = magic_enum::enum_name(teste::def);
	//std::cout << teste::abc << "\n";



	//dasmig::ng::instance().load("D:/a_cursos/projetos_CPP/CSManager/thirdParty/nameGenerator/resources");
	//dasmig::nng::instance().load("D:/a_cursos/projetos_CPP/CSManager/thirdParty/nicknameGenerator/resources");

	//std::vector <r3d::team> test = r3d::createTeamsVector(100);

	//for (int i = 0; i < 100; i++)
	//{
	//	test.at(i).showInformation();
	//	std::wcout << std::endl;
	//}
	return 0; //Primeiro teste 5,847s 24mb ram 8% cpu
}