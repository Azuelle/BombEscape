// entity.cpp

#include "entity.h"
#include <vector>;

void Bomb::onDeath() {}; //TO BE IMPLEMENTED

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

void Bomb::damageHealth(Player *player){
  if (this->checkRange(player->getPosition()) == 1){
    player->takeDamage();
  }
}

void Bomb::breakEntity(std::vector<Entity*>& entity_list){
  for (std::vector<Entity*>::iterator itr=entity_list.begin(); itr != entity_list.end(); itr++){
    if ((*itr)->checkDeath()){
      // ?;
    }
  }
}
