/***************************************************************
 * Name:      MapViewerMain.h
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
 
#ifndef MAPVIEWERMAIN_H
#define MAPVIEWERMAIN_H

//(*Headers(MapViewerFrame)
#include <wx/treectrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>
//*)

#include "../GlobalVariables.h"
#include "../CrossTunerStudioMain.h"
#include "../TableEditor/TableEditorMain.h"

#define MAX_NODES_DEFINED    256

class MapViewerFrame: public wxFrame
{
    public:

        MapViewerFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~MapViewerFrame();

        void Init(GlobalVariables *gv);
        void ClearTree(void);
        void AddTable(wxString name, unsigned short x, unsigned short y, wxString address);
        void EditTable(unsigned short position, wxString name, unsigned short x, unsigned short y, wxString address);
        short SelectedNode(void);
        void ExpandTree(void);

        GlobalVariables *global;

    private:

        //(*Handlers(MapViewerFrame)
        void OnTreeCtrlSelectionChanged(wxTreeEvent& event);
        void OnTreeCtrlItemActivated(wxTreeEvent& event);
        //*)

        //(*Identifiers(MapViewerFrame)
        static const long ID_TREECTRL1;
        static const long ID_PANEL1;
        //*)

        //(*Declarations(MapViewerFrame)
        wxPanel* Panel1;
        wxTreeCtrl* TreeCtrl;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // MAPVIEWERMAIN_H
