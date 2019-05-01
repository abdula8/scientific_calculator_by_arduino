#include<LiquidCrystal.h>
#include <Keypad.h>
int dg1;
int dg2;
char x =0 ;
char y =0 ;
char op=0 ;
char op1=0;
int dg3;
char excute;
bool equal =0;


const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
byte rowPins[] = {8, 9, 10, 11}; //connect to the row pinouts of the kpd
byte colPins[] = {13, 12, A1}; //connect to the column pinouts of the kpd

char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};


Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

#define rs A2
#define enable A3
#define d4 4
#define d5 5
#define d6 6
#define d7 7
LiquidCrystal out(rs, enable, d4, d5, d6, d7);

void setup() {
  out.begin(16,2);

}

void loop() {
 if(!x && !y && !op )//first digit
 {
  x=kpd.getKey();
  out.print(x);
  dg1 = x - 48 ;
 }
 if(x && !y && !op)
 {
  op=kpd.getKey();
  if(op=='*')
  {
    while(!op1) 
    {op1=kpd.getKey();
     if (op1=='1')
     op = '+' ;
     else if (op1=='2')
     op='-';
      else if (op1=='3')
     op='*';
      else if (op1=='4')
     op='/';
      else if (op1=='5')
     op='%';
    }
    }
 }
 
 if(x && !y && op)
 {
  y=kpd.getKey();
  out.print(y);
   dg2 = y - 48 ;
   
 }
 if(!excute && x && y && op)
 {
   excute=kpd.getKey();
  out.print('=');
  if(op=='+')
 {dg3=dg1+dg2;
 out.print(dg3);}
 else if (op=='-')
 {dg3=dg1-dg2;
 out.print(dg3);}
 else if (op=='*')
 {dg3=dg1*dg2;
 out.print(dg3);}
 else if (op=='/')
 {dg3=dg1/dg2;
 out.print(dg3);}
 else if (op=='%')
 {dg3=dg1%dg2;
 out.print(dg3);}
 }
 }



