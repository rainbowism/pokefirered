#include "global.h"
#include "overworld.h"
#include "strikes_patch.h"
#include "constants/maps.h"
#include "constants/region_map_sections.h"

u16 GetHealingPoint(void)
{
    u16 i;
    u16 mapno = (gSaveBlock1Ptr->location.mapGroup << 8) + gSaveBlock1Ptr->location.mapNum;

    switch (mapno)
    {
        case MAP_PALLET_TOWN_PLAYERS_HOUSE_1F:
            return 0;
        case MAP_SSANNE_1F_ROOM6:
            return 1;
        case MAP_POKEMON_TOWER_5F:
            return 2;
        case MAP_SILPH_CO_9F:
            return 3;
        case MAP_VIRIDIAN_CITY_POKEMON_CENTER_1F:
            return 4;
        case MAP_PEWTER_CITY_POKEMON_CENTER_1F:
            return 5;
        case MAP_CERULEAN_CITY_POKEMON_CENTER_1F:
            return 6;
        case MAP_LAVENDER_TOWN_POKEMON_CENTER_1F:
            return 7;
        case MAP_VERMILION_CITY_POKEMON_CENTER_1F:
            return 8;
        case MAP_CELADON_CITY_POKEMON_CENTER_1F:
            return 9;
        case MAP_FUCHSIA_CITY_POKEMON_CENTER_1F:
            return 10;
        case MAP_CINNABAR_ISLAND_POKEMON_CENTER_1F:
            return 11;
        case MAP_INDIGO_PLATEAU_POKEMON_CENTER_1F:
            return 12;
        case MAP_SAFFRON_CITY_POKEMON_CENTER_1F:
            return 13;
        case MAP_ROUTE4_POKEMON_CENTER_1F:
            return 14;
        case MAP_ROUTE10_POKEMON_CENTER_1F:
            return 15;
        case MAP_UNION_ROOM:
            return 1;
    }

    return 1 << 15;
}

bool8 CheckUsedLocation(void)
{
    u32 gameStat;
    u32 mapBit;
    u8 location;

    if (gSaveBlock1Ptr->location.mapGroup != 1 && gSaveBlock1Ptr->location.mapGroup != 3)
    {
        // invalid location
        return TRUE;
    }

    location = (u8) gSaveBlock1Ptr->location.mapNum;

    if (gSaveBlock1Ptr->location.mapGroup == 1)
    {
        if (location > 1 && location <= 3) // MT_MOON
            location = 1;
        if (location > 4 && location <= 29) // SSANNE
            location = 4;
        if (location > 30 && location <= 35) // UNDERGROUND_PATH
            location = 30;
        if (location > 36 && location <= 38) // DIGLETTS_CAVE
            location = 36;
        if (location > 39 && location <= 41) // VICTORY_ROAD
            location = 39;
        if (location > 42 && location <= 46) // ROCKET_HIDEOUT
            location = 42;
        if (location > 47 && location <= 58) // SILPH_CO
            location = 47;
        if (location > 59 && location <= 62) // POKEMON_MANSION
            location = 59;
        if (location > 63 && location <= 71) // SAFARI_ZONE
            location = 47;
        if (location > 72 && location <= 74) // MAP_CERULEAN_CAVE
            location = 72;
        if (location > 81 && location <= 82) // ROCK_TUNNEL
            location = 81;
        if (location > 83 && location <= 87) // SEAFOAM_ISLANDS
            location = 83;
        if (location > 87 && location <= 94) // POKEMON_TOWER
            location = 87;
    }
    else if (gSaveBlock1Ptr->location.mapGroup == 3)
    {
        location += 123;
    }

    mapBit = 1 << (location % 24);
    location = (location / 24) & 0xFF;

    gameStat = GetGameStat(GAME_STAT_LOCATION_USED + location);
    if ((gameStat & mapBit) > 0)
    {
        // location was already used
        return TRUE;
    }
    return FALSE;
}

void UpdateUsedLocation(void)
{
    u32 gameStat;
    u32 mapBit;
    u8 location;

    if (gSaveBlock1Ptr->location.mapGroup != 1 && gSaveBlock1Ptr->location.mapGroup != 3)
    {
        // invalid location
        return;
    }

    location = (u8) gSaveBlock1Ptr->location.mapNum;

    if (gSaveBlock1Ptr->location.mapGroup == 1)
    {
        if (location > 1 && location <= 3) // MT_MOON
            location = 1;
        if (location > 4 && location <= 29) // SSANNE
            location = 4;
        if (location > 30 && location <= 35) // UNDERGROUND_PATH
            location = 30;
        if (location > 36 && location <= 38) // DIGLETTS_CAVE
            location = 36;
        if (location > 39 && location <= 41) // VICTORY_ROAD
            location = 39;
        if (location > 42 && location <= 46) // ROCKET_HIDEOUT
            location = 42;
        if (location > 47 && location <= 58) // SILPH_CO
            location = 47;
        if (location > 59 && location <= 62) // POKEMON_MANSION
            location = 59;
        if (location > 63 && location <= 71) // SAFARI_ZONE
            location = 47;
        if (location > 72 && location <= 74) // MAP_CERULEAN_CAVE
            location = 72;
        if (location > 81 && location <= 82) // ROCK_TUNNEL
            location = 81;
        if (location > 83 && location <= 87) // SEAFOAM_ISLANDS
            location = 83;
        if (location > 87 && location <= 94) // POKEMON_TOWER
            location = 87;
    }
    else if (gSaveBlock1Ptr->location.mapGroup == 3)
    {
        location += 123;
    }

    mapBit = 1 << (location % 24);
    location = (location / 24) & 0xFF;

    gameStat = GetGameStat(GAME_STAT_LOCATION_USED + location);
    if ((gameStat & mapBit) > 0)
    {
        // location was already used
        return;
    }
    gameStat |= mapBit;
    SetGameStat(GAME_STAT_LOCATION_USED + location, gameStat);
}
