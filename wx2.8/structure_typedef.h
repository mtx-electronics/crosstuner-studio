        typedef struct
        {
            unsigned short flags;
            wxString fileversion;
            wxString title;
            wxString description;
            wxString author;
            unsigned int baseoffset;
        } XMLHEADER;

        typedef struct
        {
            unsigned short flags;
            wxString title;
            wxString description;
        } XMLTABLE;

        typedef struct
        {
            wxString id;
            unsigned short flags;		// Bit0:0=Unsigned 1=Signed | Bit1:0=MSB First 1=LSB First | Bit2:0=Row 1=Column
            unsigned int address;
            unsigned short bits;
            wxString units;
            unsigned short decimalpl;
            //double min;
            //double max;
            unsigned short count;
            unsigned short outputtype;		// 1=Float 2=Int
            //unsigned short datatype;
            //unsigned short unittype;
            unsigned short embeddedinfotype;	// 0=Stored 1=Calculated
            double embeddedinfolabel[MAX_EMBEDDEDINFO];
            double factor;
            double offset;
        } XMLAXIS;

        typedef struct
        {
            wxString title;
            unsigned short pluginid;
        } XMLCHECKSUM;
