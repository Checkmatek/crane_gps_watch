// Copyright (C) 2014 mru@sisyphus.teil.cc
//
// simplistic interface to the gps watch
//

#pragma once


#include <vector>
#include <string>


#include "SerialPort.hpp"
#include "DeviceInterface.hpp"

class SerialLink : public DeviceInterface {
  public:
    SerialLink(const std::string& filename);
    virtual ~SerialLink() {};
    void readMemory(unsigned addr, unsigned count, unsigned char* it) override;
    void writeMemory(unsigned addr, unsigned count, unsigned char* it) override ;
    std::string readVersion() override;
    std::string readVersion2() override;
    void clearFlash1() override;
    void clearFlash2() override;

  private:

    void sendCommand(const unsigned char opcode, const std::vector<unsigned char>& payload);
    void receiveReply(const unsigned char opcode, std::vector<unsigned char>& target);
    unsigned char expect(unsigned char val);
    void write(std::vector<unsigned char>& buf);
    unsigned char read();
    void read(std::vector<unsigned char>& buf);
    unsigned short checksum(unsigned char opcode, const std::vector<unsigned char>& payload);

  private:
    std::string filename;
    SerialPort port;
};
