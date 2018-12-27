#include "simpleChart.h"
#include "TableEditorMain.h"

BEGIN_EVENT_TABLE(simpleChart, wxPanel)
/*
 EVT_MOTION(simpleChart::mouseMoved)
 EVT_LEFT_DOWN(simpleChart::mouseDown)
 EVT_LEFT_UP(simpleChart::mouseReleased)
 EVT_RIGHT_DOWN(simpleChart::rightClick)
 EVT_LEAVE_WINDOW(simpleChart::mouseLeftWindow)
 EVT_KEY_DOWN(simpleChart::keyPressed)
 EVT_KEY_UP(simpleChart::keyReleased)
 EVT_MOUSEWHEEL(simpleChart::mouseWheelMoved)
 */

// Catch paint events
EVT_PAINT(simpleChart::paintEvent)

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

simpleChart::simpleChart(wxWindow* parent) : wxPanel(parent)
{
}

void simpleChart::paintEvent(wxPaintEvent & evt)
{
    wxPaintDC dc(this);
    render(dc);
}

void simpleChart::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}

void simpleChart::render(wxDC& dc)
{
    // Exit if no data has been supplied
    if (data_size <= 1) return;

    // Get canvas size
    int canvas_width, canvas_height;
    dc.GetSize( &canvas_width, &canvas_height );

    // Get min/max values from data
    double min=2147483647, max=-2147483647;

    for (int x=0; x < data_size; x++)
    {
        if (axis_data[x] > max)
            max=axis_data[x];

        if (axis_data[x] < min)
            min=axis_data[x];
    }

    // If all values are equal just show a line on center
    if (min==max)
    {
        dc.SetPen(wxPen(wxColor(0,0,255), 2));
        dc.DrawLine(0, canvas_height/2, canvas_width, canvas_height/2);

        return;
    }

    // Get information necessary for plotting
    double x_pixels_per_unit=(double)canvas_width / (double)(data_size-1);
    double y_pixels_per_unit=(max-min) / (double)canvas_height;

    // Init. plot variables
    double old_y=(axis_data[0] - min) / y_pixels_per_unit;
    int old_x=0, x=0;

    // Draw the grid
    for (int count=0; count < data_size; count++)
    {
        int y=(int)((axis_data[count] - min) / y_pixels_per_unit);
        if (y >= canvas_height)
            y=canvas_height-1;

        dc.SetPen(wxPen(wxColor(0x90,0x90,0x90), 1));
        dc.DrawLine(x, 0, x, canvas_height);
        dc.DrawLine(0, canvas_height-y, canvas_width, canvas_height-y);
        x=(int)((double)(count+1) * x_pixels_per_unit);
    }

    // Draw the data
    old_x=0;
    x=0;
    for (int count=0; count < data_size; count++)
    {
        int y=(int)((axis_data[count] - min) / y_pixels_per_unit);
        if (y >= canvas_height)
            y=canvas_height-1;

        dc.SetPen(wxPen(wxColor(0,0,255), 2));
        dc.DrawLine(old_x, canvas_height-old_y, x, canvas_height-y);
        old_x=x;
        old_y=y;
        x=(int)((double)(count+1) * x_pixels_per_unit);
    }

    // Draw the circle on current point
    x=(int)((double)current_pos * x_pixels_per_unit);
    int y=(int)((axis_data[current_pos] - min) / y_pixels_per_unit);
    if (y >= canvas_height)
        y=canvas_height-1;

    dc.SetBrush(*wxRED_BRUSH);
    dc.SetPen(wxPen(wxColor(255,0,0),1));
    dc.DrawCircle(wxPoint(x,canvas_height-y), 5);
}

void simpleChart::Init(int size)
{
    data_size=size;
    axis_data = new double[size];
    current_pos=0;
}
