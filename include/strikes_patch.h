#ifndef GUARD_STRIKES_PATCH_H
#define GUARD_STRIKES_PATCH_H

#include "global.h"
#include "main.h"

#define GAME_STAT_HEALING_USED 52
#define GAME_STAT_LOCATION_USED 53

u16 GetHealingPoint(void);
bool8 CheckUsedLocation(void);
void UpdateUsedLocation(void);

#endif //GUARD_STRIKES_PATCH_H
