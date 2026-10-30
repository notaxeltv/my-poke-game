#include "global.h"
#include "pokemon.h"
#include "party_menu.h"
#include "constants/species.h"
#include "constants/moves.h"
#include "constants/abilities.h"
#include "constants/pokemon.h"
#include "constants/anime_flags.h"
#include "event_data.h"
#include "random.h"

/*
 * AssignAnimeStarterPikachu
 *
 * TECHNICAL NOTE — bypass of starter_choose.c:
 * In stock pokeemerald / FireRed ports, the player picks Bulbasaur, Charmander
 * or Squirtle via the CB2 / script flow in src/starter_choose.c (and the
 * matching special in event scripts). That path eventually calls
 * ScriptGiveMon / CreateMon for the chosen species and sets FLAG_SYS_POKEMON_GET.
 *
 * For the anime timeline we never enter that UI. Call this function from the
 * Oak-lab script (or a custom special) *instead* of Special_ChooseStarter /
 * CB2_ChooseStarter. Doing so:
 *   1) skips the triplet menu and the rival-starter mirror logic,
 *   2) injects Ash's Pikachu directly into gPlayerParty slot 0,
 *   3) raises FLAG_ANIME_RECEIVED_PIKACHU + FLAG_SYS_POKEMON_GET so overworld
 *      scripts that gate on "has a Pokémon" still behave correctly.
 *
 * Wire-up tip: replace the give-starter special in the lab script with
 *     special AssignAnimeStarterPikachu
 * and leave starter_choose.o unreferenced (or stub ChooseStarter to call here).
 */
void AssignAnimeStarterPikachu(void)
{
    struct Pokemon *mon = &gPlayerParty[0];
    u8 abilityNum;
    u8 nature;
    u16 movedata;
    u8 pp;

    /* Clear party so this is unambiguously the first partner Pokémon. */
    ZeroPlayerPartyMons();

    /*
     * Nature: pick a fixed "Ash-like" Brave nature for reproducibility in
     * cutscenes, or Random() % NUM_NATURES for a mild RNG feel. Brave is used
     * here so early battles match a punchy anime tone; swap as desired.
     */
    nature = NATURE_BRAVE;

    /* Level 5 partner, perfect IVs optional — 32 = random IVs in CreateMon*. */
    CreateMonWithNature(mon, SPECIES_PIKACHU, 5, 32, nature);

    /*
     * Force Ability Static (Pikachu ability slot 0). Slot 1 would be
     * Lightning Rod in modern expansions; Hidden Ability is separate.
     */
    abilityNum = 0;
    SetMonData(mon, MON_DATA_ABILITY_NUM, &abilityNum);

    /* Anime opening moveset: Thunder Shock + Tail Whip; clear other slots. */
    movedata = MOVE_THUNDERSHOCK;
    SetMonData(mon, MON_DATA_MOVE1, &movedata);
    movedata = MOVE_TAIL_WHIP;
    SetMonData(mon, MON_DATA_MOVE2, &movedata);
    movedata = MOVE_NONE;
    SetMonData(mon, MON_DATA_MOVE3, &movedata);
    SetMonData(mon, MON_DATA_MOVE4, &movedata);

    pp = 30; /* Thunder Shock max PP */
    SetMonData(mon, MON_DATA_PP1, &pp);
    pp = 30; /* Tail Whip max PP */
    SetMonData(mon, MON_DATA_PP2, &pp);
    pp = 0;
    SetMonData(mon, MON_DATA_PP3, &pp);
    SetMonData(mon, MON_DATA_PP4, &pp);

    CalculateMonStats(mon);

    /* Mark anime + engine "owns Pokémon" state. */
    FlagSet(FLAG_ANIME_RECEIVED_PIKACHU);
    FlagSet(FLAG_SYS_POKEMON_GET);
}
