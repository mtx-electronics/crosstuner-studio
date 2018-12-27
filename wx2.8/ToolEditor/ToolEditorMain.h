/***************************************************************
 * Name:      ToolEditorMain.h
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
 
#ifndef TOOLEDITORMAIN_H
#define TOOLEDITORMAIN_H

//(*Headers(ToolEditorDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class ToolEditorDialog: public wxDialog
{
    public:

        ToolEditorDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~ToolEditorDialog();

    private:

        //(*Handlers(ToolEditorDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(ToolEditorDialog)
        static const long ID_LISTBOX1;
        static const long ID_BUTTON5;
        static const long ID_BUTTON6;
        static const long ID_BUTTON7;
        static const long ID_STATICLINE2;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRL3;
        static const long ID_BUTTON3;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL4;
        static const long ID_BUTTON4;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        //*)

        //(*Declarations(ToolEditorDialog)
        wxButton* Button_Browse;
        wxButton* Button_Help;
        wxTextCtrl* TextCtrl_Title;
        wxTextCtrl* TextCtrl_Description;
        wxStaticText* StaticText2;
        wxButton* Button1;
        wxStaticText* StaticText1;
        wxBoxSizer* BoxSizer2;
        wxStaticText* StaticText3;
        wxButton* Button2;
        wxButton* Button_Apply;
        wxStaticLine* StaticLine2;
        wxTextCtrl* TextCtrl_Arguments;
        wxButton* Button3;
        wxListBox* ListBox_Tools;
        wxTextCtrl* TextCtrl_Command;
        wxButton* Button_Cancel;
        wxStaticLine* StaticLine1;
        wxBoxSizer* BoxSizer1;
        wxStaticText* StaticText4;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TOOLEDITORMAIN_H
