#ifndef CWINDOW_H
#define CWINDOW_H

#include <gtk/gtk.h>

class CWindow;

#define CB(f) G_CALLBACK(f##CB)

#define CMAP1(C, R, func, T) \
static R func##CB(T param, C data) \
{ \
    return (data)->func(param); \
} \
R func(T param); \

#define CMAP2(C, R, func, T, TT) \
static R func##CB(T param1, TT param2, C data) \
{ \
    return (data)->func(param1, param2); \
} \
R func(T param1, TT param2); \

#define CWINDOWOBJECT "CWindowObject"

inline void setWindowObject(GtkWidget *wnd, void *data)
{
    g_object_set_data(G_OBJECT(wnd), CWINDOWOBJECT, data);
}

inline void* getWindowObject(GtkWidget *wnd)
{
    return (void*) g_object_get_data(G_OBJECT(wnd), CWINDOWOBJECT);
}

GtkWidget* menuCreateSub(GtkWidget *parent, const char *label);
GtkWidget* menuAppendItem(GtkWidget *parent, const char *label,
                          GCallback func, CWindow *wnd);
GtkToolItem* toolbarAppendItem(GtkWidget *parent, const char *name,
                               GCallback func, CWindow *wnd);
void toolbarAppendSeparator(GtkWidget *parent);
void notebookAppend(GtkWidget *notebook, const char *title, GtkWidget *page,
                    GCallback func, CWindow *wnd);

bool isLastWindow(CWindow *wnd);

class CWindow
{
public:

    CWindow();
    virtual ~CWindow();

    void showAll();

protected:

    GtkWidget *_wnd = nullptr;
    GtkWidget *_toolbar = nullptr;
    GtkWidget *_grid = nullptr;
    int _gridrow = 0;
    GtkWidget *_statusbar = nullptr;

};

#endif // CWINDOW_H


