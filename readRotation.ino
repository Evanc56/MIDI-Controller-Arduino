void readRotation(){

angle = encoder.getPosition();
anglediff = angle - lastAngle;

 if (abs(anglediff) > diff) // execute only if new and old values differ enough
  {
      if (abs(anglediff) > 2000) //Edge Case where sensor positions bridges 0
      {
        if (anglediff>0)
        {
        anglediff = 4096 - abs(anglediff); //ignores edge case by repeating previous signal
        } 
        else 
        {
          anglediff = -4096 - abs(anglediff);
        }
      }
     w = anglediff/12;
 
    //sends midi message
    if (anglediff>0) 
    {
      MIDImessage(176, 54, 68+w); //clockwise rotation 65 and up
    }
    else 
    {
      MIDImessage(176, 54, 60+w); //ccw rotation 63 and down
    }
    lastAngle = angle; // reset old value with new reading
  }
delay(1);
}
