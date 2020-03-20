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

int loopTime = 500;
int r = 4;

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
  counter();
  delay(loopTime);
  turnEverythingOff();
  delay(loopTime);
  turnEverythingOn();
  delay(loopTime);
  for (int i = 0; i < 11; i++)
  {
    turnOneDiagonalOn();
  }
  timeBomb();
  delay(loopTime);
  flicker();
  delay(loopTime);
  for (int i = 0; i < r; i++)
  {
    Snake();
  }
  delay(loopTime);
  for (int i = 0; i < 101; i++)
  {
    turnOnOneRandomLed();
  }
  delay(loopTime);
  for (int i = 0; i < r; i++)
  {
    spinHalf();
  }
  delay(loopTime);
  for (int i = 0; i < r; i++)
  {
    fillHalf();
  }
  delay(loopTime);
  for (int i = 0; i < r; i++)
  {
    fillHalfAndReverse();
  }
  delay(loopTime);
  for (int i = 0; i < r; i++)
  {
    fillHalfAndEmpty();
  }
  delay(loopTime);
  for (int i = 0; i < r; i++)
  {
    loadingScreen();
  }
  delay(loopTime);
  for (int i = 0; i < 11; i++)
  {
    spin();
  }
  delay(loopTime);
}

void turnEverythingOff()
{
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(column[i], 1);
  }
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(layer[i], 0);
  }
}

void turnEverythingOn()
{
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(column[i], 0);
  }
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(layer[i], 1);
  }
}

void turnOneDiagonalOn()
{
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(layer[i], 1);
  }

  for (int i = 0; i < 16; i++)
  {
    digitalWrite(column[i], 1);
  }
  digitalWrite(column[0], 0);
  delay(100);
  digitalWrite(column[5], 0);
  delay(100);
  digitalWrite(column[10], 0);
  delay(100);
  digitalWrite(column[15], 0);
  delay(100);
  digitalWrite(column[0], 1);
  delay(100);
  digitalWrite(column[5], 1);
  delay(100);
  digitalWrite(column[10], 1);
  delay(100);
  digitalWrite(column[15], 1);
  delay(100);
}

void timeBomb()
{
  int time = 150;
  while (time != 0)
  {
    turnEverythingOn();
    delay(time);
    turnEverythingOff();
    delay(time);
    time -= 5;
  }
  turnEverythingOn();
  delay(500);
  turnEverythingOff();
  delay(500);
}

void flicker()
{
  for (int i = 0; i < 11; i++)
  {
    int time = 100;
    turnEverythingOff();
    delay(time);
    turnEverythingOn();
    delay(time);
  }
}

void Snake()
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

void turnOnOneRandomLed()
{
  int randomLayer = random(0, 4);
  int randomColumn = random(0, 16);
  int time = 200;
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(layer[i], 0);
  }
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(column[i], 1);
  }
  digitalWrite(layer[randomLayer], 1);
  digitalWrite(column[randomColumn], 0);
  delay(time);
  digitalWrite(layer[randomLayer], 0);
  digitalWrite(column[randomColumn], 1);
}

void spinHalf()
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
  //left upper quarter
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  delay(time);
  digitalWrite(column[7], 1);
  digitalWrite(column[3], 0);
  delay(time);
  digitalWrite(column[3], 1);
  digitalWrite(column[2], 0);
  delay(time);
  digitalWrite(column[2], 1);
  digitalWrite(column[6], 1);
  //left bottom quarter
  digitalWrite(column[5], 0);
  digitalWrite(column[1], 0);
  delay(time);
  digitalWrite(column[1], 1);
  digitalWrite(column[0], 0);
  delay(time);
  digitalWrite(column[0], 1);
  digitalWrite(column[4], 0);
  delay(time);
  digitalWrite(column[4], 1);
  digitalWrite(column[5], 1);
  //right bottom quarter
  digitalWrite(column[9], 0);
  digitalWrite(column[8], 0);
  delay(time);
  digitalWrite(column[8], 1);
  digitalWrite(column[12], 0);
  delay(time);
  digitalWrite(column[12], 1);
  digitalWrite(column[13], 0);
  delay(time);
  digitalWrite(column[13], 1);
  digitalWrite(column[9], 1);
  //right upper quarter
  digitalWrite(column[10], 0);
  digitalWrite(column[14], 0);
  delay(time);
  digitalWrite(column[14], 1);
  digitalWrite(column[15], 0);
  delay(time);
  digitalWrite(column[15], 1);
  digitalWrite(column[11], 0);
  delay(time);
  digitalWrite(column[11], 1);
  digitalWrite(column[10], 1);
}

