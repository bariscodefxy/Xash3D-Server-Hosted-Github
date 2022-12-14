// vim: set ts=4 sw=4 tw=99 noet:
//
// AMX Mod X, based on AMX Mod by Aleksander Naszko ("OLO").
// Copyright (C) The AMX Mod X Development Team.
//
// This software is licensed under the GNU General Public License, version 3 or higher.
// Additional exceptions apply. For full license details, see LICENSE.txt or visit:
//     https://alliedmods.net/amxmodx-license

#if defined _csstats_included
	#endinput
#endif
#define _csstats_included

/**
 * Retrieves the client's current weapon statistics.
 *
 * @note For a list of default CS weapon ids see the CSW_* constants in
 *       amxconst.inc, this function also works on custom weapons.
 * @note For a list of possible body hitplaces see the HIT_* constants in
 *       amxconst.inc
 * @note The fields in the statistics are:
 *          0 - Kills
 *          1 - Deaths
 *          2 - Headshots
 *          3 - Teamkills
 *          4 - Shots
 *          5 - Hits
 *          6 - Damage
 *
 * @param index     Client index
 * @param wpnindex  Weapon id, or 0 to retrieve total statistics across all
 *                  weapons
 * @param stats     Buffer to copy statistics to
 * @param bodyhits  Buffer to copy body hits to
 *
 * @return          1 on success, 0 if no statistics are available for the weapon
 *                  id
 * @error           If an invalid client index or weapon id is provided, an
 *                  error will be thrown.
 */
native get_user_wstats(index, wpnindex, stats[8], bodyhits[8]);

/**
 * Retrieves the client's weapon statistics from the current round.
 *
 * @note For a list of default CS weapon ids see the CSW_* constants in
 *       amxconst.inc, this function also works on custom weapons.
 * @note For a list of possible body hitplaces see the HIT_* constants in
 *       amxconst.inc
 * @note The fields in the statistics are:
 *          0 - Kills
 *          1 - Deaths
 *          2 - Headshots
 *          3 - Teamkills
 *          4 - Shots
 *          5 - Hits
 *          6 - Damage
 *
 * @param index     Client index
 * @param wpnindex  Weapon id, or 0 to retrieve total statistics across all
 *                  weapons
 * @param stats     Buffer to copy statistics to
 * @param bodyhits  Buffer to copy body hits to
 *
 * @return          1 on success, 0 if no statistics are available for the
 *                  weapon id
 * @error           If an invalid client index or weapon id is provided, an
 *                  error will be thrown.
 */
native get_user_wrstats(index, wpnindex, stats[8], bodyhits[8]);

/**
 * Retrieves the client's weapon statistics from the permanent storage on the
 * server.
 *
 * @note The permanent storage is updated on every respawn or client disconnect.
 * @note Player rank is determined by the customizable "get_score" function in
 *       "data/csstats.amxx". By default it uses the difference of kills to
 *       deaths/teamkills.
 * @note For a list of possible body hitplaces see the HIT_* constants in
 *       amxconst.inc
 * @note The fields in the statistics are:
 *          0 - Kills
 *          1 - Deaths
 *          2 - Headshots
 *          3 - Teamkills
 *          4 - Shots
 *          5 - Hits
 *          6 - Damage
 *          7 - Rank
 *
 * @param index     Client index
 * @param stats     Buffer to copy statistics to
 * @param bodyhits  Buffer to copy body hits to
 *
 * @return          Players rank > 0 on success, or 0 if player is not ranked
 *                  and no statistics are available
 * @error           If an invalid client index is provided, an error will be
 *                  thrown.
 */
native get_user_stats(index, stats[8], bodyhits[8]);

/**
 * Retrieves the client's statistics from the current round.
 *
 * @note For a list of possible body hitplaces see the HIT_* constants in
 *       amxconst.inc
 * @note The fields in the statistics are:
 *          0 - Kills
 *          1 - Deaths
 *          2 - Headshots
 *          3 - Teamkills
 *          4 - Shots
 *          5 - Hits
 *          6 - Damage
 *
 * @param index     Client index
 * @param stats     Buffer to copy statistics to
 * @param bodyhits  Buffer to copy body hits to
 *
 * @return          1 on success, 0 if no statistics are available
 * @error           If an invalid client index is provided, an error will be
 *                  thrown.
 */
