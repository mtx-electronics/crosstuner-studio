/***************************************************************
 * Name:      MapEditorMain.cpp
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
#include "MapEditorMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(MapEditorDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(MapEditorDialog)
const long MapEditorDialog::ID_STATICTEXT1 = wxNewId();
const long MapEditorDialog::ID_TEXTCTRL1 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT2 = wxNewId();
const long MapEditorDialog::ID_TEXTCTRL2 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT35 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT36 = wxNewId();
const long MapEditorDialog::ID_TEXTCTRL5 = wxNewId();
const long MapEditorDialog::ID_TEXTCTRL9 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT37 = wxNewId();
const long MapEditorDialog::ID_CHOICE19 = wxNewId();
const long MapEditorDialog::ID_PANEL4 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT9 = wxNewId();
const long MapEditorDialog::ID_COMBOBOX3 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT10 = wxNewId();
const long MapEditorDialog::ID_CHOICE1 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT11 = wxNewId();
const long MapEditorDialog::ID_CHOICE6 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT12 = wxNewId();
const long MapEditorDialog::ID_TEXTCTRL6 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT13 = wxNewId();
const long MapEditorDialog::ID_TEXTCTRL7 = wxNewId();
const long MapEditorDialog::ID_PANEL11 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT4 = wxNewId();
const long MapEditorDialog::ID_TEXTCTRL3 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT5 = wxNewId();
const long MapEditorDialog::ID_CHOICE2 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT6 = wxNewId();
const long MapEditorDialog::ID_CHOICE3 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT7 = wxNewId();
const long MapEditorDialog::ID_CHOICE4 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT8 = wxNewId();
const long MapEditorDialog::ID_CHOICE5 = wxNewId();
const long MapEditorDialog::ID_PANEL6 = wxNewId();
const long MapEditorDialog::ID_GRID3 = wxNewId();
const long MapEditorDialog::ID_PANEL3 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT14 = wxNewId();
const long MapEditorDialog::ID_TEXTCTRL8 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT15 = wxNewId();
const long MapEditorDialog::ID_COMBOBOX1 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT16 = wxNewId();
const long MapEditorDialog::ID_CHOICE7 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT17 = wxNewId();
const long MapEditorDialog::ID_CHOICE8 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT18 = wxNewId();
const long MapEditorDialog::ID_TEXTCTRL10 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT19 = wxNewId();
const long MapEditorDialog::ID_TEXTCTRL11 = wxNewId();
const long MapEditorDialog::ID_PANEL8 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT3 = wxNewId();
const long MapEditorDialog::ID_CHOICE9 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT21 = wxNewId();
const long MapEditorDialog::ID_TEXTCTRL4 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT20 = wxNewId();
const long MapEditorDialog::ID_CHOICE11 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT22 = wxNewId();
const long MapEditorDialog::ID_CHOICE10 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT24 = wxNewId();
const long MapEditorDialog::ID_CHOICE12 = wxNewId();
const long MapEditorDialog::ID_PANEL5 = wxNewId();
const long MapEditorDialog::ID_GRID1 = wxNewId();
const long MapEditorDialog::ID_PANEL1 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT23 = wxNewId();
const long MapEditorDialog::ID_TEXTCTRL12 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT25 = wxNewId();
const long MapEditorDialog::ID_COMBOBOX2 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT26 = wxNewId();
const long MapEditorDialog::ID_CHOICE13 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT27 = wxNewId();
const long MapEditorDialog::ID_CHOICE14 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT28 = wxNewId();
const long MapEditorDialog::ID_TEXTCTRL14 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT29 = wxNewId();
const long MapEditorDialog::ID_TEXTCTRL15 = wxNewId();
const long MapEditorDialog::ID_PANEL9 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT30 = wxNewId();
const long MapEditorDialog::ID_CHOICE15 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT31 = wxNewId();
const long MapEditorDialog::ID_TEXTCTRL16 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT32 = wxNewId();
const long MapEditorDialog::ID_CHOICE16 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT33 = wxNewId();
const long MapEditorDialog::ID_CHOICE17 = wxNewId();
const long MapEditorDialog::ID_STATICTEXT34 = wxNewId();
const long MapEditorDialog::ID_CHOICE18 = wxNewId();
const long MapEditorDialog::ID_PANEL10 = wxNewId();
const long MapEditorDialog::ID_GRID2 = wxNewId();
const long MapEditorDialog::ID_PANEL2 = wxNewId();
const long MapEditorDialog::ID_NOTEBOOK1 = wxNewId();
const long MapEditorDialog::ID_BUTTON1 = wxNewId();
const long MapEditorDialog::ID_BUTTON3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MapEditorDialog,wxDialog)
    //(*EventTable(MapEditorDialog)
    //*)
END_EVENT_TABLE()

MapEditorDialog::MapEditorDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(MapEditorDialog)
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer6;
    wxFlexGridSizer* FlexGridSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer10;
    wxBoxSizer* BoxSizer8;
    wxBoxSizer* BoxSizer13;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer5;
    wxFlexGridSizer* FlexGridSizer2;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer11;
    wxBoxSizer* BoxSizer12;
    wxBoxSizer* BoxSizer14;
    wxGridSizer* GridSizer1;
    wxBoxSizer* BoxSizer9;
    wxFlexGridSizer* FlexGridSizer6;
    wxFlexGridSizer* FlexGridSizer1;
    wxBoxSizer* BoxSizer3;

    Create(parent, wxID_ANY, _("Map Editor"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(285,480));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxSize(442,490), 0, _T("ID_NOTEBOOK1"));
    Panel_Settings = new wxPanel(Notebook1, ID_PANEL4, wxDefaultPosition, wxSize(269,437), wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    BoxSizer8 = new wxBoxSizer(wxVERTICAL);
    StaticText1 = new wxStaticText(Panel_Settings, ID_STATICTEXT1, _("Display Name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer8->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_Name = new wxTextCtrl(Panel_Settings, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer8->Add(TextCtrl_Name, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel_Settings, ID_STATICTEXT2, _("Description"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer8->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_Description = new wxTextCtrl(Panel_Settings, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(259,107), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer8->Add(TextCtrl_Description, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1 = new wxGridSizer(2, 2, 0, 0);
    StaticText35 = new wxStaticText(Panel_Settings, ID_STATICTEXT35, _("Author"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT35"));
    GridSizer1->Add(StaticText35, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText36 = new wxStaticText(Panel_Settings, ID_STATICTEXT36, _("Version"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT36"));
    GridSizer1->Add(StaticText36, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_Author = new wxTextCtrl(Panel_Settings, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    GridSizer1->Add(TextCtrl_Author, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_Version = new wxTextCtrl(Panel_Settings, ID_TEXTCTRL9, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    GridSizer1->Add(TextCtrl_Version, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer8->Add(GridSizer1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    StaticText37 = new wxStaticText(Panel_Settings, ID_STATICTEXT37, _("Checksum Plugin"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT37"));
    BoxSizer8->Add(StaticText37, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice_Checksum = new wxChoice(Panel_Settings, ID_CHOICE19, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE19"));
    Choice_Checksum->SetSelection( Choice_Checksum->Append(_("0 - Automatic")) );
    BoxSizer8->Add(Choice_Checksum, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer3->Add(BoxSizer8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Panel_Settings->SetSizer(BoxSizer3);
    BoxSizer3->SetSizeHints(Panel_Settings);
    Panel_ZAxis = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer13 = new wxBoxSizer(wxVERTICAL);
    Panel6 = new wxPanel(Panel_ZAxis, ID_PANEL11, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL11"));
    FlexGridSizer2 = new wxFlexGridSizer(5, 2, 0, 0);
    FlexGridSizer2->AddGrowableCol(1);
    StaticText9 = new wxStaticText(Panel6, ID_STATICTEXT9, _("Units"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    FlexGridSizer2->Add(StaticText9, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    ComboBox_ZUnits = new wxComboBox(Panel6, ID_COMBOBOX3, wxEmptyString, wxDefaultPosition, wxSize(85,29), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX3"));
    ComboBox_ZUnits->Append(_("RPM"));
    ComboBox_ZUnits->Append(_("mg/s"));
    ComboBox_ZUnits->Append(_("Load"));
    ComboBox_ZUnits->Append(_("Throttle"));
    ComboBox_ZUnits->Append(_("Absolute Pressure"));
    ComboBox_ZUnits->Append(_("Differential Pressure"));
    ComboBox_ZUnits->Append(_("MAF"));
    ComboBox_ZUnits->Append(_("Intake Air Flow"));
    ComboBox_ZUnits->Append(_("MAP"));
    ComboBox_ZUnits->Append(_("Intake Air Pressure"));
    ComboBox_ZUnits->Append(_("IAT"));
    ComboBox_ZUnits->Append(_("Intake Air Temperature"));
    FlexGridSizer2->Add(ComboBox_ZUnits, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText10 = new wxStaticText(Panel6, ID_STATICTEXT10, _("Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    FlexGridSizer2->Add(StaticText10, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice_ZType = new wxChoice(Panel6, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice_ZType->SetSelection( Choice_ZType->Append(_("Integer")) );
    Choice_ZType->Append(_("Float"));
    FlexGridSizer2->Add(Choice_ZType, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText11 = new wxStaticText(Panel6, ID_STATICTEXT11, _("Decimals"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    FlexGridSizer2->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice_ZDecimals = new wxChoice(Panel6, ID_CHOICE6, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE6"));
    Choice_ZDecimals->SetSelection( Choice_ZDecimals->Append(_("0")) );
    Choice_ZDecimals->Append(_("1"));
    Choice_ZDecimals->Append(_("2"));
    Choice_ZDecimals->Append(_("3"));
    Choice_ZDecimals->Append(_("4"));
    Choice_ZDecimals->Append(_("5"));
    Choice_ZDecimals->Append(_("6"));
    FlexGridSizer2->Add(Choice_ZDecimals, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText12 = new wxStaticText(Panel6, ID_STATICTEXT12, _("Offset"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    FlexGridSizer2->Add(StaticText12, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_ZOffset = new wxTextCtrl(Panel6, ID_TEXTCTRL6, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    FlexGridSizer2->Add(TextCtrl_ZOffset, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText13 = new wxStaticText(Panel6, ID_STATICTEXT13, _("Factor"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    FlexGridSizer2->Add(StaticText13, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_ZFactor = new wxTextCtrl(Panel6, ID_TEXTCTRL7, _("1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    FlexGridSizer2->Add(TextCtrl_ZFactor, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Panel6->SetSizer(FlexGridSizer2);
    FlexGridSizer2->Fit(Panel6);
    FlexGridSizer2->SetSizeHints(Panel6);
    BoxSizer13->Add(Panel6, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel3 = new wxPanel(Panel_ZAxis, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    FlexGridSizer1 = new wxFlexGridSizer(5, 2, 0, 0);
    FlexGridSizer1->AddGrowableCol(1);
    StaticText4 = new wxStaticText(Panel3, ID_STATICTEXT4, _("Address"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_Address = new wxTextCtrl(Panel3, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer1->Add(TextCtrl_Address, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(Panel3, ID_STATICTEXT5, _("Bits"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice_Bits = new wxChoice(Panel3, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    Choice_Bits->Append(_("8"));
    Choice_Bits->SetSelection( Choice_Bits->Append(_("16")) );
    Choice_Bits->Append(_("32"));
    FlexGridSizer1->Add(Choice_Bits, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(Panel3, ID_STATICTEXT6, _("Sign"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    FlexGridSizer1->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice_Sign = new wxChoice(Panel3, ID_CHOICE3, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
    Choice_Sign->SetSelection( Choice_Sign->Append(_("Unsigned")) );
    Choice_Sign->Append(_("Signed"));
    FlexGridSizer1->Add(Choice_Sign, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(Panel3, ID_STATICTEXT7, _("Byte Order"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    FlexGridSizer1->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice_ByteOrder = new wxChoice(Panel3, ID_CHOICE4, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
    Choice_ByteOrder->Append(_("MSB First"));
    Choice_ByteOrder->SetSelection( Choice_ByteOrder->Append(_("LSB First")) );
    FlexGridSizer1->Add(Choice_ByteOrder, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(Panel3, ID_STATICTEXT8, _("Data Order"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    FlexGridSizer1->Add(StaticText8, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice_DataOrder = new wxChoice(Panel3, ID_CHOICE5, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
    Choice_DataOrder->Append(_("Y / X"));
    Choice_DataOrder->SetSelection( Choice_DataOrder->Append(_("X / Y")) );
    FlexGridSizer1->Add(Choice_DataOrder, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Panel3->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(Panel3);
    FlexGridSizer1->SetSizeHints(Panel3);
    BoxSizer13->Add(Panel3, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer12->Add(BoxSizer13, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
    Grid_ZGrid = new wxGrid(Panel_ZAxis, ID_GRID3, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID3"));
    Grid_ZGrid->CreateGrid(1,1);
    Grid_ZGrid->EnableEditing(true);
    Grid_ZGrid->EnableGridLines(true);
    Grid_ZGrid->SetDefaultCellFont( Grid_ZGrid->GetFont() );
    Grid_ZGrid->SetDefaultCellTextColour( Grid_ZGrid->GetForegroundColour() );
    BoxSizer14->Add(Grid_ZGrid, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer12->Add(BoxSizer14, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Panel_ZAxis->SetSizer(BoxSizer12);
    BoxSizer12->Fit(Panel_ZAxis);
    BoxSizer12->SetSizeHints(Panel_ZAxis);
    Panel_XAxis = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxSize(497,447), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer10 = new wxBoxSizer(wxVERTICAL);
    Panel2 = new wxPanel(Panel_XAxis, ID_PANEL8, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL8"));
    FlexGridSizer3 = new wxFlexGridSizer(6, 2, 0, 0);
    FlexGridSizer3->AddGrowableCol(1);
    StaticText14 = new wxStaticText(Panel2, ID_STATICTEXT14, _("Count"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    FlexGridSizer3->Add(StaticText14, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_XCount = new wxTextCtrl(Panel2, ID_TEXTCTRL8, _("1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    FlexGridSizer3->Add(TextCtrl_XCount, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText15 = new wxStaticText(Panel2, ID_STATICTEXT15, _("Units"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    FlexGridSizer3->Add(StaticText15, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    ComboBox_XUnits = new wxComboBox(Panel2, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxSize(46,29), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    ComboBox_XUnits->Append(_("RPM"));
    ComboBox_XUnits->Append(_("mg/s"));
    ComboBox_XUnits->Append(_("Load"));
    ComboBox_XUnits->Append(_("Throttle"));
    ComboBox_XUnits->Append(_("Absolute Pressure"));
    ComboBox_XUnits->Append(_("Differential Pressure"));
    ComboBox_XUnits->Append(_("MAF"));
    ComboBox_XUnits->Append(_("Intake Air Flow"));
    ComboBox_XUnits->Append(_("MAP"));
    ComboBox_XUnits->Append(_("Intake Air Pressure"));
    ComboBox_XUnits->Append(_("IAT"));
    ComboBox_XUnits->Append(_("Intake Air Temperature"));
    FlexGridSizer3->Add(ComboBox_XUnits, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText16 = new wxStaticText(Panel2, ID_STATICTEXT16, _("Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    FlexGridSizer3->Add(StaticText16, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice_XType = new wxChoice(Panel2, ID_CHOICE7, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE7"));
    Choice_XType->SetSelection( Choice_XType->Append(_("Integer")) );
    Choice_XType->Append(_("Float"));
    FlexGridSizer3->Add(Choice_XType, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText17 = new wxStaticText(Panel2, ID_STATICTEXT17, _("Decimals"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    FlexGridSizer3->Add(StaticText17, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice_XDecimals = new wxChoice(Panel2, ID_CHOICE8, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE8"));
    Choice_XDecimals->SetSelection( Choice_XDecimals->Append(_("0")) );
    Choice_XDecimals->Append(_("1"));
    Choice_XDecimals->Append(_("2"));
    Choice_XDecimals->Append(_("3"));
    Choice_XDecimals->Append(_("4"));
    Choice_XDecimals->Append(_("5"));
    Choice_XDecimals->Append(_("6"));
    FlexGridSizer3->Add(Choice_XDecimals, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText18 = new wxStaticText(Panel2, ID_STATICTEXT18, _("Offset"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    FlexGridSizer3->Add(StaticText18, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_XOffset = new wxTextCtrl(Panel2, ID_TEXTCTRL10, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL10"));
    FlexGridSizer3->Add(TextCtrl_XOffset, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText19 = new wxStaticText(Panel2, ID_STATICTEXT19, _("Factor"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    FlexGridSizer3->Add(StaticText19, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_XFactor = new wxTextCtrl(Panel2, ID_TEXTCTRL11, _("1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL11"));
    FlexGridSizer3->Add(TextCtrl_XFactor, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Panel2->SetSizer(FlexGridSizer3);
    FlexGridSizer3->Fit(Panel2);
    FlexGridSizer3->SetSizeHints(Panel2);
    BoxSizer10->Add(Panel2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1 = new wxPanel(Panel_XAxis, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    FlexGridSizer4 = new wxFlexGridSizer(5, 2, 0, 0);
    FlexGridSizer4->AddGrowableCol(1);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Source"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer4->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice_XSource = new wxChoice(Panel1, ID_CHOICE9, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE9"));
    Choice_XSource->SetSelection( Choice_XSource->Append(_("Manual")) );
    Choice_XSource->Append(_("Embedded"));
    Choice_XSource->Append(_("Scaled"));
    FlexGridSizer4->Add(Choice_XSource, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText21 = new wxStaticText(Panel1, ID_STATICTEXT21, _("Address"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    FlexGridSizer4->Add(StaticText21, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_XAddress = new wxTextCtrl(Panel1, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    FlexGridSizer4->Add(TextCtrl_XAddress, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText20 = new wxStaticText(Panel1, ID_STATICTEXT20, _("Sign"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    FlexGridSizer4->Add(StaticText20, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice_XSign = new wxChoice(Panel1, ID_CHOICE11, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE11"));
    Choice_XSign->SetSelection( Choice_XSign->Append(_("Unsigned")) );
    Choice_XSign->Append(_("Signed"));
    FlexGridSizer4->Add(Choice_XSign, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText22 = new wxStaticText(Panel1, ID_STATICTEXT22, _("Bits"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    FlexGridSizer4->Add(StaticText22, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice_XBits = new wxChoice(Panel1, ID_CHOICE10, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE10"));
    Choice_XBits->Append(_("8"));
    Choice_XBits->SetSelection( Choice_XBits->Append(_("16")) );
    Choice_XBits->Append(_("32"));
    FlexGridSizer4->Add(Choice_XBits, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText24 = new wxStaticText(Panel1, ID_STATICTEXT24, _("Byte Order"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    FlexGridSizer4->Add(StaticText24, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice_XByteOrder = new wxChoice(Panel1, ID_CHOICE12, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE12"));
    Choice_XByteOrder->Append(_("MSB First"));
    Choice_XByteOrder->SetSelection( Choice_XByteOrder->Append(_("LSB First")) );
    FlexGridSizer4->Add(Choice_XByteOrder, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer4);
    FlexGridSizer4->Fit(Panel1);
    FlexGridSizer4->SetSizeHints(Panel1);
    BoxSizer10->Add(Panel1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer9->Add(BoxSizer10, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
    Grid_XGrid = new wxGrid(Panel_XAxis, ID_GRID1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID1"));
    Grid_XGrid->CreateGrid(1,1);
    Grid_XGrid->EnableEditing(true);
    Grid_XGrid->EnableGridLines(true);
    Grid_XGrid->SetDefaultCellFont( Grid_XGrid->GetFont() );
    Grid_XGrid->SetDefaultCellTextColour( Grid_XGrid->GetForegroundColour() );
    BoxSizer11->Add(Grid_XGrid, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer9->Add(BoxSizer11, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Panel_XAxis->SetSizer(BoxSizer9);
    BoxSizer9->SetSizeHints(Panel_XAxis);
    Panel_YAxis = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    Panel4 = new wxPanel(Panel_YAxis, ID_PANEL9, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL9"));
    FlexGridSizer5 = new wxFlexGridSizer(6, 2, 0, 0);
    FlexGridSizer5->AddGrowableCol(1);
    StaticText23 = new wxStaticText(Panel4, ID_STATICTEXT23, _("Count"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    FlexGridSizer5->Add(StaticText23, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_YCount = new wxTextCtrl(Panel4, ID_TEXTCTRL12, _("1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL12"));
    FlexGridSizer5->Add(TextCtrl_YCount, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText25 = new wxStaticText(Panel4, ID_STATICTEXT25, _("Units"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    FlexGridSizer5->Add(StaticText25, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    ComboBox_YUnits = new wxComboBox(Panel4, ID_COMBOBOX2, wxEmptyString, wxDefaultPosition, wxSize(37,29), 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
    ComboBox_YUnits->Append(_("RPM"));
    ComboBox_YUnits->Append(_("mg/s"));
    ComboBox_YUnits->Append(_("Load"));
    ComboBox_YUnits->Append(_("Throttle"));
    ComboBox_YUnits->Append(_("Absolute Pressure"));
    ComboBox_YUnits->Append(_("Differential Pressure"));
    ComboBox_YUnits->Append(_("MAF"));
    ComboBox_YUnits->Append(_("Intake Air Flow"));
    ComboBox_YUnits->Append(_("MAP"));
    ComboBox_YUnits->Append(_("Intake Air Pressure"));
    ComboBox_YUnits->Append(_("IAT"));
    ComboBox_YUnits->Append(_("Intake Air Temperature"));
    FlexGridSizer5->Add(ComboBox_YUnits, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText26 = new wxStaticText(Panel4, ID_STATICTEXT26, _("Type"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT26"));
    FlexGridSizer5->Add(StaticText26, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice_YType = new wxChoice(Panel4, ID_CHOICE13, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE13"));
    Choice_YType->SetSelection( Choice_YType->Append(_("Integer")) );
    Choice_YType->Append(_("Float"));
    FlexGridSizer5->Add(Choice_YType, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText27 = new wxStaticText(Panel4, ID_STATICTEXT27, _("Decimals"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT27"));
    FlexGridSizer5->Add(StaticText27, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice_YDecimals = new wxChoice(Panel4, ID_CHOICE14, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE14"));
    Choice_YDecimals->SetSelection( Choice_YDecimals->Append(_("0")) );
    Choice_YDecimals->Append(_("1"));
    Choice_YDecimals->Append(_("2"));
    Choice_YDecimals->Append(_("3"));
    Choice_YDecimals->Append(_("4"));
    Choice_YDecimals->Append(_("5"));
    Choice_YDecimals->Append(_("6"));
    FlexGridSizer5->Add(Choice_YDecimals, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText28 = new wxStaticText(Panel4, ID_STATICTEXT28, _("Offset"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT28"));
    FlexGridSizer5->Add(StaticText28, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_YOffset = new wxTextCtrl(Panel4, ID_TEXTCTRL14, _("0"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL14"));
    FlexGridSizer5->Add(TextCtrl_YOffset, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText29 = new wxStaticText(Panel4, ID_STATICTEXT29, _("Factor"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT29"));
    FlexGridSizer5->Add(StaticText29, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_YFactor = new wxTextCtrl(Panel4, ID_TEXTCTRL15, _("1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL15"));
    FlexGridSizer5->Add(TextCtrl_YFactor, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Panel4->SetSizer(FlexGridSizer5);
    FlexGridSizer5->Fit(Panel4);
    FlexGridSizer5->SetSizeHints(Panel4);
    BoxSizer5->Add(Panel4, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel5 = new wxPanel(Panel_YAxis, ID_PANEL10, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxTAB_TRAVERSAL, _T("ID_PANEL10"));
    FlexGridSizer6 = new wxFlexGridSizer(5, 2, 0, 0);
    FlexGridSizer6->AddGrowableCol(1);
    StaticText30 = new wxStaticText(Panel5, ID_STATICTEXT30, _("Source"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
    FlexGridSizer6->Add(StaticText30, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice_YSource = new wxChoice(Panel5, ID_CHOICE15, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE15"));
    Choice_YSource->SetSelection( Choice_YSource->Append(_("Manual")) );
    Choice_YSource->Append(_("Embedded"));
    Choice_YSource->Append(_("Scaled"));
    FlexGridSizer6->Add(Choice_YSource, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText31 = new wxStaticText(Panel5, ID_STATICTEXT31, _("Address"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT31"));
    FlexGridSizer6->Add(StaticText31, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl_YAddress = new wxTextCtrl(Panel5, ID_TEXTCTRL16, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL16"));
    FlexGridSizer6->Add(TextCtrl_YAddress, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText32 = new wxStaticText(Panel5, ID_STATICTEXT32, _("Sign"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT32"));
    FlexGridSizer6->Add(StaticText32, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice_YSign = new wxChoice(Panel5, ID_CHOICE16, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE16"));
    Choice_YSign->SetSelection( Choice_YSign->Append(_("Unsigned")) );
    Choice_YSign->Append(_("Signed"));
    FlexGridSizer6->Add(Choice_YSign, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText33 = new wxStaticText(Panel5, ID_STATICTEXT33, _("Bits"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT33"));
    FlexGridSizer6->Add(StaticText33, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice_YBits = new wxChoice(Panel5, ID_CHOICE17, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE17"));
    Choice_YBits->Append(_("8"));
    Choice_YBits->SetSelection( Choice_YBits->Append(_("16")) );
    Choice_YBits->Append(_("32"));
    FlexGridSizer6->Add(Choice_YBits, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText34 = new wxStaticText(Panel5, ID_STATICTEXT34, _("Byte Order"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT34"));
    FlexGridSizer6->Add(StaticText34, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice_YByteOrder = new wxChoice(Panel5, ID_CHOICE18, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE18"));
    Choice_YByteOrder->Append(_("MSB First"));
    Choice_YByteOrder->SetSelection( Choice_YByteOrder->Append(_("LSB First")) );
    FlexGridSizer6->Add(Choice_YByteOrder, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Panel5->SetSizer(FlexGridSizer6);
    FlexGridSizer6->Fit(Panel5);
    FlexGridSizer6->SetSizeHints(Panel5);
    BoxSizer5->Add(Panel5, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4->Add(BoxSizer5, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    Grid_YGrid = new wxGrid(Panel_YAxis, ID_GRID2, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID2"));
    Grid_YGrid->CreateGrid(1,1);
    Grid_YGrid->EnableEditing(true);
    Grid_YGrid->EnableGridLines(true);
    Grid_YGrid->SetDefaultCellFont( Grid_YGrid->GetFont() );
    Grid_YGrid->SetDefaultCellTextColour( Grid_YGrid->GetForegroundColour() );
    BoxSizer6->Add(Grid_YGrid, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4->Add(BoxSizer6, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Panel_YAxis->SetSizer(BoxSizer4);
    BoxSizer4->Fit(Panel_YAxis);
    BoxSizer4->SetSizeHints(Panel_YAxis);
    Notebook1->AddPage(Panel_Settings, _("Settings"), false);
    Notebook1->AddPage(Panel_ZAxis, _("Z Axis"), false);
    Notebook1->AddPage(Panel_XAxis, _("X Axis"), false);
    Notebook1->AddPage(Panel_YAxis, _("Y Axis"), false);
    BoxSizer1->Add(Notebook1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Button_Apply = new wxButton(this, ID_BUTTON1, _("Apply && Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Button_Apply, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button_Cancel = new wxButton(this, ID_BUTTON3, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer2->Add(Button_Cancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_TEXTCTRL8,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MapEditorDialog::OnTextCtrl_XCountText);
    Connect(ID_COMBOBOX1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MapEditorDialog::OnComboBox_XUnitsTextUpdated);
    Connect(ID_CHOICE7,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MapEditorDialog::OnChoice_XTypeSelect);
    Connect(ID_CHOICE8,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MapEditorDialog::OnChoice_XDecimalsSelect);
    Connect(ID_TEXTCTRL10,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MapEditorDialog::OnTextCtrl_XOffsetText);
    Connect(ID_TEXTCTRL11,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MapEditorDialog::OnTextCtrl_XFactorText);
    Connect(ID_CHOICE9,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MapEditorDialog::OnChoice_XSourceSelect);
    Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MapEditorDialog::OnTextCtrl_XAddressText);
    Connect(ID_CHOICE11,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MapEditorDialog::OnChoice_XSignSelect);
    Connect(ID_CHOICE10,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MapEditorDialog::OnChoice_XBitsSelect);
    Connect(ID_CHOICE12,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MapEditorDialog::OnChoice_XByteOrderSelect);
    Connect(ID_TEXTCTRL12,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MapEditorDialog::OnTextCtrl_YCountText);
    Connect(ID_COMBOBOX2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MapEditorDialog::OnComboBox_YUnitsTextUpdated);
    Connect(ID_CHOICE13,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MapEditorDialog::OnChoice_YTypeSelect);
    Connect(ID_CHOICE14,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MapEditorDialog::OnChoice_YDecimalsSelect);
    Connect(ID_TEXTCTRL14,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MapEditorDialog::OnTextCtrl_YOffsetText);
    Connect(ID_TEXTCTRL15,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MapEditorDialog::OnTextCtrl_YFactorText);
    Connect(ID_CHOICE15,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MapEditorDialog::OnChoice_YSourceSelect);
    Connect(ID_TEXTCTRL16,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&MapEditorDialog::OnTextCtrl_YAddressText);
    Connect(ID_CHOICE16,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MapEditorDialog::OnChoice_YSignSelect);
    Connect(ID_CHOICE17,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MapEditorDialog::OnChoice_YBitsSelect);
    Connect(ID_CHOICE18,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&MapEditorDialog::OnChoice_YByteOrderSelect);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MapEditorDialog::OnButton_ApplyClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MapEditorDialog::OnButton_CancelClick);
    //*)

    Grid_XGrid->SetDefaultCellAlignment(wxALIGN_RIGHT,wxALIGN_CENTRE);
    Grid_YGrid->SetDefaultCellAlignment(wxALIGN_RIGHT,wxALIGN_CENTRE);

    exit_status=false;
}

MapEditorDialog::~MapEditorDialog()
{
    //(*Destroy(MapEditorDialog)
    //*)
}

/// ---------------------------------------------------------------------------
/// Event handlers
/// ---------------------------------------------------------------------------

void MapEditorDialog::OnButton_ApplyClick(wxCommandEvent& event)
{
    long lvalue;

    // General
    global->xmltable[current_map].title=TextCtrl_Name->GetValue();
    global->xmltable[current_map].description=TextCtrl_Description->GetValue();

    // Z Axis
    global->xmlaxis[current_map][2].address=HEX2Int(_T("0x") + TextCtrl_Address->GetValue());

    global->xmlaxis[current_map][2].bits=Choice_Bits->GetSelection() == 0 ? 8 :
                                         Choice_Bits->GetSelection() == 1 ? 16 :
                                         Choice_Bits->GetSelection() == 2 ? 32 : 16;

    global->xmlaxis[current_map][2].flags=(Choice_DataOrder->GetSelection() << 2) |
                                          (Choice_ByteOrder->GetSelection() << 1) |
                                           Choice_Sign->GetSelection();

    global->xmlaxis[current_map][2].units=ComboBox_ZUnits->GetValue();

    global->xmlaxis[current_map][2].outputtype=Choice_ZType->GetSelection() == 0 ? 2 : 1;

    global->xmlaxis[current_map][2].decimalpl=Choice_ZDecimals->GetSelection();

    if(!TextCtrl_ZOffset->GetValue().ToDouble(&global->xmlaxis[current_map][2].offset))
    {
        global->xmlaxis[current_map][2].offset=0;
    }

    if(!TextCtrl_ZFactor->GetValue().ToDouble(&global->xmlaxis[current_map][2].factor))
    {
        global->xmlaxis[current_map][2].factor=0;
    }

    // X Axis
    if(TextCtrl_XCount->GetValue().ToLong(&lvalue))
    {
         global->xmlaxis[current_map][0].count=(unsigned short)lvalue;
    }
    else
    {
         global->xmlaxis[current_map][0].count=0;
    }

    global->xmlaxis[current_map][0].units=ComboBox_XUnits->GetValue();

    global->xmlaxis[current_map][0].outputtype=Choice_XType->GetSelection() == 0 ? 2 : 1;

    global->xmlaxis[current_map][0].decimalpl=Choice_XDecimals->GetSelection();

    if(!TextCtrl_XOffset->GetValue().ToDouble(&global->xmlaxis[current_map][0].offset))
    {
        global->xmlaxis[current_map][0].offset=0;
    }

    if(!TextCtrl_XFactor->GetValue().ToDouble(&global->xmlaxis[current_map][0].factor))
    {
        global->xmlaxis[current_map][0].factor=0;
    }

    global->xmlaxis[current_map][0].embeddedinfotype=Choice_XSource->GetSelection();

    global->xmlaxis[current_map][0].address=HEX2Int(_T("0x") + TextCtrl_XAddress->GetValue());

    global->xmlaxis[current_map][0].flags=(Choice_XByteOrder->GetSelection() << 1) |
                                           Choice_XSign->GetSelection();

    global->xmlaxis[current_map][0].bits=Choice_XBits->GetSelection() == 0 ? 8 :
                                         Choice_XBits->GetSelection() == 1 ? 16 :
                                         Choice_XBits->GetSelection() == 2 ? 32 : 16;

    if (global->xmlaxis[current_map][0].embeddedinfotype==EMBEDDEDINFO_STORED)
    {
        for (unsigned short y=0; y < global->xmlaxis[current_map][0].count; y++)
        {
            if(!Grid_XGrid->GetCellValue(y,0).ToDouble(&global->xmlaxis[current_map][0].embeddedinfolabel[y]))
            {
                global->xmlaxis[current_map][0].embeddedinfolabel[y]=0;
            }
        }
    }
    else if (global->xmlaxis[current_map][0].embeddedinfotype==EMBEDDEDINFO_SCALED)
    {
        for (unsigned short y=0; y < 2; y++)
        {
            if(!Grid_XGrid->GetCellValue(y,0).ToDouble(&global->xmlaxis[current_map][0].embeddedinfolabel[y]))
            {
                global->xmlaxis[current_map][0].embeddedinfolabel[y]=0;
            }
        }
    }

    // Y Axis
    if(TextCtrl_YCount->GetValue().ToLong(&lvalue))
    {
         global->xmlaxis[current_map][1].count=(unsigned short)lvalue;
    }
    else
    {
         global->xmlaxis[current_map][1].count=0;
    }

    global->xmlaxis[current_map][1].units=ComboBox_YUnits->GetValue();

    global->xmlaxis[current_map][1].outputtype=Choice_YType->GetSelection() == 0 ? 2 : 1;

    global->xmlaxis[current_map][1].decimalpl=Choice_YDecimals->GetSelection();

    if(!TextCtrl_YOffset->GetValue().ToDouble(&global->xmlaxis[current_map][1].offset))
    {
        global->xmlaxis[current_map][1].offset=0;
    }

    if(!TextCtrl_YFactor->GetValue().ToDouble(&global->xmlaxis[current_map][1].factor))
    {
        global->xmlaxis[current_map][1].factor=0;
    }

    global->xmlaxis[current_map][1].embeddedinfotype=Choice_YSource->GetSelection();

    global->xmlaxis[current_map][1].address=HEX2Int(_T("0x") + TextCtrl_YAddress->GetValue());

    global->xmlaxis[current_map][1].flags=(Choice_YByteOrder->GetSelection() << 1) |
                                           Choice_YSign->GetSelection();

    global->xmlaxis[current_map][1].bits=Choice_YBits->GetSelection() == 0 ? 8 :
                                         Choice_YBits->GetSelection() == 1 ? 16 :
                                         Choice_YBits->GetSelection() == 2 ? 32 : 16;

    if (global->xmlaxis[current_map][1].embeddedinfotype==EMBEDDEDINFO_STORED)
    {
        for (unsigned short y=0; y < global->xmlaxis[current_map][1].count; y++)
        {
            if(!Grid_YGrid->GetCellValue(y,0).ToDouble(&global->xmlaxis[current_map][1].embeddedinfolabel[y]))
            {
                global->xmlaxis[current_map][1].embeddedinfolabel[y]=0;
            }
        }
    }
    else if (global->xmlaxis[current_map][1].embeddedinfotype==EMBEDDEDINFO_SCALED)
    {
        for (unsigned short y=0; y < 2; y++)
        {
            if(!Grid_YGrid->GetCellValue(y,0).ToDouble(&global->xmlaxis[current_map][1].embeddedinfolabel[y]))
            {
                global->xmlaxis[current_map][1].embeddedinfolabel[y]=0;
            }
        }
    }

    exit_status=true;

    Close();
}

void MapEditorDialog::OnButton_CancelClick(wxCommandEvent& event)
{
    exit_status=false;

    Close();
}

void MapEditorDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

/// X -------------------------------------------------------------------------

void MapEditorDialog::OnTextCtrl_XCountText(wxCommandEvent& event)
{
    long value;

    if (Choice_XSource->GetSelection() < 2)
    {
        if (TextCtrl_XCount->GetValue().ToLong(&value))
        {
            Grid_XGrid->DeleteRows(0,Grid_XGrid->GetNumberRows());
            if (value) Grid_XGrid->AppendRows((int)value);

            if (value > 0) Grid_XGrid->SetRowLabelValue(0,_T("1"));
            if (value > 1) Grid_XGrid->SetRowLabelValue(1,_T("2"));

            Update_XGrid();
        }
    }
    else
    {
        Grid_XGrid->DeleteRows(0,Grid_XGrid->GetNumberRows());
        Grid_XGrid->AppendRows(2);
        Grid_XGrid->SetRowLabelValue(0,_("Min"));
        Grid_XGrid->SetRowLabelValue(1,_("Max"));
    }
}

void MapEditorDialog::OnComboBox_XUnitsTextUpdated(wxCommandEvent& event)
{
    Grid_XGrid->SetColLabelValue(0,ComboBox_XUnits->GetValue());
}

void MapEditorDialog::OnChoice_XTypeSelect(wxCommandEvent& event)
{
    Update_XGrid();
}

void MapEditorDialog::OnChoice_XDecimalsSelect(wxCommandEvent& event)
{
    Update_XGrid();
}

void MapEditorDialog::OnTextCtrl_XOffsetText(wxCommandEvent& event)
{
    Update_XGrid();
}

void MapEditorDialog::OnTextCtrl_XFactorText(wxCommandEvent& event)
{
    Update_XGrid();
}

void MapEditorDialog::OnChoice_XSourceSelect(wxCommandEvent& event)
{
    long value;

    if (Choice_XSource->GetSelection() < 2)
    {
        if (TextCtrl_XCount->GetValue().ToLong(&value))
        {
            Grid_XGrid->DeleteRows(0,Grid_XGrid->GetNumberRows());
            if (value) Grid_XGrid->AppendRows((int)value);

            if (value > 0) Grid_XGrid->SetRowLabelValue(0,_T("1"));
            if (value > 1) Grid_XGrid->SetRowLabelValue(1,_T("2"));

            Update_XGrid();
        }
    }
    else
    {
        Grid_XGrid->DeleteRows(0,Grid_XGrid->GetNumberRows());
        Grid_XGrid->AppendRows(2);
        Grid_XGrid->SetRowLabelValue(0,_("Min"));
        Grid_XGrid->SetRowLabelValue(1,_("Max"));
    }
}

void MapEditorDialog::OnTextCtrl_XAddressText(wxCommandEvent& event)
{
    Update_XGrid();
}

void MapEditorDialog::OnChoice_XSignSelect(wxCommandEvent& event)
{
    Update_XGrid();
}

void MapEditorDialog::OnChoice_XBitsSelect(wxCommandEvent& event)
{
    Update_XGrid();
}

void MapEditorDialog::OnChoice_XByteOrderSelect(wxCommandEvent& event)
{
    Update_XGrid();
}

/// Y -------------------------------------------------------------------------

void MapEditorDialog::OnTextCtrl_YCountText(wxCommandEvent& event)
{
    long value;

    if (Choice_YSource->GetSelection() < 2)
    {
        if (TextCtrl_YCount->GetValue().ToLong(&value))
        {
            Grid_YGrid->DeleteRows(0,Grid_YGrid->GetNumberRows());
            if (value) Grid_YGrid->AppendRows((int)value);

            if (value > 0) Grid_YGrid->SetRowLabelValue(0,_T("1"));
            if (value > 1) Grid_YGrid->SetRowLabelValue(1,_T("2"));

            Update_YGrid();
        }
    }
    else
    {
        Grid_YGrid->DeleteRows(0,Grid_YGrid->GetNumberRows());
        Grid_YGrid->AppendRows(2);
        Grid_YGrid->SetRowLabelValue(0,_("Min"));
        Grid_YGrid->SetRowLabelValue(1,_("Max"));
    }
}

void MapEditorDialog::OnComboBox_YUnitsTextUpdated(wxCommandEvent& event)
{
    Grid_YGrid->SetColLabelValue(0,ComboBox_YUnits->GetValue());
}

void MapEditorDialog::OnChoice_YTypeSelect(wxCommandEvent& event)
{
    Update_YGrid();
}

void MapEditorDialog::OnChoice_YDecimalsSelect(wxCommandEvent& event)
{
    Update_YGrid();
}

void MapEditorDialog::OnTextCtrl_YOffsetText(wxCommandEvent& event)
{
    Update_YGrid();
}

void MapEditorDialog::OnTextCtrl_YFactorText(wxCommandEvent& event)
{
    Update_YGrid();
}

void MapEditorDialog::OnChoice_YSourceSelect(wxCommandEvent& event)
{
    long value;

    if (Choice_YSource->GetSelection() < 2)
    {
        if (TextCtrl_YCount->GetValue().ToLong(&value))
        {
            Grid_YGrid->DeleteRows(0,Grid_YGrid->GetNumberRows());
            if (value) Grid_YGrid->AppendRows((int)value);

            if (value > 0) Grid_YGrid->SetRowLabelValue(0,_T("1"));
            if (value > 1) Grid_YGrid->SetRowLabelValue(1,_T("2"));

            Update_YGrid();
        }
    }
    else
    {
        Grid_YGrid->DeleteRows(0,Grid_YGrid->GetNumberRows());
        Grid_YGrid->AppendRows(2);
        Grid_YGrid->SetRowLabelValue(0,_("Min"));
        Grid_YGrid->SetRowLabelValue(1,_("Max"));
    }
}

void MapEditorDialog::OnTextCtrl_YAddressText(wxCommandEvent& event)
{
    Update_YGrid();
}

void MapEditorDialog::OnChoice_YSignSelect(wxCommandEvent& event)
{
    Update_YGrid();
}

void MapEditorDialog::OnChoice_YBitsSelect(wxCommandEvent& event)
{
    Update_YGrid();
}

void MapEditorDialog::OnChoice_YByteOrderSelect(wxCommandEvent& event)
{
    Update_YGrid();
}

/// ---------------------------------------------------------------------------
/// Custom Functions
/// ---------------------------------------------------------------------------

void MapEditorDialog::NewEditor(unsigned short selected_map, GlobalVariables *gv)
{
    global = gv;
    current_map=selected_map;

    // General
    TextCtrl_Name->SetValue(_("New Map"));
    TextCtrl_Description->SetValue(_T(""));

    TextCtrl_Address->SetValue(_T("0"));
    Choice_Bits->SetSelection(1);
    Choice_Sign->SetSelection(0);
    Choice_ByteOrder->SetSelection(0);
    Choice_DataOrder->SetSelection(0);

    // Z Axis
    ComboBox_ZUnits->SetValue(_T(""));
    Choice_ZType->SetSelection(0);
    Choice_ZDecimals->SetSelection(0);
    TextCtrl_ZOffset->SetValue(_T("0"));
    TextCtrl_ZFactor->SetValue(_T("1"));

    // X Axis
    TextCtrl_XCount->SetValue(_T("1"));
    ComboBox_XUnits->SetValue(_T(""));
    Choice_XType->SetSelection(0);
    Choice_XDecimals->SetSelection(0);
    TextCtrl_XOffset->SetValue(_T("0"));
    TextCtrl_XFactor->SetValue(_T("1"));

    Choice_XSource->SetSelection(EMBEDDEDINFO_CALC);
    TextCtrl_XAddress->SetValue(_T("0"));
    Choice_XSign->SetSelection(0);
    Choice_XBits->SetSelection(1);
    Choice_XByteOrder->SetSelection(0);

    // Y Axis
    TextCtrl_YCount->SetValue(_T("1"));
    ComboBox_YUnits->SetValue(_T(""));
    Choice_YType->SetSelection(0);
    Choice_YDecimals->SetSelection(0);
    TextCtrl_YOffset->SetValue(_T("0"));
    TextCtrl_YFactor->SetValue(_T("1"));

    Choice_YSource->SetSelection(EMBEDDEDINFO_CALC);
    TextCtrl_YAddress->SetValue(_T("0"));
    Choice_YSign->SetSelection(0);
    Choice_YBits->SetSelection(1);
    Choice_YByteOrder->SetSelection(0);
}

void MapEditorDialog::UpdateEditor(unsigned short selected_map, GlobalVariables *gv)
{
    double value;
    unsigned int address;

    global = gv;
    current_map=selected_map;

    // General
    TextCtrl_Name->SetValue(global->xmltable[current_map].title);
    TextCtrl_Description->SetValue(global->xmltable[current_map].description);

    // Z Axis
    ComboBox_ZUnits->SetValue(global->xmlaxis[current_map][2].units);
    Choice_ZType->SetSelection(global->xmlaxis[current_map][2].outputtype == 2 ? 0 : 1);
    Choice_ZDecimals->SetSelection(global->xmlaxis[current_map][2].decimalpl);
    TextCtrl_ZOffset->SetValue(wxString::Format(_T("%f"),global->xmlaxis[current_map][2].offset));
    TextCtrl_ZFactor->SetValue(wxString::Format(_T("%f"),global->xmlaxis[current_map][2].factor));

    TextCtrl_Address->SetValue(Int2HEX(global->xmlaxis[current_map][2].address));
    Choice_Bits->SetSelection(global->xmlaxis[current_map][2].bits == 8 ? 0 :
                              global->xmlaxis[current_map][2].bits == 16 ? 1 :
                              global->xmlaxis[current_map][2].bits == 32 ? 2 : 1);
    Choice_Sign->SetSelection((global->xmlaxis[current_map][2].flags & FLAGS_SIGNED_BIT) == 1 ? 1 : 0);
    Choice_ByteOrder->SetSelection((global->xmlaxis[current_map][2].flags & FLAGS_ORDER_BIT) == 2 ? 1 : 0);
    Choice_DataOrder->SetSelection((global->xmlaxis[current_map][2].flags & FLAGS_RC_BIT) == 4 ? 1 : 0);

    // X Axis
    Choice_XSource->SetSelection(global->xmlaxis[current_map][0].embeddedinfotype);
    TextCtrl_XCount->SetValue(wxString::Format(_T("%i"),global->xmlaxis[current_map][0].count));
    ComboBox_XUnits->SetValue(global->xmlaxis[current_map][0].units);
    Grid_XGrid->SetColLabelValue(0,global->xmlaxis[current_map][0].units);
    Choice_XType->SetSelection(global->xmlaxis[current_map][0].outputtype == 2 ? 0 : 1);
    Choice_XDecimals->SetSelection(global->xmlaxis[current_map][0].decimalpl);
    TextCtrl_XOffset->SetValue(wxString::Format(_T("%f"),global->xmlaxis[current_map][0].offset));
    TextCtrl_XFactor->SetValue(wxString::Format(_T("%f"),global->xmlaxis[current_map][0].factor));

    TextCtrl_XAddress->SetValue(Int2HEX(global->xmlaxis[current_map][0].address));
    Choice_XSign->SetSelection((global->xmlaxis[current_map][0].flags & FLAGS_SIGNED_BIT) == 1 ? 1 : 0);
    Choice_XBits->SetSelection(global->xmlaxis[current_map][0].bits == 8 ? 0 :
                               global->xmlaxis[current_map][0].bits == 16 ? 1 :
                               global->xmlaxis[current_map][0].bits == 32 ? 2 : 1);
    Choice_XByteOrder->SetSelection((global->xmlaxis[current_map][0].flags & FLAGS_ORDER_BIT) == 2 ? 1 : 0);

    if (global->xmlaxis[current_map][0].embeddedinfotype==EMBEDDEDINFO_STORED)
    {
        for (unsigned short y=0; y < global->xmlaxis[current_map][0].count; y++)
        {
            Grid_XGrid->SetCellValue(y,0,wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][0].decimalpl) + _T("f"),global->xmlaxis[current_map][0].embeddedinfolabel[y]));
        }
    }
    else if (global->xmlaxis[current_map][0].embeddedinfotype==EMBEDDEDINFO_CALC)
    {
        if (global->bin_length[global->selected_bin])
        {
            address=global->xmlaxis[current_map][0].address;

            for (int y=0; y < global->xmlaxis[current_map][0].count; y++)
            {
                value=GetEngineeringValueFromAddress(global->bin_buffer[global->selected_bin], address, 0);
                address=IncrementAddress(address, 0);

                if (global->xmlaxis[current_map][0].outputtype==OUTPUTTYPE_INT)
                {
                    if (global->xmlaxis[current_map][0].flags & FLAGS_SIGNED_BIT)
                    {
                        Grid_XGrid->SetCellValue(y,0,wxString::Format(_T("%i"),(int)value));
                    }
                    else
                    {
                        Grid_XGrid->SetCellValue(y,0,wxString::Format(_T("%i"),(unsigned int)value));
                    }
                }
                else
                {
                    Grid_XGrid->SetCellValue(y,0,wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][0].decimalpl) + _T("f"),value));
                }
            }
        }
    }
    else if (global->xmlaxis[current_map][0].embeddedinfotype==EMBEDDEDINFO_SCALED)
    {
        for (unsigned short y=0; y < 2; y++)
        {
            Grid_XGrid->SetCellValue(y,0,wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][0].decimalpl) + _T("f"),global->xmlaxis[current_map][0].embeddedinfolabel[y]));
        }
    }

    // Y Axis
    Choice_YSource->SetSelection(global->xmlaxis[current_map][1].embeddedinfotype);
    TextCtrl_YCount->SetValue(wxString::Format(_T("%i"),global->xmlaxis[current_map][1].count));
    ComboBox_YUnits->SetValue(global->xmlaxis[current_map][1].units);
    Grid_YGrid->SetColLabelValue(0,global->xmlaxis[current_map][1].units);
    Choice_YType->SetSelection(global->xmlaxis[current_map][1].outputtype == 2 ? 0 : 1);
    Choice_YDecimals->SetSelection(global->xmlaxis[current_map][1].decimalpl);
    TextCtrl_YOffset->SetValue(wxString::Format(_T("%f"),global->xmlaxis[current_map][1].offset));
    TextCtrl_YFactor->SetValue(wxString::Format(_T("%f"),global->xmlaxis[current_map][1].factor));

    TextCtrl_YAddress->SetValue(Int2HEX(global->xmlaxis[current_map][1].address));
    Choice_YSign->SetSelection((global->xmlaxis[current_map][1].flags & FLAGS_SIGNED_BIT) == 1 ? 1 : 0);
    Choice_YBits->SetSelection(global->xmlaxis[current_map][1].bits == 8 ? 0 :
                               global->xmlaxis[current_map][1].bits == 16 ? 1 :
                               global->xmlaxis[current_map][1].bits == 32 ? 2 : 1);
    Choice_YByteOrder->SetSelection((global->xmlaxis[current_map][1].flags & FLAGS_ORDER_BIT) == 2 ? 1 : 0);

    if (global->xmlaxis[current_map][1].embeddedinfotype==EMBEDDEDINFO_STORED)
    {
        for (unsigned short y=0; y < global->xmlaxis[current_map][1].count; y++)
        {
            Grid_YGrid->SetCellValue(y,0,wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][1].decimalpl) + _T("f"),global->xmlaxis[current_map][1].embeddedinfolabel[y]));
        }
    }
    else if (global->xmlaxis[current_map][1].embeddedinfotype==EMBEDDEDINFO_CALC)
    {
        if (global->bin_length[global->selected_bin])
        {
            address=global->xmlaxis[current_map][1].address;

            for (int y=0; y < global->xmlaxis[current_map][1].count; y++)
            {
                value=GetEngineeringValueFromAddress(global->bin_buffer[global->selected_bin], address, 1);
                address=IncrementAddress(address, 1);

                if (global->xmlaxis[current_map][1].outputtype==OUTPUTTYPE_INT)
                {
                    if (global->xmlaxis[current_map][1].flags & FLAGS_SIGNED_BIT)
                    {
                        Grid_YGrid->SetCellValue(y,0,wxString::Format(_T("%i"),(int)value));
                    }
                    else
                    {
                        Grid_YGrid->SetCellValue(y,0,wxString::Format(_T("%i"),(unsigned int)value));
                    }
                }
                else
                {
                    Grid_YGrid->SetCellValue(y,0,wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][1].decimalpl) + _T("f"),value));
                }
            }
        }
    }
    else if (global->xmlaxis[current_map][1].embeddedinfotype==EMBEDDEDINFO_SCALED)
    {
        for (unsigned short y=0; y < 2; y++)
        {
            Grid_YGrid->SetCellValue(y,0,wxString::Format(_T("%.") + wxString::Format(_T("%i"),global->xmlaxis[current_map][1].decimalpl) + _T("f"),global->xmlaxis[current_map][1].embeddedinfolabel[y]));
        }
    }
}

void MapEditorDialog::Update_XGrid(void)
{
    long lvalue;
    double value;

    unsigned short flags;
    unsigned int address;
    unsigned short bits;
    unsigned short decimalpl;
    unsigned short count;
    unsigned short outputtype;
    double factor;
    double offset;

    if (Choice_XSource->GetSelection() != EMBEDDEDINFO_CALC)
        return;

    if(TextCtrl_XCount->GetValue().ToLong(&lvalue))
         count=(unsigned short)lvalue;
    else
        return;

    outputtype=Choice_XType->GetSelection() == 0 ? 2 : 1;
    decimalpl=Choice_XDecimals->GetSelection();

    if(!TextCtrl_XOffset->GetValue().ToDouble(&offset))
        return;

    if(!TextCtrl_XFactor->GetValue().ToDouble(&factor))
        return;

    address=HEX2Int(_T("0x") + TextCtrl_XAddress->GetValue());
    if (address > global->bin_length[global->selected_bin])
        return;

    flags=(Choice_XByteOrder->GetSelection() << 1) |
          Choice_XSign->GetSelection();

    bits=Choice_XBits->GetSelection() == 0 ? 8 :
         Choice_XBits->GetSelection() == 1 ? 16 :
         Choice_XBits->GetSelection() == 2 ? 32 : 16;

    if (global->bin_length[global->selected_bin])
    {
        for (int y=0; y < count; y++)
        {
            value=GetEngineeringValueFromAddress2(global->bin_buffer[global->selected_bin], flags, address, bits, decimalpl, factor, offset);
            address=IncrementAddress2(address, bits);

            if (outputtype==OUTPUTTYPE_INT)
            {
                if (flags & FLAGS_SIGNED_BIT)
                {
                    Grid_XGrid->SetCellValue(y,0,wxString::Format(_T("%i"),(int)value));
                }
                else
                {
                    Grid_XGrid->SetCellValue(y,0,wxString::Format(_T("%i"),(unsigned int)value));
                }
            }
            else
            {
                Grid_XGrid->SetCellValue(y,0,wxString::Format(_T("%.") + wxString::Format(_T("%i"),decimalpl) + _T("f"),value));
            }
        }
    }
}

void MapEditorDialog::Update_YGrid(void)
{
    long lvalue;
    double value;

    unsigned short flags;
    unsigned int address;
    unsigned short bits;
    unsigned short decimalpl;
    unsigned short count;
    unsigned short outputtype;
    double factor;
    double offset;

    if (Choice_YSource->GetSelection() != EMBEDDEDINFO_CALC)
        return;

    if(TextCtrl_YCount->GetValue().ToLong(&lvalue))
         count=(unsigned short)lvalue;
    else
        return;

    outputtype=Choice_YType->GetSelection() == 0 ? 2 : 1;
    decimalpl=Choice_YDecimals->GetSelection();

    if(!TextCtrl_YOffset->GetValue().ToDouble(&offset))
        return;

    if(!TextCtrl_YFactor->GetValue().ToDouble(&factor))
        return;

    address=HEX2Int(_T("0x") + TextCtrl_YAddress->GetValue());
    if (address > global->bin_length[global->selected_bin])
        return;

    flags=(Choice_YByteOrder->GetSelection() << 1) |
          Choice_YSign->GetSelection();

    bits=Choice_YBits->GetSelection() == 0 ? 8 :
         Choice_YBits->GetSelection() == 1 ? 16 :
         Choice_YBits->GetSelection() == 2 ? 32 : 16;

    if (global->bin_length[global->selected_bin])
    {
        for (int y=0; y < count; y++)
        {
            value=GetEngineeringValueFromAddress2(global->bin_buffer[global->selected_bin], flags, address, bits, decimalpl, factor, offset);
            address=IncrementAddress2(address, bits);

            if (outputtype==OUTPUTTYPE_INT)
            {
                if (flags & FLAGS_SIGNED_BIT)
                {
                    Grid_YGrid->SetCellValue(y,0,wxString::Format(_T("%i"),(int)value));
                }
                else
                {
                    Grid_YGrid->SetCellValue(y,0,wxString::Format(_T("%i"),(unsigned int)value));
                }
            }
            else
            {
                Grid_YGrid->SetCellValue(y,0,wxString::Format(_T("%.") + wxString::Format(_T("%i"),decimalpl) + _T("f"),value));
            }
        }
    }
}

double MapEditorDialog::GetEngineeringValueFromAddress(unsigned char *buffer, unsigned int address, unsigned short axis)
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

double MapEditorDialog::GetEngineeringValueFromAddress2(unsigned char *buffer, unsigned short flags, unsigned int address, unsigned short bits, unsigned short decimalpl, double factor, double offset)
{
    unsigned int unsigned_raw_value=0;
    int signed_raw_value=0;

    if (bits==8)
        unsigned_raw_value=buffer[address];
    else if ((bits==16) && (flags & FLAGS_ORDER_BIT))
        unsigned_raw_value=((unsigned int)buffer[address+1] << 8) + (unsigned int)buffer[address];
    else if ((bits==16) && (!(flags & FLAGS_ORDER_BIT)))
        unsigned_raw_value=((unsigned int)buffer[address] << 8) + (unsigned int)buffer[address+1];
    else if ((bits==32) && (flags & FLAGS_ORDER_BIT))
    {
        unsigned_raw_value=((unsigned int)buffer[address+3] << 24) +
                           ((unsigned int)buffer[address+2] << 16) +
                           ((unsigned int)buffer[address+1] << 8) +
                           (unsigned int)buffer[address];
    }
    else if ((bits==32) && (!(flags & FLAGS_ORDER_BIT)))
    {
        unsigned_raw_value=((unsigned int)buffer[address] << 24) +
                           ((unsigned int)buffer[address+1] << 16) +
                           ((unsigned int)buffer[address+2] << 8) +
                           (unsigned int)buffer[address+3];
    }

    if (flags & FLAGS_SIGNED_BIT)
    {
        if ((bits==8) && (!(unsigned_raw_value & 0x00000080)))  // Positive Number
            signed_raw_value=(int)unsigned_raw_value;
        else if ((bits==8) && (unsigned_raw_value & 0x00000080))  // Negative Number
            signed_raw_value=(int)unsigned_raw_value - 0x100;
        else if ((bits==16) && (!(unsigned_raw_value & 0x00008000)))  // Positive Number
            signed_raw_value=(int)unsigned_raw_value;
        else if ((bits==16) && (unsigned_raw_value & 0x00008000))  // Negative Number
            signed_raw_value=(int)unsigned_raw_value - 0x10000;
        else if ((bits==32) && (!(unsigned_raw_value & 0x80000000)))  // Positive Number
            signed_raw_value=(int)unsigned_raw_value;
        else if ((bits==32) && (unsigned_raw_value & 0x80000000))  // Negative Number
            signed_raw_value=(int)unsigned_raw_value - 0xFFFFFFFF - 1;
    }


    if (flags & FLAGS_SIGNED_BIT)
        return (RoundDouble(((double)signed_raw_value * factor) + offset,decimalpl));
    else
        return (RoundDouble(((double)unsigned_raw_value * factor) + offset,decimalpl));
}

unsigned int MapEditorDialog::IncrementAddress(unsigned int address, unsigned short axis)
{
    if (global->xmlaxis[current_map][axis].bits==8)
        address++;
    else if (global->xmlaxis[current_map][axis].bits==16)
        address+=2;
    else if (global->xmlaxis[current_map][axis].bits==32)
        address+=4;

    return (address);
}

unsigned int MapEditorDialog::IncrementAddress2(unsigned int address, unsigned short bits)
{
    if (bits==8)
        address++;
    else if (bits==16)
        address+=2;
    else if (bits==32)
        address+=4;

    return (address);
}

double MapEditorDialog::RoundDouble(double value, int places)
{
    double temp, mult;

    mult = pow(10.0, places);
    temp = floor(value * mult + 0.5);
    temp = temp / mult;

    return (temp);
}

wxString MapEditorDialog::Int2HEX(unsigned int number)
{
    char buffer[9];

    sprintf(buffer,"%X",number);
    wxString sHex(buffer, wxConvUTF8);

    return (sHex);
}

unsigned int MapEditorDialog::HEX2Int(wxString hex)
{
    char text[11];

    strncpy(text,hex.mb_str(),10);

    return (strtoul (text,NULL,0));
}
