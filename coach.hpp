#pragma once
#include <iostream>

namespace r3d
{
	class coach
	{
	public:

		coach();

		coach(std::wstring name, std::wstring nickname, std::string nationality, std::string born, char gender, std::uint8_t rating, std::string currentDate);

		coach(std::string country);

		std::uint8_t setAge(std::string currentDate);

		std::wstring getName();

		void showInformation();

	private:
		std::wstring _name;
		std::wstring _nickname;
		std::string _nationality;
		std::string _born;
		char _gender;
		std::uint8_t _age;
		std::uint8_t _rating;

		std::string getRandomBorn();

		std::uint8_t getRandomRating();
	};
}