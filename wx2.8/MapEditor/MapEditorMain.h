/***************************************************************
 * Name:      MapEditorMain.h
 * Purpose:   Defines Application Frame
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
 
#ifndef MAPEDITORMAIN_H
#define MAPEDITORMAIN_H

//(*Headers(MapEditorDialog)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/grid.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/combobox.h>
//*)

#include "../GlobalVariables.h"
#include "../CrossTunerStudioMain.h"

class MapEditorDialog: public wxDialog
{
    public:

        MapEditorDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~MapEditorDialog();

        void NewEditor(unsigned short selected_map, GlobalVariables *gv);
        void UpdateEditor(unsigned short selected_map, GlobalVariables *gv);
        bool GetExitStatus(void) const { return exit_status; };

        void Update_XGrid(void);
        void Update_YGrid(void);

        double GetEngineeringValueFromAddress(unsigned char *buffer, unsigned int address, unsigned short axis);
        double GetEngineeringValueFromAddress2(unsigned char *buffer, unsigned short flags, unsigned int address, unsigned short bits, unsigned short decimalpl, double factor, double offset);
        unsigned int IncrementAddress(unsigned int address, unsigned short axis);
        unsigned int IncrementAddress2(unsigned int address, unsigned short bits);
        double RoundDouble(double value, int places);

        wxString Int2HEX(unsigned int number);
        unsigned int HEX2Int(wxString hex);

        GlobalVariables *global;
        unsigned short current_map;
        bool exit_status;

    private:

        //(*Handlers(MapEditorDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton_ApplyClick(wxCommandEvent& event);
        void OnButton_CancelClick(wxCommandEvent& event);
        void OnChoice_XSourceSelect(wxCommandEvent& event);
        void OnChoice_YSourceSelect(wxCommandEvent& event);
        void OnTextCtrl_XCountText(wxCommandEvent& event);
        void OnTextCtrl_YCountText(wxCommandEvent& event);
        void OnComboBox_XUnitsTextUpdated(wxCommandEvent& event);
        void OnComboBox_YUnitsTextUpdated(wxCommandEvent& event);
        void OnTextCtrl_XAddressText(wxCommandEvent& event);
        void OnChoice_XSignSelect(wxCommandEvent& event);
        void OnChoice_XBitsSelect(wxCommandEvent& event);
        void OnChoice_XByteOrderSelect(wxCommandEvent& event);
        void OnChoice_XTypeSelect(wxCommandEvent& event);
        void OnChoice_XDecimalsSelect(wxCommandEvent& event);
        void OnTextCtrl_XOffsetText(wxCommandEvent& event);
        void OnTextCtrl_XFactorText(wxCommandEvent& event);
        void OnChoice_YTypeSelect(wxCommandEvent& event);
        void OnChoice_YDecimalsSelect(wxCommandEvent& event);
        void OnTextCtrl_YOffsetText(wxCommandEvent& event);
        void OnTextCtrl_YFactorText(wxCommandEvent& event);
        void OnTextCtrl_YAddressText(wxCommandEvent& event);
        void OnChoice_YSignSelect(wxCommandEvent& event);
        void OnChoice_YBitsSelect(wxCommandEvent& event);
        void OnChoice_YByteOrderSelect(wxCommandEvent& event);
        //*)

        //(*Identifiers(MapEditorDialog)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT35;
        static const long ID_STATICTEXT36;
        static const long ID_TEXTCTRL5;
        static const long ID_TEXTCTRL9;
        static const long ID_STATICTEXT37;
        static const long ID_CHOICE19;
        static const long ID_PANEL4;
        static const long ID_STATICTEXT9;
        static const long ID_COMBOBOX3;
        static const long ID_STATICTEXT10;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT11;
        static const long ID_CHOICE6;
        static const long ID_STATICTEXT12;
        static const long ID_TEXTCTRL6;
        static const long ID_STATICTEXT13;
        static const long ID_TEXTCTRL7;
        static const long ID_PANEL11;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT5;
        static const long ID_CHOICE2;
        static const long ID_STATICTEXT6;
        static const long ID_CHOICE3;
        static const long ID_STATICTEXT7;
        static const long ID_CHOICE4;
        static const long ID_STATICTEXT8;
        static const long ID_CHOICE5;
        static const long ID_PANEL6;
        static const long ID_GRID3;
        static const long ID_PANEL3;
        static const long ID_STATICTEXT14;
        static const long ID_TEXTCTRL8;
        static const long ID_STATICTEXT15;
        static const long ID_COMBOBOX1;
        static const long ID_STATICTEXT16;
        static const long ID_CHOICE7;
        static const long ID_STATICTEXT17;
        static const long ID_CHOICE8;
        static const long ID_STATICTEXT18;
        static const long ID_TEXTCTRL10;
        static const long ID_STATICTEXT19;
        static const long ID_TEXTCTRL11;
        static const long ID_PANEL8;
        static const long ID_STATICTEXT3;
        static const long ID_CHOICE9;
        static const long ID_STATICTEXT21;
        static const long ID_TEXTCTRL4;
        static const long ID_STATICTEXT20;
        static const long ID_CHOICE11;
        static const long ID_STATICTEXT22;
        static const long ID_CHOICE10;
        static const long ID_STATICTEXT24;
        static const long ID_CHOICE12;
        static const long ID_PANEL5;
        static const long ID_GRID1;
        static const long ID_PANEL1;
        static const long ID_STATICTEXT23;
        static const long ID_TEXTCTRL12;
        static const long ID_STATICTEXT25;
        static const long ID_COMBOBOX2;
        static const long ID_STATICTEXT26;
        static const long ID_CHOICE13;
        static const long ID_STATICTEXT27;
        static const long ID_CHOICE14;
        static const long ID_STATICTEXT28;
        static const long ID_TEXTCTRL14;
        static const long ID_STATICTEXT29;
        static const long ID_TEXTCTRL15;
        static const long ID_PANEL9;
        static const long ID_STATICTEXT30;
        static const long ID_CHOICE15;
        static const long ID_STATICTEXT31;
        static const long ID_TEXTCTRL16;
        static const long ID_STATICTEXT32;
        static const long ID_CHOICE16;
        static const long ID_STATICTEXT33;
        static const long ID_CHOICE17;
        static const long ID_STATICTEXT34;
        static const long ID_CHOICE18;
        static const long ID_PANEL10;
        static const long ID_GRID2;
        static const long ID_PANEL2;
        static const long ID_NOTEBOOK1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON3;
        //*)

        //(*Declarations(MapEditorDialog)
        wxStaticText* StaticText10;
        wxStaticText* StaticText22;
        wxStaticText* StaticText9;
        wxTextCtrl* TextCtrl_XFactor;
        wxChoice* Choice_ByteOrder;
        wxStaticText* StaticText20;
        wxComboBox* ComboBox_XUnits;
        wxChoice* Choice_YType;
        wxPanel* Panel5;
        wxChoice* Choice_YByteOrder;
        wxPanel* Panel_XAxis;
        wxTextCtrl* TextCtrl_XCount;
        wxStaticText* StaticText29;
        wxTextCtrl* TextCtrl_YOffset;
        wxChoice* Choice_Bits;
        wxNotebook* Notebook1;
        wxTextCtrl* TextCtrl_Address;
        wxTextCtrl* TextCtrl_Description;
        wxTextCtrl* TextCtrl_Name;
        wxStaticText* StaticText37;
        wxChoice* Choice_XType;
        wxStaticText* StaticText33;
        wxGrid* Grid_ZGrid;
        wxStaticText* StaticText13;
        wxStaticText* StaticText2;
        wxPanel* Panel4;
        wxStaticText* StaticText30;
        wxStaticText* StaticText14;
        wxGrid* Grid_XGrid;
        wxStaticText* StaticText26;
        wxStaticText* StaticText6;
        wxPanel* Panel_ZAxis;
        wxStaticText* StaticText32;
        wxStaticText* StaticText19;
        wxStaticText* StaticText8;
        wxStaticText* StaticText11;
        wxChoice* Choice_YSource;
        wxStaticText* StaticText18;
        wxTextCtrl* TextCtrl_Version;
        wxStaticText* StaticText31;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText27;
        wxChoice* Choice_XByteOrder;
        wxStaticText* StaticText3;
        wxChoice* Choice_XSign;
        wxPanel* Panel6;
        wxStaticText* StaticText21;
        wxPanel* Panel3;
        wxButton* Button_Apply;
        wxStaticText* StaticText23;
        wxChoice* Choice_XSource;
        wxStaticText* StaticText24;
        wxPanel* Panel_Settings;
        wxChoice* Choice_Checksum;
        wxTextCtrl* TextCtrl_YFactor;
        wxTextCtrl* TextCtrl_YCount;
        wxComboBox* ComboBox_ZUnits;
        wxGrid* Grid_YGrid;
        wxStaticText* StaticText34;
        wxStaticText* StaticText5;
        wxTextCtrl* TextCtrl_XAddress;
        wxStaticText* StaticText7;
        wxTextCtrl* TextCtrl_Author;
        wxChoice* Choice_ZDecimals;
        wxButton* Button_Cancel;
        wxChoice* Choice_YBits;
        wxPanel* Panel_YAxis;
        wxChoice* Choice_Sign;
        wxTextCtrl* TextCtrl_ZFactor;
        wxStaticText* StaticText28;
        wxBoxSizer* BoxSizer1;
        wxTextCtrl* TextCtrl_XOffset;
        wxChoice* Choice_YSign;
        wxComboBox* ComboBox_YUnits;
        wxStaticText* StaticText15;
        wxStaticText* StaticText12;
        wxChoice* Choice_YDecimals;
        wxStaticText* StaticText35;
        wxChoice* Choice_XDecimals;
        wxChoice* Choice_XBits;
        wxTextCtrl* TextCtrl_ZOffset;
        wxPanel* Panel2;
        wxChoice* Choice_ZType;
        wxStaticText* StaticText25;
        wxTextCtrl* TextCtrl_YAddress;
        wxStaticText* StaticText17;
        wxStaticText* StaticText4;
        wxStaticText* StaticText36;
        wxStaticText* StaticText16;
        wxChoice* Choice_DataOrder;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // MAPEDITORMAIN_H