native get_user_rstats(index, stats[8], bodyhits[8]);

/**
 * Retrieves the client's statistics inflicted upon another client from the
 * current round.
 *
 * @note For a list of possible body hitplaces see the HIT_* constants in
 *       amxconst.inc
 * @note The fields in the statistics are:
 *          0 - Kills
 *          1 - Deaths
 *          2 - Headshots
 *          3 - Teamkills
 *          4 - Shots
 *          5 - Hits
 *          6 - Damage
 *
 * @param index     Client index
 * @param victim    Victim client index, or 0 to retrieve the statistics against
 *                  all victims
 * @param stats     Buffer to copy statistics to
 * @param bodyhits  Buffer to copy body hits to
 * @param wpnname   Optional buffer to copy last used weapon name to
 * @param len       Maximum buffer size
 *
 * @return          1 on success, 0 if no statistics are available against the
 *                  specified victim
 * @error           If an invalid client index is provided, an error will be
 *                  thrown.
 */
native get_user_vstats(index, victim, stats[8], bodyhits[8], wpnname[] = "", len = 0);

/**
 * Retrieves the client's statistics received from another client from the
 * current round.
 *
 * @note For a list of possible body hitplaces see the HIT_* constants in
 *       amxconst.inc
 * @note The fields in the statistics are:
 *          0 - Kills
 *          1 - Deaths
 *          2 - Headshots
 *          3 - Teamkills
 *          4 - Shots
 *          5 - Hits
 *          6 - Damage
 *
 * @param index     Client index
 * @param wpnindex  Attacker client index, or 0 to retrieve the statistics from
 *                  all attackers
 * @param stats     Buffer to copy statistics to
 * @param bodyhits  Buffer to copy body hits to
 * @param wpnname   Optional buffer to copy last used weapon name to
 * @param len       Maximum buffer size
 *
 * @return          1 on success, 0 if no statistics are available against the
 *                  specified attacker
 * @error           If an invalid client index is provided, an error will be
 *                  thrown.
 */
native get_user_astats(index, wpnindex, stats[8], bodyhits[8], wpnname[] = "", len = 0);

/**
 * Resets the current round weapon, attacker and victim statistics.
 *
 * @param index     Client index
 *
 * @noreturn
 * @error           If an invalid client index is provided, an error will be
 *                  thrown.
 */
native reset_user_wstats(index);

/**
 * Retrieves statistics from the permanent storage on the server via iterative,
 * incremental access.
 *
 * @note The permanent storage is updated on every respawn or client disconnect.
 * @note Player rank is determined by the customizable "get_score" function in
 *       "data/csstats.amxx". By default it uses the difference of kills to
 *       deaths/teamkills.
 * @note For a list of possible body hitplaces see the HIT_* constants in
 *       amxconst.inc
 * @note The fields in the statistics are:
 *          0 - Kills
 *          1 - Deaths
 *          2 - Headshots
 *          3 - Teamkills
 *          4 - Shots
 *          5 - Hits
 *          6 - Damage
 *          7 - Rank
 *
 * @param index         Rank index
 * @param stats         Buffer to copy statistics to
 * @param bodyhits      Buffer to copy body hits to
 * @param name          Buffer to copy client name to
 * @param len           Maximum name buffer size
 * @param authid        Buffer to copy client auth id to
 * @param authidlen     Maximum authid buffer size
 *
 * @return              Next rank index (> 0 and > index), or 0 if no more
 *                      statistics exist
 */
native get_stats(index, stats[8], bodyhits[8], name[], len, authid[] = "", authidlen = 0);

/**
 * Returns the number of all entries in the permanent statistics storage.
 *
 * @return  Number of entries in statistics storage
 */
native get_statsnum();

/**
 * Retrieves the client's objective statistics from the permanent storage.
 *
 * @note The permanent storage is updated on every respawn or client disconnect.
 * @note The fields in the statistics are:
 *          0 - total defusions
 *          1 - bomb defused
 *          2 - bomb plants
 *          3 - bomb explosions
 *
 * @param index     Client index
 * @param stats     Buffer to copy statistics to
 *
 * @return          Players rank > 0 on success, or 0 if player is not ranked
 *                  and no statistics are available
 * @error           If an invalid client index is provided, an error will be
 *                  thrown.
 */
