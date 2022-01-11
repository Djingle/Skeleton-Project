#ifndef TP1_EX5_TOOLS_H
#define TP1_EX5_TOOLS_H

#include <pmp/visualization/MeshViewer.h>

class TP1_Ex5_MeshViewer : public pmp::MeshViewer
{
public:
    TP1_Ex5_MeshViewer(const char* title,
                       int width, int height,
                       /* ! STUDENTS TODO ! */
                       // Fill if required
                       bool showgui=true);

    void process_imgui();

private:
    /* ! STUDENTS TODO ! */
    // Fill if required
};

#endif // TP1_EX5_TOOLS_H