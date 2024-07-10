  #include "mbed.h"

PwmOut Drive_pin_A(PB_5);  //steering servo PWM output pin D4
PwmOut Drive_pin_B(PB_10); //Motor drive PWM output pin D6
PwmOut Drive_pin_C(PB_4);  //Motor drive PWM output pin D5 
 
int main() {

    Drive_pin_A.period_ms(20);   //Steering Servo PWM period
    Drive_pin_B.period_ms(20);   //Motor forward PWM period     
    Drive_pin_C.period_ms(20);   //Motor reverse PWM period   

    Drive_pin_B.pulsewidth_ms(0);        //drive motor off
    Drive_pin_C.pulsewidth_ms(0);        //drive motor off   
    
    wait (3);
  
    Drive_pin_A.pulsewidth_us(1450);   //Steering neutral (includes a 25uS offset)
      
    wait (1);
    
    Drive_pin_C.pulsewidth_ms(0);
    Drive_pin_B.pulsewidth_ms(10);    //drive motor on forward half power. Pulse width = 10 milliseconds
    
    wait(4);
        
    Drive_pin_A.pulsewidth_us(1700); // Half turn left

    wait (7);

    Drive_pin_A.pulsewidth_us(1200); //Half turn right

    wait (7 );
  
    Drive_pin_A.pulsewidth_us(1000);     // Full steering lock
    Drive_pin_B.pulsewidth_ms(20);   // Full power forward. Pulse width = 20 milliseconds
    
    wait (5);
    
    Drive_pin_A.pulsewidth_us(1450); // Neutral steering 
    
    wait(1);
    
    Drive_pin_A.pulsewidth_us(2000); // full steering opposite lock
    
    wait (5.5);
    
    Drive_pin_A.pulsewidth_us(1450); // Neutral steering 
    
    wait(1);
    
    Drive_pin_B.pulsewidth_ms(0);   
    Drive_pin_C.pulsewidth_ms(10);       //drive motor reverse half power. Pulsewidth = 10 milliseconds
    
    wait(3);
    
    Drive_pin_B.pulsewidth_ms(0);       //drive motor off
    Drive_pin_C.pulsewidth_ms(0);   
      
    }    

