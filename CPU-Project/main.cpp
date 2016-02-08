#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gl\glut.h>
#include <math.h>

#include "arac.h"
#include "main.h"
#include "harita.h"




ARAC *araclar[arac_sayisi];
float RBP=0.03;
double totalUpdateTime=0;
//true=dolu,false=bos
bool  yol1[35][2]={false};//baðlar cad.
bool  yol2[71][2]={false};//sahil yolu(tamamý)
bool  yol3[20][2]={false};//sahil yolu--->Tekirdað-Ýstanbul yolu
bool  yol4[29][2]={false};
bool  yol5[45][2]={false};
bool yol52[15][2]={false};
bool  yol6[26][2]={false};
bool  yol7[91][3]={false};
bool  yol8[91][3]={false};
bool  yol9[42][2]={false};
bool yol10[43][2]={false};
bool yol11[15][2]={false};
bool yol12[15][2]={false};
bool yol13[25][2]={false};
bool yol14[25][2]={false};
bool yol15[25][2]={false};
bool yol16[10][2]={false};
/////////////
bool kol1[6]={false};//çapraz yol(sol üst)-->yön 7
bool kol2[6]={false};//çapraz yol(sað üst)-->yön 8
bool kol3[6]={false};//çapraz yol(sol alt)-->yön 6
bool kol4[6]={false};//çapraz yol(sað alt)-->yön 5

bool kol2_1[5]={false};//çapraz yol(sol üst)-->yön 7
bool kol2_2[5]={false};//çapraz yol(sað üst)-->yön 8
bool kol2_3[5]={false};//çapraz yol(sol alt)-->yön 6
bool kol2_4[5]={false};//çapraz yol(sað alt)-->yön 5
////////////////////////////////////////////////////



