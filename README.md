# check-player-roleplay-name.inc

#gh-dark-mode-only
**#include <check-player-roleplay-name.inc>** // add to all includes (on top)

public OnPlayerConnect(playerid) // default SA-MP function
{
    CheckPlayerRoleplayName(playerid); // check player name with use check-player-roleplay.inc

    return 1;
}
