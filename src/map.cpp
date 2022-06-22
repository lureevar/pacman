#include <fstream>
#include <iostream>

#include "map.h"

Map::Map(const char *file) {
	this->scene = new int*[HEIGHT];

	for (int i = 0; i < WIDTH; i++) {
		this->scene[i] = new int[WIDTH];
	}

	std::ifstream in(file);

	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			in >> this->scene[i][j];
		}
	}
}

Map::~Map(void) {
	for (int i = 0; i < WIDTH; i++) {
		delete [] this->scene[i];
	}

	delete [] this->scene;
}

void Map::setScene(int **newScene) {
	this->scene = newScene;
}

void Map::setPills(int newPills) {
	this->pills = newPills;
}

int **Map::getScene(void) {
	return this->scene;
}

int Map::getPills(void) {
	return this->pills;
}

Map &Map::operator=(const Map &map) {
	if (&map != this) {
		this->scene = map.scene;
		this->pills = map.pills;
	}

	return *this;
}

void Map::draw(ALLEGRO_BITMAP *wall, ALLEGRO_BITMAP *pill, ALLEGRO_BITMAP *super_pill) {
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			switch (this->scene[i][j]) {
			case WALL:
				al_draw_bitmap(wall, j * 32, i * 32, 0);
				break;
			case PILL:
				al_draw_bitmap(pill, j * 32, i * 32, 0);
				break;
			case SUPER_PILL:
				al_draw_bitmap(super_pill, j * 32, i * 32, 0);
				break;
			}
		}
	}
}
