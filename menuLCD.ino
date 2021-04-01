#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

//https://maxpromer.github.io/LCD-Character-Creator/
//YOU CAN CREATE AND ADD YOUR CUSTOM MENU ITEMS OR CHARACTER

byte selectedByte[] = {
  B01010,
  B01011,
  B01001,
  B11000,
  B00011,
  B00011,
  B01000,
  B11100
};

byte music[] = {
  B00001,
  B00011,
  B00101,
  B01001,
  B01001,
  B01011,
  B11011,
  B11000
};

byte bird[] = {
  B11110,
  B10010,
  B10110,
  B10010,
  B10010,
  B10011,
  B10011,
  B11110
};

byte tetris[] = {
  B01010,
  B01011,
  B01001,
  B11000,
  B00011,
  B00011,
  B01000,
  B11100
};

byte smile[] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B10001,
  B10001,
  B01110,
  B00000
};

////////////////////////////////////////////
int menuItem;      //variablessssss

int btnRead;

int btn;
//1-select 2-left 3-down 4-up 5-right 0-none

bool mainMenu;

bool isThereItem;



////////////////////////////////////////////
void analogRED(){
  btnRead=analogRead(A0);
  if(btnRead>1000){btn=0;}
  if(btnRead<700){btn=1;}
  if(btnRead<550){btn=2;}
  if(btnRead<300){btn=3;}
  if(btnRead<175){btn=4;}
  if(65>btnRead){btn=5;}
  
}



////////////////////////////////////////////
//NEW ITEMS(CHARACTERS) SHOULD BE ADD THIS
//FUNCTION WITH ELSE IF CONDITION
void selected(){
  isThereItem=true;
  if(menuItem==0){
    for(int i=0;i<8;i++){
      selectedByte[i]=~music[i];
    }
  }
  else if(menuItem==1){
    for(int i=0;i<8;i++){
      selectedByte[i]=~bird[i];
    }
  }
  else if(menuItem==2){
    for(int i=0;i<8;i++){
      selectedByte[i]=~tetris[i];
    } 
  }
  else if(menuItem==3){
    for(int i=0;i<8;i++){
      selectedByte[i]=~smile[i];
    } 
  }
  else if(menuItem==4){
    for(int i=0;i<8;i++){
      selectedByte[i]=~smile[i];
    } 
  }
  else{
    isThereItem=false;
  }
  lcd.createChar(1,selectedByte);
  if(menuItem>15){
    lcd.setCursor(menuItem-16,1);
    if(isThereItem==false){
      lcd.print("A");
    }
    else{
      lcd.write(1);
    }
  }
  lcd.setCursor(menuItem,0);
  if(isThereItem==false){
    lcd.print("A");    
  }
  else{
    lcd.write(1);
  } 
}


////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  lcd.begin(16,2);
  mainMenu=true;
  menuItem=5;


/////AREA WHICH NEW CHARACTERS ADDED
  lcd.createChar(2,music);
  lcd.createChar(3,bird);
  lcd.createChar(4,tetris);
  lcd.createChar(5,smile);
  lcd.createChar(6,smile);///!!!!!!!!! ITEM AMOUNT
  
  lcd.setCursor(0,0);
  lcd.print("ASCII the SAINT");
  lcd.setCursor(0,1);
  lcd.print("Initializing xD");
  delay(2000);
}


////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  analogRED();

  //////////////////////////MAIN MENU//////////////////////
  if(mainMenu==true){
    lcd.clear();
    
    for(int i=1;i<6;i++){////// MAX i MUST BE CHANGED ACCORDING TO ITEM AMOUNT
    lcd.setCursor(i-1,0);
    lcd.write(i+1);
    }
    
    /*
     * for(int i=0;i<16;i++){ //SECOND COLUMN FOR MORE ITEMS
     * lcd.setCursor(1,i);
     * lcd.write(i+17);
     * }
     */
     
     selected();
     
     if(btn==1){ //select
      mainMenu=false;
     }
     else if(btn==2){ //left
      if(menuItem==16){
        menuItem=31;
        return;
      }
      menuItem--;
      if(menuItem<0){
        menuItem=15;
      }
     }
     else if(btn==3){ //down
      menuItem+=16;
      if(menuItem>31){
        menuItem-=32;
      }
     }
     else if(btn==4){ //up
      menuItem-=16;
      if(menuItem<0){
        menuItem+=32;
      }
     }
     else if(btn==5){ //right
      if(menuItem==15){
        menuItem=0;
        return;
      }
      menuItem++;
      if(menuItem>31){
        menuItem=16;
      }
     }

     delay(100);
     return;
  }


  else if(mainMenu==false&&menuItem==0){
    lcd.clear();
    lcd.home();
    lcd.print("Music");
    if(btn==2){
      mainMenu=true;
    }
    delay(100);
  }
  else if(mainMenu==false&&menuItem==1){
    lcd.clear();
    lcd.home();
    lcd.print("Bird");
    if(btn==2){
      mainMenu=true;
    }
    delay(100);
  }
  else if(mainMenu==false&&menuItem==2){
    lcd.clear();
    lcd.home();
    lcd.print("Tetris");
    if(btn==2){
      mainMenu=true;
    }
    delay(100);
  }
  else if(mainMenu==false&&menuItem==3){
    lcd.clear();
    lcd.home();
    lcd.print("Smile");
    if(btn==2){
      mainMenu=true;
    }
    delay(100);
  }
  else if(mainMenu==false&&menuItem==4){
    lcd.clear();
    lcd.home();
    lcd.print("Smile");
    if(btn==2){
      mainMenu=true;
    }
    delay(100);
  }


 
}
