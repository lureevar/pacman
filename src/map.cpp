#include <fstream>

#include "../include/map.hpp"

#define DEFAULT_PATH_MAP "data/map/classic.map"
#define DEFAULT_BITMAPS_WIDTH 32
#define DEFAULT_BITMAPS_HEIGHT 32

Map::Map(ALLEGRO_BITMAP *pill, ALLEGRO_BITMAP *wall, ALLEGRO_BITMAP *super_pill, ALLEGRO_BITMAP *nothing) {
	this->count_pill = this->count_super_pill = 0;

	this->path_map = DEFAULT_PATH_MAP;

	this->pill = pill;
	this->wall = wall;
	this->super_pill = super_pill;
	this->nothing = nothing;

	this->set_scene();
}

Map::Map(const Map &map) {
	this->operator=(map);

	this->set_scene();
}

int Map::get_count_pill(void) const {
	return this->count_pill;
}

int Map::get_count_super_pill(void) const {
	return this->count_pill;
}

maps_objects_e Map::get_object_scene(const int row, const int column) const {
	return this->scene[row][column];
}

void Map::draw_scene(void) const {
	for (int i = 0; i < DEFAULT_ROWS; i++) {
		for (int j = 0; j < DEFAULT_COLUMNS; j++) {
			switch (this->scene[i][j]) {
			case WALL:
				al_draw_bitmap(this->wall, j * DEFAULT_BITMAPS_HEIGHT, i * DEFAULT_BITMAPS_WIDTH, 0);
				break;
			case PILL:
				al_draw_bitmap(this->pill, j * DEFAULT_BITMAPS_HEIGHT, i * DEFAULT_BITMAPS_WIDTH, 0);
				break;
			case SUPER_PILL:
				al_draw_bitmap(this->super_pill, j * DEFAULT_BITMAPS_HEIGHT, i * DEFAULT_BITMAPS_WIDTH, 0);
				break;
			default:
				al_draw_bitmap(this->nothing, j * DEFAULT_BITMAPS_HEIGHT, i * DEFAULT_BITMAPS_WIDTH, 0);
			}
		}
	}
}

Map &Map::operator=(const Map &map) {
	if (this != &map) {
		this->count_pill = map.count_pill;
		this->count_super_pill = map.count_super_pill;

		this->pill = map.pill;
		this->super_pill = map.super_pill;
		this->wall = map.wall;
		this->nothing = map.nothing;

		for (int i = 0; i < DEFAULT_ROWS; i++)
			for (int j = 0; j < DEFAULT_COLUMNS; j++)
				this->scene[i][j] = map.scene[i][j];
	}

	return *this;
}

void Map::set_scene(void) {
	std::ifstream in(this->path_map);

	for (int i = 0; i < DEFAULT_ROWS; i++) {
		for (int j = 0; j < DEFAULT_COLUMNS; j++) {
			int object_id;

			in >> object_id;

			this->scene[i][j] = static_cast<maps_objects_e>(object_id);

			switch (this->scene[i][j]) {
			case SUPER_PILL:
				this->count_super_pill++;
				break;
			case PILL:
				this->count_pill++;
				break;
			case NOTHING:
			case WALL:
				break;
			}
		}
	}
}
