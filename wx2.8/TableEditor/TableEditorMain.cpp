/***************************************************************
 * Name:      TableEditorMain.cpp
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
#include <wx/msgdlg.h>
#include <wx/mstream.h>
#include <wx/textfile.h>
#include <wx/filefn.h>
#include <wx/clipbrd.h>

//(*InternalHeaders(TableEditorFrame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

#include "TableEditorMain.h"

#include "../images/toolbar.h"

//(*IdInit(TableEditorFrame)
const long TableEditorFrame::ID_STATICTEXT4 = wxNewId();
const long TableEditorFrame::ID_GRID1 = wxNewId();
const long TableEditorFrame::ID_PANEL6 = wxNewId();
const long TableEditorFrame::ID_RADIOBUTTON1 = wxNewId();
const long TableEditorFrame::ID_SPINCTRL1 = wxNewId();
const long TableEditorFrame::ID_BITMAPBUTTON1 = wxNewId();
const long TableEditorFrame::ID_BITMAPBUTTON2 = wxNewId();
const long TableEditorFrame::ID_RADIOBUTTON2 = wxNewId();
const long TableEditorFrame::ID_TEXTCTRL1 = wxNewId();
const long TableEditorFrame::ID_BITMAPBUTTON3 = wxNewId();
const long TableEditorFrame::ID_BITMAPBUTTON4 = wxNewId();
const long TableEditorFrame::ID_RADIOBUTTON3 = wxNewId();
const long TableEditorFrame::ID_TEXTCTRL2 = wxNewId();
const long TableEditorFrame::ID_BITMAPBUTTON5 = wxNewId();
const long TableEditorFrame::ID_BITMAPBUTTON6 = wxNewId();
const long TableEditorFrame::ID_PANEL5 = wxNewId();
const long TableEditorFrame::ID_BUTTON4 = wxNewId();
const long TableEditorFrame::ID_BUTTON2 = wxNewId();
const long TableEditorFrame::ID_BUTTON1 = wxNewId();
const long TableEditorFrame::ID_PANEL10 = wxNewId();
const long TableEditorFrame::ID_BITMAPBUTTON7 = wxNewId();
const long TableEditorFrame::ID_BITMAPBUTTON9 = wxNewId();
const long TableEditorFrame::ID_BITMAPBUTTON11 = wxNewId();
const long TableEditorFrame::ID_BITMAPBUTTON8 = wxNewId();
const long TableEditorFrame::ID_BITMAPBUTTON10 = wxNewId();
const long TableEditorFrame::ID_PANEL4 = wxNewId();
const long TableEditorFrame::ID_TEXTCTRL3 = wxNewId();
const long TableEditorFrame::ID_TEXTCTRL4 = wxNewId();
const long TableEditorFrame::ID_TEXTCTRL5 = wxNewId();
const long TableEditorFrame::ID_TEXTCTRL6 = wxNewId();
const long TableEditorFrame::ID_BUTTON3 = wxNewId();
const long TableEditorFrame::ID_PANEL9 = wxNewId();
const long TableEditorFrame::ID_PANEL11 = wxNewId();
const long TableEditorFrame::ID_PANEL7 = wxNewId();
const long TableEditorFrame::ID_STATICTEXT5 = wxNewId();
const long TableEditorFrame::ID_CUSTOM1 = wxNewId();
const long TableEditorFrame::ID_PANEL2 = wxNewId();
const long TableEditorFrame::ID_STATICTEXT6 = wxNewId();
const long TableEditorFrame::ID_CUSTOM2 = wxNewId();
const long TableEditorFrame::ID_PANEL3 = wxNewId();
const long TableEditorFrame::ID_PANEL8 = wxNewId();
const long TableEditorFrame::ID_PANEL1 = wxNewId();
const long TableEditorFrame::ID_MENUITEM7 = wxNewId();
const long TableEditorFrame::ID_MENUITEM8 = wxNewId();
const long TableEditorFrame::ID_MENUITEM9 = wxNewId();
const long TableEditorFrame::ID_MENUITEM10 = wxNewId();
const long TableEditorFrame::idMenuQuit = wxNewId();
const long TableEditorFrame::ID_MENUITEM16 = wxNewId();
const long TableEditorFrame::ID_MENUITEM11 = wxNewId();
const long TableEditorFrame::ID_MENUITEM12 = wxNewId();
const long TableEditorFrame::ID_MENUITEM21 = wxNewId();
const long TableEditorFrame::ID_MENUITEM22 = wxNewId();
const long TableEditorFrame::ID_MENUITEM23 = wxNewId();
const long TableEditorFrame::ID_MENUITEM24 = wxNewId();
const long TableEditorFrame::ID_MENUITEM25 = wxNewId();
const long TableEditorFrame::ID_MENUITEM26 = wxNewId();
const long TableEditorFrame::ID_MENUITEM18 = wxNewId();
const long TableEditorFrame::ID_MENUITEM1 = wxNewId();
const long TableEditorFrame::ID_MENUITEM2 = wxNewId();
const long TableEditorFrame::ID_MENUITEM3 = wxNewId();
const long TableEditorFrame::ID_MENUITEM4 = wxNewId();
const long TableEditorFrame::ID_MENUITEM5 = wxNewId();
const long TableEditorFrame::ID_MENUITEM6 = wxNewId();
const long TableEditorFrame::ID_MENUITEM31 = wxNewId();
const long TableEditorFrame::ID_MENUITEM32 = wxNewId();
const long TableEditorFrame::ID_MENUITEM33 = wxNewId();
const long TableEditorFrame::ID_MENUITEM13 = wxNewId();
const long TableEditorFrame::ID_MENUITEM17 = wxNewId();
const long TableEditorFrame::ID_MENUITEM14 = wxNewId();
const long TableEditorFrame::ID_MENUITEM15 = wxNewId();
const long TableEditorFrame::ID_MENUITEM36 = wxNewId();
const long TableEditorFrame::ID_MENUITEM27 = wxNewId();
const long TableEditorFrame::ID_MENUITEM28 = wxNewId();
const long TableEditorFrame::ID_MENUITEM29 = wxNewId();
const long TableEditorFrame::ID_MENUITEM30 = wxNewId();
const long TableEditorFrame::ID_MENUITEM20 = wxNewId();
const long TableEditorFrame::ID_MENUITEM19 = wxNewId();
const long TableEditorFrame::ID_MENUITEM34 = wxNewId();
const long TableEditorFrame::ID_MENUITEM35 = wxNewId();
const long TableEditorFrame::ID_MENUITEM37 = wxNewId();
const long TableEditorFrame::ID_STATUSBAR1 = wxNewId();
const long TableEditorFrame::ID_TOOLBAR1 = wxNewId();
//*)

const long TableEditorFrame::ID_TOOLBARITEM1 = wxNewId();
const long TableEditorFrame::ID_TOOLBARITEM2 = wxNewId();
const long TableEditorFrame::ID_TOOLBARITEM3 = wxNewId();
const long TableEditorFrame::ID_TOOLBARITEM4 = wxNewId();
const long TableEditorFrame::ID_TOOLBARITEM5 = wxNewId();
const long TableEditorFrame::ID_TOOLBARITEM6 = wxNewId();
const long TableEditorFrame::ID_TOOLBARITEM7 = wxNewId();
const long TableEditorFrame::ID_TOOLBARITEM8 = wxNewId();

BEGIN_EVENT_TABLE(TableEditorFrame,wxFrame)
    //(*EventTable(TableEditorFrame)
    //*)
END_EVENT_TABLE()

TableEditorFrame::TableEditorFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(TableEditorFrame)
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer10;
    wxBoxSizer* BoxSizer7;
    wxBoxSizer* BoxSizer8;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer11;
    wxMenu* Menu1;
    wxMenuItem* MenuItem_Apply;
    wxGridSizer* GridSizer1;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer9;
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer3;
    wxGridSizer* GridSizer2;
    wxMenuBar* MenuBar;

    Create(parent, wxID_ANY, _("Table Editor"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(778,469));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel_Frame = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Panel7 = new wxPanel(Panel_Frame, ID_PANEL7, wxPoint(115,155), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL7"));
    BoxSizer4 = new wxBoxSizer(wxVERTICAL);
    Panel6 = new wxPanel(Panel7, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    BoxSizer8 = new wxBoxSizer(wxVERTICAL);
    StaticText_ChartTitle = new wxStaticText(Panel6, ID_STATICTEXT4, _("Chart Title"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    BoxSizer8->Add(StaticText_ChartTitle, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Grid = new wxGrid(Panel6, ID_GRID1, wxDefaultPosition, wxSize(520,230), wxVSCROLL|wxHSCROLL, _T("ID_GRID1"));
    Grid->CreateGrid(1,1);
    Grid->EnableEditing(true);
    Grid->EnableGridLines(true);
    Grid->SetDefaultCellFont( Grid->GetFont() );
    Grid->SetDefaultCellTextColour( Grid->GetForegroundColour() );
    BoxSizer8->Add(Grid, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel6->SetSizer(BoxSizer8);
    BoxSizer8->Fit(Panel6);
    BoxSizer8->SetSizeHints(Panel6);
    BoxSizer4->Add(Panel6, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel_Controls = new wxPanel(Panel7, ID_PANEL11, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL11"));
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    Panel5 = new wxPanel(Panel_Controls, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    FlexGridSizer1 = new wxFlexGridSizer(3, 4, 0, 0);
    RadioButton_Raw = new wxRadioButton(Panel5, ID_RADIOBUTTON1, _("Raw"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    RadioButton_Raw->SetValue(true);
    FlexGridSizer1->Add(RadioButton_Raw, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl_Raw = new wxSpinCtrl(Panel5, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxDefaultSize, 0, -2147483647, 2147483646, 0, _T("ID_SPINCTRL1"));
    SpinCtrl_Raw->SetValue(_T("0"));
    FlexGridSizer1->Add(SpinCtrl_Raw, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton_RawAdd = new wxBitmapButton(Panel5, ID_BITMAPBUTTON1, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_UP")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton_RawAdd->SetHelpText(_("Increment raw value"));
    FlexGridSizer1->Add(BitmapButton_RawAdd, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton_RawSub = new wxBitmapButton(Panel5, ID_BITMAPBUTTON2, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_DOWN")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BitmapButton_RawSub->SetDefault();
    BitmapButton_RawSub->SetHelpText(_("Decrement raw value"));
    FlexGridSizer1->Add(BitmapButton_RawSub, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton_Perc = new wxRadioButton(Panel5, ID_RADIOBUTTON2, _("Perc."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    FlexGridSizer1->Add(RadioButton_Perc, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_Perc = new wxTextCtrl(Panel5, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer1->Add(TextCtrl_Perc, 1, wxALL|wxSHAPED|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton_PercAdd = new wxBitmapButton(Panel5, ID_BITMAPBUTTON3, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_UP")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
    BitmapButton_PercAdd->SetHelpText(_("Increment percentage value"));
    FlexGridSizer1->Add(BitmapButton_PercAdd, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton_PercSub = new wxBitmapButton(Panel5, ID_BITMAPBUTTON4, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_DOWN")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
    BitmapButton_PercSub->SetDefault();
    BitmapButton_PercSub->SetHelpText(_("Decrement percentage value"));
    FlexGridSizer1->Add(BitmapButton_PercSub, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton_Eng = new wxRadioButton(Panel5, ID_RADIOBUTTON3, _("Eng."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
    RadioButton_Eng->SetValue(true);
    FlexGridSizer1->Add(RadioButton_Eng, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_Eng = new wxTextCtrl(Panel5, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer1->Add(TextCtrl_Eng, 1, wxALL|wxSHAPED|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton_EngAdd = new wxBitmapButton(Panel5, ID_BITMAPBUTTON5, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_UP")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
    BitmapButton_EngAdd->SetHelpText(_("Increment engineering value"));
    FlexGridSizer1->Add(BitmapButton_EngAdd, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton_EngSub = new wxBitmapButton(Panel5, ID_BITMAPBUTTON6, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_DOWN")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
    BitmapButton_EngSub->SetDefault();
    BitmapButton_EngSub->SetHelpText(_("Decrement engineering value"));
    FlexGridSizer1->Add(BitmapButton_EngSub, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel5->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(Panel5);
    FlexGridSizer1->SetSizeHints(Panel5);
    BoxSizer5->Add(Panel5, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel10 = new wxPanel(Panel_Controls, ID_PANEL10, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL10"));
    BoxSizer9 = new wxBoxSizer(wxVERTICAL);
    Button_FillValue = new wxButton(Panel10, ID_BUTTON4, _("Fill with value"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Button_FillValue->SetHelpText(_("Fill cells with fixed value"));
    BoxSizer9->Add(Button_FillValue, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button_SelectValue = new wxButton(Panel10, ID_BUTTON2, _("Select by value"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button_SelectValue->SetHelpText(_("Select cells by value"));
    BoxSizer9->Add(Button_SelectValue, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button_SelectGreaterValue = new wxButton(Panel10, ID_BUTTON1, _("Select >="), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer9->Add(Button_SelectGreaterValue, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel10->SetSizer(BoxSizer9);
    BoxSizer9->Fit(Panel10);
    BoxSizer9->SetSizeHints(Panel10);
    BoxSizer5->Add(Panel10, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel4 = new wxPanel(Panel_Controls, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    GridSizer1 = new wxGridSizer(3, 3, 0, 0);
    GridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton_SelectionUp = new wxBitmapButton(Panel4, ID_BITMAPBUTTON7, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_UP")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON7"));
    BitmapButton_SelectionUp->SetHelpText(_("Function not available!"));
    GridSizer1->Add(BitmapButton_SelectionUp, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton_SelectionLeft = new wxBitmapButton(Panel4, ID_BITMAPBUTTON9, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_BACK")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON9"));
    BitmapButton_SelectionLeft->SetHelpText(_("Function not available!"));
    GridSizer1->Add(BitmapButton_SelectionLeft, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton_SelectionInfo = new wxBitmapButton(Panel4, ID_BITMAPBUTTON11, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_HOME")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON11"));
    BitmapButton_SelectionInfo->SetHelpText(_("Show statistics of selected cells"));
    GridSizer1->Add(BitmapButton_SelectionInfo, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton_SelectionRight = new wxBitmapButton(Panel4, ID_BITMAPBUTTON8, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_FORWARD")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON8"));
    BitmapButton_SelectionRight->SetHelpText(_("Function not available!"));
    GridSizer1->Add(BitmapButton_SelectionRight, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton_SelectionDown = new wxBitmapButton(Panel4, ID_BITMAPBUTTON10, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_GO_DOWN")),wxART_BUTTON), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON10"));
    BitmapButton_SelectionDown->SetHelpText(_("Function not available!"));
    GridSizer1->Add(BitmapButton_SelectionDown, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel4->SetSizer(GridSizer1);
    GridSizer1->Fit(Panel4);
    GridSizer1->SetSizeHints(Panel4);
    BoxSizer5->Add(Panel4, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1 = new wxPanel(Panel_Controls, ID_PANEL9, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL9"));
    BoxSizer11 = new wxBoxSizer(wxVERTICAL);
    GridSizer2 = new wxGridSizer(2, 2, 0, 0);
    TextCtrl_TopLeft = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    GridSizer2->Add(TextCtrl_TopLeft, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_TopRight = new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    GridSizer2->Add(TextCtrl_TopRight, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_BottomLeft = new wxTextCtrl(Panel1, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    GridSizer2->Add(TextCtrl_BottomLeft, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_BottomRight = new wxTextCtrl(Panel1, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    GridSizer2->Add(TextCtrl_BottomRight, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer11->Add(GridSizer2, 2, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Button_Interpolation = new wxButton(Panel1, ID_BUTTON3, _("Interpolation"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer11->Add(Button_Interpolation, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer11);
    BoxSizer11->Fit(Panel1);
    BoxSizer11->SetSizeHints(Panel1);
    BoxSizer5->Add(Panel1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel_Controls->SetSizer(BoxSizer5);
    BoxSizer5->Fit(Panel_Controls);
    BoxSizer5->SetSizeHints(Panel_Controls);
    BoxSizer4->Add(Panel_Controls, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Panel7->SetSizer(BoxSizer4);
    BoxSizer4->Fit(Panel7);
    BoxSizer4->SetSizeHints(Panel7);
    BoxSizer2->Add(Panel7, 3, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    Panel_2DGraphs = new wxPanel(Panel_Frame, ID_PANEL8, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL8"));
    BoxSizer6 = new wxBoxSizer(wxVERTICAL);
    Panel2 = new wxPanel(Panel_2DGraphs, ID_PANEL2, wxDefaultPosition, wxSize(143,153), wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer7 = new wxBoxSizer(wxVERTICAL);
    StaticText_XAxis = new wxStaticText(Panel2, ID_STATICTEXT5, _("X Axis"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    BoxSizer7->Add(StaticText_XAxis, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    XChart = new simpleChart( Panel2 );
    BoxSizer7->Add(XChart, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel2->SetSizer(BoxSizer7);
    BoxSizer7->SetSizeHints(Panel2);
    BoxSizer6->Add(Panel2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel3 = new wxPanel(Panel_2DGraphs, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    BoxSizer10 = new wxBoxSizer(wxVERTICAL);
    StaticText_YAxis = new wxStaticText(Panel3, ID_STATICTEXT6, _("Y Axis"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    BoxSizer10->Add(StaticText_YAxis, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    YChart = new simpleChart( Panel3 );
    BoxSizer10->Add(YChart, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel3->SetSizer(BoxSizer10);
    BoxSizer10->Fit(Panel3);
    BoxSizer10->SetSizeHints(Panel3);
    BoxSizer6->Add(Panel3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel_2DGraphs->SetSizer(BoxSizer6);
    BoxSizer6->Fit(Panel_2DGraphs);
    BoxSizer6->SetSizeHints(Panel_2DGraphs);
    BoxSizer3->Add(Panel_2DGraphs, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Panel_Frame->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel_Frame);
    BoxSizer2->SetSizeHints(Panel_Frame);
    BoxSizer1->Add(Panel_Frame, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    MenuBar = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem8 = new wxMenuItem(Menu1, ID_MENUITEM7, _("Open absolute data"), _("Function not available!"), wxITEM_NORMAL);
    Menu1->Append(MenuItem8);
    MenuItem9 = new wxMenuItem(Menu1, ID_MENUITEM8, _("Open difference data"), _("Function not available!"), wxITEM_NORMAL);
    Menu1->Append(MenuItem9);
    Menu1->AppendSeparator();
    MenuItem10 = new wxMenuItem(Menu1, ID_MENUITEM9, _("Save absolute data"), _("Function not available!"), wxITEM_NORMAL);
    Menu1->Append(MenuItem10);
    MenuItem11 = new wxMenuItem(Menu1, ID_MENUITEM10, _("Save difference data"), _("Function not available!"), wxITEM_NORMAL);
    Menu1->Append(MenuItem11);
    Menu1->AppendSeparator();
    MenuItem_Apply = new wxMenuItem(Menu1, idMenuQuit, _("Apply\tAlt-F4"), _("Apply modifications to BIN"), wxITEM_NORMAL);
    Menu1->Append(MenuItem_Apply);
    MenuItem_Cancel = new wxMenuItem(Menu1, ID_MENUITEM16, _("Cancel"), _("Close without saving modifications"), wxITEM_NORMAL);
    Menu1->Append(MenuItem_Cancel);
    MenuBar->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem_Copy = new wxMenuItem(Menu2, ID_MENUITEM11, _("Copy to clipboard"), _("Copy selected data to clipboard"), wxITEM_NORMAL);
    Menu2->Append(MenuItem_Copy);
    MenuItem_Paste = new wxMenuItem(Menu2, ID_MENUITEM12, _("Paste from clipboard"), _("Paste data from clipboard"), wxITEM_NORMAL);
    Menu2->Append(MenuItem_Paste);
    Menu2->AppendSeparator();
    MenuItem_IncRaw = new wxMenuItem(Menu2, ID_MENUITEM21, _("Inc. raw value"), _("Increment raw value"), wxITEM_NORMAL);
    Menu2->Append(MenuItem_IncRaw);
    MenuItem_DecRaw = new wxMenuItem(Menu2, ID_MENUITEM22, _("Dec. raw value"), _("Decrement raw value"), wxITEM_NORMAL);
    Menu2->Append(MenuItem_DecRaw);
    MenuItem_IncPerc = new wxMenuItem(Menu2, ID_MENUITEM23, _("Inc. perc. value"), _("Increment by percentage"), wxITEM_NORMAL);
    Menu2->Append(MenuItem_IncPerc);
    MenuItem_DecPerc = new wxMenuItem(Menu2, ID_MENUITEM24, _("Dec. perc. value"), _("Decrement by percentage"), wxITEM_NORMAL);
    Menu2->Append(MenuItem_DecPerc);
    MenuItem_IncEng = new wxMenuItem(Menu2, ID_MENUITEM25, _("Inc. eng. value"), _("Increment engineering value"), wxITEM_NORMAL);
    Menu2->Append(MenuItem_IncEng);
    MenuItem_DecEng = new wxMenuItem(Menu2, ID_MENUITEM26, _("Dec. eng. value"), _("Decrement engineering value"), wxITEM_NORMAL);
    Menu2->Append(MenuItem_DecEng);
    MenuItem_FillValue = new wxMenuItem(Menu2, ID_MENUITEM18, _("Fill with value"), _("Fill selected cells with a value"), wxITEM_NORMAL);
    Menu2->Append(MenuItem_FillValue);
    Menu2->AppendSeparator();
    MenuItem2 = new wxMenuItem(Menu2, ID_MENUITEM1, _("Copy from BIN #1"), _("Function not available!"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuItem3 = new wxMenuItem(Menu2, ID_MENUITEM2, _("Copy from BIN #2"), _("Function not available!"), wxITEM_NORMAL);
    Menu2->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu2, ID_MENUITEM3, _("Copy from BIN #3"), _("Function not available!"), wxITEM_NORMAL);
    Menu2->Append(MenuItem4);
    MenuBar->Append(Menu2, _("&Modify"));
    Menu6 = new wxMenu();
    MenuItem_SelectCompareBIN1 = new wxMenuItem(Menu6, ID_MENUITEM4, _("Compare BIN #1"), _("Compare current BIN to BIN #1"), wxITEM_CHECK);
    Menu6->Append(MenuItem_SelectCompareBIN1);
    MenuItem_SelectCompareBIN2 = new wxMenuItem(Menu6, ID_MENUITEM5, _("Compare BIN #2"), _("Compare current BIN to BIN #2"), wxITEM_CHECK);
    Menu6->Append(MenuItem_SelectCompareBIN2);
    MenuItem_SelectCompareBIN3 = new wxMenuItem(Menu6, ID_MENUITEM6, _("Compare BIN #3"), _("Compare current BIN to BIN #3"), wxITEM_CHECK);
    Menu6->Append(MenuItem_SelectCompareBIN3);
    Menu6->AppendSeparator();
    MenuItem_ShowDifferences = new wxMenuItem(Menu6, ID_MENUITEM31, _("Show differences"), _("Show difference between current BIN and selected compare BIN"), wxITEM_CHECK);
    Menu6->Append(MenuItem_ShowDifferences);
    MenuItem_ShowRawValues = new wxMenuItem(Menu6, ID_MENUITEM32, _("Show raw values"), _("Show raw values on grid"), wxITEM_CHECK);
    Menu6->Append(MenuItem_ShowRawValues);
    Menu6->AppendSeparator();
    MenuItem_HighlightDifferences = new wxMenuItem(Menu6, ID_MENUITEM33, _("Highlight differences"), _("Highlight the cells that are different between the current BIN and the compare BIN"), wxITEM_CHECK);
    Menu6->Append(MenuItem_HighlightDifferences);
    MenuBar->Append(Menu6, _("&Compare"));
    Menu3 = new wxMenu();
    MenuItem_SelectAll = new wxMenuItem(Menu3, ID_MENUITEM13, _("Select all"), _("Select all cells"), wxITEM_NORMAL);
    Menu3->Append(MenuItem_SelectAll);
    MenuItem_InvertSelections = new wxMenuItem(Menu3, ID_MENUITEM17, _("Invert selections"), _("Invert cell selections"), wxITEM_NORMAL);
    Menu3->Append(MenuItem_InvertSelections);
    MenuItem_Select_None = new wxMenuItem(Menu3, ID_MENUITEM14, _("Clear selections"), _("Clear all cell selections"), wxITEM_NORMAL);
    Menu3->Append(MenuItem_Select_None);
    MenuItem_SelectValue = new wxMenuItem(Menu3, ID_MENUITEM15, _("Select by value"), _("Select cells by value"), wxITEM_NORMAL);
    Menu3->Append(MenuItem_SelectValue);
    MenuItem_SelectGreaterValue = new wxMenuItem(Menu3, ID_MENUITEM36, _("Select >= value"), _("Select cells which are greater then or equal to by value"), wxITEM_NORMAL);
    Menu3->Append(MenuItem_SelectGreaterValue);
    Menu3->AppendSeparator();
    MenuItem28 = new wxMenuItem(Menu3, ID_MENUITEM27, _("Move selection up"), _("Function not available!"), wxITEM_NORMAL);
    Menu3->Append(MenuItem28);
    MenuItem29 = new wxMenuItem(Menu3, ID_MENUITEM28, _("Move selection down"), _("Function not available!"), wxITEM_NORMAL);
    Menu3->Append(MenuItem29);
    MenuItem30 = new wxMenuItem(Menu3, ID_MENUITEM29, _("Move selection left"), _("Function not available!"), wxITEM_NORMAL);
    Menu3->Append(MenuItem30);
    MenuItem31 = new wxMenuItem(Menu3, ID_MENUITEM30, _("Move selection right"), _("Function not available!"), wxITEM_NORMAL);
    Menu3->Append(MenuItem31);
    MenuBar->Append(Menu3, _("&Select"));
    Menu5 = new wxMenu();
    MenuItem_2DView = new wxMenuItem(Menu5, ID_MENUITEM20, _("View Graphs"), _("Show 2D graphs side panel"), wxITEM_CHECK);
    Menu5->Append(MenuItem_2DView);
    MenuItem_ViewControls = new wxMenuItem(Menu5, ID_MENUITEM19, _("View Controls"), _("Show controls panel"), wxITEM_CHECK);
    Menu5->Append(MenuItem_ViewControls);
    MenuBar->Append(Menu5, _("&View"));
    Menu7 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu7, ID_MENUITEM34, _("2D Map Editor"), _("Function not available!"), wxITEM_NORMAL);
    Menu7->Append(MenuItem1);
    MenuItem_3DViewer = new wxMenuItem(Menu7, ID_MENUITEM35, _("3D Map Viewer"), _("Show 3D view of the map"), wxITEM_NORMAL);
    Menu7->Append(MenuItem_3DViewer);
    MenuBar->Append(Menu7, _("&Windows"));
    Menu8 = new wxMenu();
    MenuItem6 = new wxMenuItem(Menu8, ID_MENUITEM37, _("Tool Editor\tAlt-T"), _("Function not available!"), wxITEM_NORMAL);
    Menu8->Append(MenuItem6);
    Menu8->AppendSeparator();
    MenuBar->Append(Menu8, _("&Tools"));
    Menu4 = new wxMenu();
    MenuBar->Append(Menu4, _("&Plugins"));
    SetMenuBar(MenuBar);
    StatusBar = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[2] = { 300, -10 };
    int __wxStatusBarStyles_1[2] = { wxSB_NORMAL, wxSB_NORMAL };
    StatusBar->SetFieldsCount(2,__wxStatusBarWidths_1);
    StatusBar->SetStatusStyles(2,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_GRID1,wxEVT_GRID_CELL_CHANGE,(wxObjectEventFunction)&TableEditorFrame::OnGridCellChange);
    Connect(ID_GRID1,wxEVT_GRID_SELECT_CELL,(wxObjectEventFunction)&TableEditorFrame::OnGridCellSelect);
    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnBitmapButton_RawAddClick);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnBitmapButton_RawSubClick);
    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnBitmapButton_PercAddClick);
    Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnBitmapButton_PercSubClick);
    Connect(ID_BITMAPBUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnBitmapButton_EngAddClick);
    Connect(ID_BITMAPBUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnBitmapButton_EngSubClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnButton_FillValueClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnButton_SelectValueClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnButton_SelectGreaterValueClick);
    Connect(ID_BITMAPBUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnBitmapButton_SelectionInfoClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnButton_InterpolationClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_ApplySelected);
    Connect(ID_MENUITEM16,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_CancelSelected);
    Connect(ID_MENUITEM11,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_CopySelected);
    Connect(ID_MENUITEM12,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_PasteSelected);
    Connect(ID_MENUITEM21,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_IncRawSelected);
    Connect(ID_MENUITEM22,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_DecRawSelected);
    Connect(ID_MENUITEM23,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_IncPercSelected);
    Connect(ID_MENUITEM24,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_DecPercSelected);
    Connect(ID_MENUITEM25,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_IncEngSelected);
    Connect(ID_MENUITEM26,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_DecEngSelected);
    Connect(ID_MENUITEM18,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_FillValueSelected);
    Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_SelectCompareBIN1Selected);
    Connect(ID_MENUITEM5,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_SelectCompareBIN2Selected);
    Connect(ID_MENUITEM6,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_SelectCompareBIN3Selected);
    Connect(ID_MENUITEM31,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_ShowDifferencesSelected);
    Connect(ID_MENUITEM32,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_ShowRawValuesSelected);
    Connect(ID_MENUITEM33,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_HighlightDifferencesSelected);
    Connect(ID_MENUITEM13,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_SelectAllSelected);
    Connect(ID_MENUITEM17,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_InvertSelectionsSelected);
    Connect(ID_MENUITEM14,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_Select_NoneSelected);
    Connect(ID_MENUITEM15,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_SelectValueSelected);
    Connect(ID_MENUITEM36,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_SelectGreaterValueSelected);
    Connect(ID_MENUITEM20,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_2DViewSelected);
    Connect(ID_MENUITEM19,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_ViewControlsSelected);
    Connect(ID_MENUITEM35,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&TableEditorFrame::OnMenuItem_3DViewerSelected);
    Connect(wxEVT_SIZE,(wxObjectEventFunction)&TableEditorFrame::OnResize);
    //*)

    wxMemoryInputStream icon_apply_stream(toolbar_apply_png, sizeof toolbar_apply_png);
    wxImage icon_apply = wxImage(icon_apply_stream, wxBITMAP_TYPE_PNG);

    wxMemoryInputStream icon_cancel_stream(toolbar_cancel_png, sizeof toolbar_cancel_png);
    wxImage icon_cancel = wxImage(icon_cancel_stream, wxBITMAP_TYPE_PNG);

    wxMemoryInputStream icon_copy_stream(toolbar_copy_png, sizeof toolbar_copy_png);
    wxImage icon_copy = wxImage(icon_copy_stream, wxBITMAP_TYPE_PNG);

    wxMemoryInputStream icon_paste_stream(toolbar_paste_png, sizeof toolbar_paste_png);
    wxImage icon_paste = wxImage(icon_paste_stream, wxBITMAP_TYPE_PNG);

    wxMemoryInputStream icon_differences_stream(toolbar_differences_png, sizeof toolbar_differences_png);
    wxImage icon_differences = wxImage(icon_differences_stream, wxBITMAP_TYPE_PNG);

    wxMemoryInputStream icon_highlight_stream(toolbar_highlight_png, sizeof toolbar_highlight_png);
    wxImage icon_highlight = wxImage(icon_highlight_stream, wxBITMAP_TYPE_PNG);

    wxMemoryInputStream g2d_icon_stream(toolbar_2d_png, sizeof toolbar_2d_png);
    wxImage icon_2d = wxImage(g2d_icon_stream, wxBITMAP_TYPE_PNG);

    wxMemoryInputStream g3d_icon_stream(toolbar_3d_png, sizeof toolbar_3d_png);
    wxImage icon_3d = wxImage(g3d_icon_stream, wxBITMAP_TYPE_PNG);

    ToolBar = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxNO_BORDER, _T("ID_TOOLBAR1"));
    //ToolBar->SetToolBitmapSize(wxSize(48,48));
    ToolBarItem1 = ToolBar->AddTool(ID_TOOLBARITEM1, _("Apply"), wxBitmap(icon_apply), wxNullBitmap, wxITEM_NORMAL, _("Apply modifications to BIN"), _("Apply modifications to BIN"));
    ToolBarItem2 = ToolBar->AddTool(ID_TOOLBARITEM2, _("Cancel"), wxBitmap(icon_cancel), wxNullBitmap, wxITEM_NORMAL, _("Close table editor"), _("Close table editor"));
    ToolBar->AddSeparator();
    ToolBarItem3 = ToolBar->AddTool(ID_TOOLBARITEM3, _("Copy to clipboard"), wxBitmap(icon_copy), wxNullBitmap, wxITEM_NORMAL, _("Copy selection to clipboard"), _("Copy selection to clipboard"));
    ToolBarItem4 = ToolBar->AddTool(ID_TOOLBARITEM4, _("Paste from clipboard"), wxBitmap(icon_paste), wxNullBitmap, wxITEM_NORMAL, _("Paste selection from clipboard"), _("Paste selection from clipboard"));
    ToolBar->AddSeparator();
    ToolBarItem5 = ToolBar->AddTool(ID_TOOLBARITEM5, _("Show Differences"), wxBitmap(icon_differences), wxNullBitmap, wxITEM_NORMAL, _("Show Differences"), _("Show Differences"));
    ToolBarItem6 = ToolBar->AddTool(ID_TOOLBARITEM6, _("Highlight Differences"), wxBitmap(icon_highlight), wxNullBitmap, wxITEM_NORMAL, _("Highlight Differences"), _("Highlight Differences"));
    ToolBar->AddSeparator();
    ToolBarItem7 = ToolBar->AddTool(ID_TOOLBARITEM7, _("Edit in 2D"), wxBitmap(icon_2d), wxNullBitmap, wxITEM_NORMAL, _("Edit map in 2D"), _("Edit map in 2D"));
    ToolBarItem8 = ToolBar->AddTool(ID_TOOLBARITEM8, _("View 3D"), wxBitmap(icon_3d), wxNullBitmap, wxITEM_NORMAL, _("View map in 3D"),  _("View map in 3D"));
    ToolBar->Realize();
    SetToolBar(ToolBar);

    BoxSizer1->Fit(this);
    //BoxSizer1->SetSizeHints(this);

    Connect(ID_TOOLBARITEM1,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnToolBarItem_ApplyClicked);
    Connect(ID_TOOLBARITEM2,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnToolBarItem_CancelClicked);
    Connect(ID_TOOLBARITEM3,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnToolBarItem_CopyClicked);
    Connect(ID_TOOLBARITEM4,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnToolBarItem_PasteClicked);
    Connect(ID_TOOLBARITEM5,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnToolBarItem_DifferenceClicked);
    Connect(ID_TOOLBARITEM6,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnToolBarItem_HighlightClicked);
    //Connect(ID_TOOLBARITEM7,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnToolBarItem_2DEditClicked);
    Connect(ID_TOOLBARITEM8,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&TableEditorFrame::OnToolBarItem_3DViewClicked);

    // Disable Column/Row resizing
    Grid->EnableDragGridSize(false);
    Grid->EnableDragColSize(false);
    Grid->EnableDragRowSize(false);

    // Default settings
    MenuItem_ViewControls->Check(true);
    MenuItem_2DView->Check(true);

    // Refresh to show layout correctly
    Panel_Frame->GetSizer()->Layout();
}

TableEditorFrame::~TableEditorFrame()
{
    //(*Destroy(TableEditorFrame)
    //*)
}

void TableEditorFrame::OnResize(wxSizeEvent& event)
{
    XChart->Refresh();
    YChart->Refresh();

    event.Skip();
}

/// ---------------------------------------------------------------------------
/// Menu Functions
/// ---------------------------------------------------------------------------

// FILE -----------------------------------------------------------------------

void TableEditorFrame::OnMenuItem_ApplySelected(wxCommandEvent& event)
{
    unsigned int bytes;

    if (global->xmlaxis[current_map][2].bits==8)
        bytes=1;
    else if (global->xmlaxis[current_map][2].bits==16)
        bytes=2;
    else
        bytes=4;

    unsigned int length=(unsigned int)global->xmlaxis[current_map][0].count * (unsigned int)global->xmlaxis[current_map][1].count * bytes;

    for (unsigned int x=0; x < length; x++)
        global->bin_buffer[selected_bin][global->xmlaxis[current_map][2].address + x]=temp_buffer[x];

    Close();
}

void TableEditorFrame::OnMenuItem_CancelSelected(wxCommandEvent& event)
{
    Close();
}

// MODIFY ---------------------------------------------------------------------

void TableEditorFrame::OnMenuItem_CopySelected(wxCommandEvent& event)
{
    wxString data;

    if (MenuItem_ShowRawValues->IsChecked())
        data =_T("RAW");
    else
        data =_T("ENG");

    if (MenuItem_ShowDifferences->IsChecked())
        data+=_T("-DIF");
    else
        data+=_T("-ABS");

    for (int x=0; x < Grid->GetNumberCols(); x++)
    {
        for (int y=0; y < Grid->GetNumberRows(); y++)
        {
            if (Grid->IsInSelection(y,x))
            {
                data+=_T("@") + wxString::Format(wxT("%i"),y) +
                      _T(":") + wxString::Format(wxT("%i"),x) +
                      _T("=") + Grid->GetCellValue(y,x);
            }
        }
    }

    if (wxTheClipboard->Open())
    {
        wxTheClipboard->SetData(new wxTextDataObject(data));
        wxTheClipboard->Close();

        StatusBar->SetStatusText(_("Data copied to clipboard."),1);
    }
}

void TableEditorFrame::OnMenuItem_PasteSelected(wxCommandEvent& event)
{
    wxString data, str;
    long l_value;
    int idx1,idx2,idx3=0,y,x;
    double value;

    if (wxTheClipboard->Open())
    {
        if (wxTheClipboard->IsSupported(wxDF_TEXT))
        {
            wxTextDataObject clip_data;
            wxTheClipboard->GetData(clip_data);
            data=clip_data.GetText();
        }
        wxTheClipboard->Close();

        bool type_raw;
        if (data.substr(0,3)==_T("RAW"))
            type_raw=true;
        else if (data.substr(0,3)==_T("ENG"))
            type_raw=false;
        else
        {
            StatusBar->SetStatusText(_("No data to be pasted!"),1);
            return;
        }

        bool type_abs;
        if (data.substr(4,3)==_T("ABS"))
            type_abs=true;
        else if (data.substr(4,3)==_T("DIF"))
        {
            type_abs=false;

            if (GetSelectedDifferenceBin() < 0)
            {
                StatusBar->SetStatusText(_("Please select a compare BIN before pasting difference values!"),1);
                return;
            }
        }
        else
        {
            StatusBar->SetStatusText(_("No data to be pasted!"),1);
            return;
        }

        data=data.substr(7,data.Len());
        while (1)
        {
            if (data.substr(0,1)==_T("@"))
            {
                // Find Y value
                idx1=data.Find(_T(":")); //wxNOT_FOUND
                str=data.substr(1,idx1-1);
                if(!str.ToLong(&l_value))
                {
                    StatusBar->SetStatusText(_("Error in extracting Y co-ordinate!"),1);
                    return;
                }
                y=(int)l_value;

                // Find X value
                idx1++;
                idx2=data.Find(_T("=")); //wxNOT_FOUND
                str=data.substr(idx1,idx2-idx1);
                if(!str.ToLong(&l_value))
                {
                    StatusBar->SetStatusText(_("Error in extracting X co-ordinate!"),1);
                    return;
                }
                x=(int)l_value;

                // Find Z value
                data=data.substr(1,data.Len());
                idx3=data.Find(_T("@"));
                if (idx3==wxNOT_FOUND)
                    idx3=(int)data.Len();
                str=data.substr(idx2,idx3-idx2);
                if (!str.ToDouble(&value))
                {
                    StatusBar->SetStatusText(_("Error in extracting data value!"),1);
                    return;
                }

                unsigned int address=ConvertXYToAddress(x,y);

                // Difference paste
                if (!type_abs)
                {
                    int diff_bin=GetSelectedDifferenceBin();
                    if (!type_raw)
                        value+=GetEngineeringValueFromAddress(global->bin_buffer[diff_bin], global->xmlaxis[current_map][2].address + address, 2);
                    else
                        value+=GetRawValueFromAddress(global->bin_buffer[diff_bin], global->xmlaxis[current_map][2].address + address, 2);
                }

                // Write data to buffer
                if (type_raw)
                    SetRawValueToAddress(temp_buffer, address, 2, (int)value);
                else
                    SetEngineeringValueToAddress(temp_buffer, address, 2, value);


                UpdateCellValue(x,y,address);
            }

            if (idx3==(int)data.Len()) break;
            data=data.substr(idx3,data.Len());
        }
    }

}

void TableEditorFrame::OnMenuItem_IncRawSelected(wxCommandEvent& event)
{
    OnBitmapButton_RawAddClick(event);
}

void TableEditorFrame::OnMenuItem_DecRawSelected(wxCommandEvent& event)
{
    OnBitmapButton_RawSubClick(event);
}

void TableEditorFrame::OnMenuItem_IncPercSelected(wxCommandEvent& event)
{
    OnBitmapButton_PercAddClick(event);
}

void TableEditorFrame::OnMenuItem_DecPercSelected(wxCommandEvent& event)
{
    OnBitmapButton_PercSubClick(event);
}

void TableEditorFrame::OnMenuItem_IncEngSelected(wxCommandEvent& event)
{
    OnBitmapButton_EngAddClick(event);
}

void TableEditorFrame::OnMenuItem_DecEngSelected(wxCommandEvent& event)
{
    OnBitmapButton_EngSubClick(event);
}

void TableEditorFrame::OnMenuItem_FillValueSelected(wxCommandEvent& event)
{
    OnButton_FillValueClick(event);
}

// COMPARE --------------------------------------------------------------------

void TableEditorFrame::OnMenuItem_SelectCompareBIN1Selected(wxCommandEvent& event)
{
    if (MenuItem_SelectCompareBIN1->IsChecked())
    {
        MenuItem_SelectCompareBIN2->Check(false);
        MenuItem_SelectCompareBIN3->Check(false);
    }

    SetCaption();
    OnMenuItem_ShowDifferencesSelected(event);
}

void TableEditorFrame::OnMenuItem_SelectCompareBIN2Selected(wxCommandEvent& event)
{
    if (MenuItem_SelectCompareBIN2->IsChecked())
    {
        MenuItem_SelectCompareBIN1->Check(false);
        MenuItem_SelectCompareBIN3->Check(false);
    }

    SetCaption();
    OnMenuItem_ShowDifferencesSelected(event);
}

void TableEditorFrame::OnMenuItem_SelectCompareBIN3Selected(wxCommandEvent& event)
{
    if (MenuItem_SelectCompareBIN3->IsChecked())
    {
        MenuItem_SelectCompareBIN1->Check(false);
        MenuItem_SelectCompareBIN2->Check(false);
    }

    SetCaption();
    OnMenuItem_ShowDifferencesSelected(event);
}

void TableEditorFrame::OnMenuItem_ShowDifferencesSelected(wxCommandEvent& event)
{
    if (MenuItem_ShowDifferences->IsChecked())
    {
        if ((!MenuItem_SelectCompareBIN1->IsChecked()) &&
            (!MenuItem_SelectCompareBIN2->IsChecked()) &&
            (!MenuItem_SelectCompareBIN3->IsChecked()))
        {
            StatusBar->SetStatusText(_("Please select a BIN file for comparison."),1);
            MenuItem_ShowDifferences->Check(false);

            UpdateGrid();
        }
        else
            UpdateGridDifferences();
    }
    else
        UpdateGrid();

    // Refresh to show layout correctly
    Panel_Frame->GetSizer()->Layout();
}

void TableEditorFrame::OnMenuItem_ShowRawValuesSelected(wxCommandEvent& event)
{
    if (MenuItem_ShowDifferences->IsChecked())
    {
        if ((MenuItem_SelectCompareBIN1->IsChecked()) ||
            (MenuItem_SelectCompareBIN2->IsChecked()) ||
            (MenuItem_SelectCompareBIN3->IsChecked()))
        {
            UpdateGridDifferences();
        }
        else
            UpdateGrid();
    }
    else
        UpdateGrid();

    // Refresh to show layout correctly
    Panel_Frame->GetSizer()->Layout();
}

void TableEditorFrame::OnMenuItem_HighlightDifferencesSelected(wxCommandEvent& event)
{
    if (MenuItem_ShowDifferences->IsChecked())
    {
        if ((MenuItem_SelectCompareBIN1->IsChecked()) ||
            (MenuItem_SelectCompareBIN2->IsChecked()) ||
            (MenuItem_SelectCompareBIN3->IsChecked()))
        {
            UpdateGridDifferences();
        }
        else
            UpdateGrid();
    }
    else
        UpdateGrid();

    // Refresh to show layout correctly
    Panel_Frame->GetSizer()->Layout();
}

// SELECT ---------------------------------------------------------------------

void TableEditorFrame::OnMenuItem_SelectAllSelected(wxCommandEvent& event)
{
    Grid->SelectAll();
}

void TableEditorFrame::OnMenuItem_InvertSelectionsSelected(wxCommandEvent& event)
{
    if (!Grid->IsSelection())
    {
        Grid->SelectAll();
        return;
    }

    // Create dynamic array
    bool **sel_array = 0;
    sel_array = new bool *[Grid->GetNumberRows()] ;

    for(int i = 0 ; i < Grid->GetNumberRows() ; i++)
        sel_array[i] = new bool[Grid->GetNumberCols()];

    // Fill array with selection data
    for (int x=0; x < Grid->GetNumberCols(); x++)
    {
        for (int y=0; y < Grid->GetNumberRows(); y++)
        {
            if (Grid->IsInSelection(y,x))
                sel_array[x][y]=true;
            else
                sel_array[x][y]=false;
        }
    }

    // Invert selection
    Grid->ClearSelection();
    for (int x=0; x < Grid->GetNumberCols(); x++)
    {
        for (int y=0; y < Grid->GetNumberRows(); y++)
        {
            if (!sel_array[x][y])
                Grid->SelectBlock(y, x, y, x, true);
        }
    }

    // Free allocated memory
    for(int i = 0 ; i < Grid->GetNumberRows(); i++)
        delete [] sel_array[i] ;

    delete [] sel_array;
}

void TableEditorFrame::OnMenuItem_Select_NoneSelected(wxCommandEvent& event)
{
    Grid->ClearSelection();
}

void TableEditorFrame::OnMenuItem_SelectValueSelected(wxCommandEvent& event)
{
    OnButton_SelectValueClick(event);
}

void TableEditorFrame::OnMenuItem_SelectGreaterValueSelected(wxCommandEvent& event)
{
    OnButton_SelectGreaterValueClick(event);
}

// VIEW -----------------------------------------------------------------------

void TableEditorFrame::OnMenuItem_2DViewSelected(wxCommandEvent& event)
{
    if (MenuItem_2DView->IsChecked()) Panel_2DGraphs->Show();
    else Panel_2DGraphs->Hide();

    // Refresh to show layout correctly
    Panel_Frame->GetSizer()->Layout();
}

void TableEditorFrame::OnMenuItem_ViewControlsSelected(wxCommandEvent& event)
{
    if (MenuItem_ViewControls->IsChecked()) Panel_Controls->Show();
    else Panel_Controls->Hide();

    // Refresh to show layout correctly
    Panel_Frame->GetSizer()->Layout();
}

// WINDOWS --------------------------------------------------------------------

void TableEditorFrame::OnMenuItem_3DViewerSelected(wxCommandEvent& event)
{
    // Ceate control file -----------------------------------------------------

    if (wxFileExists(_T("3d_plot")))
        wxRemoveFile(_T("3d_plot"));

    wxTextFile ctrl_file(_T("3d_plot"));
    if (!ctrl_file.Create())
    {
        StatusBar->SetStatusText(_("Error creating file '3d_plot'!"),1);
        return;
    }

    ctrl_file.AddLine(_T("set title \"") + global->xmltable[current_map].title + _T("\""));
    ctrl_file.AddLine(_T("set xlabel \"") + global->xmlaxis[current_map][0].units +  _T("\""));
    ctrl_file.AddLine(_T("set ylabel \"") + global->xmlaxis[current_map][1].units +  _T("\""));
    ctrl_file.AddLine(_T("set zlabel \"") + global->xmlaxis[current_map][2].units +  _T("\""));
    ctrl_file.AddLine(_T("set pm3d"));
    ctrl_file.AddLine(_T("splot \"3d_data.gnuplot\" with lines"));
    //ctrl_file.AddLine(_T("pause -1"));

	if (!ctrl_file.Write())
    {
        StatusBar->SetStatusText(_("Error writing file '3d_plot'!"),1);
        return;
    }

	if (!ctrl_file.Close())
    {
        StatusBar->SetStatusText(_("Error closing file '3d_plot'!"),1);
        return;
    }

    // Create data file -------------------------------------------------------

    if (wxFileExists(_T("3d_data.gnuplot")))
        wxRemoveFile(_T("3d_data.gnuplot"));

    wxTextFile data_file(_T("3d_data.gnuplot"));
    if (!data_file.Create())
    {
        StatusBar->SetStatusText(_("Error creating file '3d_data.gnuplot'!"),1);
        return;
    }

    for (int x=0; x < Grid->GetNumberCols(); x++)
    {
        wxString x_str=Grid->GetColLabelValue(x);

        for (int y=0; y < Grid->GetNumberRows(); y++)
        {
            wxString y_str=Grid->GetRowLabelValue(y);
            wxString z_str=Grid->GetCellValue(y,x);

            data_file.AddLine(x_str + _T(" ") + y_str + _T(" ") + z_str);
        }

        data_file.AddLine(_T(""));
    }

	if (!data_file.Write())
    {
        StatusBar->SetStatusText(_("Error writing file '3d_data.gnuplot'!"),1);
        return;
    }

	if (!data_file.Close())
    {
        StatusBar->SetStatusText(_("Error closing file '3d_data.gnuplot'!"),1);
        return;
    }

#if defined (WIN32)
    wxExecute(_T("gnuplot\\gnuplot.exe 3d_plot -"));
#else
    wxExecute(_T("gnuplot 3d_plot -"));
#endif
}

/// ---------------------------------------------------------------------------
/// Toolbar Functions
/// ---------------------------------------------------------------------------

void TableEditorFrame::OnToolBarItem_ApplyClicked(wxCommandEvent& event)
{
    OnMenuItem_ApplySelected(event);
}

void TableEditorFrame::OnToolBarItem_CancelClicked(wxCommandEvent& event)
{
    Close();
}

void TableEditorFrame::OnToolBarItem_CopyClicked(wxCommandEvent& event)
{
    OnMenuItem_CopySelected(event);
}

void TableEditorFrame::OnToolBarItem_PasteClicked(wxCommandEvent& event)
{
    OnMenuItem_PasteSelected(event);
}

void TableEditorFrame::OnToolBarItem_DifferenceClicked(wxCommandEvent& event)
{
    if (MenuItem_ShowDifferences->IsChecked())
        MenuItem_ShowDifferences->Check(false);
    else
        MenuItem_ShowDifferences->Check(true);

    OnMenuItem_ShowDifferencesSelected(event);
}

void TableEditorFrame::OnToolBarItem_HighlightClicked(wxCommandEvent& event)
{
    if (MenuItem_HighlightDifferences->IsChecked())
        MenuItem_HighlightDifferences->Check(false);
    else
        MenuItem_HighlightDifferences->Check(true);

    OnMenuItem_HighlightDifferencesSelected(event);
}
/*
void TableEditorFrame::OnToolBarItem_2DEditClicked(wxCommandEvent& event)
{
}
*/
void TableEditorFrame::OnToolBarItem_3DViewClicked(wxCommandEvent& event)
{
    OnMenuItem_3DViewerSelected(event);
}

