// includes, system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <windows.h>

// OpenGL Graphics includes
#include <GL/glew.h>

//#include <GL/freeglut.h>
#include <GL/glut.h>

// includes, cuda
#include <cuda_runtime.h>
#include <cuda_gl_interop.h>

// Utilities and timing functions
#include <helper_functions.h>    // includes cuda.h and cuda_runtime_api.h
#include <timer.h>               // timing functions

// CUDA helper functions
#include <helper_cuda.h>         // helper functions for CUDA error check
#include <helper_cuda_gl.h>      // helper functions for CUDA/GL interop

//threadIdx vs. için
#include "device_launch_parameters.h"

#include "arac.h"
#include "main.h"
#include "Harita.h"



//render fonksiyonlarý

void RenderScene();
void waitAndRedraw(int deger);

//CUDA fonksiyonlarý
void launch_kernel_Update(); //kernel çaðýran fonksiyon


////////////////////////////////////////////////////////////


ARAC *araclar[arac_sayisi];



float RBP=0.03;
float toplam=0.f;







////////////////////////////////////////////////////////////
float SOLX[arac_sayisi];
float SOLY[arac_sayisi];
int TIP[arac_sayisi];
int HIZ[arac_sayisi];
int YON[arac_sayisi];
int YOLID[arac_sayisi];
int SERITID[arac_sayisi];
int HCID[arac_sayisi];

