//sculptor.cpp -> implementar a class Sculptor
#include "escultor3d.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

/**
*
*@brief Metodo construtor da classe Escultor3D
*
*/
Escultor3d::Escultor3d (int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;
    r = 0;
    g = 0;
    b = 0;
    a = 0;
  
  v = new voxel **[nx];
    for (int i = 0; i < nx; i++)
    {
     v[i] = new voxel *[ny];
      for (int j = 0; j < ny; j++)
      {
        v[i][j] = new voxel [nz];
      }
    }
} 
/**
*
*@brief Metodo Destrutor da classe Escultor3D
*
*/
Escultor3d::~Escultor3d() 
{
    for (int i = 0; i < nx; i++){
      for (int j = 0; j < ny; j++){
            delete [] v[i][j];
            }
          }
        for (int i = 0; i < nx; i++)
      {
        delete [] v[i];   
    }
    delete[] v;
    
    nx = 0;
    ny = 0;
    nz = 0;
}
/**
*
*@brief Metodo usado para inserir a cor no desenho
*@param float r, float g, float b, float a
*
*/
void Escultor3d::setColor(float r, float g, float b, float a)
{
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = a;
}
/**
*
*@brief Metodo usado para inserir um voxel
*@param int x, int y, int z
*
*/
void Escultor3d::putVoxel(int x, int y, int z)
{
    if(x < 0 || y < 0 || z < 0){
      x = 0;
      y = 0;
      z = 0;
    } 
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b =  b;
    v[x][y][z].a = a;
    v[x][y][z].isOn = true;  
}
/**
*
*@brief Metodo usado para cortar um voxel
*@param int x, int y, int z
*
*/
void Escultor3d::cutVoxel(int x, int y, int z)
{
    v[x][y][z].isOn = false; 
}
/**
*
*@brief Metodo usado para inserir um box (1 pixelzinho) *entre um ponto inicial (0) e um final (1)
*@param int x0, int x1, int y0, int y1, int z0, int z1
*
*/
void Escultor3d::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int i = x0; i < x1; i++) {
  		for (int j = y0; j < y1; j++) {
  			for (int k = z0; k < z1; k++) {
  				putVoxel(i, j, k);
  			}
  		}
  	}
}
/**
*
*@brief Metodo usado para cortar um box (1 pixelzinho) entre *um ponto inicial (0) e um final (1)
*@param int x0, int x1, int y0, int y1, int z0, int z1
*
*/
void Escultor3d::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int i = x0; i < x1; i++) {
  		for (int j = y0; j < y1; j++) {
  			for (int k = z0; k < z1; k++) {
  				cutVoxel(i, j, k);
  			}
  		}
  	}
}
/**
*
*@brief Metodo usado para inserir uma esfera, tendo como *base o raio da esfera
*@param int xcenter, int ycenter, int zcenter, int radius
*
*/
void Escultor3d::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for (int i = -radius; i <= radius; i++){
  		for (int j = -radius; j <= radius; j++){
  			for (int k = -radius; k <= radius; k++){
       
          if ((i * i + j * j + k * k) < (radius * radius)){
					  putVoxel(xcenter+i, ycenter+j, zcenter+k);
				  }
        }
      }
    }
} 
/**
*
*@brief Metodo usado para cortar parte esférica, tendo como *base o raio da esfera
*@param int xcenter, int ycenter, int zcenter, int radius
*
*/
void Escultor3d::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for (int i = -radius; i < radius; i++){
  		for (int j = -radius; j < radius; j++){
  			for (int k = -radius; k < radius; k++){
       
          if ((i * i + j * j + k * k) < (radius * radius)){
					  cutVoxel(xcenter+i, ycenter+j, zcenter+k);
				  }
        }
      }
    }
}
/**
*
*@brief Metodo usado para criar um arquivo com extensão ".off" onde ficará os dados do desenho
*@param const char* filename
*
*/
void Escultor3d::writeOFF(const char* filename)
{ 
    ofstream fout;
    fout.open(filename);
      if(!fout.is_open()){
        exit(1);
    }
    int Nvox = 0;
        for(int i = 0; i < nx; i++){
          for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
              if(v[i][j][k].isOn == true){
                Nvox++;
              }
            }
          }
        }
  fout << "OFF" << endl << Nvox * 8 << " " << Nvox * 6 << " " << 0 << endl; 
    for (int i = 0; i < nx; i++) { 
  		for (int j = 0; j < ny; j++) {
  			for (int k = 0; k < nz; k++) {
  				if (v[i][j][k].isOn) {
  					fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
  					fout << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
  					fout << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << endl;
  					fout << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << endl;
  					fout << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
  					fout << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
  					fout << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << endl;
  					fout << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << endl;
            }
          }
        }
      }
  int vert = 0;
	fout << setiosflags(ios::fixed); 

	for (int i = 0; i < nx; i++) { 
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (v[i][j][k].isOn) {
					fout << 4 << " " << vert + 0 << " " << vert + 3 << " " << vert + 2 << " " << vert + 1 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
					fout << 4 << " " << vert + 4 << " " << vert + 5 << " " << vert + 6 << " " << vert + 7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
					fout << 4 << " " << vert + 0 << " " << vert + 1 << " " << vert + 5 << " " << vert + 4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
					fout << 4 << " " << vert + 0 << " " << vert + 4 << " " << vert + 7 << " " << vert + 3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
					fout << 4 << " " << vert + 3 << " " << vert + 7 << " " << vert + 6 << " " << vert + 2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
					fout << 4 << " " << vert + 1 << " " << vert + 2 << " " << vert + 6 << " " << vert + 5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
					vert = vert + 8;
				}
			}
		}
	}
	fout.close();
}