/// ---------------------------------------------------------------------------
/// Button Event Handlers
/// ---------------------------------------------------------------------------

void TableEditorFrame::OnBitmapButton_RawAddClick(wxCommandEvent& event)
{
    unsigned short c=CalculateRaw(OPERATION_ADD);
    StatusBar->SetStatusText(_("Raw number added to ") + wxString::Format(_T("%i"),c) + _(" cells."),1);
}

void TableEditorFrame::OnBitmapButton_RawSubClick(wxCommandEvent& event)
{
    unsigned short c=CalculateRaw(OPERATION_SUB);
    StatusBar->SetStatusText(_("Raw number subtracted from ") + wxString::Format(_T("%i"),c) + _(" cells."),1);
}

void TableEditorFrame::OnBitmapButton_PercAddClick(wxCommandEvent& event)
{
    if (TextCtrl_Perc->IsEmpty())
    {
        StatusBar->SetStatusText(_("Please insert a number in the percentage field!"),1);
        return;
    }

    unsigned short c=CalculatePercentage(OPERATION_ADD);
    StatusBar->SetStatusText(_("Percentage added to ") + wxString::Format(_T("%i"),c) + _(" cells."),1);
}

void TableEditorFrame::OnBitmapButton_PercSubClick(wxCommandEvent& event)
{
    if (TextCtrl_Perc->IsEmpty())
    {
        StatusBar->SetStatusText(_("Please insert a number in the percentage field!"),1);
        return;
    }

    unsigned short c=CalculatePercentage(OPERATION_SUB);
    StatusBar->SetStatusText(_("Percentage subtracted from ") + wxString::Format(_T("%i"),c) + _(" cells."),1);
}

