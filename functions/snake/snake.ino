/*
!Developed for Aruduino UNO!
Columns
  [(x,y)-Pin]
  (1,1)-13
  (1,2)-12
  (1,3)-11
  (1,4)-10
  (2,1)-9
  (2,2)-8
  (2,3)-7
  (2,4)-6
  (3,1)-5
  (3-2)-4
  (3-3)-3
  (3,4)-2
  (4,1)-1
  (4,2)-0
  (4,3)-A5
  (4,4)-A4

Layers
  layer[0]= A0
  layer[1]= A1
  layer[2]= A2
  layer[3]= A3
 */

int column[16] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, A5, A4};
int layer[4] = {A0, A1, A2, A3};

int xy[4][4] = {
    {13, 12, 11, 10},
    {9, 8, 7, 6},
    {5, 4, 3, 2},
    {1, 0, A5, A4}

};

void setup()
{
  for (int i = 0; i < 16; i++)
  {
    pinMode(column[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++)
  {
    pinMode(layer[i], OUTPUT);
  }
}
void loop()
{
  snake();
}

void snake()
{
  int time = 100;

  for (int i = 0; i < 4; i++)
  {
    digitalWrite(layer[i], 1);
  }
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(column[i], 1);
  }
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(column[i], 0);
    delay(time);
    digitalWrite(column[i], 1);
  }
  for (int i = 7; i > 3; i--)
  {
    digitalWrite(column[i], 0);
    delay(time);
    digitalWrite(column[i], 1);
  }
  for (int i = 8; i < 12; i++)
  {
    digitalWrite(column[i], 0);
    delay(time);
    digitalWrite(column[i], 1);
  }
  for (int i = 15; i > 11; i--)
  {
    digitalWrite(column[i], 0);
    delay(time);
    digitalWrite(column[i], 1);
  }
  delay(time);
  digitalWrite(column[8], 0);
  delay(time);
  digitalWrite(column[8], 1);
  digitalWrite(column[4], 0);
  delay(time);
  digitalWrite(column[4], 1);
}
