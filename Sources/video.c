#include "includes.h"

BYTE croadtype = 0;
//*************************************************************************
//*		 *************************��������*****************************   *
//*************************************************************************
//����ͼ����
word crow = 0;           //����������
byte prow = 0;  	  	    //����ͷ������ǰ��
byte pcolumn = 0;        //����ͷ��ǰ��

byte RowSAIC_DelayTime=76;   //ͼ����ʱʱ��82//43

//����������־
byte fieldover = 0;                //һ������������־�� 
//������ά����    
volatile byte g_pix[ROWS][COLUMNS]; 
volatile byte pic[ROWS][COLUMNS]; 
byte pix[ROWS][COLUMNS];

word selectRows[ROWS]=
{
//��С��:17
//�����:255
//ͼ������ӽ���Զ

		
//		17,18,19,21,22,24,25,27,28,30,
//		32,33,35,37,39,40,42,44,46,48,
//		50,52,54,56,58,60,62,65,67,69,
//		72,74,77,79,82,85,88,90,93,96,
//		99,103,106,109,113,116,120,123,127,131,
//		135,139,143,148,152,157,161,166,171,177,
//		182,188,193,199,206,212,219,226,233,240//,247
		
		

//		��С��:17
//		�����:255
//		ͼ������ӽ���Զ
		23 ,39 ,52 ,65 ,76 ,89 ,96 ,105,113,121,
		128,134,140,146,151,156,161,165,169,173,
		177,180,183,186,189,192,195,198,200,202,
		204,206,208,210,212,214,216,218,220,222,
		224,225,226,227,228,229,230,231,232,233,
		234,235,236,237,238,239,240,241,242,243,
		244,245,246,247,248,249,250,251,252,253,
		
//		257,241,228,215,204,191,184,175,167,159,
//		152,146,140,134,129,124,119,115,111,107,
//		103,100, 97, 94, 91, 88, 85, 82, 80, 78,
//		 76, 74, 72, 70, 68, 66, 64, 62, 60, 58,
//		 56, 55, 54, 53, 52, 51, 50, 49, 48, 47,
//		 46, 45, 44, 43, 42, 41, 40, 39, 38, 37,
//		 36, 35, 34, 33, 32, 31, 30, 29, 28, 27



};

//*************************************************************************
//*   **************************�жϺ���****************************      *
//*************************************************************************
void FieldInputCapture(void) 
{	
	EMIOS_0.CH[3].CCR.B.FEN=0;  //�رճ��ж� 
	prow=0;crow=0;
	EMIOS_0.CH[7].CSR.B.FLAG = 1;//�����ж�
	EMIOS_0.CH[7].CCR.B.FEN=1;	//�������ж�
}


void RowInputCapture(void) 
{	
	EMIOS_0.CH[7].CSR.B.FLAG = 1;
	++crow;
	//������ʼ
	//����Ӱ ��Ϊ����ͷ����źŵ�ǰ�����ǲ����õģ������ӵ�ǰROWS_MIN��
	if(crow>selectRows[prow])
  	{
	    for(pcolumn=0;pcolumn<RowSAIC_DelayTime;++pcolumn) {}
	    /************************
	    	��ʱ������*****************************/


	    g_pix[ROW-prow][82]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");	//��࣬��ʱ
		g_pix[ROW-prow][81]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][80]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][79]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][78]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][77]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][76]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][75]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][74]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][73]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][72]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][71]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][70]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
																																																					
		g_pix[ROW-prow][69]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][68]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][67]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][66]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][65]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][64]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][63]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][62]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][61]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][60]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
																																																				 
		g_pix[ROW-prow][59]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][58]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][57]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][56]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][55]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][54]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][53]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][52]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][51]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][50]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");

		g_pix[ROW-prow][49]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][48]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][47]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][46]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][45]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][44]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][43]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][42]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][41]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][40]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
											
		g_pix[ROW-prow][39]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][38]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][37]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][36]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][35]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][34]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][33]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][32]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][31]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][30]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		
		g_pix[ROW-prow][29]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][28]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][27]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][26]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][25]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][24]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][23]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][22]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][21]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][20]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
								
		g_pix[ROW-prow][19]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][18]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][17]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][16]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][15]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][14]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][13]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][12]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][11]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][10]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		
		g_pix[ROW-prow][9]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][8]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][7]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][6]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][5]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][4]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][3]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][2]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][1]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
		g_pix[ROW-prow][0]=SIU.GPDI[42].R; asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");	
	   	++prow;
		if(prow==ROWS)
		{
			EMIOS_0.CH[7].CCR.B.FEN=0; 	//�ر����ж�
			fieldover=1; 
		}
	}
	D0=~D0;
}

