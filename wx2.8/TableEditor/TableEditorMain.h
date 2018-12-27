/***************************************************************
 * Name:      TableEditorMain.h
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
 
#ifndef TABLEEDITORMAIN_H
#define TABLEEDITORMAIN_H

//(*Headers(TableEditorFrame)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/spinctrl.h>
#include <wx/radiobut.h>
#include <wx/toolbar.h>
#include <wx/panel.h>
#include <wx/grid.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

#include "simpleChart.h"
#include "../GlobalVariables.h"

#define OPERATION_ADD       0
#define OPERATION_SUB       1

class TableEditorFrame: public wxFrame
{
    public:

        TableEditorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~TableEditorFrame();

        void Init(unsigned short bin, unsigned short selected_map, GlobalVariables *gv);

        void UpdateGridAxis(void);
        void UpdateGrid(void);
        void UpdateGridDifferences(void);
        void UpdateCellValue(int x, int y, unsigned int address);

        void SetRawValueToGrid(int x, int y, unsigned short axis, int value);
        void SetEngineeringValueToGrid(int x, int y, unsigned short axis, double value);
        int GetRawValueFromAddress(unsigned char *buffer, unsigned int address, unsigned short axis);
        void SetRawValueToAddress(unsigned char *buffer, unsigned int address, unsigned short axis, int raw_value);
        double GetEngineeringValueFromAddress(unsigned char *buffer, unsigned int address, unsigned short axis);
        void SetEngineeringValueToAddress(unsigned char *buffer, unsigned int address, unsigned short axis, double eng_value);

        double RoundDouble(double value, int places);
        unsigned int ConvertXYToAddress(int x, int y);
        unsigned int IncrementAddress(unsigned int address, unsigned short axis);

        unsigned short CalculateRaw(unsigned short operation);
        unsigned short CalculatePercentage(unsigned short operation);
        unsigned short CalculateEngineering(unsigned short operation);

        int GetSelectedDifferenceBin(void);
        void SetCaption(void);

        unsigned short selected_bin, current_map;
        unsigned char *temp_buffer;

        GlobalVariables *global;

    private:

        //(*Handlers(TableEditorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnGridCellChange(wxGridEvent& event);
        void OnMenuItem_ApplySelected(wxCommandEvent& event);
        void OnMenuItem_CancelSelected(wxCommandEvent& event);
        void OnBitmapButton_EngAddClick(wxCommandEvent& event);
        void OnMenuItem_CellColorsSelected(wxCommandEvent& event);
        void OnMenuItem_2DViewSelected(wxCommandEvent& event);
        void OnMenuItem_ViewControlsSelected(wxCommandEvent& event);
        void OnBitmapButton_EngSubClick(wxCommandEvent& event);
        void OnGridCellSelect(wxGridEvent& event);
        void OnGridLeftUp(wxMouseEvent& event);
        void OnGridMouseMove(wxMouseEvent& event);
        void OnBitmapButton_SelectionInfoClick(wxCommandEvent& event);
        void OnBitmapButton_RawAddClick(wxCommandEvent& event);
        void OnBitmapButton_RawSubClick(wxCommandEvent& event);
        void OnBitmapButton_PercAddClick(wxCommandEvent& event);
        void OnBitmapButton_PercSubClick(wxCommandEvent& event);
        void OnMenuItem_IncRawSelected(wxCommandEvent& event);
        void OnMenuItem_DecRawSelected(wxCommandEvent& event);
        void OnMenuItem_IncPercSelected(wxCommandEvent& event);
        void OnMenuItem_DecPercSelected(wxCommandEvent& event);
        void OnMenuItem_IncEngSelected(wxCommandEvent& event);
        void OnMenuItem_DecEngSelected(wxCommandEvent& event);
        void OnMenuItem_FillValueSelected(wxCommandEvent& event);
        void OnButton_FillValueClick(wxCommandEvent& event);
        void OnButton_SelectValueClick(wxCommandEvent& event);
        void OnMenuItem_SelectAllSelected(wxCommandEvent& event);
        void OnMenuItem_InvertSelectionsSelected(wxCommandEvent& event);
        void OnMenuItem_Select_NoneSelected(wxCommandEvent& event);
        void OnMenuItem_SelectValueSelected(wxCommandEvent& event);
        void OnGridCellSelect1(wxGridEvent& event);
        void OnMenuItem_SelctCompareBIN1Selected(wxCommandEvent& event);
        void OnMenuItem_SelectCompareBIN2Selected(wxCommandEvent& event);
        void OnMenuItem_SelectCompareBIN3Selected(wxCommandEvent& event);
        void OnMenuItem_ShowDifferencesSelected(wxCommandEvent& event);
        void OnMenuItem_ShowRawValuesSelected(wxCommandEvent& event);
        void OnMenuItem_HighlightDifferencesSelected(wxCommandEvent& event);
        void OnMenuItem_SelectCompareBIN1Selected(wxCommandEvent& event);
        void OnResize(wxSizeEvent& event);
        void OnButton_SelectGreaterValueClick(wxCommandEvent& event);
        void OnMenuItem_SelectGreaterValueSelected(wxCommandEvent& event);
        void OnButton_InterpolationClick(wxCommandEvent& event);
        void OnMenuItem5Selected(wxCommandEvent& event);
        void OnMenuItem_3DViewerSelected(wxCommandEvent& event);
        void OnMenuItem_CopySelected(wxCommandEvent& event);
        void OnMenuItem_PasteSelected(wxCommandEvent& event);
        void OnResize1(wxSizeEvent& event);
        //*)

        void OnToolBarItem_ApplyClicked(wxCommandEvent& event);
        void OnToolBarItem_CancelClicked(wxCommandEvent& event);
        void OnToolBarItem_CopyClicked(wxCommandEvent& event);
        void OnToolBarItem_PasteClicked(wxCommandEvent& event);
        void OnToolBarItem_DifferenceClicked(wxCommandEvent& event);
        void OnToolBarItem_HighlightClicked(wxCommandEvent& event);
        //void OnToolBarItem_2DEditClicked(wxCommandEvent& event);
        void OnToolBarItem_3DViewClicked(wxCommandEvent& event);

        //(*Identifiers(TableEditorFrame)
        static const long ID_STATICTEXT4;
        static const long ID_GRID1;
        static const long ID_PANEL6;
        static const long ID_RADIOBUTTON1;
        static const long ID_SPINCTRL1;
        static const long ID_BITMAPBUTTON1;
        static const long ID_BITMAPBUTTON2;
        static const long ID_RADIOBUTTON2;
        static const long ID_TEXTCTRL1;
        static const long ID_BITMAPBUTTON3;
        static const long ID_BITMAPBUTTON4;
        static const long ID_RADIOBUTTON3;
        static const long ID_TEXTCTRL2;
        static const long ID_BITMAPBUTTON5;
        static const long ID_BITMAPBUTTON6;
        static const long ID_PANEL5;
        static const long ID_BUTTON4;
        static const long ID_BUTTON2;
        static const long ID_BUTTON1;
        static const long ID_PANEL10;
        static const long ID_BITMAPBUTTON7;
        static const long ID_BITMAPBUTTON9;
        static const long ID_BITMAPBUTTON11;
        static const long ID_BITMAPBUTTON8;
        static const long ID_BITMAPBUTTON10;
        static const long ID_PANEL4;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL4;
        static const long ID_TEXTCTRL5;
        static const long ID_TEXTCTRL6;
        static const long ID_BUTTON3;
        static const long ID_PANEL9;
        static const long ID_PANEL11;
        static const long ID_PANEL7;
        static const long ID_STATICTEXT5;
        static const long ID_CUSTOM1;
        static const long ID_PANEL2;
        static const long ID_STATICTEXT6;
        static const long ID_CUSTOM2;
        static const long ID_PANEL3;
        static const long ID_PANEL8;
        static const long ID_PANEL1;
        static const long ID_MENUITEM7;
        static const long ID_MENUITEM8;
        static const long ID_MENUITEM9;
        static const long ID_MENUITEM10;
        static const long idMenuQuit;
        static const long ID_MENUITEM16;
        static const long ID_MENUITEM11;
        static const long ID_MENUITEM12;
        static const long ID_MENUITEM21;
        static const long ID_MENUITEM22;
        static const long ID_MENUITEM23;
        static const long ID_MENUITEM24;
        static const long ID_MENUITEM25;
        static const long ID_MENUITEM26;
        static const long ID_MENUITEM18;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM4;
        static const long ID_MENUITEM5;
        static const long ID_MENUITEM6;
        static const long ID_MENUITEM31;
        static const long ID_MENUITEM32;
        static const long ID_MENUITEM33;
        static const long ID_MENUITEM13;
        static const long ID_MENUITEM17;
        static const long ID_MENUITEM14;
        static const long ID_MENUITEM15;
        static const long ID_MENUITEM36;
        static const long ID_MENUITEM27;
        static const long ID_MENUITEM28;
        static const long ID_MENUITEM29;
        static const long ID_MENUITEM30;
        static const long ID_MENUITEM20;
        static const long ID_MENUITEM19;
        static const long ID_MENUITEM34;
        static const long ID_MENUITEM35;
        static const long ID_MENUITEM37;
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

        //(*Declarations(TableEditorFrame)
        wxTextCtrl* TextCtrl_Perc;
        wxMenuItem* MenuItem_IncPerc;
        wxButton* Button_FillValue;
        wxStaticText* StaticText_XAxis;
        wxMenuItem* MenuItem31;
        wxMenuItem* MenuItem8;
        wxMenuItem* MenuItem_SelectCompareBIN1;
        wxTextCtrl* TextCtrl_TopRight;
        wxMenuItem* MenuItem_SelectCompareBIN2;
        simpleChart* XChart;
        wxPanel* Panel5;
        wxBitmapButton* BitmapButton_EngSub;
        wxBitmapButton* BitmapButton_SelectionInfo;
        wxBitmapButton* BitmapButton_PercAdd;
        wxBitmapButton* BitmapButton_SelectionUp;
        wxStaticText* StaticText_ChartTitle;
        wxPanel* Panel4;
        wxMenuItem* MenuItem2;
        wxPanel* Panel_2DGraphs;
        wxBitmapButton* BitmapButton_SelectionRight;
        wxMenu* Menu3;
        wxMenuItem* MenuItem1;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem_SelectValue;
        wxMenuItem* MenuItem11;
        wxMenuItem* MenuItem29;
        wxStaticText* StaticText_YAxis;
        wxButton* Button_SelectGreaterValue;
        simpleChart* YChart;
        wxMenuItem* MenuItem_DecEng;
        wxPanel* Panel_Frame;
        wxMenuItem* MenuItem_IncRaw;
        wxMenuItem* MenuItem_IncEng;
        wxPanel* Panel1;
        wxMenuItem* MenuItem_DecPerc;
        wxBitmapButton* BitmapButton_SelectionDown;
        wxBitmapButton* BitmapButton_RawSub;
        wxMenuItem* MenuItem_Copy;
        wxMenuItem* MenuItem10;
        wxMenuItem* MenuItem_InvertSelections;
        wxTextCtrl* TextCtrl_Eng;
        wxPanel* Panel6;
        wxPanel* Panel3;
        wxTextCtrl* TextCtrl_BottomLeft;
        wxMenuItem* MenuItem3;
        wxTextCtrl* TextCtrl_TopLeft;
        wxBitmapButton* BitmapButton_EngAdd;
        wxMenuItem* MenuItem_SelectAll;
        wxMenuItem* MenuItem_FillValue;
        wxMenuItem* MenuItem28;
        wxMenu* Menu7;
        wxPanel* Panel7;
        wxButton* Button_SelectValue;
        wxBitmapButton* BitmapButton_RawAdd;
        wxMenuItem* MenuItem6;
        wxSpinCtrl* SpinCtrl_Raw;
        wxMenuItem* MenuItem_ShowDifferences;
        wxMenuItem* MenuItem_Paste;
        wxRadioButton* RadioButton_Eng;
        wxMenuItem* MenuItem_2DView;
        wxMenuItem* MenuItem_ShowRawValues;
        wxMenuItem* MenuItem_Cancel;
        wxMenuItem* MenuItem_3DViewer;
        wxPanel* Panel_Controls;
        wxMenuItem* MenuItem_Select_None;
        wxPanel* Panel2;
        wxButton* Button_Interpolation;
        wxPanel* Panel10;
        wxMenu* Menu8;
        wxToolBar* ToolBar;
        wxMenu* Menu6;
        wxMenu* Menu2;
        wxBitmapButton* BitmapButton_PercSub;
        wxMenuItem* MenuItem_ViewControls;
        wxMenuItem* MenuItem9;
        wxStatusBar* StatusBar;
        wxMenuItem* MenuItem30;
        wxRadioButton* RadioButton_Perc;
        wxGrid* Grid;
        wxMenuItem* MenuItem_HighlightDifferences;
        wxMenu* Menu5;
        wxTextCtrl* TextCtrl_BottomRight;
        wxBitmapButton* BitmapButton_SelectionLeft;
        wxMenu* Menu4;
        wxMenuItem* MenuItem_SelectGreaterValue;
        wxRadioButton* RadioButton_Raw;
        wxMenuItem* MenuItem_DecRaw;
        wxMenuItem* MenuItem_SelectCompareBIN3;
        //*)

        wxToolBarToolBase* ToolBarItem1;
        wxToolBarToolBase* ToolBarItem2;
        wxToolBarToolBase* ToolBarItem3;
        wxToolBarToolBase* ToolBarItem4;
        wxToolBarToolBase* ToolBarItem5;
        wxToolBarToolBase* ToolBarItem6;
        wxToolBarToolBase* ToolBarItem7;
        wxToolBarToolBase* ToolBarItem8;

        DECLARE_EVENT_TABLE()
};

#endif // TABLEEDITORMAIN_H
