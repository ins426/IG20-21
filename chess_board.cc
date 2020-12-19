#include "chess_board.h"

chess_board::chess_board()
{
    unsigned int divisions = 1;
    float size = 1.0;

    //Calculamos el número de divisiones
    Texture.resize((4*divisions)*divisions);
    Vertices.resize((4*divisions)*divisions);
    Triangles.resize(2*divisions*divisions);

    float u = 1.0/divisions;
    int index = 0;
    int triangles = 0;

    for(int i = 0; i < divisions;i++){
        for(int j = 0; j < divisions; j++){

            //(0,0)
            Texture[index] = _vertex2f(j*u,i*u);
            Vertices[index] = _vertex3f(-size/2+j*u,-size/2+i*u,0);

            //(1,0)
            Texture[(index+1)%Texture.size()] = _vertex2f((j+1)*u,i*u);
            Vertices[(index+1)%Texture.size()] = _vertex3f(-size/2+(j+1)*u,Vertices[index].y,0);

            //(0,1)
            Texture[(index+2)%Texture.size()] = _vertex2f(Texture[index].x,(i+1)*u);
            Vertices[(index+2)%Texture.size()] = _vertex3f(-size/2+j*u,-size/2+(i+1)*u,0);

            //(1,1)
            Texture[(index+3)%Texture.size()] = _vertex2f(Texture[index+1].x,Texture[index+2].y);
            Vertices[(index+3)%Texture.size()] = _vertex3f(-size/2+(j+1)*u,-size/2+(i+1)*u,0);

            Triangles[triangles] = _vertex3ui(index,index+1,index+2);
            Triangles[(triangles+1)%Triangles.size()] = _vertex3ui(index+1,index+3,index+2);
            index+=4;
            triangles+=2;

        }
    }
    calculateNormalTriangles();
    calculateNormalVertices();
}



