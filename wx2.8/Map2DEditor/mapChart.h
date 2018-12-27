#ifndef MAPCHART_H
#define MAPCHART_H

#include "wx/wx.h"
#include "wx/sizer.h"

#define DEBUG
#define SUMMARYBAR_HEIGHT   10
#define XBAR_HEIGHT         10
#define PAD_HEIGHT          2

class mapChart : public wxPanel
{

public:
    mapChart(wxWindow* parent);

    void paintEvent(wxPaintEvent & evt);
    void paintNow();
    void render(wxDC& dc);

    void Init(void);
    void SetSummaryBar(unsigned char *buffer, unsigned int buffer_length);
    void SetView(unsigned char *buffer0, unsigned int buffer0_length,
                 unsigned char *buffer1, unsigned int buffer1_length,
                 unsigned char *buffer2, unsigned int buffer2_length,
                 unsigned int address0, unsigned int address1, unsigned int address2,
                 bool visible0, bool visible1, bool visible2, unsigned short bits, bool order, bool sign);
    void SetZoom(unsigned int x, unsigned int y, bool automatic);
    void SetGrid(bool g_enabled);
    int GetWidth(void);
    int GetRawValueFromAddress(unsigned char *buffer, unsigned int address, unsigned short bits, bool order, bool sign);

    int cnt;

private:

    bool grid_enabled;
    long mouse_x, mouse_y;
    unsigned int zoom_x, summarybar_buffer_length, current_start_address;
    int width, height, prev_width;
    double *map_data;
    unsigned char *summarybar_buffer;
    unsigned short map_bits;

    // some useful events
    void mouseMoved(wxMouseEvent & evt);
    /*
     void mouseDown(wxMouseEvent& event);
     void mouseWheelMoved(wxMouseEvent& event);
     void mouseReleased(wxMouseEvent& event);
     void rightClick(wxMouseEvent& event);
     void mouseLeftWindow(wxMouseEvent& event);
     void keyPressed(wxKeyEvent& event);
     void keyReleased(wxKeyEvent& event);
     */
    void OnResize(wxSizeEvent& evt);

    DECLARE_EVENT_TABLE()
};
#endif
