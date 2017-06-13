// Mertcan YILMAZ 130202056    Volkan Uður ARSLAN   130202012               24.10.2014
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
char *grafik_yazdir(int,int,char[]);
int main()
{	
	FILE *d_s;
	FILE *d_t;
	FILE *d_i;
	struct{
		char turkce[15];
		char ingilizce[15];
	} kelime[100];
	
	int i=0,secim=0;
	char gecici_turkce[15],gecici_ingilizce[15];
	char *girilen_k,okunan_t[15],okunan_i[15];
	int x=0,y=0;
	int kosul=0;
	char gir[50];
	bool bulundu_t=false,bulundu_i=false;
	char *sira_k=(char*)malloc(sizeof(char)*4);
	char *sira1_k=(char*)malloc(sizeof(char)*4);
	
	if((d_s=fopen("C:\\Users\\Mertcan\\Desktop\\PROJE_1-AKILLI_SÖZLÜK\\sozluk.txt","r+")) == NULL)
	{
		printf("Dosya acilamadi!");
	}
	
	while(!feof(d_s))
	{
		fscanf(d_s,"%s %s\n",kelime[i].turkce,kelime[i].ingilizce);
		++i;
	}
	
	if((d_t=fopen("C:\\Users\\Mertcan\\Desktop\\PROJE_1-AKILLI_SÖZLÜK\\turkce.txt","w+")) == NULL)
	{
		printf("Dosya acilamadi!!");
	}
	
	if((d_i=fopen("C:\\Users\\Mertcan\\Desktop\\PROJE_1-AKILLI_SÖZLÜK\\ingilizce.txt","w+")) == NULL)
	{
		printf("Dosya acilamadi!!");
	}
	
	for(int j=0;j<100;++j)
	{
		for(int k=0;k<100;++k)
		{
			if(strcmp(kelime[j].turkce,kelime[k].turkce)<0)
			{
				strcpy(gecici_turkce,kelime[j].turkce);
				strcpy(gecici_ingilizce,kelime[j].ingilizce);
				strcpy(kelime[j].turkce,kelime[k].turkce);
				strcpy(kelime[j].ingilizce,kelime[k].ingilizce);
				strcpy(kelime[k].turkce,gecici_turkce);
				strcpy(kelime[k].ingilizce,gecici_ingilizce);
			}
		}
	}
	
	for(int j=0;j<100;++j)
	{
		fprintf(d_t,"%s\n",kelime[j].turkce);
		fprintf(d_i,"%s\n",kelime[j].ingilizce);
	}
	
	fclose(d_s);
	fclose(d_t);
	fclose(d_i);
	
	initwindow(400,400);
	
	setcolor(RED);
	settextstyle(0,0,2);
	outtextxy(90,60,"AKILLI SÖZLÜK");
    setcolor(WHITE);
    settextstyle(0,0,1);
    
    outtextxy(120,120,"Türkçe-Ýngilizce");
    setcolor(RED);
	rectangle(115,110,270,140);
	setcolor(WHITE);
	
	outtextxy(120,160,"Ýngilizce-Türkçe");
	setcolor(RED);
	rectangle(115,150,270,180);
	setcolor(WHITE);
	
	outtextxy(160,200,"TAMAM");
	setcolor(RED);
	rectangle(155,195,210,220);
	setcolor(WHITE);
	
	while(kosul==0)
	{
		delay(5);
	    x=mousex();
	    y=mousey(); 
	    if(ismouseclick(WM_LBUTTONDOWN))
        {
	       if((x>=115 && x<=270) && (y<=140 && y>=110))
	       {
	       	   setcolor(BLACK);
	       	   setfillstyle(1,BLACK);
	       	   fillellipse(300,165,15,15);
	       	   
	       	   setfillstyle(1,2);
	       	   fillellipse(300,125,15,15);
			   secim=1;    
			   setcolor(WHITE);
	       }
	       else if((x>=115 && x<=270) && (y<=180 && y>=150))
	       {
	       	   setcolor(BLACK);
	       	   setfillstyle(1,BLACK);
	       	   fillellipse(300,125,15,15);
	       	   
	       	   setfillstyle(1,2);
	       	   fillellipse(300,165,15,15);
			   secim=2;    
			   setcolor(WHITE);
	       }
	    }
	    clearmouseclick(WM_LBUTTONDOWN);
	    
	    delay(5);
	    x=mousex();
	    y=mousey();
	    if(ismouseclick(WM_LBUTTONDOWN))
	    {
	    	settextstyle(2,0,5);
	    	if((x<=210 && x>=155) && (y>=195 && y<=220))
	    	{
	    		kosul=1;
	    	}
	    }
	    clearmouseclick(WM_LBUTTONDOWN);
	}
	
	outtextxy(10,250,"Lütfen aranacak kelimeyi giriniz:");
	delay(20);
	girilen_k=grafik_yazdir(200,250,gir);
	
	FILE *d_turkce;
	FILE *d_ingilizce;
	
    if((d_turkce=fopen("C:\\Users\\Mertcan\\Desktop\\PROJE_1-AKILLI_SÖZLÜK\\turkce.txt","r")) == NULL)
	{
		printf("Dosya acilamadi!!");
	}
	
	if((d_ingilizce=fopen("C:\\Users\\Mertcan\\Desktop\\PROJE_1-AKILLI_SÖZLÜK\\ingilizce.txt","r")) == NULL)
	{
		printf("Dosya acilamadi!!");
	}
	
	if(secim==1)
	{
		for(int a=0;a<100;++a)
	    {		
		    fscanf(d_turkce,"%s\n",okunan_t);
		    if(strcmp(girilen_k,okunan_t)==0)
		    {
			    for(int b=0;b<=a;++b)
			    {
				    fscanf(d_ingilizce,"%s\n",okunan_i);
			    }
			    bulundu_t=true;
			    sprintf(sira_k,"%d",a+1);
			    break;
			    
		    }
	    }
	    if(bulundu_t==true)
	       {
	       	  outtextxy(10,270,"Girdiðiniz kelimenin anlami:");
	          outtextxy(170,270,okunan_i);
	          outtextxy(250,270,sira_k);
	          outtextxy(270,270,". sirada bulunmaktadir.");
	       }
	    else if(bulundu_t==false)
	       outtextxy(170,270,"aradýðýnýz kelime bulunamadý");
	}
	else if(secim==2)
	{
		for(int a=0;a<100;++a)
	    {		
		    fscanf(d_ingilizce,"%s\n",okunan_i);
		    if(strcmp(girilen_k,okunan_i)==0)
		    {
			    for(int b=0;b<=a;++b)
			    {
				    fscanf(d_turkce,"%s\n",okunan_t);
			    }
			    bulundu_i=true;
			    sprintf(sira1_k,"%d",a+1);
			    break;
		    }
	    }
	    
	    if(bulundu_i==true)
	       {
	       	  outtextxy(10,270,"Girdiðiniz kelimenin anlami:");
	          outtextxy(170,270,okunan_t);
	          outtextxy(230,270,sira1_k);
	          outtextxy(250,270,". sirada bulunmaktadir.");
	       }
	    else if(bulundu_i==false)
	       outtextxy(170,270,"aradýðýnýz kelime bulunamadý");
	}
	
	fclose(d_turkce);
	fclose(d_ingilizce);
	
	getch();
	
	if((d_t=fopen("C:\\Users\\Mertcan\\Desktop\\PROJE_1-AKILLI_SÖZLÜK\\turkce.txt","w+")) == NULL)
	{
		printf("Dosya acilamadi!!");
	}
	
	if((d_i=fopen("C:\\Users\\Mertcan\\Desktop\\PROJE_1-AKILLI_SÖZLÜK\\ingilizce.txt","w+")) == NULL)
	{
		printf("Dosya acilamadi!!");
	}
	
	fclose(d_t);
	fclose(d_i);
	closegraph();
}
char *grafik_yazdir(int x,int y,char katar[])
{
    char *donus;
    int i=0, a=x, b=y;
    char tus;
    char kelime[15]; 
    for(;;)
	{
               tus=getch();
               if(tus==27) exit(0);
               if(tus==13) break;
               if(tus==8)
			   {
                    katar[i]='\0';
                    katar[i-1]='\0'; 
                    if((i-1)<0)
					{
                        i=0;
                        a=x;
                    }
                    else
					{
                        i--;
                        a=a-10;
                        outtextxy(a,b,"   ");
                    }
               }
               else
			   {
                    sprintf(kelime,"%c",tus);
                    outtextxy(a,b,kelime);
                    katar[i]=tus;
                    katar[i+1]='\0';
                    i++;
                    a=a+10;
               }
            }    
            donus=&katar[0];
            return donus;
}
