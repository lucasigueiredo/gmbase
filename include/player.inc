// modulo do player

hook OnPlayerConnect(playerid)
{
	SendDeathMessage(INVALID_PLAYER_ID,playerid,200);
	SendInfo(playerid, "Gamemode base criado por Vaca_Marinha :)");
    SetTimerEx("Camera", 2000, false, "i", playerid);
	PlayerInfo[playerid][Logged]=false;
	format(Conta, sizeof(Conta), "Contas/%s.ini", pNome(playerid));
	if(!DOF2_FileExists(Conta))
	{
		ShowPlayerDialog(playerid, DialogRegistro, DIALOG_STYLE_INPUT, "{FFB400}| {ffffff}Registro", "{cccccc}Digite uma senha para se registrar:", "Confirmar", "Cancelar");
	}
	else
	{
		ShowPlayerDialog(playerid, DialogLogin, DIALOG_STYLE_PASSWORD, "{FFB400}| {ffffff}Login", "{cccccc}Digite sua senha para fazer login.", "Confirmar", "Cancelar");
	}
	return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
	format(Conta, sizeof(Conta), "Contas/%s.ini", pNome(playerid));
	SendDeathMessage(INVALID_PLAYER_ID, playerid, 201);
	DOF2_SetInt(Conta, "Admin", PlayerInfo[playerid][pAdmin]);
	DOF2_SetInt(Conta, "Skin", PlayerInfo[playerid][pSkin]);
	DOF2_SetInt(Conta, "Dinheiro", GetPlayerMoney(playerid));
	DOF2_SetInt(Conta, "Score", GetPlayerScore(playerid));
	
	new Float:X, Float:Y, Float:Z, Float:A;
	GetPlayerPos(playerid, Float:X, Float:Y, Float:Z);
	GetPlayerFacingAngle(playerid,Float:A);
	DOF2_SetFloat(Conta, "PosX", X);
	DOF2_SetFloat(Conta, "PosY", Y);
	DOF2_SetFloat(Conta, "PosZ", Z);
	DOF2_SetFloat(Conta, "PosA", A);
	DOF2_SetInt(Conta, "Interior", GetPlayerInterior(playerid));
	DOF2_SetInt(Conta, "VW", GetPlayerVirtualWorld(playerid));
	
	DOF2_SaveFile();
	ResetarConta(playerid);
	return 1;
}

hook OnPlayerRequestSpawn(playerid) return IsPlayerLogged(playerid);

hook OnPlayerDeath(playerid, killerid, reason)
{
	PlayerInfo[playerid][pPosX]=2034.1435;
	PlayerInfo[playerid][pPosY]=-1402.1190;
	PlayerInfo[playerid][pPosZ]=16.6299;
	PlayerInfo[playerid][pPosA]=90.0;
	return 1;
}

hook OnPlayerText(playerid, text[ ])
{
	if(PlayerInfo[playerid][Logged] == false)
	{
		SendErro(playerid, "Voce nao esta logado.");
		return 0;
	}
	if(strlen(text) > 128)
	{
		SendErro(playerid, "Tamanho excede o limite.");
		return 0;
	}
	SendMsgChat(playerid, text);
	return 0;
}

hook OnPlayerSpawn(playerid)
{
	SetPlayerSkin(playerid, PlayerInfo[playerid][pSkin]);
	DarMoney(playerid,PlayerInfo[playerid][pDinheiro]);
	TogglePlayerControllable(playerid,true);
	return 1;
}

