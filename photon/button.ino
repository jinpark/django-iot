// This #include statement was automatically added by the Particle IDE.
#include "InternetButton/InternetButton.h"
#include "math.h"

InternetButton b = InternetButton();
bool changed = false;

void setup() {
    // Use b.begin(1); if you have the original SparkButton, which does not have a buzzer or a plastic enclosure
    // to use, just add a '1' between the parentheses in the code below.
    b.begin();
}

void loop(){
    // UP
    if(b.buttonOn(1)){
        changed = true;
        String jsonDataString = String( "{ \"direction\": \"up\"}");
        Particle.publish("button", jsonDataString);
        delay(500);
    }

    // Down
    else if (b.buttonOn(3)){
        changed = true;
        String jsonDataString = String( "{ \"direction\": \"down\"}");
        Particle.publish("button", jsonDataString);
        delay(500);
    }
    
    // Right
    else if (b.buttonOn(2)){
        changed = true;
        String jsonDataString = String( "{ \"direction\": \"right\"}");
        Particle.publish("button", jsonDataString);
        delay(500);
    }
    // Left
    else if (b.buttonOn(4)){
        changed = true;
        String jsonDataString = String( "{ \"direction\": \"left\"}");
        Particle.publish("button", jsonDataString);
        delay(500);
    }

    //If anything's been altered by clicking or the Spark.function, update the LEDs
    if(changed){
        b.allLedsOff();
        delay(100);
        b.allLedsOn(0,20,20);
        changed = false;
    }
}
