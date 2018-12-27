/***************************************************************
 * Name:      FileOptionsMain.h
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
 
#ifndef FILEOPTIONSMAIN_H
#define FILEOPTIONSMAIN_H

//(*Headers(FileOptionsDialog)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statline.h>
#include <wx/radiobut.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

class FileOptionsDialog: public wxDialog
{
    public:

        FileOptionsDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~FileOptionsDialog();

    private:

        //(*Handlers(FileOptionsDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(FileOptionsDialog)
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT7;
        static const long ID_RADIOBUTTON1;
        static const long ID_STATICTEXT8;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT4;
        static const long ID_TEXTCTRL4;
        static const long ID_RADIOBUTTON2;
        static const long ID_STATICTEXT5;
        static const long ID_TEXTCTRL5;
        static const long ID_STATICTEXT6;
        static const long ID_TEXTCTRL6;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        //*)

        //(*Declarations(FileOptionsDialog)
        wxTextCtrl* TextCtrl4;
        wxRadioButton* RadioButton1;
        wxStaticText* StaticText2;
        wxRadioButton* RadioButton2;
        wxStaticText* StaticText6;
        wxTextCtrl* TextCtrl6;
        wxStaticText* StaticText8;
        wxStaticText* StaticText1;
        wxBoxSizer* BoxSizer2;
        wxStaticText* StaticText3;
        wxButton* Button_Apply;
        wxStaticText* StaticText5;
        wxStaticText* StaticText7;
        wxButton* Button_Cancel;
        wxStaticLine* StaticLine1;
        wxBoxSizer* BoxSizer1;
        wxTextCtrl* TextCtrl5;
        wxStaticText* StaticText4;
        wxTextCtrl* TextCtrl3;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // FILEOPTIONSMAIN_H
