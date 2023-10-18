void endGame() {
  if(score >= 100 ){
    game = 2;
    win = true;
    }
  if (game == 2) {
    if (win) {
      lcd.clear();
      lcd.home();
      communicateSend(6);
      lcd.setCursor(0, 1);
      communicateSend(7);
    } else {
      lcd.clear();
      lcd.home();
      communicateSend(0);
      delay(1000);
      lcd.clear();
      lcd.home();
      communicateSend(1);
      lcd.setCursor(0, 1);
      communicateSend(2);
    }
    delay(1000);
    lcd.clear();
    score = 0;
    win = false;
    for (int i = 0 ; i < bulletNum; i++) {
      bullets[i].bulletX = bullets[i].primaryBulletX;
      bullets[i].primaryVelocity = random(50, 100);
      bullets[i].velocity = bullets[i].primaryVelocity;
      bullets[i].bulletY = random(2);
    }
    game = 0;
  }
}
