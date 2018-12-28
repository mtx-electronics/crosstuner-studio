/***************************************************************
 * Name:      AboutBoxDialog.cpp
 * Purpose:   Code for About Box
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

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "AboutBoxDialog.h"
#include <wx/mstream.h>

////@begin XPM images
////@end XPM images

#include "images/logo.h"

/*!
 * AboutBoxDialog type definition
 */

IMPLEMENT_DYNAMIC_CLASS( AboutBoxDialog, wxDialog )


/*!
 * AboutBoxDialog event table definition
 */

BEGIN_EVENT_TABLE( AboutBoxDialog, wxDialog )

////@begin AboutBoxDialog event table entries
////@end AboutBoxDialog event table entries

END_EVENT_TABLE()


/*!
 * AboutBoxDialog constructors
 */

AboutBoxDialog::AboutBoxDialog()
{
    Init();
}

AboutBoxDialog::AboutBoxDialog( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}

/*!
 * AboutBoxDialog destructor
 */

AboutBoxDialog::~AboutBoxDialog()
{
////@begin AboutBoxDialog destruction
////@end AboutBoxDialog destruction
}

/*!
 * Member initialisation
 */

void AboutBoxDialog::Init()
{
////@begin AboutBoxDialog member initialisation
    m_ContentPanel = NULL;
    m_HeaderStaticBitmap = NULL;
    m_AppNameStaticText = NULL;
    m_CopyrightStaticText = NULL;
    m_VersionStaticText = NULL;
    m_BuildInfoStaticText = NULL;
////@end AboutBoxDialog member initialisation
}

/*!
 * AboutBoxDialog creator
 */

bool AboutBoxDialog::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin AboutBoxDialog creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end AboutBoxDialog creation
    return true;
}

/*!
 * Control creation for AboutBoxDialog
 */

