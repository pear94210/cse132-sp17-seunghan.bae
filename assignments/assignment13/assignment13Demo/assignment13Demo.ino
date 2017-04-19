#include "assignment13.h"  // Declarations for ASM functions
#include "printRegs.h"     // Print registers for debugging
#include "pprintf.h"       // Include macro to do simple formatted printing (See: https://en.wikipedia.org/wiki/Printf_format_string)


uint16_t slowDivisionAlgorithm8(uint8_t dividend, uint8_t divisor) {
  // TODO: Write a C-code version of division (don't use divide; use a loop with repeated subtraction!)  
}


uint8_t cStringLengthAlgorithm(const char aString[]) {
   // TODO: Write a C-code version of the algorithm to find the string's length  
}


uint16_t slowDivisionAlgorithm16(uint16_t dividend, uint16_t divisor) {
  // TODO: Write a C-code version of division (don't use divide; use a loop with repeated subtraction!)  
}


// ******  Test cases:  Feel free to add to tests (but don't remove any) ******
void testSlowDivisionUint8() {
    Serial.println("**** Testing divisionUint8() (Prints \"<- ERROR\" on errors) ****");  

  uint8_t dividends[]  = {4, 2, 100,   5,  7, 200, 255, 9, 16, 255, 128, 128};
  uint8_t divisors[]   = {2, 4,   5, 100, 10,   2,   5, 2,  3,   9,   2,   3};
  const int numTests = sizeof(dividends)/sizeof(uint8_t);

  for(int i=0;i<numTests;i++) {
    uint8_t dividend = dividends[i];
    uint8_t divisor = divisors[i];
    uint8_t algorithm = slowDivisionAlgorithm8(dividend, divisor);
    uint8_t assembly = slowDivisionUint8(dividend, divisor);
    uint8_t expected = dividend/divisor;
    pprintf("slowDivisionAlgorithm8(%u,%u) is %u (algorithm) and %u (assembly); Should be %u", dividend, divisor, algorithm, assembly, expected);
    // Compare the results of the algorithm and real answer
    if(algorithm != expected) {
      Serial.print(" <- ERROR in Algorithm!");
    }
    // Compare the results of assembly language implementation and real answer
    if(assembly != expected) {
      Serial.print(" <- ERROR in Assembly!");
    }
    Serial.println();
  }  
}


void testCStringLength() {
    Serial.println("**** Testing cStringLength() (Prints \"<- ERROR\" on errors) ****");  

  // An Array of c-style strings to test
  char *strings[] = { 
    (char*)"1234567890",
    (char*)"Hello, world!",
    (char*)"Test case",
    (char*)"",
    (char*)"1",
    (char*)"\t\n",       // Include "escaped characters"
    (char*)"Oh N\0es",   // Include a null terminator IN the string!
    (char*)"last"
    };
  const uint16_t numTests = sizeof(strings)/sizeof(char*);

  for(uint16_t i=0;i<numTests;i++) {
    char *string = strings[i];
    uint8_t assembly = cStringLength(string);
    uint8_t algorithm = cStringLengthAlgorithm(string);
    uint8_t expected = strlen(string);
    pprintf("cStringLength(\"%s\") is %u algorithm) and %u (assembly) ; Should be %u", string, algorithm, assembly, expected);
    // Compare the results of cStringLength() to the C libraries strlen()
    if(algorithm != expected) {
      Serial.print(" <- ERROR in Algorithm!");
    }
    if(assembly != expected) {
      Serial.print(" <- ERROR in Assembly!");
    }
    Serial.println();
  }
}

// Working "Array Sum" function to use as a prototype for assembly version
uint16_t sumArrayAlgorithm(uint8_t a[], uint8_t length) {
  uint16_t sum = 0;
  uint8_t i=0;
  while(length>0) {
    length--;
    sum+=a[i];
    i++;
  }
  return sum;
}