function Camera(playerid)
{
	if(PlayerInfo[playerid][Logged] == true) return 0;
	new Cam;
	Cam = random(10);
	SetPlayerInterior(playerid, 0);
	SetPlayerVirtualWorld(playerid, 0);
	if(Cam == 0)
	{
	    InterpolateCameraPos(playerid, 1058.97, -1993.59, 93.62, 1148.84, -1910.36, 99.72, 20000, CAMERA_MOVE);
        InterpolateCameraLookAt(playerid, 1018.58, -1961.75, 80.05, 1219.92, -1729.34, 94.56, 20000, CAMERA_MOVE);
	}
	if(Cam == 1)
	{
		InterpolateCameraPos(playerid, 2579.58, -2483.87, 26.73, 2484, -2140.80, 44.37, 20000, CAMERA_MOVE);
   		InterpolateCameraLookAt(playerid, 2453.64, -2128.88, 62.11, 2395.00, -2252.64, 48.40, 20000, CAMERA_CUT);
	}
	if(Cam == 2)
	{
   		InterpolateCameraPos(playerid, -525.53, 2590.02, 53.41, -430.67, 2507.26, 124.30, 20000, CAMERA_MOVE);
   		InterpolateCameraLookAt(playerid, -334.13, 2570.30, 109.20, -368.40, 2667.56, 94.27, 20000, CAMERA_CUT);
	}
    if(Cam == 3)
    {
		InterpolateCameraPos(playerid, -641.64, -668.51, 105.94, -614.86, -515.73, 105.70, 20000, CAMERA_MOVE);
   		InterpolateCameraLookAt(playerid, -641.64, -668.51, 105.94, -551.68, -484.83, 28.43, 20000, CAMERA_CUT);
    }
    if(Cam == 4)
    {
		InterpolateCameraPos(playerid, 1713.88, 511.36, 30.15, 2046.44, 934.79, 43.55, 20000, CAMERA_MOVE);
   		InterpolateCameraLookAt(playerid, 2099.92, 989.29, 52.30, 2045.30, 1027.89, 63.93, 20000, CAMERA_CUT);
    }
    if(Cam == 5)
    {
		InterpolateCameraPos(playerid, 899.69, 1848.11, 10.82, 870.37, 1743.50, 61.18, 20000, CAMERA_MOVE);
   		InterpolateCameraLookAt(playerid, 952.38, 1627.77, 45.63, 1035.46, 1647.17, 44.15, 20000, CAMERA_CUT);
    }
    if(Cam == 6)
    {
		InterpolateCameraPos(playerid, 2773.27, 2561.81, 10.82, 2580.57, 2512.01, 60.71, 20000, CAMERA_MOVE);
   		InterpolateCameraLookAt(playerid, 2566.11, 2576.34, 41.39, 2677.94, 2622.62, 34.76, 20000, CAMERA_CUT);
    }
    if(Cam == 7)
    {
		InterpolateCameraPos(playerid, 1893.29, -976.90, 32.07, -1835.56, -554.90, 93.97, 20000, CAMERA_MOVE);
   		InterpolateCameraLookAt(playerid, -1977.35, -548.45, 91.73, -1953.70, -452.13, 86.71, 20000, CAMERA_CUT);
    }
    if(Cam == 8)
    {
		InterpolateCameraPos(playerid, -1552.73, 119.06, 21.02, -1700.89, 188.40, 32.98, 20000, CAMERA_MOVE);
   		InterpolateCameraLookAt(playerid, -1722.21, 23.11, 44.64, -1779.58, 147.26, 59.27, 20000, CAMERA_CUT);
    }
    if(Cam == 9)
    {
		InterpolateCameraPos(playerid, 1399, -2300.0, 26.73, 2484, -2140.80, 44.37, 20000, CAMERA_MOVE);
   		InterpolateCameraLookAt(playerid, 2453.64, -2128.88, 62.11, 2395.00, -2252.64, 48.40, 20000, CAMERA_CUT);
    }
    if(Cam == 10)
    {
		InterpolateCameraPos(playerid, 2550, 2300, 40.0, 2484, -2140.80, 44.37, 20000, CAMERA_MOVE);
   		InterpolateCameraLookAt(playerid, 2453.64, -2128.88, 62.11, 2395.00, -2252.64, 48.40, 20000, CAMERA_CUT);
    }
	return 1;
}