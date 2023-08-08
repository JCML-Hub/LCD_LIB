/****************************************************************************************************
//=======================================Һ���������߽���==========================================//
//��ģ������Ĭ��������������ΪSPI����
 ***
 * ��CUBEMX�п���һ��SPI���Լ��ĸ���������ڷֱ��ǣ�ע����Ҫ�����趨Ϊ����ģʽ
 *          LCD_CS
 *          LCD_RST
 *          LCD_DC
 *          LCD_LED
 *����ʹ�����SPI������Ҫ�趨����GPIO�ڸ��������ע����Ҫ�����趨Ϊ����ģʽ
 *          LCD_MOSI
 *          LCD_SCLK
//=========================================������������=========================================//
//������
**************************************************************************************************/	
#ifndef __LCD_H
#define __LCD_H		

#include "main.h"
#include "spi.h"


/*ʹ�����SPI����LCD��Ļ*/
//			1  Ϊ�������
//			0	 ΪӲ��
#define ENANLE_SOFTWARE_SPI	0
#define HARDWARE_SPI_CHANNEL	hspi1

/////////////////////////////////////���SPI//////////////////////////////////
#if ENANLE_SOFTWARE_SPI==1
//Һ�����ƿ���1�������궨��
#define	SPI_MOSI_SET  	LCD_MOSI_GPIO_Port->BSRR = LCD_MOSI_Pin    
#define	SPI_SCLK_SET  	LCD_SCLK_GPIO_Port->BSRR = LCD_SCLK_Pin    
//Һ�����ƿ���0�������궨��

#define	SPI_MOSI_CLR  	LCD_MOSI_GPIO_Port->BRR = LCD_MOSI_Pin    
#define	SPI_SCLK_CLR  	LCD_SCLK_GPIO_Port->BRR = LCD_SCLK_Pin    
#endif

#define u8 unsigned char
#define u16 unsigned short int
#define u32 unsigned int
	

//LCD��Ҫ������
typedef struct  
{										    
	uint16_t width;			//LCD ���
	uint16_t height;			//LCD �߶�
	uint16_t id;				  //LCD ID
	uint8_t  dir;			  //���������������ƣ�0��������1��������	
	uint16_t wramcmd;		//��ʼдgramָ��
	uint16_t setxcmd;		//����x����ָ��
	uint16_t setycmd;		//����y����ָ��	 
}_lcd_dev; 	


//LCD����
extern _lcd_dev lcddev;	//����LCD��Ҫ����
/////////////////////////////////////�û�������///////////////////////////////////	 
#define USE_HORIZONTAL  	 2//����Һ����˳ʱ����ת���� 	0-0����ת��1-90����ת��2-180����ת��3-270����ת

//////////////////////////////////////////////////////////////////////////////////	  
//����LCD�ĳߴ�
#define LCD_W 240
#define LCD_H 320

//TFTLCD������Ҫ���õĺ���		   
extern uint16_t  POINT_COLOR;//Ĭ�Ϻ�ɫ    
extern uint16_t  BACK_COLOR; //������ɫ.Ĭ��Ϊ��ɫ

////////////////////////////////////////////////////////////////////
//-----------------LCD�˿��趨---------------- 
/*�˴�ֱ�ӶԼĴ������в�������ʡʱ��*/
///GPIO��λ�����ߣ�
#define	LCD_CS_SET	LCD_CS_GPIO_Port->BSRR=LCD_CS_Pin    //Ƭѡ�˿�
#define	LCD_RS_SET	LCD_DC_GPIO_Port->BSRR=LCD_DC_Pin    //����/����
#define	LCD_RST_SET	LCD_RST_GPIO_Port->BSRR=LCD_RST_Pin   //��λ

//GPIO��λ�����ͣ�							    
#define	LCD_CS_CLR	LCD_CS_GPIO_Port->BRR=LCD_CS_Pin     //Ƭѡ�˿�
#define	LCD_RS_CLR	LCD_DC_GPIO_Port->BRR=LCD_DC_Pin     //����/����
#define	LCD_RST_CLR	LCD_RST_GPIO_Port->BRR=LCD_RST_Pin    //��λ

