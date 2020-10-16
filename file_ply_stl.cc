/*
* Prácticas de IG
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
*
* GPL 3
*/

#include "file_ply_stl.h"

using namespace std;

//******************************************************************************
//
//******************************************************************************

int _file_ply::open(const string &File_name)
{
  File.open(File_name.c_str(),ios::in);

  if (File.good()) return 1;
  else {
    cout << "Error: the file " << File_name << " cannot be opened" << endl;
    return 0;
  }
}

//******************************************************************************
//
//******************************************************************************

void _file_ply::get_token(istringstream &Line_stream1,string &Token1)
{
  getline(Line_stream1,Token1,' ');
}

//******************************************************************************
//
//******************************************************************************

bool _file_ply::get_new_line(ifstream &File,istringstream &Line_stream)
{
  string Line;
  if (getline(File,Line)){
    Line_stream.str(Line);
    Line_stream.seekg(0);
    return true;
  }
  else return false;
}


//******************************************************************************
//
//******************************************************************************

void _file_ply::read(vector<_vertex3f> &Coordinates, vector<_vertex3ui> &Positions)
{
  string Token;
  istringstream Line_stream;
  unsigned int Pos;

  setlocale(LC_ALL, "C");

  get_new_line(File,Line_stream);
  get_token(Line_stream,Token);
  if(Token=="ply"){
    get_new_line(File,Line_stream);
    get_token(Line_stream,Token);
    if(Token=="format"){
      get_token(Line_stream,Token);
      if(Token=="ascii"){
        do{
          get_new_line(File,Line_stream);
          get_token(Line_stream,Token);
        } while (Token!="element");
        get_token(Line_stream,Token);
        if(Token=="vertex"){
          get_token(Line_stream,Token);
          Coordinates.resize(stoi(Token));
          do{
            get_new_line(File,Line_stream);
            get_token(Line_stream,Token);
          } while (Token!="element");
          get_token(Line_stream,Token);
          if(Token=="face"){
            get_token(Line_stream,Token);
            Positions.resize(stoi(Token));
            do{
              get_new_line(File,Line_stream);
              get_token(Line_stream,Token);
            } while (Token!="end_header");
            Pos=0;
            for (unsigned int i=0;i<Coordinates.size();i++){
              get_new_line(File,Line_stream);
              //
              get_token(Line_stream,Token);
              Coordinates[i].x=stof(Token);
              get_token(Line_stream,Token);
              Coordinates[i].y=stof(Token);
              get_token(Line_stream,Token);
              Coordinates[i].z=stof(Token);
            }
            Pos=0;
            for (unsigned int i=0;i<Positions.size();i++){
              get_new_line(File,Line_stream);
              //
              get_token(Line_stream,Token);
              if (stoi(Token)==3){
                get_token(Line_stream,Token);
                Positions[i]._0=stoi(Token);
                get_token(Line_stream,Token);
                Positions[i]._1=stoi(Token);
                get_token(Line_stream,Token);
                Positions[i]._2=stoi(Token);
              }
            }
          }
          else{
            cerr << "Error: no face element found" << endl;
          }
        }
        else{
          cerr << "Error: no vertex element found" << endl;
        }
      }
      else{
        cerr << "Error: only ascii format is allowed" << endl;
      }
    }
    else{
      cerr << "Error: no format found" << endl;
    }
  }
  else{
    cerr << "Error: the file is not a PLY file" << endl;
  }
}

//******************************************************************************
//
//******************************************************************************

void _file_ply::close()
{
  File.close();
}