void testSumArray() {
  Serial.println("**** Testing sumArray() (Prints \"<- ERROR\" on errors) ****");  

  // Individual test cases
                // 1    3    3    4    5    6    7    8    9    10
  uint8_t t1[] =  { 1,   2,   3};
  uint8_t t2[] =  {50, 200, 100};
  uint8_t t3[] =  {10,   2,   7,   4,  19,  80,  72,  54,  96, 100};
  uint8_t t4[] =  { 1};
  uint8_t t5[] =  {};
  uint8_t t6[] =  { 1,   5};

  // Array of all test cases
  uint8_t *a[] =      {  t1, t2, t3, t4, t5, t6};
  // Tests are in uint8_ts already (no need to divide by sizeof(uint8_t))
  uint8_t lengths[] = { sizeof(t1), sizeof(t2), sizeof(t3), sizeof(t4), sizeof(t5), sizeof(t6)};
  
  int numTests = sizeof(lengths)/sizeof(uint8_t);

  for(int i=0;i<numTests;i++) {
    uint8_t *array = a[i];
    uint8_t length = lengths[i];    
    uint16_t algorithm = sumArrayAlgorithm(array, length);
    uint16_t assembly = sumArray(array,length);
    Serial.print("Summing: [");
    for(int j=0;j<length-1;j++) {
      Serial.print(array[j]);
      Serial.print(", ");
    }
    if(length)
      Serial.print(array[length-1]);
    Serial.print("] = ");  
    Serial.print(assembly);
    // Compare the results of assembly language implementation and real answer
    if(assembly != algorithm) {
      Serial.print(" <- ERROR");
    }
    Serial.println();
  }
}


void testGreaterThanOrEqualUInt16() {
  Serial.println("**** Testing greaterThanOrEqualUInt16() (Prints \"<- ERROR\" on errors) ****");  

  uint16_t as[] =   {4, 2, 4096, 4097, 4096, 4096, 4352, 100,   5,  7, 1000, 3, 9, 16, 0, 21001, 21000, 32000, 4, 2, 100,   5,  7, 1000, 3, 9, 16};
  uint16_t bs[]   = {2, 4, 4097, 4096, 4096, 4352, 4096,   5, 100, 10,    1, 2, 2,  3, 0, 21000, 21001, 32000, 2, 4,   5, 100, 10,    1, 2, 2,  3};
  const int numTests = sizeof(as)/sizeof(uint16_t);

  for(int i=0;i<numTests;i++) {
    uint16_t a = as[i];
    uint16_t b = bs[i];
    bool result = greaterThanOrEqualUInt16(a,b);
    bool expected = a>=b;
    pprintf("greaterThanOrEqualUInt16(%u,%u) is %u; Should be %u", a, b, result, expected);
    if(result != expected) {
      Serial.print(" <- ERROR");
    }
    Serial.println();
  }
}


void testSlowDivisonUint16() {
    Serial.println("**** Testing divisonUint16() (Prints \"<- ERROR\" on errors) ****");  

  uint16_t dividends[]  = {4, 2, 100,   5,  7, 1000, 3, 9, 16, 65535, 65535, 65525, 65535, 64000};
  uint16_t divisors[]   = {2, 4,   5, 100, 10,    1, 2, 2,  3,     1,   800, 65535, 65535, 16000};
  const int numTests = sizeof(dividends)/sizeof(uint16_t);

  for(int i=0;i<numTests;i++) {
    uint16_t dividend = dividends[i];
    uint16_t divisor = divisors[i];
    uint16_t algorithm = slowDivisionAlgorithm16(dividend, divisor);
    uint16_t assembly = slowDivisionUint16(dividend, divisor);
    uint16_t expected = dividend/divisor;
    pprintf("slowDivisionAlgorithm16(%u,%u) is %u (algorithm) and %u (assembly); Should be %u", dividend, divisor, algorithm, assembly, expected);
    // Compare the results of the algorithm and real answer
    if(algorithm != expected) {
      Serial.print(" <- ERROR in Algorithm!");
    }
    // Compare the results of assembly language implementation and real answer
    if(assembly != expected) {
      Serial.print(" <- ERROR in Assembly");
    }
    Serial.println();
  }
}

