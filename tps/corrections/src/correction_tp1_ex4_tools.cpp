#include "../include/correction_tp1_ex4_tools.h"

#include <random>

#include <imgui.h>

TP1_Ex4_MeshViewer::TP1_Ex4_MeshViewer(const char* title,
                                       int width, int height,
                                       bool showgui) : pmp::MeshViewer(title,
                                                                       width, height,
                                                                       showgui)
{
    // Nothing to do
}

TP1_Ex4_MeshViewer::TP1_Ex4_MeshViewer(const char* title,
                                        int width, int height,
                                        const pmp::SurfaceMeshGL& mesh,
                                        bool showgui) : pmp::MeshViewer(title,
                                                                        width, height,
                                                                        showgui)
{
    mesh_ = mesh;

    // Update scene center and bounds
    pmp::BoundingBox bb = mesh_.bounds();
    set_scene((pmp::vec3)bb.center(), 0.5 * bb.size());

    // Set draw mode
    if( mesh_.n_faces() == 0 )
    {
        set_draw_mode("Points");
    }
    else
    {
        set_draw_mode("Hidden Line");
    }

    // Compute face & vertex normals, update face indices
    update_mesh();

    // Set viewer angle parameter
    mesh_.set_crease_angle(crease_angle_);
}

void TP1_Ex4_MeshViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();

    if( ImGui::Button("Color in red") )
    {
        auto test = mesh_.vertex_property<pmp::Color>("v:color");
        mesh_.remove_vertex_property(test);
        colorMeshFaces(mesh_, pmp::Color(1.0, 0.0, 0.0));
        update_mesh();
    }

    if( ImGui::Button("Color in green") )
    {
        auto test = mesh_.vertex_property<pmp::Color>("v:color");
        mesh_.remove_vertex_property(test);
        colorMeshFaces(mesh_, pmp::Color(0.0, 1.0, 0.0));
        update_mesh();
    }

    if( ImGui::Button("Color vertices (random)") )
    {
        colorMeshVerticesRandomHue(mesh_);
        update_mesh();
    }
}

void HSVtoRGB(float& fR, float& fG, float& fB, float& fH, float& fS, float& fV)
{
    float fC = fV * fS; // Chroma
    float fHPrime = fmod(fH / 60.0, 6);
    float fX = fC * ( 1 - fabs(fmod(fHPrime, 2) - 1) );
    float fM = fV - fC;

    if( 0 <= fHPrime && fHPrime < 1 )
    {
        fR = fC;
        fG = fX;
        fB = 0;
    }
    else if( 1 <= fHPrime && fHPrime < 2 )
    {
        fR = fX;
        fG = fC;
        fB = 0;
    }
    else if( 2 <= fHPrime && fHPrime < 3 )
    {
        fR = 0;
        fG = fC;
        fB = fX;
    }
    else if( 3 <= fHPrime && fHPrime < 4 )
    {
        fR = 0;
        fG = fX;
        fB = fC;
    }
    else if( 4 <= fHPrime && fHPrime < 5 )
    {
        fR = fX;
        fG = 0;
        fB = fC;
    }
    else if( 5 <= fHPrime && fHPrime < 6 )
    {
        fR = fC;
        fG = 0;
        fB = fX;
    }
    else
    {
        fR = 0;
        fG = 0;
        fB = 0;
    }

    fR += fM;
    fG += fM;
    fB += fM;
}

void colorMeshFaces(pmp::SurfaceMesh& mesh,
                    const pmp::Color& color)
{
    auto fColor = mesh.face_property<pmp::Color>("f:color");
    for( auto f : mesh.faces() )
    {
        fColor[f] = color;
    }
}

void colorMeshVertices(pmp::SurfaceMesh& mesh,
                       const pmp::Color& color)
{
    auto vColor = mesh.vertex_property<pmp::Color>("v:color");
    for( auto v : mesh.vertices() )
    {
        vColor[v] = color;
    }
}

void colorMeshVerticesRandomHue(pmp::SurfaceMesh& mesh)
{
    std::random_device                      rd;
    std::default_random_engine              eng(rd());
    std::uniform_real_distribution<float>   distr(0.0f, 360.0f);
    
    auto vColor = mesh.vertex_property<pmp::Color>("v:color");
    for( auto v : mesh.vertices() )
    {
        // Random hue between 0 and 360
        float hue = distr(eng);

        // Convert from HSV to RGB
        float saturation    = 1.0f;
        float value         = 1.0f;
        float r             = 1.0f;
        float g             = 1.0f;
        float b             = 1.0f;
        HSVtoRGB(r, g, b, hue, saturation, value);

        vColor[v] = pmp::Color(r, g, b);
    }
}