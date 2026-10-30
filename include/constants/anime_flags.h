#ifndef GUARD_CONSTANTS_ANIME_FLAGS_H
#define GUARD_CONSTANTS_ANIME_FLAGS_H

/*
 * Anime story progression flags for the FireRed / Crystal / Emerald fusion.
 *
 * These occupy a dedicated free block starting at 0x4000 so they do not collide
 * with stock pokeemerald script flags (0x000–0x4FF) or system flags (~0x860+).
 * When integrating into pokeemerald-expansion, ensure NUM_FLAG_BYTES / the flag
 * save arrays cover at least through FLAG_ANIME_END, or remap this block into
 * unused FLAG_UNUSED_* slots in include/constants/flags.h.
 */

/* ------------------------------------------------------------------------- */
/* Kanto arc — Pokémon the Series / FireRed                                  */
/* ------------------------------------------------------------------------- */
#define FLAG_ANIME_RECEIVED_PIKACHU              0x4000  /* Oak lab: Pikachu joins the party */
#define FLAG_ANIME_MET_BROCK                     0x4001  /* Pewter Gym / on-the-road intro */
#define FLAG_ANIME_DEFEATED_BROCK                0x4002  /* Boulder Badge */
#define FLAG_ANIME_MET_MISTY                     0x4003  /* Cerulean / traveling companion */
#define FLAG_ANIME_DEFEATED_MISTY                0x4004  /* Cascade Badge */
#define FLAG_ANIME_SS_ANNE_BOARDED               0x4005  /* S.S. Anne arc begins */
#define FLAG_ANIME_DEFEATED_LT_SURGE             0x4006  /* Thunder Badge */
#define FLAG_ANIME_POKEMON_TOWER_CLEARED         0x4007  /* Lavender Tower / ghost arc */
#define FLAG_ANIME_DEFEATED_ERIKA                0x4008  /* Rainbow Badge */
#define FLAG_ANIME_TEAM_ROCKET_HIDEOUT_CLEARED   0x4009  /* Celadon Rocket HQ */
#define FLAG_ANIME_DEFEATED_KOGA                 0x400A  /* Soul Badge (Fuchsia) */
#define FLAG_ANIME_DEFEATED_SABRINA              0x400B  /* Marsh Badge */
#define FLAG_ANIME_CINNABAR_CLEARED              0x400C  /* Blaine / Volcano Badge arc */
#define FLAG_ANIME_DEFEATED_BLAINE               0x400D  /* Volcano Badge */
#define FLAG_ANIME_DEFEATED_GIOVANNI             0x400E  /* Earth Badge / Viridian Gym */
#define FLAG_ANIME_ELITE_FOUR_CLEARED            0x400F  /* Indigo Plateau E4 */
#define FLAG_ANIME_CHAMPION_DEFEATED             0x4010  /* Kanto Champion beaten */
#define FLAG_ANIME_KANTO_STORY_COMPLETE          0x4011  /* Kanto arc locked finished */

/* ------------------------------------------------------------------------- */
/* Johto unlock — Pokémon Crystal                                            */
/* ------------------------------------------------------------------------- */
#define FLAG_ANIME_JOHTO_UNLOCKED                0x4020  /* Travel to Johto enabled */
#define FLAG_ANIME_ARRIVED_NEW_BARK              0x4021  /* New Bark Town intro */
#define FLAG_ANIME_MET_PROF_ELM                  0x4022  /* Professor Elm met */
#define FLAG_ANIME_RECEIVED_TOGEPI_EGG           0x4023  /* Anime egg / Togepi beat */
#define FLAG_ANIME_DEFEATED_FALKNER              0x4024  /* Zephyr Badge */
#define FLAG_ANIME_DEFEATED_BUGSY                0x4025  /* Hive Badge */
#define FLAG_ANIME_DEFEATED_WHITNEY              0x4026  /* Plain Badge */
#define FLAG_ANIME_BURNED_TOWER_CLEARED          0x4027  /* Burned Tower / legendary teaser */
#define FLAG_ANIME_DEFEATED_MORTY                0x4028  /* Fog Badge */
#define FLAG_ANIME_DEFEATED_CHUCK                0x4029  /* Storm Badge */
#define FLAG_ANIME_DEFEATED_JASMINE              0x402A  /* Mineral Badge */
#define FLAG_ANIME_DEFEATED_PRYCE                0x402B  /* Glacier Badge */
#define FLAG_ANIME_TEAM_ROCKET_RADIO_CLEARED     0x402C  /* Goldenrod Radio Tower */
#define FLAG_ANIME_DEFEATED_CLAIR                0x402D  /* Rising Badge */
#define FLAG_ANIME_JOHTO_ELITE_FOUR_CLEARED      0x402E  /* Johto E4 */
#define FLAG_ANIME_JOHTO_CHAMPION_DEFEATED       0x402F  /* Johto Champion */
#define FLAG_ANIME_JOHTO_STORY_COMPLETE          0x4030  /* Johto arc locked finished */

/* ------------------------------------------------------------------------- */
/* Hoenn arrival — Pokémon Emerald                                           */
/* ------------------------------------------------------------------------- */
#define FLAG_ANIME_HOENN_UNLOCKED                0x4040  /* Travel to Hoenn enabled */
#define FLAG_ANIME_ARRIVED_LITTLEROOT            0x4041  /* Littleroot Town intro */
#define FLAG_ANIME_MET_PROF_BIRCH                0x4042  /* Professor Birch met */
#define FLAG_ANIME_MET_MAY_OR_BRENDAN            0x4043  /* Rival companion intro */
#define FLAG_ANIME_DEFEATED_ROXANNE              0x4044  /* Stone Badge */
#define FLAG_ANIME_DEFEATED_BRAWLY               0x4045  /* Knuckle Badge */
#define FLAG_ANIME_DEFEATED_WATTSON              0x4046  /* Dynamo Badge */
#define FLAG_ANIME_DEFEATED_FLANNERY             0x4047  /* Heat Badge */
#define FLAG_ANIME_DEFEATED_NORMAN               0x4048  /* Balance Badge */
#define FLAG_ANIME_DEFEATED_WINONA               0x4049  /* Feather Badge */
#define FLAG_ANIME_DEFEATED_TATE_AND_LIZA        0x404A  /* Mind Badge */
#define FLAG_ANIME_DEFEATED_JUAN                 0x404B  /* Rain Badge (Emerald) */
#define FLAG_ANIME_TEAM_AQUA_MAGMA_CLEARED       0x404C  /* Aqua/Magma legend arc done */
#define FLAG_ANIME_HOENN_ELITE_FOUR_CLEARED      0x404D  /* Hoenn E4 */
#define FLAG_ANIME_HOENN_CHAMPION_DEFEATED       0x404E  /* Wallace / Steven finale */
#define FLAG_ANIME_HOENN_STORY_COMPLETE          0x404F  /* Hoenn arc locked finished */

/* Sentinel: last allocated anime flag (inclusive) for save-size checks */
#define FLAG_ANIME_END                           FLAG_ANIME_HOENN_STORY_COMPLETE

#endif /* GUARD_CONSTANTS_ANIME_FLAGS_H */
