#include <LiquidCrystal.h> //Header file for LCD from
#include <Keypad.h> //Header file for Keypad
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Three columns
// Define the Keymap
char keys[ROWS][COLS] = {
{'*','0','#','A'},
{'1','2','3','B'},
{'4','5','6','C'},
{'7','8','9','D'}
};
byte rowPins[ROWS] = { 12, 13, 2, 3 };// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 4, 5, 6, 7 }; // Connect keypad COL0, COL1 and COL2 to these Arduino pins.
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); // Create the Keypad
const int rs = A2, en = A3, d4 = 8, d5 = 9, d6 = 10, d7 = 11; //Pins to which LCD is connected
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
long num1,num2,number;
char key,operation;
boolean result = false;
void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2); //We are using a 16*2 LCD display
lcd.print("scientific-"); //Display a intro message
lcd.setCursor(0, 1); // set the cursor to column 0, line 1
lcd.print("-calculator"); //Display a intro messagedelay(2000); //Wait for display to show info
delay(500);
lcd.clear(); //Then clean it
}

void loop() {
  // put your main code here, to run repeatedly:
key = kpd.getKey();
//int int_key = (int)key; // may also int {key}
if (key!=NO_KEY)
DetectKey();
if (result==true)
calculations();
displayResult();
}
// ascii conversion code 
/*
 * key = key + 48 
*/
//int to_int(char c)
//{
//  return c ;
//  }
  
void DetectKey()
{
  lcd.clear();
    if (key=='*')
    {
      result=false;
      num1=num2=number=0;
    }
// for button 0 to be clicked a time and more than one time 
    if (key=='0')
    {
    if (number==0)
    number = 0;
    else 
    number = ( number*10 ) + 0 ;
    }
// for button 1 to be clicked a time and more than one time 
    if (key=='1')
    {
    if (number==0)
    number = 1; // that because you clicked on the button 1 of keypad which key = 1 
    else 
    number = ( number*10 ) + 1 ; // that mean you click for the second time (pressed twice)
    }
// for button 2 to be clicked a time and more than one time 
    if (key=='2')
    {
    if (number==0)
    number = 2;
    else 
    number = ( number*10 ) + 2 ;
    }   
// for button 3 to be clicked a time and more than one time 
    if (key=='3')
    {
    if (number==0)
    number = 3;
    else 
    number = ( number*10 ) + 3 ;
    }   
// for button 4 to be clicked a time and more than one time 
    if (key=='4')
    {
    if (number==0)
    number = 4;
    else 
    number = ( number*10 ) + 4 ;
    }    
// for button 5 to be clicked a time and more than one time 
    if (key=='5')
    {
    if (number==0)
    number = 5;
    else 
    number = ( number*10 ) + 5 ;
    }   
// for button 6 to be clicked a time and more than one time 
    if (key=='6')
    {
    if (number==0)
    number = 6;
    else 
    number = ( number*10 ) + 6 ;
    }   
// for button 7 to be clicked a time and more than one time 
    if (key=='7')
    {
    if (number==0)
    number = 7;
    else 
    number = ( number*10 ) + 7 ;
    }   
// for button 8 to be clicked a time and more than one time 
    if (key=='8')
    {
    if (number==0)
    number = 8;
    else 
    number = ( number*10 ) + 8 ;
    }   
// for button 9 to be clicked a time and more than one time 
    if (key=='9')
    {
    if (number==0)
    number = 9;
    else 
    number = ( number*10 ) + 9 ;
    }   
    if (key=='#')
    {
      num2=number;
      result=true;
    }
    
    if ( key == 'A' || key == 'B' || key == 'C' || key == 'D' )
    {
      num1 = number;
      number = 0;
      if (key=='A')
      /*
       * if (key=='A')
      {
        if (number == 0)
        operation='+';
        else 
        operation='-';
      }
       * 
      */
      operation='+';
      else if (key=='B')
      operation='-';
      else if (key=='C')
      operation='*';
      else if (key=='D')
      operation='/';
      }
      delay(100);
    }
void calculations()
    {
      if ( operation == '-')
      number = num1 - num2;
      else if (operation == '+')
      number = num1 + num2;
      else if ( operation == '*')
      number = num1 * num2;
      else if ( operation == '/')
      number = num1 / num2;
      }
      
void displayResult()
{
  lcd.setCursor(0, 0);
  lcd.print(num1);
  lcd.print(operation);
  lcd.print(num2);
  if (result==true)
  {
    lcd.print(" =");
    lcd.print(number);
    }
    lcd.setCursor(0, 1);
    lcd.print(number);
  }
