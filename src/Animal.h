#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>
#include "../deps/nlohmann/json.hpp"

enum Species { // TEST COMMENT
	None,
	Chimpanzee,
	Otter,
	Wolf,
	Bear,
	Lion,
	Toucan,
	Hamster,
	Gorilla
};

struct Animal {
	public:
		Animal();
		Animal(Species species);
		Animal(Species species, std::string name);
		void makeSound() const;
		void eat() const;

		// Getters
		Species getSpecies() const;
		std::string getSpeciesStr() const;
		std::string getName() const;
		void print();

		// Setters
		void setSpecies(Species toSpecies);
		void setName(std::string name);

		// MACRO to convert/actuate object to/from json
		NLOHMANN_DEFINE_TYPE_INTRUSIVE(Animal, species, name)

	private:
		Species species;
		std::string name;
};

std::ostream& operator<<(std::ostream& os, const Animal& toPrint);

bool operator==(const Animal& lhs, const Animal& rhs);
bool operator!=(const Animal& lhs, const Animal& rhs);
bool operator<(const Animal& lhs, const Animal& rhs);
bool operator>(const Animal& lhs, const Animal& rhs);
bool operator<=(const Animal& lhs, const Animal& rhs);
bool operator>=(const Animal& lhs, const Animal& rhs);

#endif