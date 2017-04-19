#ifndef pprintf

#define sprintfBufferSz 100
extern char sprintfBuffer[];
#define pprintf(...) { snprintf(sprintfBuffer, sprintfBufferSz, __VA_ARGS__); Serial.print(sprintfBuffer); }

#endif
