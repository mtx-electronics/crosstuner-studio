/***************************************************************
 * Name:      GlobalVariables.h
 **************************************************************/

#ifndef _GlobalVariables_H_
#define _GlobalVariables_H_


/*!
 * Includes
 */

#include "global_defines.h"

/*!
 * GlobalVariables class declaration
 */

class GlobalVariables
{
public:
        /// Constructors
        //GlobalVariables();

        /// Destructor
        //~GlobalVariables();

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

        // Variables used for data storage
        unsigned char *bin_buffer[3];
        unsigned int bin_length[3];
        unsigned short xmltable_count;
        wxString bin_path[3], bin_filename[3];

        wxString xmlformat_version;
        XMLHEADER xmlheader;
        XMLTABLE xmltable[MAX_MAPS_DEFINED];
        XMLAXIS xmlaxis[MAX_MAPS_DEFINED][3];
        XMLCHECKSUM xmlchecksum;

        unsigned short selected_bin;

private:

};

#endif
    // _GlobalVariables_H_
