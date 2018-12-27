/***************************************************************
 * Name:      MapViewerMain.cpp
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
#include "MapViewerMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(MapViewerFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

unsigned short quantity_of_nodes;
short selected_node;

wxTreeItemId rootId;
wxTreeItemId subNode[MAX_NODES_DEFINED];

//(*IdInit(MapViewerFrame)
const long MapViewerFrame::ID_TREECTRL1 = wxNewId();
const long MapViewerFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MapViewerFrame,wxFrame)
    //(*EventTable(MapViewerFrame)
    //*)
END_EVENT_TABLE()

MapViewerFrame::MapViewerFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(MapViewerFrame)
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    TreeCtrl = new wxTreeCtrl(Panel1, ID_TREECTRL1, wxDefaultPosition, wxSize(183,293), wxTR_FULL_ROW_HIGHLIGHT|wxTR_DEFAULT_STYLE, wxDefaultValidator, _T("ID_TREECTRL1"));
    BoxSizer2->Add(TreeCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_ITEM_ACTIVATED,(wxObjectEventFunction)&MapViewerFrame::OnTreeCtrlItemActivated);
    Connect(ID_TREECTRL1,wxEVT_COMMAND_TREE_SEL_CHANGED,(wxObjectEventFunction)&MapViewerFrame::OnTreeCtrlSelectionChanged);
    //*)

    // Assign glyph
    //wxBitmap treeImage = wxBitmap(_T("images/layouts.png"), wxBITMAP_TYPE_PNG);
    //wxImageList *pImageList = new wxImageList( 32, 32, true );
    //pImageList->Add(treeImage, wxColor(_T("WHITE")));
    //TreeCtrl->AssignImageList(pImageList);

    // Generate root node
    rootId=TreeCtrl->AddRoot(_("Maps"),-1,-1,NULL);

    quantity_of_nodes=0;
    selected_node=-1;
}

MapViewerFrame::~MapViewerFrame()
{
    //(*Destroy(MapViewerFrame)
    //*)
}

void MapViewerFrame::Init(GlobalVariables *gv)
{
    global = gv;
}

void MapViewerFrame::OnTreeCtrlSelectionChanged(wxTreeEvent& event)
{
    selected_node=-1;

    for (int x=0; x < quantity_of_nodes; x++)
    {
        if (subNode[x] == TreeCtrl->GetSelection())
        {
            selected_node=x;
            break;
        }
    }
}

void MapViewerFrame::ClearTree(void)
{
    // Remove all items
    TreeCtrl->DeleteAllItems();

    // Generate root node
    rootId=TreeCtrl->AddRoot(_("Maps"),-1,-1,NULL);

    quantity_of_nodes=0;
}

void MapViewerFrame::AddTable(wxString name, unsigned short x, unsigned short y, wxString address)
{
    wxString text=name + _T(" (") + address + _T(") [") + wxString::Format(wxT("%i"),x) +
                  _T("x") + wxString::Format(wxT("%i"),y) + _T("]");

    subNode[quantity_of_nodes]=TreeCtrl->AppendItem(rootId,text,-1,-1,NULL);
    TreeCtrl->SetItemImage(subNode[quantity_of_nodes], 0, wxTreeItemIcon_Normal);
    quantity_of_nodes++;
}

void MapViewerFrame::EditTable(unsigned short position, wxString name, unsigned short x, unsigned short y, wxString address)
{
    wxString text=name + _T(" (") + address + _T(") [") + wxString::Format(wxT("%i"),x) +
                  _T("x") + wxString::Format(wxT("%i"),y) + _T("]");

    TreeCtrl->SetItemText(subNode[position],text);
}

short MapViewerFrame::SelectedNode(void)
{
    return (selected_node);
}

void MapViewerFrame::ExpandTree(void)
{
    TreeCtrl->ExpandAll();
}

void MapViewerFrame::OnTreeCtrlItemActivated(wxTreeEvent& event)
{
    // Check for possible error conditions
    if (quantity_of_nodes == 0)
    {
        //SetStatusBarText(_("No maps have been loaded!"),1);
        return;
    }

    if (!global->bin_length[global->selected_bin])
    {
        //SetStatusBarText(_("No BIN file has been loaded in the selected buffer!"),1);
        return;
    }

    // Get currently selected map
	if (selected_node < 0)
    {
        //CrossTunerStudioFrame->SetStatusBarText(_("Please select a map first in the map viewer!"),1);
        return;
    }

	// Create instance
	TableEditorFrame *table_editor_form = new TableEditorFrame(this);

    // Init. table
    table_editor_form->Init(global->selected_bin, selected_node, global);
    table_editor_form->UpdateGridAxis();
    table_editor_form->UpdateGrid();

	// Show dialog
	table_editor_form->Show();
}
