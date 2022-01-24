#ifndef TP3_EX2_TOOLS_H
#define TP3_EX2_TOOLS_H

#include <pmp/visualization/MeshViewer.h>
#include <pmp/algorithms/SurfaceSmoothing.h>

class TP3_Ex2_ExplicitLaplacianSmoothing : public pmp::SurfaceSmoothing
{
public:
    TP3_Ex2_ExplicitLaplacianSmoothing(pmp::SurfaceMesh& mesh) : pmp::SurfaceSmoothing(mesh)
    {
        // Nothing to do
    }

    void explicit_smoothing(unsigned int    iters,
                            float           lambda,
                            bool            use_uniform_laplace=false)
    {
        if( !mesh_.n_vertices() )
        {
            return;
        }

        // compute Laplace weight per edge: cotan or uniform
        if (!mesh_.has_edge_property("e:cotan") ||
            how_many_edge_weights_ != mesh_.n_edges())
            {compute_edge_weights(use_uniform_laplace);}
            

        auto points = mesh_.get_vertex_property<pmp::Point>("v:point");
        auto eweight = mesh_.get_edge_property<pmp::Scalar>("e:cotan");
        auto laplace = mesh_.add_vertex_property<pmp::Point>("v:laplace");

        // smoothing iterations
        pmp::Vertex vv;
        pmp::Edge e;
        for (unsigned int i = 0; i < iters; ++i)
        {
            // step 1: compute Laplace for each vertex
            for (auto v : mesh_.vertices())
            {
                pmp::Point l(0, 0, 0);

                if (!mesh_.is_boundary(v))
                {
                    pmp::Scalar w(0);

                    for (auto h : mesh_.halfedges(v))
                    {
                        vv = mesh_.to_vertex(h);
                        e = mesh_.edge(h);
                        l += eweight[e] * (points[vv] - points[v]);
                        w += eweight[e];
                    }

                    l /= w;
                }

                laplace[v] = l;
            }

            // step 2: move each vertex by its (damped) Laplacian
            for (auto v : mesh_.vertices())
            {
                points[v] += lambda * laplace[v];
            }
        }

        // clean-up custom properties
        mesh_.remove_vertex_property(laplace);
    }
};

class TP3_Ex2_MeshViewer : public pmp::MeshViewer
{
public:
    TP3_Ex2_MeshViewer(const char* title,
                       int width, int height,
                       pmp::SurfaceMeshGL& mesh,
                       bool showgui=true);

    void process_imgui();

private:
    int         nIter_{5};
    pmp::Scalar lambda_{0.5};
    pmp::Scalar mu_{0.6};
};

#endif // TP3_EX2_TOOLS_H