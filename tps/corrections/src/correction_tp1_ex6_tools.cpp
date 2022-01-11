#include "../include/correction_tp1_ex6_tools.h"

#include <random>

#include <imgui.h>

TP1_Ex6_MeshViewer::TP1_Ex6_MeshViewer(const char* title,
                                        int width, int height,
                                        pmp::SurfaceMeshGL& mesh,
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

void TP1_Ex6_MeshViewer::process_imgui()
{
    pmp::MeshViewer::process_imgui();
    
    if( ImGui::Button("Color vertices per valence") )
    {
        colorVerticesPerValence(mesh_);
        update_mesh();
    }

    if( ImGui::Button("Color faces per area") )
    {
        colorFacesPerArea(mesh_);
        update_mesh();
    }
}

void colorVerticesPerValence(pmp::SurfaceMeshGL &mesh)
{
    auto valences = mesh.add_vertex_property<size_t>("v:valence");
    for( auto v : mesh.vertices() )
    {
        valences[v] = mesh.valence(v);
    }
    vertex_valence_to_color(mesh);
}

void vertex_valence_to_color(pmp::SurfaceMeshGL &mesh)
{
    auto valences = mesh.get_vertex_property<size_t>("v:valence");
    assert(valences);

    // sort valances values
    std::vector<size_t> values;
    values.reserve(mesh.n_vertices());
    for (auto v : mesh.vertices())
    {
        values.push_back(valences[v]);
    }
    std::sort(values.begin(), values.end());

    size_t vmin = values.front();
    size_t vmax = values.back();

    // Convert to colors
    float hue;
    float sat = 1;
    float val = 1;
    float r, g, b;
    auto fcolors = mesh.vertex_property<pmp::Color>("v:color");
    for( auto v : mesh.vertices() )
    {
        // min = 0 degres, max = 270 degres = 2/3
        hue = (2.0/3.0) * ( 1 - ((valences[v] - vmin)  / (vmax - vmin)));
        ImGui::ColorConvertHSVtoRGB(hue, sat, val, r, g, b);
        fcolors[v] = pmp::Color(r, g, b);
    }
}

void colorFacesPerArea(pmp::SurfaceMeshGL &mesh)
{
    auto area = mesh.add_face_property<float>("f:area");
    for( auto f : mesh.faces() )
    {
        // Get half edge and next
        pmp::Halfedge he1 = mesh.halfedge(f);
        pmp::Halfedge he2 = mesh.next_halfedge(he1);

        // Area is 0.5 times norm of the cross product
        pmp::vec3 v1 = mesh.position( mesh.to_vertex(he1) ) - mesh.position( mesh.from_vertex(he1) );
        pmp::vec3 v2 = mesh.position( mesh.to_vertex(he2) ) - mesh.position( mesh.from_vertex(he2) );
        pmp::vec3 cross = pmp::cross(v1, v2);
        area[f] = 0.5 * pmp::norm(cross);
    }
    face_area_to_color(mesh);
}

void face_area_to_color(pmp::SurfaceMeshGL &mesh)
{
    auto areas = mesh.get_face_property<float>("f:area");
    assert(areas);

    // sort valances values
    std::vector<float> values;
    values.reserve(mesh.n_faces());
    for( auto f : mesh.faces() )
    {
        values.push_back(areas[f]);
    }
    std::sort(values.begin(), values.end());

    float amin = values.front();
    float amax = values.back();

    // Convert to colors
    float h;
    float s = 1;
    float v = 1;
    float r, g, b;
    auto fcolors = mesh.face_property<pmp::Color>("f:color");
    for( auto f : mesh.faces() )
    {
        // min = 0 degres, max = 270 degres = 2/3
        h = (2.0/3.0) * ( 1 - ((areas[f] - amin))  / (amax - amin));
        ImGui::ColorConvertHSVtoRGB(h, s, v, r, g, b);
        fcolors[f] = pmp::Color(r, g, b);
    }
}