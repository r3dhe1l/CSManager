#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/randomLibrary/random.hpp"
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/nameGenerator/dasmig/namegen.hpp"
#include "D:/a_cursos/projetos_CPP/CSManager/thirdParty/nicknameGenerator/dasmig/nicknamegen.hpp"
#include "countryChoiceFunctions.hpp"
#include "player.hpp"
#include "coach.hpp"
#include "team.hpp"

int main()
{
	dasmig::ng::instance().load("D:/a_cursos/projetos_CPP/CSManager/thirdParty/nameGenerator/resources");
	dasmig::nng::instance().load("D:/a_cursos/projetos_CPP/CSManager/thirdParty/nicknameGenerator/resources");

	std::vector <r3d::player> test = r3d::createPlayersVector(100);

	for (int i = 0; i < test.size(); i++)
	{
		test.at(i).showInformation();
		std::cout << "\n";
	}

	return 0;
}