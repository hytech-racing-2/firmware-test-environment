#pragma once
#include <queue>

#include "HyTech_FlexCAN.h"

class MockCAN {
public:
	static inline int read(CAN_message_t &msg) 					{ return read(msg, vehicle_outbox); }
	static inline int vehicle_read(CAN_message_t &msg)			{ return read(msg, vehicle_inbox); }
	static inline void write(const CAN_message_t& msg)			{ vehicle_inbox.push(msg); }
	static inline void vehicle_write(const CAN_message_t &msg) 	{ vehicle_outbox.push(msg); }
	static inline size_t vehicle_avail()						{ return vehicle_inbox.size(); }
	static void teardown();
private:
	static std::queue<CAN_message_t> vehicle_inbox;
	static std::queue<CAN_message_t> vehicle_outbox;

	static int read(CAN_message_t &msg, std::queue<CAN_message_t>& mailbox);
};