void TableEditorFrame::OnBitmapButton_EngAddClick(wxCommandEvent& event)
{
    if (TextCtrl_Eng->IsEmpty())
    {
        StatusBar->SetStatusText(_("Please insert a number in the engineering field!"),1);
        return;
    }

    unsigned short c=CalculateEngineering(OPERATION_ADD);
    StatusBar->SetStatusText(_("Engineering number added to ") + wxString::Format(_T("%i"),c) + _(" cells."),1);
}

void TableEditorFrame::OnBitmapButton_EngSubClick(wxCommandEvent& event)
{
    if (TextCtrl_Eng->IsEmpty())
    {
        StatusBar->SetStatusText(_("Please insert a number in the engineering field!"),1);
        return;
    }

    unsigned short c=CalculateEngineering(OPERATION_SUB);
    StatusBar->SetStatusText(_("Engineering number subtracted from ") + wxString::Format(_T("%i"),c) + _(" cells."),1);
}

void TableEditorFrame::OnButton_FillValueClick(wxCommandEvent& event)
{
    unsigned short c=0;
    unsigned int address;

    // Fill with raw value
    if (RadioButton_Raw->GetValue())
    {
        int raw_value;
        //double eng_value;

        for (int x=0; x < Grid->GetNumberCols(); x++)
        {
            for (int y=0; y < Grid->GetNumberRows(); y++)
            {
                if (Grid->IsInSelection(y,x))
                {
                    address=ConvertXYToAddress(x,y);
                    raw_value=SpinCtrl_Raw->GetValue();
                    SetRawValueToAddress(temp_buffer, address, 2, raw_value);
                    /*
                    if (MenuItem_ShowRawValues->IsChecked())
                    {
                        raw_value=GetRawValueFromAddress(temp_buffer, address, 2);
                        SetRawValueToGrid(x,y,2,raw_value);
                    }
                    else
                    {
                        eng_value=GetEngineeringValueFromAddress(temp_buffer, address, 2);
                        SetEngineeringValueToGrid(x,y,2,eng_value);
                    }
                    */
                    UpdateCellValue(x, y, address);

                    c++;
                }
            }
        }

        StatusBar->SetStatusText(_("Raw number set on ") + wxString::Format(_T("%i"),c) + _(" cells."),1);
    }
    // Fill with engineering value
    else if (RadioButton_Eng->GetValue())
    {
        double eng_value;
        //int raw_value;

        wxString str=TextCtrl_Eng->GetValue();
        if (!str.ToDouble(&eng_value))
        {
            StatusBar->SetStatusText(_("This is not a valid number!"),1);
            TextCtrl_Eng->SetForegroundColour(wxColor(255,0,0));
            return;
        }

        TextCtrl_Eng->SetForegroundColour(wxColor(0,0,0));

        for (int x=0; x < Grid->GetNumberCols(); x++)
        {
            for (int y=0; y < Grid->GetNumberRows(); y++)
            {
                if (Grid->IsInSelection(y,x))
                {
                    address=ConvertXYToAddress(x,y);
                    SetEngineeringValueToAddress(temp_buffer, address, 2, eng_value);
                    /*
                    if (MenuItem_ShowRawValues->IsChecked())
                    {
                        raw_value=GetRawValueFromAddress(temp_buffer, address, 2);
                        SetRawValueToGrid(x,y,2,raw_value);
                    }
                    else
                    {
                        eng_value=GetEngineeringValueFromAddress(temp_buffer, address, 2);
                        SetEngineeringValueToGrid(x,y,2,eng_value);
                    }
                    */
                    UpdateCellValue(x, y, address);

                    c++;
                }
            }
        }

        StatusBar->SetStatusText(_("Engineering number set on ") + wxString::Format(_T("%i"),c) + _(" cells."),1);
    }
    else
        StatusBar->SetStatusText(_("Filling is only available for raw & engineering numbers."),1);
}

