#include <kipr/botball.h>
int rwheel = 1; int lwheel = 2; int tophat = 0; int rangefinder = 1; int front_claw=0; int claw_arm = 1; int claw_joint = 2; int claw_claw = 3;
int main()
{	
	printf("Start\n");
    enable_servos(); set_servo_position(front_claw,0);  //set_servo_position(claw_arm,//#); set_servo_position(claw_joint,//#); set_servo_position(claw_claw,//#);
    //wait_for_light();printf("Light detected!\n");
    while(analog(0)<2900){mav(rwheel,1500); mav(lwheel,1500);} ao(); msleep(200); //forward
    mav(rwheel,1000); mav(lwheel,1000); msleep(1200); //get to other side of line
    cmpc(rwheel); while(gmpc(rwheel)<2375){motor(rwheel,60); motor(lwheel,0);} //turn left
    while(analog(0)<2900){mav(rwheel,1500); mav(lwheel,1500);} //forward
    ao(); msleep(200); //small sleep
    cmpc(rwheel); enable_servos(); set_servo_position(front_claw,2047); //open front claw
    while(gmpc(rwheel)<1800){mav(rwheel,1150);mav(lwheel,1150);} //forward a specific distance
    cmpc(rwheel);while(gmpc(rwheel)<2375){motor(rwheel,100); motor(lwheel,0);} //turn left, '90'
    while(analog(rangefinder)<2500){mav(rwheel,300); mav(lwheel,300);} //material processor
    mav(rwheel,500); mav(lwheel,500); msleep(1000); //slowly go towards the processror
    ao(); enable_servos(); msleep(200); //stop,
    set_servo_position(front_claw,0); msleep(500); //grasp processor
    while(analog(0)<2800){mav(rwheel, -1500); mav(lwheel, -1500);} //fastly yank processor, going  until black line
    ao(); msleep(500); //small sleep
    cmpc(lwheel); while(gmpc(lwheel)>-2375){motor(lwheel,-100); motor(rwheel,0);} //turn right
    cmpc(rwheel); while(gmpc(rwheel)<5800){mav(rwheel,1500); mav(lwheel,1500);} //"forward" to certain position
    cmpc(rwheel); while(gmpc(rwheel)<2000){motor(rwheel,60); motor(lwheel,0);} //turn a specific angle
    mav(rwheel,800); mav(lwheel,800); msleep(450); //set the material processor onto a corner
    ao(); msleep(500); set_servo_position(front_claw,2047); //release the material processor
    cmpc(rwheel); while(gmpc(rwheel)>-2375){motor(rwheel,-60); motor(lwheel,0);} //turn right 90, backward //huge adjustment needed here
    while(digital(0)==0||digital(1)==0){mav(rwheel,-1500); mav(lwheel,-1500);} //move backward until straight again
    ao(); set_servo_position(front_claw,0); msleep(500); //close, in order to go up
    cmpc(lwheel); while(gmpc(lwheel)<2375){mav(lwheel,1500); mav(rwheel,0);} //turn 90 deg
    while(analog(0)<2800){mav(rwheel,1000); mav(lwheel,1000);} //forward until black line
    cmpc(rwheel); while(gmpc(rwheel)<2550){mav(rwheel,1000);mav(lwheel,1000);} // forward specific distance
    cmpc(rwheel); while(gmpc(rwheel)<1517){mav(rwheel,1000);mav(lwheel,0);} // turn specific distance
    cmpc(rwheel); while(gmpc(rwheel)<500){mav(rwheel,1500); mav(lwheel,1500);}
	int timer = 0; //line following to go up the bridge
	while(timer<15000){
		if(analog(0)<2900){motor(rwheel,75); motor(lwheel,25);msleep(100);}
		else{motor(lwheel,75); motor(rwheel,25);msleep(100);}
	timer+=100;
    }
    cmpc(rwheel); while(gmpc(rwheel)<2375){mav(rwheel,1500); mav(lwheel,0);} // turn left
    cmpc(rwheel); while(gmpc(rwheel)<4000){mav(rwheel,1000); mav(lwheel,1000);} // forward a specific distance
//arm action over here
return 0;
}
