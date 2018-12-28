#define MAX_BUFFER_LENGTH       0x800000
//#define MAX_TEMP_BUFFER_LENGTH  8192

#define MAX_MAPS_DEFINED        256
#define MAX_EMBEDDEDINFO        256

#define FLAGS_RC_BIT            (1 << 2)   // Bit2:0=Row 1=Column
#define FLAGS_ORDER_BIT         (1 << 1)   // Bit1:0=MSB First 1=LSB First
#define FLAGS_SIGNED_BIT        (1 << 0)   // Bit0:0=Unsigned 1=Signed

#define EMBEDDEDINFO_STORED     0
#define EMBEDDEDINFO_CALC       1
#define EMBEDDEDINFO_SCALED     2

#define OUTPUTTYPE_FLOAT        1
#define OUTPUTTYPE_INT          2
