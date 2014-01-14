#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "cocos2d.h"


class Weapon : public cocos2d::CCNode
{	
public: 
	Weapon();
	int distance;
	double speed;
	bool can_shoot;
	double weapon_rotation;
	cocos2d::CCSprite *fire_image; 
	cocos2d::CCSprite *weapon_image; 
	// sound
	//cocos2d::CCSprite Shoot();
	cocos2d::CCSprite * Shoot();
	
};

#endif // __HERO_H__

/*

class Weapon(object):
	is_event_handler = True 
	def __init__(self,owner):
		self.owner=owner
		#self.effect = Trace()
		#print "####"
		#print owner
		self.distance=10
		self.speed = 0.5
		self.can_shoot = True
		self.weapon_speed = 2
		self.fire = cocos.sprite.Sprite('fire.png',(0,0),150,1)
		self.fire.do(Hide())
		self.owner.add(self.fire)
		self.sound = cocos.audio.pygame.mixer.Sound('sounds/shoot.wav')
			
	def enable_shoot(self,*args):
		self.can_shoot = True
		self.owner.parent.unschedule(self.enable_shoot)
	
	def sound_effect(self):		
		self.sound.play(0)
		
	def bullet_effect(self):
		pass
		
	def fire_effect(self):
		self.fire.rotation = self.owner.r+180
		self.fire.do(Blink(1,0.2) + Hide())
		#self.fire.opacity = 255
		
	def shoot(self,*args):
		self.sound_effect()
		self.fire_effect()
		self.fire_effect();
		
		
		if self.can_shoot:	self.owner.parent.add(Bullet(self.owner),20)
				
	def p(self,some,bullet):
		pass
	
	def on_mouse_press(self, x,y,button,modifiers):
		if button==1:	self.shoot()	
		
	def on_mouse_release(self,x,y,button,modifiers):
		#self.fire.opacity = 0
		pass
		
	def on_key_press(self, key):
		pass
		
	def on_key_release(self, key):
		pass
*/
