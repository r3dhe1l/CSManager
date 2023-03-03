#pragma once

#include "thirdParty/nameGenerator/dasmig/namegen.hpp"
#include "roleSkillCountry.hpp"

namespace r3d
{
	class coach
	{
	public:

		coach();

		coach(std::wstring name, std::wstring nickname, country::availableCountries nationality, std::wstring born, dasmig::ng::gender gender, std::uint8_t rating,
			std::wstring currentDate);

		coach(country::availableCountries country, dasmig::ng::gender gender);

		coach(country::availableCountries country, int tier, dasmig::ng::gender gender);

		std::uint8_t setAge(std::wstring currentDate);

		std::wstring getName();

		std::uint8_t getRating();

		country::availableCountries getNationality();

		void showInformation();

	private:
		std::wstring createRandomName(country::availableCountries& country, dasmig::ng::gender& gender);

		std::wstring createRandomNick(std::wstring& name);

		std::wstring createRandomBorn();

		std::uint8_t createRandomRating();

		std::uint8_t createRandomRatingByTier(int tier);

		std::wstring _name;
		std::wstring _nickname;
		country::availableCountries _nationality;
		std::wstring _born;
		dasmig::ng::gender _gender;
		std::uint8_t _age;
		std::uint8_t _rating;
		//team _team;
	};
};