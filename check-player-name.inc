/* colors */
#define NAME_SERVER_COLOR    (0xFFFF90FF)
#define NAME_YELLOW_COLOR   (0xFFFF00FF)

/* Massage */
#define Server(%0,%1) \
	SendClientMessageEx(%0, NAME_SERVER_COLOR, "[SERVER]:{FFFFFF} "%1)

#define Syntax(%0,%1) \
	SendClientMessageEx(%0, NAME_YELLOW_COLOR, "[SYNTAX]:{FFFFFF} "%1)


/* Function */
stock CheckPlayerRoleplayName(playerid)
{
    new name[MAX_PLAYER_NAME];
    GetPlayerName(playerid, name, sizeof(name));

    new reason[10];

    if(name[0] < 65 || name[0] > 90) reason[1] = 1;
    for(new i = 1; i < strlen(name); i++)
    {
        if(name[i] == 95) reason[0]++;
        else if(reason[0] == 1)
        {
            reason[0]++;
            if(name[i] < 65 || name[i] > 90) reason[2] = 1;
        }
        else if((reason[i] < 97 || name[i] > 122) && reason[0] == 0)
        {
            if(name[i] < 65 || name[i] > 90) reason[3] += 15;
            else reason[3]++;
        }
        else if((name[i] > 96 && name[i] < 123) && reason[0] == 0) reason[5]++;
        else if((name[i] < 97 || name[i] > 122) && reason[0] == 2)
        {
            if(name[i] < 65 || name[i] > 90) reason[4] += 15;
            else reason[4]++;
        }
        else if((name[i] > 96 && name[i] < 123) && reason[0] == 2) reason[6]++;
    }

    if(reason[0] != 2 || reason[1] != 0 || reason[2] != 0 || reason[3] != 0 || reason[4] != 0)
    {
        Syntax(playerid, "Nama roleplay yang valid contoh: {33CCFF}Shailane_Woodley {FFFFFF}& {33CCFF}Etc{FFFFFF}!");
        if(reason[0] != 2)
        {
            if(reason[0] == 0) Server(playerid, "Nick harus menggunakan satu {33CCFF}\"_\"{ffffff} untuk memisahkan Nama Depan dan Nama Belakang");
            else Server(playerid, "Anda tidak dapat menggunakan karakter {33CCFF}\"_\"." beberapa kali dalam nama panggilan.);
        }
        if(reason[1] != 0) Server(playerid, "Nama panggilan Anda harus dimulai dengan huruf kapital.");
        if(reason[2] == 1) Syntax(playerid, "Bagian kedua dari nama panggilan Anda harus dimulai dengan huruf kapital.");
        if(reason[3] != 0)
        {
            if(reason[3] >= 15) Server(playerid, "Anda menggunakan huruf kapital lebih dari sekali di bagian pertama nama panggilan Anda.");
            else Syntax(playerid, "Anda menggunakan karakter ilegal di bagian pertama nama panggilan Anda.");
        }
        if(reason[4] != 0)
        {
            if(reason[4] >= 15) Syntax(playerid, "Anda menggunakan huruf kapital lebih dari sekali di bagian kedua nama panggilan Anda.");
            else Syntax(playerid, "Anda menggunakan karakter ilegal di bagian kedua nama panggilan Anda.");
        }
        if(reason[5] < 3) Server(playerid, "Bagian pertama dari nama panggilan Anda terlalu pendek.");
        if(reason[6] < 3 && reason[0] >= 2) Server(playerid, "Bagian kedua dari nama panggilan Anda terlalu pendek.");

        Kick(playerid);
    }
    return true;
}
