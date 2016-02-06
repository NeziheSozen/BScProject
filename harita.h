#include <GL/glut.h>
float  i,j,grid[180][92];
void Grid(void)
{   glLineWidth(1.f);
//Tekirdað-İstanbul yolu (bölünmüş yol)
	for(i=0;i<90;i++)
		for( j=47;j<49;j++)
		{
			
			glColor3f(0,0,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(i*7.5f,j*3.75f);
				glVertex2f((i*7.5f)+7.5,j*3.75);
				glVertex2f((i*7.5)+7.5, (j*3.75)+3.75);
				glVertex2f(i*7.5, (j*3.75)+3.75);
			glEnd();
			
		}
	//İstanbul-Tekirdağ yolu (bölünmüş yol)
	for(i=0;i<90;i++)
		for( j=50;j<52;j++)
		{
			
			glColor3f(0,0,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(i*7.5f,j*3.75f);
				glVertex2f((i*7.5f)+7.5,j*3.75);
				glVertex2f((i*7.5)+7.5, (j*3.75)+3.75);
				glVertex2f(i*7.5, (j*3.75)+3.75);
			glEnd();
			
		}
	//bağlar cad.(yol1)
		for(i=0;i<19;i++)
		for( j=83;j<85;j++)
		{
			
			glColor3f(0,0,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(i*7.5f,j*3.75f);
				glVertex2f((i*7.5f)+7.5,j*3.75);
				glVertex2f((i*7.5)+7.5, (j*3.75)+3.75);
				glVertex2f(i*7.5, (j*3.75)+3.75);
			glEnd();
			
		}
		//bağlar cad.---->İstanbul-Tekirdağ Yolu(yol1 dikey)
		for(i=36;i<38;i++)
		for( j=26.5;j<42;j++)
		{
			
			glColor3f(0,0,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(i*3.75,j*7.5f);
				glVertex2f((i*3.75f)+3.75,j*7.5);
				glVertex2f((i*3.75)+3.75, (j*7.5)+7.5);
				glVertex2f(i*3.75, (j*7.5)+7.5);
			glEnd();
			
		}
		///////////////////////
		//YOL5 (ÜST KISIM)
		for(i=95;i<97;i++)
		for( j=26.5;j<45;j++)
		{
			
			glColor3f(0,0,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(i*3.75,j*7.5f);
				glVertex2f((i*3.75f)+3.75,j*7.5);
				glVertex2f((i*3.75)+3.75, (j*7.5)+7.5);
				glVertex2f(i*3.75, (j*7.5)+7.5);
			glEnd();
			
		}
		///////////////////////
		////YOL11 
		//for(i=49;i<51;i++)
		//for( j=3;j<14;j++)
		//{
		//	
		//	glColor3f(0,0,1);
		//	glBegin(GL_LINE_LOOP);
		//		glVertex2f(i*3.75,j*7.5f);
		//		glVertex2f((i*3.75f)+3.75,j*7.5);
		//		glVertex2f((i*3.75)+3.75, (j*7.5)+7.5);
		//		glVertex2f(i*3.75, (j*7.5)+7.5);
		//	glEnd();
		//	
		//}
		/////////////////////////
		////YOL12
		//for(i=69;i<71;i++)
		//for( j=3;j<14;j++)
		//{
		//	
		//	glColor3f(0,0,1);
		//	glBegin(GL_LINE_LOOP);
		//		glVertex2f(i*3.75,j*7.5f);
		//		glVertex2f((i*3.75f)+3.75,j*7.5);
		//		glVertex2f((i*3.75)+3.75, (j*7.5)+7.5);
		//		glVertex2f(i*3.75, (j*7.5)+7.5);
		//	glEnd();
		//	
		//}
		///////////////////////
		////YOL16
		//for(i=61;i<63;i++)
		//for( j=15;j<23;j++)
		//{
		//	
		//	glColor3f(0,0,1);
		//	glBegin(GL_LINE_LOOP);
		//		glVertex2f(i*3.75,j*7.5f);
		//		glVertex2f((i*3.75f)+3.75,j*7.5);
		//		glVertex2f((i*3.75)+3.75, (j*7.5)+7.5);
		//		glVertex2f(i*3.75, (j*7.5)+7.5);
		//	glEnd();
		//	
		//}
		// ///////////////
		////YOL6(yatay)//
	 //  ///////////////
		//for(i=30.5;i<47.5;i++)
		//	for( j=71;j<73;j++)
		//{
		//	
		//	glColor3f(0,0,1);
		//	glBegin(GL_LINE_LOOP);
		//		glVertex2f(i*7.5f,j*3.75f);
		//		glVertex2f((i*7.5f)+7.5,j*3.75);
		//		glVertex2f((i*7.5)+7.5, (j*3.75)+3.75);
		//		glVertex2f(i*7.5, (j*3.75)+3.75);
		//	glEnd();
		//	
		//}
		////YOL6(dikey)
		//for(i=61;i<63;i++)
		//for( j=26.5;j<36;j++)
		//{
		//	
		//	glColor3f(0,0,1);
		//	glBegin(GL_LINE_LOOP);
		//		glVertex2f(i*3.75,j*7.5f);
		//		glVertex2f((i*3.75f)+3.75,j*7.5);
		//		glVertex2f((i*3.75)+3.75, (j*7.5)+7.5);
		//		glVertex2f(i*3.75, (j*7.5)+7.5);
		//	glEnd();
		//	
		//}
		/////////////
		//sahil yolu(tamamý)
		for(i=0;i<71;i++)
		for( j=4;j<6;j++)
		{
			
			glColor3f(0,0,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(i*7.5f,j*3.75f);
				glVertex2f((i*7.5f)+7.5,j*3.75);
				glVertex2f((i*7.5)+7.5, (j*3.75)+3.75);
				glVertex2f(i*7.5, (j*3.75)+3.75);
			glEnd();
			
		}
		////////////////
		//YOL3
		for(i=36;i<38;i++)
		for( j=3;j<23;j++)
		{
			
			glColor3f(0,0,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(i*3.75,j*7.5f);
				glVertex2f((i*3.75f)+3.75,j*7.5);
				glVertex2f((i*3.75)+3.75, (j*7.5)+7.5);
				glVertex2f(i*3.75, (j*7.5)+7.5);
			glEnd();
			
		}
		//////////////////
		////YOL4
		//for(i=19;i<46.5;i++)
		//	for( j=28;j<30;j++)
		//{
		//	
		//	glColor3f(0,0,1);
		//	glBegin(GL_LINE_LOOP);
		//		glVertex2f(i*7.5f,j*3.75f);
		//		glVertex2f((i*7.5f)+7.5,j*3.75);
		//		glVertex2f((i*7.5)+7.5, (j*3.75)+3.75);
		//		glVertex2f(i*7.5, (j*3.75)+3.75);
		//	glEnd();
		//	
		//}
		//	////////////////
		////YOL13
		//for(i=49;i<68;i++)
		//	for( j=28;j<30;j++)
		//{
		//	
		//	glColor3f(0,0,1);
		//	glBegin(GL_LINE_LOOP);
		//		glVertex2f(i*7.5f,j*3.75f);
		//		glVertex2f((i*7.5f)+7.5,j*3.75);
		//		glVertex2f((i*7.5)+7.5, (j*3.75)+3.75);
		//		glVertex2f(i*7.5, (j*3.75)+3.75);
		//	glEnd();
		//	
		//}
		//////////////////
		////YOL14
		//for(i=49;i<68;i++)
		//	for( j=21;j<23;j++)
		//{
		//	
		//	glColor3f(0,0,1);
		//	glBegin(GL_LINE_LOOP);
		//		glVertex2f(i*7.5f,j*3.75f);
		//		glVertex2f((i*7.5f)+7.5,j*3.75);
		//		glVertex2f((i*7.5)+7.5, (j*3.75)+3.75);
		//		glVertex2f(i*7.5, (j*3.75)+3.75);
		//	glEnd();
		//	
		//}
		//	////////////////
		////YOL15
		//for(i=49;i<68;i++)
		//	for( j=12;j<14;j++)
		//{
		//	
		//	glColor3f(0,0,1);
		//	glBegin(GL_LINE_LOOP);
		//		glVertex2f(i*7.5f,j*3.75f);
		//		glVertex2f((i*7.5f)+7.5,j*3.75);
		//		glVertex2f((i*7.5)+7.5, (j*3.75)+3.75);
		//		glVertex2f(i*7.5, (j*3.75)+3.75);
		//	glEnd();
		//	
		//}
			////////////////
		//YOL9(sað kýsým)
		for(i=141;i<142;i++)
		for( j=3;j<23;j++)
		{
			
			glColor3f(0,0,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(i*3.75,j*7.5f);
				glVertex2f((i*3.75f)+3.75,j*7.5);
				glVertex2f((i*3.75)+3.75, (j*7.5)+7.5);
				glVertex2f(i*3.75, (j*7.5)+7.5);
			glEnd();
			
		}
		//YOL9(sol kýsým)
		for(i=137;i<138;i++)
		for( j=3;j<23;j++)
		{
			
			glColor3f(0,0,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(i*3.75,j*7.5f);
				glVertex2f((i*3.75f)+3.75,j*7.5);
				glVertex2f((i*3.75)+3.75, (j*7.5)+7.5);
				glVertex2f(i*3.75, (j*7.5)+7.5);
			glEnd();
			
		}

		////////////////////
		//YOL10+YOL9(sað kýsým)
		for(i=140;i<141;i++)
			for( j=3;j<45;j++)
			{
			
				glColor3f(0,0,1);
				glBegin(GL_LINE_LOOP);
					glVertex2f(i*3.75,j*7.5f);
					glVertex2f((i*3.75f)+3.75,j*7.5);
					glVertex2f((i*3.75)+3.75, (j*7.5)+7.5);
					glVertex2f(i*3.75, (j*7.5)+7.5);
				glEnd();
			
			}
		////////////////////
		//YOL10+YOL9(sol kýsým)
		for(i=138;i<139;i++)
			for( j=3;j<45;j++)
			{
				glColor3f(0,0,1);
				glBegin(GL_LINE_LOOP);
					glVertex2f(i*3.75,j*7.5f);
					glVertex2f((i*3.75f)+3.75,j*7.5);
					glVertex2f((i*3.75)+3.75, (j*7.5)+7.5);
					glVertex2f(i*3.75, (j*7.5)+7.5);
				glEnd();
			
			}
			////////////////
		//YOL5 alt kýsým
		for(i=94;i<98;i++)
		for( j=3;j<18;j++)
		{
			
			glColor3f(0,0,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(i*3.75,j*7.5f);
				glVertex2f((i*3.75f)+3.75,j*7.5);
				glVertex2f((i*3.75)+3.75, (j*7.5)+7.5);
				glVertex2f(i*3.75, (j*7.5)+7.5);
			glEnd();
			
		}
		//YOL5 alt kýsým(küçük parça)
		for(i=95;i<97;i++)
		for( j=18;j<23;j++)
		{
			
			glColor3f(0,0,1);
			glBegin(GL_LINE_LOOP);
				glVertex2f(i*3.75,j*7.5f);
				glVertex2f((i*3.75f)+3.75,j*7.5);
				glVertex2f((i*3.75)+3.75, (j*7.5)+7.5);
				glVertex2f(i*3.75, (j*7.5)+7.5);
			glEnd();
			
		}


}
///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
void Harita(void)
{   //ayrýlmýþ yol 2x2 
	
	glColor3f(0.8f,0.8f,0.8f);
	glRectf(0.f,172.5f,180*3.75,183.75f);//Tekirdað-Ýstanbul yolu kavþak1 sol taraf
	//glRectf(9*3.75,53*3.75,180*3.75,46*3.75);//Tekirdað-Ýstanbul yolu kavþak1 sað taraf
	glRectf(0.f,187.5f,675.f,198.75f);//Ýstanbul-Tekirdað yolu kavþak1 sol taraf
	//glRectf(33.75f,187.5f,675.f,198.75f);//Ýstanbul-Tekirdað yolu kavþak1 sað taraf

	glRectf(0.f,83*3.75,38*3.75,85*3.75f);//baðlar cad.
	glRectf(36*3.75,83*3.75,38*3.75,53*3.75);//baðlar cad.
	
	//glRectf(5*3.75f,83*3.75f,9*3.75f,53*3.75f);//dik yol part1(1001.cadde)
	//glRectf(5*3.75f,46*3.75f,9*3.75f,5*3.75f);//dik yol part1(1001.cadde)
	glRectf(36*3.75,46*3.75,38*3.75,6*3.75);//yol3 +yol4
	glRectf(137*3.75,50*3.75,142*3.75,49*3.75);//kavþak orta parça

	glRectf(0*3.75,4*3.75,142*3.75,6*3.75);//sahil yolu
	//glEnable(GL_DEPTH_TEST);
	//glBegin(GL_POLYGON);
	//glVertex3f(5*3.75,53*3.75,4.5f);
	//glVertex3f(9*3.75,53*3.75,4.5f);
	//glVertex3f(9*3.75,46*3.75,4.5f);
	//glVertex3f(5*3.75,46*3.75,4.5f);
	//glEnd();
	////glDisable(GL_DEPTH_TEST);
	//glBegin(GL_POLYGON);
	//glVertex3f(9*3.75,30*3.75,0.f);
	//glVertex3f(9*3.75,32*3.75,0);
	//glVertex3f(24*3.75,46*3.75,0);
	//glVertex3f(26*3.75,46*3.75,0);
	//glEnd();

	//glBegin(GL_POLYGON);
	//glVertex3f(24*3.75,53*3.75,0.f);
	//glVertex3f(26*3.75,53*3.75,0);
	//glVertex3f(9*3.75,69*3.75,0);
	//glVertex3f(9*3.75,67*3.75,0);
	//glEnd();
	
	//çapraz kol(sað alt)

	glBegin(GL_POLYGON);
		glVertex3f(98*3.75,37*3.75,0);
		glVertex3f(107*3.75,46*3.75,0);
		glVertex3f(105*3.75,46*3.75,0);
		glVertex3f(97*3.75,38*3.75,0);
	glEnd();
	
	//alt geçit(alt kýsým düz yol)
	glBegin(GL_POLYGON);
		glVertex3f(97*3.75,38*3.75,0);
		glVertex3f(97*3.75,46*3.75,0);
		glVertex3f(95*3.75,46*3.75,0);
		glVertex3f(95*3.75,38*3.75,0);
	glEnd();
	
	//çapraz kol(sol alt)
	glBegin(GL_POLYGON);
		glVertex3f(95*3.75,38*3.75,0);
		glVertex3f(87*3.75,46*3.75,0);
		glVertex3f(85*3.75,46*3.75,0);
		glVertex3f(94*3.75,37*3.75,0);
	glEnd();
	
	//alt geçite giden alt yol(gidiþ-dönüþx2)
	glBegin(GL_POLYGON);
		glVertex3f(98*3.75,37*3.75,0);
		glVertex3f(97*3.75,38*3.75,0);
		glVertex3f(95*3.75,38*3.75,0);
		glVertex3f(94*3.75,37*3.75,0);
		glVertex3f(94*3.75,6*3.75,0);
		glVertex3f(98*3.75,6*3.75,0);
	glEnd();
	
	//çapraz kol(sað üst)
	glBegin(GL_POLYGON);
		glVertex3f(107*3.75,53*3.75,0);
		glVertex3f(97*3.75,63*3.75,0);
		glVertex3f(97*3.75,61*3.75,0);
		glVertex3f(105*3.75,53*3.75,0);
	glEnd();
	
	//alt geçit (üst kýsým düz yol)
	glBegin(GL_POLYGON);
		glVertex3f(97*3.75,53*3.75,0);
		glVertex3f(97*3.75,61*3.75,0);
		glVertex3f(95*3.75,61*3.75,0);
		glVertex3f(95*3.75,53*3.75,0);
	glEnd();
	
	//çapraz kol(sol üst)
	glBegin(GL_POLYGON);
		glVertex3f(95*3.75,61*3.75,0);
		glVertex3f(95*3.75,63*3.75,0);
		glVertex3f(85*3.75,53*3.75,0);
		glVertex3f(87*3.75,53*3.75,0);
	glEnd();
	
	//yol5
	glBegin(GL_POLYGON);
		glVertex3f(97*3.75,61*3.75,0);
		glVertex3f(97*3.75,91*3.75,0);
		glVertex3f(95*3.75,91*3.75,0);
		glVertex3f(95*3.75,61*3.75,0);
	glEnd();
	
	//yol6(dik kýsým)
	//glRectf(61*3.75,73*3.75,63*3.75,53*3.75);
	//yol6(yatay kýsým)
	
	//glRectf(63*3.75,73*3.75,95*3.75,71*3.75);
	
	//segment016
	//glRectf(61*3.75,46*3.75,63*3.75,30*3.75);
	

	glRectf(137*3.75,42*3.75,142*3.75,6*3.75);//2x2+yeþillik dikey yol
	
	glRectf(138*3.75,90*3.75,141*3.75,58*3.75);//segment34
	
	
	//glRectf(37*3.75,30*3.75,94*3.75,28*3.75);//segment 011+014+017+021(yatay yol)
	
	/*glRectf(49*3.75,28*3.75,51*3.75,6*3.75);
	glRectf(69*3.75,28*3.75,71*3.75,6*3.75);
	glRectf(98*3.75,23*3.75,137*3.75,21*3.75);
	glRectf(98*3.75,14*3.75,137*3.75,12*3.75);
	glRectf(98*3.75,30*3.75,137*3.75,28*3.75);
		*/
	glBegin(GL_QUADS);
		glVertex3f(133*3.75,53*3.75,0);
		glVertex3f(146*3.75,53*3.75,0);
		glVertex3f(141*3.75,58*3.75,0);
		glVertex3f(138*3.75,58*3.75,0);
	glEnd();
	
	glBegin(GL_QUADS);
		glVertex3f(133*3.75,46*3.75,0);
		glVertex3f(137*3.75,42*3.75,0);
	
		glVertex3f(142*3.75,42*3.75,0);
		glVertex3f(146*3.75,46*3.75,0);
	glEnd();

	///////////////////////////////
	//yeþillikler
	//////////////////////////////
	glColor3f(0.0,0.3,0.0);
	glBegin(GL_TRIANGLES);
		glVertex3f(137*3.75,44*3.75,0);
		glVertex3f(137*3.75,46*3.75,0);
		glVertex3f(135*3.75,46*3.75,0);
		glVertex3f(142*3.75,44*3.75,0);
		glVertex3f(144*3.75,46*3.75,0);
		glVertex3f(142*3.75,46*3.75,0);
		glVertex3f(135*3.75,53*3.75,0);
		glVertex3f(137*3.75,53*3.75,0);
		glVertex3f(137*3.75,55*3.75,0);
		glVertex3f(142*3.75,53*3.75,0);
		glVertex3f(144*3.75,53*3.75,0);
		glVertex3f(142*3.75,55*3.75,0);
	glEnd();
	glRectf(139*3.75,46*3.75,140*3.75,30*3.75);
	glRectf(139*3.75,28*3.75,140*3.75,6*3.75);
	glRectf(0,50*3.75,137*3.75,49*3.75);
	
	glRectf(142*3.75,50*3.75,180*3.75,49*3.75);
	

	
	

	//düz þeritler
	glColor3f(1.f,1.f,1.f);
	glBegin(GL_LINES);
	
	glVertex3f(0,47*3.75,0);	//yol8 düz þerit 1
	glVertex3f(137*3.75,47*3.75,0);
	
	/*glVertex3f(9*3.75,47*3.75,0);
	glVertex3f(137*3.75,47*3.75,0);*/
	
	glVertex3f(142*3.75,47*3.75,0);//yol8 düz þerit 2
	glVertex3f(180*3.75,47*3.75,0);
	
	glVertex3f(0,52*3.75,0);		//yol7 düz þerit 1
	glVertex3f(137*3.75,52*3.75,0);
	
	
	
	
	glVertex3f(142*3.75,52*3.75,0); //yol7  düz þerit 2
	glVertex3f(180*3.75,52*3.75,0);
	
	
	glVertex3f(62*3.75,72*3.75,0);//yol6 düz þerit (yatay)
	glVertex3f(95*3.75,72*3.75,0);
	
	glVertex3f(62*3.75,72*3.75,0);//yol6 düz þerit (dikey)
	glVertex3f(62*3.75,53*3.75,0);

	glVertex3f(96*3.75,61*3.75,0);//alt geçitli kavþak- dik yol(üst kýsým part 2)
	glVertex3f(96*3.75,53*3.75,0);
	
	glVertex3f(96*3.75,63*3.75,0);//alt geçitli kavþak- dik yol(üst kýsým part1)
	glVertex3f(96*3.75,91*3.75,0);
	
	glVertex3f(96*3.75,46*3.75,0);//alt geçitli kavþak- dik yol(aþaðý kýsým)
	glVertex3f(96*3.75,6*3.75,0);
	
	glVertex3f(98*3.75,29*3.75,0);//3lü yatay yol-yol1
	glVertex3f(137*3.75,29*3.75,0);

	glVertex3f(98*3.75,22*3.75,0);//3lü yatay yol-yol2
	glVertex3f(137*3.75,22*3.75,0);
	
	glVertex3f(98*3.75,13*3.75,0);//3lü yatay yol-yol3
	glVertex3f(137*3.75,13*3.75,0);
	
	glVertex3f(37*3.75,46*3.75,0);//sahil yolu--->tekirdað&istanbul yolu dik yol 1
	glVertex3f(37*3.75,6*3.75,0);
	
	glVertex3f(62*3.75,46*3.75,0);//YOL 16 düz þerit
	glVertex3f(62*3.75,30*3.75,0);
	
	glVertex3f(50*3.75,28*3.75,0);//yol 11 düz þerit
	glVertex3f(50*3.75,6*3.75,0);
	
	glVertex3f(70*3.75,28*3.75,0);//yol 12 düz þerit
	glVertex3f(70*3.75,6*3.75,0);
	
	glVertex3f(38*3.75,29*3.75,0);//yol 4 düz þerit
	glVertex3f(94*3.75,29*3.75,0);
	
	glVertex3f(0*3.75,5*3.75,0);//sahil yolu
	glVertex3f(137*3.75,5*3.75,0);
	
	glVertex3f(37*3.75,84*3.75,0);//yol1 dik düz þerit
	glVertex3f(37*3.75,53*3.75,0);
	
	glVertex3f(0*3.75,84*3.75,0);//yol1 yatay düz þerit
	glVertex3f(37*3.75,84*3.75,0);

	glVertex3f(522.5,53*3.75,0);
	glVertex3f(522.5,90*3.75,0);
	glVertex3f(524,53*3.75,0);
	glVertex3f(524,90*3.75,0);
	glEnd();
	//
	// kesikli þeritler
	
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(3.75f,0x0F0F);
	glBegin(GL_LINES);
		glVertex3f(0,48*3.75,0);
		glVertex3f(137*3.75,48*3.75,0);
		
		/*glVertex3f(9*3.75,48*3.75,0);
		glVertex3f(137*3.75,48*3.75,0);*/
		glVertex3f(142*3.75,48*3.75,0);
		glVertex3f(180*3.75,48*3.75,0);
		
		glVertex3f(0,51*3.75,0);
		glVertex3f(137*3.75,51*3.75,0);
		/*glVertex3f(9*3.75,51*3.75,0);
		glVertex3f(137*3.75,51*3.75,0);*/
		glVertex3f(142*3.75,51*3.75,0);
		glVertex3f(180*3.75,51*3.75,0);

		glVertex3f(141*3.75,44*3.75,0);
		glVertex3f(141*3.75,28*3.75,0);
		glVertex3f(141*3.75,26*3.75,0);
		glVertex3f(141*3.75,7*3.75,0);

		glVertex3f(138*3.75,44*3.75,0);
		glVertex3f(138*3.75,28*3.75,0);
		glVertex3f(138*3.75,26*3.75,0);
		glVertex3f(138*3.75,7*3.75,0);

		glVertex3f(95*3.75,36*3.75,0);
		glVertex3f(95*3.75,7*3.75,0);

		glVertex3f(97*3.75,36*3.75,0);
		glVertex3f(97*3.75,7*3.75,0);

		//glVertex3f(6*3.75,83*3.75,0);//üst yol kesikli çizgileri(sol)
		//glVertex3f(6*3.75,6*3.75,0);

		//glVertex3f(8*3.75,83*3.75,0);//üst yol kesikli çizgileri(sað)
		//glVertex3f(8*3.75,6*3.75,0);
	glEnd();
	glDisable(GL_LINE_STIPPLE);

	/////////////////////////////////////////////////////////////
	//trafik ýþýklarý
	glColor3f(LightColor[TrafficLight[0]][0],LightColor[TrafficLight[0]][1], LightColor[TrafficLight[0]][2]);
	glRecti(142*3.75,53*3.75,142.5*3.75,53.5*3.75);
	glColor3f(LightColor[TrafficLight[1]][0],LightColor[TrafficLight[1]][1], LightColor[TrafficLight[1]][2]);
	glRecti(142*3.75,46*3.75,142.5*3.75,46.5*3.75);
	glColor3f(LightColor[TrafficLight[2]][0],LightColor[TrafficLight[2]][1], LightColor[TrafficLight[2]][2]);
	glRecti(136.5*3.75,46*3.75,137*3.75,46.5*3.75);
	glColor3f(LightColor[TrafficLight[3]][0],LightColor[TrafficLight[3]][1], LightColor[TrafficLight[3]][2]);
	glRecti(137*3.75,53*3.75,137.5*3.75,53.5*3.75);
}
///////////////////////////////////////////////////////////////////
