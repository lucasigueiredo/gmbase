MostrarRegistro(playerid) {
	return ShowPlayerDialog(playerid, DialogRegistro, DIALOG_STYLE_INPUT, "{FFB400}| {ffffff}Registro", "{cccccc}Digite uma senha para se registrar:", "Confirmar", "Cancelar");
}
MostrarLogin(playerid) {
	return ShowPlayerDialog(playerid, DialogLogin, DIALOG_STYLE_PASSWORD, "{FFB400}| {ffffff}Login", "{cccccc}Digite sua senha para fazer login.", "Confirmar", "Cancelar");
}

Dialog_Registro(playerid, response, inputtext[])
{
	if(!response) return MostrarRegistro(playerid);
	if(strlen(inputtext) < 4) return MostrarRegistro(playerid);
	if(response)
	{
		if(strlen(inputtext))
		{		
			format(Conta, sizeof(Conta), "Contas/%s.ini", pNome(playerid));
			DOF2_CreateFile(Conta);
			DOF2_SetString(Conta, "Senha", inputtext);
			DOF2_SaveFile();
			
			CriarConta(playerid);
			CarregarConta(playerid);
		}
		else return MostrarRegistro(playerid);
	}
	return 1;
}

Dialog_Login(playerid, response, inputtext[])
{
	if(!response) return MostrarLogin(playerid);
	if(response)
	{
		if(!strlen(inputtext))
		{
			return MostrarLogin(playerid); 
		}
		format(Conta, sizeof(Conta), "Contas/%s.ini", pNome(playerid));
		if(strcmp(inputtext, DOF2_GetString(Conta, "Senha"), true))
		{
			MostrarLogin(playerid);
			return SendClientMessage(playerid, -1, "Senha incorreta!");
		}
		else 
		{
			return CarregarConta(playerid);
		}
	}
	return 1;
}

hook OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid == DialogRegistro) return Dialog_Registro(playerid, response, inputtext);
	if(dialogid == DialogLogin) return Dialog_Login(playerid, response, inputtext);
	return 1;
}