void fillHalf()
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
  //bal felső negyed
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  delay(time);
  digitalWrite(column[3], 0);
  delay(time);
  digitalWrite(column[2], 0);
  delay(time);
  //bal alsó negyed
  digitalWrite(column[5], 0);
  digitalWrite(column[1], 0);
  delay(time);
  digitalWrite(column[0], 0);
  delay(time);
  digitalWrite(column[4], 0);
  delay(time);
  //jobb alsó negyed
  digitalWrite(column[9], 0);
  digitalWrite(column[8], 0);
  delay(time);
  digitalWrite(column[12], 0);
  delay(time);
  digitalWrite(column[13], 0);
  delay(time);
  //jobb felső negyed
  digitalWrite(column[10], 0);
  digitalWrite(column[14], 0);
  delay(time);
  digitalWrite(column[15], 0);
  delay(time);
  digitalWrite(column[11], 0);
  delay(time);
}

void fillHalfAndReverse()
{
  int time = 50;

  for (int i = 0; i < 4; i++)
  {
    digitalWrite(layer[i], 1);
  }

  for (int i = 0; i < 16; i++)
  {
    digitalWrite(column[i], 1);
  }
  //bal felső negyed
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  delay(time);
  digitalWrite(column[3], 0);
  delay(time);
  digitalWrite(column[2], 0);
  delay(time);
  //bal alsó negyed
  digitalWrite(column[5], 0);
  digitalWrite(column[1], 0);
  delay(time);
  digitalWrite(column[0], 0);
  delay(time);
  digitalWrite(column[4], 0);
  delay(time);
  //jobb alsó negyed
  digitalWrite(column[9], 0);
  digitalWrite(column[8], 0);
  delay(time);
  digitalWrite(column[12], 0);
  delay(time);
  digitalWrite(column[13], 0);
  delay(time);
  //jobb felső negyed
  digitalWrite(column[10], 0);
  digitalWrite(column[14], 0);
  delay(time);
  digitalWrite(column[15], 0);
  delay(time);
  digitalWrite(column[11], 0);
  delay(time);
  //REVERSE
  //jobb felső negyed
  digitalWrite(column[11], 1);
  digitalWrite(column[15], 1);
  delay(time);
  digitalWrite(column[14], 1);
  delay(time);
  digitalWrite(column[10], 1);
  delay(time);
  //jobb alsó negyed
  digitalWrite(column[13], 1);
  digitalWrite(column[12], 1);
  delay(time);
  digitalWrite(column[8], 1);
  delay(time);
  digitalWrite(column[9], 1);
  delay(time);
  //bal alsó negyed
  digitalWrite(column[4], 1);
  digitalWrite(column[0], 1);
  delay(time);
  digitalWrite(column[1], 1);
  delay(time);
  digitalWrite(column[5], 1);
  delay(time);
  //bal felső negyed
  digitalWrite(column[2], 1);
  digitalWrite(column[3], 1);
  delay(time);
  digitalWrite(column[7], 1);
  delay(time);
  digitalWrite(column[6], 1);
  delay(time);
}

