const int motors = 10;           
const int button = 4;           
boolean lastButton = LOW;       //Variable containing the previous button state                               
boolean currentButton = LOW;    //Variable containing the current
                                //button state
int speedInc = 0;


void setup()
{
  pinMode (motors, OUTPUT);    
  pinMode (button, INPUT);      
}


boolean debounce(boolean last)
{
  boolean current = digitalRead(button);    //Read the button state if it's different wait 5ms
  if (last != current)                    
    {
      delay(5);                            
      current = digitalRead(button);        //read it again
    }
    return current;
}


//Motor Speed Selection


void setSpeed(int inc)

{
  
  //speed one
  if (inc == 1)
  {
    analogWrite(motors, 110);
  }
  
  else if (inc == 2)
  {
    analogWrite(motors, 150);
  }
  else if (inc == 3)
  {
    analogWrite(motors, 180);
  }
  else if (inc == 4)
  {
    analogWrite(motors, 200);
  }
    
  //OFF 
  else
  {
    analogWrite(motors, 0);
  }
}

void loop()
{
  currentButton = debounce(lastButton);              //read debounce state  if it was pressed
  if (lastButton == LOW && currentButton == HIGH)    
  {
    speedInc++;                                    //Increment motor speed
  }
  lastButton = currentButton;                          //reset button value
  
  //if cycled through all speed increments
  //reset the speed to 0
  if (speedInc == 5)  speedInc = 0;
  
  setSpeed(speedInc);
}