void TableEditorFrame::OnButton_SelectValueClick(wxCommandEvent& event)
{
    unsigned short c=0;
    unsigned int address;

    // Select by raw value
    if (RadioButton_Raw->GetValue())
    {
        int raw_value;

        Grid->ClearSelection();

        for (int x=0; x < Grid->GetNumberCols(); x++)
        {
            for (int y=0; y < Grid->GetNumberRows(); y++)
            {
                address=ConvertXYToAddress(x,y);
                raw_value=GetRawValueFromAddress(temp_buffer, address, 2);

                if (raw_value==SpinCtrl_Raw->GetValue())
                {
                    Grid->SelectBlock(y, x, y, x, true);
                    c++;
                }
            }
        }

        StatusBar->SetStatusText(_("Selected ") + wxString::Format(_T("%i"),c) + _(" cells."),1);
    }
    // Select by engineering value
    else if (RadioButton_Eng->GetValue())
    {
        double value, eng_value;

        wxString str=TextCtrl_Eng->GetValue();
        if (!str.ToDouble(&value))
        {
            StatusBar->SetStatusText(_("This is not a valid number!"),1);
            TextCtrl_Eng->SetForegroundColour(wxColor(255,0,0));
            return;
        }

        TextCtrl_Eng->SetForegroundColour(wxColor(0,0,0));
        Grid->ClearSelection();

        for (int x=0; x < Grid->GetNumberCols(); x++)
        {
            for (int y=0; y < Grid->GetNumberRows(); y++)
            {
                address=ConvertXYToAddress(x,y);
                eng_value=GetEngineeringValueFromAddress(temp_buffer, address, 2);

                if (eng_value==value)
                {
                    Grid->SelectBlock(y, x, y, x, true);
                    c++;
                }
            }
        }

        StatusBar->SetStatusText(_("Selected ") + wxString::Format(_T("%i"),c) + _(" cells."),1);
    }
    else
        StatusBar->SetStatusText(_("Selection by value is only available for raw & engineering numbers."),1);
}

