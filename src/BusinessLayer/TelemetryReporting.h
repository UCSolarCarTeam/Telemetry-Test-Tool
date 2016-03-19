#pragma once
/*-------------------------------------------------------
   By Jordan Heinrichs for the Solar Car Team
   Copyright (c) 2015 by University of Calgary Solar Car Team
-------------------------------------------------------*/
class QIODevice;
class VehicleData;

class TelemetryReporting
{
public:
   TelemetryReporting(QIODevice& device,
                      VehicleData& vehicleData);

   void sendKeyDriverControlTelemetry();
   void sendDriverControlDetails();
   void sendFaults();
   void sendBatteryData();
   void sendCmuData(unsigned char cmuDataIndex);
   void sendMpptData(unsigned char mpptDataIndex);

private:
   // Will return length of framed data
   unsigned int frameData(const unsigned char* dataToEncode,
         unsigned long length, unsigned char* frameData);
   // Will return length of encoded data
   unsigned int stuffData(const unsigned char* dataToEncode,
         unsigned long length, unsigned char* encodedData);
   // Add checksum into data at index length and length + 1
   void addChecksum(unsigned char* data, unsigned int length);

   void writeFloatIntoData(unsigned char* data, int index, const float& value);
   void sendData(const unsigned char* data, int length);

private:
   QIODevice& outputDevice_;
   VehicleData& vehicleData_;
};