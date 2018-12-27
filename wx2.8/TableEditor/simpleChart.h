#ifndef SIMPLECHART_H
#define SIMPLECHART_H

#include "wx/wx.h"
#include "wx/sizer.h"

class simpleChart : public wxPanel
{

public:
    simpleChart(wxWindow* parent);

    void paintEvent(wxPaintEvent & evt);
    void paintNow();
    void render(wxDC& dc);

    void Init(int size);

    double *axis_data;
    int current_pos;

private:

    // some useful events
    /*
     void mouseMoved(wxMouseEvent& event);
     void mouseDown(wxMouseEvent& event);
     void mouseWheelMoved(wxMouseEvent& event);
     void mouseReleased(wxMouseEvent& event);
     void rightClick(wxMouseEvent& event);
     void mouseLeftWindow(wxMouseEvent& event);
     void keyPressed(wxKeyEvent& event);
     void keyReleased(wxKeyEvent& event);
     */

    int data_size;

    DECLARE_EVENT_TABLE()
};
#endif
