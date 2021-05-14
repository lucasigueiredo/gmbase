/* GameMode base
Creditos: Vaca_Marinha
Conheça meu projeto de servidor: https://discord.gg/aYeCz99k3N
*/
#include <a_samp>
#include <a_http>
#include <zcmd>
#include <DOF2>
#include <streamer>
#include <sscanf2>
#include <dutils>
#include <strlib>
#include <YSI_Coding\y_hooks>

main() {
	print("----------------------\n");
	print("-         BY         -\n");
	print("-   Vaca_Marinha     -\n");
	print("\n----------------------");
}

public OnGameModeInit()
{
	SetGameModeText("by Vaca_Marinha"); // Pode retirar os creditos, use e abuse :))
    UsePlayerPedAnims();
    EnableStuntBonusForAll(0);
    DisableInteriorEnterExits();
	ShowPlayerMarkers(PLAYER_MARKERS_MODE_STREAMED);
	ShowNameTags(1);
	SetNameTagDrawDistance(100.0);
	
	SetTimer("AutoMensagens", 1000 * 60 * 2, true); // Mensagem automatica a cada 2 minutos
	return  1;
}

public OnGameModeExit()
{
	DOF2_Exit(); // Fechando o DOF2
	return 1;
}

#include "../include/main" // Incluindo o modulo principal

// Final do gamemode :)
