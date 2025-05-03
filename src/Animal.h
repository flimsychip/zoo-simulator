#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

enum Species {
	None,
	Chimpanzee,
	RedPanda,
	Otter,
	Wolf,
	Bear,
	Lion,
	Elephant,
	Penguin,
	Toucan,
	Hamster
};

struct Animal {
	public:
		Animal();
		Animal(Species species);
		void makeSound() const;
		void eat() const;

		// Getters
		Species getSpecies() const;

		// Setters
		void setSpecies(Species toSpecies);

	private:
		Species species;
};

#endif