void button() {
  if (!digitalRead(13)) {
    lcd.setCursor(0, 1);
    lcd.print(" ");
    characterPosY = 0;
  }
  if (!digitalRead(10)) {
    lcd.setCursor(0, 0);
    lcd.print(" ");
    characterPosY = 1;
  }
}
bool menuButton(){
  if((!digitalRead(10))&&(!digitalRead(13))){
      game = 1;
      lcd.clear();
      return true;
    }
   return false;
}
