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
  FillHalf();
}

void FillHalf()
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
  //left, up quarter
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  delay(time);
  digitalWrite(column[3], 0);
  delay(time);
  digitalWrite(column[2], 0);
  delay(time);
  //left, down quarter
  digitalWrite(column[5], 0);
  digitalWrite(column[1], 0);
  delay(time);
  digitalWrite(column[0], 0);
  delay(time);
  digitalWrite(column[4], 0);
  delay(time);
  //right, down quarter
  digitalWrite(column[9], 0);
  digitalWrite(column[8], 0);
  delay(time);
  digitalWrite(column[12], 0);
  delay(time);
  digitalWrite(column[13], 0);
  delay(time);
  //right, up quarter
  digitalWrite(column[10], 0);
  digitalWrite(column[14], 0);
  delay(time);
  digitalWrite(column[15], 0);
  delay(time);
  digitalWrite(column[11], 0);
  delay(time);
}
