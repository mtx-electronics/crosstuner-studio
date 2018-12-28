/***************************************************************
 * Name:      CrossTunerStudioMain.h
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
 
#ifndef CROSSTUNERSTUDIOMAIN_H
#define CROSSTUNERSTUDIOMAIN_H

//(*Headers(CrossTunerStudioFrame)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/radiobut.h>
#include <wx/toolbar.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

#include "GlobalVariables.h"

#define APP_VERSION     "0.3.3 [Beta]"
#define APP_DATE        "2011-2012"

class CrossTunerStudioFrame: public wxFrame
{
    public:

        CrossTunerStudioFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~CrossTunerStudioFrame();

        bool LoadDefinitionFileFromHD(wxString path);
        void LoadDefaults(void);

        unsigned int ReadBINfromHD(unsigned short selected_buffer, wxString *filename, wxString *path, bool ui_enabled);
        void WriteBINtoHD(unsigned char *buffer, unsigned int length, wxString path);
        void WriteBINtoHDas(unsigned char *buffer, unsigned int length);

        unsigned int CopyBuffer(unsigned char *buffer1, unsigned short dest_buffer, unsigned int length);

        unsigned char CRC8(unsigned char *buffer, unsigned int length);
        unsigned short CRC16(unsigned char *buffer, unsigned int length);
        unsigned int CRC32(unsigned char *buffer, unsigned int length);

        wxString Int2HEX(unsigned int number);
        unsigned int HEX2Int(wxString hex);

        unsigned short SelectedBin(void);
        //void SetStatusBarText(wxString msg, int panel);

        GlobalVariables *global;

    private:

        //(*Handlers(CrossTunerStudioFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButtonBrowseBIN1Click(wxCommandEvent& event);
        void OnButtonBrowseBIN2Click(wxCommandEvent& event);
        void OnButtonBrowseBIN3Click(wxCommandEvent& event);
        void OnMenuItem_LoadBIN1Selected(wxCommandEvent& event);
        void OnMenuItem_LoadBIN2Selected(wxCommandEvent& event);
        void OnMenuItem_LoadBIN3Selected(wxCommandEvent& event);
        void OnMenuItem_SaveBIN1Selected(wxCommandEvent& event);
        void OnMenuItem_SaveBIN2Selected(wxCommandEvent& event);
        void OnMenuItem_SaveBIN3Selected(wxCommandEvent& event);
        void OnMenuItem_SaveAsBIN1Selected(wxCommandEvent& event);
        void OnMenuItem_SaveAsBIN2Selected(wxCommandEvent& event);
        void OnMenuItem_SaveAsBIN3Selected(wxCommandEvent& event);
        void OnMenuItem_CopyBIN1toBIN2Selected(wxCommandEvent& event);
        void OnMenuItem_CopyBIN1toBIN3Selected(wxCommandEvent& event);
        void OnMenuItem_CopyBIN2toBIN1Selected(wxCommandEvent& event);
        void OnMenuItem_CopyBIN2toBIN3Selected(wxCommandEvent& event);
        void OnMenuItem_CopyBIN3toBIN1Selected(wxCommandEvent& event);
        void OnMenuItem_CopyBIN3toBIN2Selected(wxCommandEvent& event);
        void OnMenuItem_MapViewerSelected(wxCommandEvent& event);
        void OnMenuItem_LoadDefinitionSelected(wxCommandEvent& event);
        void OnMenuItem_ImportTunerProSelected(wxCommandEvent& event);
        void OnMenuItem_MapEditorSelected(wxCommandEvent& event);
        void OnMenuItem_TableEditorSelected(wxCommandEvent& event);
        void OnMenuItem_SaveDefinitionsSelected(wxCommandEvent& event);
        void OnMenuItem_SaveDefinitionSelected(wxCommandEvent& event);
        void OnMenuItem_EditSelectedMapSelected(wxCommandEvent& event);
        void OnMenuItem_NewDefinitionSelected(wxCommandEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnMenuItem_AddNewMapSelected(wxCommandEvent& event);
        void OnMenuItem_DeleteSelectedMapSelected(wxCommandEvent& event);
        void OnMenuItem_DuplicateSelectedMapSelected(wxCommandEvent& event);
        void OnMenuItem_LoadBINSelected(wxCommandEvent& event);
        void OnMenuItem_SaveBINSelected(wxCommandEvent& event);
        void OnMenuItem_SaveBINasSelected(wxCommandEvent& event);
        void OnRadioButton_SelectBIN1Select(wxCommandEvent& event);
        void OnRadioButton_SelectBIN2Select(wxCommandEvent& event);
        void OnRadioButton_SelectBIN3Select(wxCommandEvent& event);
        void OnMenuItem_2DEditorSelected(wxCommandEvent& event);
        //*)

        void OnToolBarItem_LoadBINClicked(wxCommandEvent& event);
        void OnToolBarItem_SaveBINClicked(wxCommandEvent& event);
        void OnToolBarItem_LoadMapClicked(wxCommandEvent& event);
        void OnToolBarItem_MapViewerClicked(wxCommandEvent& event);
        void OnToolBarItem_MapEditorClicked(wxCommandEvent& event);
        void OnToolBarItem_TableEditorClicked(wxCommandEvent& event);
        void OnToolBarItem_2DEditorClicked(wxCommandEvent& event);
        //void OnToolBarItem_PreferencesClicked(wxCommandEvent& event);
        void OnToolBarItem_AboutClicked(wxCommandEvent& event);
        void OnToolBarItem_QuitClicked(wxCommandEvent& event);

        //(*Identifiers(CrossTunerStudioFrame)
        static const long ID_RADIOBUTTON1;
        static const long ID_TEXTCTRL4;
        static const long ID_BUTTON3;
        static const long ID_STATICTEXT47;
        static const long ID_STATICTEXT46;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT10;
        static const long ID_STATICTEXT11;
        static const long ID_STATICTEXT12;
        static const long ID_STATICTEXT13;
        static const long ID_STATICTEXT14;
        static const long ID_RADIOBUTTON2;
        static const long ID_TEXTCTRL3;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT49;
        static const long ID_STATICTEXT48;
        static const long ID_STATICTEXT15;
        static const long ID_STATICTEXT16;
        static const long ID_STATICTEXT17;
        static const long ID_STATICTEXT18;
        static const long ID_STATICTEXT19;
        static const long ID_STATICTEXT20;
        static const long ID_STATICTEXT21;
        static const long ID_STATICTEXT22;
        static const long ID_STATICTEXT23;
        static const long ID_STATICTEXT24;
        static const long ID_STATICTEXT25;
        static const long ID_STATICTEXT26;
        static const long ID_STATICTEXT27;
        static const long ID_STATICTEXT28;
        static const long ID_RADIOBUTTON3;
        static const long ID_TEXTCTRL2;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT51;
        static const long ID_STATICTEXT50;
        static const long ID_STATICTEXT29;
        static const long ID_STATICTEXT30;
        static const long ID_STATICTEXT31;
        static const long ID_STATICTEXT32;
        static const long ID_STATICTEXT33;
        static const long ID_STATICTEXT34;
        static const long ID_STATICTEXT35;
        static const long ID_STATICTEXT36;
        static const long ID_STATICTEXT37;
        static const long ID_STATICTEXT38;
        static const long ID_STATICTEXT39;
        static const long ID_STATICTEXT40;
        static const long ID_STATICTEXT41;
        static const long ID_STATICTEXT42;
        static const long ID_PANEL1;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM4;
        static const long ID_MENUITEM7;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM5;
        static const long ID_MENUITEM6;
        static const long idMenuQuit;
        static const long ID_MENUITEM23;
        static const long ID_MENUITEM20;
        static const long ID_MENUITEM24;
        static const long ID_MENUITEM29;
        static const long ID_MENUITEM30;
        static const long ID_MENUITEM31;
        static const long ID_MENUITEM32;
        static const long ID_MENUITEM22;
        static const long ID_MENUITEM21;
        static const long ID_MENUITEM25;
        static const long ID_MENUITEM28;
        static const long ID_MENUITEM19;
        static const long ID_MENUITEM10;
        static const long ID_MENUITEM11;
        static const long ID_MENUITEM12;
        static const long ID_MENUITEM13;
        static const long ID_MENUITEM14;
        static const long ID_MENUITEM15;
        static const long ID_MENUITEM16;
        static const long ID_MENUITEM27;
        static const long ID_MENUITEM18;
        static const long ID_MENUITEM26;
        static const long ID_MENUITEM33;
        static const long ID_MENUITEM17;
        static const long ID_MENUITEM8;
        static const long ID_MENUITEM9;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_TOOLBAR1;
        //*)

        static const long ID_TOOLBARITEM1;
        static const long ID_TOOLBARITEM2;
        static const long ID_TOOLBARITEM3;
        static const long ID_TOOLBARITEM4;
        static const long ID_TOOLBARITEM5;
        static const long ID_TOOLBARITEM6;
        static const long ID_TOOLBARITEM7;
        static const long ID_TOOLBARITEM8;
        static const long ID_TOOLBARITEM9;
        static const long ID_TOOLBARITEM10;

        //(*Declarations(CrossTunerStudioFrame)
        wxStaticText* StaticText10;
        wxMenu* MenuItem_Import;
        wxStaticText* StaticText9;
        wxMenuItem* MenuItem_DuplicateSelectedMap;
        wxMenu* MenuItem_Buffers;
        wxStaticText* StaticText_CHKType1;
        wxMenuItem* MenuItem_MapViewer;
        wxRadioButton* RadioButton_SelectBIN3;
        wxStaticText* StaticText_CHK32_1;
        wxRadioButton* RadioButton_SelectBIN2;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem_TableEditor;
        wxStaticText* StaticText_CHKType3;
        wxMenuItem* MenuItem_SaveMaps;
        wxStaticText* StaticText29;
        wxStaticText* StaticText_ECU2;
        wxMenu* Menu_Maps;
        wxStaticText* StaticText37;
        wxMenuItem* MenuItem_CopyBIN3toBIN1;
        wxMenuItem* MenuItem5;
        wxStaticText* StaticText33;
        wxStaticText* StaticText13;
        wxMenuItem* Menu2;
        wxStaticText* StaticText_CHKType2;
        wxStaticText* StaticText2;
        wxMenuItem* MenuItem_SaveBIN;
        wxMenuItem* MenuItem2;
        wxMenuItem* MenuItem_CopyBIN1toBIN2;
        wxStaticText* StaticText_CHK16_3;
        wxStaticText* StaticText_CHK32_3;
        wxMenu* Menu3;
        wxStaticText* StaticText6;
        wxMenu* MenuItem3;
        wxMenuItem* MenuItem_LoadBIN;
        wxMenuItem* MenuItem1;
        wxStaticText* StaticText_CHK8_2;
        wxMenuItem* MenuItem4;
        wxTextCtrl* TextCtrlBIN3;
        wxStaticText* StaticText19;
        wxStaticText* StaticText11;
        wxStaticText* StaticText_CHK16_2;
        wxRadioButton* RadioButton_SelectBIN1;
        wxMenuItem* MenuItem_SaveBINas;
        wxPanel* Panel1;
        wxStaticText* StaticText31;
        wxStaticText* StaticText1;
        wxStaticText* StaticText27;
        wxMenuItem* MenuItem_CopyBIN3toBIN2;
        wxStaticText* StaticText3;
        wxMenuItem* MenuItem_ImportTunerPro;
        wxMenu* Menu1;
        wxMenuItem* MenuItem_2DEditor;
        wxStaticText* StaticText39;
        wxStaticText* StaticText21;
        wxStaticText* StaticText23;
        wxStaticText* StaticText_Size3;
        wxButton* ButtonBrowseBIN3;
        wxMenuItem* MenuItem_NewMaps;
        wxMenuItem* MenuItem_Export_MapData;
        wxStaticText* StaticText_CHK8_1;
        wxMenuItem* MenuItem_DeleteSelectedMap;
        wxStaticText* StaticText5;
        wxStaticText* StaticText7;
        wxMenu* Menu7;
        wxStaticText* StaticText_SW1;
        wxMenuItem* MenuItem_EditSelectedMap;
        wxStaticText* StaticText_CHK32_2;
        wxMenuItem* MenuItem6;
        wxMenuItem* MenuItem_CopyBIN1toBIN3;
        wxMenuItem* MenuItem_AddNewMap;
        wxMenuItem* MenuItem_CopyBIN2toBIN3;
        wxStaticText* StaticText41;
        wxStaticText* StaticText_HW3;
        wxMenuItem* MenuItem_LoadMaps;
        wxStaticText* StaticText_CHK8_3;
        wxStaticText* StaticText15;
        wxMenuItem* Menu6;
        wxStaticText* StaticText35;
        wxButton* ButtonBrowseBIN2;
        wxStaticText* StaticText_CHK16_1;
        wxMenuItem* MenuItem_CopyBIN2toBIN1;
        wxStaticText* StaticText25;
        wxTextCtrl* TextCtrlBIN2;
        wxToolBar* ToolBar;
        wxStaticText* StaticText17;
        wxMenuItem* MenuItem_ExportMapList;
        wxStaticText* StaticText_Size1;
        wxStatusBar* StatusBar;
        wxStaticText* StaticText_SW3;
        wxButton* ButtonBrowseBIN1;
        wxStaticText* StaticText_HW2;
        wxStaticText* StaticText_HW1;
        wxMenu* Menu5;
        wxStaticText* StaticText_Size2;
        wxMenu* Menu4;
        wxStaticText* StaticText_ECU3;
        wxTextCtrl* TextCtrlBIN1;
        wxStaticText* StaticText_SW2;
        wxStaticText* StaticText_ECU1;
        //*)

        wxToolBarToolBase* ToolBarItem1;
        wxToolBarToolBase* ToolBarItem2;
        wxToolBarToolBase* ToolBarItem3;
        wxToolBarToolBase* ToolBarItem4;
        wxToolBarToolBase* ToolBarItem5;
        wxToolBarToolBase* ToolBarItem6;
        wxToolBarToolBase* ToolBarItem7;
        wxToolBarToolBase* ToolBarItem8;
        wxToolBarToolBase* ToolBarItem9;
        wxToolBarToolBase* ToolBarItem10;

        DECLARE_EVENT_TABLE()
};

#endif // CROSSTUNERSTUDIOMAIN_H
