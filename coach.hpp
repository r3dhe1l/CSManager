#pragma once
#include <iostream>

namespace r3d
{
	class coach
	{

	public:

		coach();

		coach(std::wstring name, std::wstring nickname, std::string nationality, std::string born, char gender, std::uint8_t rating, std::string currentDate);

		coach(std::string country, char gender);

		coach(std::string country, char tierLettre, char gender);

		std::uint8_t setAge(std::string currentDate);

		std::wstring getName();

		std::uint8_t getRating();

		std::string getNationality();

		void showInformation();

	private:
		std::wstring _name;
		std::wstring _nickname;
		std::string _nationality;
		std::string _born;
		char _gender;
		std::uint8_t _age;
		std::uint8_t _rating;

		std::wstring createRandomName(std::string& country, char& gender);

		std::wstring createRandomNick(std::wstring& name);

		std::string createRandomBorn();

		std::uint8_t createRandomRating();

		std::uint8_t createRandomRatingByTier(char tierLettre);
	};
}