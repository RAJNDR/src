/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include "testWindow.hpp"
#include <stdio.h>

int main( int argc, char* args[] )
{
	printf("starting the window");
	testWindow * iwindow = new testWindow;
	iwindow->start();

	delete(iwindow);	
	return 0;
}