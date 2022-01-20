#include "food.h"

Food::Food(std::size_t &grid_width, std::size_t &grid_height) : 
    gen(rd()),
    rand_width(0, static_cast<int>(grid_width)),
    rand_height(0, static_cast<int>(grid_height)) {

}

void Food::showFood(Snake &snake) {
    while (true) {
        int pos_x = rand_width(gen); 
        int pos_y = rand_height(gen);
        if (!snake.SnakeCell(pos_x, pos_y)){
            food.x = pos_x;
            food.y = pos_y;
            randEffect();
            return; 
        }
    }
}

void Food::randEffect() {
    std::uniform_int_distribution<size_t> rand(0, 3);
    effect = static_cast<foodEffect>(rand(gen));
}

void Food::applyEffect(float &speed) {
    switch (effect)
    {
    case foodEffect::slow: 
        speed = 0.5; 
        break;
    case foodEffect::fast: 
        speed = 1.5;
        break; 
    case foodEffect::crazy: 
        speed = 2.3; 
        break;
    case foodEffect::normal:
        speed = 1;
        break;
    }

}