/*----------------------------------------------------------------------*/
/*��Ƶ�ź����                                            	 */
/*----------------------------------------------------------------------*/
void Video_Image(void)
{
	int y,x,i,col;
#if 1
	volatile int j=0;
	for(j=0;j<ROWS;j++)
	{
		col=CenterLine[j];
		g_pix[j][col]=0;
	}
#endif
	for(y=0;y<ROWS/8;y++)
		for(x=0;x<COLUMNS;x++)
		{
			pix[y][x]=0;
			for(i=7;i>=0;i--)
				pix[y][x]=pix[y][x]*2+g_pix[y*8+i][x];
		}	

}
void TF_Image(void)
{
	int i,j;
	for(i=0;i<ROWS;i++)
		for(j=0;j<COLUMNS;j++)
		{
			if(g_pix[i][j]==0)
				pic[i][j]=0x00;
			else
				pic[i][j]=0xFF;
		}
}
void Display_Video(void)
{
	
	BYTE x,y;

	Video_Image();
	for(y=0;y<ROWS/8;y++)
	{
		LCD_Set_Pos(10,y);				
    	for(x=0;x<COLUMNS;x++)
	    {      
	    	LCD_WrDat(pix[y][x]);		
	    }
	}
}

//*************************************************************************																							                        
//*   ********************���߷���ͼ��******************************      *	
//*************************************************************************
void Send_CCD_Video(void) 
{
  unsigned char i,j;
  serial_port_1_TX(0x55);
  serial_port_1_TX(0xAA);
  serial_port_1_TX(0xFF);
  for(i = 0;i < ROWS;i ++)
  {   
	for(j = 0;j < COLUMNS;j ++)
	{
	   if(g_pix[i][j]==1)
		   serial_port_1_TX(0xFF);
	   else
		   serial_port_1_TX(0x00);
	}
  }
  serial_port_1_TX(0xFF);
  serial_port_1_TX(0xAA);
  serial_port_1_TX(0x55);
}

void SetupCCD(void)
{   
	serial_port_1_TX(0xAA);        
	serial_port_1_TX(0xBB);        
	serial_port_1_TX(0xFF);        
	serial_port_1_TX(ROWS);        
	serial_port_1_TX(COLUMNS);         
	serial_port_1_TX(0xFF);        
	serial_port_1_TX(0xBB);        
	serial_port_1_TX(0xAA);        
}

void SetupBKL(void)
{
    unsigned char para1[10] = {"L"};//������ʾ����λ���ϵı�����
    unsigned char para2[10] = {"R"};  
    unsigned char para3[10] = {"target_a"};
    byte i;
       
    serial_port_1_TX(0xCC);        
    serial_port_1_TX(0xDD);        
    serial_port_1_TX(0xFF);         
                                             
    serial_port_1_TX(ROWS);        
    serial_port_1_TX(COLUMNS);        
    serial_port_1_TX(3);         // number of parameters
    
    serial_port_1_TX(0);         // display position  0��1�ֱ��ʾ����ߴ��ڻ����ұߴ�����ʾ
    serial_port_1_TX(0);         // display position
    serial_port_1_TX(1);
    
    for(i=0;i<10;++i)
    	serial_port_1_TX(para1[i]);
    for(i=0;i<10;++i)
    	serial_port_1_TX(para2[i]);
   	for(i=0;i<10;++i)
   		serial_port_1_TX(para3[i]);
    	        
   	serial_port_1_TX(9);         // parameter color
   	serial_port_1_TX(5);
   	serial_port_1_TX(9);         // parameter color
    
   	serial_port_1_TX(0xFF);        
   	serial_port_1_TX(0xDD);        
   	serial_port_1_TX(0xCC);  
}

void Send_CCD_Blackline(void)
{
	byte i=0;
	serial_port_1_TX(0x55);
	serial_port_1_TX(0xBB);
	serial_port_1_TX(0xFF);
    for(;i<ROWS;++i)
    	serial_port_1_TX(BlackLine[0][i]);
    serial_port_1_TX(0x00);
    serial_port_1_TX(0x00);
    serial_port_1_TX(0x00);
    serial_port_1_TX(LineType[0]);//
    serial_port_1_TX(0x00);
    serial_port_1_TX(0x00);
    serial_port_1_TX(0x00);
    serial_port_1_TX(LineType[1]);//
    serial_port_1_TX(0x00);
    serial_port_1_TX(0x00);
    serial_port_1_TX(0x00);
    serial_port_1_TX(target_offset);//
    serial_port_1_TX(0xFF);        
    serial_port_1_TX(0xBB);        
    serial_port_1_TX(0x55);              
}