void fillHalfAndEmpty()
{
  int time = 50;

  for (int i = 0; i < 4; i++)
  {
    digitalWrite(layer[i], 1);
  }

  for (int i = 0; i < 16; i++)
  {
    digitalWrite(column[i], 1);
  }
  //bal felső negyed
  digitalWrite(column[6], 0);
  digitalWrite(column[7], 0);
  delay(time);
  digitalWrite(column[3], 0);
  delay(time);
  digitalWrite(column[2], 0);
  delay(time);
  //bal alsó negyed
  digitalWrite(column[5], 0);
  digitalWrite(column[1], 0);
  delay(time);
  digitalWrite(column[0], 0);
  delay(time);
  digitalWrite(column[4], 0);
  delay(time);
  //jobb alsó negyed
  digitalWrite(column[9], 0);
  digitalWrite(column[8], 0);
  delay(time);
  digitalWrite(column[12], 0);
  delay(time);
  digitalWrite(column[13], 0);
  delay(time);
  //jobb felső negyed
  digitalWrite(column[10], 0);
  digitalWrite(column[14], 0);
  delay(time);
  digitalWrite(column[15], 0);
  delay(time);
  digitalWrite(column[11], 0);
  delay(time);
  //OUTFILL
  //bal felső negyed
  digitalWrite(column[6], 1);
  digitalWrite(column[7], 1);
  delay(time);
  digitalWrite(column[3], 1);
  delay(time);
  digitalWrite(column[2], 1);
  delay(time);
  //bal alsó negyed
  digitalWrite(column[5], 1);
  digitalWrite(column[1], 1);
  delay(time);
  digitalWrite(column[0], 1);
  delay(time);
  digitalWrite(column[4], 1);
  delay(time);
  //jobb alsó negyed
  digitalWrite(column[9], 1);
  digitalWrite(column[8], 1);
  delay(time);
  digitalWrite(column[12], 1);
  delay(time);
  digitalWrite(column[13], 1);
  delay(time);
  //jobb felső negyed
  digitalWrite(column[10], 1);
  digitalWrite(column[14], 1);
  delay(time);
  digitalWrite(column[15], 1);
  delay(time);
  digitalWrite(column[11], 1);
  delay(time);
}

void loadingScreen()
{
  int time = 25;

  for (int i = 0; i < 4; i++)
  {
    digitalWrite(layer[i], 1);
  }
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(column[i], 1);
  }
  //bal felső negyed
  digitalWrite(column[6], 0);
  digitalWrite(column[10], 0);
  digitalWrite(column[11], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[14], 1);
  delay(time);
  digitalWrite(column[3], 0);
  digitalWrite(column[15], 1);
  delay(time);
  digitalWrite(column[2], 0);
  digitalWrite(column[11], 1);
  delay(time);
  digitalWrite(column[10], 1);
  //bal alsó negyed
  digitalWrite(column[5], 0);
  digitalWrite(column[1], 0);
  digitalWrite(column[7], 1);
  delay(time);
  digitalWrite(column[0], 0);
  digitalWrite(column[3], 1);
  delay(time);
  digitalWrite(column[4], 0);
  digitalWrite(column[2], 1);
  delay(time);
  digitalWrite(column[6], 1);
  //jobb alsó negyed
  digitalWrite(column[9], 0);
  digitalWrite(column[8], 0);
  digitalWrite(column[1], 1);
  delay(time);
  digitalWrite(column[12], 0);
  digitalWrite(column[0], 1);
  delay(time);
  digitalWrite(column[13], 0);
  digitalWrite(column[4], 1);
  delay(time);
  digitalWrite(column[5], 1);
  //jobb felső negyed
  digitalWrite(column[10], 0);
  digitalWrite(column[14], 0);
  digitalWrite(column[8], 1);
  delay(time);
  digitalWrite(column[15], 0);
  digitalWrite(column[12], 1);
  delay(time);
  digitalWrite(column[11], 0);
  digitalWrite(column[13], 1);
  delay(time);
  digitalWrite(column[9], 1);
}

