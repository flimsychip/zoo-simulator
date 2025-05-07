#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

enum Species {
	None,
	Chimpanzee,
	Red_Panda,
	Otter,
	Wolf,
	Bear,
	Lion,
	Elephant,
	Penguin,
	Toucan,
	Hamster,
	Gorilla
};

struct Animal {
	public:
		Animal();
		Animal(Species species);
		void makeSound() const;
		void eat() const;

		// Getters
		Species getSpecies() const;
		std::string getName() const;

		// Setters
		void setSpecies(Species toSpecies);
		void setName(std::string name);

	private:
		Species species;
		std::string name;
};

#endif