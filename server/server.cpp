#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <iostream>
#include <unistd.h>

using namespace std;

int main() {

  // Create a socket (IPv4, TCP)
  int main_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (main_socket == -1) {
    cout << "Failed to create socket. Errorno: " << errno << endl;
    exit(EXIT_FAILURE);
  }

  // Listen to port 9999 on any address
  sockaddr_in server;
  server.sin_family = AF_INET; // local
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(9999);
  auto addrlen = sizeof(server);

  if (bind(main_socket, (struct sockaddr*)&server, addrlen) < 0) {
    cout << "Failed to bind to port 9999. Errorno: " << errno << endl;
    exit(EXIT_FAILURE);
  }

  // Start listening. Hold at most 10 connections in the queue
  if (listen(main_socket, 10) < 0) {
    cout << "Failed to listen on socket. Errorno: " << errno << endl;
    exit(EXIT_FAILURE);
  }

  // Grab a connection from the queue
  int connection = accept(main_socket, (struct sockaddr*)&server, (socklen_t*)&addrlen);
  if (connection < 0) {
    cout << "Failed to grab connection. errno: " << errno << endl;
    exit(EXIT_FAILURE);
  }

  // Read from the connection
  char buffer[100];
  auto bytesRead = read(connection, buffer, 100);
  cout << "The message: " << buffer;

  // Send a message to the connection
  string response = "Pong\n";
  send(connection, response.c_str(), response.size(), 0);

  // Close the connection
  close(connection);
  close(main_socket);
}

