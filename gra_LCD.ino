#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int characterPosY = 0;
int score = 0;
int game = 0;
bool win = 0;
const int bulletNum = 5;
#include "bullet.h"
Bullet bullets[bulletNum];

void setup() {
  spriteCreate();
  pinMode(13, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  lcd.begin(16, 2);
  Serial.begin(9600);
  for (int i = 0 ; i < bulletNum; i ++) {
    bullets[i] = Bullet(random(50, 100), 12, random(2));
  }
}
void loop() {
  while (game == 0) {
    lcd.clear();
    lcd.home();
    communicateSend(5);
    if (menuButton()) {
      break;
    }
    delay(500);
    if (menuButton()) {
      break;
    }
    lcd.clear();
    lcd.home();
    communicateSend(3);
    if (menuButton()) {
      break;
    }
    lcd.setCursor(0, 1);
    communicateSend(4);
    if (menuButton()) {
      break;
    }
    delay(500);
  }
  if (game == 1) {
    button();
    characterDisplay(0 , characterPosY);
    for (int i = 0 ; i < bulletNum; i++) {
      bullets[i].bulletMove();
      bullets[i].bulletDisplay();
    }
    wallDisplay();
    Serial.println(score);
    scoreDisplay();
  }
  endGame();
}
