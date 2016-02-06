#include "arac.h"
#include <math.h>
///////////////////////////////////////////////
//otomobil:siyah, tır:zeytin yeşili,kamyon:kırmızı, otobüs:gri, kamyonet:mavi
float renkDizi[5][3]={
	{0.f, 0.f, 0.f}, {0.462f, 0.725f, 0.f}, {1.f, 0.f, 0.f}, {0.412f, 0.412f, 0.412f}, {0.f, 0.f, 1.f}
};
///////////////////////////////////////////////


ARAC::ARAC(float sx,float sy,int tip,int vel,int yon,int y_id,int s_id,int h_id)
{
	(*this).solX=sx;
	(*this).solY=sy;
	(*this).a_tipi=tip;
	(*this).hiz=vel;
	(*this).yon=yon;
	(*this).yol_id=y_id;
	(*this).serit_id=s_id;
	(*this).hc_id=h_id;
	
}

void ARAC::AracCiz()
{
	if(a_tipi==0)
	{   //otomobil
		genislik=2.0;
		uzunluk=4.6;
		renk=0;
	}
	else if(a_tipi==1)
	{   //týr
		genislik=2.45;
		uzunluk=13.6;
		renk=1;
	}
	else if(a_tipi==2)
	{   //kamyon
		genislik=2.45;
		uzunluk=7.2;
		renk=2;
	}
	else if(a_tipi==3)
	{   //otobüs
		genislik=2.55;
		uzunluk=12.8;
		renk=3;
	}
	else if(a_tipi==4)
	{   //kamyonet
		genislik=2.0;
		uzunluk=4.0;
		renk=4;
	}
	//delay için
	else if(a_tipi==5)
	{
		genislik=0.f;
		uzunluk=0.f;
	}
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(renkDizi[renk][0],renkDizi[renk][1], renkDizi[renk][2]);
	if(yon==1)
	{
		glBegin(GL_POLYGON);
		glVertex2f(solX,solY);
		glVertex2f(solX+uzunluk,solY);
		glVertex2f(solX+uzunluk,solY+genislik);
		glVertex2f(solX,solY+genislik);
		glEnd();
	}
	if(yon==2)
	{
		glBegin(GL_POLYGON);
			glVertex2f(solX,solY);
			glVertex2f(solX-uzunluk,solY);
			glVertex2f(solX-uzunluk,solY-genislik);
			glVertex2f(solX,solY-genislik);
		glEnd();
	}
	if(yon==3)
	{
		glBegin(GL_POLYGON);
			glVertex2f(solX,solY);
			glVertex2f(solX,solY+uzunluk);
			glVertex2f(solX-genislik,solY+uzunluk);
			glVertex2f(solX-genislik,solY);
		glEnd();
	}
	if(yon==4)
	{
		glBegin(GL_POLYGON);
			glVertex2f(solX,solY);
			glVertex2f(solX,solY-uzunluk);
			glVertex2f(solX+genislik,solY-uzunluk);
			glVertex2f(solX+genislik,solY);
		glEnd();
	}
	if(yon==5)
	{
		
		glBegin(GL_POLYGON);
			glVertex2f(solX,solY);
			glVertex2f(solX-genislik*sqrt(2)/2,solY+genislik*sqrt(2)/2);
			glVertex2f(solX+uzunluk*sqrt(2)/2-genislik*sqrt(2)/2,solY+uzunluk*sqrt(2)/2+genislik*sqrt(2)/2);
			glVertex2f(solX+uzunluk*sqrt(2)/2,solY+uzunluk*sqrt(2)/2);
		glEnd();
	}
	if(yon==6)
	{
		glBegin(GL_POLYGON);
			glVertex2f(solX,solY);
			glVertex2f(solX+genislik*sqrt(2)/2,solY+genislik*sqrt(2)/2);
			glVertex2f(solX+uzunluk*sqrt(2)/2+genislik*sqrt(2)/2,solY-uzunluk*sqrt(2)/2+genislik*sqrt(2)/2);
			glVertex2f(solX+uzunluk*sqrt(2)/2,solY-uzunluk*sqrt(2)/2);
		glEnd();
	}
	if(yon==7)
	{
		glBegin(GL_POLYGON);
			glVertex2f(solX,solY);
			glVertex2f(solX+genislik*sqrt(2)/2,solY-genislik*sqrt(2)/2);
			glVertex2f(solX-uzunluk*sqrt(2)/2+genislik*sqrt(2)/2,solY-uzunluk*sqrt(2)/2-genislik*sqrt(2)/2);
			glVertex2f(solX-uzunluk*sqrt(2)/2,solY-uzunluk*sqrt(2)/2);
		glEnd();
	}
	if(yon==8)
	{
		glBegin(GL_POLYGON);
			glVertex2f(solX,solY);
			glVertex2f(solX-genislik*sqrt(2)/2,solY-genislik*sqrt(2)/2);
			glVertex2f(solX-uzunluk*sqrt(2)/2-genislik*sqrt(2)/2,solY+uzunluk*sqrt(2)/2-genislik*sqrt(2)/2);
			glVertex2f(solX-uzunluk*sqrt(2)/2,solY+uzunluk*sqrt(2)/2);
		glEnd();
	}
}
