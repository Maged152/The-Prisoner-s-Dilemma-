#ifndef RANDOM_GENERATOR
#define RANDOM_GENERATOR

#include "types.hpp"
#include <random>

namespace qlm
{
    class RandomGenerator
    {
        private:
        std::mt19937 rng; // Mersenne Twister 64-bit random number generator

        public:
        // Constructor
        RandomGenerator(int seed = 0) : rng(seed) {}

        // Function to set a seed
        void SetSeed(int seed_) 
        {
            rng.seed(seed_);
        }

         // Function to generate a random float [0 - 1]
        float Random() 
        {
            return static_cast<float>(rng()) / rng.max();
        }

        // Function to generate a random integer in [a, b]
        int RandInt(int a, int b) 
        {
            std::uniform_int_distribution<int> distribution(a, b - 1);
            return distribution(rng);
        }

        
        // Function to generate a random choice based on a probability
        Choice random_choice(float p = 0.5f) 
        {
            if (p == 0.0f) 
            {
                return Choice::DEFECT;
            }

            if (p == 1.0f) 
            {
                return Choice::COOPERATE;
            }

            float r = this->Random();

            return r < p ? Choice::COOPERATE : Choice::DEFECT;
        }
       
    };
}

#endif