void adc_init();
unsigned int adc_read(unsigned char);
void adc_init()
{
	ADMUX = 0B01000000;//(1<<REFS0);// | (1<<REFS1);
	ADCSRA = ((1<<ADEN) | (1<<ADPS2)| (1<<ADPS1)| (1<<ADPS0));
	}
unsigned int adc_read(unsigned char channel)
{	
	
	ADMUX = 0x40|channel; 
	ADCSRA |= (1<<ADSC);
	while(!(ADCSRA & (1<<ADIF)));

	ADCSRA |= (1<<ADIF);
	return ADC;
}