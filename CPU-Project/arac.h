#ifndef ARAC_H
#define ARAC_H

#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
using namespace std;


class ARAC{
	public:
	float solX,solY,genislik,uzunluk,yukseklik;
	int yon;
	int yol_id;
	int serit_id;
	int hiz;
	GLint renk;
	int a_tipi;//araç tipi:1-otomobil,2-tır,3-kamyon,4-kamyonet,5-otobüs
	int hc_id;
	//ARAC();//default constructor
	ARAC(float,float,int,int,int,int,int,int);//solX,solY,kategori,hýz,yon,yol_id,serit_id,hc_id
	void AracCiz();
	void Update(int);
	

};
#endif