////////////////////////////////////////////////////
void HucreDoldur(int y_id,int s_id,int h_id,int tip)//en baþta dolu olacak hücreler belirleniyor
{
	int kap_hc_say;
	if(tip==3 || tip==1)
	{
		kap_hc_say=2;
	}
	else
		kap_hc_say=1;
	int count=h_id;
	if(y_id==1)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol1[count][s_id]=true;
			count++;
		}
	}
	if(y_id==2)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol2[count][s_id]=true;
			count++;
		}
	}
	if(y_id==5)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol5[count][s_id]=true;
			count++;
		}
	}
	if(y_id==6)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol6[count][s_id]=true;
			count++;
		}
	}
	if(y_id==7)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol7[count][s_id]=true;
			count++;
		}
		
	}
	if(y_id==8)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol8[count][s_id]=true;
			count++;
		}
	}
	if(y_id==9)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol9[count][s_id]=true;
			count++;
		}
	}
	if(y_id==10)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol10[count][s_id]=true;
			count++;
		}
	}
	if(y_id==11)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol11[count][s_id]=true;
			count++;
		}
	}
	if(y_id==12)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol12[count][s_id]=true;
			count++;
		}
	}
	if(y_id==13)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol13[count][s_id]=true;
			count++;
		}
	}
	if(y_id==14)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol14[count][s_id]=true;
			count++;
		}
	}
	if(y_id==15)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol15[count][s_id]=true;
			count++;
		}
	}
	if(y_id==16)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol16[count][s_id]=true;
			count++;
		}
	}
	if(y_id==52)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol52[count][s_id]=true;
			count++;
		}
	}
	if(y_id==101)
	{
		//çapraz yol(sol üst)
		kol1[h_id]=true;
		
	}
	
}
///////////////////////////
void delay(int id)
{
	if(araclar[id]->yon==4)
	{
		araclar[id]->hc_id++;
		araclar[id]->solX=1500.f;
	}
	
	if(araclar[id]->yon==3)
	{
		araclar[id]->hc_id--;
		araclar[id]->solX=1500.f;
	}
	
	
}
//////////////////////////////////
int getForwardGap(int y_id,int s_id,int h_id, int tip)
{
	int gap=0;
	int count;
	if(tip==3 || tip==1)
		count=2;
	else
		count=1;
	if(y_id==8)
	{
		
		while(  yol8[h_id+count][s_id]==false && h_id+count<90)
		{
			
			count++;
			gap++;
			
			
		}
		
		cout<<"gap yol8: "<<gap<<"\t"<<endl;
		return gap;
	}

	if(y_id==7)
	{
		
		while(  yol7[h_id-count][s_id]==false && h_id-count>0)
		{
			
			count++;
			gap++;
			
			
		}
		
		cout<<"gap yol8: "<<gap<<"\t"<<endl;
		return gap;
	}
}
///////////////////////////////////////////////////
void ARAC::Update(int id)
{       
	srand(time(NULL));
	//////////////////////////////////////////////////////
      ////YOL1
		if(araclar[id]->yol_id==1 )//yol1 mi?
		{
			int idx=araclar[id]->hc_id;
			//kavþak noktasýna kadar ilerle
			if(araclar[id]->serit_id==0 && araclar[id]->yon==1)
			{
				
				if(yol1[idx+1][0]==false)
				{   
					araclar[id]->solX+=7.5;
					yol1[idx+1][0]=true;
					yol1[idx][0]=false;
					araclar[id]->hc_id++;
				}
			}
			//saða döndükten sonra aþaðý yönde ilerle
			if(araclar[id]->serit_id==0 && araclar[id]->yon==4)
			{
				if(yol1[idx+1][0]==false)
				{   
					araclar[id]->solY-=7.5;
					yol1[idx+1][0]=true;
					yol1[idx][0]=false;
					araclar[id]->hc_id++;
				}
			}
			//yol1-þerit1-yön 3(yukarý gidiþ)
			if(araclar[id]->serit_id==1 && araclar[id]->yon==3)
			{
				if(yol1[idx-1][1]==false)
				{   
					araclar[id]->solY+=7.5;
					yol1[idx-1][1]=true;
					yol1[idx][1]=false;
					araclar[id]->hc_id--;
				}
			}
			//yol1-þerit1-sola dönüþ
			if(araclar[id]->hc_id==19 && araclar[id]->serit_id==1 && yol1[18][1]==false)//hedef hc boþ mu?
			{
					araclar[id]->solX=36*3.75f;
					araclar[id]->solY=85*3.75;
					araclar[id]->yon=2;
					araclar[id]->yol_id=1;
					araclar[id]->serit_id=1;
					araclar[id]->hc_id=18;
					yol1[19][1]=false;
					
					
			}
			//þerit 1--->çýkýþ noktasýna kadar ilerle
			if(araclar[id]->serit_id==1 && araclar[id]->yon==2)
			{
				
				if(yol1[idx-1][1]==false)
				{   
					araclar[id]->solX-=7.5;
					yol1[idx-1][1]=true;
					yol1[idx][1]=false;
					araclar[id]->hc_id--;
				}
			}
			//yol1-þerit1-haritadan çýkýþ--->yol5 giriþ
			if(araclar[id]->hc_id==0 && araclar[id]->serit_id==1 && yol5[1][0]== false)// hedef hc boþ mu?
			{
					araclar[id]->solX=95*3.75f;
					araclar[id]->solY=91*3.75;
					araclar[id]->yon=4;
					araclar[id]->yol_id=5;
					araclar[id]->serit_id=0;
					yol1[0][1]=false;
					araclar[id]->hc_id=1;
					
					
			}
			//yol1&serit0(saða dönüþ)
			if(araclar[id]->hc_id==19 && araclar[id]->serit_id==0 && yol1[20][0]== false)// gideceði hc. boþ mu?
			{
					araclar[id]->solX=36*3.75f;
					araclar[id]->solY=83*3.75;
					araclar[id]->yon=4;
					araclar[id]->yol_id=1;
					araclar[id]->serit_id=0;
					araclar[id]->hc_id=20;
					yol1[19][0]=false;
			}
			//yol1&serit0(saða dönüþ-otoyola çýkýþ)
			if(araclar[id]->hc_id==35 && araclar[id]->serit_id==0 && yol7[18][0]==false) //hedef hc boþ mu?
			{
					araclar[id]->solX=38*3.75f;
					araclar[id]->solY=53*3.75;
					araclar[id]->yon=2;
					araclar[id]->yol_id=7;
					araclar[id]->serit_id=0;
					yol1[35][0]=false;
					araclar[id]->hc_id=18;
			}
		
		}//end of YOL1
		//////////////////////////////////////////////////////////////////////////////////////////
		//YOL2
		if(araclar[id]->yol_id==2 )
		{
			int idx=araclar[id]->hc_id;
			//kavþak noktasýna kadar ilerle
			if(araclar[id]->serit_id==0 && araclar[id]->yon==1)
			{
				
				if(yol2[idx+1][0]==false)
				{   
					araclar[id]->solX+=7.5;
					yol2[idx+1][0]=true;
					yol2[idx][0]=false;
					araclar[id]->hc_id++;
				}
			}
			//þerit 1 yön 2
			if(araclar[id]->serit_id==1 && araclar[id]->yon==2)
			{
				
				if(yol2[idx-1][0]==false)
				{   
					araclar[id]->solX-=7.5;
					yol2[idx-1][1]=true;
					yol2[idx][1]=false;
					araclar[id]->hc_id--;
				}
			}
			//þerit 1 yol sonu(baþladýðý konuma geri dönecek)
			if(araclar[id]->serit_id==1 && araclar[id]->hc_id==0)
			{
					araclar[id]->solX=138*3.75;
					araclar[id]->solY=90*3.75;
					araclar[id]->yon=4;
					araclar[id]->serit_id=1;
					araclar[id]->yol_id=10;
					yol2[0][1]=false;
					araclar[id]->hc_id=42;
			}
			//random yön(ya sol&yukarý ya da düz devam edecek)		
			if(araclar[id]->serit_id==0 && araclar[id]->hc_id==18 )
			{
					int tempYon=rand()%2+1;

					if (tempYon==1)
					{
						yon=1;
					}
					else
					{
						if(yol3[1][0]==false && yol2[19][1]==false && yol2[20][1])
						{
							araclar[id]->solX=38*3.75;
							araclar[id]->solY=6*3.75;
							araclar[id]->yon=3;
							araclar[id]->serit_id=0;
							araclar[id]->yol_id=3;
							araclar[id]->hc_id=0;
							yol2[18][0]=false;
						}
					}
					
			}
			
			//random yön(ya YOL 52'e dönecek , ya yol5'e dönecek ya da düz devam edecek)		
			if(araclar[id]->serit_id==0 && araclar[id]->hc_id==48 )
			{
					int tempYon=rand()%2+1;

					if (tempYon==1)
					{
						yon=1;//düz git
					}
				
					else
					{
						if(yol5[1][1]==false && yol2[49][1]== false && yol2[50][1]==false)
						{
							araclar[id]->solX=97*3.75;
							araclar[id]->solY=6*3.75;
							araclar[id]->yon=3;
							araclar[id]->serit_id=1;
							araclar[id]->yol_id=5;
							araclar[id]->hc_id=42;
							yol2[48][0]=false;
						}
					}
					
			}
			//yol2 sonuna gelindi, yukarý dönecek(ya yol10 ya da yol9)
			if(araclar[id]->serit_id==0 && araclar[id]->hc_id==72 )
			{
				int tempYon=rand()%2+1;

					if (tempYon==1)
					{
						if(yol10[1][0]==false)
						{
							araclar[id]->solX=141*3.75;
							araclar[id]->solY=6*3.75;
							araclar[id]->yon=3;
							araclar[id]->serit_id=0;
							araclar[id]->yol_id=10;
							araclar[id]->hc_id=1;
							yol2[72][0]=false;
						}
					}
					else
					{
						if(yol9[1][0]==false)
						{
							araclar[id]->solX=142*3.75;
							araclar[id]->solY=6*3.75;
							araclar[id]->yon=3;
							araclar[id]->serit_id=0;
							araclar[id]->yol_id=9;
							araclar[id]->hc_id=1;
							yol2[72][0]=false;
						}
					}
			}
			//yon 2--->random yön(ya düz gidecek , ya 52 ya da 5'e dönecek)
			if(araclar[id]->serit_id==1 && araclar[id]->hc_id==50 )
			{
					int tempYon=rand()%2+1;

					if (tempYon==1)
					{
						yon=2;//düz git
					}
					
					else
					{
						if(yol5[1][1]==false && yol2[48][0]== false && yol2[49][0]==false)
						{
							araclar[id]->solX=97*3.75;
							araclar[id]->solY=6*3.75;
							araclar[id]->yon=3;
							araclar[id]->serit_id=1;
							araclar[id]->yol_id=5;
							araclar[id]->hc_id=42;
							yol2[48][0]=false;
						}
					}
					
			}
			
			//random yön(ya yol3 ya da düz devam edecek)		
			if(araclar[id]->serit_id==1 && araclar[id]->hc_id==20 )
			{
					int tempYon=rand()%2+1;

					if (tempYon==1)
					{
						yon=2;
					}
					else
					{
						if(yol3[1][0]==false && yol2[19][0]==false && yol2[18][0])
						{
							araclar[id]->solX=38*3.75;
							araclar[id]->solY=6*3.75;
							araclar[id]->yon=3;
							araclar[id]->serit_id=0;
							araclar[id]->yol_id=3;
							araclar[id]->hc_id=0;
							yol2[20][1]=false;
						}
					}
					
			}
			
		}//end of YOL2
		
		////////////////////////////////////////////////////////////////////////////////////////////
		//YOL3
		if(araclar[id]->yol_id==3 )
		{
			int idx=araclar[id]->hc_id;
			//kavþak noktasýna kadar ilerle
			if(araclar[id]->serit_id==0 && araclar[id]->yon==3)
			{
				
				if(yol3[idx+1][0]==false)
				{   
					araclar[id]->solY+=7.5;
					yol3[idx+1][0]=true;
					yol3[idx][0]=false;
					araclar[id]->hc_id++;
				}
			}

			
			//yol3 sonuna gelindi, saða dönecek--->YOL8
			if(araclar[id]->serit_id==0 && araclar[id]->hc_id==21)
			{
				araclar[id]->solX=38*3.75;
				araclar[id]->solY=46*3.75;
				araclar[id]->yon=1;
				araclar[id]->serit_id=0;
				araclar[id]->yol_id=8;
				yol3[21][0]=false;
				araclar[id]->hc_id=20;//yol8'un 19.hücresi
				yol8[20][0]=true;
				
			}
			//yol3 þerit1 aþaðý yönde ilerle
			if(araclar[id]->serit_id==1 && araclar[id]->yon==4)
			{
				
				if(yol3[idx-1][1]==false)
				{   
					araclar[id]->solY-=7.5;
					yol3[idx-1][1]=true;
					yol3[idx][1]=false;
					araclar[id]->hc_id--;
				}
			}
			//yol3---->yol2 geçiþ saða dönüþ
			if(araclar[id]->serit_id==1 && araclar[id]->hc_id==0)
			{
				araclar[id]->solX=36*3.75;
				araclar[id]->solY=6*3.75;
				araclar[id]->yon=2;
				araclar[id]->serit_id=1;
				araclar[id]->yol_id=2;
				yol3[0][1]=false;
				araclar[id]->hc_id=18;
			}
		}//end of YOL3
		//////////////////////////////////////////////////////
 
		//////////////////////////////////////////////////////////////////////////////////////////////
		//YOL5
		if(araclar[id]->yol_id==5 )
		{
			int idx=araclar[id]->hc_id;
			//kavþak noktasýna kadar ilerle
			if(araclar[id]->serit_id==0 && araclar[id]->yon==4)
			{
				
				if(yol5[idx+1][0]==false)
				{   
					araclar[id]->solY-=7.5;
					yol5[idx+1][0]=true;
					yol5[idx][0]=false;
					araclar[id]->hc_id++;
				}

				if(araclar[id]->hc_id==20)
				{
					delay(id);
					yol5[20][0]=false;
				}
				if(araclar[id]->hc_id==25)
				{
					araclar[id]->solX=95*3.75;
					araclar[id]->solY=46*3.75;
					
				}
				//yol2'ye dönüþ
				if(araclar[id]->hc_id==43)
				{
					
						araclar[id]->solX=94*3.75;
						araclar[id]->solY=6*3.75;
						araclar[id]->yol_id=2;
						araclar[id]->serit_id=1,
						araclar[id]->hc_id=48;
						yol2[48][1]=true;
						yol5[43][0]=false;
						araclar[id]->yon=2;
					
				}

			}
			
			if(araclar[id]->serit_id==1 && araclar[id]->yon==3)
			{
				
				if(yol5[idx-1][1]==false)
				{   
					araclar[id]->solY+=7.5;
					yol5[idx-1][1]=true;
					yol5[idx][1]=false;
					araclar[id]->hc_id--;
				}

				if(araclar[id]->hc_id==22)
				{
					delay(id);
					yol5[22][1]=false;
				}
				if(araclar[id]->hc_id==19)
				{
					araclar[id]->solX=97*3.75;
					araclar[id]->solY=53*3.75;
					
					
				}
				//yol5------------>çýkýþ
				if(araclar[id]->serit_id==1 && araclar[id]->hc_id==0)
				{
					//yol1 serit0'a gönder
					araclar[id]->solX=0*3.75;
					araclar[id]->solY=83*3.75;
					araclar[id]->yol_id=1;
					araclar[id]->serit_id=0;
					araclar[id]->hc_id=1;
					araclar[id]->yon=1;
					yol1[1][0]=true;
					yol5[0][1]=false;
				}
			}
			
		
			

			
			
		}//end of YOL5
		////////////////////////////////////////////////////////////////////////////////////////////
		//YOL52
		if(araclar[id]->yol_id==52 )
		{
			int idx=araclar[id]->hc_id;
			//þerit 1- þerit sonuna kadar ilerle
			if(araclar[id]->serit_id==1 && araclar[id]->yon==4)
			{
				
				if(yol52[idx-1][1]==false)
				{   
					araclar[id]->solY-=7.5;
					yol52[idx-1][1]=true;
					yol52[idx][1]=false;
					araclar[id]->hc_id--;
				}
			}
			//yol52 yukarý yönde ilerle
			if(araclar[id]->serit_id==0 && araclar[id]->yon==3)
			{
				
				if(yol52[idx+1][0]==false)
				{   
					araclar[id]->solY+=7.5;
					yol52[idx+1][0]=true;
					yol52[idx][0]=false;
					araclar[id]->hc_id++;
				}
			}
			
			if(araclar[id]->hc_id==0 && yol2[47][1]==false)//gideceði hücre boþ mu?
					{
						//saða dön---->yol2
						araclar[id]->solX=94*3.75f;
						araclar[id]->solY=6*3.75;
						araclar[id]->yon=2;
						araclar[id]->yol_id=2;
						araclar[id]->serit_id=1;
						yol52[0][1]=false;
						araclar[id]->hc_id=47;

					}
			//çapraz yol(5 yönünde)
			if(araclar[id]->hc_id==15 && araclar[id]->serit_id==0)
					{
						
						araclar[id]->solX=98*3.75f;
						araclar[id]->solY=37*3.75;
						araclar[id]->yon=5;
						araclar[id]->yol_id=104;
						araclar[id]->serit_id=1;
						araclar[id]->hc_id=0;
						yol52[15][0]=false;
					}
					
		}//end of YOL52
		///////////////////////////////////////////////////////////////////////////////////////////////
		
		////////////////////////////////////////////////////////////////////////////////////////////
		//YOL7
		
		if(araclar[id]->yol_id==7 )
		{
				int idx=araclar[id]->hc_id;
				int vmax;
				//yol7(Bölünmüþ ana yol) için max. hýzlar
				if(araclar[id]->a_tipi==0)
					vmax=4;//otomobil vmax=108km/sa
				else if(araclar[id]->a_tipi==1)
					vmax=2;//týr vmax=54km/sa
				else 
					vmax=3;//kamyon,kamyonet,otobüs vmax=81km/sa
				//Nagel-Sch. Modeli

				//Adým 1: Hýzlanma(Acceleration)
				if(araclar[id]->hiz < vmax)
					araclar[id]->hiz++;
				cout<<araclar[id]->hiz<<endl;

				//Adým 2: Yavaþlama (Braking)
				araclar[id]->hiz=minimum(araclar[id]->hiz,getForwardGap(araclar[id]->yol_id,araclar[id]->serit_id,araclar[id]->hc_id,araclar[id]->a_tipi));
				
				//Adým 3: Random Braking
				float x=float(rand())/RAND_MAX;
				
				if(x<=RBP)
					{
						araclar[id]->hiz=maximum(0,araclar[id]->hiz-1);
						
					}
				////Adým 4:Move(aþaðýda kodlarý mevcut)

				
				
				
				if(araclar[id]->hc_id>60)
					araclar[id]->hiz=1;
			//araç tipi týr ya da otobüs ise(yani 2 hc. kaplýyorsa)
			if(araclar[id]->a_tipi==3 || araclar[id]->a_tipi==1)
			
			{
				//ýþýklara kadar devam et
				if(araclar[id]->hc_id-1>73 && yol7[idx-2][serit_id]==false )
				 {
							araclar[id]->solX-=(araclar[id]->hiz*7.5);
							yol7[idx-araclar[id]->hiz][araclar[id]->serit_id]=true;
							yol7[idx-araclar[id]->hiz-1][araclar[id]->serit_id]=true;

							yol7[idx][araclar[id]->serit_id]=false;
							yol7[idx-araclar[id]->hiz+1][araclar[id]->serit_id]=false;
							araclar[id]->hc_id-=(araclar[id]->hiz);
				 }
		
				
				//kýrmýzý yandý,dur
				if(TrafficLight[2]==0 && araclar[id]->hc_id==72)
				 {
					 araclar[id]->solX-=(araclar[id]->hiz*0.f);
				 }
				 //yeþil yandý, geç
				 if(TrafficLight[2]==2 && araclar[id]->hc_id==72 && yol7[idx-1][serit_id]==false)
				 {
							araclar[id]->solX-=(araclar[id]->hiz*7.5);
							yol7[idx+araclar[id]->hiz][araclar[id]->serit_id]=true;
							yol7[idx][araclar[id]->serit_id]=false;
							araclar[id]->hc_id-=(araclar[id]->hiz);
				 }
				 //ýþýklarý geçtikten sonra durma ,devam et
				 if(araclar[id]->hc_id<=71 && yol7[idx-1][serit_id]==false)
				 {					
							araclar[id]->solX-=(araclar[id]->hiz*7.5);
							yol7[idx-araclar[id]->hiz][araclar[id]->serit_id]=true;
							yol7[idx][araclar[id]->serit_id]=false;
							araclar[id]->hc_id-=(araclar[id]->hiz);
							
				 }
			
			}
			else
				
				//ýþýklara kadar devam et
				if(araclar[id]->hc_id>72 && yol7[idx-1][serit_id]==false )
				 {
							araclar[id]->solX-=(araclar[id]->hiz*7.5);
							yol7[idx-araclar[id]->hiz][araclar[id]->serit_id]=true;
							yol7[idx][araclar[id]->serit_id]=false;
							araclar[id]->hc_id-=(araclar[id]->hiz);
				 }
				//kýrmýzý yandý,dur
				if(TrafficLight[0]==0 && araclar[id]->hc_id==72)
				 {
					 araclar[id]->solX-=(araclar[id]->hiz*0.f);
					 
				 }
				 //yeþil yandý, geç
				 if(TrafficLight[2]==2 && araclar[id]->hc_id==72 && yol7[idx-1][serit_id]==false)
				 {
							araclar[id]->solX-=(araclar[id]->hiz*7.5);
							yol7[idx-araclar[id]->hiz][araclar[id]->serit_id]=true;
							yol7[idx][araclar[id]->serit_id]=false;
							araclar[id]->hc_id-=(araclar[id]->hiz);
				 }
				//ýþýklarý geçtikten sonra durma ,devam et
				 if(araclar[id]->hc_id<=71 && yol7[idx-1][serit_id]==false)
				 {					
							araclar[id]->solX-=(araclar[id]->hiz*7.5);
							yol7[idx-araclar[id]->hiz][araclar[id]->serit_id]=true;
							yol7[idx][araclar[id]->serit_id]=false;
							araclar[id]->hc_id-=(araclar[id]->hiz);
				 }

				 //çapraz yol
				 if(araclar[id]->serit_id==0 && araclar[id]->hc_id==73)
				 {
						araclar[id]->solX=146.5*3.75f;
						araclar[id]->solY=52*3.75;
						araclar[id]->yon=8;
						araclar[id]->yol_id=202;
						araclar[id]->serit_id=1;
						araclar[id]->hc_id=0;
						yol7[73][0]=false;

				 }
				 //////////////////////////////////////////////////////////////////////////////////////////////
			//haritadan çýkýþlar
			if(araclar[id]->hc_id==1 && araclar[id]->serit_id==0)
			{
				araclar[id]->solX=180*3.75;
				araclar[id]->solY=53*3.75;
				araclar[id]->yon=2;
				araclar[id]->yol_id=7;
				araclar[id]->serit_id=0;
				yol7[1][0]=false;
				araclar[id]->hc_id=90;
				
			}
			if(araclar[id]->hc_id==1 && araclar[id]->serit_id==1)
			{
				araclar[id]->solX=180*3.75;
				araclar[id]->solY=52*3.75;
				araclar[id]->yon=2;
				araclar[id]->yol_id=7;
				araclar[id]->serit_id=1;
				yol7[1][1]=false;
				araclar[id]->hc_id=90;
				
			}
			if(araclar[id]->hc_id==1 && araclar[id]->serit_id==2)//yol7&serit2(çýkýþ)
			{
				araclar[id]->solX=180*3.75;
				araclar[id]->solY=51*3.75;
				araclar[id]->yon=2;
				araclar[id]->yol_id=7;
				araclar[id]->serit_id=2;
				yol7[1][2]=false;
				araclar[id]->hc_id=90;
			}
			
		}//end of YOL7
		//////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////////////////////////
        ////YOL8
		if(araclar[id]->yol_id==8 )
		{		int idx=araclar[id]->hc_id;
		

				int vmax;
				//yol8(Bölünmüþ ana yol) için max. hýzlar
				if(araclar[id]->a_tipi==0)
					vmax=4;//otomobil vmax=108km/sa
				else if(araclar[id]->a_tipi==1)
					vmax=2;//týr vmax=54km/sa
				else if (araclar[id]->serit_id==0)
					vmax=1;
					
				else 
					vmax=3;//kamyon,kamyonet,otobüs vmax=81km/sa
				//Nagel-Sch. Modeli

				//Adým 1: Hýzlanma(Acceleration)
				if(araclar[id]->hiz < vmax)
					araclar[id]->hiz++;
				cout<<araclar[id]->hiz<<endl;

				//Adým 2: Yavaþlama (Braking)
				araclar[id]->hiz=minimum(araclar[id]->hiz,getForwardGap(araclar[id]->yol_id,araclar[id]->serit_id,araclar[id]->hc_id,araclar[id]->a_tipi));
				
				//Adým 3: Random Braking
				float x=float(rand())/RAND_MAX;
				cout<<x<<endl;
				if(x<=RBP)
					{
						araclar[id]->hiz=maximum(0,araclar[id]->hiz-1);
						
					}
				////Adým 4:Move(aþaðýda kodlarý mevcut)

				////ýþýklara yaklaþýnca yavaþla
				
				if(araclar[id]->hc_id>=60 )
					araclar[id]->hiz=1;

			//araç tipi týr ya da otobüs ise(yani 2 hc. kaplýyorsa)
			if(araclar[id]->a_tipi==3 || araclar[id]->a_tipi==1)
			{
				//ýþýklara kadar devam et
				if(araclar[id]->hc_id+1<=67 && yol8[idx+2][serit_id]==false )
				 {
							araclar[id]->solX+=(araclar[id]->hiz*7.5);
							yol8[idx+araclar[id]->hiz][araclar[id]->serit_id]=true;
							yol8[idx+araclar[id]->hiz+1][araclar[id]->serit_id]=true;

							yol8[idx][araclar[id]->serit_id]=false;
							yol8[idx+araclar[id]->hiz-1][araclar[id]->serit_id]=false;
							araclar[id]->hc_id+=(araclar[id]->hiz);
				 }
		
				
				//kýrmýzý yandý,dur
				if(TrafficLight[2]==0 && araclar[id]->hc_id+1==68)
				 {
					 araclar[id]->solX+=(araclar[id]->hiz*0.f);
				 }
				 //yeþil yandý, geç
				 if(TrafficLight[2]==2 && araclar[id]->hc_id+1==68 && yol8[idx+2][serit_id]==false)
				 {
							araclar[id]->solX+=(araclar[id]->hiz*7.5);
							yol8[idx+araclar[id]->hiz][araclar[id]->serit_id]=true;
							yol8[idx][araclar[id]->serit_id]=false;
							araclar[id]->hc_id+=(araclar[id]->hiz);
				 }
				 //ýþýklarý geçtikten sonra durma ,devam et
				 if(araclar[id]->hc_id>=69 && yol8[idx+1][serit_id]==false)
				 {					
							araclar[id]->solX+=(araclar[id]->hiz*7.5);
							yol8[idx+araclar[id]->hiz][araclar[id]->serit_id]=true;
							yol8[idx][araclar[id]->serit_id]=false;
							araclar[id]->hc_id+=(araclar[id]->hiz);
				 }
			
			
			}
			else
				//ýþýklara kadar devam et
				if(araclar[id]->hc_id<=67 && yol8[idx+1][serit_id]==false )
				 {
							araclar[id]->solX+=(araclar[id]->hiz*7.5);
							yol8[idx+araclar[id]->hiz][araclar[id]->serit_id]=true;
							yol8[idx][araclar[id]->serit_id]=false;
							araclar[id]->hc_id+=(araclar[id]->hiz);
				 }
		
				//kýrmýzý yandý,dur
				if(TrafficLight[2]==0 && araclar[id]->hc_id==68)
				 {
					 araclar[id]->solX+=(araclar[id]->hiz*0.f);
				 }
				 //yeþil yandý, geç
				 if(TrafficLight[2]==2 && araclar[id]->hc_id==68 && yol8[idx+1][serit_id]==false)
				 {
							araclar[id]->solX+=(araclar[id]->hiz*7.5);
							yol8[idx+araclar[id]->hiz][araclar[id]->serit_id]=true;
							yol8[idx][araclar[id]->serit_id]=false;
							araclar[id]->hc_id+=(araclar[id]->hiz);
				 }
				 //ýþýklarý geçtikten sonra durma ,devam et
				 if(araclar[id]->hc_id>=69 && yol8[idx+1][serit_id]==false)
				 {					
							araclar[id]->solX+=(araclar[id]->hiz*7.5);
							yol8[idx+araclar[id]->hiz][araclar[id]->serit_id]=true;
							yol8[idx][araclar[id]->serit_id]=false;
							araclar[id]->hc_id+=(araclar[id]->hiz);
				 }
				 //////////////////////////////////////////////////////////////////////////////////////////////

				 if(araclar[id]->serit_id==0 && araclar[id]->hc_id==18)
				 {
					int tempYon=rand()%2+1;

					if (tempYon==1)
					{
						yon=1;
					}
					else
					{
						if(yol3[20][1]==false )
						{
							araclar[id]->solX=36*3.75;
							araclar[id]->solY=46*3.75;
							araclar[id]->yon=4;
							araclar[id]->serit_id=1;
							araclar[id]->yol_id=3;
							araclar[id]->hc_id=20;
							yol8[18][0]=false;
						}
					} 
				 }
				  
				   if(araclar[id]->serit_id==0 && araclar[id]->hc_id==43)
				 {
					int tempYon=rand()%2+1;

					if (tempYon==1)
					{
						yon=1;
					}
					else
					{
						if(kol3[0]==false )
						{
							araclar[id]->solX=86*3.75;
							araclar[id]->solY=45*3.75;
							araclar[id]->yon=6;
							
							araclar[id]->yol_id=103;
							araclar[id]->hc_id=0;
							yol8[43][0]=false;
						}
					} 
				 }
				  if(araclar[id]->serit_id==0 && araclar[id]->hc_id==67)
				 {
					
						if(kol2_3[0]==false )
						{
							araclar[id]->solX=134*3.75;
							araclar[id]->solY=45*3.75;
							araclar[id]->yon=6;
							
							araclar[id]->yol_id=203;
							araclar[id]->hc_id=0;
							yol8[67][0]=false;
						}
				 } 
				 
			//haritadan çýkýþlar
			if(araclar[id]->hc_id==90 && araclar[id]->serit_id==0)//yol8&serit0(çýkýþ)
			{
				araclar[id]->solX=0*3.75;
				araclar[id]->solY=46*3.75;
				araclar[id]->yon=1;
				araclar[id]->yol_id=8;
				araclar[id]->serit_id=0;
				yol8[90][0]=false;
				araclar[id]->hc_id=1;
			}

			if(araclar[id]->hc_id==90 && araclar[id]->serit_id==1)
			{
				araclar[id]->solX=0*3.75;
				araclar[id]->solY=47*3.75;
				araclar[id]->yon=1;
				araclar[id]->yol_id=8;
				araclar[id]->serit_id=1;
				yol8[90][1]=false;
				araclar[id]->hc_id=1;
				
			}
			if(araclar[id]->hc_id==90 && araclar[id]->serit_id==2)//yol8&serit2(çýkýþ)
			{
				araclar[id]->solX=0*3.75;
				araclar[id]->solY=48*3.75;
				araclar[id]->yon=1;
				araclar[id]->yol_id=8;
				araclar[id]->serit_id=2;
				yol8[90][2]=false;
				araclar[id]->hc_id=1;
			}
			
		}//end  of YOL8

		///////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////
		//YOL9
		if(araclar[id]->yol_id==9 )
		{
			int idx=araclar[id]->hc_id;
			//þerit 1- þerit sonuna kadar ilerle
			if(araclar[id]->serit_id==1 )
			{
				
				if(yol9[idx-1][1]==false)
				{   
					araclar[id]->solY-=7.5;
					yol9[idx-1][1]=true;
					yol9[idx][1]=false;
					araclar[id]->hc_id--;
				}
				
				if(araclar[id]->hc_id==0 && yol2[69][1]==false)//gideceði hücre boþ mu?
					{
						//saða dön---->yol2
						
						araclar[id]->solX=136*3.75f;
						araclar[id]->solY=6*3.75;
						araclar[id]->yon=2;
						araclar[id]->yol_id=2;
						araclar[id]->serit_id=1;
						yol9[0][1]=false;
						araclar[id]->hc_id=69;

					}
			} //serit1 sonu

			
			//yol9 yukarý yönde ilerle
			if(araclar[id]->serit_id==0 && araclar[id]->yon==3)
			{
				
				if(yol9[idx+1][0]==false)
				{   
					araclar[id]->solY+=7.5;
					yol9[idx+1][0]=true;
					yol9[idx][0]=false;
					araclar[id]->hc_id++;
				}
				if(araclar[id]->hc_id==19 && araclar[id]->serit_id==0)
				{
						araclar[id]->solX=141*3.75f;
						araclar[id]->solY=41*3.75;
						araclar[id]->yon=5;
						araclar[id]->yol_id=204;
						araclar[id]->serit_id=1;
						araclar[id]->hc_id=0;
						yol9[19][0]=false;
				}
			}
			
			
			
					
		}//end of YOL9
		///////////////////////////////////////////////////////////////////////////////
		//YOL10
		if(araclar[id]->yol_id==10 )
		{
			int idx=araclar[id]->hc_id;
			//serit0 ----->yon 3(yani yukarý)
			if(araclar[id]->serit_id==0)
			{
				//ýþýklara kadar devam et
				if(araclar[id]->hc_id<=19 && yol10[idx+1][0]==false )
				 {
							araclar[id]->solY+=(araclar[id]->hiz*7.5);
							yol10[idx+araclar[id]->hiz][araclar[id]->serit_id]=true;
							yol10[idx][araclar[id]->serit_id]=false;
							araclar[id]->hc_id+=(araclar[id]->hiz);
				 }
		
				//kýrmýzý yandý,dur
				if(TrafficLight[1]==0 && araclar[id]->hc_id==20)
				 {
					 araclar[id]->solY+=(araclar[id]->hiz*0.f);
				 }
				 //yeþil yandý, geç
				 if(TrafficLight[1]==2 && araclar[id]->hc_id==20 && yol10[idx+1][serit_id]==false)
				 {
							araclar[id]->solY+=(araclar[id]->hiz*7.5);
							yol10[idx+araclar[id]->hiz][araclar[id]->serit_id]=true;
							yol10[idx][araclar[id]->serit_id]=false;
							araclar[id]->hc_id+=(araclar[id]->hiz);
				 }
				 //ýþýklarý geçtikten sonra durma ,devam et
				 if(araclar[id]->hc_id>=21 && yol10[idx+1][serit_id]==false)
				 {					
							araclar[id]->solY+=(araclar[id]->hiz*7.5);
							yol10[idx+araclar[id]->hiz][araclar[id]->serit_id]=true;
							yol10[idx][araclar[id]->serit_id]=false;
							araclar[id]->hc_id+=(araclar[id]->hiz);
				 }

				//yol10-serit0 sonu----->yol2'ye dön
				if(araclar[id]->hc_id== 42)
				{
					
					araclar[id]->solX=0.f;
					araclar[id]->solY=4*3.75;
					araclar[id]->yol_id=2;
					araclar[id]->serit_id=0;
					araclar[id]->hc_id=1;
					yol10[42][0]=false;
					yol2[1][0]=true;
					araclar[id]->yon=1;
				}
			
			}
			//serit1----->yon4 (yani aþaðý yönde)
			if(araclar[id]->serit_id==1)
			{
				//ýþýklara kadar devam et
				if(araclar[id]->hc_id>=25 && yol10[idx-1][araclar[id]->serit_id]==false )
				 {
							araclar[id]->solY-=(araclar[id]->hiz*7.5);
							yol10[idx-araclar[id]->hiz][araclar[id]->serit_id]=true;
							yol10[idx][araclar[id]->serit_id]=false;
							araclar[id]->hc_id-=(araclar[id]->hiz);
				 }
		
				//kýrmýzý yandý,dur
				if(TrafficLight[3]==0 && araclar[id]->hc_id==24)
				 {
					 araclar[id]->solY-=(araclar[id]->hiz*0.f);
				 }
				 //yeþil yandý, geç
				 if(TrafficLight[3]==2 && araclar[id]->hc_id==24 && yol10[idx-1][araclar[id]->serit_id]==false)
				 {
							araclar[id]->solY-=(araclar[id]->hiz*7.5);
							yol10[idx-araclar[id]->hiz][araclar[id]->serit_id]=true;
							yol10[idx][araclar[id]->serit_id]=false;
							araclar[id]->hc_id-=(araclar[id]->hiz);
				 }
				 //ýþýklarý geçtikten sonra durma ,devam et
				 if(araclar[id]->hc_id<=23 && yol10[idx-1][serit_id]==false)
				 {					
							araclar[id]->solY-=(araclar[id]->hiz*7.5);
							yol10[idx-araclar[id]->hiz][araclar[id]->serit_id]=true;
							yol10[idx][araclar[id]->serit_id]=false;
							araclar[id]->hc_id-=(araclar[id]->hiz);
				 }

				//yol10-serit0 sonu----->yol2'ye dön
				if(araclar[id]->hc_id== 0)
				{
					
					araclar[id]->solX=136*3.75f;
					araclar[id]->solY=6*3.75;
					araclar[id]->yol_id=2;
					araclar[id]->serit_id=1;
					araclar[id]->hc_id=68;
					yol10[0][1]=false;
					yol2[68][1]=true;
					araclar[id]->yon=2;
				}
			}

		}//end of YOL10
		/////////////////////////////////////
		
		////////////////////////////////////////////////////////
		////----------------ÇAPRAZ YOLLAR----------------------
		if(araclar[id]->yol_id==104)
		{
			int idx=araclar[id]->hc_id;
			//kavþak noktasýna kadar ilerle
			
				if(kol4[idx+1]==false)
				{   
					araclar[id]->solX+=7.5;
					araclar[id]->solY+=7.5;
					kol4[idx+1]=true;
					kol4[idx]=false;
					araclar[id]->hc_id++;
				}
				if(araclar[id]->hc_id==5)
				{
					araclar[id]->solX=108*3.75;
					araclar[id]->solY=46*3.75;
					araclar[id]->serit_id=0;
					araclar[id]->yol_id=8;
					araclar[id]->hc_id=54;
					araclar[id]->yon=1;
					kol4[5]=false;
					yol8[54][0]=true;
				}
			
		}
		//////////////////////////////
		if(araclar[id]->yol_id==103)
		{
			int idx=araclar[id]->hc_id;
			//kavþak noktasýna kadar ilerle
			
				if(kol3[idx+1]==false)
				{   
					araclar[id]->solX+=7.5;
					araclar[id]->solY-=7.5;
					kol3[idx+1]=true;
					kol3[idx]=false;
					araclar[id]->hc_id++;
				}
				if(araclar[id]->hc_id==5)
				{
					araclar[id]->solX=94*3.75;
					araclar[id]->solY=36*3.75;
					araclar[id]->serit_id=1;
					araclar[id]->yol_id=52;
					araclar[id]->hc_id=15;
					araclar[id]->yon=4;
					kol3[5]=false;
					yol52[15][0]=true;
				}
			
		}


		//çapraz yol 204
		if(araclar[id]->yol_id==204)
		{
			int idx=araclar[id]->hc_id;
			//kavþak noktasýna kadar ilerle
			
				if(kol2_4[idx+1]==false)
				{   
					araclar[id]->solX+=7.5;
					araclar[id]->solY+=7.5;
					kol2_4[idx+1]=true;
					kol2_4[idx]=false;
					araclar[id]->hc_id++;
				}

				if(araclar[id]->hc_id==3)
				{
					araclar[id]->solX=148*3.75;
					araclar[id]->solY=46*3.75;
					araclar[id]->serit_id=0;
					araclar[id]->yol_id=8;
					araclar[id]->hc_id=74;
					araclar[id]->yon=1;
					kol2_4[3]=false;
					yol8[74][0]=true;
				}
			
		}
		//çapraz yol 203
		if(araclar[id]->yol_id==203)
		{
			int idx=araclar[id]->hc_id;
			//kavþak noktasýna kadar ilerle
			
				if(kol2_3[idx+1]==false)
				{   
					araclar[id]->solX+=7.5;
					araclar[id]->solY-=7.5;
					kol2_3[idx+1]=true;
					kol2_3[idx]=false;
					araclar[id]->hc_id++;
				}

				if(araclar[id]->hc_id==2)
				{
					araclar[id]->solX=137*3.75;
					araclar[id]->solY=42*3.75;
					araclar[id]->serit_id=1;
					araclar[id]->yol_id=9;
					araclar[id]->hc_id=18;
					araclar[id]->yon=4;
					kol2_3[2]=false;
					yol9[18][1]=true;
				}
			
		}
		//çapraz yol 202
		if(araclar[id]->yol_id==202)
		{
			int idx=araclar[id]->hc_id;
			//kavþak noktasýna kadar ilerle
			
				if(kol2_2[idx+1]==false)
				{   
					araclar[id]->solX-=7.5;
					araclar[id]->solY+=7.5;
					kol2_2[idx+1]=true;
					kol2_2[idx]=false;
					araclar[id]->hc_id++;
				}

				if(araclar[id]->hc_id==3 )
				{
					araclar[id]->solX=141*3.75;
					araclar[id]->solY=58*3.75;
					araclar[id]->serit_id=0;
					araclar[id]->yol_id=10;
					araclar[id]->hc_id=27;
					araclar[id]->yon=3;
					kol2_2[3]=false;
					yol10[27][0]=true;
				}
			
		}
		////////////////
		if(araclar[id]->yol_id==201)
		{
			int idx=araclar[id]->hc_id;
			//kavþak noktasýna kadar ilerle
			
				if(kol2_1[idx+1]==false)
				{   
					araclar[id]->solX-=7.5;
					araclar[id]->solY-=7.5;
					kol2_1[idx+1]=true;
					kol2_1[idx]=false;
					araclar[id]->hc_id++;
				}
				if(araclar[id]->hc_id==3)
				{
					araclar[id]->solX=133*3.75;
					araclar[id]->solY=52*3.75;
					araclar[id]->serit_id=0;
					araclar[id]->yol_id=7;
					araclar[id]->hc_id=67;
					araclar[id]->yon=2;
					kol2_1[5]=false;
					yol8[54][0]=true;
				}
			
		}



}//end of Update()