void TableEditorFrame::OnButton_SelectGreaterValueClick(wxCommandEvent& event)
{
    unsigned short c=0;
    unsigned int address;

    // Select by raw value
    if (RadioButton_Raw->GetValue())
    {
        int raw_value;

        Grid->ClearSelection();

        for (int x=0; x < Grid->GetNumberCols(); x++)
        {
            for (int y=0; y < Grid->GetNumberRows(); y++)
            {
                address=ConvertXYToAddress(x,y);
                raw_value=GetRawValueFromAddress(temp_buffer, address, 2);

                if (raw_value >= SpinCtrl_Raw->GetValue())
                {
                    Grid->SelectBlock(y, x, y, x, true);
                    c++;
                }
            }
        }

        StatusBar->SetStatusText(_("Selected ") + wxString::Format(_T("%i"),c) + _(" cells."),1);
    }
    // Select by engineering value
    else if (RadioButton_Eng->GetValue())
    {
        double value, eng_value;

        wxString str=TextCtrl_Eng->GetValue();
        if (!str.ToDouble(&value))
        {
            StatusBar->SetStatusText(_("This is not a valid number!"),1);
            TextCtrl_Eng->SetForegroundColour(wxColor(255,0,0));
            return;
        }

        TextCtrl_Eng->SetForegroundColour(wxColor(0,0,0));
        Grid->ClearSelection();

        for (int x=0; x < Grid->GetNumberCols(); x++)
        {
            for (int y=0; y < Grid->GetNumberRows(); y++)
            {
                address=ConvertXYToAddress(x,y);
                eng_value=GetEngineeringValueFromAddress(temp_buffer, address, 2);

                if (eng_value >= value)
                {
                    Grid->SelectBlock(y, x, y, x, true);
                    c++;
                }
            }
        }

        StatusBar->SetStatusText(_("Selected ") + wxString::Format(_T("%i"),c) + _(" cells."),1);
    }
    else
        StatusBar->SetStatusText(_("Selection by value is only available for raw & engineering numbers."),1);
}

void TableEditorFrame::OnBitmapButton_SelectionInfoClick(wxCommandEvent& event)
{
    double average=0, eng_value, min=2147483647, max=-2147483647;
    unsigned short c=0;
    unsigned int address;

    for (int x=0; x < Grid->GetNumberCols(); x++)
    {
        for (int y=0; y < Grid->GetNumberRows(); y++)
        {
            if (Grid->IsInSelection(y,x))
            {
                address=ConvertXYToAddress(x,y);
                eng_value=GetEngineeringValueFromAddress(temp_buffer, address, 2);

                if (eng_value > max)
                    max=eng_value;

                if (eng_value < min)
                    min=eng_value;

                average+=eng_value;
                c++;
            }
        }
    }

    average/=(double)c;

    StatusBar->SetStatusText(_("COUNT=") + wxString::Format(_T("%i"),c) +
                             _(" MIN=") + wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][2].decimalpl) + _T("f"),min) +
                             _(" AVG=") + wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][2].decimalpl) + _T("f"),average) +
                             _(" MAX=") + wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][2].decimalpl) + _T("f"),max),1);
}

void TableEditorFrame::OnButton_InterpolationClick(wxCommandEvent& event)
{
    unsigned short c=0;
    unsigned int address;
    int col_start=Grid->GetNumberCols(),
        col_end=0,
        row_start=Grid->GetNumberRows(),
        row_end=0,
        steps_x,
        steps_y;
    double step_x_factor, step_y_factor;

    // Find start & end of columns & rows selected
    for (int x=0; x < Grid->GetNumberCols(); x++)
    {
        for (int y=0; y < Grid->GetNumberRows(); y++)
        {
            if (Grid->IsInSelection(y,x))
            {
                if (x < col_start)
                    col_start=x;

                if (x > col_end)
                    col_end=x;

                if (y < row_start)
                    row_start=y;

                if (y > row_end)
                    row_end=y;
            }
        }
    }

    steps_x=col_end - col_start;
    step_x_factor=1 / (double)steps_x;

    steps_y=row_end - row_start;
    step_y_factor=1 / (double)steps_y;

    // Interpolation with raw value
    if (RadioButton_Raw->GetValue())
    {
        int raw_value, value;
        //double eng_value;
        long top_left, top_right, bottom_left, bottom_right;

        if(!TextCtrl_TopLeft->GetValue().ToLong(&top_left))
        {
            StatusBar->SetStatusText(_("This is not a valid number!"),1);
            TextCtrl_TopLeft->SetForegroundColour(wxColor(255,0,0));
            return;
        }

        if(!TextCtrl_TopRight->GetValue().ToLong(&top_right))
        {
            StatusBar->SetStatusText(_("This is not a valid number!"),1);
            TextCtrl_TopRight->SetForegroundColour(wxColor(255,0,0));
            return;
        }

        if(!TextCtrl_BottomLeft->GetValue().ToLong(&bottom_left))
        {
            StatusBar->SetStatusText(_("This is not a valid number!"),1);
            TextCtrl_BottomLeft->SetForegroundColour(wxColor(255,0,0));
            return;
        }

        if(!TextCtrl_BottomRight->GetValue().ToLong(&bottom_right))
        {
            StatusBar->SetStatusText(_("This is not a valid number!"),1);
            TextCtrl_BottomRight->SetForegroundColour(wxColor(255,0,0));
            return;
        }

        TextCtrl_TopLeft->SetForegroundColour(wxColor(0,0,0));
        TextCtrl_TopRight->SetForegroundColour(wxColor(0,0,0));
        TextCtrl_BottomLeft->SetForegroundColour(wxColor(0,0,0));
        TextCtrl_BottomRight->SetForegroundColour(wxColor(0,0,0));

        double current_top=(double)top_left,
               current_bottom=(double)bottom_left;

        double x_pos=1;
        for (int x=col_start; x <= col_end; x++)
        {
            double y_pos=0;

            for (int y=row_start; y <= row_end; y++)
            {
                if (Grid->IsInSelection(y,x))
                {
                    value=(int)ceil(current_top + ((current_bottom - current_top) * (step_y_factor * y_pos)));

                    address=ConvertXYToAddress(x,y);
                    raw_value=GetRawValueFromAddress(temp_buffer, address, 2) + value;
                    /*
                    if (operation==OPERATION_ADD)
                        raw_value+=value;
                    else
                        raw_value-=value;
                    */
                    SetRawValueToAddress(temp_buffer, address, 2, (unsigned int)raw_value);

                    UpdateCellValue(x, y, address);

                    c++;
                }

                y_pos++;
            }

            current_top=(double)top_left + (((double)top_right - (double)top_left) * (step_x_factor * x_pos));
            current_bottom=(double)bottom_left + (((double)bottom_right - (double)bottom_left) * (step_x_factor * x_pos));

            x_pos++;
        }
    }
    // Interpolation with engineering value
    else if (RadioButton_Eng->GetValue())
    {
        double eng_value, value;
        double top_left, top_right, bottom_left, bottom_right;

        if(!TextCtrl_TopLeft->GetValue().ToDouble(&top_left))
        {
            StatusBar->SetStatusText(_("This is not a valid number!"),1);
            TextCtrl_TopLeft->SetForegroundColour(wxColor(255,0,0));
            return;
        }

        if(!TextCtrl_TopRight->GetValue().ToDouble(&top_right))
        {
            StatusBar->SetStatusText(_("This is not a valid number!"),1);
            TextCtrl_TopRight->SetForegroundColour(wxColor(255,0,0));
            return;
        }

        if(!TextCtrl_BottomLeft->GetValue().ToDouble(&bottom_left))
        {
            StatusBar->SetStatusText(_("This is not a valid number!"),1);
            TextCtrl_BottomLeft->SetForegroundColour(wxColor(255,0,0));
            return;
        }

        if(!TextCtrl_BottomRight->GetValue().ToDouble(&bottom_right))
        {
            StatusBar->SetStatusText(_("This is not a valid number!"),1);
            TextCtrl_BottomRight->SetForegroundColour(wxColor(255,0,0));
            return;
        }

        TextCtrl_TopLeft->SetForegroundColour(wxColor(0,0,0));
        TextCtrl_TopRight->SetForegroundColour(wxColor(0,0,0));
        TextCtrl_BottomLeft->SetForegroundColour(wxColor(0,0,0));
        TextCtrl_BottomRight->SetForegroundColour(wxColor(0,0,0));

        double current_top=(double)top_left,
               current_bottom=(double)bottom_left;

        double x_pos=1;
        for (int x=col_start; x <= col_end; x++)
        {
            double y_pos=0;

            for (int y=row_start; y <= row_end; y++)
            {
                if (Grid->IsInSelection(y,x))
                {
                    value=current_top + ((current_bottom - current_top) * (step_y_factor * y_pos));

                    address=ConvertXYToAddress(x,y);
                    eng_value=GetEngineeringValueFromAddress(temp_buffer, address, 2) + value;
                    /*
                    if (operation==OPERATION_ADD)
                        eng_value+=value;
                    else
                        eng_value-=value;
                    */
                    SetEngineeringValueToAddress(temp_buffer, address, 2, eng_value);

                    UpdateCellValue(x, y, address);

                    c++;
                }

                y_pos++;
            }

            current_top=(double)top_left + (((double)top_right - (double)top_left) * (step_x_factor * x_pos));
            current_bottom=(double)bottom_left + (((double)bottom_right - (double)bottom_left) * (step_x_factor * x_pos));

            x_pos++;
        }
    }
    else
        StatusBar->SetStatusText(_("Interpolation is only available for raw & engineering numbers."),1);

   StatusBar->SetStatusText(_("Interpolation set on ") + wxString::Format(_T("%i"),c) + _(" cells."),1);
}

