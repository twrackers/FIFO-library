#include <FIFO.h>

// Define a FIFO that can contain up to 4 bytes.
FIFO fifo(4);

// Display full/empty status of ring buffer.
void show()
{
  Serial.println(fifo.isEmpty() ? "fifo is EMPTY" : "fifo is NOT EMPTY");
  Serial.println(fifo.isFull()  ? "fifo is FULL"  : "fifo is NOT FULL");
}

// One-time test.
void setup() 
{
  // Set up console output.
  Serial.begin(115200);
  // Show status of (empty) ring buffer.
  show();
  // Try pushing 5 bytes (0, 1, 2, 3, 4) into ring buffer without popping
  // any bytes out.  5th one will be skipped because buffer is full.
  for (byte b = 0; b < 5; ++b) {
    if (!fifo.isFull()) {
      Serial.print("pushing ");
      Serial.println(b, DEC);
      fifo.push(b);
    } else {
      Serial.print("skipping ");
      Serial.println(b, DEC);
    }
    // Show status after each (attempt to) push.
    show();
  }
  // Start popping bytes until buffer is empty again.
  while (!fifo.isEmpty()) {
    Serial.print("popped ");
    Serial.println(fifo.pop(), DEC);
    show();
  }
  // Pop one more time, should get zero.
  Serial.print("popped ");
  Serial.println(fifo.pop(), DEC);
  show();
}

void loop()
{
  // Nothing to see here.
}
