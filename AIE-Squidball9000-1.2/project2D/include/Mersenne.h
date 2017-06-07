#pragma once
#include <random>



/**
* A class that provides random numbers using the Mersenne Twister method. https://en.wikipedia.org/wiki/Mersenne_Twister
* This class is a wrapper that uses the Mersenne Twister built into the library <random>.
* @author Ashley Flynn - Academy of Interactive Entertainment - 2017
*/

class Mersenne {

public:

    /**
    * Default constructor. Automatically seed with a random number.
    */
    Mersenne();

    /**
    * Constructor. Seed with a given unsigned int.
    * @param i The unsigned int to seed the generator with.
    */
    Mersenne(unsigned int i);

    /**
    * Default destructor.
    */
    ~Mersenne();

    /**
    * Get a random int in the range min to max (inclusive).
    * @param min The minumum number in the random range, inclusive.
    * @param max The maximum number in the random range, inclusive.
    * @returns The random number.
    */
    int rng(int min, int max) const;

    /**
    * Get a random double in the range min to max (inclusive).
    * @param min The minumum number in the random range, inclusive.
    * @param max The maximum number in the random range, inclusive.
    * @returns The random number.
    */
    double rng(double min, double max) const;

private:

    /**
    * Pointer to Mersenne Twister RNG.
    */
    std::mt19937 *mt;
};