////////////////////////////////////////////////////////////////////
//-----------------������ɫ---------------- 
#define WHITE       0xFFFF
#define BLACK      	0x0000	  
#define BLUE       	0x001F  
#define BRED        0XF81F
#define GRED 			 	0XFFE0
#define GBLUE			 	0X07FF
#define RED         0xF800
#define MAGENTA     0xF81F
#define GREEN       0x07E0
#define CYAN        0x7FFF
#define YELLOW      0xFFE0
#define BROWN 			0XBC40 //��ɫ
#define BRRED 			0XFC07 //�غ�ɫ
#define GRAY  			0X8430 //��ɫ
//GUI��ɫ

#define DARKBLUE      	 0X01CF	//����ɫ
#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ  
#define GRAYBLUE       	 0X5458 //����ɫ
//������ɫΪPANEL����ɫ 
 
#define LIGHTGREEN     	0X841F //ǳ��ɫ
#define LIGHTGRAY     	0XEF5B //ǳ��ɫ(PANNEL)
#define LGRAY 			 		0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ

#define LGRAYBLUE      	0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE          0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)


////////////////////////////////////////////////////////////////////
//-----------------SPIͨ�ŵײ���������---------------- 

void  SPIv_WriteData(uint8_t Data);

////////////////////////////////////////////////////////////////////
//-----------------LCD�ײ���ʾ��������---------------- 

void LCD_Init(void);
void LCD_DisplayOn(void);
void LCD_DisplayOff(void);
void LCD_Clear(uint16_t Color);
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);
void LCD_DrawPoint(uint16_t x,uint16_t y);//����
uint16_t  LCD_ReadPoint(uint16_t x,uint16_t y); //����
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);		   
void LCD_SetWindows(uint16_t xStar, uint16_t yStar,uint16_t xEnd,uint16_t yEnd);

uint16_t LCD_RD_DATA(void);//��ȡLCD����									    
void LCD_WriteReg(uint8_t LCD_Reg, uint16_t LCD_RegValue);
void LCD_WR_DATA(uint8_t data);
uint16_t LCD_ReadReg(uint8_t LCD_Reg);
void LCD_WriteRAM_Prepare(void);
void LCD_WriteRAM(uint16_t RGB_Code);
uint16_t LCD_ReadRAM(void);		   
uint16_t LCD_BGR2RGB(uint16_t c);
void LCD_SetParam(void);
void Lcd_WriteData_16Bit(uint16_t Data);
void LCD_direction(uint8_t direction );

////////////////////////////////////////////////////////////////////
//-----------------LCD�û�����ʾ��������---------------- 

void GUI_DrawPoint(u16 x,u16 y,u16 color);
void LCD_Fill(u16 sx,u16 sy,u16 ex,u16 ey,u16 color);
void LCD_DrawLine(u16 x1, u16 y1, u16 x2, u16 y2);
void LCD_DrawRectangle(u16 x1, u16 y1, u16 x2, u16 y2);
void Draw_Circle(u16 x0,u16 y0,u16 fc,u8 r);
void Draw_Triangel(u16 x0,u16 y0,u16 x1,u16 y1,u16 x2,u16 y2);
void Fill_Triangel(u16 x0,u16 y0,u16 x1,u16 y1,u16 x2,u16 y2);
void LCD_ShowChar(u16 x,u16 y,u16 fc, u16 bc, u8 num,u8 size,u8 mode);
void LCD_ShowNum(u16 x,u16 y,u32 num,u8 len,u8 size);
void LCD_Show2Num(u16 x,u16 y,u16 num,u8 len,u8 size,u8 mode);
void LCD_ShowString(u16 x,u16 y,u8 size,u8 *p,u8 mode);
void GUI_DrawFont16(u16 x, u16 y, u16 fc, u16 bc, u8 *s,u8 mode);
void GUI_DrawFont24(u16 x, u16 y, u16 fc, u16 bc, u8 *s,u8 mode);
void GUI_DrawFont32(u16 x, u16 y, u16 fc, u16 bc, u8 *s,u8 mode);
void Show_Str(u16 x, u16 y, u16 fc, u16 bc, u8 *str,u8 size,u8 mode);
void Gui_Drawbmp16(u16 x,u16 y,const unsigned char *p); 
void gui_circle(int xc, int yc,u16 c,int r, int fill);
void Gui_StrCenter(u16 x, u16 y, u16 fc, u16 bc, u8 *str,u8 size,u8 mode);
void LCD_DrawFillRectangle(u16 x1, u16 y1, u16 x2, u16 y2);
void Paint_Bmp(int x0,int y0,int width,int high,const unsigned char bmp[]);

#endif  
	 
	 