void testAvgArray() {
  Serial.println("**** Testing avgArray() (Prints \"<- ERROR\" on errors) ****");  

  // Individual test cases
                // 1    3    3    4    5    6    7    8    9    10
  uint8_t t1[] =  { 1,   2,   3};
  uint8_t t2[] =  { 1};
  uint8_t t3[] =  { 1,   5};
  uint8_t t4[] =  {10,  20,  30,  40,   1,   2,   3,   4,   0,   0};
  uint8_t t5[] =  {50, 200, 100};
  uint8_t t6[] =  {10,   2,   7,   4,  19,  80,  72,  54,  96, 100};
  uint8_t t7[] =  { 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 0};

  // Array of all test cases
  uint8_t *a[] =      {  t1, t2, t3, t4, t5, t6, t7};
  // Tests are in uint8_ts already (no need to divide by sizeof(uint8_t))
  uint8_t lengths[] = { sizeof(t1), sizeof(t2), sizeof(t3), sizeof(t4), sizeof(t5), sizeof(t6)};
  
  int numTests = sizeof(lengths)/sizeof(uint8_t);

  for(int i=0;i<numTests;i++) {
    uint8_t *array = a[i];
    uint8_t length = lengths[i];    
    uint16_t algorithm = sumArrayAlgorithm(array, length)/length;
    uint16_t assembly = avgArray(array,length);
    Serial.print("Averaging: [");
    for(int j=0;j<length-1;j++) {
      Serial.print(array[j]);
      Serial.print(", ");
    }
    if(length)
      Serial.print(array[length-1]);
    Serial.print("] = ");  
    Serial.print(assembly);
    // Compare the results of assembly language implementation and real answer
    if(assembly != algorithm) {
      Serial.print(" <- ERROR");
    }
    Serial.println();
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("Starting tests...");

  // Note: To uncomment a single "Simple Test", just change the "/*" to a "//*"

  /* Simple Test
  uint8_t dividend8 = 175;
  uint8_t divisor8 = 26;
  uint8_t quotient8ASM = slowDivisionUint8(dividend8,divisor8);
  uint8_t quotient8Alg = slowDivisionAlgorithm8(dividend8,divisor8);
  pprintf("slowDivisionAlgorithm8(%u,%u) is %u (algorithm) and %u (assembly); Should be %u\n", dividend8, divisor8, quotient8Alg, quotient8ASM, dividend8/divisor8);
  // */ 
  // Full Test:
  // testSlowDivisionUint8();
  
  /* Simple Test
  const char *string = "Test Case";
  uint8_t strLenASM = cStringLength(string);
  uint8_t strLenAlg = cStringLengthAlgorithm(string);
  pprintf("cStringLength(\"%s\") is %u (algorithm) and %u (assembly); Should be %u\n", string, strLenAlg, strLenASM, strlen(string));
  // */
  // Full Test:
  // testCStringLength();
  
  /* Simple Test
  uint8_t array[] = { 1,2,3,4,5};
  uint8_t arrayLength = sizeof(array)/sizeof(uint8_t);
  uint16_t sum = sumArray(array,arrayLength);
  pprintf("sumArray(...) is %u; Should be %u\n", sum, sumArrayAlgorithm(array, arrayLength));
  // */
  // Full Test:
  // testSumArray();

  /* Simple Test
  uint16_t a = 1234;
  uint16_t b =  456;  
  pprintf("greaterThanOrEqualUInt16(%u,%u) is %u; Should be %u\n", a, b, greaterThanOrEqualUInt16(a,b), a>=b);
  // */
  // Full Test:
  // testGreaterThanOrEqualUInt16();

  /* Simple Test
  uint16_t dividend16 = 12356;
  uint16_t divisor16 = 123;
  uint16_t quotient16Alg = slowDivisionAlgorithm16(dividend16,divisor16);
  uint16_t quotient16ASM = slowDivisionUint16(dividend16,divisor16);
  pprintf("slowDivisionUint16(%u,%u) is %u (algorithm) and %u (assembly); Should be %u\n", dividend16, divisor16, quotient16Alg, quotient16ASM, dividend16/divisor16);
  // */
  // Full Test:
  // testSlowDivisonUint16();

  /* Simple Test
  pprintf("avgArray(...) is %u; Should be %u\n", avgArray(array,arrayLength), sumArrayAlgorithm(array, arrayLength)/arrayLength);
  // */
  // Full Test:
  // testAvgArray();
  Serial.println("Done with tests!!!");
}

void loop() { /* unused */ }
