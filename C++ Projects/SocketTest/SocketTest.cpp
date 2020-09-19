// Code from: https://www.binarytides.com/winsock-socket-programming-tutorial/

#pragma warning(disable: 4996)

#include <stdio.h>
#include <WinSock2.h>
#include <string>

#pragma comment(lib, "ws2_32.lib")

int main(int argc, char* argv[]) {
	WSADATA wsa;
	SOCKET s;
	char server_reply[2000];
	int recv_size;

	// MAKEWORD(2, 2) is the version. wsa is the struct where
	// socket information is stored.
	printf("\nInitializing Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code: %d", WSAGetLastError());
		return 1;
	}

	printf("Initialized.");

	// socket(address family - AF_INET == IPV4, TCP vs UDP SOCK_STREAM vs SOCK_DGRAM, 0 is IPPROTO_TCP | IPPROTO_UDP
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		printf("Could not create socket: %d", WSAGetLastError());
	}

	printf("Socket created.\n");

	// inet_addr(const char*) converts IP addresses to long
	struct sockaddr_in server;
	server.sin_addr.S_un.S_addr = inet_addr("216.58.217.46");
	server.sin_family = AF_INET;
	server.sin_port = htons(80);

	// Connect to a remote server
	if (connect(s, (struct sockaddr*) &server, sizeof(server)) < 0) {
		puts("connect error");
		return 1;
	}

	puts("Connected");

	// Send some data
	std::string tmessage = "GET / HTTP/1.1\r\n\r\n";
	
	char message[20];

	strcpy(message, tmessage.c_str());

	if (send(s, message, strlen(message), 0) < 0) {
		puts("Send failed.");
		return 1;
	}
	puts("Data sent.\n");

	// Receive a reply from the server
	if ((recv_size = recv(s, server_reply, 2000, 0)) == SOCKET_ERROR) {
		puts("recv failed");
	}

	// Add a null to make it a proper string
	//server_reply[recv_size] = '\0';
	puts(server_reply);
	
	closesocket(s);
	WSACleanup();

	return 0;


}