///////////////////////////////////////////////////
void Initial()
{   
	for(int id=0;id<arac_sayisi;id++)
	{
		araclar[id]=new ARAC(arac_dizisi[id][0],arac_dizisi[id][1],arac_dizisi[id][2],arac_dizisi[id][3],arac_dizisi[id][4],arac_dizisi[id][5],arac_dizisi[id][6],arac_dizisi[id][7]);
		HucreDoldur(araclar[id]->yol_id,araclar[id]->serit_id,araclar[id]->hc_id,araclar[id]->a_tipi);
		
	}//end of for

}//end of initial()
///////////////////////////////////////////////////
void waitAndRedraw(int deger)
{  if(animate)
	{
		TL_Time_Depend();
	
		//-------------------->TIMER<---------------------
		clock_t t; 
		t = clock();
		for(int id=0;id<arac_sayisi;id++)
		{
			araclar[id]->Update(id);
		}
		t = clock() - t; 
		double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
		totalUpdateTime+=time_taken;
		printf("Function took %lf seconds to execute \n", totalUpdateTime);
	}
		glutPostRedisplay();
		glutTimerFunc(WAIT,waitAndRedraw,1); 
}
////////////////////////////////////////////////////
void RenderScene(void)
{   
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	
	Harita();
	if(hucreToggle)
		Grid();
	glPopMatrix();
	for(int i=0;i<arac_sayisi;i++)
	{   
		araclar[i]->AracCiz();
	}
	glutSwapBuffers();
}
///////////////////////////////////////////////////
int main(int argc, char* argv[])
    {    

		  
		  Initial();
          glutInit(&argc, argv);
		  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH );
		  glutInitWindowPosition(0,0);
		  glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
          glutCreateWindow("Hücresel Otomatlar Trafik Simülasyonu(CPU)");
          glutReshapeFunc(ChangeSize);
		  glutTimerFunc(WAIT,waitAndRedraw,1);   
          glutDisplayFunc(RenderScene);
		  glutKeyboardFunc(keyboard);
		  glutMouseFunc(mouse);
          initMenus();
          SetupRC();
          glutMainLoop();
          return 0;
    }
