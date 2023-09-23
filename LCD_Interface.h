/*    
*     Created in 10/9/2023
*     By : Ahmed Eldab3
*/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H



/************************************************* Prototypes Of Functions *************************************************/


void LCD_voidGoToPosition (u8 Copy_Line,u8 Copy_pos);

void LCD_voidIitialize (void);

void LCD_voidWriteData (u8 Copy_Character);

void LCD_voidWriteCommand (u8 Copy_Command);

void LCD_voidWriteString (u8 *ptr);

void LCD_voidWriteNumber (u32 Copy_Number);

void LCD_voidAddPatternsToCGRAM (void);

void LCD_voidWritePattern (u8 Copy_PatternNumber);

u8 LCD_u8GetRow (void);

u8 LCD_u8GetColumn (void);

#endif