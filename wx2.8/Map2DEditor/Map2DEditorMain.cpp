/***************************************************************
 * Name:      Map2DEditorMain.cpp
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
 
#include "wx_pch.h"
#include "Map2DEditorMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(Map2DEditorFrame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Map2DEditorFrame)
const long Map2DEditorFrame::ID_CUSTOM1 = wxNewId();
const long Map2DEditorFrame::ID_PANEL7 = wxNewId();
const long Map2DEditorFrame::ID_LISTBOX1 = wxNewId();
const long Map2DEditorFrame::ID_BITMAPBUTTON1 = wxNewId();
const long Map2DEditorFrame::ID_BITMAPBUTTON2 = wxNewId();
const long Map2DEditorFrame::ID_BITMAPBUTTON3 = wxNewId();
const long Map2DEditorFrame::ID_BITMAPBUTTON4 = wxNewId();
const long Map2DEditorFrame::ID_PANEL2 = wxNewId();
const long Map2DEditorFrame::ID_STATICLINE1 = wxNewId();
const long Map2DEditorFrame::ID_TEXTCTRL1 = wxNewId();
const long Map2DEditorFrame::ID_BITMAPBUTTON5 = wxNewId();
const long Map2DEditorFrame::ID_BITMAPBUTTON6 = wxNewId();
const long Map2DEditorFrame::ID_TEXTCTRL2 = wxNewId();
const long Map2DEditorFrame::ID_BITMAPBUTTON7 = wxNewId();
const long Map2DEditorFrame::ID_BITMAPBUTTON8 = wxNewId();
const long Map2DEditorFrame::ID_PANEL3 = wxNewId();
const long Map2DEditorFrame::ID_STATICLINE2 = wxNewId();
const long Map2DEditorFrame::ID_STATICTEXT1 = wxNewId();
const long Map2DEditorFrame::ID_SCROLLBAR1 = wxNewId();
const long Map2DEditorFrame::ID_STATICTEXT2 = wxNewId();
const long Map2DEditorFrame::ID_SCROLLBAR2 = wxNewId();
const long Map2DEditorFrame::ID_CHECKBOX1 = wxNewId();
const long Map2DEditorFrame::ID_PANEL4 = wxNewId();
const long Map2DEditorFrame::ID_STATICLINE3 = wxNewId();
const long Map2DEditorFrame::ID_BITMAPBUTTON11 = wxNewId();
const long Map2DEditorFrame::ID_BITMAPBUTTON12 = wxNewId();
const long Map2DEditorFrame::ID_BITMAPBUTTON13 = wxNewId();
const long Map2DEditorFrame::ID_SCROLLBAR3 = wxNewId();
const long Map2DEditorFrame::ID_SCROLLBAR4 = wxNewId();
const long Map2DEditorFrame::ID_SCROLLBAR5 = wxNewId();
const long Map2DEditorFrame::ID_BITMAPBUTTON14 = wxNewId();
const long Map2DEditorFrame::ID_BITMAPBUTTON16 = wxNewId();
const long Map2DEditorFrame::ID_BITMAPBUTTON17 = wxNewId();
const long Map2DEditorFrame::ID_PANEL5 = wxNewId();
const long Map2DEditorFrame::ID_STATICLINE4 = wxNewId();
const long Map2DEditorFrame::ID_TEXTCTRL4 = wxNewId();
const long Map2DEditorFrame::ID_BITMAPBUTTON15 = wxNewId();
const long Map2DEditorFrame::ID_CHECKBOX2 = wxNewId();
const long Map2DEditorFrame::ID_PANEL6 = wxNewId();
const long Map2DEditorFrame::ID_PANEL1 = wxNewId();
const long Map2DEditorFrame::idMenuQuit = wxNewId();
const long Map2DEditorFrame::idMenuAbout = wxNewId();
const long Map2DEditorFrame::ID_STATUSBAR1 = wxNewId();
const long Map2DEditorFrame::ID_TOOLBARITEM1 = wxNewId();
const long Map2DEditorFrame::ID_TOOLBARITEM2 = wxNewId();
const long Map2DEditorFrame::ID_TOOLBARITEM3 = wxNewId();
const long Map2DEditorFrame::ID_TOOLBARITEM4 = wxNewId();
const long Map2DEditorFrame::ID_TOOLBARITEM5 = wxNewId();
const long Map2DEditorFrame::ID_TOOLBARITEM6 = wxNewId();
const long Map2DEditorFrame::ID_TOOLBARITEM7 = wxNewId();
const long Map2DEditorFrame::ID_TOOLBARITEM8 = wxNewId();
const long Map2DEditorFrame::ID_TOOLBARITEM9 = wxNewId();
const long Map2DEditorFrame::ID_TOOLBARITEM10 = wxNewId();
const long Map2DEditorFrame::ID_TOOLBARITEM11 = wxNewId();
const long Map2DEditorFrame::ID_TOOLBARITEM12 = wxNewId();
const long Map2DEditorFrame::ID_TOOLBARITEM13 = wxNewId();
const long Map2DEditorFrame::ID_TOOLBARITEM14 = wxNewId();
const long Map2DEditorFrame::ID_TOOLBARITEM15 = wxNewId();
const long Map2DEditorFrame::ID_TOOLBARITEM16 = wxNewId();
const long Map2DEditorFrame::ID_TOOLBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Map2DEditorFrame,wxFrame)
    //(*EventTable(Map2DEditorFrame)
    //*)
END_EVENT_TABLE()

Map2DEditorFrame::Map2DEditorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Map2DEditorFrame)
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer10;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxMenuItem* MenuItem2;
    wxBoxSizer* BoxSizer13;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer11;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer12;
    wxBoxSizer* BoxSizer14;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer9;
    wxMenuBar* MenuBar1;
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu2;

    Create(parent, id, _("2D Map Editor"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(800,620));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    Panel7 = new wxPanel(Panel1, ID_PANEL7, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL7"));
    BoxSizer10 = new wxBoxSizer(wxVERTICAL);
    Chart = new mapChart(Panel7);
    BoxSizer10->Add(Chart, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Panel7->SetSizer(BoxSizer10);
    BoxSizer10->Fit(Panel7);
    BoxSizer10->SetSizeHints(Panel7);
    BoxSizer3->Add(Panel7, 3, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    Panel2 = new wxPanel(Panel1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer6 = new wxBoxSizer(wxVERTICAL);
    ListBox1 = new wxListBox(Panel2, ID_LISTBOX1, wxDefaultPosition, wxSize(178,169), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    BoxSizer6->Add(ListBox1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    BitmapButton1 = new wxBitmapButton(Panel2, ID_BITMAPBUTTON1, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ADD_BOOKMARK")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BoxSizer7->Add(BitmapButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton2 = new wxBitmapButton(Panel2, ID_BITMAPBUTTON2, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_DEL_BOOKMARK")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BoxSizer7->Add(BitmapButton2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton3 = new wxBitmapButton(Panel2, ID_BITMAPBUTTON3, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_BACK")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
    BoxSizer7->Add(BitmapButton3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton4 = new wxBitmapButton(Panel2, ID_BITMAPBUTTON4, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_FORWARD")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
    BoxSizer7->Add(BitmapButton4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer6->Add(BoxSizer7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Panel2->SetSizer(BoxSizer6);
    BoxSizer6->Fit(Panel2);
    BoxSizer6->SetSizeHints(Panel2);
    BoxSizer5->Add(Panel2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    BoxSizer5->Add(StaticLine1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel3 = new wxPanel(Panel1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    FlexGridSizer1 = new wxFlexGridSizer(2, 3, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    TextCtrl1 = new wxTextCtrl(Panel3, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer1->Add(TextCtrl1, 1, wxALL|wxEXPAND|wxSHAPED|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton5 = new wxBitmapButton(Panel3, ID_BITMAPBUTTON5, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_UP")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
    FlexGridSizer1->Add(BitmapButton5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton6 = new wxBitmapButton(Panel3, ID_BITMAPBUTTON6, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_DOWN")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
    FlexGridSizer1->Add(BitmapButton6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(Panel3, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer1->Add(TextCtrl2, 1, wxALL|wxEXPAND|wxSHAPED|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton7 = new wxBitmapButton(Panel3, ID_BITMAPBUTTON7, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_UP")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON7"));
    FlexGridSizer1->Add(BitmapButton7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton8 = new wxBitmapButton(Panel3, ID_BITMAPBUTTON8, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_DOWN")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON8"));
    FlexGridSizer1->Add(BitmapButton8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel3->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(Panel3);
    FlexGridSizer1->SetSizeHints(Panel3);
    BoxSizer5->Add(Panel3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine2 = new wxStaticLine(Panel1, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    BoxSizer5->Add(StaticLine2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel4 = new wxPanel(Panel1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    BoxSizer8 = new wxBoxSizer(wxVERTICAL);
    FlexGridSizer2 = new wxFlexGridSizer(2, 2, 0, 0);
    FlexGridSizer2->AddGrowableCol(1);
    StaticText1 = new wxStaticText(Panel4, ID_STATICTEXT1, _("X"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ScrollBar_ZoomX = new wxScrollBar(Panel4, ID_SCROLLBAR1, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SCROLLBAR1"));
    ScrollBar_ZoomX->SetScrollbar(0, 1, 10, 1);
    FlexGridSizer2->Add(ScrollBar_ZoomX, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel4, ID_STATICTEXT2, _("Y"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ScrollBar_ZoomY = new wxScrollBar(Panel4, ID_SCROLLBAR2, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SCROLLBAR2"));
    ScrollBar_ZoomY->SetScrollbar(0, 1, 10, 1);
    FlexGridSizer2->Add(ScrollBar_ZoomY, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8->Add(FlexGridSizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    CheckBox_ZoomAuto = new wxCheckBox(Panel4, ID_CHECKBOX1, _("Auto"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox_ZoomAuto->SetValue(true);
    BoxSizer9->Add(CheckBox_ZoomAuto, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer8->Add(BoxSizer9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel4->SetSizer(BoxSizer8);
    BoxSizer8->Fit(Panel4);
    BoxSizer8->SetSizeHints(Panel4);
    BoxSizer5->Add(Panel4, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    StaticLine3 = new wxStaticLine(Panel1, ID_STATICLINE3, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
    BoxSizer2->Add(StaticLine3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    Panel5 = new wxPanel(Panel1, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
    BitmapButton11 = new wxBitmapButton(Panel5, ID_BITMAPBUTTON11, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_BACK")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON11"));
    BoxSizer11->Add(BitmapButton11, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton12 = new wxBitmapButton(Panel5, ID_BITMAPBUTTON12, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_BACK")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON12"));
    BoxSizer11->Add(BitmapButton12, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton13 = new wxBitmapButton(Panel5, ID_BITMAPBUTTON13, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_BACK")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON13"));
    BoxSizer11->Add(BitmapButton13, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer12 = new wxBoxSizer(wxVERTICAL);
    ScrollBar_BIN1 = new wxScrollBar(Panel5, ID_SCROLLBAR3, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SCROLLBAR3"));
    ScrollBar_BIN1->SetScrollbar(0, 1, 10, 1);
    BoxSizer12->Add(ScrollBar_BIN1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ScrollBar4 = new wxScrollBar(Panel5, ID_SCROLLBAR4, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SCROLLBAR4"));
    ScrollBar4->SetScrollbar(0, 1, 10, 1);
    BoxSizer12->Add(ScrollBar4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ScrollBar5 = new wxScrollBar(Panel5, ID_SCROLLBAR5, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SCROLLBAR5"));
    ScrollBar5->SetScrollbar(0, 1, 10, 1);
    BoxSizer12->Add(ScrollBar5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer11->Add(BoxSizer12, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BitmapButton14 = new wxBitmapButton(Panel5, ID_BITMAPBUTTON14, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_FORWARD")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON14"));
    BoxSizer11->Add(BitmapButton14, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton16 = new wxBitmapButton(Panel5, ID_BITMAPBUTTON16, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_FORWARD")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON16"));
    BoxSizer11->Add(BitmapButton16, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton17 = new wxBitmapButton(Panel5, ID_BITMAPBUTTON17, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_FORWARD")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON17"));
    BoxSizer11->Add(BitmapButton17, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel5->SetSizer(BoxSizer11);
    BoxSizer11->Fit(Panel5);
    BoxSizer11->SetSizeHints(Panel5);
    BoxSizer4->Add(Panel5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine4 = new wxStaticLine(Panel1, ID_STATICLINE4, wxDefaultPosition, wxSize(10,-1), wxLI_VERTICAL, _T("ID_STATICLINE4"));
    BoxSizer4->Add(StaticLine4, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel6 = new wxPanel(Panel1, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    BoxSizer13 = new wxBoxSizer(wxVERTICAL);
    BoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
    TextCtrl4 = new wxTextCtrl(Panel6, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    BoxSizer14->Add(TextCtrl4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton_Goto = new wxBitmapButton(Panel6, ID_BITMAPBUTTON15, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_REDO")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON15"));
    BoxSizer14->Add(BitmapButton_Goto, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer13->Add(BoxSizer14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    CheckBox2 = new wxCheckBox(Panel6, ID_CHECKBOX2, _("Sync"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
    CheckBox2->SetValue(false);
    BoxSizer13->Add(CheckBox2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel6->SetSizer(BoxSizer13);
    BoxSizer13->Fit(Panel6);
    BoxSizer13->SetSizeHints(Panel6);
    BoxSizer4->Add(Panel6, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer4, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    ToolBar1 = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxNO_BORDER, _T("ID_TOOLBAR1"));
    ToolBarItem1 = ToolBar1->AddTool(ID_TOOLBARITEM1, _("Select BIN #1"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_MISSING_IMAGE")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem2 = ToolBar1->AddTool(ID_TOOLBARITEM2, _("Select BIN #2"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_MISSING_IMAGE")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem3 = ToolBar1->AddTool(ID_TOOLBARITEM3, _("Select BIN #3"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_MISSING_IMAGE")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBar1->AddSeparator();
    ToolBarItem4 = ToolBar1->AddTool(ID_TOOLBARITEM4, _("Visible BIN #1"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_MISSING_IMAGE")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem5 = ToolBar1->AddTool(ID_TOOLBARITEM5, _("Visible BIN #2"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_MISSING_IMAGE")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem6 = ToolBar1->AddTool(ID_TOOLBARITEM6, _("Visible BIN #3"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_MISSING_IMAGE")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBar1->AddSeparator();
    ToolBarItem7 = ToolBar1->AddTool(ID_TOOLBARITEM7, _("View Grid"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_MISSING_IMAGE")),wxART_TOOLBAR), wxNullBitmap, wxITEM_CHECK, wxEmptyString, wxEmptyString);
    ToolBar1->AddSeparator();
    ToolBarItem8 = ToolBar1->AddTool(ID_TOOLBARITEM8, _("Search Sequence"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FIND")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem9 = ToolBar1->AddTool(ID_TOOLBARITEM9, _("Search Backwards"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FIND")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem10 = ToolBar1->AddTool(ID_TOOLBARITEM10, _("Search Forward"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FIND")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBar1->AddSeparator();
    ToolBarItem11 = ToolBar1->AddTool(ID_TOOLBARITEM11, _("View 8bit"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_MISSING_IMAGE")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem12 = ToolBar1->AddTool(ID_TOOLBARITEM12, _("View 16bit"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_MISSING_IMAGE")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem13 = ToolBar1->AddTool(ID_TOOLBARITEM13, _("View 32bit"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_MISSING_IMAGE")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBar1->AddSeparator();
    ToolBarItem14 = ToolBar1->AddTool(ID_TOOLBARITEM14, _("View HEX/DEC"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_MISSING_IMAGE")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem15 = ToolBar1->AddTool(ID_TOOLBARITEM15, _("Byte Sequence"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_MISSING_IMAGE")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem16 = ToolBar1->AddTool(ID_TOOLBARITEM16, _("Signed/Unsigned"), wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_MISSING_IMAGE")),wxART_TOOLBAR), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBar1->Realize();
    SetToolBar(ToolBar1);
    SetSizer(BoxSizer1);
    Layout();

    Connect(ID_SCROLLBAR1,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Map2DEditorFrame::OnScrollBar_ZoomXScrollChanged);
    Connect(ID_SCROLLBAR2,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Map2DEditorFrame::OnScrollBar_ZoomYScrollChanged);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&Map2DEditorFrame::OnCheckBox_ZoomAutoClick);
    Connect(ID_SCROLLBAR3,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Map2DEditorFrame::OnScrollBar_BIN1ScrollChanged);
    Connect(ID_BITMAPBUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Map2DEditorFrame::OnBitmapButton_GotoClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Map2DEditorFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Map2DEditorFrame::OnAbout);
    Connect(wxEVT_SIZE,(wxObjectEventFunction)&Map2DEditorFrame::OnResize);
    //*)
}

Map2DEditorFrame::~Map2DEditorFrame()
{
    //(*Destroy(Map2DEditorFrame)
    //*)
}

void Map2DEditorFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Map2DEditorFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

/// ---------------------------------------------------------------------------
/// Misc Functions
/// ---------------------------------------------------------------------------

void Map2DEditorFrame::Init(unsigned short selected_bin, unsigned short selected_map, GlobalVariables *gv)
{
    global=gv;
    current_bin=selected_bin;
    current_map=selected_map;
    current_address0=0;
    current_address1=0;
    current_address2=0;

    ScrollBar_BIN1->SetRange(global->bin_length[0]);

    Chart->Init();
    Chart->SetZoom(ScrollBar_ZoomX->GetThumbPosition()+1, ScrollBar_ZoomY->GetThumbPosition()+1, CheckBox_ZoomAuto->GetValue());
    Chart->SetSummaryBar(global->bin_buffer[0], global->bin_length[0]);
    Chart->SetView(global->bin_buffer[0], global->bin_length[0],
                   global->bin_buffer[1], global->bin_length[1],
                   global->bin_buffer[2], global->bin_length[2],
                   current_address0, current_address1, current_address2,
                   true, false, false, 16, false, false);   //ScrollBar_Chart->GetThumbPosition()

    Chart->Refresh();
    /*
    if (global->bin_length[0])
        MenuItem_SelectCompareBIN1->Enable(true);
    else
        MenuItem_SelectCompareBIN1->Enable(false);

    if (global->bin_length[1])
        MenuItem_SelectCompareBIN2->Enable(true);
    else
        MenuItem_SelectCompareBIN2->Enable(false);

    if (global->bin_length[2])
        MenuItem_SelectCompareBIN3->Enable(true);
    else
        MenuItem_SelectCompareBIN3->Enable(false);
    */
}