void spin()
{
  int time = 75;
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(layer[i], 1);
  }
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(column[i], 1);
  }
  //bal felső és jobb alsó negyed
  digitalWrite(column[6], 0);
  digitalWrite(column[9], 0);
  digitalWrite(column[7], 0);
  digitalWrite(column[8], 0);
  delay(time);
  digitalWrite(column[7], 1);
  digitalWrite(column[8], 1);
  digitalWrite(column[3], 0);
  digitalWrite(column[12], 0);
  delay(time);
  digitalWrite(column[3], 1);
  digitalWrite(column[12], 1);
  digitalWrite(column[2], 0);
  digitalWrite(column[13], 0);
  delay(time);
  digitalWrite(column[2], 1);
  digitalWrite(column[13], 1);
  digitalWrite(column[6], 1);
  digitalWrite(column[9], 1);
  //bal alsó és jobb felső negyed
  digitalWrite(column[5], 0);
  digitalWrite(column[10], 0);
  digitalWrite(column[1], 0);
  digitalWrite(column[14], 0);
  delay(time);
  digitalWrite(column[1], 1);
  digitalWrite(column[14], 1);
  digitalWrite(column[0], 0);
  digitalWrite(column[15], 0);
  delay(time);
  digitalWrite(column[0], 1);
  digitalWrite(column[15], 1);
  digitalWrite(column[4], 0);
  digitalWrite(column[11], 0);
  delay(time);
  digitalWrite(column[4], 1);
  digitalWrite(column[11], 1);
  digitalWrite(column[5], 1);
  digitalWrite(column[10], 1);
}
void counter()
{
  int time = 5;
  int forOne = 11;
  int forTwo = 8;
  int forThree = 8;
  int forFour = 8;
  int forFive = 8;
  int forEnd = 51;
  //TurnEverythningOff
  turnEverythingOff();

  //1.1
  for (int i = 0; i < forOne; i++)
  {
    digitalWrite(column[7], 0);
    digitalWrite(layer[2], 1);
    delay(time);
    digitalWrite(column[7], 1);

    digitalWrite(column[11], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[11], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 0);
    digitalWrite(layer[3], 0);
  }
  turnEverythingOff();
  //1.2
  for (int i = 0; i < forOne; i++)
  {
    digitalWrite(column[6], 0);
    digitalWrite(layer[2], 1);
    delay(time);
    digitalWrite(column[6], 1);

    digitalWrite(column[10], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[10], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 0);
    digitalWrite(layer[3], 0);
  }
  turnEverythingOff();
  //1.3
  for (int i = 0; i < forOne; i++)
  {
    digitalWrite(column[5], 0);
    digitalWrite(layer[2], 1);
    delay(time);
    digitalWrite(column[5], 1);

    digitalWrite(column[9], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[9], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 0);
    digitalWrite(layer[3], 0);
  }
  turnEverythingOff();
  //1.4
  for (int i = 0; i < forEnd; i++)
  {
    digitalWrite(column[4], 0);
    digitalWrite(layer[2], 1);
    delay(time);
    digitalWrite(column[4], 1);

    digitalWrite(column[8], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[8], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 0);
    digitalWrite(layer[3], 0);
  }
  turnEverythingOff();
  //2.1

  for (int i = 0; i < forTwo; i++)
  {
    digitalWrite(column[7], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[7], 1);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[3], 0);

    digitalWrite(column[11], 0);
    digitalWrite(layer[1], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[11], 1);
    digitalWrite(layer[1], 0);
    digitalWrite(layer[3], 0);

    digitalWrite(column[15], 0);
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[15], 1);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[3], 0);
  }
  turnEverythingOff();
  //2.2
  for (int i = 0; i < forTwo; i++)
  {
    digitalWrite(column[6], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[6], 1);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[3], 0);

    digitalWrite(column[10], 0);
    digitalWrite(layer[1], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[10], 1);
    digitalWrite(layer[1], 0);
    digitalWrite(layer[3], 0);

    digitalWrite(column[14], 0);
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[14], 1);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[3], 0);
  }
  turnEverythingOff();
  //2.3
  for (int i = 0; i < forTwo; i++)
  {
    digitalWrite(column[5], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[5], 1);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[3], 0);

    digitalWrite(column[9], 0);
    digitalWrite(layer[1], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[9], 1);
    digitalWrite(layer[1], 0);
    digitalWrite(layer[3], 0);

    digitalWrite(column[13], 0);
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[13], 1);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[3], 0);
  }
  turnEverythingOff();
  //2.4
  for (int i = 0; i < forEnd; i++)
  {
    digitalWrite(column[4], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[4], 1);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[3], 0);

    digitalWrite(column[8], 0);
    digitalWrite(layer[1], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[8], 1);
    digitalWrite(layer[1], 0);
    digitalWrite(layer[3], 0);

    digitalWrite(column[12], 0);
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[12], 1);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[3], 0);
  }
  turnEverythingOff();
  //3.1
  for (int i = 0; i < forThree; i++)
  {
    digitalWrite(column[7], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[7], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[3], 0);

    digitalWrite(column[11], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[3], 1);
    digitalWrite(layer[2], 1);
    delay(time);
    digitalWrite(column[11], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[3], 0);
    digitalWrite(layer[2], 0);

    digitalWrite(column[15], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[3], 1);
    digitalWrite(layer[1], 1);
    delay(time);
    digitalWrite(column[15], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[3], 0);
    digitalWrite(layer[1], 0);
  }
  turnEverythingOff();
  //3.2
  for (int i = 0; i < forThree; i++)
  {
    digitalWrite(column[6], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[6], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[3], 0);

    digitalWrite(column[10], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[3], 1);
    digitalWrite(layer[2], 1);
    delay(time);
    digitalWrite(column[10], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[3], 0);
    digitalWrite(layer[2], 0);

    digitalWrite(column[14], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[3], 1);
    digitalWrite(layer[1], 1);
    delay(time);
    digitalWrite(column[14], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[3], 0);
    digitalWrite(layer[1], 0);
  }
  turnEverythingOff();
  //3.3
  for (int i = 0; i < forThree; i++)
  {
    digitalWrite(column[5], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[5], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[3], 0);

    digitalWrite(column[9], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[3], 1);
    digitalWrite(layer[2], 1);
    delay(time);
    digitalWrite(column[9], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[3], 0);
    digitalWrite(layer[2], 0);

    digitalWrite(column[13], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[3], 1);
    digitalWrite(layer[1], 1);
    delay(time);
    digitalWrite(column[13], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[3], 0);
    digitalWrite(layer[1], 0);
  }
  turnEverythingOff();
  //3.4
  for (int i = 0; i < forEnd; i++)
  {
    digitalWrite(column[4], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[4], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[3], 0);

    digitalWrite(column[8], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[3], 1);
    digitalWrite(layer[2], 1);
    delay(time);
    digitalWrite(column[8], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[3], 0);
    digitalWrite(layer[2], 0);

    digitalWrite(column[12], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[3], 1);
    digitalWrite(layer[1], 1);
    delay(time);
    digitalWrite(column[12], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[3], 0);
    digitalWrite(layer[1], 0);
  }
  turnEverythingOff();
  //4.1
  for (int i = 0; i < forFour; i++)
  {
    digitalWrite(column[7], 0);
    digitalWrite(layer[1], 1);
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[7], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[3], 0);

    digitalWrite(column[11], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    delay(time);
    digitalWrite(column[11], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 0);

    digitalWrite(column[15], 0);
    digitalWrite(layer[1], 1);
    delay(time);
    digitalWrite(column[15], 1);
    digitalWrite(layer[1], 0);
  }
  turnEverythingOff();
  //4.2
  for (int i = 0; i < forFour; i++)
  {
    digitalWrite(column[6], 0);
    digitalWrite(layer[1], 1);
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[6], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[3], 0);

    digitalWrite(column[10], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    delay(time);
    digitalWrite(column[10], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 0);

    digitalWrite(column[14], 0);
    digitalWrite(layer[1], 1);
    delay(time);
    digitalWrite(column[14], 1);
    digitalWrite(layer[1], 0);
  }
  turnEverythingOff();
  //4.3
  for (int i = 0; i < forFour; i++)
  {
    digitalWrite(column[5], 0);
    digitalWrite(layer[1], 1);
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[5], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[3], 0);

    digitalWrite(column[9], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    delay(time);
    digitalWrite(column[9], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 0);

    digitalWrite(column[13], 0);
    digitalWrite(layer[1], 1);
    delay(time);
    digitalWrite(column[13], 1);
    digitalWrite(layer[1], 0);
  }
  turnEverythingOff();
  //4.3
  for (int i = 0; i < forEnd; i++)
  {
    digitalWrite(column[4], 0);
    digitalWrite(layer[1], 1);
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    delay(time);
    digitalWrite(column[4], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[3], 0);

    digitalWrite(column[8], 0);
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    delay(time);
    digitalWrite(column[8], 1);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 0);

    digitalWrite(column[12], 0);
    digitalWrite(layer[1], 1);
    delay(time);
    digitalWrite(column[12], 1);
    digitalWrite(layer[1], 0);
  }
  turnEverythingOff();
}
