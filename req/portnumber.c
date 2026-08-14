#include "req.h"
#include <stdio.h>
#include <arpa/inet.h>

int portnumber (int port){
	return htons(port);
}
