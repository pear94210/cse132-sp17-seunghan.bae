// Function prototypes for assembly file.
extern "C" {
  uint8_t slowDivisionUint8(uint8_t a, uint8_t b);
  uint8_t cStringLength(const char aString[]);
  uint16_t sumArray(uint8_t a[], uint8_t length);

  bool greaterThanOrEqualUInt16(uint16_t a, uint16_t b);
  uint16_t slowDivisionUint16(uint16_t a, uint16_t b);
  
  uint16_t avgArray(uint8_t a[], uint8_t length);
}

