#include "mapChart.h"

BEGIN_EVENT_TABLE(mapChart, wxPanel)

EVT_MOTION(mapChart::mouseMoved)
/*
 EVT_LEFT_DOWN(mapChart::mouseDown)
 EVT_LEFT_UP(mapChart::mouseReleased)
 EVT_RIGHT_DOWN(mapChart::rightClick)
 EVT_LEAVE_WINDOW(mapChart::mouseLeftWindow)
 EVT_KEY_DOWN(mapChart::keyPressed)
 EVT_KEY_UP(mapChart::keyReleased)
 EVT_MOUSEWHEEL(mapChart::mouseWheelMoved)
 */

// Catch paint events
EVT_PAINT(mapChart::paintEvent)

// Catch resize events
EVT_SIZE (mapChart::OnResize)

END_EVENT_TABLE()

/*
 void simpleChart::mouseMoved(wxMouseEvent& event) {}
 void simpleChart::mouseDown(wxMouseEvent& event) {}
 void simpleChart::mouseWheelMoved(wxMouseEvent& event) {}
 void simpleChart::mouseReleased(wxMouseEvent& event) {}
 void simpleChart::rightClick(wxMouseEvent& event) {}
 void simpleChart::mouseLeftWindow(wxMouseEvent& event) {}
 void simpleChart::keyPressed(wxKeyEvent& event) {}
 void simpleChart::keyReleased(wxKeyEvent& event) {}
 */

mapChart::mapChart(wxWindow* parent) : wxPanel(parent)
{
}

void mapChart::paintEvent(wxPaintEvent & evt)
{
    wxPaintDC dc(this);
    render(dc);
}

void mapChart::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}

void mapChart::render(wxDC& dc)
{
    cnt++;

    /// Get canvas size
    dc.GetSize( &width, &height );

    /// Set grid
    if (grid_enabled)
    {
        dc.SetPen( wxPen( wxColor(0x90,0x90,0x90), 1 ) ); // gray line, 1 pixels thick

        for (int x=0; x < width;x+=(int)zoom_x)
            dc.DrawLine( x, 0, x, height-(SUMMARYBAR_HEIGHT+PAD_HEIGHT)); // draw line verticle the rectangle

        //for (int x=0; x < height;x+=grid_size)
            //dc.DrawLine( 0, x, width, x ); // draw line across the rectangle
    }

    /// Print summary bar
    unsigned int summary_factor=summarybar_buffer_length / width;
    int x_pos=0;
    for (unsigned int x=0; x < summarybar_buffer_length; x+=summary_factor)
    {
        if (summarybar_buffer[x]==0xFF)
            dc.SetPen(wxPen(wxColor(0xFF,0xFF,0xFF), 1)); // blue line, 1 pixels thick
        else
            dc.SetPen(wxPen(wxColor(0,0,0xFF), 1)); // blue line, 1 pixels thick

        if ((x > (current_start_address - summary_factor)) && (x < (current_start_address + summary_factor)))
            dc.SetPen(wxPen(wxColor(0xFF,0,0), 1)); // blue line, 1 pixels thick

        dc.DrawLine(x_pos, height, x_pos, height-SUMMARYBAR_HEIGHT);
        x_pos++;
    }

    /// Print map data
    double max_y;
    if (map_bits==8)
        max_y=255;
    else if (map_bits==16)
        max_y=65535;
    else
        max_y=4294967295;

    double factor=((double)height-(double)SUMMARYBAR_HEIGHT) / max_y;

    unsigned int old_y=map_data[0] * factor, new_y, old_x=0;

    unsigned int map_index=0;

    dc.SetPen( wxPen( wxColor(0,0,0xFF), 1 ) ); // blue line, 1 pixels thick
    for (int x=0; x < width; x+=(int)zoom_x)
    {
        new_y=map_data[map_index++] * factor;
        if (x) dc.DrawLine(old_x, height-(old_y+SUMMARYBAR_HEIGHT+PAD_HEIGHT), x, height-(new_y+SUMMARYBAR_HEIGHT+PAD_HEIGHT));
        old_y=new_y;
        old_x=x;
    }

    /// Show current mouse position
    dc.SetPen( wxPen( wxColor(0,0,0), 1 ) ); // black line, 1 pixels thick
    dc.DrawLine( mouse_x, 0, mouse_x, height );

    /// Print current mouse co-ordinates
#ifdef DEBUG
    wxString mouse_pos = wxString::Format(wxT("%i"),mouse_x) +
                         wxT(" x ") +
                         wxString::Format(wxT("%i"),mouse_y);

    wxSize sz = dc.GetTextExtent(mouse_pos);
    dc.DrawText(mouse_pos, 10, 10);
#endif
}

