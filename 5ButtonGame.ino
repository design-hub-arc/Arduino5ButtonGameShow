  // alright we want a game show button set up
  // 5 buttons for contestants, 1 button for host
  // once host presses his button the contestant's button's are unlocked
  // if a contestant presses a button before it's 'unlocked
  // they are penalized and will be disqualified from the round
  // first person to press their button will get their LED to light up
  // only 1 LED should light up and the LED that is associated with
  // whoever pressed their button first
  //pressing the button too soon gives contestantX a value of -1
  //being the winner gives contestantX a value of 42
int host = 0;
int contestant1 = 0;
int contestant2 = 0;
int contestant3 = 0;
int contestant4 = 0;
int contestant5 = 0;
bool isWin = false; //to prevent infinite loops

void setup() {
  // put your setup code here, to run once:
  // the inputs, connected to external switches/buttons
  pinMode(0, INPUT); // host's button
  pinMode(1, INPUT); // contestant 1
  pinMode(2, INPUT); // contestant 2
  pinMode(3, INPUT); // contestant 3
  pinMode(4, INPUT); // contestant 4
  pinMode(5, INPUT); // contestant 5

  //the outputs, connected to external LEDs
  pinMode(6, OUTPUT);  // contestant 1 LED
  pinMode(7, OUTPUT);  // contestant 2 LED
  pinMode(8, OUTPUT);  // contestant 3 LED
  pinMode(9, OUTPUT);  // contestant 4 LED
  pinMode(10, OUTPUT); // contestant 5 LED
}

void loop() {
  // put your main code here, to run repeatedly:
  // first read to see if anyone pressed their button before the host
  contestant1 = digitalRead(1);
  contestant2 = digitalRead(2);
  contestant3 = digitalRead(3);
  contestant4 = digitalRead(4);
  contestant5 = digitalRead(5);
  // if they did press the button it will be marked as -1
  if ( contestant1 == HIGH )
  contestant1 = -1;
  if ( contestant2 == HIGH )
  contestant2 = -1;
  if ( contestant3 == HIGH )
  contestant3 = -1;
  if ( contestant4 == HIGH )
  contestant4 = -1;
  if ( contestant5 == HIGH )
  contestant5 = -1;
  //now read and check to see if the host has pressed their button
  host = digitalRead(0); //read in host input
  if ( host == HIGH )
  {
    // the game has started, now we must reread the buttons but...
    // if the contestant = -1, meaning their pressed the button too early
    // they will not be read
    // this will be repeated until the someone presses their button
    do
    { 
      if ( contestant1 != -1)
      contestant1 = digitalRead(1);
      if ( contestant2 != -1)
      contestant2 = digitalRead(2);
      if ( contestant3 != -1)
      contestant3 = digitalRead(3);
      if ( contestant4 != -1)
      contestant4 = digitalRead(4);
      if ( contestant5 != -1)
      contestant5 = digitalRead(5);
      //set isWin to true so my default case is switch it back to false...
      //it was that or type out isWin = true 5 times
      //now i can also make this switch statement handle the LED lighting but
      // that would make testing and future changes harder, I think
      // thought more decided to make this also light LEDs
      isWin = true;
      if ( contestant1 == HIGH )
      {
        contestant1 = 42;
        digitalWrite(6, HIGH);
      }
      else if ( contestant2 == HIGH )
      {
        contestant2 = 42;
        digitalWrite(7, HIGH);
      }
      else if ( contestant3 == HIGH )
      {
        contestant3 = 42;
        digitalWrite(8, HIGH);
      }
      else if ( contestant4 == HIGH )
      {
        contestant4 = 42;
        digitalWrite(9, HIGH);
      }
      else if ( contestant5 == HIGH )
      {
        contestant5 = 42;
        digitalWrite(10, HIGH);
      }
      else
      {
        //do nothing just wait for someone to press the dam button
        isWin = false; //Forgot to add this dam me
      }
    } while ( isWin == false );
    //Yay means somone won, see who by seeing who got 42, and light their LED
    //now we are going to wait a little bit, and then turn off the LEDs
    delay(5000); // waits 5 sec, 5000 = 5000 millisec = 5 sec
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  }
//and the game starts again.
//TODO make the arduino keep score?
}
