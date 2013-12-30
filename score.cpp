#include "score.hpp"

static const char FNT_0[] = {  0x7e,   	 //  xxx xxx  
							   0xc7,	 // xx    xxx
							   0xcb,	 // xx   x xx
							   0xd3,	 // xx x   xx
							   0xe3,	 // xxx    xx
							   0x7e		 //  xxx xxx
							   	  }; 

static const char FNT_1[] = {  0x60,   	 //  xx  
							   0xe0,	 // xxx
							   0x60,	 //  xx
							   0x60,	 //  xx
							   0x60,	 //  xx
							   0xf0		 // xxxx
							   	  }; 

static const char FNT_2[] = {  0x7e,   	 //  xxx xxx 
							   0xe7,	 // xxx   xxx
							   0x07,	 //       xxx
							   0x0e,	 //      xxx
							   0x38,	 //   xx x  
							   0xff		 // xxxx xxxx
							   	  };   

static const char FNT_3[] = {  0xff,   	 // xxxx xxxx 
							   0x03,	 //        xx
							   0x0c,	 //      xx 
							   0x03,	 //        xx
							   0xc3,	 // xx     xx 
							   0x7c		 //  xxx xx
							   	  }; 

static const char FNT_4[] = {  0xff,   	 // xxxx xxxx 
							   0x03,	 //        xx
							   0x0c,	 //      xx 
							   0x03,	 //        xx
							   0xc3,	 // xx     xx 
							   0x7c		 //  xxx xx
							   	  }; 							   	    							   	  

Score::Score()
{
	setName("score");
}

Score::~Score()
{

}

bool Score::update()
{
	return isAlive();
}

bool Score::render()
{
	renderPixels(FNT_0, 6, 0, 0);
	renderPixels(FNT_1, 6, 60, 0);
	renderPixels(FNT_2, 6, 120, 0);
	renderPixels(FNT_3, 6, 180, 0);
	return true;
}

int Score::getId()
{
	return -1;
}