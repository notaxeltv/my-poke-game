#include "global.h"
#include "pokemon.h"
#include "constants/pokemon.h"
#include "constants/species.h"

/*
 * Anime-style obedience: unlike battle_script_commands.c::Cmd_obediencecheck
 * / IsMonDisobedient, ownership (OT ID == player ID) does NOT grant immunity.
 * Ash's Charizard still refused orders after capture — badge level caps apply
 * to every party member, including the original trainer's own Pokémon.
 *
 * Return values (compatible with bool8 TRUE/FALSE checks):
 *   TRUE  (1) — mon obeys this turn
 *   FALSE (0) — mon is over the badge level cap (caller may run disobedience
 *               effects: loafing, snoring, attacking self, etc.)
 *
 * Optional integration: call from the obedience battle command before the
 * stock OT-ID early-out, or replace that early-out entirely.
 */

/* Forward declaration — implement via FlagGet on FLAG_BADGE0x_GET, or export
 * a shared helper from event_object_movement / script services when merging. */
u8 GetBadgeCount(void);

/* Per-badge max obedient level (anime-tuned; tweak freely). Index = badge count. */
static const u8 sAnimeObedienceLevelCaps[9] = {
    10,  /* 0 badges — early Kanto, Pikachu can already strain orders */
    20,  /* 1 — Boulder */
    30,  /* 2 — Cascade */
    40,  /* 3 — Thunder */
    50,  /* 4 — Rainbow */
    60,  /* 5 — Soul */
    70,  /* 6 — Marsh */
    80,  /* 7 — Volcano */
    100, /* 8 — Earth / full loyalty restored */
};

/* Stub usable until the real badge counter is linked from the expansion. */
u8 GetBadgeCount(void)
{
    /* Prefer a real implementation that counts FLAG_BADGE01_GET … FLAG_BADGE08_GET.
     * Returning 0 keeps obedience strict during early bring-up. */
    return 0;
}

bool8 CheckAnimeObedience(struct Pokemon *mon)
{
    u8 level;
    u8 badges;
    u8 levelCap;

    if (mon == NULL)
        return TRUE;

    /* Fainted / empty slots never need an obedience check. */
    if (GetMonData(mon, MON_DATA_SPECIES, NULL) == SPECIES_NONE)
        return TRUE;

    level = GetMonData(mon, MON_DATA_LEVEL, NULL);
    badges = GetBadgeCount();
    if (badges > 8)
        badges = 8;

    levelCap = sAnimeObedienceLevelCaps[badges];

    /*
     * INTENTIONAL DIVERGENCE FROM VANILLA:
     * Stock IsMonDisobedient returns early when
     *   GetMonData(mon, MON_DATA_OT_ID, NULL) == GetTrainerId(gSaveBlock2Ptr->playerTrainerId)
     * so traded-in mons alone are gated. Here we deliberately do NOT compare
     * OT IDs — the level-vs-badge test always runs, matching anime disobedience
     * for the player's own high-level Pokémon (Charizard, etc.).
     */
    if (level <= levelCap)
        return TRUE;

    return FALSE;
}
