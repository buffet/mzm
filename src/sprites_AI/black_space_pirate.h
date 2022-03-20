#ifndef BLACK_SPACE_PIRATE_AI_H
#define BLACK_SPACE_PIRATE_AI_H

#include "../types.h"

void black_space_pirate_hit_by_projectile(void);
void black_space_pirate_colliding_with_laser(void);
void black_space_pirate_init(void);
void black_space_pirate_check_offscreen(void);
void black_space_pirate_before_shooting_gfx_init(void);
void black_space_pirate_determine_shooting_direction(void);
void black_space_pirate_jumping(void);
void black_space_pirate_move(void);
void black_space_pirate_death(u8 playSound);
void unk_2d794(void);
void unk_2d7dc(void);
void black_space_pirate(void);

#endif /* BLACK_SPACE_PIRATE_AI_H */