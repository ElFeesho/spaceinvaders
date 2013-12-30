#include "score.hpp"

static const char FNT_0[] = {  0xff,   	 // xxxx xxxx  
							   0xc3,	 // xx     xx
							   0xc3,	 // xx     xx
							   0xc3,	 // xx     xx
							   0xc3,	 // xx     xx
							   0xff		 // xxxx xxxx
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

static const char FNT_3[] = {  0x7e,   	 // xxxx xxxx 
							   0xe7,	 //       xxx
							   0x07,	 //       xx
							   0x0e,	 //      xxx
							   0x38,	 //   xx x  
							   0xff		 // xxxx xxxx
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
	renderPixels(FNT_2, 6, 0, 0);
	return true;
}

int Score::getId()
{
	return -1;
}