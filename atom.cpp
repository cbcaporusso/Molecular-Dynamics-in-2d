#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

#include "atom.h"
#include "types.h"

mdatom::mdatom(Vector2 pos, Vector2 vel, Vector2 force) {
	r = pos;  
	v = vel;
	f = force;
}

mdatom::mdatom(Vector2 pos, Vector2 vel) {
	r = pos;  
	v = vel;
}

mdatom::mdatom(Vector2 pos) { r = pos; }

double mdatom::PBCsqrDistance( const mdatom& x2, const Vector2 box ) { 

	Vector2 dr;
	dr = r - x2.r;

	if 			( dr.u_[0] > 0.5 * box.u_[0] ) dr.u_[0] -= box.u_[0];
	else if 	( dr.u_[0] < 0.5 * box.u_[0] ) dr.u_[0] += box.u_[0];

	if 			( dr.u_[1] > 0.5 * box.u_[1] ) dr.u_[1] -= box.u_[1];
	else if 	( dr.u_[0] < 0.5 * box.u_[0] ) dr.u_[1] += box.u_[1];

	return dr * dr ;

};

void mdatom::PBCadjust( const Vector2 box ) {

	double lx,ly;
	lx = box.u_[0];
	ly = box.u_[1];
	
	if ( r.u_[0] < 0.0 ) r.u_[0] += lx; ;
	if ( r.u_[0] > lx  ) r.u_[0] -= lx; ;
	
	if ( r.u_[1] < 0.0 ) r.u_[1] += ly; ;
	if ( r.u_[1] > ly  ) r.u_[1] -= ly; ;

}