/// ---------------------------------------------------------------------------
/// Grid Event Handlers
/// ---------------------------------------------------------------------------

void TableEditorFrame::OnGridCellChange(wxGridEvent& event)
{
    double value;

    int x=event.GetCol();
    int y=event.GetRow();

    Grid->SetCellBackgroundColour(y,x,wxColor(255,255,255));

    wxString str=Grid->GetCellValue(y,x);
    if (!str.ToDouble(&value))
    {
        StatusBar->SetStatusText(_("This is not a valid number!"),1);
        Grid->SetCellTextColour(y,x,wxColor(255,0,0));
        return;
    }

    unsigned int address=ConvertXYToAddress(x,y);

    // If diffence is selected then increment by
    // given value in respect to selected BIN buffer
    if (MenuItem_ShowDifferences->IsChecked())
    {
        int diff_bin=GetSelectedDifferenceBin();
        value+=GetEngineeringValueFromAddress(global->bin_buffer[diff_bin], global->xmlaxis[current_map][2].address + address, 2);
    }

    if (MenuItem_ShowRawValues->IsChecked())
        SetRawValueToAddress(temp_buffer, address, 2, (int)value);
    else
        SetEngineeringValueToAddress(temp_buffer, address, 2, value);

    Grid->SetCellTextColour(y,x,wxColor(0,0,0));
}

void TableEditorFrame::OnGridCellSelect(wxGridEvent& event)
{
    unsigned int address;

    // Update X Chart
    for (int x=0; x < Grid->GetNumberCols(); x++)
    {
        address=ConvertXYToAddress(x,event.GetRow());
        XChart->axis_data[x]=GetEngineeringValueFromAddress(temp_buffer, address, 2);
    }
    //XChart->data_size=Grid->GetNumberCols();
    XChart->current_pos=event.GetCol();
    XChart->Refresh();

    // Update Y Chart
    for (int y=0; y < Grid->GetNumberRows(); y++)
    {
        address=ConvertXYToAddress(event.GetCol(),y);
        YChart->axis_data[y]=GetEngineeringValueFromAddress(temp_buffer, address, 2);
    }
    //YChart->data_size=Grid->GetNumberRows();
    YChart->current_pos=event.GetRow();
    YChart->Refresh();

    event.Skip();
}

/// ---------------------------------------------------------------------------
/// Misc Functions
/// ---------------------------------------------------------------------------

void TableEditorFrame::Init(unsigned short bin, unsigned short selected_map, GlobalVariables *gv)
{
    global=gv;
    selected_bin=bin;
    current_map=selected_map;

    // Initialize X/Y Chart labels
    if (global->xmlaxis[current_map][0].units.IsEmpty())
        StaticText_XAxis->SetLabel(_("X Axis"));
    else
        StaticText_XAxis->SetLabel(_T("X: ") + global->xmlaxis[current_map][0].units);

    if (global->xmlaxis[current_map][1].units.IsEmpty())
        StaticText_YAxis->SetLabel(_("Y Axis"));
    else
        StaticText_YAxis->SetLabel(_T("Y: ") + global->xmlaxis[current_map][1].units);

    // Initialize X/Y Charts
    XChart->Init(global->xmlaxis[current_map][0].count);
    YChart->Init(global->xmlaxis[current_map][1].count);

    // Disbale unused BIN compares
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

    // Fill temp. buffer with table data from bin file
    unsigned int bytes;

    if (global->xmlaxis[current_map][2].bits==8)
        bytes=1;
    else if (global->xmlaxis[current_map][2].bits==16)
        bytes=2;
    else
        bytes=4;

    unsigned int length=(unsigned int)global->xmlaxis[current_map][0].count * (unsigned int)global->xmlaxis[current_map][1].count * bytes;
    temp_buffer=(unsigned char*)malloc(length);

    for (unsigned int x=0; x < length; x++)
        temp_buffer[x]=global->bin_buffer[selected_bin][global->xmlaxis[current_map][2].address + x];
}

void TableEditorFrame::UpdateGridAxis(void)
{
    double value;
    unsigned int address;

    // Switch between X/Y major
    unsigned short a,b;

    if (global->xmlaxis[current_map][2].flags & FLAGS_RC_BIT)
    {
        // Column (X)
        a=0;
        b=1;
    }
    else
    {
        // Row (Y)
        a=1;
        b=0;
    }

    SetCaption();

    // Default inits.
    StaticText_ChartTitle->SetLabel(global->xmltable[current_map].title +
                                    _T(" - [ ") +
                                    global->xmlaxis[current_map][1].units +
                                    _T(" / ") +
                                    global->xmlaxis[current_map][0].units +
                                    _T(" / ") +
                                    global->xmlaxis[current_map][2].units +
                                    _T(" ]"));

    Grid->ClearGrid();
    Grid->SetDefaultCellAlignment(wxALIGN_RIGHT,wxALIGN_CENTRE);
    Grid->AppendCols(global->xmlaxis[current_map][0].count-1);
    Grid->AppendRows(global->xmlaxis[current_map][1].count-1);

    // Fill X Labels
    if (global->xmlaxis[current_map][0].embeddedinfotype==EMBEDDEDINFO_STORED)
    {
        for (unsigned short x=0; x < global->xmlaxis[current_map][0].count; x++)
        {
            Grid->SetColLabelValue(x,wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][0].decimalpl) + _T("f"),global->xmlaxis[current_map][0].embeddedinfolabel[x]));
        }
    }
    else if (global->xmlaxis[current_map][0].embeddedinfotype==EMBEDDEDINFO_CALC)
    {
        address=global->xmlaxis[current_map][0].address;
        for (int x=0; x < global->xmlaxis[current_map][0].count; x++)
        {
            value=GetEngineeringValueFromAddress(global->bin_buffer[selected_bin], address, 0);
            address=IncrementAddress(address, 0);

            if (global->xmlaxis[current_map][0].outputtype==OUTPUTTYPE_INT)
            {
                if (global->xmlaxis[current_map][0].flags & FLAGS_SIGNED_BIT)
                {
                    Grid->SetColLabelValue(x,wxString::Format(_T("%i"),(int)value));
                }
                else
                {
                    Grid->SetColLabelValue(x,wxString::Format(_T("%i"),(unsigned int)value));
                }
            }
            else
            {
                Grid->SetColLabelValue(x,wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][0].decimalpl) + _T("f"),value));
            }
        }
    }
    else if (global->xmlaxis[current_map][0].embeddedinfotype==EMBEDDEDINFO_SCALED)
    {
        double step=(global->xmlaxis[current_map][0].embeddedinfolabel[1] -
                     global->xmlaxis[current_map][0].embeddedinfolabel[0]) /
                     (double)(global->xmlaxis[current_map][0].count - 1);

        value=global->xmlaxis[current_map][0].embeddedinfolabel[0];
        for (int x=0; x < global->xmlaxis[current_map][0].count; x++)
        {
            Grid->SetColLabelValue(x,wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][0].decimalpl) + _T("f"),value));
            value+=step;
        }
    }

    // Fill Y Labels
    if (global->xmlaxis[current_map][1].embeddedinfotype==EMBEDDEDINFO_STORED)
    {
        for (unsigned short y=0; y < global->xmlaxis[current_map][1].count; y++)
        {
            Grid->SetRowLabelValue(y,wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][1].decimalpl) + _T("f"),global->xmlaxis[current_map][1].embeddedinfolabel[y]));
        }
    }
    else if (global->xmlaxis[current_map][1].embeddedinfotype==EMBEDDEDINFO_CALC)
    {
        address=global->xmlaxis[current_map][1].address;
        for (int y=0; y < global->xmlaxis[current_map][1].count; y++)
        {
            value=GetEngineeringValueFromAddress(global->bin_buffer[selected_bin], address, 1);
            address=IncrementAddress(address, 1);

            if (global->xmlaxis[current_map][1].outputtype==OUTPUTTYPE_INT)
            {
                if (global->xmlaxis[current_map][1].flags & FLAGS_SIGNED_BIT)
                {
                    Grid->SetRowLabelValue(y,wxString::Format(_T("%i"),(int)value));
                }
                else
                {
                    Grid->SetRowLabelValue(y,wxString::Format(_T("%i"),(unsigned int)value));
                }
            }
            else
            {
                Grid->SetRowLabelValue(y,wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][1].decimalpl) + _T("f"),value));
            }
        }
    }
    else if (global->xmlaxis[current_map][1].embeddedinfotype==EMBEDDEDINFO_SCALED)
    {
        double step=(global->xmlaxis[current_map][1].embeddedinfolabel[1] -
                     global->xmlaxis[current_map][1].embeddedinfolabel[0]) /
                     (double)(global->xmlaxis[current_map][1].count - 1);

        value=global->xmlaxis[current_map][1].embeddedinfolabel[0];
        for (int y=0; y < global->xmlaxis[current_map][1].count; y++)
        {
            Grid->SetRowLabelValue(y,wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][1].decimalpl) + _T("f"),value));
            value+=step;
        }
    }
}

void TableEditorFrame::UpdateGrid(void)
{
    double value, diff_value=0;
    unsigned int address;

    // Switch between X/Y major
    unsigned short a,b;

    if (global->xmlaxis[current_map][2].flags & FLAGS_RC_BIT)
    {
        // Column (X)
        a=0;
        b=1;
    }
    else
    {
        // Row (Y)
        a=1;
        b=0;
    }

    // Select BIN to use for difference
    int diff_bin;
    if (MenuItem_HighlightDifferences->IsChecked())
        diff_bin=GetSelectedDifferenceBin();
    else
        diff_bin=-1;

    // Find min/max values
    address=0;
    double min=2147483647, max=-2147483647;

    for (int x=0; x < global->xmlaxis[current_map][0].count; x++)
    {
        for (int y=0; y < global->xmlaxis[current_map][1].count; y++)
        {
            if (MenuItem_ShowRawValues->IsChecked())
                value=(double)GetRawValueFromAddress(temp_buffer, address, 2);
            else
                value=GetEngineeringValueFromAddress(temp_buffer, address, 2);

            address=IncrementAddress(address, 2);

            // Store min/max values
            if (value > max)
                max=value;

            if (value < min)
                min=value;
        }
    }

    // Fill values in grid
    double value_steps=(max-min)/32;
    unsigned char r,g;

    address=0;
    for (int x=0; x < global->xmlaxis[current_map][a].count; x++)
    {
        for (int y=0; y < global->xmlaxis[current_map][b].count; y++)
        {
            if (MenuItem_ShowRawValues->IsChecked())
            {
                value=(double)GetRawValueFromAddress(temp_buffer, address, 2);

                if (diff_bin >= 0)
                    diff_value=(double)GetRawValueFromAddress(global->bin_buffer[diff_bin], global->xmlaxis[current_map][2].address + address, 2);
            }
            else
            {
                value=GetEngineeringValueFromAddress(temp_buffer, address, 2);

                if (diff_bin >= 0)
                    diff_value=GetEngineeringValueFromAddress(global->bin_buffer[diff_bin], global->xmlaxis[current_map][2].address + address, 2);
            }

            address=IncrementAddress(address, 2);

            // Output data to grid
            if ((global->xmlaxis[current_map][2].outputtype==OUTPUTTYPE_INT) || (MenuItem_ShowRawValues->IsChecked()))
            {
                if (global->xmlaxis[current_map][2].flags & FLAGS_SIGNED_BIT)
                {
                    if (!a) Grid->SetCellValue(y,x,wxString::Format(_T("%i"),(int)value));
                    else  Grid->SetCellValue(x,y,wxString::Format(_T("%i"),(int)value));
                }
                else
                {
                    if (!a) Grid->SetCellValue(y,x,wxString::Format(_T("%i"),(unsigned int)value));
                    else  Grid->SetCellValue(x,y,wxString::Format(_T("%i"),(unsigned int)value));
                }
            }
            else
            {
                if (!a) Grid->SetCellValue(y,x,wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][2].decimalpl) + _T("f"),value));
                else  Grid->SetCellValue(x,y,wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][2].decimalpl) + _T("f"),value));
            }

            // Highlight differences
            if ((diff_bin >= 0) && (value != diff_value))
            {
                if (!a)
                    Grid->SetCellBackgroundColour(y,x,wxColor(0xC6,0xC6,0xFF));
                else
                    Grid->SetCellBackgroundColour(x,y,wxColor(0xC6,0xC6,0xFF));
            }
            // Color by value weight
            else
            {
                value=(value-min) / value_steps;
                if (value < 16)
                {
                    if (value < 1) value=1;

                    r=255 - (255 / (unsigned char)value);
                    g=255;
                }
                else
                {
                    if (value < 17) value=17;

                    r=255;
                    g=255 / ((unsigned char)value - 16);
                }

                if (!a)
                    Grid->SetCellBackgroundColour(y,x,wxColor(r,g,0));
                else
                    Grid->SetCellBackgroundColour(x,y,wxColor(r,g,0));
            }
        }
    }

    Grid->Fit();
}

