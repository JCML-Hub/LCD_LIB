/****************************************************************************************************
//=======================================液晶屏数据线接线==========================================//
//本模块驱动默认数据总线类型为SPI总线
 ***
 * 在CUBEMX中开启一个SPI，以及四个高速输出口分别是：注意需要将其设定为快速模式
 *          LCD_CS
 *          LCD_RST
 *          LCD_DC
 *          LCD_LED
 *如若使用软件SPI最少需要设定两个GPIO口高速输出，注意需要将其设定为快速模式
 *          LCD_MOSI
 *          LCD_SCLK
//=========================================触摸屏触接线=========================================//
//待补充
**************************************************************************************************/	
#ifndef __LCD_H
#define __LCD_H		

#include "main.h"
#include "spi.h"


/*使能软件SPI驱动LCD屏幕*/
//			1  为软件驱动
//			0	 为硬件
#define ENANLE_SOFTWARE_SPI	0
#define HARDWARE_SPI_CHANNEL	hspi1

/////////////////////////////////////软件SPI//////////////////////////////////
#if ENANLE_SOFTWARE_SPI==1
//液晶控制口置1操作语句宏定义
#define	SPI_MOSI_SET  	LCD_MOSI_GPIO_Port->BSRR = LCD_MOSI_Pin    
#define	SPI_SCLK_SET  	LCD_SCLK_GPIO_Port->BSRR = LCD_SCLK_Pin    
//液晶控制口置0操作语句宏定义

#define	SPI_MOSI_CLR  	LCD_MOSI_GPIO_Port->BRR = LCD_MOSI_Pin    
#define	SPI_SCLK_CLR  	LCD_SCLK_GPIO_Port->BRR = LCD_SCLK_Pin    
#endif

#define u8 unsigned char
#define u16 unsigned short int
#define u32 unsigned int
	

//LCD重要参数集
typedef struct  
{										    
	uint16_t width;			//LCD 宽度
	uint16_t height;			//LCD 高度
	uint16_t id;				  //LCD ID
	uint8_t  dir;			  //横屏还是竖屏控制：0，竖屏；1，横屏。	
	uint16_t wramcmd;		//开始写gram指令
	uint16_t setxcmd;		//设置x坐标指令
	uint16_t setycmd;		//设置y坐标指令	 
}_lcd_dev; 	


//LCD参数
extern _lcd_dev lcddev;	//管理LCD重要参数
/////////////////////////////////////用户配置区///////////////////////////////////	 
#define USE_HORIZONTAL  	 2//定义液晶屏顺时针旋转方向 	0-0度旋转，1-90度旋转，2-180度旋转，3-270度旋转

//////////////////////////////////////////////////////////////////////////////////	  
//定义LCD的尺寸
#define LCD_W 240
#define LCD_H 320

//TFTLCD部分外要调用的函数		   
extern uint16_t  POINT_COLOR;//默认红色    
extern uint16_t  BACK_COLOR; //背景颜色.默认为白色

////////////////////////////////////////////////////////////////////
//-----------------LCD端口设定---------------- 
/*此处直接对寄存器进行操作，节省时间*/
///GPIO置位（拉高）
#define	LCD_CS_SET	LCD_CS_GPIO_Port->BSRR=LCD_CS_Pin    //片选端口
#define	LCD_RS_SET	LCD_DC_GPIO_Port->BSRR=LCD_DC_Pin    //数据/命令
#define	LCD_RST_SET	LCD_RST_GPIO_Port->BSRR=LCD_RST_Pin   //复位

//GPIO复位（拉低）							    
#define	LCD_CS_CLR	LCD_CS_GPIO_Port->BRR=LCD_CS_Pin     //片选端口
#define	LCD_RS_CLR	LCD_DC_GPIO_Port->BRR=LCD_DC_Pin     //数据/命令
#define	LCD_RST_CLR	LCD_RST_GPIO_Port->BRR=LCD_RST_Pin    //复位

////////////////////////////////////////////////////////////////////
//-----------------画笔颜色---------------- 
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
#define BROWN 			0XBC40 //棕色
#define BRRED 			0XFC07 //棕红色
#define GRAY  			0X8430 //灰色
//GUI颜色

#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
//以上三色为PANEL的颜色 
 
#define LIGHTGREEN     	0X841F //浅绿色
#define LIGHTGRAY     	0XEF5B //浅灰色(PANNEL)
#define LGRAY 			 		0XC618 //浅灰色(PANNEL),窗体背景色

#define LGRAYBLUE      	0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE          0X2B12 //浅棕蓝色(选择条目的反色)


////////////////////////////////////////////////////////////////////
//-----------------SPI通信底层驱动函数---------------- 

void  SPIv_WriteData(uint8_t Data);

////////////////////////////////////////////////////////////////////
//-----------------LCD底层显示驱动函数---------------- 

void LCD_Init(void);
void LCD_DisplayOn(void);
void LCD_DisplayOff(void);
void LCD_Clear(uint16_t Color);
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);
void LCD_DrawPoint(uint16_t x,uint16_t y);//画点
uint16_t  LCD_ReadPoint(uint16_t x,uint16_t y); //读点
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);		   
void LCD_SetWindows(uint16_t xStar, uint16_t yStar,uint16_t xEnd,uint16_t yEnd);

uint16_t LCD_RD_DATA(void);//读取LCD数据									    
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
//-----------------LCD用户端显示驱动函数---------------- 

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
	 
	 



