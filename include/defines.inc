// Modulo de defines
#define Loop(%0,%1) for(new %0 = 0; %0 < %1; %0++)
#define DarMoney(%0,%1) ResetPlayerMoney(%0) && GivePlayerMoney(%0,%1) // meio que um anti money hack
#define function%0(%1) \
forward%0(%1); public%0(%1)