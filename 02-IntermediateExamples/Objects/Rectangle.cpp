#include "WolframLibrary.h"
#include "Rectangle.h"

Rectangle::Rectangle(mint ww, mint hh) { w = ww; h = hh; }
void Rectangle::set(mint ww, mint hh) { w = ww;	h = hh; }
mint Rectangle::get_w(void) {	return w; }
mint Rectangle::get_h(void) {	return h;}
mint Rectangle::area(void) { return w*h; }
