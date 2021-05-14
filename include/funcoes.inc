// modulo de funcoes


// > Funcoes dos players <

ResetarConta(playerid) // funcao pra resetar todos os dados ao player sair
{
	PlayerInfo[playerid] = reset;
}

IsPlayerLogged(playerid)
{
	if(PlayerInfo[playerid][Logged] == true)
	{
		SetSpawnInfo(playerid,-1,PlayerInfo[playerid][pSkin],PlayerInfo[playerid][pPosX],PlayerInfo[playerid][pPosY],PlayerInfo[playerid][pPosZ],PlayerInfo[playerid][pPosA],0,0,0,0,0,0);
		SpawnPlayer(playerid);
		SetPlayerInterior(playerid, 0);
		SetCameraBehindPlayer(playerid);
	}
	return 1;
}

CriarConta(playerid)
{
	format(Conta, sizeof(Conta), "Contas/%s.ini", pNome(playerid));
	
	DOF2_SetInt(Conta, "Admin", 0);
	DOF2_SetInt(Conta, "Skin", 98);
	DOF2_SetInt(Conta, "Dinheiro", 500);
	DOF2_SetInt(Conta, "Score", 0);
	DOF2_SetFloat(Conta, "PosX", 2069.8767);
	DOF2_SetFloat(Conta, "PosY", -1766.6870);
	DOF2_SetFloat(Conta, "PosZ", 13.5621);
	DOF2_SetFloat(Conta, "PosA", 90.0);
	DOF2_SetInt(Conta, "Interior", 0);
	DOF2_SetInt(Conta, "VW", 0);
	
	DOF2_SaveFile();
}

CarregarConta(playerid)
{
	format(Conta, sizeof(Conta), "Contas/%s.ini", pNome(playerid));
	
	PlayerInfo[playerid][pAdmin] = DOF2_GetInt(Conta, "Admin");
	PlayerInfo[playerid][pSkin] = DOF2_GetInt(Conta, "Skin");
	PlayerInfo[playerid][pDinheiro] = DOF2_GetInt(Conta, "Dinheiro");
	PlayerInfo[playerid][pScore] = DOF2_GetInt(Conta, "Score");
	PlayerInfo[playerid][pPosX] = DOF2_GetInt(Conta, "PosX");
	PlayerInfo[playerid][pPosY] = DOF2_GetInt(Conta, "PosY");
	PlayerInfo[playerid][pPosZ] = DOF2_GetInt(Conta, "PosZ");
	PlayerInfo[playerid][pPosA] = DOF2_GetInt(Conta, "PosA");
	PlayerInfo[playerid][pInterior] = DOF2_GetInt(Conta, "Interior");
	PlayerInfo[playerid][pVW] = DOF2_GetInt(Conta, "VW");
	PlayerInfo[playerid][Logged]=true;
	
	SetPlayerScore(playerid, PlayerInfo[playerid][pScore]);
	DarMoney(playerid, PlayerInfo[playerid][pDinheiro]);
	SetPlayerInterior(playerid, PlayerInfo[playerid][pInterior]);
	SetSpawnInfo(playerid, -1, PlayerInfo[playerid][pSkin], PlayerInfo[playerid][pPosX], PlayerInfo[playerid][pPosY], PlayerInfo[playerid][pPosZ], PlayerInfo[playerid][pPosA],0,0,0,0,0,0);
	SpawnPlayer(playerid);
	SetPlayerVirtualWorld(playerid, PlayerInfo[playerid][pVW]);
	return 1;
}

pNome(playerid)
{
	new vNome[MAX_PLAYER_NAME];
	GetPlayerName(playerid, vNome, 24);
	return vNome;
}

// > Mensagens uteis

SendErro(playerid, texto[])
{
	new string[1024];
	format(string, sizeof(string), "{FC1919}Erro | {FF7878}%s", texto);
	return SendClientMessage(playerid, -1, string);
}

SendInfo(playerid, texto[])
{
	new string[1024];
	format(string, sizeof(string), "{1FD1BA}Info | {9FFFF3}%s", texto);
	return SendClientMessage(playerid, -1, string);
}

SendMsgChat(playerid, texto[])
{	
	new tag[128], string[1024];
	switch(PlayerInfo[playerid][pAdmin])
	{
		case 0: {
			format(tag, sizeof(tag), "");
		}
		case 1: {
			format(tag, sizeof(tag), "{00A8FF}[ADMIN]");
		}
		case 2: {
			format(tag, sizeof(tag), "{7E00FF}[DONO]");
		}
	}
	format(string, sizeof(string), "%s{FFE5BB}%s(%i){ffffff}: %s", tag, pNome(playerid), playerid, texto);
	return SendClientMessageToAll(-1, string);
}

// > Coisa atoa

function AutoMensagens() {
	SendClientMessageToAll(-1, MensagensAuto[UltimaAutoMensagem]);
	// Select the next message
    UltimaAutoMensagem++;

	// Check if the next chosen message exists (the messagenumber is the same as the size of the array of messages)
	if (UltimaAutoMensagem == sizeof(MensagensAuto))
	    UltimaAutoMensagem = 0; // Select the first message again

	return 1;
}

ReturnVehicleID(vName[])
{
	Loop(x, 211)
	{
	    if(strfind(vNames[x], vName, true) != -1)
		return x + 400;
	}
	return -1;
}