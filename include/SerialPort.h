//
// Created by orion on 1/30/21.
//

#ifndef NAVXTIMESTAMP_SERIALPORT_H
#define NAVXTIMESTAMP_SERIALPORT_H
#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>
#include <iostream>
#include <stdexcept>
#include <thread>
#include <chrono>


class SerialPort {


private:
  int ReadBufferSize;
  int timeout;
  char terminationChar;
  bool termination;
  std::string id;
  int baudRate;
  int fd;
  struct termios tty;
  int err;

public:

  SerialPort(int baudRate, std::string id);

  void Init(int baudRate, std::string id);

  void SetReadBufferSize(int size);

  void SetTimeout(int timeout);


  void EnableTermination(char c);


  void Flush();

  void Write(char *data, int length);

  int GetBytesReceived();

  int Read(char *data, int size);

  void WaitForData();

  void Reset();

  void Close();

};
#endif // NAVXTIMESTAMP_SERIALPORT_H
