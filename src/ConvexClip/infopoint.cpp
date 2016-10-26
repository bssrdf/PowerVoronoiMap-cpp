#include "infopoint.h"
#include "point2d.h"
using namespace voronoi;

InfoPoint::InfoPoint(Point2D* erg, char code):
    erg_(erg),snd_(NULL),code_(code)
{}
InfoPoint::InfoPoint(Point2D* erg, Point2D* snd, char code):
    erg_(erg),snd_(snd),code_(code)
{}
const char* InfoPoint::toString()
{
    //String ergs, snds = "";
    const char *ergs=0;
    const char *snds=0;
    if(erg_ == NULL)
    {
        ergs = snds = "";
    }else if( snd_ == NULL)
    {
        ergs = erg->toString();
    }else
    {
        ergs = erg->toString();
        snds = snd->toString();
    }
    return "c: " + code + " " + ergs + " " + snds;
}
