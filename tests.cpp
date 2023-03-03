#include "random.hpp"
#include "magic_enum.hpp"
#include "thirdParty/nicknameGenerator/dasmig/nicknamegen.hpp"
#include "countryChoiceFunctions.hpp"
#include "player.hpp"
#include "coach.hpp"
#include "team.hpp"
//arrumar draft para uma função
//arrumar saida dos nomes dos paises
//adicionar team como atributo de player e coach
//fazer calculo dos atributos
//criar enum de traits
//arrumar espaços fora da visão
//arrumar algoritmo do draft
//aprender usar date.h
//criar time para free agents

int main()
{
	dasmig::ng::instance().load("thirdParty/nameGenerator/resources");
	dasmig::nng::instance().load("thirdParty/nicknameGenerator/resources");

	std::vector <r3d::team> test = r3d::createTeamsVector(100);

	for (int i = 0; i < 100; i++)
	{
		test.at(i).showInformation();
		std::wcout << std::endl;
	}
	return 0; //Primeiro teste 5,847s 24mb ram 8% cpu
}