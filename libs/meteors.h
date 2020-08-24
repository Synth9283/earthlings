#pragma once

void spawnMeteor(Game *game);
int checkMeteor(Planet *planet, Meteor *meteor);
void destroyMeteor(Meteor *meteor);
void moveMeteor(Game *game, Meteor *meteor);
unsigned int updateMeteor(Game *game, unsigned int tickCount);
