#ifndef MAP_H
#define MAP_H

#define DEFAULT_ROWS 20
#define DEFAULT_COLUMNS 20

#include <string>

#include <allegro5/allegro5.h>

typedef enum {
	WALL,
	PILL,
	SUPER_PILL,
	NOTHING,
} maps_objects_e;

class Map {
	public:
		Map(ALLEGRO_BITMAP *, ALLEGRO_BITMAP *, ALLEGRO_BITMAP *, ALLEGRO_BITMAP *);
		Map(const Map &);
		int get_count_pill(void) const;
		int get_count_super_pill(void) const;
		maps_objects_e get_object_scene(const int, const int) const;
		void draw_scene(void) const;
		Map &operator=(const Map &);
	private:
		std::string path_map;
		ALLEGRO_BITMAP *pill, *wall, *super_pill, *nothing;
		int count_pill, count_super_pill;
		maps_objects_e scene[DEFAULT_ROWS][DEFAULT_COLUMNS];
		void set_scene(void);
};

#endif // MAP_H
