/***************************************************************
 * Name:      CrossTunerStudioMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Faro Salvatore (info@mtx-electronics.com)
 * Created:   2009-09-14
 * Copyright: MTX Electronics (www.mtx-electronics.com)
 ***************************************************************
 *
 * This file is part of CrossTuner Studio.
 *
 *    CrossTuner Studio is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    CrossTuner Studio is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with the CrossTuner Studio Code.  
 *    If not, see <http://www.gnu.org/licenses/>.
 *
 ***************************************************************/
 
/*
	wxDynamicLibrary dll;
	if (!dll.Load(wxStandardPaths::Get().GetExecutablePath().BeforeLast(wxFILE_SEP_PATH)+wxT("/renddll.so")))
        StatusBar->SetStatusText(_("ERROR!!!"),1);
    else
    {
        StatusBar->SetStatusText(_("OK!!!"),1);

        if(dll.IsLoaded())
        {
              StatusBar->SetStatusText(_("DLL LOADED!!!"),1);
              typedef void (*RunApp)(wxWindow*);
              RunApp myFunc = (RunApp) (dll.GetSymbol(wxT("RunApp")));
              myFunc(this);
              dll.Detach();
              dll.Unload();
        }

    }
*/

#include "wx_pch.h"
#include <wx/msgdlg.h>
#include <wx/ffile.h>
#include <wx/filefn.h>
#include <wx/config.h>
#include <wx/mstream.h>
#include <wx/stdpaths.h>
#include <wx/dynlib.h>

//(*InternalHeaders(CrossTunerStudioFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "tinyxml.h"
#include "CrossTunerStudioMain.h"
#include "AboutBoxDialog.h"
#include "MapViewer/MapViewerMain.h"
#include "MapEditor/MapEditorMain.h"
#include "TableEditor/TableEditorMain.h"
#include "Map2DEditor/Map2DEditorMain.h"

#include "images/appicon.h"
#include "images/toolbar.h"

// Global tables for CRC's
const unsigned char crc8_lookup_table[] = {
        0x00, 0x07, 0x0e, 0x09, 0x1c, 0x1b, 0x12, 0x15,
        0x38, 0x3f, 0x36, 0x31, 0x24, 0x23, 0x2a, 0x2d,
        0x70, 0x77, 0x7E, 0x79, 0x6C, 0x6B, 0x62, 0x65,
        0x48, 0x4F, 0x46, 0x41, 0x54, 0x53, 0x5A, 0x5D,
        0xE0, 0xE7, 0xEE, 0xE9, 0xFC, 0xFB, 0xF2, 0xF5,
        0xD8, 0xDF, 0xD6, 0xD1, 0xC4, 0xC3, 0xCA, 0xCD,
        0x90, 0x97, 0x9E, 0x99, 0x8C, 0x8B, 0x82, 0x85,
        0xA8, 0xAF, 0xA6, 0xA1, 0xB4, 0xB3, 0xBA, 0xBD,
        0xC7, 0xC0, 0xC9, 0xCE, 0xDB, 0xDC, 0xD5, 0xD2,
        0xFF, 0xF8, 0xF1, 0xF6, 0xE3, 0xE4, 0xED, 0xEA,
        0xB7, 0xB0, 0xB9, 0xBE, 0xAB, 0xAC, 0xA5, 0xA2,
        0x8F, 0x88, 0x81, 0x86, 0x93, 0x94, 0x9D, 0x9A,
        0x27, 0x20, 0x29, 0x2E, 0x3B, 0x3C, 0x35, 0x32,
        0x1F, 0x18, 0x11, 0x16, 0x03, 0x04, 0x0D, 0x0A,
        0x57, 0x50, 0x59, 0x5E, 0x4B, 0x4C, 0x45, 0x42,
        0x6F, 0x68, 0x61, 0x66, 0x73, 0x74, 0x7D, 0x7A,
        0x89, 0x8E, 0x87, 0x80, 0x95, 0x92, 0x9B, 0x9C,
        0xB1, 0xB6, 0xBF, 0xB8, 0xAD, 0xAA, 0xA3, 0xA4,
        0xF9, 0xFE, 0xF7, 0xF0, 0xE5, 0xE2, 0xEB, 0xEC,
        0xC1, 0xC6, 0xCF, 0xC8, 0xDD, 0xDA, 0xD3, 0xD4,
        0x69, 0x6E, 0x67, 0x60, 0x75, 0x72, 0x7B, 0x7C,
        0x51, 0x56, 0x5F, 0x58, 0x4D, 0x4A, 0x43, 0x44,
        0x19, 0x1E, 0x17, 0x10, 0x05, 0x02, 0x0B, 0x0C,
        0x21, 0x26, 0x2F, 0x28, 0x3D, 0x3A, 0x33, 0x34,
        0x4E, 0x49, 0x40, 0x47, 0x52, 0x55, 0x5C, 0x5B,
        0x76, 0x71, 0x78, 0x7F, 0x6A, 0x6D, 0x64, 0x63,
        0x3E, 0x39, 0x30, 0x37, 0x22, 0x25, 0x2C, 0x2B,
        0x06, 0x01, 0x08, 0x0F, 0x1A, 0x1D, 0x14, 0x13,
        0xAE, 0xA9, 0xA0, 0xA7, 0xB2, 0xB5, 0xBC, 0xBB,
        0x96, 0x91, 0x98, 0x9F, 0x8A, 0x8D, 0x84, 0x83,
        0xDE, 0xD9, 0xD0, 0xD7, 0xC2, 0xC5, 0xCC, 0xCB,
        0xE6, 0xE1, 0xE8, 0xEF, 0xFA, 0xFD, 0xF4, 0xF3 };

const unsigned short crc16_lookup_table[] = {
        0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241, 0xC601, 0x06C0, 0x0780,
        0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440, 0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1,
        0xCE81, 0x0E40, 0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841, 0xD801,
        0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40, 0x1E00, 0xDEC1, 0xDF81, 0x1F40,
        0xDD01, 0x1DC0, 0x1C80, 0xDC41, 0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680,
        0xD641, 0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040, 0xF001, 0x30C0,
        0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240, 0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501,
        0x35C0, 0x3480, 0xF441, 0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41,
        0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840, 0x2800, 0xE8C1, 0xE981,
        0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41, 0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1,
        0xEC81, 0x2C40, 0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640, 0x2200,
        0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041, 0xA001, 0x60C0, 0x6180, 0xA141,
        0x6300, 0xA3C1, 0xA281, 0x6240, 0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480,
        0xA441, 0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41, 0xAA01, 0x6AC0,
        0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840, 0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01,
        0x7BC0, 0x7A80, 0xBA41, 0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
        0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640, 0x7200, 0xB2C1, 0xB381,
        0x7340, 0xB101, 0x71C0, 0x7080, 0xB041, 0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0,
        0x5280, 0x9241, 0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440, 0x9C01,
        0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40, 0x5A00, 0x9AC1, 0x9B81, 0x5B40,
        0x9901, 0x59C0, 0x5880, 0x9841, 0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81,
        0x4A40, 0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41, 0x4400, 0x84C1,
        0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641, 0x8201, 0x42C0, 0x4380, 0x8341, 0x4100,
        0x81C1, 0x8081, 0x4040 };

const unsigned int crc32_lookup_table[] = {
        0x00000000, 0x77073096, 0xEE0E612C, 0x990951BA,
        0x076DC419, 0x706AF48F, 0xE963A535, 0x9E6495A3,
        0x0EDB8832, 0x79DCB8A4, 0xE0D5E91E, 0x97D2D988,
        0x09B64C2B, 0x7EB17CBD, 0xE7B82D07, 0x90BF1D91,
        0x1DB71064, 0x6AB020F2, 0xF3B97148, 0x84BE41DE,
        0x1ADAD47D, 0x6DDDE4EB, 0xF4D4B551, 0x83D385C7,
        0x136C9856, 0x646BA8C0, 0xFD62F97A, 0x8A65C9EC,
        0x14015C4F, 0x63066CD9, 0xFA0F3D63, 0x8D080DF5,
        0x3B6E20C8, 0x4C69105E, 0xD56041E4, 0xA2677172,
        0x3C03E4D1, 0x4B04D447, 0xD20D85FD, 0xA50AB56B,
        0x35B5A8FA, 0x42B2986C, 0xDBBBC9D6, 0xACBCF940,
        0x32D86CE3, 0x45DF5C75, 0xDCD60DCF, 0xABD13D59,
        0x26D930AC, 0x51DE003A, 0xC8D75180, 0xBFD06116,
        0x21B4F4B5, 0x56B3C423, 0xCFBA9599, 0xB8BDA50F,
        0x2802B89E, 0x5F058808, 0xC60CD9B2, 0xB10BE924,
        0x2F6F7C87, 0x58684C11, 0xC1611DAB, 0xB6662D3D,
        0x76DC4190, 0x01DB7106, 0x98D220BC, 0xEFD5102A,
        0x71B18589, 0x06B6B51F, 0x9FBFE4A5, 0xE8B8D433,
        0x7807C9A2, 0x0F00F934, 0x9609A88E, 0xE10E9818,
        0x7F6A0DBB, 0x086D3D2D, 0x91646C97, 0xE6635C01,
        0x6B6B51F4, 0x1C6C6162, 0x856530D8, 0xF262004E,
        0x6C0695ED, 0x1B01A57B, 0x8208F4C1, 0xF50FC457,
        0x65B0D9C6, 0x12B7E950, 0x8BBEB8EA, 0xFCB9887C,
        0x62DD1DDF, 0x15DA2D49, 0x8CD37CF3, 0xFBD44C65,
        0x4DB26158, 0x3AB551CE, 0xA3BC0074, 0xD4BB30E2,
        0x4ADFA541, 0x3DD895D7, 0xA4D1C46D, 0xD3D6F4FB,
        0x4369E96A, 0x346ED9FC, 0xAD678846, 0xDA60B8D0,
        0x44042D73, 0x33031DE5, 0xAA0A4C5F, 0xDD0D7CC9,
        0x5005713C, 0x270241AA, 0xBE0B1010, 0xC90C2086,
        0x5768B525, 0x206F85B3, 0xB966D409, 0xCE61E49F,
        0x5EDEF90E, 0x29D9C998, 0xB0D09822, 0xC7D7A8B4,
        0x59B33D17, 0x2EB40D81, 0xB7BD5C3B, 0xC0BA6CAD,
        0xEDB88320, 0x9ABFB3B6, 0x03B6E20C, 0x74B1D29A,
        0xEAD54739, 0x9DD277AF, 0x04DB2615, 0x73DC1683,
        0xE3630B12, 0x94643B84, 0x0D6D6A3E, 0x7A6A5AA8,
        0xE40ECF0B, 0x9309FF9D, 0x0A00AE27, 0x7D079EB1,
        0xF00F9344, 0x8708A3D2, 0x1E01F268, 0x6906C2FE,
        0xF762575D, 0x806567CB, 0x196C3671, 0x6E6B06E7,
        0xFED41B76, 0x89D32BE0, 0x10DA7A5A, 0x67DD4ACC,
        0xF9B9DF6F, 0x8EBEEFF9, 0x17B7BE43, 0x60B08ED5,
        0xD6D6A3E8, 0xA1D1937E, 0x38D8C2C4, 0x4FDFF252,
        0xD1BB67F1, 0xA6BC5767, 0x3FB506DD, 0x48B2364B,
        0xD80D2BDA, 0xAF0A1B4C, 0x36034AF6, 0x41047A60,
        0xDF60EFC3, 0xA867DF55, 0x316E8EEF, 0x4669BE79,
        0xCB61B38C, 0xBC66831A, 0x256FD2A0, 0x5268E236,
        0xCC0C7795, 0xBB0B4703, 0x220216B9, 0x5505262F,
        0xC5BA3BBE, 0xB2BD0B28, 0x2BB45A92, 0x5CB36A04,
        0xC2D7FFA7, 0xB5D0CF31, 0x2CD99E8B, 0x5BDEAE1D,
        0x9B64C2B0, 0xEC63F226, 0x756AA39C, 0x026D930A,
        0x9C0906A9, 0xEB0E363F, 0x72076785, 0x05005713,
        0x95BF4A82, 0xE2B87A14, 0x7BB12BAE, 0x0CB61B38,
        0x92D28E9B, 0xE5D5BE0D, 0x7CDCEFB7, 0x0BDBDF21,
        0x86D3D2D4, 0xF1D4E242, 0x68DDB3F8, 0x1FDA836E,
        0x81BE16CD, 0xF6B9265B, 0x6FB077E1, 0x18B74777,
        0x88085AE6, 0xFF0F6A70, 0x66063BCA, 0x11010B5C,
        0x8F659EFF, 0xF862AE69, 0x616BFFD3, 0x166CCF45,
        0xA00AE278, 0xD70DD2EE, 0x4E048354, 0x3903B3C2,
        0xA7672661, 0xD06016F7, 0x4969474D, 0x3E6E77DB,
        0xAED16A4A, 0xD9D65ADC, 0x40DF0B66, 0x37D83BF0,
        0xA9BCAE53, 0xDEBB9EC5, 0x47B2CF7F, 0x30B5FFE9,
        0xBDBDF21C, 0xCABAC28A, 0x53B39330, 0x24B4A3A6,
        0xBAD03605, 0xCDD70693, 0x54DE5729, 0x23D967BF,
        0xB3667A2E, 0xC4614AB8, 0x5D681B02, 0x2A6F2B94,
        0xB40BBE37, 0xC30C8EA1, 0x5A05DF1B, 0x2D02EF8D };

// Global variable defines
MapViewerFrame *map_viewer_frm;

//(*IdInit(CrossTunerStudioFrame)
const long CrossTunerStudioFrame::ID_RADIOBUTTON1 = wxNewId();
const long CrossTunerStudioFrame::ID_TEXTCTRL4 = wxNewId();
const long CrossTunerStudioFrame::ID_BUTTON3 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT47 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT46 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT1 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT2 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT3 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT4 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT5 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT6 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT7 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT8 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT9 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT10 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT11 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT12 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT13 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT14 = wxNewId();
const long CrossTunerStudioFrame::ID_RADIOBUTTON2 = wxNewId();
const long CrossTunerStudioFrame::ID_TEXTCTRL3 = wxNewId();
const long CrossTunerStudioFrame::ID_BUTTON2 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT49 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT48 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT15 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT16 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT17 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT18 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT19 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT20 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT21 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT22 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT23 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT24 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT25 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT26 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT27 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT28 = wxNewId();
const long CrossTunerStudioFrame::ID_RADIOBUTTON3 = wxNewId();
const long CrossTunerStudioFrame::ID_TEXTCTRL2 = wxNewId();
const long CrossTunerStudioFrame::ID_BUTTON1 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT51 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT50 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT29 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT30 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT31 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT32 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT33 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT34 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT35 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT36 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT37 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT38 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT39 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT40 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT41 = wxNewId();
const long CrossTunerStudioFrame::ID_STATICTEXT42 = wxNewId();
const long CrossTunerStudioFrame::ID_PANEL1 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM1 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM4 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM7 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM2 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM3 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM5 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM6 = wxNewId();
const long CrossTunerStudioFrame::idMenuQuit = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM23 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM20 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM24 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM29 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM30 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM31 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM32 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM22 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM21 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM25 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM28 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM19 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM10 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM11 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM12 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM13 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM14 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM15 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM16 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM27 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM18 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM26 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM33 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM17 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM8 = wxNewId();
const long CrossTunerStudioFrame::ID_MENUITEM9 = wxNewId();
const long CrossTunerStudioFrame::idMenuAbout = wxNewId();
const long CrossTunerStudioFrame::ID_STATUSBAR1 = wxNewId();
const long CrossTunerStudioFrame::ID_TOOLBAR1 = wxNewId();
//*)

