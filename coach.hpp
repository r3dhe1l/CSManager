#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "countryChoiceFunctions.hpp"


namespace r3d
{
	class coach
	{

	public:

		coach();

		coach(std::wstring name, std::wstring nickname, r3d::country::avaibleCountries nationality, std::wstring born, dasmig::ng::gender gender, std::uint8_t rating,
			std::wstring currentDate);

		coach(r3d::country::avaibleCountries country, dasmig::ng::gender gender);

		coach(r3d::country::avaibleCountries country, int tier, dasmig::ng::gender gender);

		std::uint8_t setAge(std::wstring currentDate);

		std::wstring getName();

		std::uint8_t getRating();

		r3d::country::avaibleCountries getNationality();

		void showInformation();

	private:
		std::wstring createRandomName(r3d::country::avaibleCountries& country, dasmig::ng::gender& gender);

		std::wstring createRandomNick(std::wstring& name);

		std::wstring createRandomBorn();

		std::uint8_t createRandomRating();

		std::uint8_t createRandomRatingByTier(int tier);

		std::wstring _name;
		std::wstring _nickname;
		r3d::country::avaibleCountries _nationality;
		std::wstring _born;
		dasmig::ng::gender _gender;
		std::uint8_t _age;
		std::uint8_t _rating;
	};
}