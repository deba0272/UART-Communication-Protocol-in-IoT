#define MY_ADDR 0x02  // Define the address of this transmitter
void setup() {
  // Initialize UART0 (Serial0)
  UBRR0H = 0;
  UBRR0L = 103;//9600 baud rate
  UCSR0B = (1<<TXEN0);  // Enable transmitter
  UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);  // 8 data bits, 1 stop bit
}
void transmit(unsigned char address, unsigned char data) {
  while (!(UCSR0A&(1<<UDRE0)));// Wait until the buffer is empty
  UDR0=address;  // Send the address first
  while (!(UCSR0A&(1<<UDRE0)));
  UDR0 = data;  // Then send the actual data
}
void loop() {
  transmit(MY_ADDR, 'Hello Sir,Madam');
  delay(1000); // Wait for a second
}
