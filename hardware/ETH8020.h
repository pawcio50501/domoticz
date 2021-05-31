#pragma once

#include "DomoticzHardware.h"

class CETH8020 : public CDomoticzHardwareBase
{
      public:
	CETH8020(int ID, const std::string &IPAddress, unsigned short usIPPort, const std::string &username, const std::string &password);
	~CETH8020() override = default;
	bool WriteToHardware(const char *pdata, unsigned char length) override;

      private:
	void Init();
	bool StartHardware() override;
	bool StopHardware() override;
	void Do_Work();
	void GetMeterDetails();
	void UpdateSwitch(unsigned char Idx, uint8_t SubUnit, bool bOn, double Level, const std::string &defaultname);

      private:
	std::string m_szIPAddress;
	unsigned short m_usIPPort;
	std::string m_Username;
	std::string m_Password;
	std::shared_ptr<std::thread> m_thread;
};