void Map2DEditorFrame::OnScrollBar_ZoomXScrollChanged(wxScrollEvent& event)
{
    Chart->SetZoom(ScrollBar_ZoomX->GetThumbPosition()+1, ScrollBar_ZoomY->GetThumbPosition()+1, CheckBox_ZoomAuto->GetValue());
    Chart->Refresh();

    event.Skip();
}

void Map2DEditorFrame::OnScrollBar_ZoomYScrollChanged(wxScrollEvent& event)
{
    Chart->SetZoom(ScrollBar_ZoomX->GetThumbPosition()+1, ScrollBar_ZoomY->GetThumbPosition()+1, CheckBox_ZoomAuto->GetValue());
    Chart->Refresh();

    event.Skip();
}

void Map2DEditorFrame::OnCheckBox_ZoomAutoClick(wxCommandEvent& event)
{
    Chart->SetZoom(ScrollBar_ZoomX->GetThumbPosition()+1, ScrollBar_ZoomY->GetThumbPosition()+1, CheckBox_ZoomAuto->GetValue());
    Chart->Refresh();

    event.Skip();
}

void Map2DEditorFrame::OnScrollBar_BIN1ScrollChanged(wxScrollEvent& event)
{
    if (ScrollBar_BIN1->GetThumbPosition() % 2)
        current_address0=ScrollBar_BIN1->GetThumbPosition()+1;
    else
        current_address0=ScrollBar_BIN1->GetThumbPosition();

    Chart->SetView(global->bin_buffer[0], global->bin_length[0],
                   global->bin_buffer[1], global->bin_length[1],
                   global->bin_buffer[2], global->bin_length[2],
                   current_address0, current_address1, current_address2,
                   true, false, false, 16, false, false);
    Chart->Refresh();

    event.Skip();
}

void Map2DEditorFrame::OnResize(wxSizeEvent& event)
{
    StatusBar1->SetStatusText(_("Cnt ") + wxString::Format(wxT("%i"),Chart->cnt) + _("  Width ") + wxString::Format(wxT("%i"),Chart->GetWidth()),0);

    event.Skip();
}

void Map2DEditorFrame::OnBitmapButton_GotoClick(wxCommandEvent& event)
{
    StatusBar1->SetStatusText(_("Cnt ") + wxString::Format(wxT("%i"),Chart->cnt) + _("  Width ") + wxString::Format(wxT("%i"),Chart->GetWidth()),0);

    event.Skip();
}
