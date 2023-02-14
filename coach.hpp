#pragma once
#include <iostream>
#include <vector>
#include <map>


namespace r3d
{
	class coach
	{

	public:

		coach();

		coach(std::wstring name, std::wstring nickname, std::string nationality, std::string born, char gender, std::uint16_t rating, std::string currentDate);

		coach(std::string country, char gender);

		coach(std::string country, char tierLettre, char gender);

		std::uint16_t setAge(std::string currentDate);

		std::wstring getName();

		std::uint16_t getRating();

		std::string getNationality();

		void showInformation();

	private:
		std::wstring createRandomName(std::string& country, char& gender);

		std::wstring createRandomNick(std::wstring& name);

		std::string createRandomBorn();

		std::uint16_t createRandomRating();

		std::uint16_t createRandomRatingByTier(char tierLettre);

		std::wstring _name;
		std::wstring _nickname;
		std::string _nationality;
		std::string _born;
		char _gender;
		std::uint16_t _age;
		std::uint16_t _rating;
	};
}