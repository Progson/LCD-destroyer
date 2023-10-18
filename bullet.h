class Bullet {
  public:
    int velocity, bulletY, bulletX, primaryVelocity, primaryBulletX;
    Bullet() {}
    Bullet(int vel, int bulX, int bulY) {
      primaryVelocity = vel;
      bulletY = bulY;
      bulletX = bulX;
      primaryBulletX = bulletX;
      velocity = primaryVelocity;
    }
    void bulletDisplay() {
      lcd.setCursor(bulletX, bulletY);
      lcd.write((byte)1);
    }
    void bulletMove() {
      velocity--;
      if (velocity <= 0) {
        lcd.setCursor(bulletX, bulletY);
        lcd.write(" ");
        bulletX--;
        velocity = primaryVelocity;
      }

      if ((bulletX >= -2) && (bulletX <= 0)) {
        if (bulletY == characterPosY) {
          score++;
          if(primaryVelocity > 10){
          primaryVelocity -= 2;
          }
          bulletX = primaryBulletX;
        } else if (bulletX < -1) {
          game = 2;
          bulletX = primaryBulletX;
        }
      }
    }
};
