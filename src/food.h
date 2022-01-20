#ifndef FOOD_H
#define FOOD_H

#include <random>
#include <chrono>
#include <thread>
#include "SDL.h"
#include "snake.h"

class Food {
    public:
        SDL_Point food; 
        Food(std::size_t &grid_width, std::size_t &grid_height);
        void showFood(Snake &snake);
        void randEffect();
        void applyEffect(float &speed); 
        void effectDuration(); 

    private:
        enum class foodEffect {slow, fast, normal};
        foodEffect effect; 
        std::random_device rd; 
        std::mt19937 gen;
        std::uniform_int_distribution<int> rand_width; 
        std::uniform_int_distribution<int> rand_height; 
};



#endif 