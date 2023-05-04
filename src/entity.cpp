// entity.cpp

#include "entity.h"
#include <vector>;

void Bomb::onDeath(Player* player, std::vector<Entity*>& entity_list) {
  if (this->checkRange(player->getPosition()) == 1){
    player->takeDamage();
  }
  for(std::vector<Entity*>::iterator itr=entity_list.begin(); itr != entity_list.end(); itr++){
    if ((*itr)->checkDeath() == false){
      (*itr)->alreadyDied = true;
    }
  }
};

void Bomb::setBombLevel(Player* player){
  this->bombLevel = player->getBombLevel();
}

bool Bomb::checkRange(Pos p){ // Pass in player position or entity position
  int bombX = this->getPosition().x;
  int bombY = this->getPosition().y;
  int range = bombLevel * 2;
  if ((p.x<=bombX + range && p.x>=bombX - range && p.y==bombY) || (p.y<=bombY + range && p.y>=bombY + range && p.x==bombX)){
    return true;
  } else {
    return false;
  }
}
