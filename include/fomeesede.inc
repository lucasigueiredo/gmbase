// sistema de fome e sede
#include <progress>
#include <YSI_Coding\y_hooks>

new Bar:BFome;
new Bar:BSede;
new Text:SFome;
new Text:SSede;
new TimerF[MAX_PLAYERS];
new TimerS[MAX_PLAYERS];

hook OnGameModeInit()
{
    BFome = CreateProgressBar(550.00, 274.00, 55.50, 4.19, 0xFFFFFFAA, 100.0);
    BSede = CreateProgressBar(550.00, 294.00, 55.50, 4.19, 0xFFFFFFAA, 100.0);
    SetProgressBarMaxValue(BFome, 100);
	SetProgressBarMaxValue(BSede, 100);
	
	SFome = TextDrawCreate(535.000000, 270.000000, "hud:radar_burgerShot");
	TextDrawFont(SFome, 4);
	TextDrawTextSize(SFome, 10.000, 10.000);
	TextDrawUseBox(SFome, 1);

	SSede = TextDrawCreate(535.000000, 290.000000, "hud:radar_diner");
	TextDrawFont(SSede, 4);
	TextDrawTextSize(SSede, 10.000, 10.000);
	TextDrawUseBox(SSede, 1);
	return 1;
}

hook OnGameModeExit()
{
    HideProgressBarForAll(BFome);
    HideProgressBarForAll(BSede);
    return 1;
}

hook OnPlayerSpawn(playerid)
{
    ShowProgressBarForPlayer(playerid, BFome);
    ShowProgressBarForPlayer(playerid, BSede);
    UpdateProgressBar(BFome, playerid);
    UpdateProgressBar(BSede, playerid);
    TextDrawShowForPlayer(playerid, SFome);
	TextDrawShowForPlayer(playerid, SSede);
    TimerF[playerid] = SetTimerEx("Fome", 450000, true, "i", playerid);
    TimerS[playerid] = SetTimerEx("Sede", 400000, true, "i", playerid);
	return 1;
}

function Fome(playerid)
{
    SetPVarInt(playerid,"Fome",GetPVarInt(playerid,"Fome")+2);
    SetProgressBarValue(BFome, GetPVarInt(playerid,"Fome"));
    UpdateProgressBar(BFome,playerid);
    if(GetPVarInt(playerid,"Fome") >= 100)
    {
        new Float:Vida;
        GetPlayerHealth(playerid, Vida),SetPlayerHealth(playerid, Vida-2.0);
        SendClientMessage(playerid,-1,"| FOME | Seu jogador está com Fome, vá até um restaurante sanar está Fome!");
    }
	return 1;
}

function Sede(playerid)
{
    SetPVarInt(playerid,"Sede",GetPVarInt(playerid,"Sede")+2);
    SetProgressBarValue(BSede, GetPVarInt(playerid,"Sede"));
    UpdateProgressBar(BSede,playerid);
    if(GetPVarInt(playerid,"Fome") >= 100)
    {
        new Float:Vida;
        GetPlayerHealth(playerid, Vida),SetPlayerHealth(playerid, Vida-2.0);
        SendClientMessage(playerid,-1,"| SEDE | Seu jogador está com Sede, vá até um restaurante sanar está Sede!");
    }
	return 1;
}


