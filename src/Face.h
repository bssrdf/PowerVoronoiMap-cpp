#ifndef VORONOI_FACE
#define VORONOI_FACE
#include "CoflictList.h"
#incldue "Point2D.h"
#include <string>
/**
 * Facet class connected over double-linked edge list. Contains incident vertices and edges.
 * Adapted from ArlindNocaj java version of voronoi library
 *
 * @author Jianye Xia at Chalmers University of Technology
 */
namespace voronoi{
class Face{
    public:
        Face(Vertex& a,Vertex& b,Vertex& c);
        Face(Vertex& a,Vertex& b,Vertex& c,Vertex& orient);
        
        inline int              getIndex()                  {return index_;}
        inline void             setIndex(int index)         {index_=index;}
        inline ConflictList&    getList()                   {return list_;}
        inline void             setList(ConflictList& list) {list_=&list;}
        inline Vertex&          getVertex(int i)            {return v_[i];}

        inline bool             isVisibleFromBelow()        {return (normal_.z<1.4259414393190911e-9);}
        inline bool             isMarked()                  {return marked_;}
        inline bool             behind(const Vertex& p)     { return (normal_.dot(p)<normal_.dot(v_[0]));}
        inline bool             conflict(const Vertex& p)   {return (normal_.dot(p)>(normal_.dot(v_[0])+epsilon_));}

        inline int              getEdgeCount()              {return 3;}   //TODO: need check!!
        inline int              getVertexCount()            {return 3;} //TODO: need check!!
        inline HullEdge&        getEdge(int i)              {return e_[i];}
        inline Vector&          getNormal()                 {return normal_;}
        inline void             setNormal(Vector& normal)   {normal_=normal;}
        inline void             setMarked(bool marked)      {marked_=marked;}
        inline void             removeConflict()            {list_.clear();}  //TODO: check the exact function of list to be used!!

        void            orient(Vertex& orient);
        std::string     toString();
        void            link(Face& f0,Vertex& v0, Vertex& v1);
        void            link(HullEdge& e);
        HullEdge&       getEdge(const Vertex& v0,const Vertex& v1);
        Point2D&        getDualPoint();
        HullEdge&       getHorizon();
        
    private:
        static double epsilon_=1e-10;

        ConflictList*   list_;
        bool            marked_;
        Vertex&         v_[3];
        HullEdge&       e_[3];
        Vector*         normal_;
        int             index_; 

        Point2D         dualPoint_;
        
        void        createEdges();
};

}


#endif