void mapChart::OnResize(wxSizeEvent& evt)
{
    Refresh();
    evt.Skip();
}

void mapChart::mouseMoved(wxMouseEvent & evt)
{
    evt.GetPosition(&mouse_x,&mouse_y);

    //if (!((double)mouse_x ^ (double)zoom_x))

    Refresh();
    evt.Skip();
}

void mapChart::Init(void)
{
    grid_enabled=true;
    zoom_x=2;
    prev_width=0;
    cnt=0;

    map_data = new double[2000];
}

void mapChart::SetSummaryBar(unsigned char *buffer, unsigned int buffer_length)
{
    // Allocate buffer
    //void *tmp_buffer = realloc(summarybar_buffer, (size_t)buffer_length);
    //if (!tmp_buffer)
        //return;

    //summarybar_buffer=(unsigned char *)tmp_buffer;
    //if (summarybar_buffer != NULL) free (summarybar_buffer);
    summarybar_buffer=(unsigned char*)malloc(buffer_length);

    for(unsigned int x=0; x < buffer_length; x++)
        summarybar_buffer[x]=buffer[x];

    summarybar_buffer_length=buffer_length;
}

void mapChart::SetView(unsigned char *buffer0, unsigned int buffer0_length,
                       unsigned char *buffer1, unsigned int buffer1_length,
                       unsigned char *buffer2, unsigned int buffer2_length,
                       unsigned int address0, unsigned int address1, unsigned int address2,
                       bool visible0, bool visible1, bool visible2, unsigned short bits, bool order, bool sign)
{
    current_start_address=address0;
    map_bits = bits;

    for (unsigned int x=0; x < 2000; x++)
    {
        map_data[x]=GetRawValueFromAddress(buffer0, address0, bits, order, sign);
        address0+=2;
    }
}

void mapChart::SetZoom(unsigned int x, unsigned int y, bool automatic)
{
    zoom_x=x;
}

void mapChart::SetGrid(bool g_enabled)
{
    grid_enabled=g_enabled;
}

int mapChart::GetWidth(void)
{
    return (width);
}

int mapChart::GetRawValueFromAddress(unsigned char *buffer, unsigned int address, unsigned short bits, bool order, bool sign)
{
    unsigned int unsigned_raw_value=0;
    int signed_raw_value=0;

    if (bits==8)
        unsigned_raw_value=buffer[address];
    else if ((bits==16) && (order))
        unsigned_raw_value=((unsigned int)buffer[address+1] << 8) + (unsigned int)buffer[address];
    else if ((bits==16) && (!order))
        unsigned_raw_value=((unsigned int)buffer[address] << 8) + (unsigned int)buffer[address+1];
    else if ((bits==32) && (order))
    {
        unsigned_raw_value=((unsigned int)buffer[address+3] << 24) +
                           ((unsigned int)buffer[address+2] << 16) +
                           ((unsigned int)buffer[address+1] << 8) +
                           (unsigned int)buffer[address];
    }
    else if ((bits==32) && (!order))
    {
        unsigned_raw_value=((unsigned int)buffer[address] << 24) +
                           ((unsigned int)buffer[address+1] << 16) +
                           ((unsigned int)buffer[address+2] << 8) +
                           (unsigned int)buffer[address+3];
    }

    if (sign)
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

        return(signed_raw_value);
    }

    return ((int)unsigned_raw_value);
}
