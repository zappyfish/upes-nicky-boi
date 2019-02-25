#include "packet.h"
#include "packet_manager.h"
#include "receive_function.h"
#include "send_function.h"

#define TEST_PACKET_NAME "test"

PacketManager packetManager;

// Callbacks and ReceiveFunctions go here:
// Note: DO NOT STORE PACKET VALUES WITHOUT COPYING (they get free'd after the callback)
// Note: Also, let the packet manager take care of serialization. Don't make calls to serialize yourself.

// 1. Test Receive Callback
void testReceiveCallback(Packet *packet) {
  packet->getParam("x");
}

ReceiveFunction testReceiveFunction(TEST_PACKET_NAME, &testReceiveCallback);

// 2. etc.

void setup() {
  // Add all callbacks here
  packetManager.setPacketCallback(TEST_PACKET_NAME, &testReceiveFunction);
  
}

void loop() {
  // See if we got anything new
  packetManager.checkForPackets();
  // Sleep here

  // Send a packet!
  Packet p(TEST_PACKET_NAME);
  p.setParam("x", "5");
  packetManager.sendPacket(&p);
}
