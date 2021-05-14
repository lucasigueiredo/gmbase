#include <sampvoice>
#include <YSI_Coding\y_hooks>

new SV_LSTREAM:lstream[MAX_PLAYERS] = { SV_NULL, ... };

public SV_VOID:OnPlayerActivationKeyPress(SV_UINT:playerid, SV_UINT:keyid) 
{
    if (keyid == 0x42 && lstream[playerid]) SvAttachSpeakerToStream(lstream[playerid], playerid);
}

public SV_VOID:OnPlayerActivationKeyRelease(SV_UINT:playerid, SV_UINT:keyid)
{
    if (keyid == 0x42 && lstream[playerid]) SvDetachSpeakerFromStream(lstream[playerid], playerid);
}

hook OnPlayerConnect(playerid)
{
    if (SvGetVersion(playerid) == SV_NULL)
    {
        SendErro(playerid, "Seu VOIP não foi encontrado, mas isso não interfere em nada.");
    }
    else if (SvHasMicro(playerid) == SV_FALSE)
    {
        SendErro(playerid, "Não foi encontrado nenhum microfone, mas isso não interfere em nada.");
    }
    else if ((lstream[playerid] = SvCreateDLStreamAtPlayer(40.0, SV_INFINITY, playerid, 0xff0000ff, "Local")))
    {
        SendInfo(playerid, "Nosso servidor possui VOIP, use B para falar no chat local.");

        SvAddKey(playerid, 0x42);
    }
    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    if (lstream[playerid])
    {
        SvDeleteStream(lstream[playerid]);
        lstream[playerid] = SV_NULL;
    }
    return 1;
}