void TableEditorFrame::UpdateGridDifferences(void)
{
    double value, diff_value=0;
    unsigned int address;

    // Switch between X/Y major
    unsigned short a,b;

    if (global->xmlaxis[current_map][2].flags & FLAGS_RC_BIT)
    {
        // Column (X)
        a=0;
        b=1;
    }
    else
    {
        // Row (Y)
        a=1;
        b=0;
    }

    // Select BIN to use for difference
    int diff_bin=GetSelectedDifferenceBin();

    // Find min/max values
    address=0;
    double min=2147483647, max=-2147483647;

    for (int x=0; x < global->xmlaxis[current_map][0].count; x++)
    {
        for (int y=0; y < global->xmlaxis[current_map][1].count; y++)
        {
            if (MenuItem_ShowRawValues->IsChecked())
            {
                value=(double)GetRawValueFromAddress(temp_buffer, address, 2) -
                      (double)GetRawValueFromAddress(global->bin_buffer[diff_bin], global->xmlaxis[current_map][2].address + address, 2);
            }
            else
            {
                value=GetEngineeringValueFromAddress(temp_buffer, address, 2) -
                      GetEngineeringValueFromAddress(global->bin_buffer[diff_bin], global->xmlaxis[current_map][2].address + address, 2);
            }

            address=IncrementAddress(address, 2);

            // Store min/max values
            if (value > max)
                max=value;

            if (value < min)
                min=value;
        }
    }

    // Fill values in grid
    double value_steps=(max-min)/32;
    unsigned char r,g;

    address=0;
    for (int x=0; x < global->xmlaxis[current_map][a].count; x++)
    {
        for (int y=0; y < global->xmlaxis[current_map][b].count; y++)
        {
            if (MenuItem_ShowRawValues->IsChecked())
            {
                value=(double)GetRawValueFromAddress(temp_buffer, address, 2) -
                      (double)GetRawValueFromAddress(global->bin_buffer[diff_bin], global->xmlaxis[current_map][2].address + address, 2);
            }
            else
            {
                value=GetEngineeringValueFromAddress(temp_buffer, address, 2) -
                      GetEngineeringValueFromAddress(global->bin_buffer[diff_bin], global->xmlaxis[current_map][2].address + address, 2);
            }

            if (MenuItem_HighlightDifferences->IsChecked())
                diff_value=(double)GetRawValueFromAddress(temp_buffer, address, 2) -
                           (double)GetRawValueFromAddress(global->bin_buffer[diff_bin], global->xmlaxis[current_map][2].address + address, 2);

            address=IncrementAddress(address, 2);

            // Output data to grid
            if ((global->xmlaxis[current_map][2].outputtype==OUTPUTTYPE_INT) || (MenuItem_ShowRawValues->IsChecked()))
            {
                if (global->xmlaxis[current_map][2].flags & FLAGS_SIGNED_BIT)
                {
                    if (!a) Grid->SetCellValue(y,x,wxString::Format(_T("%i"),(int)value));
                    else  Grid->SetCellValue(x,y,wxString::Format(_T("%i"),(int)value));
                }
                else
                {
                    if (!a) Grid->SetCellValue(y,x,wxString::Format(_T("%i"),(unsigned int)value));
                    else  Grid->SetCellValue(x,y,wxString::Format(_T("%i"),(unsigned int)value));
                }
            }
            else
            {
                if (!a) Grid->SetCellValue(y,x,wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][2].decimalpl) + _T("f"),value));
                else  Grid->SetCellValue(x,y,wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][2].decimalpl) + _T("f"),value));
            }

            // Highlight differences
            if ((MenuItem_HighlightDifferences->IsChecked()) && (diff_value != 0))
            {
                if (!a)
                    Grid->SetCellBackgroundColour(y,x,wxColor(0xC6,0xC6,0xFF));
                else
                    Grid->SetCellBackgroundColour(x,y,wxColor(0xC6,0xC6,0xFF));
            }
            // Color by value weight
            else
            {
                value/=value_steps;
                if (value < 16)
                {
                    if (value < 1) value=1;

                    r=255 - (255 / (unsigned char)value);
                    g=255;
                }
                else
                {
                    if (value < 17) value=17;

                    r=255;
                    g=255 / ((unsigned char)value - 16);
                }

                if (!a)
                    Grid->SetCellBackgroundColour(y,x,wxColor(r,g,0));
                else
                    Grid->SetCellBackgroundColour(x,y,wxColor(r,g,0));
            }
        }
    }

    Grid->Fit();
}

void TableEditorFrame::UpdateCellValue(int x, int y, unsigned int address)
{
    double value;

    // If diffence is selected then update grid
    // with diff. value only and select raw or eng.
    if (MenuItem_ShowRawValues->IsChecked())
    {
        if (MenuItem_ShowDifferences->IsChecked())
        {
            int diff_bin=GetSelectedDifferenceBin();
            value=(double)GetRawValueFromAddress(temp_buffer, address, 2) -
                  (double)GetRawValueFromAddress(global->bin_buffer[diff_bin], global->xmlaxis[current_map][2].address + address, 2);
        }
        else
        {
            value=(double)GetRawValueFromAddress(temp_buffer, address, 2);
        }

        SetRawValueToGrid(x,y,2,(int)value);
    }
    else
    {
        if (MenuItem_ShowDifferences->IsChecked())
        {
            int diff_bin=GetSelectedDifferenceBin();

            value=GetEngineeringValueFromAddress(temp_buffer, address, 2) -
                  GetEngineeringValueFromAddress(global->bin_buffer[diff_bin], global->xmlaxis[current_map][2].address + address, 2);
        }
        else
        {
            value=GetEngineeringValueFromAddress(temp_buffer, address, 2);
        }

        SetEngineeringValueToGrid(x,y,2,value);
    }
}

void TableEditorFrame::SetRawValueToGrid(int x, int y, unsigned short axis, int value)
{
    // Output data to grid
    if (global->xmlaxis[current_map][axis].flags & FLAGS_SIGNED_BIT)
    {
        Grid->SetCellValue(y,x,wxString::Format(_T("%i"),value));
    }
    else
    {
        Grid->SetCellValue(y,x,wxString::Format(_T("%i"),(unsigned int)value));
    }

    Grid->SetCellBackgroundColour(y,x,wxColor(255,255,255));
    Grid->SetCellTextColour(y,x,wxColor(0,0,0));
}

void TableEditorFrame::SetEngineeringValueToGrid(int x, int y, unsigned short axis, double value)
{
    // Output data to grid
    if (global->xmlaxis[current_map][axis].outputtype==OUTPUTTYPE_INT)
    {
        if (global->xmlaxis[current_map][axis].flags & FLAGS_SIGNED_BIT)
        {
            Grid->SetCellValue(y,x,wxString::Format(_T("%i"),(int)value));
        }
        else
        {
            Grid->SetCellValue(y,x,wxString::Format(_T("%i"),(unsigned int)value));
        }
    }
    else
    {
        Grid->SetCellValue(y,x,wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][2].decimalpl) + _T("f"),value));
    }

    Grid->SetCellBackgroundColour(y,x,wxColor(255,255,255));
    Grid->SetCellTextColour(y,x,wxColor(0,0,0));
}

int TableEditorFrame::GetRawValueFromAddress(unsigned char *buffer, unsigned int address, unsigned short axis)
{
    unsigned int unsigned_raw_value=0;
    int signed_raw_value=0;

    if (global->xmlaxis[current_map][axis].bits==8)
        unsigned_raw_value=buffer[address];
    else if ((global->xmlaxis[current_map][axis].bits==16) && (global->xmlaxis[current_map][axis].flags & FLAGS_ORDER_BIT))
        unsigned_raw_value=((unsigned int)buffer[address+1] << 8) + (unsigned int)buffer[address];
    else if ((global->xmlaxis[current_map][axis].bits==16) && (!(global->xmlaxis[current_map][axis].flags & FLAGS_ORDER_BIT)))
        unsigned_raw_value=((unsigned int)buffer[address] << 8) + (unsigned int)buffer[address+1];
    else if ((global->xmlaxis[current_map][axis].bits==32) && (global->xmlaxis[current_map][axis].flags & FLAGS_ORDER_BIT))
    {
        unsigned_raw_value=((unsigned int)buffer[address+3] << 24) +
                           ((unsigned int)buffer[address+2] << 16) +
                           ((unsigned int)buffer[address+1] << 8) +
                           (unsigned int)buffer[address];
    }
    else if ((global->xmlaxis[current_map][axis].bits==32) && (!(global->xmlaxis[current_map][axis].flags & FLAGS_ORDER_BIT)))
    {
        unsigned_raw_value=((unsigned int)buffer[address] << 24) +
                           ((unsigned int)buffer[address+1] << 16) +
                           ((unsigned int)buffer[address+2] << 8) +
                           (unsigned int)buffer[address+3];
    }

    if (global->xmlaxis[current_map][axis].flags & FLAGS_SIGNED_BIT)
    {
        if ((global->xmlaxis[current_map][axis].bits==8) && (!(unsigned_raw_value & 0x00000080)))  // Positive Number
            signed_raw_value=(int)unsigned_raw_value;
        else if ((global->xmlaxis[current_map][axis].bits==8) && (unsigned_raw_value & 0x00000080))  // Negative Number
            signed_raw_value=(int)unsigned_raw_value - 0x100;
        else if ((global->xmlaxis[current_map][axis].bits==16) && (!(unsigned_raw_value & 0x00008000)))  // Positive Number
            signed_raw_value=(int)unsigned_raw_value;
        else if ((global->xmlaxis[current_map][axis].bits==16) && (unsigned_raw_value & 0x00008000))  // Negative Number
            signed_raw_value=(int)unsigned_raw_value - 0x10000;
        else if ((global->xmlaxis[current_map][axis].bits==32) && (!(unsigned_raw_value & 0x80000000)))  // Positive Number
            signed_raw_value=(int)unsigned_raw_value;
        else if ((global->xmlaxis[current_map][axis].bits==32) && (unsigned_raw_value & 0x80000000))  // Negative Number
            signed_raw_value=(int)unsigned_raw_value - 0xFFFFFFFF - 1;

        return(signed_raw_value);
    }

    return ((int)unsigned_raw_value);
}

void TableEditorFrame::SetRawValueToAddress(unsigned char *buffer, unsigned int address, unsigned short axis, int raw_value)
{
    unsigned int unsigned_raw_value=(unsigned int)raw_value;
/*
    if (global->xmlaxis[current_map][axis].flags & FLAGS_SIGNED_BIT)
        unsigned_raw_value=(unsigned int)raw_value;
    else
        unsigned_raw_value=raw_value;
*/
    if (global->xmlaxis[current_map][axis].bits==8)
        buffer[address]=(unsigned char)(unsigned_raw_value & 0x000000FF);
    else if ((global->xmlaxis[current_map][axis].bits==16) && (global->xmlaxis[current_map][axis].flags & FLAGS_ORDER_BIT))
    {
        buffer[address+1]=(unsigned char)(unsigned_raw_value >> 8);
        buffer[address]=(unsigned char)(unsigned_raw_value & 0x000000FF);
    }
    else if ((global->xmlaxis[current_map][axis].bits==16) && (!(global->xmlaxis[current_map][axis].flags & FLAGS_ORDER_BIT)))
    {
        buffer[address]=(unsigned char)(unsigned_raw_value >> 8);
        buffer[address+1]=(unsigned char)(unsigned_raw_value & 0x000000FF);
    }
    else if ((global->xmlaxis[current_map][axis].bits==32) && (global->xmlaxis[current_map][axis].flags & FLAGS_ORDER_BIT))
    {
        buffer[address+3]=(unsigned char)(unsigned_raw_value >> 24);
        buffer[address+2]=(unsigned char)((unsigned_raw_value >> 16) & 0x000000FF);
        buffer[address+1]=(unsigned char)((unsigned_raw_value >> 8) & 0x000000FF);
        buffer[address]=(unsigned char)(unsigned_raw_value & 0x000000FF);
    }
    else if ((global->xmlaxis[current_map][axis].bits==32) && (!(global->xmlaxis[current_map][axis].flags & FLAGS_ORDER_BIT)))
    {
        buffer[address]=(unsigned char)(unsigned_raw_value >> 24);
        buffer[address+1]=(unsigned char)((unsigned_raw_value >> 16) & 0x000000FF);
        buffer[address+2]=(unsigned char)((unsigned_raw_value >> 8) & 0x000000FF);
        buffer[address+3]=(unsigned char)(unsigned_raw_value & 0x000000FF);
    }
}

