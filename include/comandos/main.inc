#include "../include/comandos/admin" // comandos ademiro

// para adicionar um novo modulo de comandos use:
// #include "../include/comandos/nome do modulo" //

public OnPlayerCommandPerformed(playerid, cmdtext[], success) {
	if(!success) return SendErro(playerid, "Comando inválido.");
	return 1;
}