////////////////////////////////////////////////////////////


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
			yol1[count][s_id]=1;
			count++;
		}
	}
	if(y_id==2)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol2[count][s_id]=1;
			count++;
		}
	}
		if(y_id==3)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol3[count][s_id]=1;
			count++;
		}
	}
	if(y_id==5)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol5[count][s_id]=1;
			count++;
		}
	}

	if(y_id==7)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol7[count][s_id]=1;
			count++;
		}
		
	}
	if(y_id==8)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol8[count][s_id]=1;
			count++;
		}
	}
	if(y_id==9)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol9[count][s_id]=1;
			count++;
		}
	}
	if(y_id==10)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol10[count][s_id]=1;
			count++;
		}
	}
	
	if(y_id==52)
	{
		for(int j=0;j<kap_hc_say;j++)
		{
			yol52[count][s_id]=1;
			count++;
		}
	}
	
}
///////////////////////////

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
		
		while(  yol8[h_id+count][s_id]==0 && h_id+count<90)
		{
			
			count++;
			gap++;
			
			
		}
		
		
		return gap;
	}

	
}
///////////////////////////////////////////////////
__global__ void kernel(float *sx,float *sy,int *tip, int *hiz,int *yon,int *yolID,int *srtID,int *hcID,int *yol1,int *yol2,int *yol3,int *yol5, int *yol52, int *yol7 ,int *yol8,int *yol9,int* yol10, int *TrafficLight,int *kol1,int *kol2, int *kol3, int* kol4,int *kol2_1,int *kol2_2,int *kol2_3, int *kol2_4)
{
	int id=threadIdx.x + blockIdx.x * blockDim.x;
	
	/////////////////////////////////////////
	////YOL1
		if(yolID[id]==1 )//yol1 mi?
		{
			int hdx=hcID[id];
			int sdx=srtID[id];
			int serit_sayi=2;
			int idx=hdx*serit_sayi+sdx;

			//kavþak noktasýna kadar ilerle
			if(sdx==0 && yon[id]==1)
			{
				
				if(yol1[idx+serit_sayi]==0)
				{   
					sx[id]+=7.5;
					yol1[idx+serit_sayi]=1;
					yol1[idx]=0;
					hcID[id]++;
				}
			}
			////saða döndükten sonra aþaðý yönde ilerle
			if(sdx==0 && yon[id]==4)
			{
				if(yol1[idx+1*serit_sayi]==0)
				{   
					sy[id]-=7.5;
					yol1[idx+1*serit_sayi]=1;
					yol1[idx]=0;
					hcID[id]++;
				}
			}
			//yol1-þerit1-yön 3(yukarý gidiþ)
			if(sdx==1 && yon[id]==3)
			{
				if(yol1[idx-1*serit_sayi]==0)
				{   
					sy[id]+=7.5;
					yol1[idx-1*serit_sayi]=1;
					yol1[idx]=0;
					hcID[id]--;
				}
			}
			////yol1-þerit1-sola dönüþ
			if(hdx==19 && sdx==1 ){
					sx[id]=36*3.75f;
					sy[id]=85*3.75;
					yon[id]=2;
					yolID[id]=1;
					srtID[id]=1;
					hcID[id]=18;
					yol1[19*serit_sayi+1]=0;
					
					
			}
			////þerit 1--->çýkýþ noktasýna kadar ilerle
			if(sdx==1 && yon[id]==2)
			{
				
				if(yol1[idx-1*serit_sayi]==0)
				{   
					sx[id]-=7.5;
					yol1[idx-1*serit_sayi]=1;
					yol1[idx]=0;
					hcID[id]--;
				}
			}
			////yol1-þerit1-haritadan çýkýþ--->yol5 giriþ
			if(hdx==0 && sdx==1 )// hedef hc boþ mu?
			{
					sx[id]=95*3.75f;
					sy[id]=91*3.75;
					yon[id]=4;
					yolID[id]=5;
					srtID[id]=0;
					yol1[0*serit_sayi+1]=0;
					hcID[id]=1;
					
					
			}
			////yol1&serit0(saða dönüþ)
			if(hdx==19 && sdx==0 )// gideceði hc. boþ mu?
			{
					sx[id]=36*3.75f;
					sy[id]=83*3.75;
					yon[id]=4;
					yolID[id]=1;
					srtID[id]=0;
					hcID[id]=20;
					yol1[19*serit_sayi+0]=0;
			}
			////yol1&serit0(saða dönüþ-otoyola çýkýþ)
			if(hdx==34 && sdx==0 && yol7[18*serit_sayi+0]==0) //hedef hc boþ mu?
			{
					sx[id]=38*3.75f;
					sy[id]=53*3.75;
					yon[id]=2;
					yolID[id]=7;
					srtID[id]=0;
					yol1[34*serit_sayi+0]=0;
					hcID[id]=18;
			}
		
		}//end of YOL1
	////////////////////////////////////////////////////////////////////////////////////////////
		//YOL2
	if(yolID[id]==2 )
		{
			int hdx=hcID[id];
			int sdx=srtID[id];
			int serit_sayi=2;
			int idx=hdx*serit_sayi+sdx;

			//kavþak noktasýna kadar ilerle
			if(sdx==0 && yon[id]==1)
			{
				
				if(yol2[idx+1*serit_sayi]==0)
				{   
					sx[id]+=7.5;
					yol2[idx+1*serit_sayi]=1;
					yol2[idx]=0;
					hcID[id]++;
				}
			}
			//þerit 1 yön 2
			if(sdx==1 && yon[id]==2)
			{
				
				if(yol2[idx-1*serit_sayi]==0)
				{   
					sx[id]-=7.5;
					yol2[idx-1*serit_sayi]=1;
					yol2[idx]=0;
					hcID[id]--;
				}
			}
			//þerit 2 yol sonu(baþladýðý konuma geri dönecek)
			if(sdx==1 && hcID[id]==0)
			{
					sx[id]=138*3.75;
					sy[id]=90*3.75;
					yon[id]=4;
					yolID[id]=10;
					srtID[id]=1;
					yol2[0*serit_sayi+1]=0;
					hcID[id]=42;
			}

			//yol2 sonuna gelindi, yukarý dönecek
			if(sdx==0 && hcID[id]==72 )
			{
				
						if(yol10[1*serit_sayi+0]==0)
						{
							sx[id]=141*3.75;
							sy[id]=6*3.75;
							yon[id]=3;
							srtID[id]=0;
							yolID[id]=10;
							hcID[id]=1;
							yol2[72*serit_sayi+0]=0;
					    }
			}	
			
			
			
		}//end of YOL2
	
		////////////////////////////////////////////////////////////////////////////////////////////
		//YOL3
		if(yolID[id]==3 )
		{
			int hdx=hcID[id];
			int sdx=srtID[id];
			int serit_sayi=2,
			int idx=hdx*serit_sayi+sdx;

			//kavþak noktasýna kadar ilerle
			if(sdx==0 && yon[id]==3)
			{
				
				if(yol3[idx+1*serit_sayi]==0)
				{   
					sy[id]+=7.5;
					yol3[idx+1*serit_sayi]=1;
					yol3[idx]=0;
					hcID[id]++;
				}
			}

			
			//yol3 sonuna gelindi, saða dönecek--->YOL8
			if(sdx==0 && hdx==20)
			{
				sx[id]=38*3.75;
				sy[id]=46*3.75;
				yon[id]=1;
				srtID[id]=0;
				yolID[id]=8;
				yol3[20*serit_sayi+0]=0;
				hcID[id]=20;//yol8'un 19.hücresi
				yol8[20*serit_sayi+0]=true;
				
			}
			//yol3 þerit1 aþaðý yönde ilerle
			if(sdx==1 && yon[id]==4)
			{
				
				if(yol3[idx-1*serit_sayi]==0)
				{   
					sy[id]-=7.5;
					yol3[idx-1*serit_sayi]=1;
					yol3[idx]=0;
					hcID[id]--;
				}
			}
			//yol3---->yol2 geçiþ saða dönüþ
			if(sdx==1 && hcID[id]==0)
			{
				sx[id]=36*3.75;
				sy[id]=6*3.75;
				yon[id]=2;
				srtID[id]=1;
				yolID[id]=2;
				yol3[0*serit_sayi+1]=0;
				hcID[id]=18;
			}
		}//end of YOL3

		////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////
		//YOL5
		if(yolID[id]==5 )
		{
			int hdx=hcID[id];
			int sdx=srtID[id];
			int serit_sayi=2;
			int idx=hdx*serit_sayi+sdx;

			//kavþak noktasýna kadar ilerle
			if(sdx==0 && yon[id]==4)
			{
				
				if(yol5[idx+1*serit_sayi]==0)
				{   
					sy[id]-=7.5;
					yol5[idx+1*serit_sayi]=1;
					yol5[idx]=0;
					hcID[id]++;
				}

				if(hdx>=19 && hdx<25)
				{
					sx[id]=1500.f;
					yol5[20*serit_sayi+0]=0;
					hcID[id]++;
				}
				if(hdx==25)
				{
					sx[id]=95*3.75;
					sy[id]=46*3.75;
					
				}
				//yol2'ye dönüþ
				
				if(hdx==42   )
				{
					
						sx[id]=94*3.75;
						sy[id]=6*3.75;
						yolID[id]=2;
						srtID[id]=1,
						hcID[id]=48;
						yol2[48*serit_sayi+1]=1;
						yol5[43*serit_sayi+0]=0;
						yon[id]=2;
					
				}
				
			}
			if(sdx==1 && yon[id]==3)
			{
				
				if(yol5[idx-1*serit_sayi]==0)
				{   
					sy[id]+=7.5;
					yol5[idx-1*serit_sayi]=1;
					yol5[idx]=0;
					hcID[id]--;
				}

				if(hdx<=23 && hdx>19)
				{
					sx[id]=1500.f;
					yol5[22*serit_sayi+1]=0;
					hcID[id]--;
				}
				if(hdx==19)
				{
					sx[id]=97*3.75;
					sy[id]=53*3.75;
					
					
				}
				//yol5------------>çýkýþ
				if(sdx==1 && hdx==0)
				{
					//yol1 serit0'a gönder
					sx[id]=0*3.75;
					sy[id]=83*3.75;
					yolID[id]=1;
					srtID[id]=0;
					hcID[id]=1;
					yon[id]=1;
					yol1[1*serit_sayi+0]=1;
					yol5[0*serit_sayi+1]=0;
				}
			}
			
		
			

			
			
		}//end of YOL5
		////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////
		//YOL52
		if(yolID[id]==52 )
		{
			int hdx=hcID[id];
			int sdx=srtID[id];
			int serit_sayi=2;
			int idx=hdx*serit_sayi+sdx;
			//þerit 1- þerit sonuna kadar ilerle
			if(sdx==1 && yon[id]==4)
			{
				
				if(yol52[idx-1*serit_sayi]==0)
				{   
					sy[id]-=7.5;
					yol52[idx-1*serit_sayi]=1;
					yol52[idx]=0;
					hcID[id]--;
				}
			}
			//yol52 yukarý yönde ilerle
			if(sdx==0 && yon[id]==3)
			{
				
				if(yol52[idx+1*serit_sayi]==0)
				{   
					sy[id]+=7.5;
					yol52[idx+1*serit_sayi]=1;
					yol52[idx]=0;
					hcID[id]++;
				}
			}
			
			if(hdx==0 && yol2[47*serit_sayi+1]==0)//gideceði hücre boþ mu?
					{
						//saða dön---->yol2
						sx[id]=94*3.75f;
						sy[id]=6*3.75;
						yon[id]=2;
						yolID[id]=2;
						srtID[id]=1;
						yol52[0*serit_sayi+1]=0;
						hcID[id]=47;

					}
			//çapraz yol(5 yönünde)
			if(hdx==15 && sdx==0)
					{
						
						sx[id]=98*3.75f;
						sy[id]=37*3.75;
						yon[id]=5;
						yolID[id]=104;
						srtID[id]=1;
						hcID[id]=0;
						yol52[idx]=0;
					}
					
		}//end of YOL52
		///////////////////////////////////////////////////////////////
		//YOL7
	if(yolID[id]==7)
	{
		int hdx=hcID[id];
		int sdx=srtID[id];
		int serit_sayi=3;
		if(tip[id]==0 || tip[id]==2 || tip[id]==4)
				{
					//ýþýklara kadar devam et
					if(hdx>72 && yol7[hdx*serit_sayi+sdx-serit_sayi]==0 )
					 {
							sx[id]-=7.5;
							yol7[hdx*serit_sayi+sdx-serit_sayi*hiz[id]]=1;
							yol7[hdx*serit_sayi+sdx]=0;
							hcID[id]--;
					 }
				}
			//	//kýrmýzý yandý,dur
				if(TrafficLight[0]==0 && hdx==72)
				 {
					 sx[id]-=(hiz[id]*0.f);
				 }
			//	 //yeþil yandý, geç
				if(TrafficLight[0]==2 && hdx==72 && yol7[hdx*serit_sayi+sdx-serit_sayi]==0)
				 {
							sx[id]-=7.5;
							yol7[hdx*serit_sayi+sdx-serit_sayi*hiz[id]]=1;
							yol7[hdx*serit_sayi+sdx]=0;
							hcID[id]--;
				 }
			//	 //ýþýklarý geçtikten sonra durma ,devam et
				if(hdx<=71 && yol7[hdx*serit_sayi+sdx-serit_sayi]==0)
				 {					
							
							sx[id]-=7.5;
							yol7[hdx*serit_sayi+sdx-serit_sayi*hiz[id]]=1;
							yol7[hdx*serit_sayi+sdx]=0;
							hcID[id]--;
				 }

				//çapraz yol
				 if(sdx==0 && hdx==73)
				 {
						sx[id]=146.5*3.75f;
						sy[id]=52*3.75;
						yon[id]=8;
						yolID[id]=202;
						srtID[id]=1;
						hcID[id]=0;
						yol7[73*3+0]=0;

				 }
				//haritadan çýkýþlar
			if(hdx==1 && sdx==0)
			{
				sx[id]=180*3.75;
				sy[id]=53*3.75;
				yon[id]=2;
				yolID[id]=7;
				srtID[id]=0;
				yol7[1*serit_sayi+0]=0;
				hcID[id]=90;
				
			}
			if(hdx==1 && sdx==1)
			{
				sx[id]=180*3.75;
				sy[id]=52*3.75;
				yon[id]=2;
				yolID[id]=7;
				srtID[id]=1;
				yol7[1*serit_sayi+1]=0;
				hcID[id]=90;
				
			}
			if(hdx==1 && sdx==2)//yol7&serit2(çýkýþ)
			{
				sx[id]=180*3.75;
				sy[id]=51*3.75;
				yon[id]=2;
				yolID[id]=7;
				srtID[id]=2;
				yol7[1*serit_sayi+2]=0;
				hcID[id]=90;
			}


	}
	/////////////////////////////////////////
	if(yolID[id]== 8 )
		{		
			int hdx=hcID[id];
			int sdx=srtID[id];
			int serit_sayi=3;
			int idx=hdx*serit_sayi+sdx;
			//int vmax;
			//	//yol8(Bölünmüþ ana yol) için max. hýzlar
			//	if(tip[id]==0)
			//		vmax=4;//otomobil vmax=108km/sa
			//	else if(tip[id]==1)
			//		vmax=2;//týr vmax=54km/sa
			//	else if (srtID[id]==0)
			//		vmax=1;
			//		
			//	else 
			//		vmax=3;//kamyon,kamyonet,otobüs vmax=81km/sa
			//	//Nagel-Sch. Modeli

			//	//Adým 1: Hýzlanma(Acceleration)
			//	if(hiz[id] < vmax)
			//		hiz[id]++;
			//	

			//	//Adým 2: Yavaþlama (Braking)
			//	//hiz[id]=minimum(hiz[id],getForwardGap(yolID[id],srtID[id],hcID[id],tip[id]));
			//	
			//	////Adým 3: Random Braking
			//	//float x=float(rand())/RAND_MAX;
			//
			//	//if(x<=RBP)
			//	//	{
			//	//		araclar[id]->hiz=maximum(0,araclar[id]->hiz-1);
			//	//		
			//	//	}
			//	////Adým 4:Move(aþaðýda kodlarý mevcut)

			//	////ýþýklara yaklaþýnca yavaþla
			//	
			//	if(hcID[id]>=60 )
			//		hiz[id]=1;

			////araç tipi týr ya da otobüs ise(yani 2 hc. kaplýyorsa)
				if(tip[id]==3 || tip[id]==1)
			    {
				//ýþýklara kadar devam et
				if(hdx+serit_sayi<=67 && yol8[idx+serit_sayi*2]==0 )
				 {
							sx[id]+=7.5;
							yol8[idx+serit_sayi]=1;
							yol8[idx+serit_sayi*2]=1;

							yol8[idx]=0;
							yol8[idx-1*serit_sayi]=0;
							hcID[id]++;
				 }
				}
			
				//kýrmýzý yandý,dur
				if(TrafficLight[2]==0 && (hdx+1)==68)
				 {
					 sx[id]+=0.f;
				 }
				 //yeþil yandý, geç
				if(TrafficLight[2]==2 && (hdx+1)==68 && yol8[hdx*serit_sayi+sdx+serit_sayi*2]==0)
				 {
							sx[id]+=7.5;
							yol8[idx+serit_sayi]=1;
							yol8[idx]=0;
							hcID[id]++;
				 }

				 //ýþýklarý geçtikten sonra durma ,devam et
				if(hdx>=69 && yol8[hdx*serit_sayi+sdx+serit_sayi*2]==0)
				 {					
							sx[id]+=7.5;
							yol8[idx+serit_sayi]=1;
							yol8[idx]=0;
							hcID[id]++;
				 }

			/////////////////////////////////////////////////
			//tek hücreliler :)

				if(tip[id]==0 || tip[id]==2 || tip[id]==4)
				{
					//ýþýklara kadar devam et
					if(hdx<=67 && yol8[hdx*serit_sayi+sdx+serit_sayi]==0 )
					 {
							sx[id]+=7.5;
							yol8[hdx*serit_sayi+sdx+serit_sayi*hiz[id]]=1;
							yol8[hdx*serit_sayi+sdx]=0;
							hcID[id]++;
					 }
				}
			//	//kýrmýzý yandý,dur
				if(TrafficLight[2]==0 && hdx==68)
				 {
					 sx[id]+=(hiz[id]*0.f);
				 }
			//	 //yeþil yandý, geç
				if(TrafficLight[2]==2 && hdx==68 && yol8[hdx*serit_sayi+sdx+serit_sayi]==0)
				 {
							sx[id]+=7.5;
							yol8[hdx*serit_sayi+sdx+serit_sayi*hiz[id]]=1;
							yol8[hdx*serit_sayi+sdx]=0;
							hcID[id]++;
				 }
			//	 //ýþýklarý geçtikten sonra durma ,devam et
				if(hdx>=69 && yol8[hdx*serit_sayi+sdx+serit_sayi]==0)
				 {					
							
							sx[id]+=7.5;
							yol8[hdx*serit_sayi+sdx+serit_sayi*hiz[id]]=1;
							yol8[hdx*serit_sayi+sdx]=0;
							hcID[id]++;
				 }
			//	 //////////////////////////////////////////////////////////////////////////////////////////////

			//	 if(araclar[id]->serit_id==0 && araclar[id]->hc_id==18)
			//	 {
			//		int tempYon=rand()%2+1;

			//		if (tempYon==1)
			//		{
			//			yon=1;
			//		}
			//		else
			//		{
			//			if(yol3[20][1]==false )
			//			{
			//				araclar[id]->solX=36*3.75;
			//				araclar[id]->solY=46*3.75;
			//				araclar[id]->yon=4;
			//				araclar[id]->serit_id=1;
			//				araclar[id]->yol_id=3;
			//				araclar[id]->hc_id=20;
			//				yol8[18][0]=false;
			//			}
			//		} 
			//	 }
			//	  if(araclar[id]->serit_id==0 && araclar[id]->hc_id==31)
			//	 {
			//		int tempYon=rand()%2+1;

			//		if (tempYon==1)
			//		{
			//			yon=1;
			//		}
			//		else
			//		{
			//			if(yol16[8][1]==false )
			//			{
			//				araclar[id]->solX=61*3.75;
			//				araclar[id]->solY=46*3.75;
			//				araclar[id]->yon=4;
			//				araclar[id]->serit_id=1;
			//				araclar[id]->yol_id=16;
			//				araclar[id]->hc_id=8;
			//				yol8[31][0]=false;
			//			}
			//		} 
			//	 }
			//	   if(araclar[id]->serit_id==0 && araclar[id]->hc_id==43)
			//	 {
			//		int tempYon=rand()%2+1;

			//		if (tempYon==1)
			//		{
			//			yon=1;
			//		}
			//		else
			//		{
			//			if(kol3[0]==false )
			//			{
			//				araclar[id]->solX=86*3.75;
			//				araclar[id]->solY=45*3.75;
			//				araclar[id]->yon=6;
			//				
			//				araclar[id]->yol_id=103;
			//				araclar[id]->hc_id=0;
			//				yol8[43][0]=false;
			//			}
			//		} 
			//	 }
			//	  if(araclar[id]->serit_id==0 && araclar[id]->hc_id==67)
			//	 {
			//		
			//			if(kol2_3[0]==false )
			//			{
			//				araclar[id]->solX=134*3.75;
			//				araclar[id]->solY=45*3.75;
			//				araclar[id]->yon=6;
			//				
			//				araclar[id]->yol_id=203;
			//				araclar[id]->hc_id=0;
			//				yol8[67][0]=false;
			//			}
			//	 } 
			//	 
			////haritadan çýkýþlar
			if(hdx==90 && sdx==0)//yol8&serit0(çýkýþ)
			{
				sx[id]=0*3.75;
				sy[id]=46*3.75;
				yon[id]=1;
				yolID[id]=8;
				srtID[id]=0;
				yol8[90*serit_sayi+0]=0;
				hcID[id]=1;
			}

			if(hdx==90 && sdx==1)
			{
				sx[id]=0*3.75;
				sy[id]=47*3.75;
				yon[id]=1;
				yolID[id]=8;
				srtID[id]=1;
				yol8[90*serit_sayi+1]=0;
				hcID[id]=1;
				
			}
			if(hdx==90 && sdx==2)//yol8&serit2(çýkýþ)
			{
				sx[id]=0*3.75;
				sy[id]=48*3.75;
				yon[id]=1;
				yolID[id]=8;
				srtID[id]=2;
				yol8[90*serit_sayi+2]=0;
				hcID[id]=1;
			}
		
			//
			//
		}//end  of YOL8
		///////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////
		//YOL9
		if(yolID[id]==9 )
		{
			int hdx=hcID[id];
			int sdx=srtID[id];
			int serit_sayi=2;
			int idx=hdx*serit_sayi+sdx;
			//þerit 1- þerit sonuna kadar ilerle
			if(sdx==1 )
			{
				
				if(yol9[idx-1*serit_sayi]==0)
				{   
					sy[id]-=7.5;
					yol9[idx-1*serit_sayi]=1;
					yol9[idx]=0;
					hcID[id]--;
				}
				
				if(hdx==0 && yol2[69*serit_sayi+1]==0)//gideceði hücre boþ mu?
					{
						//saða dön---->yol2
						
						sx[id]=136*3.75f;
						sy[id]=6*3.75;
						yon[id]=2;
						yolID[id]=2;
						srtID[id]=1;
						yol9[0*2+1]=0;
						hcID[id]=69;

					}
			} //serit1 sonu

			
			//yol9 yukarý yönde ilerle
			if(sdx==0 && yon[id]==3)
			{
				
				if(yol9[idx+1*serit_sayi]==0)
				{   
					sy[id]+=7.5;
					yol9[idx+1*serit_sayi]=1;
					yol9[idx]=0;
					hcID[id]++;
				}
				if(hdx==19 && sdx==0)
				{
						sx[id]=141*3.75f;
						sy[id]=41*3.75;
						yon[id]=5;
						yolID[id]=204;
						srtID[id]=1;
						hcID[id]=0;
						yol9[19*serit_sayi+0]=0;
				}
			}
			
			
			
					
		}//end of YOL9
		///////////////////////////////////////////////////////////////////////////////
		//YOL10
		if(yolID[id]==10 )
		{
			int hdx=hcID[id];
			int sdx=srtID[id];
			int serit_sayi=2;
			int idx=hdx*serit_sayi+sdx;
			//serit0 ----->yon 3(yani yukarý)
			if(sdx==0)
			{
				//ýþýklara kadar devam et
				if(hdx<=19 && yol10[idx+1*serit_sayi]==0 )
				 {
							sy[id]+=(hiz[id]*7.5);
							yol10[idx+hiz[id]*serit_sayi]=1;
							yol10[idx]=0;
							hcID[id]+=(hiz[id]);
				 }
		
				//kýrmýzý yandý,dur
				if(TrafficLight[1]==0 && hdx==20)
				 {
					 sy[id]+=(hiz[id]*0.f);
				 }
				 //yeþil yandý, geç
				if(TrafficLight[1]==2 && hdx==20 && yol10[idx+1*serit_sayi]==0)
				 {
							sy[id]+=(hiz[id]*7.5);
							yol10[idx+hiz[id]*serit_sayi]=1;
							yol10[idx]=0;
							hcID[id]+=(hiz[id]);
				 }
				 //ýþýklarý geçtikten sonra durma ,devam et
				if(hdx>=21 && yol10[idx+1*serit_sayi]==0)
				 {					
							sy[id]+=(hiz[id]*7.5);
							yol10[idx+hiz[id]*serit_sayi]=1;
							yol10[idx]=0;
							hcID[id]+=(hiz[id]);
				 }

				//yol10-serit0 sonu----->yol2'ye dön
				if(hdx== 42)
				{
					
					sx[id]=0.f;
					sy[id]=4*3.75;
					yolID[id]=2,
					srtID[id]=0;
					hcID[id]=1;
					yol10[42*serit_sayi+0]=0;
					yol2[1*serit_sayi+0]=1;
					yon[id]=1;
				}
			
			}
			//serit1----->yon4 (yani aþaðý yönde)
			if(sdx==1)
			{
				//ýþýklara kadar devam et
				if(hdx>=25 && yol10[idx-1*serit_sayi]==0 )
				 {
							sy[id]-=(hiz[id]*7.5);
							yol10[idx-hiz[id]*serit_sayi]=1;
							yol10[idx]=0;
							hcID[id]-=hiz[id];
				 }
		
				//kýrmýzý yandý,dur
				if(TrafficLight[3]==0 && hdx==24)
				 {
					 sy[id]-=(hiz[id]*0.f);
				 }
				 //yeþil yandý, geç
				if(TrafficLight[3]==2 && hdx==24 && yol10[idx-1*serit_sayi]==0)
				 {
					 sy[id]-=(hiz[id]*7.5);
					 yol10[idx-hiz[id]*serit_sayi]=1;
					 yol10[idx]=0;
					 hcID[id]-=(hiz[id]);
				 }
				 //ýþýklarý geçtikten sonra durma ,devam et
				if(hdx<=23 && yol10[idx-1*serit_sayi]==0)
				 {					
						    sy[id]-=(hiz[id]*7.5);
							yol10[idx-hiz[id]*serit_sayi]=1;
							yol10[idx]=0;
							hcID[id]-=(hiz[id]);
				 }

				//yol10-serit0 sonu----->yol2'ye dön
				if(hdx==1)
				{
					
					sx[id]=136*3.75f;
					sy[id]=6*3.75;
					yolID[id]=2;
					srtID[id]=1;
					hcID[id]=68;
					yol10[0*serit_sayi+1]=0;
					yol2[68*serit_sayi+1]=1;
					yon[id]=2;
				}
			}

		}//end of YOL10

		////////////////////////////////////////////////////////
		////----------------ÇAPRAZ YOLLAR----------------------
		if(yolID[id]==104)
		{
			int idx=hcID[id];
			
			
			//kavþak noktasýna kadar ilerle
			
				if(kol4[idx+1]==0)
				{   
					sx[id]+=7.5;
					sy[id]+=7.5;
					kol4[idx+1]=1;
					kol4[idx]=0;
					hcID[id]++;
				}
				if(idx==5)
				{
					sx[id]=108*3.75;
					sy[id]=46*3.75;
					srtID[id]=0;
					yolID[id]=8;
					hcID[id]=54;
					yon[id]=1;
					kol4[5]=0;
					yol8[54*3+0]=1;
				}
			
		}
		//////////////////////////////
		if(yolID[id]==103)
		{
			int idx=hcID[id];
			//kavþak noktasýna kadar ilerle
			
				if(kol3[idx+1]==0)
				{   
					sx[id]+=7.5;
					sy[id]-=7.5;
					kol3[idx+1]=1;
					kol3[idx]=0;
					hcID[id]++;
				}
				if(hcID[id]==5)
				{
					sx[id]=94*3.75;
					sy[id]=36*3.75;
					srtID[id]=1;
					yolID[id]=52;
					hcID[id]=15;
					yon[id]=4;
					kol3[5]=0;
					yol52[15*2+0]=1;
				}
			
		}


		//çapraz yol 204
		if(yolID[id]==204)
		{
			int idx=hcID[id];
			//kavþak noktasýna kadar ilerle
			
				if(kol2_4[idx+1]==0)
				{   
					sx[id]+=7.5;
					sy[id]+=7.5;
					kol2_4[idx+1]=1;
					kol2_4[idx]=0;
					hcID[id]++;
				}

				if(hcID[id]==3)
				{
					sx[id]=148*3.75;
					sy[id]=46*3.75;
					srtID[id]=0;
					yolID[id]=8;
					hcID[id]=74;
					yon[id]=1;
					kol2_4[3]=0;
					yol8[74*3+0]=1;
				}
			
		}
		//çapraz yol 203
		if(yolID[id]==203)
		{
			int idx=hcID[id];
			//kavþak noktasýna kadar ilerle
			
				if(kol2_3[idx+1]==0)
				{   
					sx[id]+=7.5;
					sy[id]-=7.5;
					kol2_3[idx+1]=1;
					kol2_3[idx]=0;
					hcID[id]++;
				}

				if(hcID[id]==2)
				{
					sx[id]=137*3.75;
					sy[id]=42*3.75;
					srtID[id]=1;
					yolID[id]=9;
					hcID[id]=18;
					yon[id]=4;
					kol2_3[2]=0;
					yol9[18*9+1]=1;
				}
			
		}
		//çapraz yol 202
		if(yolID[id]==202)
		{
			int idx=hcID[id];
			//kavþak noktasýna kadar ilerle
			
				if(kol2_2[idx+1]==0)
				{   
					sx[id]-=7.5;
					sy[id]+=7.5;
					kol2_2[idx+1]=1;
					kol2_2[idx]=0;
					hcID[id]++;
				}

				if(hcID[id]==3 )
				{
					sx[id]=141*3.75;
					sy[id]=58*3.75;
					srtID[id]=0;
					yolID[id]=10;
					hcID[id]=27;
					yon[id]=3;
					kol2_2[3]=0;
					yol10[27*2+0]=1;
				}
			
		}
		////////////////
		if(yolID[id]==201)
		{
			int idx=hcID[id];
			//kavþak noktasýna kadar ilerle
			
				if(kol2_1[idx+1]==0)
				{   
					sx[id]-=7.5;
					sy[id]-=7.5;
					kol2_1[idx+1]=1;
					kol2_1[idx]=0;
					hcID[id]++;
				}
				if(hcID[id]==3)
				{
					sx[id]=133*3.75;
					sy[id]=52*3.75;
					srtID[id]=0;
					yolID[id]=7;
					hcID[id]=67;
					yon[id]=2;
					kol2_1[5]=0;
					yol8[54*3+0]=1;
				}
			
		}

}