double TableEditorFrame::GetEngineeringValueFromAddress(unsigned char *buffer, unsigned int address, unsigned short axis)
{
    unsigned int unsigned_raw_value=0;
    int signed_raw_value=0;

    if (global->xmlaxis[current_map][axis].bits==8)
        unsigned_raw_value=buffer[address];
    else if ((global->xmlaxis[current_map][axis].bits==16) && (global->xmlaxis[current_map][axis].flags & FLAGS_ORDER_BIT))
        unsigned_raw_value=((unsigned int)buffer[address+1] << 8) + (unsigned int)buffer[address];
    else if ((global->xmlaxis[current_map][axis].bits==16) && (!(global->xmlaxis[current_map][axis].flags & FLAGS_ORDER_BIT)))
        unsigned_raw_value=((unsigned int)buffer[address] << 8) + (unsigned int)buffer[address+1];
    else if ((global->xmlaxis[current_map][axis].bits==32) && (global->xmlaxis[current_map][axis].flags & FLAGS_ORDER_BIT))
    {
        unsigned_raw_value=((unsigned int)buffer[address+3] << 24) +
                           ((unsigned int)buffer[address+2] << 16) +
                           ((unsigned int)buffer[address+1] << 8) +
                           (unsigned int)buffer[address];
    }
    else if ((global->xmlaxis[current_map][axis].bits==32) && (!(global->xmlaxis[current_map][axis].flags & FLAGS_ORDER_BIT)))
    {
        unsigned_raw_value=((unsigned int)buffer[address] << 24) +
                           ((unsigned int)buffer[address+1] << 16) +
                           ((unsigned int)buffer[address+2] << 8) +
                           (unsigned int)buffer[address+3];
    }

    if (global->xmlaxis[current_map][axis].flags & FLAGS_SIGNED_BIT)
    {
        if ((global->xmlaxis[current_map][axis].bits==8) && (!(unsigned_raw_value & 0x00000080)))  // Positive Number
            signed_raw_value=(int)unsigned_raw_value;
        else if ((global->xmlaxis[current_map][axis].bits==8) && (unsigned_raw_value & 0x00000080))  // Negative Number
            signed_raw_value=(int)unsigned_raw_value - 0x100;
        else if ((global->xmlaxis[current_map][axis].bits==16) && (!(unsigned_raw_value & 0x00008000)))  // Positive Number
            signed_raw_value=(int)unsigned_raw_value;
        else if ((global->xmlaxis[current_map][axis].bits==16) && (unsigned_raw_value & 0x00008000))  // Negative Number
            signed_raw_value=(int)unsigned_raw_value - 0x10000;
        else if ((global->xmlaxis[current_map][axis].bits==32) && (!(unsigned_raw_value & 0x80000000)))  // Positive Number
            signed_raw_value=(int)unsigned_raw_value;
        else if ((global->xmlaxis[current_map][axis].bits==32) && (unsigned_raw_value & 0x80000000))  // Negative Number
            signed_raw_value=(int)unsigned_raw_value - 0xFFFFFFFF - 1;
    }


    if (global->xmlaxis[current_map][axis].flags & FLAGS_SIGNED_BIT)
        return (RoundDouble(((double)signed_raw_value * global->xmlaxis[current_map][axis].factor) + global->xmlaxis[current_map][axis].offset,global->xmlaxis[current_map][axis].decimalpl));
    else
        return (RoundDouble(((double)unsigned_raw_value * global->xmlaxis[current_map][axis].factor) + global->xmlaxis[current_map][axis].offset,global->xmlaxis[current_map][axis].decimalpl));
}

void TableEditorFrame::SetEngineeringValueToAddress(unsigned char *buffer, unsigned int address, unsigned short axis, double eng_value)
{
    double value;
    unsigned int raw_value;

    eng_value=RoundDouble(eng_value,global->xmlaxis[current_map][axis].decimalpl);

    value=eng_value * (1 / global->xmlaxis[current_map][axis].factor);
    if (global->xmlaxis[current_map][axis].offset < 0)
        value+=(global->xmlaxis[current_map][axis].offset * -1);
    else
        value-=global->xmlaxis[current_map][axis].offset;

    raw_value=(unsigned int)value;

    if (global->xmlaxis[current_map][axis].bits==8)
        buffer[address]=(unsigned char)(raw_value & 0x000000FF);
    else if ((global->xmlaxis[current_map][axis].bits==16) && (global->xmlaxis[current_map][axis].flags & FLAGS_ORDER_BIT))
    {
        buffer[address+1]=(unsigned char)(raw_value >> 8);
        buffer[address]=(unsigned char)(raw_value & 0x000000FF);
    }
    else if ((global->xmlaxis[current_map][axis].bits==16) && (!(global->xmlaxis[current_map][axis].flags & FLAGS_ORDER_BIT)))
    {
        buffer[address]=(unsigned char)(raw_value >> 8);
        buffer[address+1]=(unsigned char)(raw_value & 0x000000FF);
    }
    else if ((global->xmlaxis[current_map][axis].bits==32) && (global->xmlaxis[current_map][axis].flags & FLAGS_ORDER_BIT))
    {
        buffer[address+3]=(unsigned char)(raw_value >> 24);
        buffer[address+2]=(unsigned char)((raw_value >> 16) & 0x000000FF);
        buffer[address+1]=(unsigned char)((raw_value >> 8) & 0x000000FF);
        buffer[address]=(unsigned char)(raw_value & 0x000000FF);
    }
    else if ((global->xmlaxis[current_map][axis].bits==32) && (!(global->xmlaxis[current_map][axis].flags & FLAGS_ORDER_BIT)))
    {
        buffer[address]=(unsigned char)(raw_value >> 24);
        buffer[address+1]=(unsigned char)((raw_value >> 16) & 0x000000FF);
        buffer[address+2]=(unsigned char)((raw_value >> 8) & 0x000000FF);
        buffer[address+3]=(unsigned char)(raw_value & 0x000000FF);
    }
}

double TableEditorFrame::RoundDouble(double value, int places)
{
    double temp, mult;

    mult = pow(10.0, places);
    temp = floor(value * mult + 0.5);
    temp = temp / mult;

    return (temp);
}

unsigned int TableEditorFrame::ConvertXYToAddress(int x, int y)
{
    // Switch between X/Y major
    int a,b;

    if (global->xmlaxis[current_map][2].flags & FLAGS_RC_BIT)
    {
        // Column (X)
        a=0;
        b=1;
    }
    else
    {
        // Row (Y)
        a=1;
        b=0;
    }

    // Calculate address
    unsigned int address=0;
    for (int xx=0; xx < global->xmlaxis[current_map][a].count; xx++)
    {
        for (int yy=0; yy < global->xmlaxis[current_map][b].count; yy++)
        {
            if ((!a) && (x==xx) && (y==yy))
                return (address);
            else if ((a) && (x==yy) && (y==xx))
                return (address);

            address=IncrementAddress(address, 2);
        }
    }

    return (address);
}

unsigned int TableEditorFrame::IncrementAddress(unsigned int address, unsigned short axis)
{
    if (global->xmlaxis[current_map][axis].bits==8)
        address++;
    else if (global->xmlaxis[current_map][axis].bits==16)
        address+=2;
    else if (global->xmlaxis[current_map][axis].bits==32)
        address+=4;

    return (address);
}

unsigned short TableEditorFrame::CalculateRaw(unsigned short operation)
{
    unsigned short c=0;
    unsigned int address, raw_value;
    //double value;

    for (int x=0; x < Grid->GetNumberCols(); x++)
    {
        for (int y=0; y < Grid->GetNumberRows(); y++)
        {
            if (Grid->IsInSelection(y,x))
            {
                address=ConvertXYToAddress(x,y);
                raw_value=GetRawValueFromAddress(temp_buffer, address, 2);

                if (operation==OPERATION_ADD)
                    raw_value+=SpinCtrl_Raw->GetValue();
                else
                    raw_value-=SpinCtrl_Raw->GetValue();

                SetRawValueToAddress(temp_buffer, address, 2, (unsigned int)raw_value);

                // If diffence is selected then update grid
                // with diff. value only and select raw or eng.
                /*
                if (MenuItem_ShowRawValues->IsChecked())
                {
                    if (MenuItem_ShowDifferences->IsChecked())
                    {
                        int diff_bin=GetSelectedDifferenceBin();
                        value=(double)GetRawValueFromAddress(temp_buffer, address, 2) -
                              (double)GetRawValueFromAddress(global->bin_buffer[diff_bin], global->xmlaxis[current_map][2].address + address, 2);
                    }
                    else
                    {
                        value=(double)GetRawValueFromAddress(temp_buffer, address, 2);
                    }

                    SetRawValueToGrid(x,y,2,(int)value);
                }
                else
                {
                    if (MenuItem_ShowDifferences->IsChecked())
                    {
                        int diff_bin=GetSelectedDifferenceBin();

                        value=GetEngineeringValueFromAddress(temp_buffer, address, 2) -
                              GetEngineeringValueFromAddress(global->bin_buffer[diff_bin], global->xmlaxis[current_map][2].address + address, 2);
                    }
                    else
                    {
                        value=GetEngineeringValueFromAddress(temp_buffer, address, 2);
                    }

                    SetEngineeringValueToGrid(x,y,2,value);
                }
                */
                UpdateCellValue(x, y, address);

                c++;
            }
        }
    }

    return (c);
}

unsigned short TableEditorFrame::CalculatePercentage(unsigned short operation)
{
    double perc_value, perc_fraction, value;
    unsigned int address;

    wxString str=TextCtrl_Perc->GetValue();
    if (!str.ToDouble(&perc_value))
    {
        StatusBar->SetStatusText(_("This is not a valid number!"),1);
        TextCtrl_Perc->SetForegroundColour(wxColor(255,0,0));
        return (0);
    }

    TextCtrl_Perc->SetForegroundColour(wxColor(0,0,0));

    unsigned short c=0;
    for (int x=0; x < Grid->GetNumberCols(); x++)
    {
        for (int y=0; y < Grid->GetNumberRows(); y++)
        {
            if (Grid->IsInSelection(y,x))
            {
                address=ConvertXYToAddress(x,y);
                value=GetEngineeringValueFromAddress(temp_buffer, address, 2);

                perc_fraction=value * (perc_value / 100);
                if (operation==OPERATION_ADD)
                    value+=perc_fraction;
                else
                    value-=perc_fraction;

                SetEngineeringValueToAddress(temp_buffer, address, 2, value);

                // If diffence is selected then update grid
                // with diff. value only and select raw or eng.
                /*
                if (MenuItem_ShowRawValues->IsChecked())
                {
                    if (MenuItem_ShowDifferences->IsChecked())
                    {
                        int diff_bin=GetSelectedDifferenceBin();

                        value=(double)GetRawValueFromAddress(temp_buffer, address, 2) -
                              (double)GetRawValueFromAddress(global->bin_buffer[diff_bin], global->xmlaxis[current_map][2].address + address, 2);
                    }
                    else
                    {
                        value=(double)GetRawValueFromAddress(temp_buffer, address, 2);
                    }

                    SetRawValueToGrid(x,y,2,(int)value);
                }
                else
                {
                    if (MenuItem_ShowDifferences->IsChecked())
                    {
                        int diff_bin=GetSelectedDifferenceBin();

                        value=GetEngineeringValueFromAddress(temp_buffer, address, 2) -
                              GetEngineeringValueFromAddress(global->bin_buffer[diff_bin], global->xmlaxis[current_map][2].address + address, 2);
                    }
                    else
                    {
                        value=GetEngineeringValueFromAddress(temp_buffer, address, 2);
                    }

                    SetEngineeringValueToGrid(x,y,2,value);
                }
                */
                UpdateCellValue(x, y, address);

                c++;
            }
        }
    }

    return (c);
}

unsigned short TableEditorFrame::CalculateEngineering(unsigned short operation)
{
    double inc_value, value;
    unsigned int address;
    unsigned short c=0;

    wxString str=TextCtrl_Eng->GetValue();
    if (!str.ToDouble(&inc_value))
    {
        StatusBar->SetStatusText(_("This is not a valid number!"),1);
        TextCtrl_Eng->SetForegroundColour(wxColor(255,0,0));
        return (0);
    }

    TextCtrl_Eng->SetForegroundColour(wxColor(0,0,0));

    for (int x=0; x < Grid->GetNumberCols(); x++)
    {
        for (int y=0; y < Grid->GetNumberRows(); y++)
        {
            if (Grid->IsInSelection(y,x))
            {

                address=ConvertXYToAddress(x,y);
                value=GetEngineeringValueFromAddress(temp_buffer, address, 2);

                if (operation==OPERATION_ADD)
                    value+=inc_value;
                else
                    value-=inc_value;

                SetEngineeringValueToAddress(temp_buffer, address, 2, value);

                // If diffence is selected then update grid
                // with diff. value only and select raw or eng.
                /*
                if (MenuItem_ShowRawValues->IsChecked())
                {
                    if (MenuItem_ShowDifferences->IsChecked())
                    {
                        int diff_bin=GetSelectedDifferenceBin();
                        value=(double)GetRawValueFromAddress(temp_buffer, address, 2) -
                              (double)GetRawValueFromAddress(global->bin_buffer[diff_bin], global->xmlaxis[current_map][2].address + address, 2);
                    }
                    else
                    {
                        value=(double)GetRawValueFromAddress(temp_buffer, address, 2);
                    }

                    SetRawValueToGrid(x,y,2,(int)value);
                }
                else
                {
                    if (MenuItem_ShowDifferences->IsChecked())
                    {
                        int diff_bin=GetSelectedDifferenceBin();

                        value=GetEngineeringValueFromAddress(temp_buffer, address, 2) -
                              GetEngineeringValueFromAddress(global->bin_buffer[diff_bin], global->xmlaxis[current_map][2].address + address, 2);
                    }
                    else
                    {
                        value=GetEngineeringValueFromAddress(temp_buffer, address, 2);
                    }

                    SetEngineeringValueToGrid(x,y,2,value);
                }
                */
                UpdateCellValue(x, y, address);

                c++;
            }
        }
    }

    return (c);
}

int TableEditorFrame::GetSelectedDifferenceBin(void)
{
    if (MenuItem_SelectCompareBIN1->IsChecked())
        return (0);
    else if (MenuItem_SelectCompareBIN2->IsChecked())
        return (1);
    else if (MenuItem_SelectCompareBIN3->IsChecked())
        return (2);

    return (-1);
}

void TableEditorFrame::SetCaption(void)
{
    if (GetSelectedDifferenceBin() < 0)
    {
        this->SetTitle(_("[Source BIN #") +
                       wxString::Format(wxT("%i"),selected_bin+1) +
                       _T("]"));
    }
    else
    {
        this->SetTitle(_("[Source BIN #") +
                       wxString::Format(wxT("%i"),selected_bin+1) +
                       _(" : Compare BIN #") +
                       wxString::Format(wxT("%i"),GetSelectedDifferenceBin()+1) +
                       _T("]"));
    }
}

