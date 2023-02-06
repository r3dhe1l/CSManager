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
	//r3d::team teste1 = r3d::team();
	//r3d::player teste2 = r3d::player();
	//r3d::coach teste3 = r3d::coach();
	int i = 0;
	while (i < 100)
	{
		std::wstring nome = dasmig::ng::instance().get_name(dasmig::ng::gender::m, dasmig::ng::culture::brazilian).append_surname();
		std::wstring nick = dasmig::nng::instance().get_nickname(nome);

		std::wcout << nome << " e nick: " << nick << std::endl;
		i++;
	}
}