///////////////////////////////////////////////////
void Initial()
{   
	for(int id=0;id<arac_sayisi;id++)
	{
		SOLX[id]=arac_dizisi[id][0];
		SOLY[id]=arac_dizisi[id][1];
		TIP[id]=arac_dizisi[id][2];
		HIZ[id]=arac_dizisi[id][3];
		YON[id]=arac_dizisi[id][4];
		YOLID[id]=arac_dizisi[id][5];
		SERITID[id]=arac_dizisi[id][6];
		HCID[id]=arac_dizisi[id][7];
		
		
		HucreDoldur(YOLID[id],SERITID[id],HCID[id],TIP[id]);
		
	}//end of for

}//end of initial()
///////////////////////////////////////////////////
void waitAndRedraw(int deger)
{  
		
	    if(animate)
		{
			cudaEvent_t start, stop;//****// 
			float zaman;//****// 
			cudaEventCreate(&start);//****// 
			cudaEventCreate(&stop);//****//

			TL_Time_Depend();
			dim3 threads,blocks;
			threads.x=arac_sayisi;
			blocks.x=1;
			float *dev_SOLX,*dev_SOLY;
			int *dev_TIP,*dev_HIZ,*dev_YON,*dev_YOLID,*dev_SERITID,*dev_HCID;
			int *dev_yol1,*dev_yol2,*dev_yol3,*dev_yol5,*dev_yol52,*dev_yol7;
			int *dev_yol8,*dev_yol9,*dev_yol10;
			int *dev_TL;
			int *dev_kol1,*dev_kol2,*dev_kol3,*dev_kol4;
			int *dev_kol2_1,*dev_kol2_2,*dev_kol2_3,*dev_kol2_4;

			cudaEventRecord(start, 0);//****//
			//yer ayýr
			cudaMalloc((void**)&dev_SOLX,arac_sayisi*sizeof(float));
			cudaMalloc((void**)&dev_SOLY,arac_sayisi*sizeof(float));
			cudaMalloc((void**)&dev_TIP,arac_sayisi*sizeof(int));
			cudaMalloc((void**)&dev_HIZ,arac_sayisi*sizeof(int));
			cudaMalloc((void**)&dev_YON,arac_sayisi*sizeof(int));
			cudaMalloc((void**)&dev_YOLID,arac_sayisi*sizeof(int));
			cudaMalloc((void**)&dev_SERITID,arac_sayisi*sizeof(int));
			cudaMalloc((void**)&dev_HCID,arac_sayisi*sizeof(int));

			cudaMalloc((void**)&dev_yol1,35*2*sizeof(int));
			cudaMalloc((void**)&dev_yol2,71*2*sizeof(int));
			cudaMalloc((void**)&dev_yol3,20*2*sizeof(int));
			cudaMalloc((void**)&dev_yol5,45*2*sizeof(int));
			cudaMalloc((void**)&dev_yol52,91*3*sizeof(int));
			cudaMalloc((void**)&dev_yol7,91*3*sizeof(int));
			cudaMalloc((void**)&dev_yol8,91*3*sizeof(int));
			cudaMalloc((void**)&dev_yol9,42*2*sizeof(int));
			cudaMalloc((void**)&dev_yol10,43*2*sizeof(int));
			cudaMalloc((void**)&dev_kol1,6*sizeof(int));
			cudaMalloc((void**)&dev_kol2,6*sizeof(int));
			cudaMalloc((void**)&dev_kol3,6*sizeof(int));
			cudaMalloc((void**)&dev_kol4,6*sizeof(int));
			cudaMalloc((void**)&dev_kol2_1,5*sizeof(int));
			cudaMalloc((void**)&dev_kol2_2,5*sizeof(int));
			cudaMalloc((void**)&dev_kol2_3,5*sizeof(int));
			cudaMalloc((void**)&dev_kol2_4,5*sizeof(int));
			

			cudaMalloc((void**)&dev_TL,4*sizeof(int));
			/////////////////////////////////////////////////////////////////
			cudaMemcpy(dev_SOLX,SOLX,arac_sayisi*sizeof(float),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_SOLY,SOLY,arac_sayisi*sizeof(float),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_TIP,TIP,arac_sayisi*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_HIZ,HIZ,arac_sayisi*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_YON,YON,arac_sayisi*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_YOLID,YOLID,arac_sayisi*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_SERITID,SERITID,arac_sayisi*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_HCID,HCID,arac_sayisi*sizeof(int),cudaMemcpyHostToDevice);
			
			cudaMemcpy(dev_yol1,yol1,35*2*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_yol2,yol2,71*2*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_yol3,yol3,20*2*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_yol5,yol5,45*2*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_yol52,yol52,15*2*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_yol7,yol7,91*3*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_yol8,yol8,91*3*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_yol9,yol9,42*2*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_yol10,yol10,43*2*sizeof(int),cudaMemcpyHostToDevice);

			cudaMemcpy(dev_kol1,kol1,6*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_kol2,kol2,6*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_kol3,kol3,6*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_kol4,kol4,6*sizeof(int),cudaMemcpyHostToDevice);

			cudaMemcpy(dev_kol2_1,kol2_1,5*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_kol2_2,kol2_2,5*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_kol2_3,kol2_3,5*sizeof(int),cudaMemcpyHostToDevice);
			cudaMemcpy(dev_kol2_4,kol2_4,5*sizeof(int),cudaMemcpyHostToDevice);

			cudaMemcpy(dev_TL,TrafficLight,4*sizeof(int),cudaMemcpyHostToDevice);

			
			kernel<<<blocks,threads>>>(dev_SOLX,dev_SOLY,dev_TIP,dev_HIZ,dev_YON,dev_YOLID,dev_SERITID,dev_HCID,dev_yol1,dev_yol2,dev_yol3,dev_yol5,dev_yol52,dev_yol7,dev_yol8,dev_yol9,dev_yol10,dev_TL,dev_kol1,dev_kol2,dev_kol3,dev_kol4,dev_kol2_1,dev_kol2_2,dev_kol2_3,dev_kol2_4);
			
			

			cudaMemcpy(SOLX,dev_SOLX,arac_sayisi*sizeof(float),cudaMemcpyDeviceToHost);
			cudaMemcpy(SOLY,dev_SOLY,arac_sayisi*sizeof(float),cudaMemcpyDeviceToHost);
			cudaMemcpy(TIP,dev_TIP,arac_sayisi*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(HIZ,dev_HIZ,arac_sayisi*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(YON,dev_YON,arac_sayisi*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(YOLID,dev_YOLID,arac_sayisi*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(SERITID,dev_SERITID,arac_sayisi*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(HCID,dev_HCID,arac_sayisi*sizeof(int),cudaMemcpyDeviceToHost);

			
			cudaMemcpy(yol1,dev_yol1,35*2*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(yol2,dev_yol2,71*2*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(yol3,dev_yol3,20*2*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(yol5,dev_yol5,45*2*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(yol52,dev_yol52,15*2*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(yol7,dev_yol7,91*3*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(yol8,dev_yol8,91*3*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(yol9,dev_yol9,42*2*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(yol10,dev_yol10,43*2*sizeof(int),cudaMemcpyDeviceToHost);
			
			cudaMemcpy(kol1,dev_kol1,6*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(kol2,dev_kol2,6*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(kol3,dev_kol3,6*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(kol4,dev_kol4,6*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(kol2_1,dev_kol2_1,5*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(kol2_2,dev_kol2_2,5*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(kol2_3,dev_kol2_3,5*sizeof(int),cudaMemcpyDeviceToHost);
			cudaMemcpy(kol2_4,dev_kol2_4,5*sizeof(int),cudaMemcpyDeviceToHost);

			cudaMemcpy(TrafficLight,dev_TL,4*sizeof(int),cudaMemcpyDeviceToHost);

		

			cudaFree(dev_SOLX);
			cudaFree(dev_SOLY);
			cudaFree(dev_TIP);
			cudaFree(dev_HIZ);
			cudaFree(dev_YON);
			cudaFree(dev_YOLID);
			cudaFree(dev_SERITID);
			cudaFree(dev_HCID);

			cudaFree(dev_yol1);
			cudaFree(dev_yol2);
			cudaFree(dev_yol3);
			cudaFree(dev_yol5);
			cudaFree(dev_yol52);
			cudaFree(dev_yol7);
			cudaFree(dev_yol8);
			cudaFree(dev_yol9);
			cudaFree(dev_yol10);
			cudaFree(dev_kol1);
			cudaFree(dev_kol2);
			cudaFree(dev_kol3);
			cudaFree(dev_kol4);
			cudaFree(dev_TL);
			cudaEventRecord(stop, 0); 
			cudaEventSynchronize(stop);//****// 
			cudaEventElapsedTime(&zaman, start, stop);//****// 

			toplam+=zaman;
			printf ("Time for the Kernel: %f ms-----toplam: %f ms\n", zaman,toplam);//****//
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
	for(int id=0;id<arac_sayisi;id++)
	{   
		
		araclar[id]=new ARAC(SOLX[id],SOLY[id],TIP[id],HIZ[id],YON[id],YOLID[id],SERITID[id],HCID[id]);
		araclar[id]->AracCiz();
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
          glutCreateWindow("Hücresel Otomatlar Trafik Simülasyonu(GPU)");
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

