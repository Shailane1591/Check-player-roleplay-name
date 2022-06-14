#include <check-player-roleplay-name> // add to all includes (on top)

public OnPlayerConnect(playerid) // default SA-MP function
{
    CheckPlayerRoleplayName(playerid); // check player name with use check-player-roleplay-name.inc

    return 1;
}
