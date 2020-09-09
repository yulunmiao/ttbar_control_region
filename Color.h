#include <TColor.h>  

#ifndef CUSTOMIZED_COLOR

#define	cLightblue	2001
#define	cBlue		2002
#define	cOrange		2003
#define	cBrown		2004
#define cYellow 	2005
#define	cDarkyellow	2006
#define cBlueviolet	2007
#define cViolet		2008
#define cDarkviolet	2009
#define cLightgreen	2010
#define cGreen		2011
#define cPink		2012

TColor *lightblue  = new TColor(2001,91/255.,187/255.,241/255.);
TColor *blue       = new TColor(2002,60/255.,144/255.,196/255.);
TColor *orange     = new TColor(2003,230/255.,159/255.,0/255.);
TColor *brown      = new TColor(2004,180/255.,117/255.,0/255.);
TColor *yellow     = new TColor(2005,245/255.,236/255.,69/255.);
TColor *darkyellow = new TColor(2006,215/255.,200/255.,0/255.);
TColor *blueviolet = new TColor(2007,70/255.,109/255.,171/255.);
TColor *violet     = new TColor(2008,70/255.,90/255.,134/255.);
TColor *darkviolet = new TColor(2009,55/255.,65/255.,100/255.);
TColor *lightgreen = new TColor(2010,120/255.,160/255.,0/255.);
TColor *green      = new TColor(2011,0/255.,158/255.,115/255.);
TColor *pink       = new TColor(2012,204/255.,121/255.,167/255.);

#define CUSTOMIZED_COLOR
#endif
