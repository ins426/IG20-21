#include "_cube.h"

_cube::_cube(float Size)
{
    Vertices.resize(8);

    Vertices[0]=_vertex3f(-Size/2,Size/2,Size/2);
    Vertices[1]=_vertex3f(Size/2,Size/2,Size/2);
    Vertices[2]=_vertex3f(-Size/2,-Size/2,Size/2);
    Vertices[3]=_vertex3f(Size/2,-Size/2,Size/2);

    Vertices[4]=_vertex3f(-Size/2,Size/2,-Size/2);
    Vertices[5]=_vertex3f(Size/2,Size/2,-Size/2);
    Vertices[6]=_vertex3f(-Size/2,-Size/2,-Size/2);
    Vertices[7]=_vertex3f(Size/2,-Size/2,-Size/2);

    Triangles.resize(12);

    //Front
    Triangles[0]=_vertex3ui(2,3,1);
    Triangles[1]=_vertex3ui(2,1,0);

    //Right
    Triangles[2]=_vertex3ui(3,7,5);
    Triangles[3]=_vertex3ui(3,5,1);

    //Bottom
    Triangles[4]=_vertex3ui(6,7,3);
    Triangles[5]=_vertex3ui(6,3,2);

    //Left
    Triangles[6]=_vertex3ui(6,2,0);
    Triangles[7]=_vertex3ui(6,0,4);

    //Top
    Triangles[8]=_vertex3ui(0,1,5);
    Triangles[9]=_vertex3ui(0,5,4);

    //Back
    Triangles[10]=_vertex3ui(7,6,4);
    Triangles[11]=_vertex3ui(7,4,5);

}
