void spriteCreate(){
  byte bulletSprite [8] = {
    B00000,
    B00100,
    B01110,
    B11011,
    B01110,
    B00100,
    B00000,
    B00000,
  };
  byte playerSprite [8]  = {
    B10000,
    B11000,
    B01110,
    B00111,
    B01110,
    B11000,
    B10000,
    B00000,
  };
  lcd.createChar(0, playerSprite);
  lcd.createChar(1, bulletSprite);
}
