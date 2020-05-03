#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>

using namespace std;

#define PORT    9999
#define MAXMSG  512
#define MAXC    10

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
  server.sin_port = htons(PORT);
  auto addrlen = sizeof(server);

  if (bind(main_socket, (struct sockaddr*)&server, addrlen) < 0) {
    cout << "Failed to bind to port 9999. Errorno: " << errno << endl;
    exit(EXIT_FAILURE);
  }

  // Start listening. Hold at most 10 connections in the queue
  if (listen(main_socket, MAXC) < 0) {
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
  auto bytesRead = read(connection, buffer, MAXMSG);
  cout << "The message: " << buffer;

  // Send a message to the connection
  for (int i = 0; i < 1000; i++)
  {
    string response = to_string(i) + "\n";
    send(connection, response.c_str(), response.size(), 0);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  // Close the connection
  close(connection);
  close(main_socket);
}

