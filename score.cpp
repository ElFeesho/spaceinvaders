#include "score.hpp"

static const char FNT_0[] = {  0x7e,   	 //  xxx xxx  
							   0xc7,	 // xx    xxx
							   0xcb,	 // xx   x xx
							   0xd3,	 // xx x   xx
							   0xe3,	 // xxx    xx
							   0x7e		 //  xxx xxx
							   	  }; 

static const char FNT_1[] = {  0x18,   	 //    x x  
							   0x38,	 //   xx x
							   0x18,	 //    x x
							   0x18,	 //    x x
							   0x18,	 //    x x
							   0x3c		 //   xx xx
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

static const char FNT_4[] = {  0x0c,   	 //      xx 
							   0x3c,	 //   xx xx
							   0x6c,	 //  xx  xx 
							   0xff,	 // xxxx xxxx
							   0x0c,	 //      xx 
							   0x0c		 //      xx
							   	  };

static const char FNT_5[] = {  0xff,   	 // xxxx xxxx 
							   0xc0,	 // xx
							   0xfe,	 // xxxx xxx  
							   0x03,	 //        xx
							   0xc3,	 // xx     xx 
							   0x7e		 //  xxx xxx     
							   	  }; 	

static const char FNT_6[] = {  0x0e,   	 //      xxx 
							   0x38,	 //   xx x
							   0x7e,	 //  xxx xxx  
							   0xc3,	 // xx     xx
							   0xc3,	 // xx     xx 
							   0x7e		 //  xxx xxx     
							   	  }; 	

static const char FNT_7[] = {  0xff,   	 // xxxx xxxx 
							   0x03,	 //        xx
							   0x06,	 //       xx  
							   0x0c,	 //      xx
							   0x18,	 //    x x 
							   0x30		 //   xx      
							   	  }; 	

static const char FNT_8[] = {  0x7e,   	 //  xxx xxx 
							   0xc3,	 // xx     xx
							   0x7e,	 //  xxx xxx  
							   0xc3,	 // xx     xx
							   0xc3,	 // xx     xx 
							   0x7e		 //  xxx xxx     
							   	  }; 	

static const char FNT_9[] = {  0x7e,   	 //  xxx xxx 
							   0xc3,	 // xx     xx
							   0xc3,	 // xx     xx  
							   0x3e,	 //   xx xxx
							   0x0c,	 //      xx 
							   0x18		 //    x x       
							   	  }; 							   	    							   	  

static const char *FNT[] = { 
	FNT_0,
	FNT_1,
	FNT_2,
	FNT_3,
	FNT_4,
	FNT_5,
	FNT_6,
	FNT_7,
	FNT_8,
	FNT_9
};

Score::Score() : score(0)
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
	int thousand = score/1000;
	int hundreds = (score-(thousand*1000)) / 100;
	int tens = (score - (hundreds * 100) - (thousand*1000)) / 10;
	int points = (score - (hundreds * 100) - (thousand*1000) - (tens * 10));

	renderPixels(FNT[thousand], 6, X(), Y());
	renderPixels(FNT[hundreds], 6, X()+20, Y());
	renderPixels(FNT[tens], 6, X()+40, Y());
	renderPixels(FNT[points], 6, X()+60, Y());
	
	return true;
}

int Score::getId()
{
	return -1;
}

void Score::incScore(int points)
{
	score += points;
}