native get_user_stats2(index, stats[4]);

/**
 * Retrieves objective statistics from the permanent storage on the server via
 * iterative, incremental access.
 *
 * @note The permanent storage is updated on every respawn or client disconnect.
 * @note The fields in the statistics are:
 *          0 - total defusions
 *          1 - bomb defused
 *          2 - bomb plants
 *          3 - bomb explosions
 *
 * @param index         Client index
 * @param stats         Buffer to copy statistics to
 * @param authid        Buffer to copy client auth id to
 * @param authidlen     Maximum authid buffer size
 *
 * @return              Next rank index (> 0 and > index), or 0 if no more
 *                      statistics exist
 */
native get_stats2(index, stats[4], authid[] = "", authidlen = 0);

/* New Native */

/* 
*  Returns the Rank of Player. --> index = id. 
*  Returns 0 if no Rank exists.
*/
native get_user_rank(index);

/*
*  Gets current session score of player --> index = id
*  Returns 0 if player is not valid/out of range
*  Returns 1
*/
native get_user_score(index, &frags, &deaths);

/*
*  Sets overall stats of Player with given parameters. --> index = id. 
*  Returns 0 if player is not valid/out of range
*  Returns new Rank
*
*  Note - If you don't want to edit/set a stats/bodyhits field,
*  you can set its value as -1
*/
native set_user_stats(index, stats[8], bodyhits[8]);

native set_user_stats2(index, stats2[4]);

/*
*  Sets overall stats with given parameters. --> index = position. 
*  Returns new Rank
*
*  Note - If you don't want to edit/set a stats/bodyhits field,
*  you can set its value as -1
*/
native set_stats(index, stats[8], bodyhits[8]);

native set_stats2(index, stats2[4]);

/*
*  Sets current session score of player --> index = id
*  Returns 0 if player is not valid/out of range
*  Returns 1
*
*  Note - If you don't want to edit/set a stats/bodyhits field,
*  you can set its value as -1
*/
native set_user_score(index, frags, deaths, bool:resetStats = false);

/*
*  Resets overall stats to null --> index = id.
*  Returns 0 if player is not valid/out of range
*  Returns new Rank
*
*  Note - This doesn't differentiate stats or stats2.
*  It simply nulls the entire Stats structure of index.
*/
native reset_user_stats(index)

/*
*  Resets overall stats to null --> index = position.
*  Returns new Rank
*
*  Note - This doesn't differentiate stats or stats2.
*  It simply nulls the entire Stats structure of index.
*/
native reset_stats(index)

/*
*  Adds/Pushes overall stats with given parameters.
*  Returns 0 if Stats Entry already exists or can't be created
*  Returns new Rank
*
*  Note - If you don't want to set a stats/bodyhits field,
*  you can set its value as -1
*
* IMPORTANT : "unique" is based on the value of "csstats_rank" cvar 
* which sets the basis for uniquely defining a rankstats entry:
* 0 - name[]
* 1 - authid[]
* 2 - ip[] ( make sure to set parameter isip = 1 )
*
* WARNING : Use this function with Caution.
*/
native push_stats(const unique[], const name[], stats[8], bodyhits[8], isip=0);

/*
* Removes and Deletes the Stats Entry. --> index = position. 
*  Returns -1 if position is not found.
*  Returns 1 if successfully removed.
*/
native remove_stats(index);

/* 
*  Reloads all the stats from the file and 
*  refresh rankstats of all the connected 
*  players and also reset current score of player
*  Returns 1
*
*  Note - If the stats are not externally edited
*  then this will restore the stats from previous
*  map change or from start of HLDS as by default,
*  stats file is saved only at these moments.
*
*  If the stats file doesn't exist, the function
*  will not load stats. The stats in-game will remain
*  the same as before.
*
*  default stats file path : amxmodx/data/csstats.dat
*/
native force_load_stats();

/*
*  Manually saves all the stats till previous round
*  before Restart of Map/Server.
*  Returns 1
*
*  default stats file path : amxmodx/data/csstats.dat
*/
native force_save_stats();

/*
*  Resets the Score
*/
stock reset_user_score(id)
{
	return set_user_score(id, 0, 0);
}
