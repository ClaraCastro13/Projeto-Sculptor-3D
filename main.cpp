#include "voxel.h"
#include "escultor3d.h"
#include <iostream>

using namespace std;

int main(void) {
  Escultor3d Abelha(28,18,38);
  
  //Corpo parte amarela
  Abelha.setColor(1,1,0,1);
  Abelha.putBox(4,24,4,18,12,26);
  
  //Corpo listras marrom
  Abelha.setColor(0.224,0.145,0.071,1);
  Abelha.putBox(11,13,4,18,12,26);
  Abelha.putBox(15,17,4,18,12,26);
  Abelha.putBox(19,24,4,18,12,26);
  
  //Perninhas abelha
  Abelha.setColor(0,0,0,1);
  Abelha.putBox(9,11,2,4,14,16);
  Abelha.putBox(13,15,2,4,14,16);
  Abelha.putBox(17,19,2,4,14,16);
  Abelha.putBox(9,11,2,4,22,24);
  Abelha.putBox(13,15,2,4,22,24);
  Abelha.putBox(17,19,2,4,22,24);
  
  //Antenas abelha
  Abelha.setColor(0,0,0,1);
  Abelha.putBox(0,2,16,18,22,24);
  Abelha.putBox(0,2,16,18,14,16);
  Abelha.putBox(2,4,14,16,22,24);
  Abelha.putBox(2,4,14,16,14,16);
  
  //Olhos abelha (Parte preta)
  Abelha.setColor(0,0,0,1);
  Abelha.putBox(4,6,6,12,12,16);
  Abelha.putBox(4,6,6,12,22,26);
  
  //Olhos abelha (Parte branca)
  Abelha.setColor(1,1,1,1);
  Abelha.putBox(4,6,8,12,14,16);
  Abelha.putBox(4,6,8,12,22,24);
  
  //Partezinha das costas
  Abelha.setColor(0.224,0.145,0.071,1);
  Abelha.putBox(9,11,17,18,16,18);
  Abelha.putBox(9,11,17,18,20,22);
  Abelha.putBox(7,9,17,18,14,16);
  Abelha.putBox(7,9,17,18,22,24);
  
  //Asas (Parte branca)
  Abelha.setColor(1,1,1,0.9);
  Abelha.putBox(10,20,14,16,0,12);
  Abelha.putBox(10,20,14,16,26,38);
  Abelha.putBox(20,22,14,16,2,10);
  Abelha.putBox(20,22,14,16,28,36);
  
  //Asas (Corte para área transparente)
  Abelha.cutBox(10,12,14,16,0,10);
  Abelha.cutBox(10,12,14,16,28,38);
  Abelha.cutBox(12,14,14,16,0,4);
  Abelha.cutBox(12,14,14,16,34,38);
  Abelha.cutBox(14,16,14,16,0,2);
  Abelha.cutBox(14,16,14,16,36,38);
  Abelha.cutBox(12,18,14,16,10,12);
  Abelha.cutBox(12,18,14,16,26,28);
  Abelha.cutBox(14,16,14,16,4,10);
  Abelha.cutBox(14,16,14,16,28,34);
  Abelha.cutBox(18,20,14,16,2,10);
  Abelha.cutBox(18,20,14,16,28,36);

  //Asas (Parte transparente)
  Abelha.setColor(1,1,1,0.1);
  Abelha.putBox(12,18,14,16,10,12);
  Abelha.putBox(12,18,14,16,26,28);
  Abelha.putBox(14,16,14,16,4,10);
  Abelha.putBox(14,16,14,16,28,34);
  Abelha.putBox(18,20,14,16,2,10);
  Abelha.putBox(18,20,14,16,28,36);
  
  //Ferrão
  Abelha.setColor(0,0,0,1);
  Abelha.putBox(24,27,9,11,18,20);
  
  Abelha.writeOFF((char*)"Escultor3d.off");
	return 0;
}