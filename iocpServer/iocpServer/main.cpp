#include "common.h"
#include "iocp.h"

int main(int argc, char *argv[])
{
	IOCompletionPort iocp_server;

	if (iocp_server.Initialize()) {
		iocp_server.StartServer();
	}
}