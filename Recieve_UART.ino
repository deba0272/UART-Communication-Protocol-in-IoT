#define MY_ADDR 0x02  // Define the address of this receiver(Macros)
void setup() {
  // Initialize UART0 (Serial0)
  UBRR0H = 0;
  UBRR0L = 103;//9600 baud rate
  DDRB|=0xFF;//setting output pin
  UCSR0B = (1<<RXEN0);  // Enable receiver
  UCSR0C = (1<<UCSZ01)|(1<<UCSZ00); // 8 data bits, 1 stop bit
}
unsigned char receive() {
  while (!(UCSR0A&(1<<RXC0)));//wait untill data is recieved
  return UDR0;  // Return the received data from the buffer
}
void loop() {
  unsigned char receivedAddress = receive();  // Receive the address first
  if (receivedAddress == MY_ADDR) {
    unsigned char data = receive();
    PORTB|=(1<<PA0);//led glows
  }
}