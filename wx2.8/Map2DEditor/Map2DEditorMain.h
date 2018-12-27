/***************************************************************
 * Name:      Map2DEditorMain.h
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
 
#ifndef MAP2DEDITORMAIN_H
#define MAP2DEDITORMAIN_H

//(*Headers(Map2DEditorFrame)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/listbox.h>
#include <wx/statline.h>
#include <wx/toolbar.h>
#include <wx/panel.h>
#include <wx/bmpbuttn.h>
#include <wx/scrolbar.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

#include "../GlobalVariables.h"
#include "mapChart.h"

class Map2DEditorFrame: public wxFrame
{
    public:

        Map2DEditorFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Map2DEditorFrame();

        void Init(unsigned short selected_bin, unsigned short selected_map, GlobalVariables *gv);
        int GetRawValueFromAddress(unsigned char *buffer, unsigned int address, unsigned short bits, bool order, bool sign);

    private:

        //(*Handlers(Map2DEditorFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnResize(wxSizeEvent& event);
        void OnChartPaint(wxPaintEvent& event);
        void OnChartResize(wxSizeEvent& event);
        void OnScrollBar_ZoomXScrollChanged(wxScrollEvent& event);
        void OnScrollBar_ZoomYScrollChanged(wxScrollEvent& event);
        void OnCheckBox_ZoomAutoClick(wxCommandEvent& event);
        void OnScrollBar_ChartScrollChanged(wxScrollEvent& event);
        void OnScrollBar_BIN1ScrollChanged(wxScrollEvent& event);
        void OnResize1(wxSizeEvent& event);
        void OnBitmapButton_GotoClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(Map2DEditorFrame)
        static const long ID_CUSTOM1;
        static const long ID_PANEL7;
        static const long ID_LISTBOX1;
        static const long ID_BITMAPBUTTON1;
        static const long ID_BITMAPBUTTON2;
        static const long ID_BITMAPBUTTON3;
        static const long ID_BITMAPBUTTON4;
        static const long ID_PANEL2;
        static const long ID_STATICLINE1;
        static const long ID_TEXTCTRL1;
        static const long ID_BITMAPBUTTON5;
        static const long ID_BITMAPBUTTON6;
        static const long ID_TEXTCTRL2;
        static const long ID_BITMAPBUTTON7;
        static const long ID_BITMAPBUTTON8;
        static const long ID_PANEL3;
        static const long ID_STATICLINE2;
        static const long ID_STATICTEXT1;
        static const long ID_SCROLLBAR1;
        static const long ID_STATICTEXT2;
        static const long ID_SCROLLBAR2;
        static const long ID_CHECKBOX1;
        static const long ID_PANEL4;
        static const long ID_STATICLINE3;
        static const long ID_BITMAPBUTTON11;
        static const long ID_BITMAPBUTTON12;
        static const long ID_BITMAPBUTTON13;
        static const long ID_SCROLLBAR3;
        static const long ID_SCROLLBAR4;
        static const long ID_SCROLLBAR5;
        static const long ID_BITMAPBUTTON14;
        static const long ID_BITMAPBUTTON16;
        static const long ID_BITMAPBUTTON17;
        static const long ID_PANEL5;
        static const long ID_STATICLINE4;
        static const long ID_TEXTCTRL4;
        static const long ID_BITMAPBUTTON15;
        static const long ID_CHECKBOX2;
        static const long ID_PANEL6;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
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
        static const long ID_TOOLBARITEM11;
        static const long ID_TOOLBARITEM12;
        static const long ID_TOOLBARITEM13;
        static const long ID_TOOLBARITEM14;
        static const long ID_TOOLBARITEM15;
        static const long ID_TOOLBARITEM16;
        static const long ID_TOOLBAR1;
        //*)

        //(*Declarations(Map2DEditorFrame)
        wxToolBarToolBase* ToolBarItem4;
        wxScrollBar* ScrollBar_ZoomX;
        wxTextCtrl* TextCtrl4;
        wxPanel* Panel5;
        wxToolBar* ToolBar1;
        wxToolBarToolBase* ToolBarItem9;
        mapChart* Chart;
        wxBitmapButton* BitmapButton5;
        wxToolBarToolBase* ToolBarItem3;
        wxToolBarToolBase* ToolBarItem12;
        wxBitmapButton* BitmapButton16;
        wxStaticText* StaticText2;
        wxPanel* Panel4;
        wxToolBarToolBase* ToolBarItem11;
        wxBitmapButton* BitmapButton17;
        wxScrollBar* ScrollBar4;
        wxToolBarToolBase* ToolBarItem10;
        wxToolBarToolBase* ToolBarItem15;
        wxBitmapButton* BitmapButton14;
        wxCheckBox* CheckBox2;
        wxBitmapButton* BitmapButton_Goto;
        wxScrollBar* ScrollBar_ZoomY;
        wxPanel* Panel1;
        wxBitmapButton* BitmapButton2;
        wxStaticText* StaticText1;
        wxBitmapButton* BitmapButton13;
        wxBitmapButton* BitmapButton8;
        wxBitmapButton* BitmapButton1;
        wxToolBarToolBase* ToolBarItem16;
        wxCheckBox* CheckBox_ZoomAuto;
        wxPanel* Panel6;
        wxStaticLine* StaticLine4;
        wxPanel* Panel3;
        wxToolBarToolBase* ToolBarItem6;
        wxStaticLine* StaticLine2;
        wxToolBarToolBase* ToolBarItem13;
        wxBitmapButton* BitmapButton12;
        wxToolBarToolBase* ToolBarItem1;
        wxScrollBar* ScrollBar5;
        wxPanel* Panel7;
        wxToolBarToolBase* ToolBarItem14;
        wxScrollBar* ScrollBar_BIN1;
        wxStatusBar* StatusBar1;
        wxStaticLine* StaticLine3;
        wxBitmapButton* BitmapButton6;
        wxStaticLine* StaticLine1;
        wxTextCtrl* TextCtrl2;
        wxBitmapButton* BitmapButton7;
        wxBitmapButton* BitmapButton4;
        wxToolBarToolBase* ToolBarItem5;
        wxTextCtrl* TextCtrl1;
        wxBitmapButton* BitmapButton3;
        wxToolBarToolBase* ToolBarItem8;
        wxPanel* Panel2;
        wxBitmapButton* BitmapButton11;
        wxToolBarToolBase* ToolBarItem2;
        wxToolBarToolBase* ToolBarItem7;
        wxListBox* ListBox1;
        //*)

        unsigned int current_address0, current_address1, current_address2;
        unsigned short current_bin, current_map;
        GlobalVariables *global;

        DECLARE_EVENT_TABLE()
};

#endif // MAP2DEDITORMAIN_H