void AboutBoxDialog::CreateControls()
{
////@begin AboutBoxDialog content construction
    AboutBoxDialog* itemDialog1 = this;

    // The basic idea behind a box sizer is that windows will most often be laid out in rather simple basic
    // geometry, typically in a row or a column or several hierarchies of either.
    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    // A panel is a window on which controls are placed. It is usually placed within a frame. It contains
    // minimal extra functionality over and above its parent class wxWindow; its main purpose is to be similar
    // in appearance and functionality to a dialog, but with the flexibility of having any window as a parent.
    m_ContentPanel = new wxPanel( itemDialog1, ID_ContentPanel, wxDefaultPosition, wxSize(300, 300), wxNO_BORDER|wxTAB_TRAVERSAL );
    m_ContentPanel->SetBackgroundColour(wxColour(255, 255, 255));
    itemBoxSizer2->Add(m_ContentPanel, 0, wxGROW, 0);

    // The basic idea behind a box sizer is that windows will most often be laid out in rather simple basic
    // geometry, typically in a row or a column or several hierarchies of either.
    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxVERTICAL);
    m_ContentPanel->SetSizer(itemBoxSizer4);

    // A static bitmap control displays a bitmap. It is meant for display of the small icons in the dialog
    // boxes and is not meant to be a general purpose image display control. In particular, under Windows 9x
    // the size of bitmap is limited to 64*64 pixels and thus you should use your own control if you want to
    // display larger images portably.
    //m_HeaderStaticBitmap = new wxStaticBitmap( m_ContentPanel, wxID_STATIC, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
    //itemBoxSizer4->Add(m_HeaderStaticBitmap, 0, wxGROW, 0);
    //wxImage hdrImage = wxImage( _T( "about.jpg" ), wxBITMAP_TYPE_JPEG);
    wxMemoryInputStream istream(logo_png, sizeof logo_png);
    wxImage hdrImage = wxImage(istream, wxBITMAP_TYPE_PNG);

    //(void*) new wxStaticBitmap(this, -1, wxBitmap( hdrImage ), wxPoint(0,0));
    m_HeaderStaticBitmap = new wxStaticBitmap( m_ContentPanel, wxID_STATIC, wxBitmap( hdrImage ), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer4->Add(m_HeaderStaticBitmap, 0, wxGROW, 0);

    // A wxSizer that can lay out items in a virtual grid like a wxFlexGridSizer but in this case explicit
    // positioning of the items is allowed using wxGBPosition, and items can optionally span more than one
    // row and/or column using wxGBSpan.
    wxGridBagSizer* itemGridBagSizer6 = new wxGridBagSizer(0, 0);
    itemGridBagSizer6->AddGrowableRow(2);
    itemGridBagSizer6->AddGrowableRow(3);
    itemGridBagSizer6->SetEmptyCellSize(wxSize(10, 20));
    itemBoxSizer4->Add(itemGridBagSizer6, 0, wxGROW|wxLEFT|wxRIGHT|wxBOTTOM, 10);

    // A static text control displays one or more lines of read-only text.
    // Application Name
    m_AppNameStaticText = new wxStaticText( m_ContentPanel, wxID_STATIC, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    m_AppNameStaticText->SetForegroundColour(wxColour(0, 0, 255));
    m_AppNameStaticText->SetFont(wxFont(18, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Arial Narrow")));
    itemGridBagSizer6->Add(m_AppNameStaticText, wxGBPosition(0, 0), wxGBSpan(1, 2), wxALIGN_LEFT|wxALIGN_BOTTOM|wxLEFT|wxRIGHT|wxTOP, 5);

    // A static text control displays one or more lines of read-only text.
    // Version TEXT
    wxStaticText* itemStaticText8 = new wxStaticText( m_ContentPanel, wxID_STATIC, _("version"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStaticText8->SetForegroundColour(wxColour(192, 192, 192));
    itemStaticText8->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Arial")));
    itemGridBagSizer6->Add(itemStaticText8, wxGBPosition(1, 0), wxGBSpan(1, 1), wxALIGN_RIGHT|wxALIGN_TOP|wxLEFT|wxBOTTOM, 5);

    // A static text control displays one or more lines of read-only text.
    // Version Number
    m_VersionStaticText = new wxStaticText( m_ContentPanel, wxID_STATIC, _T(""), wxDefaultPosition, wxDefaultSize, 0 );
    m_VersionStaticText->SetForegroundColour(wxColour(192, 192, 192));
    m_VersionStaticText->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Arial")));
    itemGridBagSizer6->Add(m_VersionStaticText, wxGBPosition(1, 1), wxGBSpan(1, 1), wxALIGN_LEFT|wxALIGN_TOP|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    // A static text control displays one or more lines of read-only text.
    // Copyright
    m_CopyrightStaticText = new wxStaticText( m_ContentPanel, wxID_STATIC, _T(""), wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE );
    itemGridBagSizer6->Add(m_CopyrightStaticText, wxGBPosition(2, 0), wxGBSpan(1, 2), wxGROW|wxGROW|wxALL, 5);

    // A static text control displays one or more lines of read-only text.
    // Build Information
    m_BuildInfoStaticText = new wxStaticText( m_ContentPanel, wxID_STATIC, _T(""), wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE );
    itemGridBagSizer6->Add(m_BuildInfoStaticText, wxGBPosition(3, 0), wxGBSpan(1, 2), wxGROW|wxGROW|wxALL, 5);

    // ----------------------------
    itemBoxSizer4->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    // A static line is just a line which may be used in a dialog to separate the groups of controls. The line may be only vertical or horizontal.
    wxStaticLine* itemStaticLine13 = new wxStaticLine( itemDialog1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer2->Add(itemStaticLine13, 0, wxGROW, 0);

    // This class creates button layouts which conform to the standard button spacing and ordering defined by the
    // platform or toolkit's user interface guidelines (if such things exist). By using this class, you can ensure
    // that all your standard dialogs look correct on all major platforms. Currently it conforms to the Windows,
    // GTK+ and Mac OS X human interface guidelines.
    wxStdDialogButtonSizer* itemStdDialogButtonSizer14 = new wxStdDialogButtonSizer;

    // A button is a control that contains a text string, and is one of the most common elements of a GUI. It may be placed on a dialog box or panel,
    // or indeed almost any other window.
    itemBoxSizer2->Add(itemStdDialogButtonSizer14, 0, wxALIGN_RIGHT|wxALL, 5);
    wxButton* itemButton15 = new wxButton( itemDialog1, wxID_OK, _("&OK"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer14->AddButton(itemButton15);

    itemStdDialogButtonSizer14->Realize();

////@end AboutBoxDialog content construction
    m_BuildInfoStaticText->SetLabel(AboutBoxDialog::GetBuildInfo(wxBUILDINFO_LONG));
}

/*!
 * Get bitmap resources
 */

wxBitmap AboutBoxDialog::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin AboutBoxDialog bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end AboutBoxDialog bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon AboutBoxDialog::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin AboutBoxDialog icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end AboutBoxDialog icon retrieval
}

wxString AboutBoxDialog::GetBuildInfo(wxBuildInfoFormat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == wxBUILDINFO_LONG)
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T(" (Unicode");
#else
        wxbuild << _T(" (ANSI");
#endif // wxUSE_UNICODE
    }
	wxbuild << _(" build)");
    return wxbuild;
}

void AboutBoxDialog::ApplyInfo()
{
	SetTitle(wxString::Format(wxT("%s %s"), _("About"), m_AppName.GetData()));
    m_AppNameStaticText->SetLabel(m_AppName);
    m_VersionStaticText->SetLabel(m_Version);
    m_CopyrightStaticText->SetLabel(m_Copyright);
	wxString buildInfo;
	if(m_CustomBuildInfo.IsEmpty())
	{
		buildInfo = AboutBoxDialog::GetBuildInfo(wxBUILDINFO_LONG);
	}
	else
	{
		buildInfo = m_CustomBuildInfo;
	}
	m_BuildInfoStaticText->SetLabel(buildInfo);
	int labelWidth = m_HeaderStaticBitmap->GetSize().GetWidth() - 20;
	m_VersionStaticText->Wrap(labelWidth);
	m_CopyrightStaticText->Wrap(labelWidth);
	m_BuildInfoStaticText->Wrap(labelWidth);
	m_ContentPanel->Layout();
	m_ContentPanel->GetSizer()->Fit(m_ContentPanel);
    GetSizer()->Fit(this);
	Centre();
}
