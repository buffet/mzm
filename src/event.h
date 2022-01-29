#ifndef EVENT_H
#define EVENT_H

#include "types.h"

enum __attribute__ ((packed)) event_action {
    EVENT_ACTION_CLEARING = 0x0,
    EVENT_ACTION_SETTING = 0x1,
    EVENT_ACTION_TOGGLING = 0x2,
    EVENT_ACTION_CHECKING = 0x3
};

enum __attribute__ ((packed)) event {
    EVENT_NONE = 0x0,
    EVENT_EASY = 0x1,
    EVENT_HARD = 0x2,
    EVENT_ENTER_NORFAIR_DEMO_PLAYED = 0x3,
    EVENT_EXIT_KRAID_DEMO_PLAYED = 0x4,
    EVENT_ENTER_RIDLEY_DEMO_PLAYED = 0x5,
    EVENT_ENTER_MOTHERSHIP_DEMO_PLAYED = 0x6,
    EVENT_ENTER_TOURIAN_DEMO_PLAYED = 0x7,
    EVENT_STATUE_LONG_BEAM_GRABBED = 0x8,
    EVENT_STATUE_BOMBS_GRABBED = 0x9,
    EVENT_STATUE_ICE_BEAM_GRABBED = 0xA,
    EVENT_STATUE_SPEEDBOOSTER_GRABBED = 0xB,
    EVENT_STATUE_HIGH_JUMP_GRABBED = 0xC,
    EVENT_STATUE_VARIA_SUIT_GRABBED = 0xD,
    EVENT_STATUE_WAVE_BEAM_GRABBED = 0xE,
    EVENT_STATUE_SCREW_ATTACK_GRABBED = 0xF,
    EVENT_POWER_GRIP_OBTAINED = 0x10,
    EVENT_CHOZO_PILLAR_FULLY_EXTENDED = 0x11,
    EVENT_HIGH_JUMP_OBTAINED = 0x12,
    EVENT_VARIA_SUIT_OBTAINED = 0x13,
    EVENT_CHARGE_BEAM_OBTAINED = 0x14,
    EVENT_SCREW_ATTACK_OBTAINED = 0x15,
    EVENT_SPACE_JUMP_OBTAINED = 0x16,
    EVENT_GRAVITY_SUIT_OBTAINED = 0x17,
    EVENT_PLASMA_BEAM_OBTAINED = 0x18,
    EVENT_DEOREM_ENCOUNTERED_AT_FIRST_LOCATION_OR_KILLED = 0x19,
    EVENT_DEOREM_ENCOUNTERED_AT_SECOND_LOCATION_OR_KILLED = 0x1A,
    EVENT_DEOROM_KILLED_AT_SECOND_LOCATION = 0x1B,
    EVENT_ACID_WORM_KILLED = 0x1C,
    EVENT_KRAID_GADORA_KILLED = 0x1D,
    EVENT_KRAID_KILLED = 0x1E,
    EVENT_KRAID_ELEVATOR_STATUS_DESTROYED = 0x1F,
    EVENT_CATERPILLAR_KILLED = 0x20,
    EVENT_IMAGO_TUNNEL_DISCOVERED = 0x21,
    EVENT_COCOON_KILLED = 0x22,
    EVENT_IMAGO_KILLED = 0x23,
    EVENT_RIDLEY_GADORA_KILLED = 0x24,
    EVENT_RIDLEY_KILLED = 0x25,
    EVENT_RIDLEY_ELEVATOR_STATUS_DESTROYED = 0x26,
    EVENT_MOTHER_BRAIN_KILLED = 0x27,
    EVENT_CROCOMIRE_KILLED = 0x28,
    EVENT_REPEL_MACHINE_KILLED = 0x29,
    EVENT_VIEWED_STATUE_ROOM = 0x2A,
    EVENT_DESSGEEGA_KILLED = 0x2B,
    EVENT_THREE_HIVES_DESTROYED = 0x2C,
    EVENT_BUGS_KILLED = 0x2D,
    EVENT_ZIPLINES_ACTIVATED = 0x2E,
    EVENT_PLANT_DESTROYED_LAVA = 0x2F,
    EVENT_PLANT_DESTROYED_POST_VARIA = 0x30,
    EVENT_PLANT_DESTROYED_VARIA2 = 0x31,
    EVENT_PLANT_DESTROYED_VARIA3 = 0x32,
    EVENT_PLANT_DESTROYED_VARIA1 = 0x33,
    EVENT_KRAID_BARISTUTES_KILLED = 0x34,
    EVENT_KRAID_STATUE_OPENED = 0x35,
    EVENT_RIDLEY_STATUE_OPENED = 0x36,
    EVENT_FIRST_METROID_ROOM_CLEARED = 0x37,
    EVENT_THIRD_METROID_ROOM_CLEARED = 0x38,
    EVENT_FIFTH_METROID_ROOM_CLEARED = 0x39,
    EVENT_SECOND_METROID_ROOM_CLEARED = 0x3A,
    EVENT_SIXTH_METROID_ROOM_CLEARED = 0x3B,
    EVENT_FOURTH_METROID_ROOM_CLEARED = 0x3C,
    EVENT_ZEBETITE_ONE_DESTROYED = 0x3D,
    EVENT_ZEBETITE_TWO_DESTROYED = 0x3E,
    EVENT_ZEBETITE_THREE_DESTROYED = 0x3F,
    EVENT_ZEBETITE_FOUR_DESTROYED = 0x40,
    EVENT_ESCAPED_ZEBES = 0x41,
    EVENT_MARKER_BETWEEN_ZEBES_AND_MOTHERSHIP = 0x42,
    EVENT_FULLY_POWERED_SUIT_OBTAINED = 0x43,
    EVENT_SKIPPED_VARIA_SUIT = 0x44,
    EVENT_CHOZOBLOCK = 0x45,
    EVENT_POWERBOMB_STOLEN = 0x46,
    EVENT_SPACE_PIRATE_WITH_POWERBOMB_ONE = 0x47,
    EVENT_SPACE_PIRATE_WITH_POWERBOMB_TWO = 0x48,
    EVENT_GLASS_TUBE_BROKEN = 0x49,
    EVENT_MECHA_RIDLEY_KILLED = 0x4A,
    EVENT_ESCAPED_CHOZODIA = 0x4B,
    EVENT_AKI = 0x4C,
    EVENT_BOMBATE = 0x4D,
    EVENT_END_UNUSED = 0x4E
};

u32 event_function(enum event_action action, enum event event);

#endif /* EVENT_H */