const long CrossTunerStudioFrame::ID_TOOLBARITEM1 = wxNewId();
const long CrossTunerStudioFrame::ID_TOOLBARITEM2 = wxNewId();
const long CrossTunerStudioFrame::ID_TOOLBARITEM3 = wxNewId();
const long CrossTunerStudioFrame::ID_TOOLBARITEM4 = wxNewId();
const long CrossTunerStudioFrame::ID_TOOLBARITEM5 = wxNewId();
const long CrossTunerStudioFrame::ID_TOOLBARITEM6 = wxNewId();
const long CrossTunerStudioFrame::ID_TOOLBARITEM7 = wxNewId();
const long CrossTunerStudioFrame::ID_TOOLBARITEM8 = wxNewId();
const long CrossTunerStudioFrame::ID_TOOLBARITEM9 = wxNewId();
const long CrossTunerStudioFrame::ID_TOOLBARITEM10 = wxNewId();

BEGIN_EVENT_TABLE(CrossTunerStudioFrame,wxFrame)
    //(*EventTable(CrossTunerStudioFrame)
    //*)
END_EVENT_TABLE()

CrossTunerStudioFrame::CrossTunerStudioFrame(wxWindow* parent,wxWindowID id)
{
    // Select language
    wxLocale *m_locale;
    m_locale=new wxLocale (wxLANGUAGE_DEFAULT);
    m_locale->AddCatalogLookupPathPrefix(wxStandardPaths::Get().GetExecutablePath());
    m_locale->AddCatalog(_T("language"));

    // Restore "C" numeric locale
    setlocale(LC_NUMERIC, "C");
/*
    int sys_lang = wxLocale::GetSystemLanguage();
    if( sys_lang != wxLANGUAGE_DEFAULT )
    {
   m_locale.Init(sys_lang);         // set custom locale
   m_locale.AddCatalogLookupPathPrefix("locale");   // set "locale" prefix
   m_locale.AddCatalog("wxproton");            // our private domain
   m_locale.AddCatalog("wxstd");            // wx common domain is default
        // Restore "C" numeric locale
        setlocale(LC_NUMERIC, "C");
    }
*/
    //(*Initialize(CrossTunerStudioFrame)
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer10;
    wxBoxSizer* BoxSizer8;
    wxMenuItem* MenuItem_About;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer11;
    wxMenuItem* MenuItemQuit;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer9;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu_File;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu_Help;
    wxMenuBar* MenuBar;

    Create(parent, wxID_ANY, _("CrossTuner Studio"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer10 = new wxBoxSizer(wxVERTICAL);
    RadioButton_SelectBIN1 = new wxRadioButton(Panel1, ID_RADIOBUTTON1, _("Select BIN #1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    RadioButton_SelectBIN1->SetValue(true);
    RadioButton_SelectBIN1->SetToolTip(_("Select BIN #1 as the default for edit operations"));
    BoxSizer10->Add(RadioButton_SelectBIN1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
    TextCtrlBIN1 = new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(179,27), wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    BoxSizer11->Add(TextCtrlBIN1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonBrowseBIN1 = new wxButton(Panel1, ID_BUTTON3, _("..."), wxDefaultPosition, wxSize(30,29), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    ButtonBrowseBIN1->SetToolTip(_("Load BIN #1 from your hard drive"));
    BoxSizer11->Add(ButtonBrowseBIN1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer10->Add(BoxSizer11, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1 = new wxFlexGridSizer(8, 3, 0, 0);
    FlexGridSizer1->AddGrowableCol(2);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT47, _("Size"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT47"));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_Size1 = new wxStaticText(Panel1, ID_STATICTEXT46, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT46"));
    FlexGridSizer1->Add(StaticText_Size1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("ECU"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_ECU1 = new wxStaticText(Panel1, ID_STATICTEXT2, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText_ECU1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("HW"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_HW1 = new wxStaticText(Panel1, ID_STATICTEXT4, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer1->Add(StaticText_HW1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("SW"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_SW1 = new wxStaticText(Panel1, ID_STATICTEXT6, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer1->Add(StaticText_SW1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("Chk. Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    FlexGridSizer1->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_CHKType1 = new wxStaticText(Panel1, ID_STATICTEXT8, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    FlexGridSizer1->Add(StaticText_CHKType1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT9, _("Chk. 8"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    FlexGridSizer1->Add(StaticText9, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_CHK8_1 = new wxStaticText(Panel1, ID_STATICTEXT10, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    FlexGridSizer1->Add(StaticText_CHK8_1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText11 = new wxStaticText(Panel1, ID_STATICTEXT11, _("Chk. 16"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    FlexGridSizer1->Add(StaticText11, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_CHK16_1 = new wxStaticText(Panel1, ID_STATICTEXT12, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    FlexGridSizer1->Add(StaticText_CHK16_1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText13 = new wxStaticText(Panel1, ID_STATICTEXT13, _("Chk. 32"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    FlexGridSizer1->Add(StaticText13, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_CHK32_1 = new wxStaticText(Panel1, ID_STATICTEXT14, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    FlexGridSizer1->Add(StaticText_CHK32_1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer10->Add(FlexGridSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer10, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer6 = new wxBoxSizer(wxVERTICAL);
    RadioButton_SelectBIN2 = new wxRadioButton(Panel1, ID_RADIOBUTTON2, _("Select BIN #2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    RadioButton_SelectBIN2->SetToolTip(_("Select BIN #2 as the default for edit operations"));
    BoxSizer6->Add(RadioButton_SelectBIN2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    TextCtrlBIN2 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    BoxSizer9->Add(TextCtrlBIN2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonBrowseBIN2 = new wxButton(Panel1, ID_BUTTON2, _("..."), wxDefaultPosition, wxSize(30,29), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    ButtonBrowseBIN2->SetToolTip(_("Load BIN #2 from your hard drive"));
    BoxSizer9->Add(ButtonBrowseBIN2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6->Add(BoxSizer9, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(8, 3, 0, 0);
    FlexGridSizer2->AddGrowableCol(2);
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT49, _("Size"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT49"));
    FlexGridSizer2->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_Size2 = new wxStaticText(Panel1, ID_STATICTEXT48, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT48"));
    FlexGridSizer2->Add(StaticText_Size2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText15 = new wxStaticText(Panel1, ID_STATICTEXT15, _("ECU"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    FlexGridSizer2->Add(StaticText15, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_ECU2 = new wxStaticText(Panel1, ID_STATICTEXT16, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    FlexGridSizer2->Add(StaticText_ECU2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText17 = new wxStaticText(Panel1, ID_STATICTEXT17, _("HW"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    FlexGridSizer2->Add(StaticText17, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_HW2 = new wxStaticText(Panel1, ID_STATICTEXT18, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    FlexGridSizer2->Add(StaticText_HW2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText19 = new wxStaticText(Panel1, ID_STATICTEXT19, _("SW"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    FlexGridSizer2->Add(StaticText19, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_SW2 = new wxStaticText(Panel1, ID_STATICTEXT20, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    FlexGridSizer2->Add(StaticText_SW2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText21 = new wxStaticText(Panel1, ID_STATICTEXT21, _("Chk. Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    FlexGridSizer2->Add(StaticText21, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_CHKType2 = new wxStaticText(Panel1, ID_STATICTEXT22, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    FlexGridSizer2->Add(StaticText_CHKType2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText23 = new wxStaticText(Panel1, ID_STATICTEXT23, _("Chk. 8"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    FlexGridSizer2->Add(StaticText23, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_CHK8_2 = new wxStaticText(Panel1, ID_STATICTEXT24, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    FlexGridSizer2->Add(StaticText_CHK8_2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText25 = new wxStaticText(Panel1, ID_STATICTEXT25, _("Chk. 16"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    FlexGridSizer2->Add(StaticText25, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_CHK16_2 = new wxStaticText(Panel1, ID_STATICTEXT26, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT26"));
    FlexGridSizer2->Add(StaticText_CHK16_2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText27 = new wxStaticText(Panel1, ID_STATICTEXT27, _("Chk. 32"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT27"));
    FlexGridSizer2->Add(StaticText27, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_CHK32_2 = new wxStaticText(Panel1, ID_STATICTEXT28, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT28"));
    FlexGridSizer2->Add(StaticText_CHK32_2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer6, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    RadioButton_SelectBIN3 = new wxRadioButton(Panel1, ID_RADIOBUTTON3, _("Select BIN #3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
    RadioButton_SelectBIN3->SetToolTip(_("Select BIN #3 as the default for edit operations"));
    BoxSizer5->Add(RadioButton_SelectBIN3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    TextCtrlBIN3 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer8->Add(TextCtrlBIN3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonBrowseBIN3 = new wxButton(Panel1, ID_BUTTON1, _("..."), wxDefaultPosition, wxSize(30,29), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    ButtonBrowseBIN3->SetToolTip(_("Load BIN #3 from your hard drive"));
    BoxSizer8->Add(ButtonBrowseBIN3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(BoxSizer8, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(8, 3, 0, 0);
    FlexGridSizer3->AddGrowableCol(2);
    StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT51, _("Size"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT51"));
    FlexGridSizer3->Add(StaticText10, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_Size3 = new wxStaticText(Panel1, ID_STATICTEXT50, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT50"));
    FlexGridSizer3->Add(StaticText_Size3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText29 = new wxStaticText(Panel1, ID_STATICTEXT29, _("ECU"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT29"));
    FlexGridSizer3->Add(StaticText29, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_ECU3 = new wxStaticText(Panel1, ID_STATICTEXT30, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
    FlexGridSizer3->Add(StaticText_ECU3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText31 = new wxStaticText(Panel1, ID_STATICTEXT31, _("HW"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT31"));
    FlexGridSizer3->Add(StaticText31, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_HW3 = new wxStaticText(Panel1, ID_STATICTEXT32, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT32"));
    FlexGridSizer3->Add(StaticText_HW3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText33 = new wxStaticText(Panel1, ID_STATICTEXT33, _("SW"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT33"));
    FlexGridSizer3->Add(StaticText33, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_SW3 = new wxStaticText(Panel1, ID_STATICTEXT34, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT34"));
    FlexGridSizer3->Add(StaticText_SW3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText35 = new wxStaticText(Panel1, ID_STATICTEXT35, _("Chk. Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT35"));
    FlexGridSizer3->Add(StaticText35, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_CHKType3 = new wxStaticText(Panel1, ID_STATICTEXT36, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT36"));
    FlexGridSizer3->Add(StaticText_CHKType3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText37 = new wxStaticText(Panel1, ID_STATICTEXT37, _("Chk. 8"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT37"));
    FlexGridSizer3->Add(StaticText37, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_CHK8_3 = new wxStaticText(Panel1, ID_STATICTEXT38, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT38"));
    FlexGridSizer3->Add(StaticText_CHK8_3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText39 = new wxStaticText(Panel1, ID_STATICTEXT39, _("Chk. 16"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT39"));
    FlexGridSizer3->Add(StaticText39, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_CHK16_3 = new wxStaticText(Panel1, ID_STATICTEXT40, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT40"));
    FlexGridSizer3->Add(StaticText_CHK16_3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText41 = new wxStaticText(Panel1, ID_STATICTEXT41, _("Chk. 32"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT41"));
    FlexGridSizer3->Add(StaticText41, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_CHK32_3 = new wxStaticText(Panel1, ID_STATICTEXT42, _("---"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT42"));
    FlexGridSizer3->Add(StaticText_CHK32_3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5->Add(FlexGridSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Panel1->SetSizer(BoxSizer3);
    BoxSizer3->Fit(Panel1);
    BoxSizer3->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    MenuBar = new wxMenuBar();
    Menu_File = new wxMenu();
    MenuItem_LoadBIN = new wxMenuItem(Menu_File, ID_MENUITEM1, _("Load BIN\tAlt-1"), _("Load BIN file from your hard drive"), wxITEM_NORMAL);
    Menu_File->Append(MenuItem_LoadBIN);
    MenuItem_SaveBIN = new wxMenuItem(Menu_File, ID_MENUITEM4, _("Save BIN\tAlt-4"), _("Save BIN file to your hard drive"), wxITEM_NORMAL);
    Menu_File->Append(MenuItem_SaveBIN);
    MenuItem_SaveBINas = new wxMenuItem(Menu_File, ID_MENUITEM7, _("Save BIN as ...\tAlt-7"), _("Save BIN file to your hard drive with a different name"), wxITEM_NORMAL);
    Menu_File->Append(MenuItem_SaveBINas);
    Menu_File->AppendSeparator();
    MenuItem4 = new wxMenuItem(Menu_File, ID_MENUITEM2, _("Append to BIN"), _("Function not available!"), wxITEM_NORMAL);
    Menu_File->Append(MenuItem4);
    MenuItem5 = new wxMenuItem(Menu_File, ID_MENUITEM3, _("Overload to BIN"), _("Function not available!"), wxITEM_NORMAL);
    Menu_File->Append(MenuItem5);
    Menu_File->AppendSeparator();
    MenuItem6 = new wxMenuItem(Menu_File, ID_MENUITEM5, _("Split BIN"), _("Function not available!"), wxITEM_NORMAL);
    Menu_File->Append(MenuItem6);
    MenuItem7 = new wxMenuItem(Menu_File, ID_MENUITEM6, _("Save Partial BIN"), _("Function not available!"), wxITEM_NORMAL);
    Menu_File->Append(MenuItem7);
    Menu_File->AppendSeparator();
    MenuItemQuit = new wxMenuItem(Menu_File, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu_File->Append(MenuItemQuit);
    MenuBar->Append(Menu_File, _("&File"));
    Menu_Maps = new wxMenu();
    MenuItem_NewMaps = new wxMenuItem(Menu_Maps, ID_MENUITEM23, _("New Map Definitions \tAlt-N"), _("Clear definitions from memory"), wxITEM_NORMAL);
    Menu_Maps->Append(MenuItem_NewMaps);
    MenuItem_LoadMaps = new wxMenuItem(Menu_Maps, ID_MENUITEM20, _("Load Map Definitions\tAlt-L"), _("Load definition file from hard drive"), wxITEM_NORMAL);
    Menu_Maps->Append(MenuItem_LoadMaps);
    MenuItem_SaveMaps = new wxMenuItem(Menu_Maps, ID_MENUITEM24, _("Save Map Definitions\tAlt-W"), _("Save definition file to hard drive"), wxITEM_NORMAL);
    Menu_Maps->Append(MenuItem_SaveMaps);
    Menu_Maps->AppendSeparator();
    MenuItem_AddNewMap = new wxMenuItem(Menu_Maps, ID_MENUITEM29, _("Add New Map\tAlt-A"), _("Create a new map"), wxITEM_NORMAL);
    Menu_Maps->Append(MenuItem_AddNewMap);
    MenuItem_EditSelectedMap = new wxMenuItem(Menu_Maps, ID_MENUITEM30, _("Edit Selected Map\tAlt-I"), _("Edit the currently selected map"), wxITEM_NORMAL);
    Menu_Maps->Append(MenuItem_EditSelectedMap);
    MenuItem_DeleteSelectedMap = new wxMenuItem(Menu_Maps, ID_MENUITEM31, _("Delete Selected Map\tAlt-D"), _("Delete the currently selected map"), wxITEM_NORMAL);
    Menu_Maps->Append(MenuItem_DeleteSelectedMap);
    MenuItem_DuplicateSelectedMap = new wxMenuItem(Menu_Maps, ID_MENUITEM32, _("Duplicate Selected Map\tAlt-U"), _("Duplicate the currently selected map"), wxITEM_NORMAL);
    Menu_Maps->Append(MenuItem_DuplicateSelectedMap);
    Menu_Maps->AppendSeparator();
    MenuItem_Import = new wxMenu();
    MenuItem_ImportTunerPro = new wxMenuItem(MenuItem_Import, ID_MENUITEM22, _("TunerPro (XDF v1.50)"), _("Import TunerPro XDF definition files"), wxITEM_NORMAL);
    MenuItem_Import->Append(MenuItem_ImportTunerPro);
    Menu_Maps->Append(ID_MENUITEM21, _("Import"), MenuItem_Import, _("Import definitions from other formats"));
    MenuItem3 = new wxMenu();
    MenuItem_ExportMapList = new wxMenuItem(MenuItem3, ID_MENUITEM25, _("Map List"), _("Function not available!"), wxITEM_NORMAL);
    MenuItem3->Append(MenuItem_ExportMapList);
    MenuItem_Export_MapData = new wxMenuItem(MenuItem3, ID_MENUITEM28, _("Map Data"), _("Function not available!"), wxITEM_NORMAL);
    MenuItem3->Append(MenuItem_Export_MapData);
    Menu_Maps->Append(ID_MENUITEM19, _("Export"), MenuItem3, wxEmptyString);
    MenuBar->Append(Menu_Maps, _("&Maps"));
    Menu1 = new wxMenu();
    MenuItem_Buffers = new wxMenu();
    MenuItem_CopyBIN1toBIN2 = new wxMenuItem(MenuItem_Buffers, ID_MENUITEM10, _("Copy BIN #1 to BIN #2"), _("Copy BIN #1 to BIN #2"), wxITEM_NORMAL);
    MenuItem_Buffers->Append(MenuItem_CopyBIN1toBIN2);
    MenuItem_CopyBIN1toBIN3 = new wxMenuItem(MenuItem_Buffers, ID_MENUITEM11, _("Copy BIN #1 to BIN #3"), _("Copy BIN #1 to BIN #3"), wxITEM_NORMAL);
    MenuItem_Buffers->Append(MenuItem_CopyBIN1toBIN3);
    MenuItem_CopyBIN2toBIN1 = new wxMenuItem(MenuItem_Buffers, ID_MENUITEM12, _("Copy BIN #2 to BIN #1"), _("Copy BIN #2 to BIN #1"), wxITEM_NORMAL);
    MenuItem_Buffers->Append(MenuItem_CopyBIN2toBIN1);
    MenuItem_CopyBIN2toBIN3 = new wxMenuItem(MenuItem_Buffers, ID_MENUITEM13, _("Copy BIN #2 to BIN #3"), _("Copy BIN #2 to BIN #3"), wxITEM_NORMAL);
    MenuItem_Buffers->Append(MenuItem_CopyBIN2toBIN3);
    MenuItem_CopyBIN3toBIN1 = new wxMenuItem(MenuItem_Buffers, ID_MENUITEM14, _("Copy BIN #3 to BIN #1"), _("Copy BIN #3 to BIN #1"), wxITEM_NORMAL);
    MenuItem_Buffers->Append(MenuItem_CopyBIN3toBIN1);
    MenuItem_CopyBIN3toBIN2 = new wxMenuItem(MenuItem_Buffers, ID_MENUITEM15, _("Copy BIN #3 to BIN #2"), _("Copy BIN #3 to BIN #2"), wxITEM_NORMAL);
    MenuItem_Buffers->Append(MenuItem_CopyBIN3toBIN2);
    Menu1->Append(ID_MENUITEM16, _("Copy Buffers"), MenuItem_Buffers, _("Functions to copy BIN buffers between one another"));
    MenuBar->Append(Menu1, _("&Modify"));
    Menu4 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu4, ID_MENUITEM27, _("Preferences\tAlt-P"), _("Function not available!"), wxITEM_NORMAL);
    Menu4->Append(MenuItem1);
    MenuBar->Append(Menu4, _("&Options"));
    Menu3 = new wxMenu();
    MenuItem_MapViewer = new wxMenuItem(Menu3, ID_MENUITEM18, _("Definitions Viewer\tAlt-V"), _("Open map definitions window"), wxITEM_NORMAL);
    Menu3->Append(MenuItem_MapViewer);
    MenuItem_TableEditor = new wxMenuItem(Menu3, ID_MENUITEM26, _("Table Map Editor\tAlt-T"), _("Open map data in table form"), wxITEM_NORMAL);
    Menu3->Append(MenuItem_TableEditor);
    MenuItem_2DEditor = new wxMenuItem(Menu3, ID_MENUITEM33, _("2D Map Editor\tAlt-O"), _("Function not available!"), wxITEM_NORMAL);
    Menu3->Append(MenuItem_2DEditor);
    MenuBar->Append(Menu3, _("&Windows"));
    Menu7 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu7, ID_MENUITEM17, _("Tool Editor\tAlt-T"), _("Function not available!"), wxITEM_NORMAL);
    Menu7->Append(MenuItem2);
    Menu7->AppendSeparator();
    MenuBar->Append(Menu7, _("&Tools"));
    Menu5 = new wxMenu();
    Menu2 = new wxMenuItem(Menu5, ID_MENUITEM8, _("Checksum"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(Menu2);
    Menu6 = new wxMenuItem(Menu5, ID_MENUITEM9, _("Flashing"), wxEmptyString, wxITEM_NORMAL);
    Menu5->Append(Menu6);
    MenuBar->Append(Menu5, _("&Plugins"));
    Menu_Help = new wxMenu();
    MenuItem_About = new wxMenuItem(Menu_Help, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu_Help->Append(MenuItem_About);
    MenuBar->Append(Menu_Help, _("&Help"));
    SetMenuBar(MenuBar);
    StatusBar = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[2] = { 400, -10 };
    int __wxStatusBarStyles_1[2] = { wxSB_NORMAL, wxSB_NORMAL };
    StatusBar->SetFieldsCount(2,__wxStatusBarWidths_1);
    StatusBar->SetStatusStyles(2,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnRadioButton_SelectBIN1Select);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnButtonBrowseBIN1Click);
    Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnRadioButton_SelectBIN2Select);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnButtonBrowseBIN2Click);
    Connect(ID_RADIOBUTTON3,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnRadioButton_SelectBIN3Select);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnButtonBrowseBIN3Click);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_LoadBINSelected);
    Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_SaveBINSelected);
    Connect(ID_MENUITEM7,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_SaveBINasSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnQuit);
    Connect(ID_MENUITEM23,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_NewDefinitionSelected);
    Connect(ID_MENUITEM20,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_LoadDefinitionSelected);
    Connect(ID_MENUITEM24,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_SaveDefinitionSelected);
    Connect(ID_MENUITEM29,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_AddNewMapSelected);
    Connect(ID_MENUITEM30,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_EditSelectedMapSelected);
    Connect(ID_MENUITEM31,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_DeleteSelectedMapSelected);
    Connect(ID_MENUITEM32,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_DuplicateSelectedMapSelected);
    Connect(ID_MENUITEM22,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_ImportTunerProSelected);
    Connect(ID_MENUITEM10,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_CopyBIN1toBIN2Selected);
    Connect(ID_MENUITEM11,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_CopyBIN1toBIN3Selected);
    Connect(ID_MENUITEM12,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_CopyBIN2toBIN1Selected);
    Connect(ID_MENUITEM13,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_CopyBIN2toBIN3Selected);
    Connect(ID_MENUITEM14,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_CopyBIN3toBIN1Selected);
    Connect(ID_MENUITEM15,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_CopyBIN3toBIN2Selected);
    Connect(ID_MENUITEM18,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_MapViewerSelected);
    Connect(ID_MENUITEM26,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_TableEditorSelected);
    Connect(ID_MENUITEM33,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnMenuItem_2DEditorSelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnAbout);
    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&CrossTunerStudioFrame::OnClose);
    //*)

    wxMemoryInputStream appicon_stream(appicon_png, sizeof appicon_png);
    wxImage appicon = wxImage(appicon_stream, wxBITMAP_TYPE_PNG);

    wxIcon FrameIcon;
    FrameIcon.CopyFromBitmap(wxBitmap(appicon));
    SetIcon(FrameIcon);

    wxMemoryInputStream openbin_icon_stream(toolbar_openbin_png, sizeof toolbar_openbin_png);
    wxImage icon_openbin = wxImage(openbin_icon_stream, wxBITMAP_TYPE_PNG);

    wxMemoryInputStream savebin_icon_stream(toolbar_savebin_png, sizeof toolbar_savebin_png);
    wxImage icon_savebin = wxImage(savebin_icon_stream, wxBITMAP_TYPE_PNG);

    wxMemoryInputStream openmap_icon_stream(toolbar_openmap_png, sizeof toolbar_openmap_png);
    wxImage icon_openmap = wxImage(openmap_icon_stream, wxBITMAP_TYPE_PNG);

    wxMemoryInputStream mapview_icon_stream(toolbar_mapview_png, sizeof toolbar_mapview_png);
    wxImage icon_mapview = wxImage(mapview_icon_stream, wxBITMAP_TYPE_PNG);

    wxMemoryInputStream mapedit_icon_stream(toolbar_mapedit_png, sizeof toolbar_mapedit_png);
    wxImage icon_mapedit = wxImage(mapedit_icon_stream, wxBITMAP_TYPE_PNG);

    wxMemoryInputStream tableedit_icon_stream(toolbar_tableedit_png, sizeof toolbar_tableedit_png);
    wxImage icon_tableedit = wxImage(tableedit_icon_stream, wxBITMAP_TYPE_PNG);

    wxMemoryInputStream g2d_icon_stream(toolbar_2d_png, sizeof toolbar_2d_png);
    wxImage icon_2d = wxImage(g2d_icon_stream, wxBITMAP_TYPE_PNG);

    wxMemoryInputStream preferences_icon_stream(toolbar_preferences_png, sizeof toolbar_preferences_png);
    wxImage icon_preferences = wxImage(preferences_icon_stream, wxBITMAP_TYPE_PNG);

    wxMemoryInputStream about_icon_stream(toolbar_about_png, sizeof toolbar_about_png);
    wxImage icon_about = wxImage(about_icon_stream, wxBITMAP_TYPE_PNG);

    wxMemoryInputStream quit_icon_stream(toolbar_quit_png, sizeof toolbar_quit_png);
    wxImage icon_quit = wxImage(quit_icon_stream, wxBITMAP_TYPE_PNG);

    //wxBitmap hdr_icon(icon_xpm);

    ToolBar = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxNO_BORDER, _T("ID_TOOLBAR1"));
    ToolBarItem1 = ToolBar->AddTool(ID_TOOLBARITEM1, _("Load BIN"), wxBitmap(icon_openbin), wxNullBitmap, wxITEM_NORMAL, _("Load BIN"), _("Load BIN"));
    ToolBarItem2 = ToolBar->AddTool(ID_TOOLBARITEM2, _("Save BIN"), wxBitmap(icon_savebin), wxNullBitmap, wxITEM_NORMAL, _("Save BIN"), _("Save BIN"));
    ToolBar->AddSeparator();
    ToolBarItem3 = ToolBar->AddTool(ID_TOOLBARITEM3, _("Load Map"), wxBitmap(icon_openmap), wxNullBitmap, wxITEM_NORMAL, _("Load Map Definitions"), _("Load Map Definitions"));
    ToolBarItem4 = ToolBar->AddTool(ID_TOOLBARITEM4, _("Map Viewer"), wxBitmap(icon_mapview), wxNullBitmap, wxITEM_NORMAL, _("Definitions Map Viewer"), _("Definitions Map Viewer"));
    ToolBarItem5 = ToolBar->AddTool(ID_TOOLBARITEM5, _("Map Editor"), wxBitmap(icon_mapedit), wxNullBitmap, wxITEM_NORMAL, _("Definitions Map Editor"), _("Definitions Map Editor"));
    ToolBar->AddSeparator();
    ToolBarItem6 = ToolBar->AddTool(ID_TOOLBARITEM6, _("Table Editor"), wxBitmap(icon_tableedit), wxNullBitmap, wxITEM_NORMAL, _("Table Editor"), _("Table Editor"));
    ToolBarItem7 = ToolBar->AddTool(ID_TOOLBARITEM7, _("2D Editor"), wxBitmap(icon_2d), wxNullBitmap, wxITEM_NORMAL, _("2D Editor"), _("2D Editor"));
    ToolBar->AddSeparator();
    ToolBarItem8 = ToolBar->AddTool(ID_TOOLBARITEM8, _("Preferences"), wxBitmap(icon_preferences), wxNullBitmap, wxITEM_NORMAL, _("Preferences"), _("Preferences"));
    ToolBar->AddSeparator();
    ToolBarItem9 = ToolBar->AddTool(ID_TOOLBARITEM9, _("About"), wxBitmap(icon_about), wxNullBitmap, wxITEM_NORMAL, _("About"), _("About"));
    ToolBarItem10 = ToolBar->AddTool(ID_TOOLBARITEM10, _("Quit"), wxBitmap(icon_quit), wxNullBitmap, wxITEM_NORMAL, _("Quit"), _("Quit"));
    ToolBar->Realize();
    SetToolBar(ToolBar);

    BoxSizer1->Fit(this);

    Connect(ID_TOOLBARITEM1,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnToolBarItem_LoadBINClicked);
    Connect(ID_TOOLBARITEM2,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnToolBarItem_SaveBINClicked);
    Connect(ID_TOOLBARITEM3,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnToolBarItem_LoadMapClicked);
    Connect(ID_TOOLBARITEM4,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnToolBarItem_MapViewerClicked);
    Connect(ID_TOOLBARITEM5,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnToolBarItem_MapEditorClicked);
    Connect(ID_TOOLBARITEM6,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnToolBarItem_TableEditorClicked);
    Connect(ID_TOOLBARITEM7,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnToolBarItem_2DEditorClicked);
    //Connect(ID_TOOLBARITEM8,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnToolBarItem_PreferencesClicked);
    Connect(ID_TOOLBARITEM9,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnToolBarItem_AboutClicked);
    Connect(ID_TOOLBARITEM10,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&CrossTunerStudioFrame::OnToolBarItem_QuitClicked);

    global = new GlobalVariables;

    //global->bin_buffer[0]=(unsigned char*)malloc(MAX_BUFFER_LENGTH);
    //global->bin_buffer[1]=(unsigned char*)malloc(MAX_BUFFER_LENGTH);
    //global->bin_buffer[2]=(unsigned char*)malloc(MAX_BUFFER_LENGTH);

    global->bin_length[0]=0;
    global->bin_length[1]=0;
    global->bin_length[2]=0;

    global->xmltable_count=0;
    global->selected_bin=0;

    LoadDefaults();
}

CrossTunerStudioFrame::~CrossTunerStudioFrame()
{
    //(*Destroy(CrossTunerStudioFrame)
    //*)
}

void CrossTunerStudioFrame::OnClose(wxCloseEvent& event)
{
    int x,y,w,h;

    wxConfig config(_T("CrossTunerStudio"),_T("MTX Electronics"));

    this->GetPosition(&x, &y);
    config.Write(_T("/WindowPositions/CrossTunerStudioFrameX"), x);
    config.Write(_T("/WindowPositions/CrossTunerStudioFrameY"), y);

    if (map_viewer_frm != NULL)
    {
        map_viewer_frm->GetPosition(&x, &y);
        config.Write(_T("/WindowPositions/MapViewerFrameX"), x);
        config.Write(_T("/WindowPositions/MapViewerFrameY"), y);

        map_viewer_frm->GetSize(&w, &h);
        config.Write(_T("/WindowPositions/MapViewerFrameW"), w);
        config.Write(_T("/WindowPositions/MapViewerFrameH"), h);
    }

    Destroy();
}

/// ---------------------------------------------------------------------------
/// Menu Functions
/// ---------------------------------------------------------------------------

void CrossTunerStudioFrame::OnMenuItem_LoadBINSelected(wxCommandEvent& event)
{
    wxString filename, path;

    unsigned short selected_bin=SelectedBin();
    unsigned int length=ReadBINfromHD(selected_bin,&filename,&path, true);

    if (length > 0)
    {
        global->bin_length[selected_bin]=length;
        global->bin_filename[selected_bin]=filename;
        global->bin_path[selected_bin]=path;

        if (selected_bin==0)
        {
            TextCtrlBIN1->SetValue(filename);
            StaticText_Size1->SetLabel(wxString::Format(wxT("%i"),length));
            StaticText_CHK8_1->SetLabel(_("0x") + Int2HEX(CRC8(global->bin_buffer[0],length)));
            StaticText_CHK16_1->SetLabel(_("0x") + Int2HEX(CRC16(global->bin_buffer[0],length)));
            StaticText_CHK32_1->SetLabel(_("0x") + Int2HEX(CRC32(global->bin_buffer[0],length)));

            wxConfig config(_T("CrossTunerStudio"),_T("MTX Electronics"));
            config.Write(_T("/OpenFiles/Bin1Path"), path);
            config.Write(_T("/OpenFiles/Bin1Filename"), filename);
        }
        else if (selected_bin==1)
        {
            TextCtrlBIN2->SetValue(filename);
            StaticText_Size2->SetLabel(wxString::Format(wxT("%i"),length));
            StaticText_CHK8_2->SetLabel(_("0x") + Int2HEX(CRC8(global->bin_buffer[1],length)));
            StaticText_CHK16_2->SetLabel(_("0x") + Int2HEX(CRC16(global->bin_buffer[1],length)));
            StaticText_CHK32_2->SetLabel(_("0x") + Int2HEX(CRC32(global->bin_buffer[1],length)));

            wxConfig config(_T("CrossTunerStudio"),_T("MTX Electronics"));
            config.Write(_T("/OpenFiles/Bin2Path"), path);
            config.Write(_T("/OpenFiles/Bin2Filename"), filename);
        }
        else
        {
            TextCtrlBIN3->SetValue(filename);
            StaticText_Size3->SetLabel(wxString::Format(wxT("%i"),length));
            StaticText_CHK8_3->SetLabel(_("0x") + Int2HEX(CRC8(global->bin_buffer[2],length)));
            StaticText_CHK16_3->SetLabel(_("0x") + Int2HEX(CRC16(global->bin_buffer[2],length)));
            StaticText_CHK32_3->SetLabel(_("0x") + Int2HEX(CRC32(global->bin_buffer[2],length)));

            wxConfig config(_T("CrossTunerStudio"),_T("MTX Electronics"));
            config.Write(_T("/OpenFiles/Bin3Path"), path);
            config.Write(_T("/OpenFiles/Bin3Filename"), filename);
        }
    }
}

void CrossTunerStudioFrame::OnMenuItem_SaveBINSelected(wxCommandEvent& event)
{
    unsigned short selected_bin=SelectedBin();

    WriteBINtoHD(global->bin_buffer[selected_bin], global->bin_length[selected_bin], global->bin_path[selected_bin]);
}

void CrossTunerStudioFrame::OnMenuItem_SaveBINasSelected(wxCommandEvent& event)
{
    unsigned short selected_bin=SelectedBin();

    WriteBINtoHDas(global->bin_buffer[selected_bin], global->bin_length[selected_bin]);
}

void CrossTunerStudioFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void CrossTunerStudioFrame::OnMenuItem_NewDefinitionSelected(wxCommandEvent& event)
{
    global->xmltable_count=0;

    // Clear Map Viewer Tree
    if (map_viewer_frm != NULL)
        map_viewer_frm->ClearTree();
}

void CrossTunerStudioFrame::OnMenuItem_LoadDefinitionSelected(wxCommandEvent& event)
{
    // Open file dialog window
    wxFileDialog *FileDialog = new wxFileDialog(this, _("Select maps file to load"), wxEmptyString, wxEmptyString, wxT("XTS files (*.xts)|*.xts|All files (*.*)|*.*"), wxFD_DEFAULT_STYLE|wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

    if (FileDialog->ShowModal() == wxID_CANCEL)
    {
        delete FileDialog;
        return;
    }

    if (LoadDefinitionFileFromHD(FileDialog->GetPath()))
    {
        wxConfig config(_T("CrossTunerStudio"),_T("MTX Electronics"));
        config.Write(_T("/OpenFiles/MapsPath"), FileDialog->GetPath());

        StatusBar->SetStatusText(_("Maps file loaded."),1);
    }
}

void CrossTunerStudioFrame::OnMenuItem_SaveDefinitionSelected(wxCommandEvent& event)
{
    // Open file dialog window
    wxFileDialog *FileDialog = new wxFileDialog(this, _("Select maps file to save"), wxEmptyString, wxEmptyString, wxT("XTS files (*.xts)|*.xts|All files (*.*)|*.*"), wxFD_DEFAULT_STYLE|wxFD_SAVE|wxOVERWRITE_PROMPT, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

    if (FileDialog->ShowModal() == wxID_CANCEL)
    {
        delete FileDialog;
        return;
    }

    char txt[256];
    wxString str;

    TiXmlDocument doc;
    TiXmlElement* msg;
    TiXmlDeclaration* decl = new TiXmlDeclaration("1.0","","");
	doc.LinkEndChild(decl);

    TiXmlElement* root = new TiXmlElement("XTS");
	doc.LinkEndChild(root);
	root->SetAttribute("version","1.0");

	// ------------------------------------------------------------------------
	TiXmlElement* header = new TiXmlElement("HEADER");
	root->LinkEndChild(header);

	msg = new TiXmlElement("flags");
	str=_T("0x") + Int2HEX(global->xmlheader.flags);
	msg->LinkEndChild(new TiXmlText((const char*)str.mb_str()));
	header->LinkEndChild(msg);

	msg = new TiXmlElement("fileversion");
	msg->LinkEndChild(new TiXmlText((const char*)global->xmlheader.fileversion.mb_str()));
	header->LinkEndChild(msg);

	msg = new TiXmlElement("title");
	msg->LinkEndChild(new TiXmlText((const char*)global->xmlheader.title.mb_str()));
	header->LinkEndChild(msg);

	msg = new TiXmlElement("description");
	msg->LinkEndChild(new TiXmlText((const char*)global->xmlheader.description.mb_str()));
	header->LinkEndChild(msg);

	msg = new TiXmlElement("author");
	msg->LinkEndChild(new TiXmlText((const char*)global->xmlheader.author.mb_str()));
	header->LinkEndChild(msg);

	msg = new TiXmlElement("baseoffset");
	str=_T("0x") + Int2HEX(global->xmlheader.baseoffset);
	msg->LinkEndChild(new TiXmlText((const char*)str.mb_str()));
	header->LinkEndChild(msg);

	// ------------------------------------------------------------------------
	for (int table_num=0; table_num < global->xmltable_count; table_num++)
    {
        TiXmlElement* table = new TiXmlElement("TABLE");
        root->LinkEndChild(table);

        msg = new TiXmlElement("flags");
        str=_T("0x") + Int2HEX(global->xmltable[table_num].flags);
        msg->LinkEndChild(new TiXmlText((const char*)str.mb_str()));
        table->LinkEndChild(msg);

        msg = new TiXmlElement("title");
        msg->LinkEndChild(new TiXmlText((const char*)global->xmltable[table_num].title.mb_str()));
        table->LinkEndChild(msg);

        msg = new TiXmlElement("description");
        msg->LinkEndChild(new TiXmlText((const char*)global->xmltable[table_num].description.mb_str()));
        table->LinkEndChild(msg);

        for (int x=0; x < 3; x++)
        {
            TiXmlElement* axis = new TiXmlElement("AXIS");
            table->LinkEndChild(axis);

            if (x==0) strcpy(txt,"x");
            else if (x==1) strcpy(txt,"y");
            else if (x==2) strcpy(txt,"z");

            axis->SetAttribute("id",txt);

            msg = new TiXmlElement("flags");
            str=_T("0x") + Int2HEX(global->xmlaxis[table_num][x].flags);
            msg->LinkEndChild(new TiXmlText((const char*)str.mb_str()));
            axis->LinkEndChild(msg);

            msg = new TiXmlElement("address");
            str=_T("0x") + Int2HEX(global->xmlaxis[table_num][x].address);
            msg->LinkEndChild(new TiXmlText((const char*)str.mb_str()));
            axis->LinkEndChild(msg);

            msg = new TiXmlElement("bits");
            sprintf(txt,"%i",global->xmlaxis[table_num][x].bits);
            msg->LinkEndChild(new TiXmlText(txt));
            axis->LinkEndChild(msg);

            msg = new TiXmlElement("units");
            msg->LinkEndChild(new TiXmlText((const char*)global->xmlaxis[table_num][x].units.mb_str()));
            axis->LinkEndChild(msg);

            msg = new TiXmlElement("decimalpl");
            sprintf(txt,"%i",global->xmlaxis[table_num][x].decimalpl);
            msg->LinkEndChild(new TiXmlText(txt));
            axis->LinkEndChild(msg);

            msg = new TiXmlElement("count");
            sprintf(txt,"%i",global->xmlaxis[table_num][x].count);
            msg->LinkEndChild(new TiXmlText(txt));
            axis->LinkEndChild(msg);

            msg = new TiXmlElement("outputtype");
            sprintf(txt,"%i",global->xmlaxis[table_num][x].outputtype);
            msg->LinkEndChild(new TiXmlText(txt));
            axis->LinkEndChild(msg);

            msg = new TiXmlElement("embeddedinfotype");
            sprintf(txt,"%i",global->xmlaxis[table_num][x].embeddedinfotype);
            msg->LinkEndChild(new TiXmlText(txt));
            axis->LinkEndChild(msg);

            if (global->xmlaxis[table_num][x].embeddedinfotype==EMBEDDEDINFO_STORED)
            {
                for (int c=0; c < global->xmlaxis[table_num][x].count; c++)
                {
                    TiXmlElement* embeddedinfolabel = new TiXmlElement("embeddedinfolabel");
                    axis->LinkEndChild(embeddedinfolabel);
                    sprintf(txt,"%i",c);
                    embeddedinfolabel->SetAttribute("index",txt);
                    embeddedinfolabel->SetDoubleAttribute("value",global->xmlaxis[table_num][x].embeddedinfolabel[c]);
                }
            }
            else if (global->xmlaxis[table_num][x].embeddedinfotype==EMBEDDEDINFO_SCALED)
            {
                for (int c=0; c < 2; c++)
                {
                    TiXmlElement* embeddedinfolabel = new TiXmlElement("embeddedinfolabel");
                    axis->LinkEndChild(embeddedinfolabel);
                    sprintf(txt,"%i",c);
                    embeddedinfolabel->SetAttribute("index",txt);
                    embeddedinfolabel->SetDoubleAttribute("value",global->xmlaxis[table_num][x].embeddedinfolabel[c]);
                }
            }

            msg = new TiXmlElement("factor");
            sprintf(txt,"%f",global->xmlaxis[table_num][x].factor);
            msg->LinkEndChild(new TiXmlText(txt));
            axis->LinkEndChild(msg);

            msg = new TiXmlElement("offset");
            sprintf(txt,"%f",global->xmlaxis[table_num][x].offset);
            msg->LinkEndChild(new TiXmlText(txt));
            axis->LinkEndChild(msg);
        }
    }

	// ------------------------------------------------------------------------
	TiXmlElement* checksum = new TiXmlElement("CHECKSUM");
	root->LinkEndChild(checksum);

	msg = new TiXmlElement("title");
	msg->LinkEndChild(new TiXmlText((const char*)global->xmlchecksum.title.mb_str()));
	checksum->LinkEndChild(msg);

	msg = new TiXmlElement("pluginid");
	sprintf(txt,"%i",global->xmlchecksum.pluginid);
	msg->LinkEndChild(new TiXmlText(txt));
	checksum->LinkEndChild(msg);

	// ------------------------------------------------------------------------
	doc.SaveFile((const char*)FileDialog->GetPath().mb_str());


    StatusBar->SetStatusText(_("Maps file saved."),1);
}

void CrossTunerStudioFrame::OnMenuItem_AddNewMapSelected(wxCommandEvent& event)
{
	// Create instance
    MapEditorDialog *map_editor_dlg = new MapEditorDialog(this);

    // Init. table
    map_editor_dlg->NewEditor(MAX_MAPS_DEFINED-1, global);

	// Show dialog
	map_editor_dlg->ShowModal();

	if (map_editor_dlg->GetExitStatus())
    {
        int selected_map=-1;

        if (global->xmltable_count == 0)
        {
            selected_map=-1; // No maps loaded start new
        }
        else
        {
            if (map_viewer_frm != NULL)
            {
                selected_map=map_viewer_frm->SelectedNode();
                if (selected_map < 0)
                {
                    selected_map=global->xmltable_count;    // Add map to end of list
                }
            }
        }

        if ((selected_map >= 0) && (selected_map < global->xmltable_count))
        {
            for (int x=global->xmltable_count; x > selected_map; x--)
            {
                global->xmltable[x].title=global->xmltable[x-1].title;
                global->xmltable[x].description=global->xmltable[x-1].description;

                // Z Axis
                global->xmlaxis[x][2].address=global->xmlaxis[x-1][2].address;
                global->xmlaxis[x][2].bits=global->xmlaxis[x-1][2].bits;
                global->xmlaxis[x][2].flags=global->xmlaxis[x-1][2].flags;
                global->xmlaxis[x][2].units=global->xmlaxis[x-1][2].units;
                global->xmlaxis[x][2].decimalpl=global->xmlaxis[x-1][2].decimalpl;
                global->xmlaxis[x][2].offset=global->xmlaxis[x-1][2].offset;
                global->xmlaxis[x][2].factor=global->xmlaxis[x-1][2].factor;

                // X Axis
                global->xmlaxis[x][0].count=global->xmlaxis[x-1][0].count;
                global->xmlaxis[x][0].units=global->xmlaxis[x-1][0].units;
                global->xmlaxis[x][0].outputtype=global->xmlaxis[x-1][0].outputtype;
                global->xmlaxis[x][0].decimalpl=global->xmlaxis[x-1][0].decimalpl;
                global->xmlaxis[x][0].offset=global->xmlaxis[x-1][0].offset;
                global->xmlaxis[x][0].factor=global->xmlaxis[x-1][0].factor;
                global->xmlaxis[x][0].embeddedinfotype=global->xmlaxis[x-1][0].embeddedinfotype;
                global->xmlaxis[x][0].address=global->xmlaxis[x-1][0].address;
                global->xmlaxis[x][0].flags=global->xmlaxis[x-1][0].flags;
                global->xmlaxis[x][0].bits=global->xmlaxis[x-1][0].bits;

                if (global->xmlaxis[x-1][0].embeddedinfotype==EMBEDDEDINFO_STORED)
                {
                    for (unsigned short y=0; y < global->xmlaxis[x-1][0].count; y++)
                    {
                        global->xmlaxis[x][0].embeddedinfolabel[y]=global->xmlaxis[x-1][0].embeddedinfolabel[y];
                    }
                }
                else if (global->xmlaxis[x-1][0].embeddedinfotype==EMBEDDEDINFO_SCALED)
                {
                    for (unsigned short y=0; y < 2; y++)
                    {
                        global->xmlaxis[x][0].embeddedinfolabel[y]=global->xmlaxis[x-1][0].embeddedinfolabel[y];
                    }
                }

                // Y Axis
                global->xmlaxis[x][1].count=global->xmlaxis[x-1][1].count;
                global->xmlaxis[x][1].units=global->xmlaxis[x-1][1].units;
                global->xmlaxis[x][1].outputtype=global->xmlaxis[x-1][1].outputtype;
                global->xmlaxis[x][1].decimalpl=global->xmlaxis[x-1][1].decimalpl;
                global->xmlaxis[x][1].offset=global->xmlaxis[x-1][1].offset;
                global->xmlaxis[x][1].factor=global->xmlaxis[x-1][1].factor;
                global->xmlaxis[x][1].embeddedinfotype=global->xmlaxis[x-1][1].embeddedinfotype;
                global->xmlaxis[x][1].address=global->xmlaxis[x-1][1].address;
                global->xmlaxis[x][1].flags=global->xmlaxis[x-1][1].flags;
                global->xmlaxis[x][1].bits=global->xmlaxis[x-1][1].bits;

                if (global->xmlaxis[x-1][1].embeddedinfotype==EMBEDDEDINFO_STORED)
                {
                    for (unsigned short y=0; y < global->xmlaxis[x-1][1].count; y++)
                    {
                        global->xmlaxis[x][1].embeddedinfolabel[y]=global->xmlaxis[x-1][1].embeddedinfolabel[y];
                    }
                }
                else if (global->xmlaxis[x-1][1].embeddedinfotype==EMBEDDEDINFO_SCALED)
                {
                    for (unsigned short y=0; y < 2; y++)
                    {
                        global->xmlaxis[x][1].embeddedinfolabel[y]=global->xmlaxis[x-1][1].embeddedinfolabel[y];
                    }
                }
            }

            selected_map++;
        }

        if (selected_map == -1) selected_map=0;

        global->xmltable[selected_map].title=global->xmltable[MAX_MAPS_DEFINED-1].title;
        global->xmltable[selected_map].description=global->xmltable[MAX_MAPS_DEFINED-1].description;

        // Z Axis
        global->xmlaxis[selected_map][2].address=global->xmlaxis[MAX_MAPS_DEFINED-1][2].address;
        global->xmlaxis[selected_map][2].bits=global->xmlaxis[MAX_MAPS_DEFINED-1][2].bits;
        global->xmlaxis[selected_map][2].flags=global->xmlaxis[MAX_MAPS_DEFINED-1][2].flags;
        global->xmlaxis[selected_map][2].units=global->xmlaxis[MAX_MAPS_DEFINED-1][2].units;
        global->xmlaxis[selected_map][2].outputtype=global->xmlaxis[MAX_MAPS_DEFINED-1][2].outputtype;
        global->xmlaxis[selected_map][2].decimalpl=global->xmlaxis[MAX_MAPS_DEFINED-1][2].decimalpl;
        global->xmlaxis[selected_map][2].offset=global->xmlaxis[MAX_MAPS_DEFINED-1][2].offset;
        global->xmlaxis[selected_map][2].factor=global->xmlaxis[MAX_MAPS_DEFINED-1][2].factor;

        // X Axis
        global->xmlaxis[selected_map][0].count=global->xmlaxis[MAX_MAPS_DEFINED-1][0].count;
        global->xmlaxis[selected_map][0].units=global->xmlaxis[MAX_MAPS_DEFINED-1][0].units;
        global->xmlaxis[selected_map][0].outputtype=global->xmlaxis[MAX_MAPS_DEFINED-1][0].outputtype;
        global->xmlaxis[selected_map][0].decimalpl=global->xmlaxis[MAX_MAPS_DEFINED-1][0].decimalpl;
        global->xmlaxis[selected_map][0].offset=global->xmlaxis[MAX_MAPS_DEFINED-1][0].offset;
        global->xmlaxis[selected_map][0].factor=global->xmlaxis[MAX_MAPS_DEFINED-1][0].factor;
        global->xmlaxis[selected_map][0].embeddedinfotype=global->xmlaxis[MAX_MAPS_DEFINED-1][0].embeddedinfotype;
        global->xmlaxis[selected_map][0].address=global->xmlaxis[MAX_MAPS_DEFINED-1][0].address;
        global->xmlaxis[selected_map][0].flags=global->xmlaxis[MAX_MAPS_DEFINED-1][0].flags;
        global->xmlaxis[selected_map][0].bits=global->xmlaxis[MAX_MAPS_DEFINED-1][0].bits;

        if (global->xmlaxis[MAX_MAPS_DEFINED-1][0].embeddedinfotype==EMBEDDEDINFO_STORED)
        {
            for (unsigned short y=0; y < global->xmlaxis[MAX_MAPS_DEFINED-1][0].count; y++)
            {
                global->xmlaxis[selected_map][0].embeddedinfolabel[y]=global->xmlaxis[MAX_MAPS_DEFINED-1][0].embeddedinfolabel[y];
            }
        }
        else if (global->xmlaxis[MAX_MAPS_DEFINED-1][0].embeddedinfotype==EMBEDDEDINFO_SCALED)
        {
            for (unsigned short y=0; y < 2; y++)
            {
                global->xmlaxis[selected_map][0].embeddedinfolabel[y]=global->xmlaxis[MAX_MAPS_DEFINED-1][0].embeddedinfolabel[y];
            }
        }

        // Y Axis
        global->xmlaxis[selected_map][1].count=global->xmlaxis[MAX_MAPS_DEFINED-1][1].count;
        global->xmlaxis[selected_map][1].units=global->xmlaxis[MAX_MAPS_DEFINED-1][1].units;
        global->xmlaxis[selected_map][1].outputtype=global->xmlaxis[MAX_MAPS_DEFINED-1][1].outputtype;
        global->xmlaxis[selected_map][1].decimalpl=global->xmlaxis[MAX_MAPS_DEFINED-1][1].decimalpl;
        global->xmlaxis[selected_map][1].offset=global->xmlaxis[MAX_MAPS_DEFINED-1][1].offset;
        global->xmlaxis[selected_map][1].factor=global->xmlaxis[MAX_MAPS_DEFINED-1][1].factor;
        global->xmlaxis[selected_map][1].embeddedinfotype=global->xmlaxis[MAX_MAPS_DEFINED-1][1].embeddedinfotype;
        global->xmlaxis[selected_map][1].address=global->xmlaxis[MAX_MAPS_DEFINED-1][1].address;
        global->xmlaxis[selected_map][1].flags=global->xmlaxis[MAX_MAPS_DEFINED-1][1].flags;
        global->xmlaxis[selected_map][1].bits=global->xmlaxis[MAX_MAPS_DEFINED-1][1].bits;

        if (global->xmlaxis[MAX_MAPS_DEFINED-1][1].embeddedinfotype==EMBEDDEDINFO_STORED)
        {
            for (unsigned short y=0; y < global->xmlaxis[MAX_MAPS_DEFINED-1][1].count; y++)
            {
                global->xmlaxis[selected_map][1].embeddedinfolabel[y]=global->xmlaxis[MAX_MAPS_DEFINED-1][1].embeddedinfolabel[y];
            }
        }
        else if (global->xmlaxis[MAX_MAPS_DEFINED-1][1].embeddedinfotype==EMBEDDEDINFO_SCALED)
        {
            for (unsigned short y=0; y < 2; y++)
            {
                global->xmlaxis[selected_map][1].embeddedinfolabel[y]=global->xmlaxis[MAX_MAPS_DEFINED-1][1].embeddedinfolabel[y];
            }
        }

        global->xmltable_count++;

        if (map_viewer_frm == NULL)
        {
            OnMenuItem_MapViewerSelected(event);
        }
        else
        {
            map_viewer_frm->ClearTree();
            for (int count=0; count < global->xmltable_count; count++)
            {
                map_viewer_frm->AddTable(global->xmltable[count].title,
                                       global->xmlaxis[count][0].count,
                                       global->xmlaxis[count][1].count,
                                       Int2HEX(global->xmlaxis[count][2].address));
            }

            map_viewer_frm->ExpandTree();

            StatusBar->SetStatusText(_("New map added."),1);
        }
    }
}

void CrossTunerStudioFrame::OnMenuItem_EditSelectedMapSelected(wxCommandEvent& event)
{
    if (global->xmltable_count == 0)
    {
        StatusBar->SetStatusText(_("No maps have been loaded!"),1);
        return;
    }

    if (map_viewer_frm == NULL)
    {
        StatusBar->SetStatusText(_("Map viewer not initialized!"),1);
        return;
    }

    int selected_map=map_viewer_frm->SelectedNode();
    if (selected_map < 0)
    {
        StatusBar->SetStatusText(_("Please select a map first in the map viewer!"),1);
        return;
    }

	// Create instance
    MapEditorDialog *map_editor_dlg = new MapEditorDialog(this);

    // Init. table
    map_editor_dlg->UpdateEditor(selected_map, global);

	// Show dialog
	map_editor_dlg->ShowModal();

	// Update map viewer
    map_viewer_frm->EditTable(selected_map,
                              global->xmltable[selected_map].title,
                              global->xmlaxis[selected_map][0].count,
                              global->xmlaxis[selected_map][1].count,
                              Int2HEX(global->xmlaxis[selected_map][2].address));
}

void CrossTunerStudioFrame::OnMenuItem_DeleteSelectedMapSelected(wxCommandEvent& event)
{
    if ((global->xmltable_count == 0) || (map_viewer_frm == NULL))
        return;

    int selected_map=map_viewer_frm->SelectedNode();
    if ((selected_map < 0) || (selected_map >= global->xmltable_count))
        return;

    for (int x=selected_map; x < global->xmltable_count; x++)
    {
        global->xmltable[x].title=global->xmltable[x+1].title;
        global->xmltable[x].description=global->xmltable[x+1].description;

        // Z Axis
        global->xmlaxis[x][2].address=global->xmlaxis[x+1][2].address;
        global->xmlaxis[x][2].bits=global->xmlaxis[x+1][2].bits;
        global->xmlaxis[x][2].flags=global->xmlaxis[x+1][2].flags;
        global->xmlaxis[x][2].units=global->xmlaxis[x+1][2].units;
        global->xmlaxis[x][2].decimalpl=global->xmlaxis[x+1][2].decimalpl;
        global->xmlaxis[x][2].offset=global->xmlaxis[x+1][2].offset;
        global->xmlaxis[x][2].factor=global->xmlaxis[x+1][2].factor;

        // X Axis
        global->xmlaxis[x][0].count=global->xmlaxis[x+1][0].count;
        global->xmlaxis[x][0].units=global->xmlaxis[x+1][0].units;
        global->xmlaxis[x][0].outputtype=global->xmlaxis[x+1][0].outputtype;
        global->xmlaxis[x][0].decimalpl=global->xmlaxis[x+1][0].decimalpl;
        global->xmlaxis[x][0].offset=global->xmlaxis[x+1][0].offset;
        global->xmlaxis[x][0].factor=global->xmlaxis[x+1][0].factor;
        global->xmlaxis[x][0].embeddedinfotype=global->xmlaxis[x+1][0].embeddedinfotype;
        global->xmlaxis[x][0].address=global->xmlaxis[x+1][0].address;
        global->xmlaxis[x][0].flags=global->xmlaxis[x+1][0].flags;

        if (global->xmlaxis[x+1][0].embeddedinfotype==EMBEDDEDINFO_STORED)
        {
            for (unsigned short y=0; y < global->xmlaxis[x+1][0].count; y++)
            {
                global->xmlaxis[x][0].embeddedinfolabel[y]=global->xmlaxis[x+1][0].embeddedinfolabel[y];
            }
        }

        // Y Axis
        global->xmlaxis[x][1].count=global->xmlaxis[x+1][1].count;
        global->xmlaxis[x][1].units=global->xmlaxis[x+1][1].units;
        global->xmlaxis[x][1].outputtype=global->xmlaxis[x+1][1].outputtype;
        global->xmlaxis[x][1].decimalpl=global->xmlaxis[x+1][1].decimalpl;
        global->xmlaxis[x][1].offset=global->xmlaxis[x+1][1].offset;
        global->xmlaxis[x][1].factor=global->xmlaxis[x+1][1].factor;
        global->xmlaxis[x][1].embeddedinfotype=global->xmlaxis[x+1][1].embeddedinfotype;
        global->xmlaxis[x][1].address=global->xmlaxis[x+1][1].address;
        global->xmlaxis[x][1].flags=global->xmlaxis[x+1][1].flags;

        if (global->xmlaxis[x+1][1].embeddedinfotype==EMBEDDEDINFO_STORED)
        {
            for (unsigned short y=0; y < global->xmlaxis[x+1][1].count; y++)
            {
                global->xmlaxis[x][1].embeddedinfolabel[y]=global->xmlaxis[x+1][1].embeddedinfolabel[y];
            }
        }
    }

    global->xmltable_count--;

    map_viewer_frm->ClearTree();
    for (int count=0; count < global->xmltable_count; count++)
    {
        map_viewer_frm->AddTable(global->xmltable[count].title,
                               global->xmlaxis[count][0].count,
                               global->xmlaxis[count][1].count,
                               Int2HEX(global->xmlaxis[count][2].address));
    }

    map_viewer_frm->ExpandTree();

    StatusBar->SetStatusText(_("Map deleted."),1);
}

void CrossTunerStudioFrame::OnMenuItem_DuplicateSelectedMapSelected(wxCommandEvent& event)
{
    if ((global->xmltable_count == 0) || (map_viewer_frm == NULL))
        return;

    int selected_map=map_viewer_frm->SelectedNode();
    if ((selected_map < 0) || (selected_map >= global->xmltable_count))
        return;

    global->xmltable[global->xmltable_count].title=global->xmltable[selected_map].title;
    global->xmltable[global->xmltable_count].description=global->xmltable[selected_map].description;

    // Z Axis
    global->xmlaxis[global->xmltable_count][2].address=global->xmlaxis[selected_map][2].address;
    global->xmlaxis[global->xmltable_count][2].bits=global->xmlaxis[selected_map][2].bits;
    global->xmlaxis[global->xmltable_count][2].flags=global->xmlaxis[selected_map][2].flags;
    global->xmlaxis[global->xmltable_count][2].units=global->xmlaxis[selected_map][2].units;
    global->xmlaxis[global->xmltable_count][2].outputtype=global->xmlaxis[selected_map][2].outputtype;
    global->xmlaxis[global->xmltable_count][2].decimalpl=global->xmlaxis[selected_map][2].decimalpl;
    global->xmlaxis[global->xmltable_count][2].offset=global->xmlaxis[selected_map][2].offset;
    global->xmlaxis[global->xmltable_count][2].factor=global->xmlaxis[selected_map][2].factor;

    // X Axis
    global->xmlaxis[global->xmltable_count][0].count=global->xmlaxis[selected_map][0].count;
    global->xmlaxis[global->xmltable_count][0].units=global->xmlaxis[selected_map][0].units;
    global->xmlaxis[global->xmltable_count][0].outputtype=global->xmlaxis[selected_map][0].outputtype;
    global->xmlaxis[global->xmltable_count][0].decimalpl=global->xmlaxis[selected_map][0].decimalpl;
    global->xmlaxis[global->xmltable_count][0].offset=global->xmlaxis[selected_map][0].offset;
    global->xmlaxis[global->xmltable_count][0].factor=global->xmlaxis[selected_map][0].factor;
    global->xmlaxis[global->xmltable_count][0].embeddedinfotype=global->xmlaxis[selected_map][0].embeddedinfotype;
    global->xmlaxis[global->xmltable_count][0].address=global->xmlaxis[selected_map][0].address;
    global->xmlaxis[global->xmltable_count][0].bits=global->xmlaxis[selected_map][0].bits;
    global->xmlaxis[global->xmltable_count][0].flags=global->xmlaxis[selected_map][0].flags;

    if (global->xmlaxis[selected_map][0].embeddedinfotype==EMBEDDEDINFO_STORED)
    {
        for (unsigned short y=0; y < global->xmlaxis[selected_map][0].count; y++)
        {
            global->xmlaxis[global->xmltable_count][0].embeddedinfolabel[y]=global->xmlaxis[selected_map][0].embeddedinfolabel[y];
        }
    }
    else if (global->xmlaxis[selected_map][0].embeddedinfotype==EMBEDDEDINFO_SCALED)
    {
        for (unsigned short y=0; y < 2; y++)
        {
            global->xmlaxis[global->xmltable_count][0].embeddedinfolabel[y]=global->xmlaxis[selected_map][0].embeddedinfolabel[y];
        }
    }

    // Y Axis
    global->xmlaxis[global->xmltable_count][1].count=global->xmlaxis[selected_map][1].count;
    global->xmlaxis[global->xmltable_count][1].units=global->xmlaxis[selected_map][1].units;
    global->xmlaxis[global->xmltable_count][1].outputtype=global->xmlaxis[selected_map][1].outputtype;
    global->xmlaxis[global->xmltable_count][1].decimalpl=global->xmlaxis[selected_map][1].decimalpl;
    global->xmlaxis[global->xmltable_count][1].offset=global->xmlaxis[selected_map][1].offset;
    global->xmlaxis[global->xmltable_count][1].factor=global->xmlaxis[selected_map][1].factor;
    global->xmlaxis[global->xmltable_count][1].embeddedinfotype=global->xmlaxis[selected_map][1].embeddedinfotype;
    global->xmlaxis[global->xmltable_count][1].address=global->xmlaxis[selected_map][1].address;
    global->xmlaxis[global->xmltable_count][1].bits=global->xmlaxis[selected_map][1].bits;
    global->xmlaxis[global->xmltable_count][1].flags=global->xmlaxis[selected_map][1].flags;

    if (global->xmlaxis[selected_map][1].embeddedinfotype==EMBEDDEDINFO_STORED)
    {
        for (unsigned short y=0; y < global->xmlaxis[selected_map][1].count; y++)
        {
            global->xmlaxis[global->xmltable_count][1].embeddedinfolabel[y]=global->xmlaxis[selected_map][1].embeddedinfolabel[y];
        }
    }
    else if (global->xmlaxis[selected_map][1].embeddedinfotype==EMBEDDEDINFO_SCALED)
    {
        for (unsigned short y=0; y < 2; y++)
        {
            global->xmlaxis[global->xmltable_count][1].embeddedinfolabel[y]=global->xmlaxis[selected_map][1].embeddedinfolabel[y];
        }
    }

    global->xmltable_count++;

    map_viewer_frm->ClearTree();
    for (int count=0; count < global->xmltable_count; count++)
    {
        map_viewer_frm->AddTable(global->xmltable[count].title,
                               global->xmlaxis[count][0].count,
                               global->xmlaxis[count][1].count,
                               Int2HEX(global->xmlaxis[count][2].address));
    }

    map_viewer_frm->ExpandTree();

    StatusBar->SetStatusText(_("Map duplicated."),1);
}

void CrossTunerStudioFrame::OnMenuItem_ImportTunerProSelected(wxCommandEvent& event)
{
    // Open file dialog window
    wxFileDialog *FileDialog = new wxFileDialog(this, _("Select XDF file to import"), wxEmptyString, wxEmptyString, wxT("XDF files (*.xdf)|*.xdf|All files (*.*)|*.*"), wxFD_DEFAULT_STYLE|wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

    if (FileDialog->ShowModal() == wxID_CANCEL)
    {
        delete FileDialog;
        return;
    }

    // Open XML document
    TiXmlDocument doc((const char*)FileDialog->GetPath().mb_str());
    if (!doc.LoadFile())
    {
        StatusBar->SetStatusText(_("Unable to open definitions file!"),1);
        return;
    }

    TiXmlHandle hDoc(&doc);	//Handle to xml document
    TiXmlHandle hRoot(0);   //Handle to root
    TiXmlElement* pElem;    //Handle to element
    TiXmlElement* pChild;   //Handle to child elements

    // Find root element (XDFFORMAT)
    pElem = hDoc.FirstChildElement().Element();
    if (!pElem)
    {
        StatusBar->SetStatusText(_("The definitions file is corrupted!"),1);
	    return;
    }

    // Save root for later use
    hRoot = TiXmlHandle(pElem);

    // Read version information -----------------------------------------------
    global->xmlformat_version=wxString::FromAscii(pElem->Attribute("version"));
    if (global->xmlformat_version != _T("1.50"))
    {
        StatusBar->SetStatusText(_("The definitions file version is not compatible!"),1);
	    return;
    }

    // Clear Map Viewer Tree
    if (map_viewer_frm != NULL)
        map_viewer_frm->ClearTree();

    // Run through all XML elements -------------------------------------------
    global->xmltable_count=0;
    for(pChild=hRoot.FirstChild().Element(); pChild; pChild = pChild->NextSiblingElement())
    {
        wxString parent(pChild->Value(), wxConvUTF8);

        if (parent==_T("XDFHEADER"))
        {
            for(TiXmlElement* header_child = pChild->FirstChildElement(); header_child; header_child = header_child->NextSiblingElement())
            {
                wxString value(header_child->Value(), wxConvUTF8);
                wxString text(header_child->GetText(), wxConvUTF8);

                if (value==_T("fileversion"))
                {
                    global->xmlheader.fileversion=text;
                }
                else if (value==_T("deftitle"))
                {
                    global->xmlheader.title=text;
                }
                else if (value==_T("description"))
                {
                    global->xmlheader.description=text;
                }
                else if (value==_T("author"))
                {
                    global->xmlheader.author=text;
                }
                else if (value==_T("baseoffset"))
                {
                    global->xmlheader.baseoffset=HEX2Int(text);
                }
            }
        }
        else if (parent==_T("XDFTABLE"))
        {
            for(TiXmlElement* table_child = pChild->FirstChildElement(); table_child; table_child = table_child->NextSiblingElement())
            {
                wxString table_value(table_child->Value(), wxConvUTF8);
                wxString table_text(table_child->GetText(), wxConvUTF8);

                if (table_value==_T("title"))
                {
                    global->xmltable[global->xmltable_count].title=table_text;
                }
                else if (table_value==_T("description"))
                {
                    global->xmltable[global->xmltable_count].description=table_text;
                }
                else if (table_value==_T("XDFAXIS"))
                {
                    int axis_id;

                    wxString id(table_child->Attribute("id"), wxConvUTF8);
                    if (id==_T("x")) axis_id=0;
                    else if (id==_T("y")) axis_id=1;
                    else axis_id=2;

                    global->xmlaxis[global->xmltable_count][axis_id].id=id;

                    for(TiXmlElement* axis_child = table_child->FirstChildElement(); axis_child; axis_child = axis_child->NextSiblingElement())
                    {
                        wxString axis_value(axis_child->Value(), wxConvUTF8);
                        wxString axis_text(axis_child->GetText(), wxConvUTF8);

                        if (axis_value==_T("EMBEDDEDDATA"))
                        {
                            // TODO
                            /*
                            try
                            {
                                global->xmlaxis[global->xmltable_count][axis_id].flags=(unsigned short)strtoul(axis_child->Attribute("mmedtypeflags"),NULL,0);
                            }
                            catch(...)
                            {
                                global->xmlaxis[global->xmltable_count][axis_id].flags=0;
                            }

                            try
                            {
                                global->xmlaxis[global->xmltable_count][axis_id].address=strtoul(axis_child->Attribute("mmedaddress"),NULL,0);
                            }
                            catch(...)
                            {
                                global->xmlaxis[global->xmltable_count][axis_id].address=0;
                            }

                            try
                            {
                                global->xmlaxis[global->xmltable_count][axis_id].bits=(unsigned short)atoi(axis_child->Attribute("mmedelementsizebits"));
                            }
                            catch(...)
                            {
                                global->xmlaxis[global->xmltable_count][axis_id].bits=8;
                            }
                            */
                        }
                        else if (axis_value==_T("units"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].units=axis_text;
                        }
                        else if (axis_value==_T("decimalpl"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].decimalpl=(unsigned short)atoi(axis_text.mb_str());
                        }
                        /*
                        else if (axis_value==_T("min"))
                        {
                            axis_text.ToDouble(&global->xmlaxis[global->xmltable_count][axis_id].min);
                        }
                        else if (axis_value==_T("max"))
                        {
                            axis_text.ToDouble(&global->xmlaxis[global->xmltable_count][axis_id].max);
                        }
                        */
                        else if ((axis_value==_T("indexcount")) && (axis_id != 2))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].count=(unsigned short)atoi(axis_text.mb_str());
                        }
                        else if (axis_value==_T("outputtype"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].outputtype=(unsigned short)atoi(axis_text.mb_str());
                        }
                        else if (axis_value==_T("embedinfo"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].embeddedinfotype=(unsigned short)strtoul(axis_child->Attribute("type"),NULL,0);
                        }
                        /*
                        else if (axis_value==_T("datatype"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].datatype=(unsigned short)atoi(axis_text.mb_str());
                        }
                        else if (axis_value==_T("unittype"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].unittype=(unsigned short)atoi(axis_text.mb_str());
                        }
                        */
                        else if (axis_value==_T("LABEL"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].embeddedinfolabel[strtoul(axis_child->Attribute("index"),NULL,0)]=atof(axis_child->Attribute("value"));
                        }
                        else if (axis_value==_T("MATH"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].factor=1;
                            global->xmlaxis[global->xmltable_count][axis_id].offset=0;
/*
                            global->xmlaxis[global->xmltable_count][axis_id].math_equation=wxString::FromAscii(axis_child->Attribute("equation"));

                            for(TiXmlElement* math_child = axis_child->FirstChildElement(); math_child; math_child = math_child->NextSiblingElement())
                            {
                                wxString math_value(axis_child->Value(), wxConvUTF8);
                                wxString math_text(axis_child->GetText(), wxConvUTF8);

                                if (math_value==_T("VAR"))
                                {
                                    global->xmlaxis[global->xmltable_count][axis_id].var_id=wxString::FromAscii(axis_child->Attribute("id"));
                                }
                            }
*/
                        }
                    }
                }
            }

            if (map_viewer_frm != NULL)
            {
                map_viewer_frm->AddTable(global->xmltable[global->xmltable_count].title,
                                         global->xmlaxis[global->xmltable_count][0].count,
                                         global->xmlaxis[global->xmltable_count][1].count,
                                         Int2HEX(global->xmlaxis[global->xmltable_count][2].address));
            }

            global->xmltable_count++;
        }
        else if (parent==_T("XDFCHECKSUM"))
        {
            for(TiXmlElement* checksum_child = pChild->FirstChildElement(); checksum_child; checksum_child = checksum_child->NextSiblingElement())
            {
                wxString checksum_value(checksum_child->Value(), wxConvUTF8);
                wxString checksum_text(checksum_child->GetText(), wxConvUTF8);

                if (checksum_value==_T("title"))
                {
                    global->xmlchecksum.title=checksum_text;
                }
                else if (checksum_value==_T("REGION"))
                {
                    for(TiXmlElement* region_child = checksum_child->FirstChildElement(); region_child; region_child = region_child->NextSiblingElement())
                    {
                        wxString region_value(region_child->Value(), wxConvUTF8);
                        wxString region_text(region_child->GetText(), wxConvUTF8);

                        if (region_value==_T("pluginmoduleid"))
                        {
                            if (region_text.Left(33) == _T("9b6fa911-da49-1953-b6c0-1c7d3a9cf"))
                            {
                                unsigned long number;
                                if (region_text.Right(3).ToULong(&number))
                                    global->xmlchecksum.pluginid=(unsigned short)number;
                                else
                                    global->xmlchecksum.pluginid=0;
                            }
                            else
                                global->xmlchecksum.pluginid=0;
                        }
                    }
                }
            }
        }
    }

	// Show dialog
	if (map_viewer_frm == NULL)
        OnMenuItem_MapViewerSelected(event);
    else
        map_viewer_frm->Show();

    StatusBar->SetStatusText(_("Definitions file loaded."),1);
}

void CrossTunerStudioFrame::OnMenuItem_CopyBIN1toBIN2Selected(wxCommandEvent& event)
{
    if(CopyBuffer(global->bin_buffer[0],1,global->bin_length[0]))
    {
        global->bin_length[1]=global->bin_length[0];
        global->bin_filename[1]=global->bin_filename[0];
        global->bin_path[1]=global->bin_path[0];

        TextCtrlBIN2->SetValue(global->bin_filename[0]);
        StaticText_Size2->SetLabel(StaticText_Size1->GetLabel());
        StaticText_CHK8_2->SetLabel(StaticText_CHK8_1->GetLabel());
        StaticText_CHK16_2->SetLabel(StaticText_CHK16_1->GetLabel());
        StaticText_CHK32_2->SetLabel(StaticText_CHK32_1->GetLabel());

        StatusBar->SetStatusText(_("BIN #1 copied to BIN #2."),1);
    }
}

void CrossTunerStudioFrame::OnMenuItem_CopyBIN1toBIN3Selected(wxCommandEvent& event)
{
    if(CopyBuffer(global->bin_buffer[0],2,global->bin_length[0]))
    {
        global->bin_length[2]=global->bin_length[0];
        global->bin_filename[2]=global->bin_filename[0];
        global->bin_path[2]=global->bin_path[0];

        TextCtrlBIN3->SetValue(global->bin_filename[0]);
        StaticText_Size3->SetLabel(StaticText_Size1->GetLabel());
        StaticText_CHK8_3->SetLabel(StaticText_CHK8_1->GetLabel());
        StaticText_CHK16_3->SetLabel(StaticText_CHK16_1->GetLabel());
        StaticText_CHK32_3->SetLabel(StaticText_CHK32_1->GetLabel());

        StatusBar->SetStatusText(_("BIN #1 copied to BIN #3."),1);
    }
}

void CrossTunerStudioFrame::OnMenuItem_CopyBIN2toBIN1Selected(wxCommandEvent& event)
{
    if(CopyBuffer(global->bin_buffer[1],0,global->bin_length[1]))
    {
        global->bin_length[0]=global->bin_length[1];
        global->bin_filename[0]=global->bin_filename[1];
        global->bin_path[0]=global->bin_path[1];

        TextCtrlBIN1->SetValue(global->bin_filename[1]);
        StaticText_Size1->SetLabel(StaticText_Size2->GetLabel());
        StaticText_CHK8_1->SetLabel(StaticText_CHK8_2->GetLabel());
        StaticText_CHK16_1->SetLabel(StaticText_CHK16_2->GetLabel());
        StaticText_CHK32_1->SetLabel(StaticText_CHK32_2->GetLabel());

        StatusBar->SetStatusText(_("BIN #2 copied to BIN #1."),1);
    }
}

void CrossTunerStudioFrame::OnMenuItem_CopyBIN2toBIN3Selected(wxCommandEvent& event)
{
    if(CopyBuffer(global->bin_buffer[1],2,global->bin_length[1]))
    {
        global->bin_length[2]=global->bin_length[1];
        global->bin_filename[2]=global->bin_filename[1];
        global->bin_path[2]=global->bin_path[1];

        TextCtrlBIN3->SetValue(global->bin_filename[1]);
        StaticText_Size3->SetLabel(StaticText_Size2->GetLabel());
        StaticText_CHK8_3->SetLabel(StaticText_CHK8_2->GetLabel());
        StaticText_CHK16_3->SetLabel(StaticText_CHK16_2->GetLabel());
        StaticText_CHK32_3->SetLabel(StaticText_CHK32_2->GetLabel());

        StatusBar->SetStatusText(_("BIN #2 copied to BIN #3."),1);
    }
}

void CrossTunerStudioFrame::OnMenuItem_CopyBIN3toBIN1Selected(wxCommandEvent& event)
{
    if(CopyBuffer(global->bin_buffer[2],0,global->bin_length[2]))
    {
        global->bin_length[0]=global->bin_length[2];
        global->bin_filename[0]=global->bin_filename[2];
        global->bin_path[0]=global->bin_path[2];

        TextCtrlBIN1->SetValue(global->bin_filename[2]);
        StaticText_Size1->SetLabel(StaticText_Size3->GetLabel());
        StaticText_CHK8_1->SetLabel(StaticText_CHK8_3->GetLabel());
        StaticText_CHK16_1->SetLabel(StaticText_CHK16_3->GetLabel());
        StaticText_CHK32_1->SetLabel(StaticText_CHK32_3->GetLabel());

        StatusBar->SetStatusText(_("BIN #3 copied to BIN #1."),1);
    }
}

void CrossTunerStudioFrame::OnMenuItem_CopyBIN3toBIN2Selected(wxCommandEvent& event)
{
    if(CopyBuffer(global->bin_buffer[2],1,global->bin_length[2]))
    {
        global->bin_length[1]=global->bin_length[2];
        global->bin_filename[1]=global->bin_filename[2];
        global->bin_path[1]=global->bin_path[2];

        TextCtrlBIN2->SetValue(global->bin_filename[2]);
        StaticText_Size2->SetLabel(StaticText_Size3->GetLabel());
        StaticText_CHK8_2->SetLabel(StaticText_CHK8_3->GetLabel());
        StaticText_CHK16_2->SetLabel(StaticText_CHK16_3->GetLabel());
        StaticText_CHK32_2->SetLabel(StaticText_CHK32_3->GetLabel());

        StatusBar->SetStatusText(_("BIN #3 copied to BIN #2."),1);
    }
}

void CrossTunerStudioFrame::OnMenuItem_MapViewerSelected(wxCommandEvent& event)
{
	if (map_viewer_frm == NULL)
    {
        map_viewer_frm = new MapViewerFrame(this);

        map_viewer_frm->Init(global);

        if (global->xmltable_count)
        {
            for (int count=0; count < global->xmltable_count; count++)
            {
                map_viewer_frm->AddTable(global->xmltable[count].title,
                                       global->xmlaxis[count][0].count,
                                       global->xmlaxis[count][1].count,
                                       Int2HEX(global->xmlaxis[count][2].address));
            }

            map_viewer_frm->ExpandTree();
        }
    }

	// Show dialog
	map_viewer_frm->Show();
}

void CrossTunerStudioFrame::OnMenuItem_TableEditorSelected(wxCommandEvent& event)
{
    // Check for possible error conditions
    if (global->xmltable_count == 0)
    {
        StatusBar->SetStatusText(_("No maps have been loaded!"),1);
        return;
    }

    if (map_viewer_frm == NULL)
    {
        StatusBar->SetStatusText(_("Map viewer not initialized!"),1);
        return;
    }

    if (!global->bin_length[SelectedBin()])
    {
        StatusBar->SetStatusText(_("No BIN file has been loaded in the selected buffer!"),1);
        return;
    }

    // Get currently selected map
	int selected_map=map_viewer_frm->SelectedNode();
	if (selected_map < 0)
    {
        StatusBar->SetStatusText(_("Please select a map first in the map viewer!"),1);
        return;
    }

	// Create instance
	TableEditorFrame *table_editor_form = new TableEditorFrame(this);

    // Init. table
    table_editor_form->Init(SelectedBin(), selected_map, global);
    table_editor_form->UpdateGridAxis();
    table_editor_form->UpdateGrid();

	// Show dialog
	table_editor_form->Show();
}

void CrossTunerStudioFrame::OnMenuItem_2DEditorSelected(wxCommandEvent& event)
{
    if (!global->bin_length[SelectedBin()])
    {
        StatusBar->SetStatusText(_("No BIN file has been loaded in the selected buffer!"),1);
        return;
    }

	// Create instance
	Map2DEditorFrame *map2d_editor_form = new Map2DEditorFrame(this);

    // Init. table
    map2d_editor_form->Init(SelectedBin(), map_viewer_frm->SelectedNode(), global);
    //map2d_editor_form->UpdateGridAxis();
    //map2d_editor_form->UpdateGrid();

	// Show dialog
	map2d_editor_form->Show();
}

void CrossTunerStudioFrame::OnAbout(wxCommandEvent& event)
{
	// Create about box instance
	AboutBoxDialog *about_dlg = new AboutBoxDialog(this);

	// Set application data
	about_dlg->SetAppName(_T("CrossTuner Studio"));
	about_dlg->SetVersion(_T(APP_VERSION));
	about_dlg->SetCopyright(_T("Copyright (c) MTX Electronics, " APP_DATE ".\nAll rights reserved."));
	about_dlg->SetCustomBuildInfo(AboutBoxDialog::GetBuildInfo(AboutBoxDialog::wxBUILDINFO_LONG).GetData());

	// Apply data changes
	about_dlg->ApplyInfo();

	// Show dialog
	about_dlg->ShowModal();

	// Destroy dialog
	about_dlg->Destroy();
}

/// ---------------------------------------------------------------------------
/// Toolbar Functions
/// ---------------------------------------------------------------------------

void CrossTunerStudioFrame::OnToolBarItem_LoadBINClicked(wxCommandEvent& event)
{
    OnMenuItem_LoadBINSelected(event);
}

void CrossTunerStudioFrame::OnToolBarItem_SaveBINClicked(wxCommandEvent& event)
{
    OnMenuItem_SaveBINSelected(event);
}

void CrossTunerStudioFrame::OnToolBarItem_LoadMapClicked(wxCommandEvent& event)
{
    OnMenuItem_LoadDefinitionSelected(event);
}

void CrossTunerStudioFrame::OnToolBarItem_MapViewerClicked(wxCommandEvent& event)
{
    OnMenuItem_MapViewerSelected(event);
}

void CrossTunerStudioFrame::OnToolBarItem_MapEditorClicked(wxCommandEvent& event)
{
    OnMenuItem_EditSelectedMapSelected(event);
}

void CrossTunerStudioFrame::OnToolBarItem_TableEditorClicked(wxCommandEvent& event)
{
    OnMenuItem_TableEditorSelected(event);
}

void CrossTunerStudioFrame::OnToolBarItem_2DEditorClicked(wxCommandEvent& event)
{
    OnMenuItem_2DEditorSelected(event);
}

/*
void CrossTunerStudioFrame::OnToolBarItem_PreferencesClicked(wxCommandEvent& event)
{
}
*/
void CrossTunerStudioFrame::OnToolBarItem_AboutClicked(wxCommandEvent& event)
{
    OnAbout(event);
}

void CrossTunerStudioFrame::OnToolBarItem_QuitClicked(wxCommandEvent& event)
{
    Close();
}

/// ---------------------------------------------------------------------------
/// Misc. UI Functions
/// ---------------------------------------------------------------------------

void CrossTunerStudioFrame::OnButtonBrowseBIN1Click(wxCommandEvent& event)
{
    RadioButton_SelectBIN1->SetValue(true);

    OnMenuItem_LoadBINSelected(event);
}

void CrossTunerStudioFrame::OnButtonBrowseBIN2Click(wxCommandEvent& event)
{
    RadioButton_SelectBIN2->SetValue(true);

    OnMenuItem_LoadBINSelected(event);
}

void CrossTunerStudioFrame::OnButtonBrowseBIN3Click(wxCommandEvent& event)
{
    RadioButton_SelectBIN3->SetValue(true);

    OnMenuItem_LoadBINSelected(event);
}

/// ---------------------------------------------------------------------------
/// Load/Save Functions
/// ---------------------------------------------------------------------------

bool CrossTunerStudioFrame::LoadDefinitionFileFromHD(wxString path)
{
    if (!wxFileExists(path))
    {
        StatusBar->SetStatusText(_("Maps file not found!"),1);
        return (false);
    }

    // Open XML document
    TiXmlDocument doc((const char*)path.mb_str());
    if (!doc.LoadFile())
    {
        StatusBar->SetStatusText(_("Unable to load maps file!"),1);
        return (false);
    }

    TiXmlHandle hDoc(&doc);	//Handle to xml document
    TiXmlHandle hRoot(0);   //Handle to root
    TiXmlElement* pElem;    //Handle to element
    TiXmlElement* pChild;   //Handle to child elements

    // Find root element (XTS)
    pElem = hDoc.FirstChildElement().Element();
    if (!pElem)
    {
        StatusBar->SetStatusText(_("The maps file is corrupted!"),1);
	    return (false);
    }

    // Save root for later use
    hRoot = TiXmlHandle(pElem);

    // Read version information -----------------------------------------------
    global->xmlformat_version=wxString::FromAscii(pElem->Attribute("version"));
    if (global->xmlformat_version != _T("1.0"))
    {
        StatusBar->SetStatusText(_("The maps file version is not compatible!"),1);
	    return (false);
    }

    // Clear Map Viewer Tree
    if (map_viewer_frm != NULL)
        map_viewer_frm->ClearTree();

    // Run through all XML elements -------------------------------------------
    global->xmltable_count=0;
    for(pChild=hRoot.FirstChild().Element(); pChild; pChild = pChild->NextSiblingElement())
    {
        wxString parent(pChild->Value(), wxConvUTF8);

        if (parent==_T("HEADER"))
        {
            for(TiXmlElement* header_child = pChild->FirstChildElement(); header_child; header_child = header_child->NextSiblingElement())
            {
                wxString value(header_child->Value(), wxConvUTF8);
                wxString text(header_child->GetText(), wxConvUTF8);

                if (value==_T("flags"))
                {
                    global->xmlheader.flags=(unsigned short)HEX2Int(text);
                }
                else if (value==_T("fileversion"))
                {
                    global->xmlheader.fileversion=text;
                }
                else if (value==_T("title"))
                {
                    global->xmlheader.title=text;
                }
                else if (value==_T("description"))
                {
                    global->xmlheader.description=text;
                }
                else if (value==_T("author"))
                {
                    global->xmlheader.author=text;
                }
                else if (value==_T("baseoffset"))
                {
                    global->xmlheader.baseoffset=HEX2Int(text);
                }
            }
        }
        else if (parent==_T("TABLE"))
        {
            for(TiXmlElement* table_child = pChild->FirstChildElement(); table_child; table_child = table_child->NextSiblingElement())
            {
                wxString table_value(table_child->Value(), wxConvUTF8);
                wxString table_text(table_child->GetText(), wxConvUTF8);

                if (table_value==_T("flags"))
                {
                    global->xmltable[global->xmltable_count].flags=(unsigned short)HEX2Int(table_text);
                }
                else if (table_value==_T("title"))
                {
                    global->xmltable[global->xmltable_count].title=table_text;
                }
                else if (table_value==_T("description"))
                {
                    global->xmltable[global->xmltable_count].description=table_text;
                }
                else if (table_value==_T("AXIS"))
                {
                    int axis_id;

                    wxString id(table_child->Attribute("id"), wxConvUTF8);
                    if (id==_T("x")) axis_id=0;
                    else if (id==_T("y")) axis_id=1;
                    else axis_id=2;

                    global->xmlaxis[global->xmltable_count][axis_id].id=id;

                    for(TiXmlElement* axis_child = table_child->FirstChildElement(); axis_child; axis_child = axis_child->NextSiblingElement())
                    {
                        wxString axis_value(axis_child->Value(), wxConvUTF8);
                        wxString axis_text(axis_child->GetText(), wxConvUTF8);

                        if (axis_value==_T("flags"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].flags=(unsigned short)HEX2Int(axis_text);
                        }
                        else if (axis_value==_T("address"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].address=HEX2Int(axis_text);
                        }
                        else if (axis_value==_T("bits"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].bits=(unsigned short)atoi(axis_text.mb_str());
                        }
                        else if (axis_value==_T("units"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].units=axis_text;
                        }
                        else if (axis_value==_T("decimalpl"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].decimalpl=(unsigned short)atoi(axis_text.mb_str());
                        }
                        /*
                        else if (axis_value==_T("min"))
                        {
                            if (!axis_text.ToDouble(&global->xmlaxis[global->xmltable_count][axis_id].min))
                                global->xmlaxis[global->xmltable_count][axis_id].min=0;
                        }
                        else if (axis_value==_T("max"))
                        {
                            if (!axis_text.ToDouble(&global->xmlaxis[global->xmltable_count][axis_id].max))
                                global->xmlaxis[global->xmltable_count][axis_id].max=65535;
                        }
                        */
                        else if (axis_value==_T("count"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].count=(unsigned short)atoi(axis_text.mb_str());
                        }
                        else if (axis_value==_T("outputtype"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].outputtype=(unsigned short)atoi(axis_text.mb_str());
                        }
                        /*
                        else if (axis_value==_T("datatype"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].datatype=(unsigned short)atoi(axis_text.mb_str());
                        }
                        else if (axis_value==_T("unittype"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].unittype=(unsigned short)atoi(axis_text.mb_str());
                        }
                        */
                        else if (axis_value==_T("embeddedinfotype"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].embeddedinfotype=(unsigned short)atoi(axis_text.mb_str());
                        }
                        else if (axis_value==_T("embeddedinfolabel"))
                        {
                            global->xmlaxis[global->xmltable_count][axis_id].embeddedinfolabel[strtoul(axis_child->Attribute("index"),NULL,0)]=atof(axis_child->Attribute("value"));
                        }
                        else if (axis_value==_T("factor"))
                        {
                            if (!axis_text.ToDouble(&global->xmlaxis[global->xmltable_count][axis_id].factor))
                                global->xmlaxis[global->xmltable_count][axis_id].factor=1;
                        }
                        else if (axis_value==_T("offset"))
                        {
                            if (!axis_text.ToDouble(&global->xmlaxis[global->xmltable_count][axis_id].offset))
                                global->xmlaxis[global->xmltable_count][axis_id].offset=0;
                        }
                    }
                }
            }

            if (map_viewer_frm != NULL)
            {
                map_viewer_frm->AddTable(global->xmltable[global->xmltable_count].title,
                                        global->xmlaxis[global->xmltable_count][0].count,
                                        global->xmlaxis[global->xmltable_count][1].count,
                                        Int2HEX(global->xmlaxis[global->xmltable_count][2].address));
            }

            global->xmltable_count++;
        }
        else if (parent==_T("CHECKSUM"))
        {
            for(TiXmlElement* checksum_child = pChild->FirstChildElement(); checksum_child; checksum_child = checksum_child->NextSiblingElement())
            {
                wxString checksum_value(checksum_child->Value(), wxConvUTF8);
                wxString checksum_text(checksum_child->GetText(), wxConvUTF8);

                if (checksum_value==_T("title"))
                {
                    global->xmlchecksum.title=checksum_text;
                }
                else if (checksum_value==_T("pluginid"))
                {
                    global->xmlchecksum.pluginid=(unsigned short)atoi(checksum_text.mb_str());
                }
            }
        }
    }

    // Show dialog
    if (map_viewer_frm == NULL)
    {
        wxCommandEvent event;
        OnMenuItem_MapViewerSelected(event);
    }
    else
        map_viewer_frm->Show();

    return (true);
}

/// ---------------------------------------------------------------------------
/// Buffer Functions
/// ---------------------------------------------------------------------------

unsigned int CrossTunerStudioFrame::ReadBINfromHD(unsigned short selected_buffer, wxString *filename, wxString *path, bool ui_enabled)
{
    if (ui_enabled)
    {
        // Open file dialog window
        wxFileDialog *FileDialog = new wxFileDialog(this, _("Select BIN file to load"), wxEmptyString, wxEmptyString, wxT("BIN files (*.bin)|*.bin|ORI files (*.ori)|*.ori|MOD files (*.mod)|*.mod|All files (*.*)|*.*"), wxFD_DEFAULT_STYLE|wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

        if (FileDialog->ShowModal() == wxID_CANCEL)
        {
            delete FileDialog;
            return (0);
        }

        *path=FileDialog->GetPath();
        *filename=FileDialog->GetFilename();
    }

    if (wxFileExists(*path))
    {
        // Open file in binary mode
        wxFFile fp((const wxChar*)*path,(const wxChar*)_T("rb"));

        // Get file length
        wxFileOffset bin_length=fp.Length();
        if ((bin_length == wxInvalidOffset) || ((unsigned int)bin_length > MAX_BUFFER_LENGTH))
        {
            StatusBar->SetStatusText(_("File size error!"),1);
            return (0);
        }

        // Allocate buffer
        void *tmp_buffer = realloc(global->bin_buffer[selected_buffer], (size_t)bin_length);
        if (!tmp_buffer)
        {
            StatusBar->SetStatusText(_("Buffer reallocation error!"),1);
            return (0);
        }
        global->bin_buffer[selected_buffer]=(unsigned char *)tmp_buffer;

        // Read data into buffer
        size_t read_length=fp.Read(global->bin_buffer[selected_buffer], (size_t)bin_length);
        if (read_length != (size_t)bin_length)
        {
            StatusBar->SetStatusText(_("File read error!"),1);
            return (0);
        }

        fp.Close();

        StatusBar->SetStatusText(_("File loaded successfully."),1);

        return((unsigned int)read_length);
    }

    StatusBar->SetStatusText(_("File not found!"),1);
    return (0);
}

void CrossTunerStudioFrame::WriteBINtoHD(unsigned char *buffer, unsigned int length, wxString path)
{
    if ((buffer==NULL) || (!length))
    {
        StatusBar->SetStatusText(_("Buffer empty error!"),1);
        return;
    }

    // Open file in binary mode
    wxFFile fp((const wxChar*)path,(const wxChar*)_T("wb"));

    size_t write_length=fp.Write(buffer, (size_t)length);
    if ( write_length != (size_t)length)
    {
        StatusBar->SetStatusText(_("File write error!"),1);
        return;
    }

    fp.Close();

    StatusBar->SetStatusText(_("File saved successfully."),1);
}

void CrossTunerStudioFrame::WriteBINtoHDas(unsigned char *buffer, unsigned int length)
{
    if ((buffer==NULL) || (!length))
    {
        StatusBar->SetStatusText(_("Buffer empty error!"),1);
        return;
    }

    // Open file dialog window
    wxFileDialog *FileDialog = new wxFileDialog(this, _("Select save location & filename"), wxEmptyString, wxEmptyString, wxT("BIN files (*.bin)|*.bin|ORI files (*.ori)|*.ori|MOD files (*.mod)|*.mod|All files (*.*)|*.*"), wxFD_DEFAULT_STYLE|wxFD_SAVE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));

    if (FileDialog->ShowModal() == wxID_CANCEL)
    {
        delete FileDialog;
        return;
    }

    // Open file in binary mode
    wxFFile fp((const wxChar*)FileDialog->GetPath(),(const wxChar*)_T("wb"));

    size_t write_length=fp.Write(buffer, (size_t)length);
    if ( write_length != (size_t)length)
    {
        StatusBar->SetStatusText(_("File write error!"),1);
        return;
    }

    fp.Close();

    StatusBar->SetStatusText(_("File saved successfully."),1);
}

unsigned int CrossTunerStudioFrame::CopyBuffer(unsigned char *buffer1, unsigned short dest_buffer, unsigned int length)
{
    if ((buffer1==NULL) || (!length))
    {
        StatusBar->SetStatusText(_("Buffer empty error!"),1);
        return (0);
    }

    // Allocate buffer
    void *tmp_buffer = realloc(global->bin_buffer[dest_buffer], (size_t)length);
    if (!tmp_buffer)
    {
        StatusBar->SetStatusText(_("Buffer reallocation error!"),1);
        return (0);
    }
    global->bin_buffer[dest_buffer]=(unsigned char *)tmp_buffer;

    for(unsigned int x=0; x < length; x++)
        global->bin_buffer[dest_buffer][x]=buffer1[x];

    return(length);
}

/// ---------------------------------------------------------------------------
/// CRC Functions
/// ---------------------------------------------------------------------------

unsigned char CrossTunerStudioFrame::CRC8(unsigned char *buffer, unsigned int length)
{
    unsigned char crc=0xff;

    for (unsigned int x=0; x < length; x++)
        crc=crc8_lookup_table[crc ^ buffer[x]];

    return (crc);
}

unsigned short CrossTunerStudioFrame::CRC16(unsigned char *buffer, unsigned int length)
{
    unsigned short crc=0xffff;

    for (unsigned int x=0; x < length; x++)
        crc=(crc >> 8) ^ crc16_lookup_table[buffer[x] ^ (crc & 0x00ff)];

    return (crc);
}

unsigned int CrossTunerStudioFrame::CRC32(unsigned char *buffer, unsigned int length)
{
    unsigned int crc=0xffffffff;

    for (unsigned int x=0; x < length; x++)
        crc=(crc >> 8) ^ crc32_lookup_table[buffer[x] ^ (crc & 0x000000ff)];

    return (crc);
}

/// ---------------------------------------------------------------------------
/// Number to HEX convertion Functions
/// ---------------------------------------------------------------------------

wxString CrossTunerStudioFrame::Int2HEX(unsigned int number)
{
    char buffer[9];

    sprintf(buffer,"%X",number);
    wxString sHex(buffer, wxConvUTF8);

    return (sHex);
}

unsigned int CrossTunerStudioFrame::HEX2Int(wxString hex)
{
    char text[11];

    strncpy(text,hex.mb_str(),10);

    return (strtoul (text,NULL,0));
}

/// ---------------------------------------------------------------------------
/// Misc. Functions
/// ---------------------------------------------------------------------------

void CrossTunerStudioFrame::LoadDefaults(void)
{
    wxString filename, path;

    wxConfig config(_T("CrossTunerStudio"),_T("MTX Electronics"));

    // Read BIN1
    if (config.Read(_T("/OpenFiles/Bin1Path"), &path))
    {
        if (config.Read(_T("/OpenFiles/Bin1Filename"), &filename))
        {
            unsigned int length=ReadBINfromHD(0,&filename,&path, false);

            if (length > 0)
            {
                global->bin_length[0]=length;
                global->bin_filename[0]=filename;
                global->bin_path[0]=path;

                TextCtrlBIN1->SetValue(filename);
                StaticText_Size1->SetLabel(wxString::Format(wxT("%i"),length));
                StaticText_CHK8_1->SetLabel(_("0x") + Int2HEX(CRC8(global->bin_buffer[0],length)));
                StaticText_CHK16_1->SetLabel(_("0x") + Int2HEX(CRC16(global->bin_buffer[0],length)));
                StaticText_CHK32_1->SetLabel(_("0x") + Int2HEX(CRC32(global->bin_buffer[0],length)));
            }
        }
    }

    // Read BIN2
    if (config.Read(_T("/OpenFiles/Bin2Path"), &path))
    {
        if (config.Read(_T("/OpenFiles/Bin2Filename"), &filename))
        {
            unsigned int length=ReadBINfromHD(1,&filename,&path, false);

            if (length > 0)
            {
                global->bin_length[1]=length;
                global->bin_filename[1]=filename;
                global->bin_path[1]=path;

                TextCtrlBIN2->SetValue(filename);
                StaticText_Size2->SetLabel(wxString::Format(wxT("%i"),length));
                StaticText_CHK8_2->SetLabel(_("0x") + Int2HEX(CRC8(global->bin_buffer[1],length)));
                StaticText_CHK16_2->SetLabel(_("0x") + Int2HEX(CRC16(global->bin_buffer[1],length)));
                StaticText_CHK32_2->SetLabel(_("0x") + Int2HEX(CRC32(global->bin_buffer[1],length)));
            }
        }
    }

    // Read BIN3
    if (config.Read(_T("/OpenFiles/Bin3Path"), &path))
    {
        if (config.Read(_T("/OpenFiles/Bin3Filename"), &filename))
        {
            unsigned int length=ReadBINfromHD(2,&filename,&path, false);

            if (length > 0)
            {
                global->bin_length[2]=length;
                global->bin_filename[2]=filename;
                global->bin_path[2]=path;

                TextCtrlBIN3->SetValue(filename);
                StaticText_Size3->SetLabel(wxString::Format(wxT("%i"),length));
                StaticText_CHK8_3->SetLabel(_("0x") + Int2HEX(CRC8(global->bin_buffer[2],length)));
                StaticText_CHK16_3->SetLabel(_("0x") + Int2HEX(CRC16(global->bin_buffer[2],length)));
                StaticText_CHK32_3->SetLabel(_("0x") + Int2HEX(CRC32(global->bin_buffer[2],length)));
            }
        }
    }

    // Read Maps
    if (config.Read(_T("/OpenFiles/MapsPath"), &path))
    {
        if (LoadDefinitionFileFromHD(path))
        {
            StatusBar->SetStatusText(_("Maps file loaded."),1);
        }
    }

    // Set Position of CrossTunerStudioFrame
    int x,y,w,h;
    if (config.Read(_T("/WindowPositions/CrossTunerStudioFrameX"), &x))
    {
        if (config.Read(_T("/WindowPositions/CrossTunerStudioFrameY"), &y))
        {
            this->SetPosition(wxPoint(x,y));
        }
    }

    // Set Position of MapViewerDialog
    if (map_viewer_frm != NULL)
    {
        if (config.Read(_T("/WindowPositions/MapViewerFrameX"), &x))
        {
            if (config.Read(_T("/WindowPositions/MapViewerFrameY"), &y))
            {
                map_viewer_frm->SetPosition(wxPoint(x,y));
            }
        }

        if (config.Read(_T("/WindowPositions/MapViewerFrameW"), &w))
        {
            if (config.Read(_T("/WindowPositions/MapViewerFrameH"), &h))
            {
                map_viewer_frm->SetSize(w,h);
            }
        }
    }
}

unsigned short CrossTunerStudioFrame::SelectedBin(void)
{
    unsigned short value=0;

    if (RadioButton_SelectBIN1->GetValue())
        value=0;
    else if (RadioButton_SelectBIN2->GetValue())
        value=1;
    else
        value=2;

    global->selected_bin=value;

    return (value);
}

/*
void CrossTunerStudioFrame::SetStatusBarText(wxString msg, int panel)
{
    StatusBar->SetStatusText(msg,panel);
}
*/

void CrossTunerStudioFrame::OnRadioButton_SelectBIN1Select(wxCommandEvent& event)
{
    global->selected_bin=0;
}

void CrossTunerStudioFrame::OnRadioButton_SelectBIN2Select(wxCommandEvent& event)
{
    global->selected_bin=1;
}

void CrossTunerStudioFrame::OnRadioButton_SelectBIN3Select(wxCommandEvent& event)
{
    global->selected_bin=2;
}

