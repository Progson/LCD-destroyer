void characterDisplay(int x, int y) {
  lcd.setCursor(x, y);
  lcd.write((byte)0);
}
void wallDisplay() {
  lcd.setCursor(13, 0);
  lcd.write('|');
  lcd.setCursor(13, 1);
  lcd.write('|');
}
void scoreDisplay() {
  lcd.setCursor(14, 0);
  lcd.print(score);
}
void communicateSend(int n) {
  String c = communicate(n);
  for (int i = 0; i < c.length() ; i++) {
    lcd.print(c[i]);
    delay(200);
  }
}
String communicate(int n) {
  switch (n) {
    case 0:
      return "   Game Over   ";
      break;
    case 1: {
        String endTitle = " Your score: ";
        endTitle += score;
        return endTitle;
        break;
      }
    case 2:
      return "    You Suck    ";
      break;
    case 3:
      return "   Created by   ";
      break;
    case 4:
      return "Dominik Szczepek";
      break;
    case 5:
      return " LCD Destroyers ";
      break;
    case 6:
      return "     You won    ";
      break;
    case 7:
      return "  I respect You ";
      break;
  }
}
